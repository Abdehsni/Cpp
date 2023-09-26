#include<vector>
#include<map>
#include<tuple>
#include<string>
#include<fstream>
#include <sstream>
#ifndef FILELOADER_H
#define FILELOADER_H


namespace model{

class FileLoader{
    /// for checking the name of file entered by the user
    /// \brief badNameFile
    /// \param path
    /// \return
    bool badNameFile(std::string path);

    ///for checking if the name of file is not already used by the game
    /// \brief existingNameFile
    /// \param path
    /// \return
    ///
    bool existingNameFile(std::string path);
public:
    FileLoader();
    std::tuple<std::vector<std::string>,int,int>initLevel(int level);
    std::tuple<std::tuple<std::vector<std::string>, int, int>, int> loadALevel(const std::string &path);
    void saveLevel(const std::string &path, const std::tuple<std::vector<std::string>, int, int> &elements,const int& currentLevel);
};

}



#endif // FILELOADER_H
