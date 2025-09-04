/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:55:55 by vgalmich          #+#    #+#             */
/*   Updated: 2025/09/04 13:58:30 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FormClass/Form.hpp"

int main()
{
    try
    {
        std::cout << CYAN << "=== Bureaucrates creation ===" << RESET << std::endl;
        Bureaucrat bob("Vero", 50);
        Bureaucrat jim("Vivi", 120);
        Bureaucrat alice("Kim", 1);

        std::cout << bob << std::endl;
        std::cout << jim << std::endl;
        std::cout << alice << std::endl;

        std::cout << "\n=== Création des formulaires ===" << std::endl;
        Form contract("Contract", 100, 50);
        Form topSecret("TopSecret", 20, 5);

        std::cout << contract << std::endl;
        std::cout << topSecret << std::endl;

        std::cout << "\n=== Tentatives de signature ===" << std::endl;
        bob.signForm(contract);       // OK (50 <= 100)
        jim.signForm(contract);       // KO (120 > 100)
        jim.signForm(topSecret);      // KO (120 > 20)
        bob.signForm(topSecret);      // KO (50 > 20)
        alice.signForm(topSecret);    // OK (1 <= 20)

        std::cout << "\n=== État final des formulaires ===" << std::endl;
        std::cout << contract << std::endl;
        std::cout << topSecret << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }

    return 0;
}