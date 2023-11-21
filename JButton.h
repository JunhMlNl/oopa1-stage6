#pragma once
#include <string>
#include "Screen.h"
class JButton
{
public:
	JButton();
	JButton(std::string title);

	// setBounds �Լ��� ��ġ�� ũ�⸦ �����ϴ� �Լ�. (��ư�� ũ��)
	void setBounds(int x, int y, int width, int height); 

	// setLocation �� ��ġ�� �����ϴ� �Լ�  (��ư��ġ�� ����)
	void setLocation(int x, int y);

	// setSize�� ũ�⸦ �����ϴ� �Լ�  (����� ����)
	void setSize(int width, int height);

	void repaint();			// ��ư�� �׸��� �Լ�   
	void setParent(Screen*);		// ��ũ�� ��ü �����͸� �����ϴ� �Լ�
	bool areYouThere(int x, int y);  // �ش� ��ġ�� ��ư�� �ִ��� �˷��ִ� �Լ�
	std::string getActionString();	// ��ư ����(��ɾ�� Ȱ��)�� �����ִ� �Լ� 1109�������� �ʿ� ���� �� ����.
	virtual void onClick();			// ��ư Ŭ���Ǹ� �ڵ� ȣ��Ǵ� �Լ�

protected:  // ���߿� ����� ���ؼ� protected�� �ص���.
	std::string title_;	// ��ư ����
	int x_, y_, width_, height_;  // ��ġ �� ũ��
	Screen* parent_;		// screen�� ���� ������.

};

