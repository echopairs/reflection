//
// Created by echopairs on 3/18/17.
//

#ifndef REFLECTION_MESSAGE1_H
#define REFLECTION_MESSAGE1_H

#include <iostream>
#include "Message.h"
#include "reflection_factory.h"

class Message1: public Message
{
public:
    Message1():Message()
    {

    }
    std::string show()
    {
        return "Message1";
    }
};

REGISTER_MESSAGE(Message1, "message1");

#endif //REFLECTION_MESSAGE1_H
