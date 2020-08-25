#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <queue>
#include <chrono>
#include <condition_variable>
#include <atomic>

void test_1(){
    std::thread t([](){
        std::thread::id this_id = std::this_thread::get_id();
        std::cout<<"thread id: "<<this_id<<std::endl;
    });

    t.join();
}

static int sum = 0;

void no_lock(int repeat, int factor) {
    for(int i=0; i< repeat; i++)
    {
        sum+=2*factor;

    }
}

void critical_section(int repeat, int factor) {
    static std::mutex mtx;
    for(int i=0; i< repeat; i++) {
        std::unique_lock<std::mutex> lock(mtx);
        sum+=2*factor;
        lock.unlock();
    }
}

void test_2() {
    int repeat1 = 10000;
    int repeat2 = 12000;
    std::cout<<"expect:"<< repeat1 + repeat2<<std::endl;

    int factor = 5;

    std::thread t1(no_lock, repeat1, factor), t2(no_lock, repeat2, factor);
    t1.join();
    t2.join();

    std::cout<<"nolock: "<< sum/2/factor<<std::endl;
    sum = 0;

    std::thread t3(critical_section, repeat1, factor), t4(critical_section, repeat2, factor);
    t3.join();
    t4.join();

    std::cout<<"with lock: "<< sum /2/factor<<std::endl;
}

void test_3()
{
    std::packaged_task<int()> task([](){std::cout << "in thread"<<std::endl;return 1+1;});
    std::future<int> result = task.get_future();

    std::thread(std::move(task)).detach();
    std::cout << "waiting..."<<std::endl;

    result.wait();
    std::cout << "done!" << std:: endl << "future result is " << result.get() << std::endl;
}

void test_4()
{
    std::mutex mtx;
    std::queue<int> produced_nums;
    int product_num = 13;
    std::condition_variable cv;
    constexpr int consumer_num = 3;

    auto producer = [&]() {
        for(int i=1;i<product_num;i++){
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            std::unique_lock<std::mutex> lock(mtx);
            std::cout << "producing " << i << std::endl;
            produced_nums.push(i);
            cv.notify_all(); 
        }


        for (int i=0; i < consumer_num; ++i)
        {
            std::unique_lock<std::mutex> lock(mtx);
            produced_nums.push(0);
            cv.notify_all(); 
        }
    
    };

    auto consumer = [&]() {
        while (true) {
            bool flag = false;

            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock);
            while( !produced_nums.empty() ) {

                if (0 == produced_nums.front()){
                    produced_nums.pop();
                    // cv.notify_all();
                    std::cout << "consumer quiting " << std::endl;
                    flag = true;        
                    break;
                }

                std::cout << "consuming " << produced_nums.front() << std::endl;
                produced_nums.pop();
                
                lock.unlock();

                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                
                lock.lock();
            }

            if (flag) {
                break;
            }
        }
    };

    std::thread p(producer);
    std::thread cs[consumer_num];
    for (int i = 0; i < consumer_num; ++i) {
        cs[i] = std::thread(consumer);
    }
    p.join();
    for (int i = 0; i < consumer_num; ++i) {
        cs[i].join();
    }

}

struct A {
    float x;
    int y;
    long long z;
};

void test_5(){

    std::atomic<A> a;
    std::cout << std::boolalpha << a.is_lock_free() << std::endl;

    std::atomic<int> count = {0};

    std::thread t1([&](){
        count.fetch_add(1);
    });
    std::thread t2([&](){
        count++;        // 等价于 fetch_add
        count += 1;     // 等价于 fetch_add
    });
    t1.join();
    t2.join();
    std::cout << count << std::endl;
}

int main() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
}