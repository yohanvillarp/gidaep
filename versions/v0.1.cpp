//este es el codigo desordenado 

#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
//arreglar codigo desde el principio
//distribucion de productos a tiendas de la empresa
//importes y almacenaje solo mostrando modelo y pares totales 
//corregir almacen solo 10
//implementar el sistema de ventaaaa
//agregar cajero de empresa? - cartera empresarial?
//idea: crear manual de usuario en el primer menu
//idea: aplicaciones para el admin
//aumentar inventario de catalogo xD - tambien funcion de agregar marcas para el admin

//1.sistema de usuarios
//declaracion de funciones
void iniciar_sesion(),registrarse(),menu_user();
void menu_inicio(),distribucion(),almacen(),datos_inicializados(),catalogo_compra(),menu_modelos(),menu_admin();
void inicializacion_datos_admin(),menu_admin();
//declaracion de variables
int opc,activador=0,aux=0,user_num=0;
int opc2,opc3,opc4,opc5,opc6,opc7,aux2,aux4=0,aux5=0,inicio=0,salto_de_lineas=0,admin_cont=0;
int m=0,n=0;    //donde n representa la cantidad de productos en nuestro almacen y m corresponde al importe de 10 pares de productos"zapatillas"
float precio_pormayor=0,error=0;
int nike=0,adidas=0,reebok=0,puma=0,converse=0;
int fin=0;
char empresa_alm[20],pass_alm[15];

//usar la misma variable para muchas cosas en el futuro , ordenaaar
//ESTRUCTURAS

struct admin
{
	string username;
	string password;
}admin;

void inicializacion_datos_admin()
{
	admin.username="yohanvp2106";
	admin.password="aryo_1308";
}

void menu_admin()
{
	cout<<"ESTE APARTADO AUN NO ESTA TERMINADO"<<endl;
	admin_cont=100000000;
}

struct usuarios
{
	char nombre[10];
	char apellido[10];
	int DNI;
	char nombre_empresa[20];
	char password[15];           //se usa password por que c++ no reconoce la ñ
	struct almacenes
	{
		string modelo;
		string estilo;
		string codigo;
		float precio;
		struct tallas
		{
			int tallas;
		}talla[12];
	}almacen[1000];
	
}usuario[10];                 //maximo de 10(en proceso) usuarios 

struct Marca
{
	string nombre;
	int descuento;
	struct modelos
{
	string modelo;	string estilo;	string codigo;
	int cantidad_disponible;   
	float precio;
	struct tallas
	{
		int tallas;
	}talla[10];
	
}nike[5],adidas[5],converse[5],puma[5],reebok[5];            //reemplaza por marca? cambiaria todo el codigo =(   marca[i] representara a cada marca 

}marca[10];

/*marca[0].nombre="Nike";	          
	marca[1].nombre="Adidas";        
	marca[2].nombre="Converse";	    
	marca[3].nombre="Puma";	        
	marca[4].nombre="Reebok";       
*/


//programa principal- ordenar eso waaaaaaaaa- todo va bien hasta hora
//ordenar almacen 
//y posiblemente crear un cajero para empresas
int main()
{
	//solucionar lo de salir xD
	menu_user();
	inicializacion_datos_admin();
	if(error==5 or fin==1)
	{
	goto aaa005;
	}
	menu_inicio();
	aaa005:
	cout<<endl<<"Hasta pronto"<<endl;
	getch();
	return 0;
}

//MENUS
void menu_user()
{
	if(activador==2)
			{
				activador=0;
				main();
			}
	cout<<"BIENVENIDO A ARYO , GRACIAS POR CONFIAR EN NUESTRO SISTEMA =)"<<endl;
	cout<<"por favor inicie secion o registrese"<<endl<<endl;
	
	cout<<"1.INICIAR SESION"<<endl;
	cout<<"2.REGISTRARSE"<<endl;
	cout<<"3.SALIR"<<endl<<endl;
	//proximamente ... manual del usuario
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
			fin++;
			break;
	}
	
}

void menu_inicio()
{
	if(salto_de_lineas==1)
	{
		goto aaa007;
	}
	cout<<endl<<endl;
	cout<<"Bienvenido "<<usuario[aux].nombre<<" "<< usuario[aux].apellido<<endl;
	cout<<"gracias por preferir el sistema VIKEL para su empresa"<<endl;
	cout<<"Esperamos que la empresa "<<usuario[aux].nombre_empresa<<" pueda estar satisfecha con nuestro servicio"<<endl<<endl;
	salto_de_lineas=1;
	aaa007:
	cout<<"que quiere hacer hoy?"<<endl<<endl;
	cout<<"1.Comprar al por mayor"<<endl;
	cout<<"2.Distribuir"<<endl;
	cout<<"3.Ver almacen"<<endl;
	cout<<"4.Volver al menu anterior"<<endl;
	cout<<"5.Salir"<<endl;
	cin>>opc2;
	switch(opc2)
	{
	case 1: 
		catalogo_compra();
	case 2:
		distribucion();
	case 3:
		almacen();
	case 4:
		menu_user();
	case 5:
		break;
		
	}
}


//REGISTRO....1
void registrarse()
{	
//sistema que inicie usuarios
	if(user_num>10)
	{
		cout<<"Este sistema no admite mas de 10 cuentas"<<endl<<endl;
		menu_user();
	}
		cout<<"por favor ingrese los siguientes datos"<<endl<<endl;
		cout<<"Nombre: ";  cin>>usuario[user_num].nombre,10; 
		cout<<"Apellido: "; cin>>usuario[user_num].apellido,10; 
		aaa007:
		cout<<"DNI: "; cin>>usuario[user_num].DNI;
		if(usuario[user_num].DNI<=10000000 or usuario[user_num].DNI>=99999999)
		{
			cout<<"digite un DNI valido por favor =)"<<endl;
			goto aaa007;
		} 
		cout<<"Nombre de la empresa: "; cin>>usuario[user_num].nombre_empresa; 
		//idea: compaaracion de nombre de empresas para no crear con el mismo nombre
		cout<<"Password: "; cin>>usuario[user_num].password;
		user_num++;
		
	menu_user();
}

void iniciar_sesion()
{
	//resolver problema de usuario aun no registrado iniciando sesion
	aaa008:
		if(error==5)
		{
			cout<<"demasiados errores cometidos"<<endl;
			goto aaa006;
		}
	cout<<"NOMBRE DE LA EMPRESA: "; 
	cin>>empresa_alm;
	
	if(admin.username==empresa_alm)
		{
			admin_cont++;
			goto aaa006;	
		}
		
	for(int i=0; i<10; i++)
	{
		if(strcmp(usuario[i].nombre_empresa,empresa_alm)==0)
		{
			//solucionar problema de inicio de sesion al iniciar sin cuenta y luego registrarse para volverse a registrar - fallo 
			activador++;
			cout<<"Empresa encontrada en la base de datos"<<endl;
			aux=i;
			goto aaa006;
		}
		
		if(strcmp(usuario[i].nombre_empresa,empresa_alm)!=0)
		{
			if(activador==2)
			{
				datos_inicializados();
			}
			//pequeño error al ingresar varias veces el usuario admin y poner nombre de empresa incorrecta
			else
			{
			cout<<"Esta empresa no esta registrada en nuestra base de datos"<<endl<<endl;
			menu_user();	
			}	
		}
	}
		
	aaa006:
	if(admin_cont==1)
	{
		cout<<"PASSWORD x): ";  
		cin>>pass_alm;
		if(pass_alm==admin.password and error!=5)
		{
			admin_cont++;
			cout<<"Por seguridad la contraseña se le pedira seguido..."<<endl<<endl;
			menu_admin();
		}
		else
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
		cin>>pass_alm;
		if(strcmp(pass_alm,usuario[aux].password)==0)
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
	cout<<endl;	cin>>opc3;
	switch(opc3)
	{
		case 1:
			nike=1;
			menu_modelos();
			break;
		case 2:
			adidas=1;
			menu_modelos();
			break;
		case 3:
			converse=1;
			menu_modelos();
			break;
		case 4:
			puma=1;
			menu_modelos();
			break;
		case 5:
			reebok=1;
			menu_modelos();
			break;
		case 6:
			menu_inicio();
	}
}	
	
void menu_modelos()
{
	aaa002:
	for(int i=opc3; i<opc3+1;i++)
	{
			cout<<"Bienvenido a la distribuidora "<<marca[i-1].nombre<<" ,estos son los modelos disponibles"<<endl;
			cout<<"Esta distribuidora esta dispuesta a descontarte el "<<marca[i-1].descuento<<"% por importe de cada caja(12 pares del mismo modelo)"<<endl<<endl;
	}
			if(nike==1)
		{
			for(int i=0; i<5; i++)
			{
				cout<<i+1<<" "<<marca[0].nike[i].modelo<<"-"<<marca[0].nike[i].estilo<<"-precio:"<<marca[0].nike[i].precio<<"- cantidad disponible:"<<marca[0].nike[i].cantidad_disponible<<endl;
				aux4=i;
				nike=0;
			}
		}
		if(adidas==1)
		{
			for(int i=0; i<5; i++)
			{
				cout<<i+1<<" "<<marca[1].adidas[i].modelo<<"-"<<marca[1].adidas[i].estilo<<"-precio:"<<marca[1].adidas[i].precio<<"- cantidad disponible:"<<marca[1].adidas[i].cantidad_disponible<<endl;
				aux4=i;
				aux=i;
				adidas=0;
			}
		}
		if(converse==1)
		{
			for(int i=0; i<5; i++)
			{
				cout<<i+1<<" "<<marca[2].converse[i].modelo<<"-"<<marca[2].converse[i].estilo<<"-precio:"<<marca[2].converse[i].precio<<"- cantidad disponible:"<<marca[2].converse[i].cantidad_disponible<<endl;
				aux4=i;
				converse=0;
			}
		}
		if(puma==1)
		{
			for(int i=0; i<5; i++)
			{
				cout<<i+1<<" "<<marca[3].puma[i].modelo<<"-"<<marca[3].puma[i].estilo<<"-precio:"<<marca[3].puma[i].precio<<"- cantidad disponible:"<<marca[3].puma[i].cantidad_disponible<<endl;
				puma=0;
			}
		}
		if(reebok==1)
		{
			for(int i=0; i<5; i++)
			{
				cout<<i+1<<" "<<marca[4].reebok[i].modelo<<"-"<<marca[4].reebok[i].estilo<<"-precio:"<<marca[4].reebok[i].precio<<"- cantidad disponible:"<<marca[4].reebok[i].cantidad_disponible<<endl;
				aux4=i;                 //sirve para determinar el numero de modelo :3 , no borrar
				reebok=0;
			}
		}
	
	cout<<"6.volver al menu anterior"<<endl;
	cin>>opc4; 
	switch(opc4)
	{
		case 1:
			marca[0].nike[0].cantidad_disponible=marca[0].nike[0].cantidad_disponible-10;
			
				//aumentar cada ambito de la variable al almacen , para que tenga toda su informacion o intentar copiarla y repartirla por tallas :D
			
			//para cada marca un nuevo switch
				//********************++++corregir*****************************// establecer el caso para cada modelo y mandarlo al almacen 

					//nueva variable para importar el modelo xDDD- el switch no es necesario
					cout<<"Comprar?"<<endl;
					cout<<"1.SI"<<endl;
					cout<<"2.NO"<<endl;
					cin>>opc7;
					switch(opc7)
					{	
					case 1:
					
						//corregir esto , declarar un if , para ver si el almacen esta vacio o no "i"
						m=n+10;
						if(m-10>=1000)
						{
							cout<<"Almacen lleno"<<endl;
						}
						for(int i=n,j=0; i<m,j<10; i++,j++)
						{
						usuario[user_num].almacen[i].modelo=marca[0].nike[aux4].modelo;
						usuario[user_num].almacen[i].estilo=marca[0].nike[aux4].estilo;
						usuario[user_num].almacen[i].codigo=marca[0].nike[aux4].codigo;
						usuario[user_num].almacen[i].precio=marca[0].nike[aux4].precio*marca[0].descuento/100;
						usuario[user_num].almacen[j].talla[j].tallas=34+j;	
						}
						n=n+10;
					
					aux4=0;
					cout<<"Gracias por su compraa"<<endl;
					catalogo_compra();
					case 2:
						goto aaa002;
						break;
						
					}
		case 2:
			marca[1].adidas[1].cantidad_disponible=marca[1].adidas[1].cantidad_disponible-10;
			cout<<"Comprar?"<<endl;
					cout<<"1.SI"<<endl;
					cout<<"2.NO"<<endl;
					cin>>opc7;
					switch(opc7)
					{	
					case 1:
					m=n+10;
					if(m-10>=1000)
					{
					cout<<"Almacen lleno"<<endl;
					}
					for(int i=n,j=0; i<m,j<10; i++,j++)
					{
					usuario[user_num].almacen[user_num].modelo=marca[0].adidas[aux4].modelo;
					usuario[user_num].almacen[user_num].estilo=marca[0].adidas[aux4].estilo;
					usuario[user_num].almacen[user_num].codigo=marca[0].adidas[aux4].codigo;
					usuario[user_num].almacen[user_num].precio=marca[0].adidas[aux4].precio*marca[1].descuento/100;
					usuario[user_num].almacen[user_num].talla[j].tallas=34+j;
					}
					n=n+10;
				aux4=0;
				cout<<"Gracias por su compraa"<<endl;
				catalogo_compra();
					case 2:
						goto aaa002;
						break;
					}
			case 3:
			marca[2].converse[2].cantidad_disponible=marca[2].converse[2].cantidad_disponible-10;
			cout<<"Comprar?"<<endl;
					cout<<"1.SI"<<endl;
					cout<<"2.NO"<<endl;
					cin>>opc7;
					switch(opc7)
					{	
					case 1:
					m=n+10;
					if(m-10>=1000)
					{
						cout<<"Almacen lleno"<<endl;
					}
					for(int i=n,j=0; i<m,j<10; i++,j++)
					{
					usuario[user_num].almacen[user_num].modelo=marca[0].converse[aux4].modelo;
					usuario[user_num].almacen[user_num].estilo=marca[0].converse[aux4].estilo;
					usuario[user_num].almacen[user_num].codigo=marca[0].converse[aux4].codigo;
					usuario[user_num].almacen[user_num].precio=marca[0].converse[aux4].precio*marca[2].descuento/100;
					usuario[user_num].almacen[user_num].talla[j].tallas=34+j;
					}
					n=n+10;
				aux4=0;
				cout<<"Gracias por su compraa"<<endl;
				catalogo_compra();
					case 2:
						goto aaa002;
						break;
					}
		case 4:
			marca[3].puma[3].cantidad_disponible=marca[4].converse[4].cantidad_disponible-10;
			cout<<"Comprar?"<<endl;
					cout<<"1.SI"<<endl;
					cout<<"2.NO"<<endl;
					cin>>opc7;
					switch(opc7)
					{	
					case 1:
					m=n+10;
					if(m-10>=1000)
					{
						cout<<"Almacen lleno"<<endl;
					}
					for(int i=n,j=0; i<m,j<10; i++,j++)
					{
					usuario[user_num].almacen[user_num].modelo=marca[0].puma[aux4].modelo;
					usuario[user_num].almacen[user_num].estilo=marca[0].puma[aux4].estilo;
					usuario[user_num].almacen[user_num].codigo=marca[0].puma[aux4].codigo;
					usuario[user_num].almacen[user_num].precio=marca[0].puma[aux4].precio*marca[3].descuento/100;
					usuario[user_num].almacen[user_num].talla[j].tallas=34+j;
					}
					n=n+10;
				aux4=0;
				cout<<"Gracias por su compraa"<<endl;
				catalogo_compra();
					case 2:
						goto aaa002;
						break;
					}
		case 5:
			marca[4].reebok[4].cantidad_disponible=marca[4].reebok[4].cantidad_disponible-10;
			cout<<"Comprar?"<<endl;
					cout<<"1.SI"<<endl;
					cout<<"2.NO"<<endl;
					cin>>opc7;
					switch(opc7)
					{	
					case 1:
					m=n+10;
					if(m-10>=1000)
					{
						cout<<"Almacen lleno"<<endl;
					}
					for(int i=n,j=0; i<m,j<10; i++,j++)
					{
					usuario[user_num].almacen[user_num].modelo=marca[0].reebok[aux4].modelo;
					usuario[user_num].almacen[user_num].estilo=marca[0].reebok[aux4].estilo;
					usuario[user_num].almacen[user_num].codigo=marca[0].reebok[aux4].codigo;
					usuario[user_num].almacen[user_num].precio=marca[0].reebok[aux4].precio*marca[4].descuento/100;
					usuario[user_num].almacen[user_num].talla[j].tallas=34+j;
					}
					n=n+10;
				aux4=0;
				cout<<"Gracias por su compraa"<<endl;
				catalogo_compra();
					case 2:
						goto aaa002;
						break;
					}
		case 6: 
			catalogo_compra();
			break;
	}
}


int cantidad_tiendas=0,contador=0;
struct tienda
{
	int nombre;
	string direccion;
	//factores como el numero de ventas dependen de la tienda
	int numero_ventas;
}tiendas[5];

void distribucion()
{
	//variable de primera vez para evitar nombrar de nuevo
	cout<<"necesitamos que nos especifique la cantidad de tiendas de las que dispone su empresa"<<endl;
	cin>>cantidad_tiendas;
	//dato previo
	cantidad_tiendas=5;
	cout<<"especifique a la tienda que desea acceder"<<endl;
	//opcion de direcciones ramdon
	if(contador=0)
	{
		cout<<"Como es la primera vez que accede al programa , tiene que nombrar a cada una de sus tiendas y brindar su ubicacion, puede leer en el manual de usuarios, el por que este paso, gracias =)"<<endl<<endl;
		for(int i=0; i<5;i++)
		{
		cout<<"Tienda "<<i<<": "<<endl;
		cout<<"Nombre: ";
		cin>>tiendas[i].nombre;
		 cout<<endl<<"direccion: "; 
		cin>>tiendas[i].direccion;
		}
		contador++;
		cout<<"analizando datos...";
		cout<<"DATOS ANALIZADOS";
		
		//esto lleva al almacen ?? que rarp xD
	}
	if(contador>0)
	{
		for(int i=0; i<5;i++)
	{
		cout<<tiendas[i].nombre<<"__"<<tiendas[i].direccion<<endl;
	}
	}
	
	
	
}


void almacen()
{
	//ampliar a 1000
	cout<<"Aqui se guardan todos los productos de los que dispones"<<endl;
	for(int i=0;i<1000;i++)
		{
		if(usuario[user_num].almacen[i].talla[i].tallas==0)
		{
			i++;
		}
		else
		{
		cout<<i+1<<"."<<"Modelo:"<<usuario[user_num].almacen[i].modelo<<"__";
		cout<<usuario[user_num].almacen[i].estilo<<"__";
		cout<<"codigo:"<<usuario[user_num].almacen[i].codigo<<"__";
		cout<<"precio:"<<usuario[user_num].almacen[i].precio<<" soles__";
		cout<<"talla:"<<usuario[user_num].almacen[i].talla[i].tallas;	
		cout<<endl;	
		aux5++;
		}
		if(aux5==0 and i==999)
		{
			cout<<endl<<"ESTE ALMACEN ESTA VACIO x)"<<endl<<endl;
		}
		if(m==1000)
		{
			cout<<endl<<"ESTE ALMACEN ESTA LLENO =3"<<endl<<endl;
		}
	
	}
		menu_inicio();
}
	//INICIALIZACION
	void datos_inicializados()
{
	
	if(inicio==0)
	{
	cout<<endl;
	cout<<"cargando datos, por favor espere...."<<endl;
	//marcas consideradas
	marca[0].nombre="Nike";	          marca[0].descuento=50;
	marca[1].nombre="Adidas";         marca[1].descuento=60;
	marca[2].nombre="Converse";	      marca[2].descuento=50;
	marca[3].nombre="Puma";	          marca[3].descuento=60;
	marca[4].nombre="Reebok";         marca[4].descuento=50;
	//modelos-precios y codigos tomados de la web y paginas oficiales =) con aproximacion de costo de "por mayor" , p/u real
	//las tallas van despues de adquirir el producto- crear nueva estructura
	//al parece hay otra forma de almacenar datos =(
	//nike -- www.nike.com.pe
	marca[0].nike[0].modelo="Blazer";
	marca[0].nike[0].codigo="DV7231-200";
	marca[0].nike[0].estilo="Low 77 premium";
	marca[0].nike[0].precio=469.90;
	marca[0].nike[0].cantidad_disponible=100;
	marca[0].nike[1].modelo="Air Jordan";
	marca[0].nike[1].codigo="DV0982-100";
	marca[0].nike[1].estilo="1 Retro Low OG";
	marca[0].nike[1].precio=719;
	marca[0].nike[1].cantidad_disponible=200;
	marca[0].nike[2].modelo="Dunk";
	marca[0].nike[2].codigo="DZ5224-300";
	marca[0].nike[2].estilo="Low SV";
	marca[0].nike[2].precio=579.90;
	marca[0].nike[2].cantidad_disponible=50;
	marca[0].nike[3].modelo="Pegasus";
	marca[0].nike[3].codigo="FB7703-001";
	marca[0].nike[3].estilo="40 Premium";
	marca[0].nike[3].precio=649.9;
	marca[0].nike[3].cantidad_disponible=40;
	marca[0].nike[4].modelo="Air force";
	marca[0].nike[4].codigo="DQ7582-101";
	marca[0].nike[4].estilo="1 '07 SE";
	marca[0].nike[4].precio=579.90;
	marca[0].nike[4].cantidad_disponible=90;
	//adidas -- www.adidas.pe
	marca[1].adidas[0].modelo="originals";
	marca[1].adidas[0].codigo="FZ6275";
	marca[1].adidas[0].estilo="FORUM MID";
	marca[1].adidas[0].precio=449;
	marca[1].adidas[0].cantidad_disponible=60;
	marca[1].adidas[1].modelo="ULTRABOOST";
	marca[1].adidas[1].codigo="HP9930";
	marca[1].adidas[1].estilo="22";
	marca[1].adidas[1].precio=559;
	marca[1].adidas[1].cantidad_disponible=50;
	marca[1].adidas[2].modelo="Samba";
	marca[1].adidas[2].codigo="HQ9036";
	marca[1].adidas[2].estilo="THE VELOSAMBA MADE WITH NATURE";
	marca[1].adidas[2].precio=549;
	marca[1].adidas[2].cantidad_disponible=40;
	marca[1].adidas[3].modelo="Sportswear";
	marca[1].adidas[3].codigo="HP9737";
	marca[1].adidas[3].estilo="ULTRA ADIDAS 4D";
	marca[1].adidas[3].precio=999;
	marca[1].adidas[3].cantidad_disponible=10;
	marca[1].adidas[4].modelo="Basquet";
	marca[1].adidas[4].codigo="HQ1020";
	marca[1].adidas[4].estilo="TRAE UNLIMITED";
	marca[1].adidas[4].precio=449;
	marca[1].adidas[4].cantidad_disponible=90;
	//converse -- www.coliseum.com.pe
	marca[2].converse[0].modelo="Chuck 70";
	marca[2].converse[0].codigo="A03425C-0";
	marca[2].converse[0].estilo="AT-CX";
	marca[2].converse[0].precio=449.90;
	marca[2].converse[0].cantidad_disponible=50;
	marca[2].converse[1].modelo="Chuck Taylor";
	marca[2].converse[1].codigo="A06031C-0";
	marca[2].converse[1].estilo="All Star Lift Platform Pride";
	marca[2].converse[1].precio=459.90;
	marca[2].converse[1].cantidad_disponible=60;
	marca[2].converse[2].modelo="Chuck Taylor";
	marca[2].converse[2].codigo="A03500C-0";
	marca[2].converse[2].estilo="All Star Lugged 2.0 Platform Utility";
	marca[2].converse[2].precio=349.90;
	marca[2].converse[2].cantidad_disponible=70;
	marca[2].converse[3].modelo="Run Star";
	marca[2].converse[3].codigo="A03552C-0";
	marca[2].converse[3].estilo="Motion CX Platform Marbled";
	marca[2].converse[3].precio=479.90;
	marca[2].converse[3].cantidad_disponible=80;
	marca[2].converse[4].modelo="Chuck Taylor";
	marca[2].converse[4].codigo="157197C-0";
	marca[2].converse[4].estilo="All Star Core Hi";
	marca[2].converse[4].precio=269.90;
	marca[2].converse[4].cantidad_disponible=100;
	//puma-- eu.puma.com
	marca[3].puma[0].modelo="Slipstream";
	marca[3].puma[0].codigo="393266_01";
	marca[3].puma[0].estilo="FBball";
	marca[3].puma[0].precio=472.70;
	marca[3].puma[0].cantidad_disponible=70;
	marca[3].puma[1].modelo="ULTRA ULTIMATE FG/AG";
	marca[3].puma[1].codigo="107311_01";
	marca[3].puma[1].estilo="Football Boots";
	marca[3].puma[1].precio=866.70;
	marca[3].puma[1].cantidad_disponible=30;
	marca[3].puma[2].modelo="PUMA x KOCHE";
	marca[3].puma[2].codigo="392078_01";
	marca[3].puma[2].estilo="Plexus";
	marca[3].puma[2].precio=590.90;
	marca[3].puma[2].cantidad_disponible=120;
	marca[3].puma[3].modelo="RBD";
	marca[3].puma[3].codigo="386373_07";
	marca[3].puma[3].estilo="Game Low";
	marca[3].puma[3].precio=216.50;
	marca[3].puma[3].cantidad_disponible=180;
	marca[3].puma[4].modelo="Disc Blaze";
	marca[3].puma[4].codigo="390931_02";
	marca[3].puma[4].estilo="OG";
	marca[3].puma[4].precio=590.90;
	marca[3].puma[4].cantidad_disponible=50;
	//reebok --www.reebok.mx
	marca[4].reebok[0].modelo="Tenis";
	marca[4].reebok[0].codigo="IE4100";
	marca[4].reebok[0].estilo="Classic Leather";
	marca[4].reebok[0].precio=484.70;
	marca[4].reebok[0].cantidad_disponible=100;
	marca[4].reebok[1].modelo="Tenis";
	marca[4].reebok[1].codigo="HP6046";
	marca[4].reebok[1].estilo="Nano X3";
	marca[4].reebok[1].precio=611.20;
	marca[4].reebok[1].cantidad_disponible=70;
	marca[4].reebok[2].modelo="Tenis Shaq Attaq";
	marca[4].reebok[2].codigo="HR0603";
	marca[4].reebok[2].estilo="Street Fighter";
	marca[4].reebok[2].precio=843.10;
	marca[4].reebok[2].cantidad_disponible=60;
	marca[4].reebok[3].modelo="Tenis Club";
	marca[4].reebok[3].codigo="GY1068";
	marca[4].reebok[3].estilo="C 85 Eames";
	marca[4].reebok[3].precio=590.10;
	marca[4].reebok[3].cantidad_disponible=100;
	marca[4].reebok[4].modelo="Tenis Royal";
	marca[4].reebok[4].codigo="GW1543";
	marca[4].reebok[4].estilo="Complete Sport";
	marca[4].reebok[4].precio=242.20;
	marca[4].reebok[4].cantidad_disponible=60;		
	}
	inicio++;		
}

