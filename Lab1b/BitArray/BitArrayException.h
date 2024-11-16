#include <exception>
#include <string>

class BitArrayException : public std::exception {
private:
    std::string errorMessage;

public:
    BitArrayException(std::string errorMessage) {
        this->errorMessage = errorMessage;
    }

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};
