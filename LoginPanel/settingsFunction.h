#ifndef SETTINGSFUNCTION_H
#define SETTINGSFUNCTION_H

#include <qpushbutton.h>

void styleIconButton(QPushButton *button, QString &patch) {
	QPixmap pixmap(patch);
	QIcon buttonIcon(pixmap);
	button->setIcon(buttonIcon);
	button->setIconSize(pixmap.rect().size());
	button->setStyleSheet("background-color:white; border-radius: 5px;");
}

#endif // !SETTINGSFUNCTION_H
