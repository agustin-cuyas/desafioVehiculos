# Primer desafío C++
## Sistema de Gestión de Vehículos

Para el desarrollo del desafío, primero identifiqué las clases que se requerían y luego las definí con sus métodos y atributos. Posteriormente desarrollé las funciones ingresarInfo, mostrarInfo y el main para finalmente implementar las funciones de cargarBateria y conducir.

En el proceso tuve que decidir en qué orden ejecutar los métodos y dónde, por ejemplo el caso de llamar a conducir una vez que se mostraron todos los vehiculos. Además me encontré con el problema de los constructores:
  `Para construir los objetos, usamos el constructor de vehiculo y agregamos la característica particular de auto, moto y camión.
    En el caso de los vehículos eléctricos, usamos el constructor del auto, moto o camión y agregamos el contructor de electricidad para incluir la batería.
    Esto se debe a que los constructores de las subclases no heredan los atributos.`

El primer desafío fue implementar la colección para cargar multiples vehiculos, una vez solucionado eso avancé sin mayores problemas hasta finalizarlo.
