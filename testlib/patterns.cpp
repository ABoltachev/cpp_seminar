#include "patterns.hpp"


std::mutex Singleton::m_mutex;
std::shared_ptr<Singleton> Singleton::m_instance;

std::shared_ptr<Singleton> Singleton::instance() {
    std::lock_guard<std::mutex> lg(m_mutex);
    if (!m_instance) {
        Singleton *ptr = new Singleton;
        m_instance = std::shared_ptr<Singleton>(ptr);
    }

    return m_instance;
}


class window
{
    public:
    virtual void show() = 0;
    virtual ~window(){};
};

class windowWin: public window
{
    public:
    void show(){};
    ~windowWin(){};
};

class button
{
    public:
    virtual void show() = 0;
    virtual ~button(){};
};

class AFactory
{
    public:
    virtual window* createWindow(){};
    virtual button* createButton(){};
    
};

class windowFactory: public AFactory
{
    public:
    window* createWindow(){    }

};
