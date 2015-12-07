#include "blockdelegate.h"

BlockDelegate::BlockDelegate(QWidget *parent)
{
    QImage image(48,48, QImage::Format_RGBA8888);
    image.fill(QColor("#ffffff"));
    Blocks.push_back(image);
}

void BlockDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    painter->drawImage(option.rect, Blocks.value(index.model()->data(index).toInt()));
}

void BlockDelegate::AddBlock(QImage block){
    Blocks.push_back(block);
}

QImage BlockDelegate::GetImage(int block){
    return Blocks.value(block);
}
