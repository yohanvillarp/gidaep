void menu_admin()
{
	cout<<"==========MENU - ADMINISTRADOR=========="<<endl;
	cout<<"Este menu trae opciones de desarrollador"<<endl;
	cout<<"1.AGREGAR MARCAS Y MODELOS"<<endl;
	cout<<"2.AUMENTAR NUMERO DE CAJAS MINIMAS DE COMPRA"<<endl;
	cout<<"3.VER EMPRESAS REGISTRADAS"<<endl;
	cout<<"4.SALIR DE CUENTA DE ADMINISTRADOR"<<endl;
	cin>>opc;
	switch(opc)
	{
		case 1:
			desarrollador0();
			menu_admin();
		case 2:
			desarrollador1();
			menu_admin();
		case 3:
			desarrollador2();
			menu_admin();
		case 4:
			menu_inicio();
		default:
		break;	
	}
}

void desarrollador2()
{
	cout<<"Estas son las empresas registradas hasta el momento y sus respectivos dueños"<<endl;
	for(int i=0; i<num_user; i++)
	{
		cout<<"Empresa "<<usuario[i].nombre_empresa<<endl<<endl;
		cout<<"Empresario a cargo: "<<usuario[i].nombre<<" "<<usuario[i].apellido<<endl;
		cout<<"DNI: "<<usuario[i].DNI<<endl;
		cout<<"Cantidad ocupada en el almacen virtual: "<<usuario[i].almacen<<endl;
		cout<<"Cantidad de tiendas: "<<usuario[i].cantidad_tiendas<<endl<<endl;
	}
}

void desarrollador1()
{
	cout<<"Digite el nuevo numero de cajas minimas de compra de cada distribuidota"<<endl;
	cin>>cajas_venta;
	menu_admin;
}
void desarrollador0()
{
	cout<<"Añadir "<<endl;
	cout<<"1.MARCA"<<endl;
	cout<<"2.MODELO"<<endl;
	cout<<"3.VOLVER AL MENU ANTERIOR"<<endl;
	cin>>opc;
	switch(opc)
	{
		case 1:
			nueva_marca();
		case 2:
			nuevo_modelo();
		case 3:
			menu_admin();
		default:
			break;
	}
}


