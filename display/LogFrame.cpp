//
// Created by rem on 26/04/18.
//

#include "LogFrame.h"

LogFrame::LogFrame(QWidget *parent, int size_Y) : QFrame(parent) {

    this->setFixedSize(300, size_Y);

    Line* emptyLine = new Line(this, "");
    Line* title = new Line(this, "Hermès Pathfinding - Log");
    emptyLine->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    title->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    title->setFont(QFont("Cursive", 16, QFont::Medium));
    nbLine = size_Y/TEXT_SIZE;

    layout = new QVBoxLayout;
    layout->setAlignment(Qt::AlignTop);
    layout->addWidget(emptyLine);
    layout->addWidget(title);
    layout->addWidget(new Line(*emptyLine));
    this->setLayout(layout);
}

void LogFrame::debug(const char *line) {
    Line* newLine = new Line(this, line);
    lines.push(newLine);
    if(lines.size() > nbLine) {
        layout->removeWidget(lines.front());
        lines.pop();
        this->update();
    }
    layout->addWidget(newLine);
}

void LogFrame::warning(const char *line) {
    Line* newLine = new Line(this, line);
    lines.push(newLine);
    if(lines.size() > nbLine) {
        layout->removeWidget(lines.front());
        lines.pop();
        this->update();
    }
    layout->addWidget(newLine);
}

void LogFrame::error(const char *line) {
    Line* newLine = new Line(this, line);
    lines.push(newLine);
    if(lines.size() > nbLine) {
        layout->removeWidget(lines.front());
        lines.pop();
        this->update();
    }
    layout->addWidget(newLine);
}

int LogFrame::getNbLine() const {
    return nbLine;
}
