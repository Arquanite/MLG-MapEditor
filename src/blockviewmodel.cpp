#include "blockviewmodel.h"

BlockViewModel::BlockViewModel()
{
    BlockNames+= tr("Sky");
    BlockTypes+= tr("Solid");
}

int	BlockViewModel::columnCount(const QModelIndex &parent) const{
    return 4;
}

int BlockViewModel::rowCount(const QModelIndex &parent) const{
    return BlocksCount/4 +1;
}

QVariant BlockViewModel::data(const QModelIndex &index, int role) const{
    int Value = 4*index.row()+index.column();
    if(Value > BlocksCount) return QVariant();
    if(role == Qt::ToolTipRole) return BlockNames.value(Value) + "\n" + BlockTypes.value(Value);
    if(role != Qt::DisplayRole) return QVariant();
    return Value;
}

void BlockViewModel::AddBlock(QString name, QString type){
    BlocksCount++;
    BlockNames+= name;
    BlockTypes+= type;
    if(BlocksCount%4 == 0){
        beginInsertRows(QModelIndex(),0,0);
        endInsertRows();
    }
    dataChanged(index(0,0), index(0,4));
}

QString BlockViewModel::GetNameOf(int block){
    return BlockNames.value(block);
}

QString BlockViewModel::GetTypeOf(int block){
    return BlockTypes.value(block);
}
