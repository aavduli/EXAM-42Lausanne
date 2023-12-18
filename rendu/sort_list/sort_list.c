void	swap_values(t_list *a, t_list *b)
{
	int swap = a->data;
	a->data = b->data;
	b->data = swap;
}

t_list *sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *head = lst;
	int swapped = 1;

	while(swapped == 1)
	{
		swapped = 0;
		while (head != 0 && head->next != 0)
		{
			if (cmp(head->data, cur->next->data) == 0)
			{
				swap_values(head, head->next);
				swapped = 1;
			}
			head = head->next;
		}
		head = lst;
	}
	return (lst);
}
void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int swapped = 1;

	while (swapped == 1)
	{
		i = 1;
		swapped = 0;
		while(i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				swap_values(&tab[i - 1], &tab[i])
				swapped = 1;
			}
			i++;
		}
	}
}
