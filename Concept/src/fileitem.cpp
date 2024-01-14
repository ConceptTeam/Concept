#include "fileitem.h"
#include <string>
using namespace std;

FileItem::FileItem(int index, string filename, string location) {
    this->index = index;
    this->filename = filename;
    this->location = location;
}

FileItem::~FileItem() {

}

string FileItem::getFilename() {
    return this->filename;
}
