/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:30:44 by dulrich           #+#    #+#             */
/*   Updated: 2024/08/18 10:19:02 by dulrich          ###   ########.fr       */
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
	int				biggest;
	int				smallest;
} t_link;

//main.c
int		main(int argc, char **argv);
void	init_stack(t_link **stack, char **argv, int flag);
void	init_link(t_link **stack, int nbr, char **argv, int flag);

//utils.c
int		stack_len(t_link *stack);
long	ft_atol(char *str);
int		chunk_is_done(t_link **head, int chunk);

//free.c
void	free_links(t_link **stack);
void	free_artificial_argv(char **argv);
void	print_stack(t_link *stack, char *name);

//checks.c
int		is_sorted(t_link *stack, int reverse);
int		is_duplicate(t_link *stack, int nbr);
int		is_syntax_error(char *str);

//push.c
void	pb(t_link **a, t_link **b);
void	pa(t_link **a, t_link **b);
void	push(t_link **dest, t_link **src);

//rotate.c
void	rotate(t_link **stack, int reverse);
void	rb(t_link **b);
void	ra(t_link **a);
void	rr(t_link **a, t_link **b);

//rev_rotate.c
void	rra(t_link **a);
void	rrb(t_link **b);
void	rrr(t_link **a, t_link **b);

//swap.c
void	sb(t_link **b);
void	sa(t_link **a);
void	swap(t_link **stack);

//push_swap.c
void	sort_three(t_link **stack);
void	sort_five(t_link **a, t_link **b);
void	sort_all(t_link **a, t_link **b, int amount);
void	push_swap(t_link **a, t_link **b);

//ps_utils.c
void	allocate_chunks(t_link **stack, int *nbrs, int max_chunk, int nbrs_per_chunk);
void	last_rotation(t_link **stack);
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
void	get_cheapest_link(t_link **a, t_link **b, int chunk);
void	push_cheapest(t_link **a, t_link **b, t_link *first_link, t_link *second_link);
int		choose_insertion(t_link **stack, t_link *link);

//sorting_utils.c
t_link	*calc_moves_to_push(t_link **stack, t_link *link, int first);
int		compare_moves(t_link *first, t_link *second);
t_link	*find_second_match(t_link **stack, t_link *link);
t_link	*find_first_match(t_link **stack, t_link *link);

#endif