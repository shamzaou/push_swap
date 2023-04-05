static void	ps_print_list_operations(t_push_swap *ps)
{
	t_op *tmp;

	ps_operation_revers(&ps->op);
	tmp = ps->op;
	while (tmp)
	{
		ft_printf("%s\n", ps_get_operation(tmp->n));
		tmp = tmp->next;
	}
}

static void	ps_print_usage(void)
{
	ft_putstr("Usage 🚀🚀🚀 : ./push_swap \
[integer values that are not in order ...]\n");
	exit(0);
}

int			main(int argc, char **argv)
{
	t_push_swap ps;

	if (argc > 1)
	{
		ps_init(&ps);
		ps_parser(&ps, argv + 1);
		ps_quick_sort(&ps);
		ps_print_list_operations(&ps);
		ps_free(&ps);
	}
	else
		ps_print_usage();
	return (0);
}

static int	ps_get_right_radius(double size_a)
{
	int		size;
	double	radius;

	size = 100;
	radius = 3;
	while (size < size_a)
	{
		size *= 2.24;
		radius++;
	}
	return (radius);
}

void		ps_quick_sort(t_push_swap *ps)
{
	ps->search_radius = ps_get_right_radius((double)ps->size_a);
	if (ps_sort_first_stage(ps))
		return ;
	ps_sort_second_stage(ps);
}

static void	ps_sort_last_3_numbers(t_push_swap *ps, t_stack *stk)
{
	if (stk->n < stk->next->n && stk->n < stk->next->next->n
		&& stk->next->n < stk->next->next->n)
		return ;
	else if (stk->n < stk->next->n && stk->n < stk->next->next->n
			&& stk->next->n > stk->next->next->n)
	{
		ps_sort_make_op(ps, RRA);
		ps_sort_make_op(ps, SA);
	}
	else if (stk->n > stk->next->n && stk->n < stk->next->next->n
			&& stk->next->n < stk->next->next->n)
		ps_sort_make_op(ps, SA);
	else if (stk->n < stk->next->n && stk->n > stk->next->next->n
			&& stk->next->n > stk->next->next->n)
		ps_sort_make_op(ps, RRA);
	else if (stk->n > stk->next->n && stk->n > stk->next->next->n
			&& stk->next->n < stk->next->next->n)
		ps_sort_make_op(ps, RA);
	else if (stk->n > stk->next->n && stk->n > stk->next->next->n
			&& stk->next->n > stk->next->next->n)
	{
		ps_sort_make_op(ps, SA);
		ps_sort_make_op(ps, RRA);
	}
}

static int	ps_sort_if_rr_ss_sa(t_push_swap *ps)
{
	if (ps->size_b > 2 && ps->b->n < ps->b->next->n)
	{
		if (ps->b->n < ps->b->next->next->n)
			return (RR);
		return (SS);
	}
	return (RA);
}

static void	ps_sort_search_and_push_b(t_push_swap *ps)
{
	int min;
	int op;

	min = ps_sort_get_op_num(ps, 1);
	if (ps_sort_in_half_case(ps->a, min, 1))
	{
		while ((op = ps_sort_if_can_move_up(ps->a, ps->size_a, min)) > 0)
		{
			if (op == 1 || op == 3)
				ps_sort_make_op(ps, ps_sort_if_rr_ss_sa(ps));
			else if (op == 2)
				ps_sort_make_op(ps, RRA);
		}
		ps_sort_make_op(ps, PB);
	}
	else
		ps_sort_make_op(ps, ps_sort_if_rr_ss_sa(ps));
}

int			ps_sort_first_stage(t_push_swap *ps)
{
	int sort;

	while (!(sort = ps_stack_is_sorted(ps->a)) && ps->size_a > 3)
		ps_sort_search_and_push_b(ps);
	if (ps->size_a == 3)
		ps_sort_last_3_numbers(ps, ps->a);
	else if (!sort && ps->size_a == 2)
		ps_sort_make_op(ps, SA);
	if (!ps->b && ps_stack_is_sorted(ps->a))
		return (1);
	return (0);
}

static void	ps_sort_spin_drum_up(t_push_swap *ps, int max)
{
	int op;

	while (ps->a_end->n < ps->a->n && ps->a_end->n > max)
	{
		op = ps_sort_if_can_move_up(ps->b, ps->size_b, max);
		if (op == 2)
			ps_sort_make_op(ps, RRR);
		else
			ps_sort_make_op(ps, RRA);
	}
}

static void	ps_sort_spin_drum_down(t_push_swap *ps, int max)
{
	int op;

	while (ps->a->n < max)
	{
		op = ps_sort_if_can_move_up(ps->b, ps->size_b, max);
		if (op == 1 || op == 3)
			ps_sort_make_op(ps, RR);
		else
			ps_sort_make_op(ps, RA);
	}
}

static void	ps_sort_search_and_push_a(t_push_swap *ps)
{
	int max;
	int op;

	max = ps_sort_get_op_num(ps, 2);
	if (ps_sort_in_half_case(ps->b, max, 2))
	{
		if (ps->a_end->n < ps->a->n && ps->a_end->n > max)
			ps_sort_spin_drum_up(ps, max);
		if (ps->a->n < max)
			ps_sort_spin_drum_down(ps, max);
		while ((op = ps_sort_if_can_move_up(ps->b, ps->size_b, max)) > 0)
		{
			if (op == 1 || op == 3)
				ps_sort_make_op(ps, RB);
			else if (op == 2)
				ps_sort_make_op(ps, RRB);
		}
		ps_sort_make_op(ps, PA);
	}
	else
		ps_sort_make_op(ps, RB);
}

void		ps_sort_second_stage(t_push_swap *ps)
{
	while (ps->b)
		ps_sort_search_and_push_a(ps);
}

int			ps_sort_if_can_move_up(t_stack *stk, int size, int num)
{
	int		pos;

	pos = 1;
	while (stk)
	{
		if (stk->n == num)
			break ;
		pos++;
		stk = stk->next;
	}
	if (pos == 1)
		return (0);
	else if (pos == 2)
		return (3);
	else if (((size / 2) + 1) >= pos)
		return (1);
	else
		return (2);
}

int			ps_sort_in_half_case(t_stack *stk, int num, int min_or_max)
{
	int less;
	int more;

	less = 0;
	more = 0;
	while (stk)
	{
		if (stk->n > num)
			more++;
		else
			less++;
		stk = stk->next;
	}
	if (min_or_max == 1)
		return ((less <= ((more + less + 1) / 5)) ? 1 : 0);
	else if (min_or_max == 2)
		return ((less >= ((more + less + 1) / 5)) ? 1 : 0);
	return (0);
}

int			ps_sort_get_search_numbers(t_stack *start, t_stack *end,
									int size, int min_or_max)
{
	int	i;
	int	n;

	i = 0;
	n = start->n;
	while (i < (size / 2) && start)
	{
		if (min_or_max == 1 && start->n < n)
			n = start->n;
		else if (min_or_max == 2 && start->n > n)
			n = start->n;
		start = start->next;
		i++;
	}
	while (i < size && end)
	{
		if (min_or_max == 1 && end->n < n)
			n = end->n;
		else if (min_or_max == 2 && end->n > n)
			n = end->n;
		end = end->prev;
		i++;
	}
	return (n);
}

int			ps_sort_get_op_num(t_push_swap *ps, int min_or_max)
{
	if (min_or_max == 1)
		return (ps_sort_get_search_numbers(ps->a, ps->a_end,
				ps->search_radius * 2, 1));
	else if (min_or_max == 2)
		return (ps_sort_get_search_numbers(ps->b, ps->b_end,
				ps->search_radius * 2, 2));
	else
		return (0);
}

void		ps_sort_make_op(t_push_swap *ps, int op)
{
	ps_make_operation(ps, op);
	ps_operation_push(&ps->op, op);
}
