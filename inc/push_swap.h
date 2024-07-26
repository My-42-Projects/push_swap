/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:30:44 by dulrich           #+#    #+#             */
/*   Updated: 2024/07/25 21:31:32 by dulrich          ###   ########.fr       */
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
	int				rr;
	int				rrr;
} t_link;

//main.c
int		main(int argc, char **argv);
void	init_stack(t_link **stack, char **argv, int flag);
void	init_link(t_link *stack, int nbr, char **argv, int flag);

//utils.c
t_link	*get_last_link(t_link **head);
t_link	*clone_stack(t_link **a, t_link **c);
int		stack_len(t_link **stack);
long	ft_atol(char *str);

//free.c
void	free_links(t_link **stack);
void	free_artificial_argv(char **argv);

//checks.c
int		is_sorted(t_link *stack, int reverse);
int		is_duplicate(t_link *stack, int nbr);
int		is_syntax_error(char *str);

//push.c
void	pb(t_link **a, t_link **b);
void	pa(t_link **a, t_link **b);
void	push(t_link **dest, t_link **src);

//rotate.c


//swap.c


//ps_utils.c
int		chunk_is_done(t_link **head, int chunk);

//error.c
void	ft_error(t_link **stack, char **argv, int flag);

//push_swap.c
void	sort_three(t_link *stack);
void	sort_five(t_link *a, t_link *b);
void	sort_all(t_link **a, t_link **b, int amount);
void	push_swap(t_link **a, t_link **b);

//quicksort.c
void	find_index(t_link *a);

//sorting.c
void	get_cheapest_link(t_link **a, t_link **b, int chunk);
void	push_cheapest(t_link **a, t_link **b, t_link *first_node, t_link *second_node);
void	choose_insert(t_link **stack, int index);

//sorting_utils.c
t_link	*find_right_spot(t_link **stack, int index, int flag);
t_link	*calc_moves_to_push(t_link **stack, t_link *link, int flag);
int		compare_moves(t_link *first, t_link *second);
t_link	*find_second_match(t_link **stack, t_link *link);
t_link	*find_first_match(t_link **stack, t_link *link);

#endif