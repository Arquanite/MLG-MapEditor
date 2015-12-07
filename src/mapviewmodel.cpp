#include "mapviewmodel.h"

MapViewModel::MapViewModel()
{
    Column col;
    for(int i=0; i<columnCount(QModelIndex()); i++){
        Map.push_front(col);
    }
}

int	MapViewModel::columnCount(const QModelIndex &parent) const{
    return 17;
}

int MapViewModel::rowCount(const QModelIndex &parent) const{
    return 13;
}

QVariant MapViewModel::data(const QModelIndex &index, int role) const{
    if(role != Qt::DisplayRole) return QVariant();
    return Map.value(index.column()).row[index.row()];
}

void MapViewModel::ChangeBlock(QModelIndex index, int block){
    Column col = Map.value(index.column());
    col.row[index.row()] = block;
    Map.replace(index.column(), col);
    dataChanged(index, index);
}
