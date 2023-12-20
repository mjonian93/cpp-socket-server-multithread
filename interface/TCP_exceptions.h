#ifndef TCP_EXCEPTIONS_H
#define TCP_EXCEPTIONS_H

#include <exception>

class SocketFailedException : public std::exception{
public:
    SocketFailedException() noexcept = default;
    ~SocketFailedException() = default;
    virtual const char* what () const noexcept {
        return "Socket failed Exception";
    }
};

class SetSockOptFailedException : public std::exception{
public:
    SetSockOptFailedException() noexcept = default;
    ~SetSockOptFailedException() = default;
    virtual const char* what () const noexcept {
        return "SetSockOpt Failed Exception";
    }
};

class BindFailedException : public std::exception{
public:
    BindFailedException() noexcept = default;
    ~BindFailedException() = default;
    virtual const char* what () const noexcept {
        return "Bind Failed Exception";
    }
};

class ListenFailedException : public std::exception{
public:
    ListenFailedException() noexcept = default;
    ~ListenFailedException() = default;
    virtual const char* what () const noexcept {
        return "Listen Failed Exception";
    }
};

class AcceptFailedException : public std::exception{
public:
    AcceptFailedException() noexcept = default;
    ~AcceptFailedException() = default;
    virtual const char* what () const noexcept {
        return "Accept Failed Exception";
    }
};

#endif