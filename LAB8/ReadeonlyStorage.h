#ifndef _READONLYSTORAGE_H_
#define _READONLYSTORAGE_H_


template<class T>
class ReadonlyStorage {
private:
    T data;

public:
    ReadonlyStorage(T _data) : data(_data) {}

    T getData() const
    {
        return data;
    }

    ReadonlyStorage operator +(const ReadonlyStorage& r)
    {
        return ReadonlyStorage(this->getData() + r.getData());
    }

    operator T()  // this method for static_cast<>() operation
    {
        return data;
    }
};

#endif