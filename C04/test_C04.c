#include "../common/assert.h"
#include "../common/data.h"
#include "lib_C04.h"
#include <stdlib.h>

#ifndef DATA_PATH
# define DATA_PATH "C04/data.txt"
#endif

static void	test_atoi_base_from_data(void)
{
	t_data_table t;
	if (data_load_section(DATA_PATH, "ft_atoi_base", '|', &t) != 0)
	{
		printf("⚠️  no data for [ft_atoi_base] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; i++)
	{
		const char *s    = t.rows[i].cols[0];
		const char *base = t.rows[i].cols[1];
		long expected    = strtol(t.rows[i].cols[2], NULL, 10);

		int got = ft_atoi_base((char *)s, (char *)base);
		assert_int_eq(got, (int)expected, s);
	}
	data_free(&t);
}

void	test_C04(void)
{
	t_set_suite("C04");
	test_atoi_base_from_data();
	t_summary();
}
