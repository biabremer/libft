/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sqrt.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 17:56:49 by bbremer       #+#    #+#                 */
/*   Updated: 2019/01/25 18:13:26 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int x;
	int xsqr;

	x = 1;
	xsqr = 0;
	while (xsqr < nb)
	{
		xsqr = x * x;
		x++;
	}
	if (xsqr == nb)
	{
		return (xsqr);
	}
	return (0);
}
