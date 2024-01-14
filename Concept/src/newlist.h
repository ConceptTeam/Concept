// newlist.h
#ifndef NEWLIST_H
#define NEWLIST_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include "fileitem.h"

class NewListAbstractModel : public QAbstractListModel {
Q_OBJECT

public:
    enum FileRoles {
        NameRole = Qt::UserRole + 1,
        TypeRole
    };

    explicit NewListAbstractModel(QObject *parent = nullptr);

    // void add(const FileItem animalModel);

    Q_INVOKABLE QVariantList getFileItemsForQML() const;

    Q_INVOKABLE void remove(int index, int count = 1);

    Q_INVOKABLE void add(const QString &filename);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<FileItem> m_list;
};

#endif // NEWLIST_H
