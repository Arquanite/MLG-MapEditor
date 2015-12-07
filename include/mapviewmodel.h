#ifndef MAPVIEWMODEL_H
#define MAPVIEWMODEL_H

#include <QAbstractItemModel>


struct Column{
    int row[13] = {0};
};

class MapViewModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MapViewModel();
    int	columnCount(const QModelIndex &parent) const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void ChangeBlock(QModelIndex index, int block);
private:
    QVector<Column> Map;
signals:

public slots:
};

#endif // MAPVIEWMODEL_H
