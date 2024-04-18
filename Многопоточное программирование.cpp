#include <iostream>
#include <thread>
#include <chrono>

//Метод для эмуляции сложной задачи
void DoWork()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << std::this_thread::get_id() << "DoWork" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}


int main()
{
    setlocale(LC_ALL, "rus");

    std::thread th(DoWork);
    //th.detach();
    std::thread th2(DoWork);
    




    std::cout << "START MAIN" << std::endl;
    //Преостанавливает работу потока 
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    //Получить идентиикатор потока
    std::cout << std::this_thread::get_id() << std::endl;
    std::cout << "END MAIN" << std::endl;

    //DoWork();
    for (int i = 0; i < 10; i++)
    {
        std::cout << std::this_thread::get_id() << " " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    th.join();//позволяет дождаться выполнение той задачи, которую мы поставили в потоек
    th2.join();
    return 0;
}