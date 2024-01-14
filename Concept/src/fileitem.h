// fileitem.h
#ifndef FILEITEM_H
#define FILEITEM_H

#include <string>
using namespace std;

class FileItem {

private:
    int index;
    string filename;
    string location;

public:
    FileItem(int index, string filename, string location);
    ~FileItem();
    string getFilename();

};

#endif // FILEITEM_H
