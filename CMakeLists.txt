cmake_minimum_required(VERSION 3.20)
project(MegaWar)

set(CMAKE_CXX_STANDARD 14)

add_executable(MegaWar main.cpp Card.cpp Card.h Deck.cpp Deck.h CardPile.cpp CardPile.h Player.cpp Player.h WarPile.cpp WarPile.h LostAndFound.cpp LostAndFound.h MegaDeck.cpp MegaDeck.h)
