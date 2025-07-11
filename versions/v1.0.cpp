//comentarios
/*agregar texto que diga que aun no se agregaron modelos
arreglar salto de lineas  la variable de primera vez tiene que usarse para cada usuario , sin confundirlos 
comprar mas que solo 1 , que sean 5 o 10 cajas por compra minimo
codigo de usuario
acomodar codigo- decorar
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
void distribucion(),almacen(),carga_datos(),catalogo_compra(),iniciar_sesion(),registrarse();
void menu_admin(),ini_datos();
void empresas_registradas();
void cajero(),deposito(),estado_cuenta();
void manual(),busqueda_manual(),busqueda();
void empresas_registradas();
void desarrollador2();
//Tiendas
void resgistro_tiendas();
void menu_tiendas();
void registro_tiendas();
void ver_tiendas();
void tiendas_totales();
void tiendas_buscador();
void envio_productos();
void registro_datos();
void nueva_marca();
void nuevo_modelo();
void desarrollador0(),desarrollador1();

//declaracion de variables
int activador=0;
int opc5,opc6,aux5=0,inicio=0;
int admin_cont=0;
float precio_pormayor=0,error=0;
char almacen_string[20];
int contador=0;
int cont10=0;
int monto,aux,aux2;
//variables importantes
int user_act,n_modelo,n_marca;;
int num_user=-1;
int cajas_venta=1;
int caja=12;
//variables de varios usos
int opc;
char almacen_char[30];
int n_tienda;
int cantidad_tiendas=0,cantidad_aumento_tiendas;
int envio=0;
int n_deposito=0;
int n_organizador=10;
int total_marcas=4;

//ESTRUCTURAS

struct usuarios
{
	char nombre[10],apellido[10],nombre_empresa[20],password[20];       //se usa password por que c++ no reconoce la ñ
	int DNI,almacen;                                                    //capacidad        
	float saldo_empresarial;
	int cantidad_tiendas;
	struct tiendas
	{
		string nombre;
		string direccion;
		int movimientos;
		int n_productos;
		struct marca                                                     //para mayor orden en el  se guardara por estos datos
		{
			string nombre;
		    int cajas;
			struct modelo
				{
					string nombre,codigo;	  
					int cajas;
					float precio;
				}modelo_producto[5];   
		}marca_producto[20];
	}tienda[100];
	struct marcas
	{
		string nombre;
		struct modelos
		{
			string nombre,codigo;
			float precio;
			int cajas;
		}modelo[5];
	}marca[20];
	struct depo
	{
		float monto;
	}deposito[10];
}usuario[100];                 //maximo de 100(en proceso) usuarios 

struct marca
{
	string nombre;
	float des_importe;
	int cantidad_cajas;
	struct modelos
	{
		string nombre,codigo;	  
		int cajas;
		float precio;
	}modelos[5];             //modelos reemplaza nike, adidas, etc
}marca[20];

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
			menu_user();
		default:
		break;	
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
void desarrollador2()
{
	cout<<"Estas son las empresas registradas hasta el momento y sus respectivos dueños"<<endl;
	for(int i=0; i<num_user+1; i++)
	{
		cout<<"Empresa "<<usuario[i].nombre_empresa<<endl;
		cout<<"Empresario a cargo: "<<usuario[i].nombre<<" "<<usuario[i].apellido<<endl;
		cout<<"DNI: "<<usuario[i].DNI<<endl;
		cout<<"Cantidad ocupada en el almacen virtual: "<<usuario[i].almacen<<" cajas"<<endl;
		cout<<"Cantidad de tiendas: "<<usuario[i].cantidad_tiendas<<" "<<endl<<endl;
	}
}


void nueva_marca()
{
	if(total_marcas>=99)
	{
		cout<<"Solo se permite agregar 15 marcas como maximo"<<endl;
		desarrollador0();
	}
	total_marcas++;
	cout<<"Como se llama la marca que desea agregar?"<<endl;
	cin>>marca[total_marcas].nombre;
	cout<<"Marca agregada =)"<<endl<<endl;
	for(int i=0; i<5; i++)
	{
		marca[total_marcas].modelos[i].cajas=0;
	}
	desarrollador0();
}

void nuevo_modelo()
{
	cout<<endl<<"Debido a restricciones del programa, solo podemos agregar 5 modelos a las marcas que añadiste"<<endl;
	cout<<"Selecionar marca en la que deseamos agregar modelos"<<endl;
	for(int i=5; i<total_marcas+1; i++)
	{
		cout<<i+1<<"."<<marca[i].nombre<<endl;
	}
	cin>>n_marca;
	n_marca--;
	for(int i=0; i<5; i++)
	{
		if(marca[n_marca].modelos[i].cajas==0)
		{
		cout<<endl<<"Rellene los datos del modelo que desea agregar"<<endl;
		cout<<"Modelo: ";
		cin>>marca[n_marca].modelos[i].nombre;
		cout<<"Codigo: ";
		cin>>marca[n_marca].modelos[i].codigo;
		cout<<"Precio: ";
		cin>>marca[n_marca].modelos[i].precio;
		cout<<"Cantidad de cajas disponibles: ";
		cin>>marca[n_marca].modelos[i].cajas;
		cout<<"Modelo agregado a "<<marca[n_marca].nombre<<endl<<endl;
		break;
		}
	}	
}

//MENUS
//MENU_USER
void menu_user()
{	
	if(activador==2)
		{
			activador=0;
			main();
		}
	cout<<endl<<"==============="<<GIDAEP.nombre<<"==============="<<endl;
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
			admin_cont=0;
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
			carga_datos();
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
	cout<<"Hola =)"<<endl;
	cout<<"Te mostrare detalle a detalle el uso del programa y sus funciones"<<endl<<endl;
	cout<<"I.MENU PRINCIPAL"<<endl;
	cout<<"El menu principal es el que manejan todos nuestros usuarios, cabe recalcar que solo damos acceso a las empresas";
	cout<<" que hayan adquirido el programa legalmente"<<endl;
	cout<<"En el menu principal encontrara las siguientes opciones..."<<endl;
	cout<<"1.INICIAR SESION"<<endl;
	cout<<"2.REGISTRARSE"<<endl;
	cout<<"3.MANUAL DE USUARIO"<<endl;
	cout<<"4.SALIR"<<endl<<endl;
	cout<<"I1.REGISTRO"<<endl<<endl;
	cout<<"Para empezar a usar el programa tendrás que registrarte, esto servira para verificar que tus datos sean autenticos"<<endl;
	cout<<"Al registrarte se te dara un codigo , el cual te servira para ingresar al programa, una vez obtenido este mismo ";
	cout<<"Puedes pasar a ingresar al programa"<<endl<<endl;
	
	cout<<"2.INGRESO"<<endl<<endl;
}

//menu_inicio
void menu_inicio()
{
	cout<<endl;
	cout<<"Bienvenido "<<usuario[user_act].nombre<<" "<< usuario[user_act].apellido<<endl;
	cout<<"gracias por preferir el sistema "<<GIDAEP.nombre<<" para su empresa"<<endl;
	cout<<"Esperamos que la empresa "<<usuario[user_act].nombre_empresa<<" pueda estar satisfecha con nuestro servicio"<<endl<<endl;
	cout<<"que quiere hacer hoy?"<<endl<<endl;
	cout<<"1.IMPORTAR ARTICULOS"<<endl;
	//agregar opcion de tienda , y dividir en tienda virtual y lo de distribuir
	cout<<"2.TIENDAS"<<endl;
	cout<<"3.ALMACEN DE ARTICULOS"<<endl;
	cout<<"4.SALDO"<<endl;
	cout<<"5.CERRAR SESION"<<endl;
	cin>>opc;
	switch(opc)
	{
	case 1: 
		catalogo_compra();
	case 2:
		menu_tiendas();
	case 3:
		almacen();
	case 4:
		cajero();
	case 5:
		cout<<endl<<"Hasta pronto "<<usuario[user_act].nombre<<endl<<endl;
		menu_user();
	default:
		break;
	}
}

//COMPRAR
void catalogo_compra()
{
	//menu paralelo compra-venta?
	cout<<endl<<"Selecciona la marca de la distribuidora de la que desea adquirir los productos"<<endl<<endl;
	for(int i=0; i<total_marcas+1; i++)
	{
		cout<<i+1<<"."<<marca[i].nombre<<endl;
	}
	cout<<total_marcas+2<<".volver al menu anterior"<<endl;
	cout<<endl;	cin>>n_marca;
	if(n_marca>=0 and n_marca<=total_marcas+1)
	{
		n_marca--;
		menu_modelos();
	}
	if(n_marca==total_marcas+2)
	{
		menu_inicio();
	}
}	
	
void menu_modelos()
{
	aaa001:
	cout<<"Bienvenido a la distribuidora "<<marca[n_marca].nombre<<" ,estos son los modelos disponibles"<<endl;
	cout<<"Para importaciones como minimo puede comprar "<<cajas_venta<<" cajas (12 pares de diferentes tallas por caja)"<<endl<<endl;
	for(int i=0; i<5; i++)
	{
		cout<<"modelo "<<i+1<<endl; cout<<"nombre: "<<marca[n_marca].modelos[i].nombre<<endl; cout<<"precio por unidad:"<<marca[n_marca].modelos[i].precio<<endl; cout<<"cajas disponibles:"<<marca[n_marca].modelos[i].cajas<<endl<<endl;
	}		
	cout<<"6.volver al menu anterior"<<endl<<endl;
	cout<<"Si desea comprar alguno de los modelos, digite el numero al que corresponda este mismo: "<<endl;
	cin>>n_modelo; 
	aaa002:
	
	if(n_modelo>0 and n_modelo <=5)
	{	
		n_modelo--;
		cout<<"El precio en total por las "<<cajas_venta<<" cajas seria de "<<marca[n_marca].modelos[n_modelo].precio*cajas_venta*caja<<" soles"<<endl;
		cout<<"Comprar?"<<endl;
		cout<<"1.SI"<<endl;
		cout<<"2.NO"<<endl;
		cin>>opc;
		switch(opc)
		{
			case 1:
			if(usuario[user_act].saldo_empresarial<marca[n_marca].modelos[n_modelo].precio*cajas_venta*caja)
			{
				cout<<endl;
				cout<<"Usted no dispone de saldo suficiente en su cuenta, por favor deposite saldo en su cuenta ,antes de realizar las compras"<<endl;
				cout<<endl;
				menu_modelos();
			}
			
				if(usuario[user_act].saldo_empresarial>=marca[n_marca].modelos[n_modelo].precio*cajas_venta*caja)
			{
				usuario[user_act].saldo_empresarial-=marca[n_marca].modelos[n_modelo].precio*cajas_venta*caja;
				if(usuario[user_act].almacen<=1000)
				{
					if(usuario[user_act].marca[n_marca].modelo[n_modelo].cajas==0)
			    		usuario[user_act].marca[n_marca].nombre=marca[n_marca].nombre;
						usuario[user_act].marca[n_marca].modelo[n_modelo].nombre=marca[n_marca].modelos[n_modelo].nombre;
						usuario[user_act].marca[n_marca].modelo[n_modelo].codigo=marca[n_marca].modelos[n_modelo].codigo;
						usuario[user_act].marca[n_marca].modelo[n_modelo].precio=marca[n_marca].modelos[n_modelo].precio;
						usuario[user_act].marca[n_marca].modelo[n_modelo].cajas=usuario[user_act].marca[n_marca].modelo[n_modelo].cajas+cajas_venta;
						marca[n_marca].modelos[n_modelo].cajas=marca[n_marca].modelos[n_modelo].cajas-cajas_venta;
						usuario[user_act].almacen++;
						cout<<"Gracias por su compraa"<<endl;
						
		            	catalogo_compra();
						goto aaa010;
				}
				if(usuario[user_act].almacen>1000)
			    {	
				    cout<<"Almacen lleno"<<endl;
				    goto aaa001;
			    }
				if(usuario[user_act].marca[n_marca].modelo[n_modelo].cajas<cajas_venta)
				{
					cout<<"No disponemos de las cajas suficientes para distribuirle el producto"<<endl;
					goto aaa001;
				}
				if(usuario[user_act].marca[n_marca].modelo[n_modelo].cajas>=cajas_venta)
				{
					usuario[user_act].marca[n_marca].modelo[n_modelo].cajas++;
					marca[n_marca].modelos[n_modelo].cajas--;
				}
				
			}
		   	
			aaa010:	
			menu_modelos();
			case 2:
				menu_modelos();
		}
	}
	if(n_modelo==6)
	{
		catalogo_compra();
	}
}

	//CARGA DE DATOS
	void carga_datos()
{
	if(inicio==0)
	{
	cout<<endl;
	cout<<"cargando datos, por favor espere...."<<endl;
	//marcas consideradas
	marca[0].nombre="Nike";	          marca[0].des_importe=0.6;   //60%
	marca[1].nombre="Adidas";         marca[1].des_importe=0.5;   //50%
	marca[2].nombre="Converse";	      marca[2].des_importe=0.6;   //60%
	marca[3].nombre="Puma";	          marca[3].des_importe=0.5;   //50%
	marca[4].nombre="Reebok";         marca[4].des_importe=0.5;   //50%
	//modelos-precios y codigos tomados de la web y paginas oficiales =) con aproximacion de costo de "por mayor" , p/u real
	//las tallas van despues de adquirir el producto- crear nueva estructura
	//al parece hay otra forma de almacenar datos =(
	//nike -- www.nike.com.pe
	marca[0].modelos[0].nombre="Blazer Low 77 premium";
	marca[0].modelos[0].codigo="DV7231-200";
	marca[0].modelos[0].precio=469.90*marca[0].des_importe;
	marca[0].modelos[0].cajas=100;
	marca[0].modelos[1].nombre="Air Jordan 1 Retro Low OG";
	marca[0].modelos[1].codigo="DV0982-100";
	marca[0].modelos[1].precio=719*marca[0].des_importe;
	marca[0].modelos[1].cajas=200;
	marca[0].modelos[2].nombre="Dunk Low SV";
	marca[0].modelos[2].codigo="DZ5224-300";
	marca[0].modelos[2].precio=579.90*marca[0].des_importe;
	marca[0].modelos[2].cajas=50;
	marca[0].modelos[3].nombre="Pegasus 40 Premium";
	marca[0].modelos[3].codigo="FB7703-001";
	marca[0].modelos[3].precio=649.9*marca[0].des_importe;
	marca[0].modelos[3].cajas=40;
	marca[0].modelos[4].nombre="Air force 1 '07 SE";
	marca[0].modelos[4].codigo="DQ7582-100";
	marca[0].modelos[4].precio=579.90*marca[0].des_importe;
	marca[0].modelos[4].cajas=90;
	//adidas -- www.adidas.pe
	marca[1].modelos[0].nombre="originals FORUM MID";
	marca[1].modelos[0].codigo="FZ6275";
	marca[1].modelos[0].precio=449*marca[1].des_importe;
	marca[1].modelos[0].cajas=60;
	marca[1].modelos[1].nombre="ULTRABOOST 22";
	marca[1].modelos[1].codigo="HP9930";
	marca[1].modelos[1].precio=559*marca[1].des_importe;
	marca[1].modelos[1].cajas=50;
	marca[1].modelos[2].nombre="Samba THE VELOSAMBA MADE WITH NATURE";
	marca[1].modelos[2].codigo="HQ9036";
	marca[1].modelos[2].precio=549*marca[1].des_importe;
	marca[1].modelos[2].cajas=40;
	marca[1].modelos[3].nombre="Sportswear ULTRA ADIDAS 4D";
	marca[1].modelos[3].codigo="HP9737";
	marca[1].modelos[3].precio=999*marca[1].des_importe;
	marca[1].modelos[3].cajas=10;
	marca[1].modelos[4].nombre="Basquet TRAE UNLIMITED";
	marca[1].modelos[4].codigo="HQ1020";
	marca[1].modelos[4].precio=449*marca[1].des_importe;
	marca[1].modelos[4].cajas=90;
	//converse -- www.coliseum.com.pe
	marca[2].modelos[0].nombre="Chuck 70 AT-CX";
	marca[2].modelos[0].codigo="A03425C-0";
	marca[2].modelos[0].precio=449.90*marca[2].des_importe;
	marca[2].modelos[0].cajas=50;
	marca[2].modelos[1].nombre="Chuck Taylor All Star Lift Platform Pride";
	marca[2].modelos[1].codigo="A06031C-0";
	marca[2].modelos[1].precio=459.90*marca[2].des_importe;
	marca[2].modelos[1].cajas=60;
	marca[2].modelos[2].nombre="Chuck Taylor All Star Lugged 2.0 Platform Utility";
	marca[2].modelos[2].codigo="A03500C-0";
	marca[2].modelos[2].precio=349.90*marca[2].des_importe;
	marca[2].modelos[2].cajas=70;
	marca[2].modelos[3].nombre="Run Star Motion CX Platform Marbled";
	marca[2].modelos[3].codigo="A03552C-0";
	marca[2].modelos[3].precio=479.90*marca[2].des_importe;
	marca[2].modelos[3].cajas=80;
	marca[2].modelos[4].nombre="Chuck Taylor All Star Core Hi";
	marca[2].modelos[4].codigo="157197C-0";
	marca[2].modelos[4].precio=269.90*marca[2].des_importe;
	marca[2].modelos[4].cajas=100;
	//puma-- eu.puma.com
	marca[3].modelos[0].nombre="Slipstream FBball";
	marca[3].modelos[0].codigo="393266_01";
	marca[3].modelos[0].precio=472.70*marca[3].des_importe;
	marca[3].modelos[0].cajas=70;
	marca[3].modelos[1].nombre="ULTRA ULTIMATE FG/AG Football Boots";
	marca[3].modelos[1].codigo="107311_01";
	marca[3].modelos[1].precio=866.70*marca[3].des_importe;
	marca[3].modelos[1].cajas=30;
	marca[3].modelos[2].nombre="PUMA x KOCHE Plexus";
	marca[3].modelos[2].codigo="392078_01";
	marca[3].modelos[2].precio=590.90*marca[3].des_importe;
	marca[3].modelos[2].cajas=120;
	marca[3].modelos[3].nombre="RBD Game Low";
	marca[3].modelos[3].codigo="386373_07";
	marca[3].modelos[3].precio=216.50*marca[3].des_importe;
	marca[3].modelos[3].cajas=180;
	marca[3].modelos[4].nombre="Disc Blaze OG";
	marca[3].modelos[4].codigo="390931_02";
	marca[3].modelos[4].precio=590.90*marca[3].des_importe;
	marca[3].modelos[4].cajas=50;
	//reebok --www.reebok.mx
	marca[4].modelos[0].nombre="Tenis Classic Leather";
	marca[4].modelos[0].codigo="IE4100";
	marca[4].modelos[0].precio=484.70*marca[4].des_importe;
	marca[4].modelos[0].cajas=100;
	marca[4].modelos[1].nombre="Tenis Nano X3";
	marca[4].modelos[1].codigo="HP6046";
	marca[4].modelos[1].precio=611.20*marca[4].des_importe;
	marca[4].modelos[1].cajas=70;
	marca[4].modelos[2].nombre="Tenis Shaq Attaq Street Fighter";
	marca[4].modelos[2].codigo="HR0603";
	marca[4].modelos[2].precio=843.10*marca[4].des_importe;
	marca[4].modelos[2].cajas=60;
	marca[4].modelos[3].nombre="Tenis Club C 85 Eames";
	marca[4].modelos[3].codigo="GY1068";
	marca[4].modelos[3].precio=590.10*marca[4].des_importe;
	marca[4].modelos[3].cajas=100;
	marca[4].modelos[4].nombre="Tenis Royal Complete Sport";
	marca[4].modelos[4].codigo="GW1543";
	marca[4].modelos[4].precio=242.20*marca[4].des_importe;
	marca[4].modelos[4].cajas=60;		
	}
	inicio=1;		
	menu_inicio();
}

void cajero()
{
	cout<<"Aqui puede depocitar de manera rapida y eficaz a su cuenta empresarial"<<endl<<endl;
	cout<<"1.DEPOSITO PARA COMPRAS"<<endl;
	cout<<"2.ESTADO MONETARIO DE CUENTA"<<endl;
	cout<<"3.VOLVER AL MENU ANTERIOR"<<endl;
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
	
	if(usuario[user_act].saldo_empresarial>100000)
	{
		cout<<"Lo sentimos, no puede realizar depositos por ahora, el maximo de saldo en este programa es de 100000 soles"<<endl;
		cajero();
	}
	
	if(monto>100000)
	{
		cout<<"Por seguridad solo puede depositar 100000 soles a su cuenta por transaccion"<<endl;
		goto aaa011;
	}
	if(monto>0 and monto<=100000)
	{
		if(n_deposito==n_organizador)
		{
			cout<<"DENTROOOOOOOOOOO"<<endl;
			n_deposito=0;
			n_organizador=0;
			//este for organizara los depositos, para que siga aumentandose el historial
			for(int i=9; i>0; i--)
			{
				usuario[user_act].deposito[i].monto=usuario[user_act].deposito[i-1].monto;
			}
		}
		
		usuario[user_act].saldo_empresarial+=monto;
		usuario[user_act].deposito[n_deposito].monto=monto;
		monto=0;
		cout<<"Depocito realizado, su nuevo saldo es de "<<usuario[user_act].saldo_empresarial<<" soles =)"<<endl;
		if(n_organizador==0)
		{
			cajero();
		}	
		n_deposito++;
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
	cout<<"1.DINERO EN CUENTA"<<endl;
	cout<<"2.DEPOSITOS REALIZADOS"<<endl;
	cout<<"3.VOLVER AL MENU ANTERIOR"<<endl;
	cin>>opc;
	switch(opc)
	{
		case 1: 
		cout<<"Saldo en cuenta empresarial: "<<usuario[user_act].saldo_empresarial<<" soles"<<endl;
		cajero();
		case 2:
			cout<<"ESTOS SON SUS ULTIMOS 10 DEPOSITOS A SU CUENTA EMPRESARIAL"<<endl;
			for(int i=0; i<10; i++)
			{
				cout<<i+1<<"."<<usuario[user_act].deposito[i].monto<<" soles"<<endl;
			}
			cajero();
		case 3:
		cajero();
	}
}


void ini_datos()
{
	GIDAEP.nombre="GIDAEP";
	GIDAEP.username="GIDAEP";
	GIDAEP.password="VillarP";
}


void menu_tiendas()
{
	cout<<"==========MENU - TIENDAS =========="<<endl;
	cout<<endl<<"Hola "<<usuario[user_act].nombre<<endl;
	cout<<"Aqui puedes gestionar tus tiendas"<<endl;
	cout<<"1.Registrar tiendas"<<endl;
	cout<<"2.Ver tiendas"<<endl;
	cout<<"3.Enviar productos a mis tiendas"<<endl;
	cout<<"4.Registro de datos"<<endl;
	cout<<"5.Volver al menu anterior"<<endl;
	cin>>opc;
	switch(opc)
	{
		case 1: 
	     	registro_tiendas();
			break;
		case 2:
		    ver_tiendas();
		    break;
		case 3:
			envio_productos();
			break;
		case 4:
			registro_datos();
			break;
			
		case 5:
			menu_inicio();
			
		default: 
		break;
	}
}


void registro_tiendas()
{
		cout<<"necesitamos que nos especifique la cantidad de tiendas que deseas registrar"<<endl;
		cout<<"Tiendas a añadir: ";
		cin>>cantidad_aumento_tiendas;
	
	cout<<"Ahora nombre sus tiendas y agregue la direccion, para una administracion mas sencilla"<<endl;
		for(int i=cantidad_tiendas; i<cantidad_aumento_tiendas+cantidad_tiendas; i++)
		{
		cout<<"Nombre: ";
		cin>>usuario[user_act].tienda[i].nombre;
		cout<<"Direccion: ";
		cin>>usuario[user_act].tienda[i].direccion;
		}
	usuario[user_act].cantidad_tiendas+=cantidad_aumento_tiendas;
	cantidad_tiendas+=cantidad_aumento_tiendas;
	cout<<"Tiendas registradas"<<endl;
	menu_tiendas();
}

void ver_tiendas()
{
		cout<<"1.Ver todas las tiendas"<<endl;
		cout<<"2.Buscar por nombre"<<endl;
		cout<<"3.Volver al menu anterior"<<endl;
		cin>>opc;
		switch(opc)
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

void tiendas_totales()
{
	for(int i=0; i<cantidad_tiendas; i++)
	{
			cout<<"Tienda "<<i+1<<endl;
			cout<<"Nombre: "<<usuario[user_act].tienda[i].nombre<<endl;
			cout<<"Direccion: "<<usuario[user_act].tienda[i].direccion<<endl<<endl;
			//agregar if de si existe producto o no en la tienda
			for(int k=0; k<total_marcas+1; k++)
			{
				for(int l=0; l<5; l++)
				{
					if(usuario[user_act].tienda[i].marca_producto[k].modelo_producto[l].cajas>=1)
					{
						cout<<"Producto "<<endl;
						cout<<"Marca: "<<usuario[user_act].tienda[i].marca_producto[k].nombre<<endl;
						cout<<"Modelo: "<<usuario[user_act].tienda[i].marca_producto[k].modelo_producto[l].nombre<<endl;
						cout<<"Modelo: "<<usuario[user_act].tienda[i].marca_producto[k].modelo_producto[l].codigo<<endl;
						cout<<"Modelo: "<<usuario[user_act].tienda[i].marca_producto[k].modelo_producto[l].precio<<endl;
						cout<<"Cantidad de cajas: "<<usuario[user_act].tienda[i].marca_producto[k].modelo_producto[l].cajas<<endl<<endl;
					}
				}	
			}			
	}
	menu_tiendas();
}



void tiendas_buscador()
{
cout<<"Por favor digite el nombre de la tienda"<<endl;

	cin>>almacen_char;
	opc=101;
	for(int i=0; i<cantidad_tiendas; i++)
	{
	  	if(almacen_char==usuario[user_act].tienda[i].nombre)
		{	
			cout<<"tienda encontrada"<<endl;
			cout<<"Nombre: "<<usuario[user_act].tienda[i].nombre<<endl;
			cout<<"Direccion: "<<usuario[user_act].tienda[i].direccion<<endl;
			opc=100;
			//agregar if de si existe producto o no en la tienda
			for(int j=0; j<usuario[user_act].tienda[i].n_productos;j++)
			{
				cout<<"Producto "<<j+1<<endl;
				for(int k=0; k<total_marcas+1; k++)
				{
					for(int l=0; l<5; l++)
					{
						if(usuario[user_act].tienda[i].marca_producto[k].modelo_producto[l].cajas>=1)
						{
							opc=99;
							cout<<"Marca: "<<usuario[user_act].tienda[i].marca_producto[k].nombre<<endl;
							cout<<"Modelo: "<<usuario[user_act].tienda[i].marca_producto[k].modelo_producto[l].nombre<<endl;
							cout<<"Modelo: "<<usuario[user_act].tienda[i].marca_producto[k].modelo_producto[l].codigo<<endl;
							cout<<"Modelo: "<<usuario[user_act].tienda[i].marca_producto[k].modelo_producto[l].precio<<endl;
							cout<<"Cantidad de cajas: "<<usuario[user_act].tienda[i].marca_producto[k].modelo_producto[l].cajas<<endl<<endl;
						}	
					}
				}
			}
		}
	}
	if(opc==100)
	{
		cout<<"Esta tienda no dispone de ningun articulo"<<endl;
		opc=0;
		menu_tiendas;
	}
	if(opc==101)
	{
		cout<<"tienda no encontrada"<<endl;
		opc=0;
		menu_tiendas();	
	}
	if(opc=99)
	{
		menu_tiendas();
	}
}

void registro_datos()
{
	for(int i=0; i<cantidad_tiendas; i++)
	{
		if(usuario[user_act].tienda[i].movimientos!=0)
		{
			for(int i=0; i<cantidad_tiendas; i++)
			{
				cout<<"Usted realizo "<<usuario[user_act].tienda[i].movimientos<<" envios a la tienda "<<usuario[user_act].tienda[i].nombre<<endl;
				opc=108;
			}
		}
	}
	if(opc!=108)
	{
		cout<<"No hizo ningun movimiento hasta ahora"<<endl<<endl;
	}
menu_tiendas();	
}

void envio_productos()
{
	if(envio==1)
	{
		envio--;
		goto aaa001;
	}
	cout<<"Digite el nombre de la tienda a la que desea enviarle el producto"<<endl;
	cin>>almacen_char;
	for(int i=0; i<cantidad_tiendas; i++)
	{
	  	if(almacen_char==usuario[user_act].tienda[i].nombre)
		{
			cout<<"tienda encontrada"<<endl;
			cout<<"Nombre: "<<usuario[user_act].tienda[i].nombre<<endl;
			cout<<"Direccion: "<<usuario[user_act].tienda[i].direccion<<endl<<endl;
			n_tienda=i;
			goto aaa003;
		}	
	}
	cout<<"Esta tienda no esta registrada"<<endl;
	menu_tiendas();	
	
	aaa003:
	cout<<"seleccione el producto del almacen a enviar"<<endl;
	envio++;
	almacen();
	aaa001:
	//interactuar con el almacen
	if(opc==21)
	{
		usuario[user_act].tienda[n_tienda].n_productos++;
		cout<<"Producto "<<usuario[user_act].tienda[n_tienda].marca_producto[n_marca].modelo_producto[n_modelo].nombre<<" enviado a la tienda "<<usuario[user_act].tienda[n_tienda].nombre<<endl;
		menu_tiendas();
	}
	if(opc!=21)
	{
		cout<<"Solo puede seleccionar modelos que tenga en su almacen"<<endl;
		menu_tiendas();
	}
}

void almacen()
{
	
	cout<<"Almacen virtual de "<<usuario[user_act].nombre_empresa<<endl<<endl;
	for(int i=0;i<total_marcas+1;i++)
	{
		cout<<"Marca "<<i+1<<endl;
		cout<<marca[i].nombre<<endl;
		
		for(int j=0;j<5;j++)
		{
			if(usuario[user_act].marca[i].modelo[j].cajas!=0)
			{
			cout<<"Modelo: "<<j+1<<endl;
			cout<<"Modelo:"<<usuario[user_act].marca[i].modelo[j].nombre<<endl;
			cout<<"codigo:"<<usuario[user_act].marca[i].modelo[j].codigo<<endl;
			cout<<"precio de venta:"<<usuario[user_act].marca[i].modelo[j].precio<<" soles"<<endl;
			cout<<"cajas: "<<usuario[user_act].marca[i].modelo[j].cajas<<endl;	
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
	if(envio==1)
	{	
		cout<<"Numero de marca: "; cin>>n_marca;
		n_marca--;
		cout<<"Numero de modelo: "; cin>>n_modelo;
		n_modelo--;
		if(usuario[user_act].marca[n_marca].modelo[n_modelo].cajas==1)
		{
			usuario[user_act].tienda[n_tienda].marca_producto[n_marca].nombre=usuario[user_act].marca[n_marca].nombre;
			usuario[user_act].tienda[n_tienda].marca_producto[n_marca].modelo_producto[n_modelo].nombre=usuario[user_act].marca[n_marca].modelo[n_modelo].nombre;
			usuario[user_act].tienda[n_tienda].marca_producto[n_marca].modelo_producto[n_modelo].codigo=usuario[user_act].marca[n_marca].modelo[n_modelo].codigo;
			usuario[user_act].tienda[n_tienda].marca_producto[n_marca].modelo_producto[n_modelo].cajas++;
			usuario[user_act].tienda[n_tienda].marca_producto[n_marca].modelo_producto[n_modelo].precio=usuario[user_act].marca[n_marca].modelo[n_modelo].precio;
			//eliminando cajas y datos del almacen
			usuario[user_act].marca[n_marca].modelo[n_modelo].cajas--;
			//Solo es necesario cambiar las cajas, ya que el for del almacen no se dará si las cajas son iguales a 0
			opc=21;
		}
		if(usuario[user_act].marca[n_marca].modelo[n_modelo].cajas>1)
		{
			usuario[user_act].tienda[n_tienda].marca_producto[n_marca].modelo_producto[n_modelo].cajas++;
			usuario[user_act].marca[n_marca].modelo[n_modelo].cajas--;
			opc=21;
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
