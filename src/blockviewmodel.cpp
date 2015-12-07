#include "blockviewmodel.h"

BlockViewModel::BlockViewModel()
{

}

int	BlockViewModel::columnCount(const QModelIndex &parent) const{
    return 4;
}

int BlockViewModel::rowCount(const QModelIndex &parent) const{
    return BlocksCount/4 +1;
}

QVariant BlockViewModel::data(const QModelIndex &index, int role) const{
    if(role != Qt::DisplayRole) return QVariant();
    return 4*index.row()+index.column();
}

void BlockViewModel::BlockAdded(){
    BlocksCount++;
    if(BlocksCount%4 == 0){
        beginInsertRows(QModelIndex(),0,0);
        endInsertRows();
    }
    dataChanged(index(0,0), index(0,4));
}
