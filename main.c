#include <stdio.h>

int main() {
    int id = 0, stock = 0, cantidad, opcion, cont = 0;
    float descuento, venta, precio = 0, total_ganancias = 0;
    char c, nombre[30] = {0};

    do {
        printf("=======================================\n");
        printf("\t   MENU DE OPCIONES\n");
        printf("=======================================\n");
        printf("[1] Registrar producto\n");
        printf("[2] Vender Producto\n");
        printf("[3] Ingresar el stock\n");
        printf("[4] Mostrar informacion del producto\n");
        printf("[5] Mostrar total de ganancias\n");
        printf("[6] Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {  
            printf("Entrada invalida.\n");
            while (getchar() != '\n');  
            continue; 
        }
        
        
        while (getchar() != '\n');

        
        if (opcion >= 2 && opcion <= 5 && cont == 0) {
            printf("\nPrimero tiene que registrar un producto.\n");
            continue;
        }

        switch (opcion) {
        case 1:
            do {
                printf("Ingrese el ID del producto: ");
                if (scanf("%d", &id) != 1 || id < 1) {  
                    printf("ID invalido.\n");
                    while (getchar() != '\n');  
                    id = -1;
                }
            } while (id < 1);

            printf("Ingrese el nombre del producto: ");
            while (getchar() != '\n');  
            fgets(nombre, 30, stdin);

            do {
                printf("Ingrese la cantidad inicial en stock: ");
                if (scanf("%d", &stock) != 1 || stock < 1) {
                    printf("Cantidad invalida. Debe ser un numero entero positivo.\n");
                    
                    while ((c = getchar()) != '\n' && c != EOF);
                    stock = -1;
                    continue;
                }
                
                
                if ((c = getchar()) != '\n') {
                    printf("Cantidad invalida. No se permiten decimales.\n");
                    
                    while (c != '\n' && c != EOF) c = getchar();
                    stock = -1;
                }
            } while (stock < 1);

            do {
                printf("Ingrese el precio unitario del producto: ");
                if (scanf("%f", &precio) != 1 || precio <= 0) {
                    printf("Precio invalido.\n");
                   
                    while ((c = getchar()) != '\n' && c != EOF);
                    precio = -1;
                    continue;
                }
                
               
                while ((c = getchar()) != '\n' && c != EOF);
                
            } while (precio <= 0);

            cont = 1;
            printf("\nProducto registrado con exito.\n");
            break;
        case 2:
            do {
                printf("Ingrese la cantidad a vender: ");
                if (scanf("%d", &cantidad) != 1 || cantidad < 1 || cantidad > stock) {  
                    printf("Cantidad invalida. Verifique el stock disponible.\n");
                    while (getchar() != '\n');  
                    cantidad = -1;
                }
            } while (cantidad < 1 || cantidad > stock);
            
            venta = cantidad * precio;

            if (venta > 50) {  
                descuento = venta * 0.10;
                venta -= descuento;
                printf("Se ha aplicado un descuento del 10%%: -$%.2f\n", descuento);
            }

            printf("El total de la venta es: $%.2f\n", venta);
            total_ganancias += venta;
            stock -= cantidad;
            break;

        case 3:
            do {
                printf("Ingrese la cantidad a agregar al stock: ");
                if (scanf("%d", &cantidad) != 1 || cantidad < 1) {  
                    printf("Stock invalido. Ingrese enter para ingresar un stock nuevo\n");
                    while (getchar() != '\n');  
                    cantidad = -1;
                }
               
                

            } while (cantidad < 1);

            stock += cantidad;
            printf("Stock actualizado correctamente. Stock actual: %d\n", stock);
            break;

        case 4:
            printf("\nInformacion del producto:\n");
            printf("ID: %d\n", id);
            printf("Nombre: %s", nombre); 
            printf("Stock disponible: %d\n", stock);
            printf("Precio unitario: $%.2f\n", precio);
            break;

        case 5:
            printf("Total de ganancias: $%.2f\n", total_ganancias);
            break;

        case 6:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 6);
    
    return 0;
}
