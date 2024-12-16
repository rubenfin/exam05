/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   infin_add.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 19:06:03 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/12/16 19:10:51 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct str {
    char *s;
    int sign;
    bool biggest;
} str;