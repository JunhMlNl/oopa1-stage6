#pragma once
#include "JButton.h"
#include "PainterScreen.h"
class PainterButton :
    public JButton
{
public:
    PainterButton();
    PainterButton(std::string title);
    void onClick() override;
};

