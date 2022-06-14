#pragma once

#include "lib/lib_string.hpp"

namespace preproc {
    void squash_vector(std::vector<std::string>& orignal, const std::vector<std::string>& other) {
        int orignal_size = orignal.size();
        for(int orignal_count = 0; orignal_count < orignal_size; orignal_count++) {
            if(orignal[orignal_count][0] == '@') {
                std::vector<std::string>::iterator orignal_itr = orignal.begin();
                orignal[orignal_count] = other[0];

                int other_size = other.size();
                for(int other_count = 1; other_count < other_size; other_count++) {
                    orignal.insert(orignal_itr + orignal_count + other_count, other[other_count]);
                    orignal_itr = orignal.begin();
                }
            }
        }
    }

    std::string remove_comments(const std::string& line) {
        if(line == "" || line == ";" || line[0] == ';') {
            return "";
        }

        bool enable_removal = true;
        int required_len = 0;
        int line_size = line.size();
        for(int char_index = 0; char_index < line_size; char_index++) {
            if(line[char_index] == '"') {
                enable_removal = !enable_removal;
            }
            if((line[char_index] == ';') && enable_removal) {
                break;
            }
            required_len++;
        }
        
        std::string useful_string = line.substr(0, required_len);
        return useful_string;
    }

    void expand_files(std::string file_contents, std::vector<std::string>& expanded_contents) {
        std::vector<std::string> line_contents = lib::split(file_contents, '\n');
        int line_contents_size = line_contents.size();

        for(int line_itr = 0; line_itr < line_contents_size; line_itr++) {
            line_contents[line_itr] = remove_comments(line_contents[line_itr]);
            line_contents[line_itr] = lib::trim_leading(line_contents[line_itr]);
            line_contents[line_itr] = lib::trim_trailing(line_contents[line_itr]);

            if(line_contents[line_itr] != "") {
                expanded_contents.emplace_back(line_contents[line_itr]);
            }
        }


    }
}
