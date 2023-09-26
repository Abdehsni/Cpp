#ifndef POSITION_H
#define POSITION_H

/**
 * @brief The Position class
 */
namespace model {

struct Position{
    int row;
    int column;
    /**
     * @brief constructor Position
     * @param row
     * @param column
     */
    Position(int row=0, int column=0);
    /**
     * @brief operator ==
     * @param player
     */
    inline bool operator == (const Position& position)const;
    /**
    * @brief operator !=
    * @param player
    */
    inline bool operator != (const Position& position)const;
    /**
    * @brief operator -
    * @param player
    */
    inline int operator-(Position& position);

};

bool Position::operator==(const Position& position)const{
    if(position.column==this->column && position.row==this->row){
         return true;
    }
        return false;
}

bool Position::operator!=(const Position& position)const{
    if(position.column!=this->column||position.row!=this->row)return true;
    else return false;
}
int Position::operator-( Position& position){
    return (this->row+this->column) -(position.row+position.column);
}

}
#endif // POSITION_H



