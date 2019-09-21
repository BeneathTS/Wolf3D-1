#ifndef DRAW_H
# define DRAW_H

typedef struct		s_bsp
{
	struct s_bsp	*front;
	struct s_bsp	*back;
}					t_bsp;

void				bsp_creator(void);
#endif