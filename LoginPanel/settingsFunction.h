#ifndef SETTINGSFUNCTION_H
#define SETTINGSFUNCTION_H

#include <qpushbutton.h>

void styleIconButton(QPushButton *button, QString &patch) {
	QPixmap pixmap(patch);
	QIcon buttonIcon(pixmap);
	button->setIcon(buttonIcon);
	button->setIconSize(pixmap.rect().size());
	button->setStyleSheet("QPushButton{""background-color:white;" "border-radius:5px;" "outline:none;""}" "QPushButton:hover{""background-color:#CCC""}");
}

void styleLabel(QLabel *label) {
	label->setStyleSheet("color:white;");
}

void styleLineEdit(QLineEdit *lineEdit) {
	lineEdit->setStyleSheet("border:2px solid #1C74B2; color:#CCC; border-radius: 5px; background-color: #2F3336;");
}

void styleButtonInSettings(QPushButton *button) {
	button->setStyleSheet("QPushButton{""background:#2b333e;" "border:1px solid #2b333e;" "width:75px;" "height:24px;" "outline:none;" "color:#CCC""}" "QPushButton:hover{""background-color:#09111C;""}");
}

#endif // !SETTINGSFUNCTION_H
