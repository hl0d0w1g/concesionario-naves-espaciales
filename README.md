# Concesionario de Naves Espaciales

Programa de consola escrito en **C++** que simula la aplicacion de un concesionario de naves espaciales. En ella se podran dar de alta usuarios de tipo humano y extraterreste y naves de los tipos estación espacial, destructores, cargueros espaciales y cazas. Se podrán hacer compras de las naves por parte de los usuarios y guarda todos los datos de la aplicación en archivos *.txt*.

*Programado en linux.*

## Intrucciones de uso

* En el menú 'gestionar propietarios' se puede dar de alta o de baja un usuario tanto del tipo humano como extraterrestre, asi como editar sus datos. También se podrá ver una lista de los usuarios dados de alta en el sistema. Los usuarios se caracterizan por su número de identificación (8 número y una letra para humanos y 9 números para extraterrestres) y su planeta de residencia.

* En el menú 'gestionar naves' se puede dar de alta o de baja una nave de cualquiera de los 4 tipos disponibles, asi como editar sus datos. También se podrá ver una lista de las naves dadas de alta en el sistema. Las naves tienen caracteristicas comunes como son la matricula (una letra seguida de 4 números y 3 letras), el número de tripulantes, el tipo de propulsión y el precio de venta. El resto de caracteristicas son especificas de cada nave.

*  En el menú 'operaciones de compra' se permitirá a los usuarios registrados en el sistema comprar naves que también esten registradas en el sistema. Los humanos tendrán permitido comprar destructores y los extraterrestres no podrán comprar estaciones espaciales. Para realizar una compra se deberá introducir la identificación de un usuario y elegir una nave entre las mostradas por pantalla y se realizará la operación.

*  En el menú 'visualizar historico' se mostrará un listado de las compras realizadas.

*  En el menú 'buscar ventas' se podrá realizar una busqueda de una o varias ventas en concreto, pudiendose introducir como parametros de busqueda una fecha concreta, un intervalo de tiempo o la indetificación de un usuario para ver las ventas que se le realizarón.

## Autor

* **Luis Cambero** - [lcambero](https://github.com/lcambero)

## Ultima actualización

Domingo 10 de diciembre de 2017

## Licencia

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
