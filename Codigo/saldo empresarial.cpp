// saldo empresarial 

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
int organizador=9;
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
		if(n_deposito==organizador)
		{
			n_deposito=0;
			n_organizador=0;
			//este for organizara los depositos, para que siga aumentandose el historial
			for(int i=9; i>0; i++)
			{
				usuario[user_act].deposito[i].monto=usuario[user_act].deposito[i-1].monto;
			}
		}
		usuario[user_act].saldo_empresarial+=monto;
		monto=0;
		cout<<"Depocito realizado, su nuevo saldo es de "<<usuario[user_act].saldo_empresarial<<" soles =)"<<endl;	
		usuario[user_act].deposito[n_deposito].monto=usuario[user_act].saldo_empresarial;
		n_deposito++;
	    cajero();
	}
	if(monto<0)
	{
		cout<<"No puede depocitar un saldo negativo"<<endl;
		goto aaa011;
	}
}
int n_deposito=0;
	
void estado_cuenta()
{
	cout<<"1.DINERO EN CUENTA"<<endl;
	cout<<"2.DEPOSITOS REALIZADOS";
	cout<<"3.VOLVER AL MENU ANTERIOR"<<endl;
	cin>>opc;
	switch(opc)
	{
		case 1: 
		cout<<"Saldo en cuenta empresarial: "<<usuario[user_act].saldo_empresarial<<" soles"<<endl;
		case 2:
			cout<<"ESTOS SON SUS ULTIMOS 5 DEPOSITOS A SU CUENTA EMPRESARIAL"<<endl;
			for(int i=0; i<9; i++)
			{
				cout<<i+1<<usuario[user_act].deposito[i].monto<<endl;
			}
		case 3:
		cajero();
	}
}

struct depo
{
	float monto;
}deposito[5]
