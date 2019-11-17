/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_value.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 09:55:42 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/17 05:30:51 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_VALUE_H
# define DEFINE_VALUE_H

# include "wolf3d.h"

typedef enum			e_type_menu
{
	Menu,
	Choose,
	Game,
	Settings,
	Editor
}						t_type_menu;

typedef enum			e_type_boolean
{
	No,
	Yes
}						t_type_boolean;

# define WIDTH 1280
# define HEIGHT 720

# define LOGO_ALPHA 	0xCD

# define BUTTONS_ALPHA	0x77

# define TEX_SIZE 		64

# define FLOOR_COLOR	0x353C44

# define X 				0
# define Y 				1

# define START 			0
# define FINISH 		1

# define V 				0
# define H 				1

/*
**	MENU
*/
# define BG_IMG 		"assets/menu/XPM/background.xpm"
# define LG_IMG 		"assets/menu/XPM/logo.xpm"
# define LG_BASE 		"assets/menu/XPM/logo_base.xpm"
# define BT1 			"assets/menu/XPM/bt1.xpm"
# define BT2 			"assets/menu/XPM/bt2.xpm"
# define BT3 			"assets/menu/XPM/bt3.xpm"
# define BT4 			"assets/menu/XPM/bt4.xpm"
# define BT1_ACTIVE 	"assets/menu/XPM/bt5.xpm"
# define BT2_ACTIVE 	"assets/menu/XPM/bt6.xpm"
# define BT3_ACTIVE 	"assets/menu/XPM/bt7.xpm"
# define BT4_ACTIVE 	"assets/menu/XPM/bt8.xpm"
# define SCRL_BASE 		"assets/menu/XPM/scroll_base.xpm"
# define SCRL 			"assets/menu/XPM/scroller.xpm"

/*
**	TEXTURE
*/
# define BS_TEX			"assets/textures/xpm/bluestone.xpm"
# define WD_TEX			"assets/textures/xpm/wood.xpm"

#endif
