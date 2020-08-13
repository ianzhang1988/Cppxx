#include <iostream>
#include <memory>

int main() {
    auto pointer = std::make_shared<int>(5);
    auto pointer_other = std::make_shared<int>(10);
    std::cout<<*pointer<<std::endl;
    std::cout<<"pointer count: "<<pointer.use_count()<<std::endl;
    std::cout<<"pointer_other count: "<<pointer_other.use_count()<<std::endl;
    auto pointer1 = pointer;
    auto pointer2 = pointer;
    std::cout<<"pointer count: "<<pointer.use_count()<<std::endl;
    pointer1.reset();
    std::cout<<"pointer count: "<<pointer.use_count()<<std::endl;

    std::cout<<"after reset ptr: "<<pointer1.get()<<std::endl;
    // std::cout<<"after reset value: "<<*pointer1<<std::endl; //Segmentation fault (core dumped)

    if (pointer == pointer2){
        std::cout<<"pointer == pointer2"<<std::endl;
    }

    if (pointer.get() == pointer2.get()){
        std::cout<<"pointer.get() == pointer2.get()"<<std::endl;
    }

    pointer2 = pointer_other;
    std::cout<<*pointer2<<std::endl;
    std::cout<<"pointer count: "<<pointer.use_count()<<std::endl;
    std::cout<<"pointer_other count: "<<pointer_other.use_count()<<std::endl;

    std::unique_ptr<int> unique(new int(15));
    std::cout<<*unique<<std::endl;
    std::unique_ptr<int> unique1;
    unique1 = std::move(unique);
    std::cout<<*unique1<<std::endl;
    // std::cout<<*unique<<std::endl;  //Segmentation fault (core dumped)
}