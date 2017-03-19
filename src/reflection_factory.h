//
// Created by echopairs on 3/18/17.
//

#ifndef REFLECTION_REFLECTION_FACTORY_H
#define REFLECTION_REFLECTION_FACTORY_H

#include <memory>
#include <functional>
#include <map>
#include <iostream>

// the interface of Messages
class Message;

class AutoFactory
{
public:

    template<typename  T>
    class RegisterHelper
    {
    public:

        RegisterHelper(const std::string &type_name)
        {
            AutoFactory::Instance().maps_.emplace(type_name, [] { return new T(); });
        }
//
//        template<typename... Args>
//        RegisterHelper(const std::string& key, Args... args)
//        {
//            AutoFactory::Instance().maps_.emplace(key, [&] { return new T(args...); });
//        }
    };

    static Message* GetMessage(const std::string type_name)
    {
        auto item = maps_.find(type_name);
        if (item == maps_.end())
        {
            return nullptr;
        }
        return maps_[type_name]();
    }

    static std::shared_ptr<Message> ProduceShared(const std::string &type_name)
    {
        return std::shared_ptr<Message>(GetMessage(type_name));
    }


    static std::unique_ptr<Message> ProduceUnique(const std::string &type_name)
    {
        return std::unique_ptr<Message>(GetMessage(type_name));
    }

private:
    static AutoFactory & Instance()
    {
        static AutoFactory instance;
        return instance;
    }

    static std::map<std::string, std::function<Message*()> > maps_;
    AutoFactory() {};
    AutoFactory(AutoFactory &) = delete;
    AutoFactory(AutoFactory &&) = delete;
    AutoFactory operator= (AutoFactory &) = delete;
};

std::map<std::string, std::function<Message*()> > AutoFactory::maps_ ;

#define REGISTER_MESSAGE(T, key)  \
static AutoFactory::RegisterHelper<T> T##message (key)

#endif //REFLECTION_REFLECTION_FACTORY_H
