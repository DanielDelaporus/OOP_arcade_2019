/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Debian]
** File description:
** Lib_arcade_sfml
*/

#ifndef LIB_ARCADE_SFML_HPP_
#define LIB_ARCADE_SFML_HPP_

#include "../IgraphicLib.hpp"

class Lib_arcade_sfml : public IgraphicLib{
    public:
        Lib_arcade_sfml();
        ~Lib_arcade_sfml();
        virtual void refresh() override;
        virtual void clear() override;

    protected:
    private:
};

#endif /* !LIB_ARCADE_SFML_HPP_ */
