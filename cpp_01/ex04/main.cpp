#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    std::string str;
    std::string s1;
    std::string s2;
    std::string fileName;
    int index;

    if (argc != 4)
    {
        std::cout << "There should be three arguments!" << std::endl;
        return 1;
    }

    fileName = argv[1];
    fileName = fileName + ".replace";
    s1 = argv[2];
    s2 = argv[3];
    std::ifstream reading(argv[1]);
    if (!reading)
    {
        std::cout << "Error: unable to open file for reading!" << std::endl;
        return 1;
    }
    std::ofstream writing(fileName);
    if (!writing)
    {
        std::cout << "Error: unable to open file for writing!" << std::endl;
        return 1;
    }
    while (!reading.eof())
    {
        getline(reading, str);
        index = 0;
        while (index != std::string::npos)
        {
            index = str.find(s1, 0);
            if (index == std::string::npos)
            {
                writing << str;
                if (!reading.eof())
                    writing << std::endl;
            }
            else
            {
                writing << str.substr(0, index);
                str = str.substr(index + s1.size());
                writing << s2;
            }
        }
    }
    reading.close();
    writing.close();
    std::cout << "File created and owerriten" << std::endl;
    return 0;
}