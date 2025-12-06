#include "libkal.cpp"

extern "C" {
    Table* new_table() {
        return new Table;
    }

    void add_to_table(Table* table, const char* key, const char* value) {
        (*table)[std::string(key)] = std::string(value);
    }

    void free_table(Table* table) {
        delete table;
    }
}

extern "C" {
    ResultList* new_list() {
        return new ResultList;
    }

    void extract_to_list(ResultList* list, Result* result) {
        for(Result& each_result : result->to_list()) {
            list->emplace_back(Result(each_result));
        }
    }

    int list_size(ResultList* list) {
        return list->size();
    }

    Result* list_index(ResultList* list, int index) {
        return new Result((*list)[index]);
    }

    void free_list(ResultList* list) {
        delete list;
    }
}

extern "C" {
    Result* new_result(const char* value) {
        return new Result(std::string(value));
    }

    Result* result_get_index(Result* result, int index) {
        return new Result((*result)[index]);
    }

    Result* result_get_key(Result* result, const char* key) {
        return new Result((*result)[std::string(key)]);
    }

    double result_to_number(Result* result) {
        return result->to_number();
    }

    const char* result_to_string(Result* result) {
        return (result->to_string()).c_str();
    }

    bool result_to_null(Result* result) {
        return result->to_null();
    }

    void print_result(Result* result) {
        std::cout << *result << "\n";
    }

    void free_result(Result* result) {
        delete result;
    }
}

extern "C" {
    Kal* new_kal() {
        return new Kal();
    }

    Result* kal_exec(Kal* kal, const char* code, Table* table) {
        return new Result(kal->exec(std::string(code), *table));
    }

    void free_kal(Kal* kal) {
        delete kal;
    }
}