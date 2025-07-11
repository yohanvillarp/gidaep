//comentarios
/*ver tiendas , online 
arreglar lo de salir
arreglar salto de lineas
descuento innecesario
agregar carrito? de almacen para comprar todo a la vez x)
codigo de usuario
el descuento es valido?
la variable de primera vez tiene que usarse para cada usuario , sin confundirlos 
suma de cajas del usuario <=1000
establecer cantidad de cajas a comprar
poner un maximo en el almacen - tiene que distribuir los productos para seguir almacenando
enfocarme en la distribucion
arreglar codigo desde el principio
importes y almacenaje solo mostrando modelo y pares totales 
implementar el sistema de ventaaaa
cartera empresarial?
idea: aplicaciones para el admin
aumentar inventario de catalogo xD - tambien funcion de agregar marcas para el admin
ordenar almacen 
usar la misma variable para muchas cosas en el futuro , ordenaaar
*/

//bibliotecas añadidas
#include<iostream>
#include<string.h>
#include<conio.h>
#include<conio.h>

using namespace std;

//declaracion de funciones
void menu_inicio(),menu_modelos(),menu_admin(),menu_user();
void distribucion(),almacen(),datos_inicializados(),catalogo_compra(),iniciar_sesion(),registrarse();
void menu_admin(),ini_datos();
void empresas_registradas();
void tiendas();
void cajero(),deposito(),estado_cuenta();
void manual(),busqueda_manual(),busqueda();
void empresas_registradas();
void tiendas_a();
//declaracion de variables
int activador=0;
int opc5,opc6,aux5=0,inicio=0;
int admin_cont=0;
float precio_pormayor=0,error=0;
char almacen_string[20];
int cantidad_tiendas=0,contador=0;
int cont10=0;
int monto,aux,aux2;
//variables importantes
int user_act,n_modelo,n_marca;;
int num_user=-1;
//variables de varios usos
int opc;

//ESTRUCTURAS

struct usuarios
{
	char nombre[10],apellido[10],nombre_empresa[20],password[20];       //se usa password por que c++ no reconoce la ñ
	int DNI,almacen;                                                    //capacidad        
	float saldo_empresarial;
	struct tiendas
	{
		string nombre,direccion;
	
	}tienda[100];
	struct marcas
	{
		string nombre;
		struct modelos
		{
			string modelo,codigo;
			float precio;
			int cajas;
		}modelo[5];
	}marca[5];
}usuario[100];                 //maximo de 100(en proceso) usuarios 

struct marca
{
	string nombre;
	int des_importe,cantidad_cajas;
	struct modelos
	{
		string modelo,codigo;	  
		int cajas;
		float precio;
	}modelos[5];             //modelos reemplaza nike, adidas, etc
}marca[5];

struct g
{
	string nombre;
	string username,password;
}GIDAEP;

//funcion principal
//**********************************************************************
int main()
{
	ini_datos();
	menu_user();
	getch();
	return 0;
}
//**********************************************************************

//MENUS
//MENU_USER
void menu_user()
{	
	if(activador==2)
		{
			activador=0;
			main();
		}
	cout<<"==============="<<GIDAEP.nombre<<"==============="<<endl;
	cout<<"BIENVENIDO A "<<GIDAEP.nombre<<", GRACIAS POR CONFIAR EN NUESTRO SISTEMA =)"<<endl;
	cout<<"por favor inicie sesion o registrese"<<endl<<endl;
	cout<<"1.INICIAR SESION"<<endl;
	cout<<"2.REGISTRARSE"<<endl;
	cout<<"3.MANUAL DE USUARIO"<<endl;
	cout<<"4.SALIR"<<endl<<endl;
	cin>>opc;
	
	switch(opc)
	{
		case 1: 
			iniciar_sesion();
			break;
		case 2:
			registrarse();
			break;
		case 3: 
			manual();
			break;
		case 4:
			cout<<"Hasta pronto"<<endl;
			break;
		default:
		break;
	}
}


//1.INICIAR SESION
void iniciar_sesion()
{
	aaa008:
		if(error==4)
		{
			cout<<"demasiados errores cometidos"<<endl;
			goto aaa006;
		}
	cout<<"NOMBRE DE LA EMPRESA: "; 
	cin>>almacen_string;
	
	if(GIDAEP.username==almacen_string)
		{
			admin_cont++;
			goto aaa006;	
		}
		
	for(int i=0; i<10; i++)
	{
		if(strcmp(usuario[i].nombre_empresa,almacen_string)==0)
		{
			activador++;
			cout<<"Empresa encontrada en la base de datos"<<endl;
			user_act=i;
			goto aaa006;
		}
	}
	for(int i=0; i<10; i++)
	{
		if(strcmp(usuario[i].nombre_empresa,almacen_string)!=0 and activador==0)
		{
			cout<<"Empresa no registrada en la base de datos"<<endl;
			menu_user();		
		}
	}	
		
	aaa006:
	if(admin_cont==1)
	{
		cout<<"PASSWORD x): ";  
		cin>>almacen_string;
		if(almacen_string==GIDAEP.password)
		{
			admin_cont++;
			cout<<"Por seguridad la contraseña se le pedira seguido..."<<endl<<endl;
			menu_admin();
		}
		if(almacen_string!=GIDAEP.password and error<=3)
		{
		cout<<"clave erronea, ingrese su nombre de usuario nuevamente por favor"<<endl;
		admin_cont=0;
		error++;
		goto aaa008;
		}	
	}
		
	if(activador==1)
	{
		aaa001:
		cout<<"PASSWORD: ";  
		cin>>almacen_string;
		if(strcmp(almacen_string,usuario[user_act].password)==0)
		{
			activador++;
			cout<<"Password verificada =)"<<endl<<endl;
			datos_inicializados();
		}
	else
	{
		cout<<"Esta contraseña es incorrecta"<<endl<<endl;
		goto aaa001;
	}
	}	
}

//2.REGISTRO
void registrarse()
{	
//sistema que inicie usuarios
num_user++;
	if(num_user>99)
	{
		cout<<"Este sistema no admite mas de 100 cuentas"<<endl<<endl;
		menu_user();
	}
		cout<<"por favor ingrese los siguientes datos"<<endl<<endl;
		cout<<"Nombre: ";  cin>>usuario[num_user].nombre,10; 
		cout<<"Apellido: "; cin>>usuario[num_user].apellido,10; 
		aaa007:
		cout<<"DNI: "; cin>>usuario[num_user].DNI;
		if(usuario[num_user].DNI<=10000000 or usuario[num_user].DNI>=99999999)
		{
			cout<<"digite un DNI valido por favor =)"<<endl;
			goto aaa007;
		} 
		for(int i=0; i<10;i++)
		{
			if(i!=num_user)
			{
				if(usuario[num_user].DNI==usuario[i].DNI)
				{
				cout<<"Este DNI le pertenece a otro usuario"<<endl;
				goto aaa007;
				}
			}
		}
		aaa008:
		cout<<"Nombre de la empresa: "; cin>>usuario[num_user].nombre_empresa; 
		//idea: compaaracion de nombre de empresas para no crear con el mismo nombre
		
		for(int i=0; i<10;i++)
		{
			if(i!=num_user)
			{
				if(strcmp(usuario[num_user].nombre_empresa,usuario[i].nombre_empresa)==0)
				{
				cout<<"Esta empresa ya esta registrada, si tu empresa se llama igual , por favor le pedimos que agregue un numero al final , para diferenciarlas"<<endl;
				goto aaa008;
				}
			}
		}
		cout<<"Password: "; cin>>usuario[num_user].password;
	menu_user();
}

//3.MANUAL
void manual()
{
	cout<<"Bienvenido al manual, aqui encontraras todo lo que debes de saber sobre nuestro programa =)"<<endl<<endl;
	cout<<"Cual es la funcion del programa?"<<endl;
	cout<<"Este programa esta diseñado para grandes empresas las cuales importan directamente desde las empresas originales de las marcas con las que estamos afiliadas"<<endl<<endl;
	cout<<"Por el momento solo estamos afiliados con marcas de zapatillas reconocidas, tales como adidas, nike, reebok, puma y converse, pero esperamos pronto trabajar con muchas mas marcas"<<endl;
	cout<<"Solo somos mediadores entre el pago de los importes, una vez realizado esto mismo y ya haber destinado las tiendas a las que deseas enviar los productos adquiridos, nos encargaremos de enviarlo "<<endl;
	cout<<"manual en desarrollo"<<endl<<endl;;
	menu_user();
}

//menu_inicio
void menu_inicio()
{
	cout<<endl<<endl;
	cout<<"Bienvenido "<<usuario[user_act].nombre<<" "<< usuario[user_act].apellido<<endl;
	cout<<"gracias por preferir el sistema<<GIDAEP.nombre<<para su empresa"<<endl;
	cout<<"Esperamos que la empresa "<<usuario[user_act].nombre_empresa<<" pueda estar satisfecha con nuestro servicio"<<endl<<endl;
	cout<<"que quiere hacer hoy?"<<endl<<endl;
	cout<<"1.Importar productos"<<endl;
	//agregar opcion de tienda , y dividir en tienda virtual y lo de distribuir
	cout<<"2.Distribuir productos"<<endl;
	cout<<"3.Ver almacen general"<<endl;
	cout<<"4.Saldo en cuenta"<<endl;
	cout<<"5.cerrar sesion"<<endl;
	cout<<"6.Salir"<<endl;
	cin>>opc;
	switch(opc)
	{
	case 1: 
		catalogo_compra();
	case 2:
		distribucion();
	case 3:
		almacen();
	case 4:
		cajero();
	case 5:
		cout<<endl<<"Hasta pronto "<<usuario[user_act].nombre<<endl<<endl;
		menu_user();
	case 6:
		break;
	}
}


	
//COMPRAR
void catalogo_compra()
{
	//menu paralelo compra-venta?
	cout<<endl<<"Selecciona la marca de la distribuidora de la que desea adquirir los productos"<<endl<<endl;
	for(int i=0; i<5; i++)
	{
		cout<<i+1<<"."<<marca[i].nombre<<endl;
	}
	cout<<"6.volver al menu anterior"<<endl;
	cout<<endl;	cin>>opc;
	if(opc>=0 and opc<=5)
	{
		n_marca=opc-1;
		menu_modelos();
	}
	if(opc ==6)
	{
		menu_inicio();
	}
}	
	
void menu_modelos()
{
	
	for(int i=opc; i<opc+1;i++)
	{
		cout<<"Bienvenido a la distribuidora "<<marca[i-1].nombre<<" ,estos son los modelos disponibles"<<endl;
		cout<<"Esta distribuidora esta dispuesta a descontarte el "<<marca[i-1].des_importe<<"% por importe de cada caja(12 pares del mismo modelo)"<<endl<<endl;
	}
	for(int i=0; i<5; i++)
	{
		cout<<i+1<<" "<<marca[n_marca].modelos[i].modelo<<"__precio:"<<marca[n_marca].modelos[i].precio*marca[n_marca].des_importe/100<<"- cajas disponibles:"<<marca[n_marca].modelos[i].cajas<<endl;
	}		
	cout<<"6.volver al menu anterior"<<endl;
	cin>>n_modelo; 
	aaa002:
	
	if(n_modelo>0 and n_modelo <=5)
	{	
		n_modelo--;
		cout<<"Comprar?"<<endl;
		cout<<"1.SI"<<endl;
		cout<<"2.NO"<<endl;
		cin>>opc;
		switch(opc)
		{
			case 1:
				if(usuario[user_act].saldo_empresarial>=marca[n_marca].modelos[n_modelo].precio*marca[n_marca].des_importe/100)
			{
				usuario[user_act].saldo_empresarial-=marca[n_marca].modelos[n_modelo].precio*marca[n_marca].des_importe/100;
				if(usuario[user_act].almacen<=1000)
				{
					if(usuario[user_act].marca[n_marca].modelo[n_modelo].precio==0)
			    		usuario[user_act].marca[n_marca].nombre=marca[n_marca].nombre;
						usuario[user_act].marca[n_marca].modelo[n_modelo].modelo=marca[n_marca].modelos[n_modelo].modelo;
						usuario[user_act].marca[n_marca].modelo[n_modelo].codigo=marca[n_marca].modelos[n_modelo].codigo;
						usuario[user_act].marca[n_marca].modelo[n_modelo].precio=marca[n_marca].modelos[n_modelo].precio;
						
						usuario[user_act].marca[n_marca].modelo[n_modelo].cajas++;
						marca[n_marca].modelos[n_modelo].cajas--;
						usuario[user_act].almacen++;
						cout<<"Gracias por su compraa"<<endl;
						
		            	catalogo_compra();
						goto aaa010;
				} 
				if(usuario[user_act].marca[n_marca].modelo[n_modelo].cajas>0)
				{
					usuario[user_act].marca[n_marca].modelo[n_modelo].cajas++;
					marca[n_marca].modelos[n_modelo].cajas--;
				}
				aaa010:
							
				if(usuario[user_act].almacen>1000)
			    {	
				    cout<<"Almacen lleno"<<endl;
			    }
			}
		   	if(usuario[user_act].saldo_empresarial<marca[n_marca].modelos[n_modelo].precio*marca[n_marca].des_importe/100)
			{
				cout<<endl;
				cout<<"Usted no dispone de saldo suficiente en su cuenta, por favor deposite saldo en su cuenta ,antes de realizar las compras"<<endl;
				cout<<endl;
				menu_modelos();
			}
			break;
			case 2:
				menu_modelos();
		}
	}
	if(n_modelo==6)
	{
		catalogo_compra();
	}
}


void almacen()
{
	//ampliar a 1000 -solo aumentaran las cajas, pero tengo limites :D solo queda corregir lo de la numeración jsjs
	//crear una variable que solo llegue hasta donde hallamos usado el almacen , 1000 veces es demasiado xD
	cout<<"Almacen virtual de "<<usuario[user_act].nombre_empresa<<endl<<endl;
	for(int i=0;i<5;i++)
	{

			cout<<i+1<<"."<<marca[i].nombre<<endl;
		
		for(int j=0;j<5;j++)
		{
			if(usuario[user_act].marca[i].modelo[j].precio!=0)
			{
			cout<<"Modelo:"<<usuario[user_act].marca[i].modelo[j].modelo<<"_";
			cout<<"codigo:"<<usuario[user_act].marca[i].modelo[j].codigo<<"__";
			cout<<"precio de venta:"<<usuario[user_act].marca[i].modelo[j].precio<<" soles__";
			cout<<"cajas: "<<usuario[user_act].marca[i].modelo[j].cajas;	
			cout<<endl;	
			aux2=1;
			aux5=1;
			//hacer mas simple esta parte 	
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
	
	if(usuario[user_act].almacen>=1000)
		{
			cout<<endl<<"ESTE ALMACEN ESTA LLENO =3"<<endl<<endl;
		}
		usuario[user_act].almacen++;
		aux5=0;
		menu_inicio();
}


void menu_admin()
{
	
}

	//INICIALIZACION
	void datos_inicializados()
{
	if(inicio==0)
	{
	cout<<endl;
	cout<<"cargando datos, por favor espere...."<<endl;
	//marcas consideradas
	marca[0].nombre="Nike";	          marca[0].des_importe=50;
	marca[1].nombre="Adidas";         marca[1].des_importe=50;
	marca[2].nombre="Converse";	      marca[2].des_importe=50;
	marca[3].nombre="Puma";	          marca[3].des_importe=50;
	marca[4].nombre="Reebok";         marca[4].des_importe=50;
	//modelos-precios y codigos tomados de la web y paginas oficiales =) con aproximacion de costo de "por mayor" , p/u real
	//las tallas van despues de adquirir el producto- crear nueva estructura
	//al parece hay otra forma de almacenar datos =(
	//nike -- www.nike.com.pe
	marca[0].modelos[0].modelo="Blazer Low 77 premium";
	marca[0].modelos[0].codigo="DV7231-200";
	marca[0].modelos[0].precio=469.90;
	marca[0].modelos[0].cajas=100;
	marca[0].modelos[1].modelo="Air Jordan 1 Retro Low OG";
	marca[0].modelos[1].codigo="DV0982-100";
	marca[0].modelos[1].precio=719;
	marca[0].modelos[1].cajas=200;
	marca[0].modelos[2].modelo="Dunk Low SV";
	marca[0].modelos[2].codigo="DZ5224-300";
	marca[0].modelos[2].precio=579.90;
	marca[0].modelos[2].cajas=50;
	marca[0].modelos[3].modelo="Pegasus 40 Premium";
	marca[0].modelos[3].codigo="FB7703-001";
	marca[0].modelos[3].precio=649.9;
	marca[0].modelos[3].cajas=40;
	marca[0].modelos[4].modelo="Air force 1 '07 SE";
	marca[0].modelos[4].codigo="DQ7582-100";
	marca[0].modelos[4].precio=579.90;
	marca[0].modelos[4].cajas=90;
	//adidas -- www.adidas.pe
	marca[1].modelos[0].modelo="originals FORUM MID";
	marca[1].modelos[0].codigo="FZ6275";
	marca[1].modelos[0].precio=449;
	marca[1].modelos[0].cajas=60;
	marca[1].modelos[1].modelo="ULTRABOOST 22";
	marca[1].modelos[1].codigo="HP9930";
	marca[1].modelos[1].precio=559;
	marca[1].modelos[1].cajas=50;
	marca[1].modelos[2].modelo="Samba THE VELOSAMBA MADE WITH NATURE";
	marca[1].modelos[2].codigo="HQ9036";
	marca[1].modelos[2].precio=549;
	marca[1].modelos[2].cajas=40;
	marca[1].modelos[3].modelo="Sportswear ULTRA ADIDAS 4D";
	marca[1].modelos[3].codigo="HP9737";
	marca[1].modelos[3].precio=999;
	marca[1].modelos[3].cajas=10;
	marca[1].modelos[4].modelo="Basquet TRAE UNLIMITED";
	marca[1].modelos[4].codigo="HQ1020";
	marca[1].modelos[4].precio=449;
	marca[1].modelos[4].cajas=90;
	//converse -- www.coliseum.com.pe
	marca[2].modelos[0].modelo="Chuck 70 AT-CX";
	marca[2].modelos[0].codigo="A03425C-0";
	marca[2].modelos[0].precio=449.90;
	marca[2].modelos[0].cajas=50;
	marca[2].modelos[1].modelo="Chuck Taylor All Star Lift Platform Pride";
	marca[2].modelos[1].codigo="A06031C-0";
	marca[2].modelos[1].precio=459.90;
	marca[2].modelos[1].cajas=60;
	marca[2].modelos[2].modelo="Chuck Taylor All Star Lugged 2.0 Platform Utility";
	marca[2].modelos[2].codigo="A03500C-0";
	marca[2].modelos[2].precio=349.90;
	marca[2].modelos[2].cajas=70;
	marca[2].modelos[3].modelo="Run Star Motion CX Platform Marbled";
	marca[2].modelos[3].codigo="A03552C-0";
	marca[2].modelos[3].precio=479.90;
	marca[2].modelos[3].cajas=80;
	marca[2].modelos[4].modelo="Chuck Taylor All Star Core Hi";
	marca[2].modelos[4].codigo="157197C-0";
	marca[2].modelos[4].precio=269.90;
	marca[2].modelos[4].cajas=100;
	//puma-- eu.puma.com
	marca[3].modelos[0].modelo="Slipstream FBball";
	marca[3].modelos[0].codigo="393266_01";
	marca[3].modelos[0].precio=472.70;
	marca[3].modelos[0].cajas=70;
	marca[3].modelos[1].modelo="ULTRA ULTIMATE FG/AG Football Boots";
	marca[3].modelos[1].codigo="107311_01";
	marca[3].modelos[1].precio=866.70;
	marca[3].modelos[1].cajas=30;
	marca[3].modelos[2].modelo="PUMA x KOCHE Plexus";
	marca[3].modelos[2].codigo="392078_01";
	marca[3].modelos[2].precio=590.90;
	marca[3].modelos[2].cajas=120;
	marca[3].modelos[3].modelo="RBD Game Low";
	marca[3].modelos[3].codigo="386373_07";
	marca[3].modelos[3].precio=216.50;
	marca[3].modelos[3].cajas=180;
	marca[3].modelos[4].modelo="Disc Blaze OG";
	marca[3].modelos[4].codigo="390931_02";
	marca[3].modelos[4].precio=590.90;
	marca[3].modelos[4].cajas=50;
	//reebok --www.reebok.mx
	marca[4].modelos[0].modelo="Tenis Classic Leather";
	marca[4].modelos[0].codigo="IE4100";
	marca[4].modelos[0].precio=484.70;
	marca[4].modelos[0].cajas=100;
	marca[4].modelos[1].modelo="Tenis Nano X3";
	marca[4].modelos[1].codigo="HP6046";
	marca[4].modelos[1].precio=611.20;
	marca[4].modelos[1].cajas=70;
	marca[4].modelos[2].modelo="Tenis Shaq Attaq Street Fighter";
	marca[4].modelos[2].codigo="HR0603";
	marca[4].modelos[2].precio=843.10;
	marca[4].modelos[2].cajas=60;
	marca[4].modelos[3].modelo="Tenis Club C 85 Eames";
	marca[4].modelos[3].codigo="GY1068";
	marca[4].modelos[3].precio=590.10;
	marca[4].modelos[3].cajas=100;
	marca[4].modelos[4].modelo="Tenis Royal Complete Sport";
	marca[4].modelos[4].codigo="GW1543";
	marca[4].modelos[4].precio=242.20;
	marca[4].modelos[4].cajas=60;		
	}
	inicio=1;		
	menu_inicio();
}

void distribucion()
{
	//separaaaar en el menu agregar mas funciones
		cout<<"necesitamos que nos especifique la cantidad de tiendas de las que dispone su empresa"<<endl;
		cin>>cantidad_tiendas;
	
	cout<<"Ahora nombre sus tiendas y agregue la direccion, para una administracion mas sencilla"<<endl;
		for(int i=0; i<cantidad_tiendas; i++)
		{
		cout<<"Nombre: ";
		cin>>usuario[user_act].tienda[i].nombre;
		cout<<"Direccion: ";
		cin>>usuario[user_act].tienda[i].direccion;
		}
	cout<<"analizando datos..."<<endl;
	cout<<"DATOS ANALIZADOS"<<endl;
	tiendas();
}



void tiendas_a()
{
	cout<<"Quiere seleccionar la tienda a la que desea acceder o buscarla manualmente?"<<endl;
	
	cout<<"1.Buscar manualmente"<<endl;
	cout<<"2.Busqueda por nombre"<<endl;
	cout<<"3.salir"<<endl;
	cin>>opc;
	switch(opc)
	{
		case 1: 
	     	busqueda_manual();
		case 2:
		    busqueda();
		case 3:
			break;
	}
}

//busqueda manual y busqueda por nombre o direccion
void busqueda_manual()
{
	for(int i=0; i<cantidad_tiendas; i++)
	{
		cout<<i+1<<""<<usuario[user_act].tienda[i].nombre<<"  ";
		cout<<usuario[user_act].tienda[i].direccion<<endl;
	}
	cin>>opc;
}

void busqueda()
{
	cout<<"Por que dato quieres buscar la tienda?"<<endl;
	cout<<"1.Nombre"<<endl;
	cout<<"2.Direccion"<<endl;
	cin>>opc;
	switch(opc)
	{
		case 1:
			cout<<"Ingrese el nombre de la tienda"<<endl;
			aaa010:
			cin>>almacen_string;
			for(int i=0; i<cantidad_tiendas; i++)
			{
		    	if(almacen_string==usuario[user_act].tienda[i].nombre)
		    	{
		    		cout<<"tienda encontrada"<<endl;
		    		cont10=1;
		    		//llevar a tienda
				}
			}
			if(cont10==0)
			{
				cout<<"tienda no encontrada, vuelva a escribir el nombre"<<endl;
				goto aaa010;
			}
		//agregar la opcion de ya no buscar si el cliente queda atrapado aquí 

		case 2:
			cout<<"Ingrese la direccion de la tienda"<<endl;
			aaa011:
			cin>>almacen_string;
			for(int i=0; i<cantidad_tiendas; i++)
			{
		    	if(almacen_string==usuario[user_act].tienda[i].direccion)
		    	{
		    		cout<<"tienda encontrada"<<endl;
		    		cont10=1;
		    		//llevar a tienda
				}
			}
			if(cont10==0)
			{
				cout<<"tienda no encontrada, vuelva a escribir la direccion"<<endl;
				goto aaa011;
			}
	}
}
void cajero()
{
	cout<<"Aquí puede depocitar de manera rapida y eficaz a su cuenta empresarial"<<endl;
	cout<<"1.Depocitar"<<endl;
	cout<<"2.Ver estado de cuenta"<<endl;
	cout<<"3.Volver al menu anterior"<<endl;
	cin>>opc;
	switch(opc)
	{
		case 1: 
			deposito();
		case 2:
			estado_cuenta();
		case 3:
			menu_inicio();
	}
}

void deposito()
{
	aaa011:
	cout<<"Ingrese el monto que desea depositar a su cuenta empresarial"<<endl;
	cin>>monto;
	if(monto>100000)
	{
		cout<<"Por seguridad solo puede depositar 100000 soles a su cuenta por transaccion"<<endl;
		goto aaa011;
	}
	if(monto>0 or monto<=100000)
	{
		usuario[user_act].saldo_empresarial+=monto;
		monto=0;
		cout<<"Depocito realizado, su nuevo saldo es de "<<usuario[user_act].saldo_empresarial<<" soles =)"<<endl;	
	    cajero();
	}
	if(monto<0)
	{
		cout<<"No puede depocitar un saldo negativo"<<endl;
		goto aaa011;
	}
}	
void estado_cuenta()
{
	cout<<"1.Saldo en cuenta"<<endl;
	cin>>opc;
	switch(opc)
	{
		case 1: 
		cout<<"Saldo en cuenta empresarial: "<<usuario[user_act].saldo_empresarial<<" soles"<<endl;
	}
	cajero();
}

void empresas_registradas()
{
	
}

void ini_datos()
{
	GIDAEP.nombre="GIDAEP";
	GIDAEP.username="GIDAEP";
	GIDAEP.password="VillarP";
}

void tiendas()
{
	cout<<"Esta es la tienda "<<""<<" Y dispone de los siguientes productos:"<<endl;
}
