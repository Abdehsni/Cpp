#include"fileloader.h"

namespace model {

FileLoader::FileLoader()
{
}


std::tuple<std::tuple<std::vector<std::string>, int, int>,int> FileLoader::loadALevel(const std::string& path)
{
    std::tuple<std::vector<std::string>, int, int> data{};
    int savedLevel;
    unsigned indexOfLine = 0;
    std::string line;
    std::string completePath="./../../Baba_is_you/resources/"+path;


    if(badNameFile(path)){
        throw std::invalid_argument("the name doesn't end with .txt  !!!!");
    }else if(existingNameFile(path)){
        throw std::invalid_argument("This is an unauthorized name of file !");
    }else{
        std::ifstream myFile(completePath);
        if (myFile.is_open()) {
            std::vector<std::string> elements;
            while (getline(myFile, line)) {
                std::stringstream sline(line);
                std::string element;
                while (sline >> element) {
                    elements.push_back(element);
                }
                if(indexOfLine==0){
                    savedLevel = std::stoi(elements.at(0));
                }else if (indexOfLine == 1) {
                    std::get<1>(data) = std::stoi(elements.at(0));
                    std::get<2>(data) = std::stoi(elements.at(1));
                } else {
                    std::string gameobject;
                    for (unsigned indexElements = 0; indexElements < 3; indexElements++) {
                        gameobject.append(elements.at(indexElements));
                        gameobject.append(" ");
                    }
                    std::get<0>(data).push_back(gameobject);
                }
                elements.clear();
                indexOfLine++;
            }
            myFile.close();
        } else {
            throw std::invalid_argument("Unable to open file");
        }

    }

    return make_tuple(data,savedLevel);
}




void FileLoader::saveLevel(const std::string &path,const std::tuple<std::vector<std::string>, int, int> &elements,const int& currentLevel)
{
    if(badNameFile(path)){
        throw std::invalid_argument("the name doesn't end with .txt  !!!!");
    }else if(existingNameFile(path)){
        throw std::invalid_argument("This is an unauthorized name of file !");
    }else{
        std::string completePath="./../../Baba_is_you/resources/";
        completePath+=path;
        std::ofstream outfile(completePath);

         if(!outfile.is_open()) {
            throw std::invalid_argument("Cannot create the file");
         }else{
             outfile<<std::to_string(currentLevel)<<std::endl;
             outfile<<std::to_string(std::get<1>(elements))<<" "<<std::to_string(std::get<2>(elements))<<" "<<std::endl;
           for(auto &object:std::get<0>(elements)){
                 outfile<<object<<std::endl;
             }
         }
         outfile.close();
    }

}


bool FileLoader::badNameFile(std::string path)
{
    if(path.size()<4){
        return true;
    }else{
        return !(path.substr(path.size()-4)==".txt");
    }
}




bool FileLoader::existingNameFile(std::string path)
{
    if(path=="level_0.txt"||path=="level_1.txt"||path=="level_2.txt"||path=="level_3.txt"||path=="level_4.txt"||path=="level_5.txt"){
        return true;
    }else{
        return false;
    }
}




std::tuple<std::vector<std::string>, int, int> FileLoader::initLevel(int level) {
    std::tuple<std::vector<std::string>, int, int> data{};
    unsigned indexOfLine = 0;
    std::string line;
    std::ifstream myFile;

    switch (level) {
    case 0:
        myFile = std::ifstream("./../../Baba_is_you/resources/level_0.txt");
        break;
    case 1:
        myFile = std::ifstream("./../../Baba_is_you/resources/level_1.txt");
        break;
    case 2:
        myFile = std::ifstream("./../../Baba_is_you/resources/level_2.txt");
        break;
    case 3:
        myFile = std::ifstream("./../../Baba_is_you/resources/level_3.txt");
        break;
    case 4:
        myFile = std::ifstream("./../../Baba_is_you/resources/level_4.txt");
        break;
    case 5:
        return data;
    }

    if (myFile.is_open()) {
        std::vector<std::string> elements;
        while (getline(myFile, line)) {
            std::stringstream sline(line);
            std::string element;
            while (sline >> element) {
                elements.push_back(element);
            }
            if (indexOfLine == 0) {
                std::get<1>(data) = std::stoi(elements.at(0));
                std::get<2>(data) = std::stoi(elements.at(1));
            } else {
                std::string gameobject;
                for (unsigned indexElements = 0; indexElements < 3; indexElements++) {
                    gameobject.append(elements.at(indexElements));
                    gameobject.append(" ");
                }
                std::get<0>(data).push_back(gameobject);
            }
            elements.clear();
            indexOfLine++;
        }
        myFile.close();
    } else {
        throw std::invalid_argument("Unable to open file");
    }
    return data;
}



}
