/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:07:31 by mahoang           #+#    #+#             */
/*   Updated: 2019/11/12 18:19:05 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int ac, char **av)
{
	int i = 44;
	char c = 'v';
	char s[10] = "prout";
	printf("%c et %i et %s\n", c, i, s);
	printf("%d", ft_atoi(s[10]));
}
 //https://www.rocq.inria.fr/secret/Anne.Canteaut/COURS_C/cours.pdf

// Par conséquent, pour une gestion de ressources plus optimisée, la bibliothèque « stdarg » de la librairie C met à
// disposition une liste chaînée qui répartit dans la mémoire les éléments de notre liste et les relie entre eux par des
// pointeurs. En effet, la manipulation des arguments dans une fonction variadique se fait à l’aide des macros
// « va_start », « va_arg », « va_end » et d’un pointeur « va_list ».

// // « va_list » est un pointeur qui permet de récupérer le premier élément de la liste d’argument,

// // « va_start » permet de commencer à parcourir la liste chaînée d’arguments en paramètre de la fonction

// // « va_arg » permet de récupérer un argument de la liste d’arguments à chaque appel,

// // « va_end » signale que l’on a fini de parcourir la liste d’arguments.


// // La logique globale de la gestion des arguments à nombre variable appliquée à « printf » est la suivante :

// // Dans un premier temps, on crée un pointeur qui pointe sur le premier élément de la liste d’arguments variables.

// // Il faut ensuite l’initialiser pour qu’il pointe sur le premier argument à l’aide de la fonction « va_start ».

// // On commence à parcourir notre chaîne de caractères à la recherche du caractère ‘%’ qui indique la présence potentielle
// d’un argument à afficher : si c’est le cas, on affiche l’argument et on passe au suivant en utilisant « va_arg » ;
// si ça ne l’est pas, on affiche le caractère.

// Une fois la liste d’arguments entièrement parcourue, on fait appel à la fonction « va_end ».
