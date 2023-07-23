#pragma once

class Player {
public:
    Player();
    
    void addArrow();
    void remArrow();
    
    void setLookingDown(bool isLookingDown);
    bool getLookingDown() const;
    
    unsigned getArrowCount() const noexcept;
    
private:
    unsigned m_arrows;
    bool     m_lookingDown;
};
