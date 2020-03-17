/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Lib_arcade_ncurse
*/

#ifndef LIB_ARCADE_NCURSE_HPP_
#define LIB_ARCADE_NCURSE_HPP_

#include "../IgraphicLib.hpp"

class Lib_arcade_ncurse : public IgraphicLib {
    public:
        Lib_arcade_ncurse();
        ~Lib_arcade_ncurse();
        virtual void refresh() override;
        virtual void clear() override;

    protected:
    private:
};

#endif /* !LIB_ARCADE_NCURSE_HPP_ */
