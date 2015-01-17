/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:52:22 by gpetrov           #+#    #+#             */
/*   Updated: 2015/01/17 19:17:08 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sys/utsname.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>

int		main()
{		
	struct utsname test;

	uname(&test);
	std::cout << test.sysname << std::endl; 
	std::cout << test.nodename << std::endl; 
	std::cout << test.release << std::endl; 
	std::cout << test.version << std::endl; 
	std::cout << test.machine << std::endl; 
	std::cout << test.nodename << std::endl; 

	struct passwd *passwd;
	passwd = getpwuid(getuid());
	std::cout << passwd->pw_name << std::endl;
}
