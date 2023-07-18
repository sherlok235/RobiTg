#include "Bot.hpp"

ToDoListBot::~ToDoListBot()
{

}

ToDoListBot::ToDoListBot(std::string & token)
{
    m_token = token;
}

ToDoListBot::ToDoListBot(std::string && token)
{
    m_token = std::move(token);
}

std::string ToDoListBot::read_token(std::string file_name)
{
    if(!reader)
        reader = std::make_unique<FileTokenReader>(file_name);
    m_token = reader->read_token();
    return m_token;
}

ToDoListBot::ToDoListBot()
{
    m_token = "";
}

ToDoListBot::ToDoListBot(ITokenReader & reader)
{
    m_token = reader.read_token();
}
