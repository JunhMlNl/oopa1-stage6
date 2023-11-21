#include "PainterScreen.h"
#include "PainterButton.h"
#include "Etc.h"

PainterScreen::PainterScreen():Screen() {
}

PainterScreen::PainterScreen(std::wstring title, int width, int height) : Screen(title,width, height){
}

void PainterScreen::repaint() {
	//��ư�׸���.
	Screen::repaint(); 
	// ������ �׸���.
	for (int i = 0; i < numShape; i++) {
		myshape[i]->draw();
	}
}

bool PainterScreen::eventHandler(MyEvent e) {
	if (e.isLButtonDownEvent()) {
		// ���⼭�� ��ư�� Ŭ���� ������ Ȯ���ϰ�(findButton)
		// �ű⿡ �´� �׼��� �ϸ� �ȴ�.
		// ��ư�� �������̶�� ���� ��ư�� �����Ѿ��Ѵ�.(��� ���� ���)   //tempBtn�� ���
		// �ƴ϶�� ����ó�� ��ġ�� ����Ų��.
		tempBtn = findButton(e);

		if (tempBtn == nullptr) {
			onLButtonDown(e);
		}
	}
	else if (e.isLButtonUpEvent()) {
		// ���⼭�� ��ư�� Ŭ���� ������ Ȯ���ϰ�(findButton)
		// �ű⿡ �´� �׼��� �ϸ� �ȴ�.
		// ������ ������ ��ư�̶�� (button down �ÿ� ���) ��ư�� onclick�� ȣ��.
		// ��ư�� �����µ� �� ���� �� ��ư ��ġ�� �ƴ� ���,
		// �� ���� ��ư�ε� ���� ��ư�� �ٸ��ų� ��ư�� ���� ���� ������ �ƹ� �ϵ� ���Ѵ�.
		JButton* jb = findButton(e);

		if (jb == nullptr && tempBtn == nullptr) {
			onLButtonUp(e);
		}
		else if (jb == tempBtn) {
			tempBtn->onClick(); //���⼭ FigType����.
		}

		tempBtn = nullptr;
	}
	return false;
}

void PainterScreen::initialize() {
	JButton* jb1 = new PainterButton("�簢��");
	addButton(jb1); jb1->setBounds(10, 10, 100, 25); //���� ���� ���ص� �� �� ����
	JButton* jb2 = new PainterButton("Ÿ��");
	addButton(jb2); jb2->setBounds(120, 10, 100, 25);
}

void PainterScreen::setFigType(JButton *jb) {
	if (jb->getActionString() == "�簢��") {
		figType_ = 1;
	}
	else if (jb->getActionString() == "Ÿ��") {
		figType_ = 2;
	}
}

void PainterScreen::onLButtonDown(MyEvent e) {
	startx = e.getX();
	starty = e.getY();
}

void PainterScreen::onLButtonUp(MyEvent e) {
	endx = e.getX();
	endy = e.getY();
	if (figType_ == 1) {
		rect = new MyRect(startx, starty, endx, endy, graphics_);
		myshape[numShape++] = rect;
	}
	else if (figType_ == 2) {
		oval = new MyOval(startx, starty, endx, endy, graphics_);
		myshape[numShape++] = oval;
	}
	invalidate();
}


