#pragma once

#include <string>

class MessageSystem {
public:
    void print(const std::string &message);
    void update();
    void clear();

private:
    int getOldestIndex();

    static constexpr int numMessages = 3;
    std::string messages[numMessages]{};
    int triggerTime = 1;
};