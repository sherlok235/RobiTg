#pragma once
#ifndef TokenReader
#define TokenReader

#include <fstream>
#include <memory>
#include <string>
class ITokenReader{
public:
    virtual std::string read_token() =0;
    virtual ~ITokenReader();
};
class FileTokenReader: public ITokenReader{
    std::string file_name,token;
    std::shared_ptr<std::ifstream> file;
public:
    FileTokenReader(const std::string& filename) noexcept;
    FileTokenReader(const std::string &&filename) noexcept;
    void setFile_name(const std::string &newFile_name);
    std::string read_token() override;
    ~FileTokenReader() noexcept override =default;
};
#endif
