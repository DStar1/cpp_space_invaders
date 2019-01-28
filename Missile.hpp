/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:23:48 by lhernand          #+#    #+#             */
/*   Updated: 2019/01/26 17:23:49 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_HPP
# define MISSILE_HPP
# include "Game.hpp"
# include "Junk.hpp"
# include <unistd.h> // library for usleep
class Missile : public Junk
{
	public:
		Missile(void);
		~Missile(void);
		Missile(Missile const & src);
		Missile &operator=(Missile const & rhs);

		// void 		setY(int y);
		//methods for movement
		void 		moveUp(void);
		//methods for game mechanics using ncursus
		void 		drawMissile(Game *game);

};

#endif
