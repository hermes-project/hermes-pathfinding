//
// Created by rem on 20/03/18.
//

#include <QtWidgets/QtWidgets>
#include "Window.h"

Window::Window(QWidget* parent, Landmark* landmark) : QWidget(parent), frame(new LandmarkFrame(this, landmark, new Graph(landmark)))
{
    // Paramètres globaux de la frame
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(40, 40, 40));

    // Les boutons à lier avec les bonnes méthodes
    QPushButton* quit = new QPushButton("Quit");
    QPushButton* regenerate = new QPushButton("Regenerate");
    QPushButton* add = new QPushButton("Add");
    QPushButton* empty = new QPushButton("Nani button (not binded)");

    // On configure le look des boutons
    quit->setFont(QFont("Cursive", 11, QFont::Bold));
    regenerate->setFont(QFont("Cursive", 11, QFont::Bold));;
    add->setFont(QFont("Cursive", 11, QFont::Bold));
    empty->setFont(QFont("Cursive", 11, QFont::Bold));

    // Le lien en question !
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(regenerate, &QPushButton::clicked, frame, &LandmarkFrame::regenerate);
    connect(add, &QPushButton::clicked, frame, &LandmarkFrame::add);

    // Gestion des layouts
    QGridLayout* buttonLayout = new QGridLayout;
    buttonLayout->addWidget(regenerate, 0, 0);
    buttonLayout->addWidget(quit, 0, 1);
    buttonLayout->addWidget(add, 1, 0);
    buttonLayout->addWidget(empty, 1, 1);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(buttonLayout);
    layout->addWidget(frame);
    this->setLayout(layout);
    this->setPalette(pal);
    this->show();
}