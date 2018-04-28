//
// Created by rem on 26/04/18.
//

#ifndef HERMES_PATHFINDING_MENU_H
#define HERMES_PATHFINDING_MENU_H


#include <QtWidgets/QtWidgets>
#include <QtWidgets/QPushButton>

class Menu : public QWidget {
    Q_OBJECT
public:
    /** Constructeur */
    Menu(QWidget* parent= nullptr);

    /** Les botons du menu */
    QPushButton* quit;
    QPushButton* regenerate;
    QPushButton* add;
    QPushButton* empty;
};


#endif //HERMES_PATHFINDING_MENU_H
