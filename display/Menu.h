//
// Created by rem on 20/03/18.
//

#ifndef HERMES_PATHFINDING_MENU_H
#define HERMES_PATHFINDING_MENU_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>

class Menu : public QWidget{
    Q_OBJECT
public:
    Menu(QWidget* parent=0);
    void paintEvent(QPaintEvent *event) override;

    QPushButton* buttonGenerate;
};


#endif //HERMES_PATHFINDING_MENU_H
