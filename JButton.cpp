#include "JButton.h"
#include "Globals.h"
#include <iostream>
// �Լ����� �����ؾ��Ѵ�.

JButton::JButton() {
}

JButton::JButton(std::string title) {
	title_ = title;
}

void JButton::setBounds(int x, int y, int width, int height) {
	x_ = x;
	y_ = y;
	width_ = width;
	height_ = height;
}
// setLocation �� ��ġ�� �����ϴ� �Լ�  (��ư��ġ�� ����)
void JButton::setLocation(int x, int y) {
	x_ = x;	
	y_ = y;
}
// setSize�� ũ�⸦ �����ϴ� �Լ�  (����� ����)
void JButton::setSize(int width, int height) {
	width_ = width;
	height_ = height;
}

// ��ư�� �׸��� �Լ�
void JButton::repaint() {
	if (parent_ != nullptr && parent_->getGraphics() != nullptr) {
		Graphics* g = parent_->getGraphics();
		g->drawRect(x_, y_, width_, height_); 
		g->drawString(title_, x_ + 5 , y_ + 5); 
	}
}
// ��ũ�� ��ü �����͸� �����ϴ� �Լ�
void JButton::setParent(Screen* scr) {
	parent_ = scr;
}
// �ش� ��ġ�� ��ư�� �ִ��� �˷��ִ� �Լ�
bool JButton::areYouThere(int x, int y) {
	if (x >= x_ && x <= x_ + width_ && y >= y_ && y <= y_ + height_) {
		return true;
	}
	else {
		return false;
	}
}

// ��ư ����(��ɾ�� Ȱ��)�� �����ִ� �Լ� 1109�������� �ʿ� ���� �� ����.
std::string JButton::getActionString() {
	return title_;
}
// ��ư Ŭ���Ǹ� �ڵ� ȣ��Ǵ� �Լ�

void JButton::onClick() {
}