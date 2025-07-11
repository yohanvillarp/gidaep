void resgistro_tiendas();

void tiendas()
{
	cout<<"Esta es la tienda "<<""<<" Y dispone de los siguientes productos:"<<endl;
}

int main()
{
	menu_tiendas();
}

struct tiend
{
string nombre,direccion;
struct marca                                        //para mayor orden en el  se guardara por estos datos
   	{
		char nombre[30];
		int descuento,cajas,movimientos;
		struct modelo
		{
			string modelo,codigo;
			int cajas;
			float precio;
		}modelo_producto[5];   
	}marca_producto[5];
}tienda[100];
	struct marcas

void menu_tiendas()
{
	cout<<"Buenas días "<<usuario[user_act].nombre<<endl;
	cout<<"Aqui puedes gestionar tus tiendas"<<endl;
	cout<<"1.Registrar tiendas"<<endl;
	cout<<"2.Ver tiendas"<<endl;
	cout<<"3.Enviar productos a mis tiendas"<<endl;
	cout<<"4.Registro de datos"<<endl;
	cout<<"5.Salir"<<endl;
	cin>>opc;
	switch(opc)
	{
		case 1: 
	     	registro_tiendas();
	     	menu_tiendas();
		case 2:
		    ver_tiendas();
		    menu_tiendas();
		case 3:
			envio_productos();
			menu_tiendas();
		case 4:
			registro_datos();
			menu_tiendas();
			
		case 5:
			break;
			
		default: 
		break;
	}
}		

int cantidad_tiendas,cantidad_aumento_tiendas;
	
void registro_tiendas()
{
		cout<<"necesitamos que nos especifique la cantidad de tiendas que deseas registrar"<<endl;
		cin>>cantidad_total_tiendas;
	
	cout<<"Ahora nombre sus tiendas y agregue la direccion, para una administracion mas sencilla"<<endl;
		for(int i=cantidad_tiendas; i<cantidad_aumento_tiendas+cantidad_tiendas; i++)
		{
		cout<<"Nombre: ";
		cin>>usuario[user_act].tienda[i].nombre;
		cout<<"Direccion: ";
		cin>>usuario[user_act].tienda[i].direccion;
		}
		
	cantidad_tiendas+=cantidad_aumento_tiendas;
	
	cout<<"Tiendas registradas"<<endl;
	menu_tiendas();
}

void ver_tiendas()
{
	if(cantidad_tiendas<10)
	{
		tiendas_totales();
	}
	else
	{
		cout<<"1.Ver todas las tiendas"<<endl;
		cout<<"2.Buscador"<<endl;
		cout<<"3.Volver al menu anterior"<<endl;
		cin>>opc;
		switch()
		{
			case 1: 
				tiendas_totales();
			case 2:
				tiendas_buscador();
			case 3:
				menu_tiendas();
			default:
				break;
		}
	}
}

void tiendas_totales()
{
	for(int i=0; i<cantidad_tiendas; i++)
	{
			cout<<"Tienda "<<i<<endl;
			cout<<"Nombre: "<<usuario[user_act].tienda[i].nombre<<endl;
			cout<<"Direccion: "<<usuario[user_act].tienda[i].direccion<<endl;
			//agregar if de si existe producto o no en la tienda
			for(int j=1; i<cantidad_tiendas;i++)
			{
				for(int k=0; k<5; k++)
				{
					for(int l=0; l<5; l++)
					{
						cout<<"Producto "<<j<<endl;
						cout<<"Marca: "<<usuario[user_act].tienda[i].marca_producto[k].nombre;
						cout<<"Modelo: "<<usuario[user_act].tienda[i].marca_producto[k].modelo[l].nombre;
						cout<<"Modelo: "<<usuario[user_act].tienda[i].marca_producto[k].modelo[l].codigo;
						cout<<"Modelo: "<<usuario[user_act].tienda[i].marca_producto[k].modelo[l].precio;
						cout<<"Modelo: "<<usuario[user_act].tienda[i].marca_producto[k].modelo[l].cajas;
					}
				}
			}
		break;
	}
	menu_tiendas()
}

char almacen_char[30];

void tiendas_buscador()
{
cout<<"Por favor digite el nombre de la tienda"<<endl;

	cin>>almacen_char;
	for(int i=0; i<cantidad_tiendas; i++)
	{
	  	if(strcmp(almacen_char,usuario[user_act].tienda[i].nombre)==0)
		{
			cout<<"tienda encontrada"<<endl;
			cout<<"Nombre: "<<usuario[user_act].tienda[i].nombre<<endl;
			cout<<"Direccion: "<<usuario[user_act].tienda[i].direccion<<endl;
			//agregar if de si existe producto o no en la tienda
			for(int j=1; i<cantidad_tiendas;i++)
			{
				for(int k=0; k<5; k++)
				{
					for(int l=0; l<5; l++)
					{
						cout<<"Producto "<<j<<endl;
						cout<<"Marca: "<<usuario[user_act].tienda[i].marca_producto[k].nombre;
						cout<<"Modelo: "<<usuario[user_act].tienda[i].marca_producto[k].modelo[l].nombre;
						cout<<"Modelo: "<<usuario[user_act].tienda[i].marca_producto[k].modelo[l].codigo;
						cout<<"Modelo: "<<usuario[user_act].tienda[i].marca_producto[k].modelo[l].precio;
						cout<<"Modelo: "<<usuario[user_act].tienda[i].marca_producto[k].modelo[l].cajas;
					}
				}
			}
		break;
		}
	}
	else
	{
		cout<<"tienda no encontrada"<<endl;
	}
	menu_tiendas();
}

void envio_productos()
{
	if(almacen==1)
	{
		almacen--;
		goto aaa001;
	}
	cout<<"Digite el nombre de la tienda a la que desea enviarle el producto"<<endl;
	cin>>almacen_char;
	for(int i=0; i<cantidad_tiendas; i++)
	{
	  	if(strcmp(almacen_char,usuario[user_act].tienda[i].nombre)==0)
		{
			cout<<"tienda encontrada"<<endl;
			cout<<"Nombre: "<<usuario[user_act].tienda[i].nombre<<endl;
			cout<<"Direccion: "<<usuario[user_act].tienda[i].direccion<<endl<<endl;
			n_tienda=i;
			break;
		}	
	}
	cout<<"seleccione el producto del producto del almacen a enviar"<<endl;
	envio++;
	almacen();
	aaa001:
	//interactuar con el almacen
	cout<<"Producto enviado a la tienda "<<usuario[user_act].tienda[n_tienda].nombre<<endl;
	menu_tiendas();
}

void almacen()
{
	
	cout<<"Almacen virtual de "<<usuario[user_act].nombre_empresa<<endl<<endl;
	for(int i=0;i<5;i++)
	{

			cout<<i+1<<"."<<marca[i].nombre<<endl;
		
		for(int j=0;j<5;j++)
		{
			if(usuario[user_act].marca[i].modelo[j].cajas!=0)
			{
			cout<<"Modelo:"<<usuario[user_act].marca[i].modelo[j].modelo<<"_";
			cout<<"codigo:"<<usuario[user_act].marca[i].modelo[j].codigo<<"__";
			cout<<"precio de venta:"<<usuario[user_act].marca[i].modelo[j].precio<<" soles__";
			cout<<"cajas: "<<usuario[user_act].marca[i].modelo[j].cajas;	
			cout<<endl;	
			aux2=1;
			aux5=1;	
			}
		}
	if(aux2==0)
	{
		cout<<"No tienes ningun modelo de esta marca"<<endl;
	}
	aux2=0;
	}
	if(aux5==0)
	{
		aux5=0;
		cout<<endl<<"ESTE ALMACEN ESTA VACIO x)"<<endl<<endl;
	}
	
	//interaccion con envio
	if(envio==1 and aux5==1)
	{	
		cout<<"Marca: "; cin>>n_marca;
		n_marca--;
		cout<<"Modelo: "; cin>>n_modelo;
		n_modelo--;
		if(usuario[user_act].marca[n_marca].modelo[n_modelo].precio==marca[n_marca].modelos[n_modelo].precio)
		{
			usuario[user_act].tienda[n_tienda].marca_producto[n_marca].nombre=usuario[user_act].marca[n_marca].nombre;
			usuario[user_act].tienda[n_tienda].marca_producto[n_marca].modelo_producto[n_modelo].nombre=usuario[user_act].marca[n_marca].modelo[n_modelo].nombre;
			usuario[user_act].tienda[n_tienda].marca_producto[n_marca].modelo_producto[n_modelo].codigo=usuario[user_act].marca[n_marca].modelo[n_modelo].codigo;
			usuario[user_act].tienda[n_tienda].marca_producto[n_marca].modelo_producto[n_modelo].cajas++
			usuario[user_act].tienda[n_tienda].marca_producto[n_marca].modelo_producto[n_modelo].precio=usuario[user_act].marca[n_marca].modelo[n_modelo].precio;
			//eliminando cajas y datos del almacen
			usuario[user_act].marca[n_marca].modelo[n_modelo].cajas--;
			//Solo es necesario cambiar las cajas, ya que el for del almacen no se dará si las cajas son iguales a 0
		}
		envio_productos();
	}
	if(envio==1 and aux5==0)
	{
		cout<<"No puedes distribuir productos ya que no tienes ninguno"<<endl;
		menu_tiendas();
	}
	
	if(usuario[user_act].almacen>=1000)
		{
			cout<<endl<<"ESTE ALMACEN ESTA LLENO =3"<<endl<<endl;
		}
		usuario[user_act].almacen++;
		aux5=0;
		menu_inicio();
}

void registro_datos()
{
	if(usuario[user_act].tiendas[i].movimientos!=0)
	{
		for(int i=0; i<cantidad_tiendas; i++)
		{
			cout<<"Usted realizo "<<usuario[user_act].tiendas[i].movimientos<<" envios a la tienda "<<usuario[user_act].tiendas[i].nombre<<endl;
		}
	}
menu_tiendas();	
}
