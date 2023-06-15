#pragma once

class Player {
public:
    Player();
    
    void addArrow();
    void remArrow();
    
    unsigned getArrowCount() const noexcept;
    
private:
    unsigned m_arrows;
};
