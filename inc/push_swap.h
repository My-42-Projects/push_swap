/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:30:44 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/16 18:53:37 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_link
{
	struct s_link	*next;
	struct s_link	*prev;
	int				nbr;
	int				index;
	int				chunk;
	int				moves_to_push;
	int				rr;
	int				rrr;
} t_link;

//Functions

#endif