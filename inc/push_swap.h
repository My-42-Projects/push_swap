/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:30:44 by dulrich           #+#    #+#             */
/*   Updated: 2024/09/24 08:53:26 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_link
{
	struct s_link	*next;
	struct s_link	*prev;
	struct s_link	*target;
	bool			above_mid;
	int				nbr;
	int				index;
	int				pos;
	int				ops;
}	t_link;

//main.c
int		main(int argc, char **argv);
void	init_link(t_link **stack, int nbr, char **argv, bool to_free);
void	init_stack(t_link **stack, char **argv, bool to_free);

//push_swap.c
void	push_swap(t_link **a, t_link **b);
void	sort_all(t_link **a, t_link **b);
void	sort_three(t_link **stack);

//utils.c
int		stack_len(t_link *stack);
long	ft_atol(char *str);
void	print_stack(t_link *stack, char *name);

//free.c
void	free_links(t_link **stack);
void	free_artificial_argv(char **argv);

//checks.c
int		is_sorted(t_link **stack, int reverse);
int		is_duplicate(t_link *stack, int nbr);
int		is_syntax_error(char *str);

//push.c
void	pb(t_link **a, t_link **b);
void	pa(t_link **a, t_link **b);
void	push(t_link **dest, t_link **src);

//rotate.c
void	rotate(t_link **stack);
void	ra(t_link **a);
void	rb(t_link **b);
void	rr(t_link **a, t_link **b);
void	rotate_both(t_link **a, t_link **b, t_link *link, bool reverse);

//rev_rotate.c
void	rev_rotate(t_link **stack);
void	rra(t_link **a);
void	rrb(t_link **b);
void	rrr(t_link **a, t_link **b);

//swap.c
void	swap(t_link **stack);
void	sb(t_link **b);
void	sa(t_link **a);

//ps_utils.c
void	allocate_index(t_link **stack, int *nbrs);
void	last_rotation(t_link **stack);
void	find_pos(t_link *stack);

//get_links.c
t_link	*get_smallest_link(t_link *stack);
t_link	*get_biggest_link(t_link *stack);
t_link	*get_last_link(t_link *head);
t_link	*get_first_link(t_link *head);
t_link	*get_closest_link(t_link **stack, t_link *link);

//error.c
void	ft_error(t_link **stack, char **argv, int flag);
void	ps_error(t_link **stack);

//quicksort.c
void	find_index(t_link *a);

//sorting.c
void	push_cheapest(t_link **a, t_link **b, t_link *to_push);
void	get_cheapest_link(t_link **a, t_link **b);

//sorting_utils.c
t_link	*compare_operations(t_link **stack);
void	finish_rot(t_link **stack, t_link *to_top, char name);
void	calc_total_ops(t_link **a, t_link **b, t_link *link);

#endif