#ifndef BLOCKDELEGATE_H
#define BLOCKDELEGATE_H

#include <QItemDelegate>
#include <QPainter>
#include <QVector>
#include <QImage>

class BlockDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    BlockDelegate(QWidget *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void AddBlock(QImage block);
    QImage GetImage(int block);
private:
    QVector<QImage> Blocks;
signals:

public slots:

};

#endif // BLOCKDELEGATE_H
