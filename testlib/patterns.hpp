#pragma once
#include <memory>
#include <mutex>
#include <string>
#include <iostream>
// get, set print

class Singleton{
    private:
        static std::shared_ptr<Singleton> m_instance;
        std::string m_name;
        Singleton() = default;
        static std::mutex m_mutex;
    public:
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        static std::shared_ptr<Singleton> instance();

        std::string get_name() const{
            std::lock_guard<std::mutex> lg(Singleton::m_mutex);
            return m_name;
        }
        void set_name(std::string new_name){
            std::lock_guard<std::mutex> lg(Singleton::m_mutex);
            m_name = new_name;
        }
        void print() const{
            std::lock_guard<std::mutex> lg(Singleton::m_mutex);
            std::cout << m_name << std::endl;
        }
};
