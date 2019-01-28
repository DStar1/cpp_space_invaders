/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 00:33:43 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/27 00:33:47 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.hpp"

Missile::Missile(void)
{
	return ;
}
Missile::~Missile(void)
{
	std::cout << "Missile Destroyed" << std::endl;
}
Missile::Missile(Missile const & src)
{
	*this = src;
}
Missile 		&Missile::operator=(Missile const & rhs)
{
	if (this == &rhs)
		return (*this);
	this->x = rhs.getX();
	this->y = rhs.getY();
	this->N = rhs.getN();
	return (*this);
}
void 		Missile::clearMissile(void)
{
	mvaddch(this->getY(), this->getX(), ' ');
	// usleep(100);
	refresh();
}

void 		Missile::killMissile(void)
{
	this->clearMissile();
	this->setN(0);
}
void 		Missile::moveUp(void)
{
	mvaddch(this->getY(), this->getX(), ' ');
	this->setY(this->getY() - 1);
}
void 		Missile::drawMissile(Game *game)
{
	if (this->getN() > 0 && (this->getY() > 0 && this->getY() < game->getMapY() - 1))
	{
		this->moveUp();
		attron(COLOR_PAIR(3));
		mvaddch(this->getY(), this->getX(), '0');
		attroff(COLOR_PAIR(3));
		box(stdscr, 0, 0);
		refresh();
		// usleep(10000); // creates small delay for the enemies as they move left to right and back.
	}
	else
		this->N = 0;
}
int			Missile::missileCollision(int nx, int ny)
{
	if ((this->getY() == ny && this->getX() == nx))
	//  ||
	// 	(this->getY() == ny && this->getX() == nx+1) ||
	// 	(this->getY() == ny && this->getX() == nx-1) ||
	// 	(this->getY() == ny-1 && this->getX() == nx-1) ||
	// 	(this->getY() == ny-1 && this->getX() == nx-1) ||
	// 	(this->getY() == ny+1 && this->getX() == nx+1) ||
	// 	(this->getY() == ny+1 && this->getX() == nx+1) ||
	// 	(this->getY() == ny-1 && this->getX() == nx+1) ||
	// 	(this->getY() == ny-1 && this->getX() == nx+1))
	{
		this->killMissile();
		// box(stdscr, 0, 0);
		// refresh();
		return 1;
	}
	return 0;
}
