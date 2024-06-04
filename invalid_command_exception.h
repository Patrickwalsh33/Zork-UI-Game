#ifndef INVALID_COMMAND_EXCEPTION_H
#define INVALID_COMMAND_EXCEPTION_H

#include <exception>
#include <QString>

class InvalidCommandException : public std::exception {
public:
    InvalidCommandException(const QString& message) : message_(message) {}

    const char* what() const noexcept override{
        return message_.toStdString().c_str();
    }

private:
    QString message_;
};

#endif // INVALID_COMMAND_EXCEPTION_H
