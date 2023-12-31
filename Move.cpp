//
//  Move.cpp
//  Bunco
//
//  Created by Howard Stahl on 2/21/22.
//  Copyright © 2022 Howard Stahl. All rights reserved.
//

#include "Move.h"
#include <stdexcept>

namespace cs31
{

// by default, a move is invalid
Move::Move()
{
    // this code is really not needed since the default constructor
    // will do all this work but I am explicitly showing it for CS 31
    // students
    Piece p;  // invalid piece
    for( int i = 0; i < REQUIREDLENGTH; i++)
    {
        array[ i ] = p;
    }
}

// trivial getter
// but throw logic_error if the index is out of range
Piece Move::getPiece( int i )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        return( array[ i ] );
    else
        throw std::logic_error( "invalid i value" );
}

// construct a Piece for the Move from the character parameter
// but throw logic_error if the index is out of range
void  Move::setPiece( int i, char c )
{
    if (i >= 0 && i < REQUIREDLENGTH)
    {
        Piece p( c );
        array[ i ] = p;
    }
    else
        throw std::logic_error( "invalid i value" );
}

// construct a Piece for the Move from the Piece parameter
// but throw logic_error if the index is out of range
void  Move::setPiece( int i, Piece p )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        array[ i ] = p;
    else
        throw std::logic_error( "invalid i value" );
}

// construct a Piece for the Move from the first letter
// of the string parameter
// but throw logic_error if the index is out of range
void  Move::setPiece( int i, std::string s )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        setPiece( i, s.at( 0 ) );
    else
        throw std::logic_error( "invalid i value" );
}

// Attempted TODO create the Pieces for this Move from the supplied word
// Attempted TODO throw logic_error if the supplied word is too short or too long
//This operation should accept a five-character string and set each Piece of this Move object to the character provided in the string parameter.  If the string parameter is not five letters long, this operation should throw a std::logic_error back at the calling code.
void  Move::setPieces( std::string s )
{
    if (s.length()!=5)
    {
        throw std::logic_error("The word must be 5 letters long");
    }
    
    for (int i = 0; i < s.length(); i++)
    {
        setPiece(i, s.at(i));
        setPiece(i, s);
        setPiece(i, Piece(s.at(i)));
    }
}

// stringify this Move
std::string Move::to_string() const
{
    std::string s;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        s += array[ i ].getLetterAsString();
    }
    return( s );
}


}
