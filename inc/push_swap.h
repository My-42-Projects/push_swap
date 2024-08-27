/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:30:44 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/27 16:16:29 by dulrich          ###   ########.fr       */
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
	int				r;
	int				rr;
	int				target_r;
	int				target_rr;
	int				reverse;
	int				biggest;
	int				smallest;
	int				ops;
	int				target;
	int				above_mid;
	int				below_mid;
} t_link;

//main.c
int		main(int argc, char **argv);
void	init_stack(t_link **stack, char **argv, int flag);
void	init_link(t_link **stack, int nbr, char **argv, int flag);

//push_swap.c
void	sort_three(t_link **stack);
// void	sort_five(t_link **a, t_link **b);
void	sort_all(t_link **a, t_link **b);
void	push_swap(t_link **a, t_link **b);
void	push_back(t_link **a, t_link **b);

//utils.c
int		stack_len(t_link *stack);
long	ft_atol(char *str);
int		chunk_is_done(t_link **head, int chunk);

//free.c
void	free_links(t_link **stack);
void	free_artificial_argv(char **argv);
void	print_stack(t_link *stack, char *name);

//checks.c
int		is_sorted(t_link **stack, int reverse);
int		is_duplicate(t_link *stack, int nbr);
int		is_syntax_error(char *str);

//push.c
void	pb(t_link **a, t_link **b);
void	pa(t_link **a, t_link **b);
void	push(t_link **dest, t_link **src);

//rotate.c
void	rotate(t_link **stack, int reverse);
void	ra(t_link **a);
void	rb(t_link **b);
void	rr(t_link **a, t_link **b);
void	rotate_both(t_link **a, t_link **b, t_link *one, t_link *two, int i);

//rev_rotate.c
void	rra(t_link **a);
void	rrb(t_link **b);
void	rrr(t_link **a, t_link **b);
int		calc_rot_both(t_link *first, t_link *second);
int		calc_rev_rot_both(t_link *first, t_link *second);

//swap.c
void	swap(t_link **stack);
void	sb(t_link **b);
void	sa(t_link **a);

//ps_utils.c
void	allocate_chunks(t_link **stack, int *nbrs, int max_chunk, int nbrs_per_chunk);
void	last_rotation(t_link **stack, int is_a);
int		determine_rotation(t_link **stack, t_link *link);

//get_links.c
t_link	*get_smallest_link(t_link *stack);
t_link	*get_biggest_link(t_link *stack);
t_link	*get_last_link(t_link *head);
t_link	*get_first_link(t_link *head);
int		is_closer(int to_push, int closest, int current);
t_link	*get_closest_link(t_link **stack, t_link *link, int is_bigger);

//error.c
void	ft_error(t_link **stack, char **argv, int flag);
void	ps_error(t_link **stack);

//quicksort.c
void	find_index(t_link *a);
int		*get_ints(t_link *stack);
int		*quicksort(int *nbrs, int first, int last);
int		partition(int *nbrs, int first, int last);

//sorting.c
void	get_cheapest_link(t_link **a, t_link **b);
void	push_cheapest(t_link **a, t_link **b, t_link *one, t_link *two);
void	finish_rot(t_link **a, t_link **b, t_link *to_push, t_link *target);
void	find_target_above_mid(t_link *target, t_link **stack, int is_bigger);
void	find_target_below_mid(t_link *target, t_link **stack, int is_bigger);
int		calc_remaining_ops(t_link *link, t_link *target, int i);
int		place_in_b(t_link *link, t_link *target, t_link **stack, int is_bigger);
void	find_correct_position(t_link **b, t_link *link);
t_link	*compare_operations(t_link **stack);
void	moves_to_top_of_a(t_link **stack, t_link *link);
t_link	*get_target(t_link **stack, t_link *to_push);

//sorting_utils.c
t_link	*calc_moves_to_push(t_link **stack, t_link *link, int first);
int		compare_moves(t_link *first, t_link *second);
t_link	*find_second_match(t_link **stack, t_link *link);
t_link	*find_first_match(t_link **stack, t_link *link);

#endif