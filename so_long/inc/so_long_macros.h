/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_macros.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:57:56 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 20:57:58 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MACROS_H
# define SO_LONG_MACROS_H

# define ERROR	-1

# define WALL			'1'
# define EMPTY			'0'
# define START			'P'
# define EXIT			'E'
# define COLLECTABLE	'C'

# define LEFT		0
# define RIGHT		2
# define UP			13
# define DOWN		1
# define EXITCODE	53

# define UP_DIR			0
# define LEFT_DIR		1
# define RIGHT_DIR		2
# define DOWN_DIR		3

# define CANTMOVE		0
# define POSMOVE		1
# define WINMOVE		2

# define WRONG_NUM_OF_ARGS			1
# define CANNOT_READ				2
# define WRONG_LETTER				3
# define MISSING_PART				4
# define NOT_RECTANGULAR			5
# define NOT_SURROUNDED_WALLS		6
# define WRONG_FILE_NAME			7

# define WRONG_NUM_OF_ARGS_TEXT		"GIVEN MORE THEN 1 ARGUMENT."
# define CANNOT_READ_TEXT			"CANNOT READ FROM MAP THE GIVEN FILE."
# define WRONG_LETTER_TEXT			"THE MAP CONTAINS ADDITIONAL LETTERS, \
WHICH CANNOT BE PARSED."
# define MISSING_PART_TEXT			"THE MAP DOES NOT CONTAIN ONE OR MORE OF THE FOLLOWING ATTRIBUTES: \
A START, AN END OR ANY COLLECTABLES."
# define NOT_RECTANGULAR_TEXT		"GIVEN MAP IS NOT RECTANGULAR."
# define NOT_SURROUNDED_WALLS_TEXT   "THE MAP IS NOT SURROUNDED WITH WALLS."
# define WRONG_FILE_NAME_TEXT		"THE GIVEN FILE NAME IS WRONG"
# define WARNING_TEXT				"\nMAKE SURE YOU GAVE A VALID INPUT"

# define WHITE			0xFFFFFF
# define GREEN			0x107830
# define GREEN1			0xa7f542

# define ENEMY_COUNT	5

# define BLACK_WRITE	"\033[0;30m"				
# define RED_WRITE		"\033[1;31m"			
# define WHITE_WRITE	"\033[0;37m"
# define GREEN_WRITE	"\033[1;32m"
# define SEP_COLOR		"\033[1;36m"

# define ENEMY_MOVE_SPEED		50
# define PLAYER_MOVE_SPEED		50
# define COIN_ANIMATION_SPEED	10
# define CHANGE_DIR_SPEED		100
# define ENEMY_ANIM_SPEED		12

#endif
