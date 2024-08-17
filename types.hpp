#pragma once

class Value {
    public:
        std::string type = "";
        bool is_ref = false;
        virtual std::string print() = 0;
        virtual ~Value() {}
};

class Ref : public Value {
    public:
        std::string type = "Ref";
        Value* ref = nullptr;
        Value* parent = nullptr;
        Ref(Value*, Value* = nullptr);
        std::string print();
        ~Ref();
};

class Number : public Value {
    public:
        std::string type = "Number";
        std::string val;
        Number(std::string);
        std::string print();
        ~Number();
};

class String : public Value {
    public:
        char* str;
        std::string type = "String";
        String(std::string);
        std::string print();
        std::string val();
        ~String();
};

class List : public Value {
    public:
        std::vector<Value*> items;
        std::string type = "List";
        List();
        List(std::string);
        std::string print();
        ~List();
};

class Dict : public Value {
    public:
        std::unordered_map<std::string, Value*> dict;
        std::string type = "Dict";
        std::vector<std::string> keys;
        Dict();
        Dict(std::string);
        void append_unique(std::string, bool = false);
        std::string print();
        ~Dict();
};

class Null : public Value {
    public:
        std::string type = "Null";
        Null();
        std::string print();
        ~Null();
};