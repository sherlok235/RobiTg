#include "TokenReader.hpp"
FileTokenReader::FileTokenReader(const std::string &filename)noexcept
    :file_name(filename){
    file = std::make_shared<std::ifstream>();
}

FileTokenReader::FileTokenReader(const std::string&& filename)noexcept
    :file_name(std::move(filename))
{
    file = std::make_shared<std::ifstream>();
}

void FileTokenReader::setFile_name(const std::string &newFile_name)
{
    file_name = newFile_name;
}

std::string FileTokenReader::read_token()
{
    if(!file->is_open()){ // double despecing
    file->open(file_name);
    if(!file->is_open())
        throw std::runtime_error("File can't be open "+ file_name+ "\n");
    }
    if(file && token.empty())
        *file>>token;
    if(token.size() ==46)
    return token;
    return "Token size don't corespond\n";
}

