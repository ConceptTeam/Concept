#include "newlist.h"
#include "fileitem.h"
#include <string>

NewListAbstractModel::NewListAbstractModel(QObject *parent)
        : QAbstractListModel(parent) {}


int NewListAbstractModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_list.count();
}

QVariant NewListAbstractModel::data (const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= m_list.count())
        return {};

    FileItem listItem = m_list[index.row()];
    switch (role) {
        case NameRole:
        return QString::fromStdString(listItem.getFilename());
        default:
            return {};
    }
}

QHash<int, QByteArray> NewListAbstractModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[TypeRole] = "type";
    return roles;
}

void NewListAbstractModel::remove(int index, int count) {
    beginRemoveRows(QModelIndex(), index, index + count - 1);
    for (int row = 0; row < count; ++row) {
        m_list.removeAt(index);
    }
    endRemoveRows();
}

void NewListAbstractModel::add(const QString &filename) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());

    // save the file to DB and get location on the filesystem
    string location = "";

    // if no file name was provided
    if (filename == "") {
        m_list << FileItem(rowCount(), "New file " + to_string(rowCount()), location);
    }
    else {
        m_list << FileItem(rowCount(), filename.toStdString(), location);
    }

    endInsertRows();
}

QVariantList NewListAbstractModel::getFileItemsForQML() const {
    QVariantList fileList;
    for (FileItem item : m_list) {
        QVariantMap fileMap;
        fileMap["filename"] = QString::fromStdString(item.getFilename());
        fileList.append(fileMap);
    }
    return fileList;
}
