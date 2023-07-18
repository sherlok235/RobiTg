#pragma once
#ifndef Bot_CPP
#define Bot_CPP
#include "TokenReader.hpp"
#include <string>
class IBot{
protected:
    std::unique_ptr<ITokenReader> reader;
    std::string m_token;
    // you should to create a vector that will store all wllowed commands
    virtual void send_msg(unsigned,std::string) = 0;
    virtual std::string read_token(std::string) = 0;
    virtual std::string read_token() = 0;
    virtual void recive() = 0;
public:
    virtual ~IBot();

};
class ToDoListBot: protected IBot{
    void recive() override;
    void send_msg(unsigned, std::string) override;
    std::string read_token(std::string)override;
public:
    ToDoListBot();
    ToDoListBot(ITokenReader&);
    ToDoListBot(std::string&);
    ToDoListBot(std::string&&);
    ~ToDoListBot() override;
};
#endif
