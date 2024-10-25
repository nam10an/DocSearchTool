#include <bits/stdc++.h>
#include <chrono>
#include "dictionary.h"
#include<sstream>
#define FILENAME "mahatma-gandhi-collected-works-volume-1.txt"

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream inputFile(FILENAME);

    if (!inputFile.is_open()) {
        std::cerr << "ERROR: UNABLE TO OPEN INPUT FILE" <<std::endl;
        return 1;
    }

    std::string tuple;
    std::string sentence;

    Dictionary dict;

    while (std::getline(inputFile, tuple, ')') && std::getline(inputFile, sentence)) {
        tuple+=')';

        std::vector<int> metadata;     // e.g book_no page_no
        // sentence is stored in sentence string
        std::istringstream iss(tuple);
        iss.ignore(1); // Ignore the first character '('

        std::string temp;

        while (std::getline(iss, temp, ',')) {  //convert elements to int
            // Trim leading and trailing white spaces
            size_t start = temp.find_first_not_of(" ");
            size_t end = temp.find_last_not_of(" ");
            if (start != std::string::npos && end != std::string::npos) {
                temp = temp.substr(start, end - start + 1);
            }
            
            if(temp[0] == '\'') { //remove the single quotes
                int num = std::stoi(temp.substr(1, temp.size() - 2));
                metadata.push_back(num);
            } 
            else{
                int num = std::stoi(temp);
                metadata.push_back(num);
            }
        }
        dict.insert_sentence(metadata[0], metadata[1], metadata[2], metadata[3], sentence);
    }

    inputFile.close();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "Runtime: " << duration.count() << " milliseconds" << std::endl;

    dict.dump_dictionary("counts.txt");
    std::ifstream countfile("counts.txt"); 
    if (!countfile.is_open()) {
        std::cerr << "ERROR: UNABLE TO OPEN countfile " << std::endl;
        return 1;
    }

    bool flag = true;
    std::string l;
    int count=0;
    while(std::getline(countfile, l)) {
        std::istringstream iss(l);
        std::string word;
        int wcount;

        if(std::getline(iss, word, ',') && iss>>wcount){
            if(dict.get_word_count(word)!=wcount){
                cout<<"ALL DID NOT MATCHED"<<endl;
                cout<<"Expected count for word "<<word<< " : "<<wcount<<"  count: "<<count<<", received: "<<dict.get_word_count(word)<<endl;
                flag=false; 
                break;
            }
        }
        count++;
    }

    if(flag){
        cout<<"ALL MATCHED"<<endl;
    }
    countfile.close();
    return 0;
}