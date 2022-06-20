//Proyecto: Entrega final, manejo de información de la U.
///Por JESÚS TRASLAVIÑA.
//PUJ, 25/05/2020.
#include <iostream>
#include <stdlib.h>
#define maxe 100
#define maxm 20
using namespace std;


///ESTRUCTURAS
struct semestre
{
    char situacion_academica;
    float promedio;
    int creditos;
};

struct estudiante
{
    long int cedula;
    string nombre;
    long int telefono;
    string direccion;
    string ciudad;
    int cant_asig_perdidas;
    string asig_perdidas[maxm];
    int diacumple;
    int mescumple;
    int aniocumple;
    char sexo;
    int semestres_vistos;
    semestre semestres[30];
};


///PROTOTIPOS DE FUNCIONES

int buscar_est(long int cedula, int cant_est, estudiante estudiantes[]);
void lectura (estudiante estudiantes[maxe], int cante, long int cedutemp);
void borrar(estudiante estudiantes[], int indice_buscado, int cante);
void prese_datos(estudiante estudiantes);
float ppa(estudiante est);
int verifi_sexo (estudiante estudiantes[], int cante, int impresiones[],char sexo);
int max_pruebas(estudiante estudiantes[], int cante);
void femeni_prueba(estudiante mujer);
void verifi_exclu(estudiante estudiantes[], int cante);
void grado(estudiante estudiantes[], int cante);
///NUEVA FUNCION_SUSTENTACIÓN.
int infe_tres(estudiante estudiantes[],int  cante, int impresiones[]);

///FUNCIÓN PRINCIPAL
int main ()
{
    int cante=0,op,opcero=0,indice_buscado;//cante, es la cantidad de estudiante; op, es la opción; opcero, es el centinela que verifica el uso de la opción cero; indice_buscado es el estudiante que se busca.
    long int cedutemp;// es la cedula temporal para agregar o borrar.
    char seguro;//centinela de borrar estudiante.
    estudiante estudiantes[maxe]; //Arreglo de tipo estructura estudiante que guarda la información de cada uno.
    int impresiones[maxe];// este arreglo almacena los indices de algunas funciones.
    bool fin=false;//centinela para terminar el programa
    int cuantos_imprimir;//TAMAÑO DEL ARREGLO IMPRESIONES
    int indice_mas_pruebas;//la posición en el arreglo, del estudiante ha estado más veces en prueba.
    cout<<"°°°BASE DE DATOS DE 'LaU'°°(GOMEZ_TRASLAVINA)°°°°"<<endl;
    do
    {
        cout<<endl;
        //Se presenta el menú de opciones
        cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
        cout<<"MENU DE OPCIONES--------"<<endl;
        cout<<"______0.________________Introducir Datos Disp|"<<endl;
        cout<<"______1.________________Lista masculina estud|"<<endl;
        cout<<"______2.________________Lista femenina estudi|"<<endl;
        cout<<"______3.________________El d + vces  n prueba|"<<endl;
        cout<<"______4.________________Asig.Perdidas femenin|"<<endl;
        cout<<"______5.________________ReportarPromedios<3.0|"<<endl;
        cout<<"______6.________________Borrar estu. X cedula|"<<endl;
        cout<<"______7.________________Agregar un Estudiante|"<<endl;
        cout<<"______8.________________Estudiates  Excluidos|"<<endl;
        cout<<"______9.________________Candidatos  al  Grado|"<<endl;
        cout<<"______10.________________Salir  del   Programa|"<<endl;
        cout<<"# de Opcion: ";
        cin>>op;
        //system ("cls");//Borrrar pantalla.
        if((opcero==0 && op!=0 && op!=9)|| (op!=0 && op!=9 && op!=7 && cante==0))
        {
            //Condicional para Restringir uso de otras opciones antes de elegir la cero, o cuando no hay estudiantes.
            cout<<"\nNO HAY ESTUDIANTES!!"<<endl;
            cout<<"SI NO HA UTILIZADO LA OPCION CERO,"<<endl;
            cout<<"UTILICE PRIMERO LA OPCION CERO."<<endl;
            cout<<"DE LO CONTRARIO AGREGUE UN ESTUDIANTE <op=6> POR FAVOR."<<endl;
            cout<<"<#ESTUDIANTES=0>"<<endl;
        }
        else
        {
            switch (op)
            {
            case 0:
                cedutemp=-1;
                if(opcero==0)
                {
                    cout<<"Cantidad de Estudiantes:"<<endl;
                    cin>>cante;
                    lectura(estudiantes,cante, cedutemp);//lamado a la función de lectura.
                    if(cante==0)
                    {
                        cout<<"NO HAY ESTUDIANTES TODAVIA"<<endl;
                    }
                }
                else
                {
                    cout<<endl;
                    cout<<"No se puede volver a ejecutar esta opcion!"<<endl;
                }
                break;
            case 1:
                cuantos_imprimir= verifi_sexo(estudiantes,cante, impresiones, 'm');//se llena el arreglo con solo estudiantes masculinos y se obtine la cantidad.
                cout<<endl;
                cout<<"Los estudiantes masculinos: "<<endl;
                for(int i=0; i<cuantos_imprimir; i++)
                {
                    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                    cout<<"ESTUDIANTE #"<<impresiones[i]+1<<endl;
                    prese_datos(estudiantes[impresiones[i]]);
                    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                }
                cout<<"HAY "<<cuantos_imprimir<<" ESTUDIANTE/S MASCULINO/S"<<endl;
                cout<<endl;
                break;
            case 2:
                cuantos_imprimir= verifi_sexo(estudiantes,cante, impresiones, 'f');//se llena el arreglo con solo estudiantes femeninos y se obtine la cantidad.
                cout<<endl;
                cout<<"Los estudiantes femeninos: "<<endl;
                for(int i=0; i<cuantos_imprimir; i++)
                {
                    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                    cout<<"ESTUDIANTE #"<<impresiones[i]+1<<endl;
                    prese_datos(estudiantes[impresiones[i]]);
                    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;;
                }
                cout<<"HAY "<<cuantos_imprimir<<" ESTUDIANTE/S FEMENINO/S"<<endl;
                cout<<endl;
                break;
            case 3:
                cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                cout<<"La mayor cantidad de veces en prueba es: <";
                indice_mas_pruebas=max_pruebas(estudiantes,cante);
                cout<<">"<<endl;
                if(indice_mas_pruebas!=-1)
                {
                    cout<<"CANTIDAD QUE LE PERTENECE AL : ";
                    cout<<"ESTUDIANTE #"<<indice_mas_pruebas+1<<endl;
                    prese_datos(estudiantes[indice_mas_pruebas]);
                    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                    cout<<"ADVERTENCIA!! SI QUIERE VER LA CANTIDAD"<<endl;
                    cout<<"DE VECES EN PRUEBA, DESLIZAR ARRIBA!!!!"<<endl;
                }
                else
                {
                    cout<<"No hay estudiante que haya estado en prueba"<<endl;
                }
                break;
            case 4:
                cuantos_imprimir= verifi_sexo(estudiantes,cante, impresiones, 'f');
                cout<<" MUJERES QUE ALGUNA VEZ HAN ESTADO EN PRUEBA "<<endl;
                cout<<" Si no se visualizan datos, no existen ..... "<<endl;
                for(int i=0; i<cuantos_imprimir; i++)
                {
                    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                    femeni_prueba(estudiantes[impresiones[i]]);
                    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                }
                cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                cout<<endl;
                break;
            case 5:

                cout<<" ESTUDIANTES CON PROMEDIOS INFERIORES A TRES  "<<endl;
                cuantos_imprimir=infe_tres(estudiantes, cante, impresiones);
                if(cuantos_imprimir>0)
                {
                    for(int i=0; i<cuantos_imprimir; i++)
                    {
                        cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                        prese_datos(estudiantes[i]);
                        cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                    }
                    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                    cout<<endl;

                }
                else
                {
                    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                    cout<<"NO HAY ESTUDIANTES QUE CUMPLAN CON ESA CONDICION"<<endl;
                    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                }
                cout<<"Cantidad de estudiantes que cumplen la condicion: "<<cuantos_imprimir<<endl;

                break;
            case 6:
                //BORRAR UNO.
                cout<<"Cedula a borrar: ";
                cin>>cedutemp;
                indice_buscado=buscar_est(cedutemp, cante, estudiantes);
                if(indice_buscado!=-1)
                {
                    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                    cout<<"ESTUDIANTE #"<<indice_buscado+1<<endl;
                    prese_datos(estudiantes[indice_buscado]);
                    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                    cout<<"Esta seguro de borrar a <"<<estudiantes[indice_buscado].nombre<<">, Si=s o No=n: ";
                    cin>>seguro;
                    if(seguro=='s')
                    {
                        borrar(estudiantes,indice_buscado,cante);
                        cante--;
                        cout<<endl;
                        cout<<"SE HA ELIMINADO EXITOSAMENTE!!"<<endl;
                    }
                    else
                    {
                        cout<<" OK, NO SE BORRA"<<endl;
                    }
                    cout<<endl;
                }
                else
                {
                    cout<<endl;
                    cout<<"NO EXISTE EL ESTUDIANTE!"<<endl;
                }
                break;
            case 7:
                cout<< "Cedula del nuevo: ";
                cin>>cedutemp;
                if((buscar_est(cedutemp, cante, estudiantes)==-1)|| cante==0 )
                {
                    lectura(estudiantes,cante,cedutemp);
                    cante++;
                    cout<<endl;
                    cout<<"SE GUARDO EL ESTUDIANTE"<<endl;
                }
                else
                {
                    cout<<endl;
                    cout<<"YA EXISTE EL ESTUDIANTE"<<endl;
                }
                break;
            case 8:
                cout<<"ESTUDIANTES A EXCLUIR:°°°°°°°"<<endl;
                verifi_exclu(estudiantes, cante);
                cout<<endl;
                break;
            case 9:
                grado(estudiantes, cante);
                break;
            case 10:
                fin=true;
                cout<<".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
                cout<<".-.-.-.FIN DEL PROGRAMA-.-.-.-."<<endl;
                break;

            default:
                cout<<"NO EXISTE ESA OPCION"<<endl;
                break;
            }
            cout<<"CANTIDAD TOTAL DE ESTUDIANTES : "<<cante<<endl;
            if(opcero==0)
            {
                opcero++;

            }
            else
            {
                cout<<"<<<PRESIONE ENTER>>>"<<endl;
                cin.ignore();
                cin.get();
                //Aguardar el reinicio den ciclo.
            }
        }
        //system ("cls");//Borrrar pantalla.
    }
    while(!fin);
}


///FUNCIONES
/**
FUNCION DE la opción 5 nueva.

*/
int infe_tres(estudiante estudiantes[],int  cante, int impresiones[])
{
    int contador=0,cantidad=0;
    for(int i=0; i<cante; i++)
    {
        contador=0;
        for(int j=0; j<estudiantes[i].semestres_vistos; j++)
        {
            if(estudiantes[i].semestres[j].promedio<3)
            {
                contador++;
            }
        }
        if(contador>0)
        {
            impresiones[cantidad]=i;
            cantidad++;
        }
    }
    return cantidad;

}
/**
FUNCION DE LECTURA
    Param [estudiante] estudiantes[]: Arreglo que contiene la información de los estudiantes.
    Param [int] cante: Cantidad actual de estudiantes en el sistema.
    Param [long int] cedutemp: Numero que guarda la cedula nueva y define si es entrada inicial o de un solo estudiante.
    Post: Se registraron exitosamente los datos de los estudiantes
*/
void lectura (estudiante estudiantes[maxe], int cante, long int cedutemp)
{
    //Ingreso de datos masivo en el orden preestablecido.
    int z,repetir;
    repetir=cante;
    if(cedutemp!=-1)
    {
        repetir=1;
    }
    for(int i=0; i<repetir; i++)//Depende de la opcíon que se haya elegido, lo hace una vez o masivamente.
    {
        z=i;
        cout<<endl;
        if(cedutemp==-1)
        {
            cout<<"ESTUDIANTE #"<<i+1<<endl;
        }
        else
        {
            cout<<"ESTUDIANTE #"<<cante+1<<endl;
        }
        cout<< "Cedula : ";
        if(cedutemp==-1)
        {
            cin>>estudiantes[z].cedula;
        }
        else
        {
            cout<<cedutemp<<endl;
            z=cante;
            estudiantes[z].cedula=cedutemp;
        }
        cout<< "Nombre:   ";
        cin>>estudiantes[z].nombre;
        cout<< "Telefono: ";
        cin>>estudiantes[z].telefono;
        cout<< "Direccion:";
        cin>>estudiantes[z].direccion;
        cout<< "Ciudad:   ";
        cin>>estudiantes[z].ciudad;
        cout<< "Cuantas Asignaturas reprobadas? :";
        cin>>estudiantes[z].cant_asig_perdidas;
        for(int a=0; a<estudiantes[z].cant_asig_perdidas  ; a++)
        {
            cout<<"Nombre ASIGNATURA "<<a+1<<": ";
            cin>>estudiantes[z].asig_perdidas[a];
        }
        cout<< "Dia de Nacimiento: ";
        cin>>estudiantes[z].diacumple;
        cout<< "Mes de Nacimiento: ";
        cin>>estudiantes[z].mescumple;
        cout<< "Anio de Nacimiento: ";
        cin>>estudiantes[z].aniocumple;
        cout<< "Sexo: ";
        cin>>estudiantes[z].sexo;
        cout<< "Semestres Cursados: ";
        cin>>estudiantes[z].semestres_vistos;
        for(int j=0; j<estudiantes[z].semestres_vistos; j++)
        {
            cout<<"SEMESTRE #"<<j+1<<endl;
            cout<< "Situación académica (p= prueba)(n=normal) :";
            cin>>estudiantes[z].semestres[j].situacion_academica;
            cout<< "Promedio semestre : ";
            cin>>estudiantes[z].semestres[j].promedio;
            cout<< "Creditos Semestre : ";
            cin>>estudiantes[z].semestres[j].creditos;
        }
    }

}

/**
ESTUDIANTES CON MÁS VECES EN PRUEBA (PARA OPCIÓN 3)
    Param [estudiante] estudiantes[]: Arreglo que contiene la información de los estudiantes.
    Param [int] cante: Cantidad actual de estudiantes en el sistema.
    Retorna: Código (índice en el arreglo) del estudiante con más semestres en prueba académica.
    Post: Se ha retornado el índice del estudiante con más semestres en prueba académica.
*/
int max_pruebas(estudiante estudiantes[], int cante)
{
    int mayor=-1,veces,mejor;
    for(int z=0; z<cante; z++)
    {
        veces=0;
        for(int j=0; j<estudiantes[z].semestres_vistos; j++)
        {
            if(estudiantes[z].semestres[j].situacion_academica=='p')
            {
                veces++;//Acumula las veces en prueba que ha estado cada estudiante.
            }
        }
        if(veces > mayor)//Define, cada vez, cual es el mayor.
        {
            mayor=veces;
            mejor=z;//es el índice que sobrepaso el valor mayor anterior, de mayor cantidad de veces en prueba
        }
    }
    if(mayor==0)
    {
        mejor=-1;
    }
    cout<<mayor;//ESCRIBE LA CANTIDAD DE VECES EN PRUEBA, de ese Estudiante.
    return mejor;//índice.

}

/**
    VERIFICACIÓN ESTUDIANTE PRUEBA (OPCIÓN 4)
    Param [estudiante] mujer: Estudiante femenino del que se verificará si ha estado en prueba.

    Post: Si el estudiante ha estado en prueba, se imprimieron su nombre, cantidad de asignaturas perdidas y los nombres de las asignaturas.
*/
void femeni_prueba(estudiante mujer)
{
    int veces=0;
    for(int j=0; j<mujer.semestres_vistos; j++)
    {
        if(mujer.semestres[j].situacion_academica=='p')
        {
            veces++;
        }
    }
    if(veces>0)
    {
        cout<< "Nombre                : "<<mujer.nombre<<endl;
        cout<< "Asignaturas reprobadas: "<<mujer.cant_asig_perdidas<<endl;
        for(int a=0; a<mujer.cant_asig_perdidas  ; a++)
        {
            cout<<"=>        ASIGNATURA "<<a+1<<": "<<mujer.asig_perdidas[a]<<endl;
        }
    }
}

/**
PESENTAR DATOS DE UN ESTUDIANTE
    Param [estudiante] estudiantes: Estudiante del que se van a presentar datos.

    Post: Se imprimieron los datos completos del estudiante.
*/
void prese_datos(estudiante estudiantes)
{
    cout<< "Cedula                : "<<estudiantes.cedula<<endl;
    cout<< "Nombre                : "<<estudiantes.nombre<<endl;
    cout<< "Telefono              : "<<estudiantes.telefono<<endl;
    cout<< "Direccion             : "<<estudiantes.direccion<<endl;
    cout<< "Ciudad                : "<<estudiantes.ciudad<<endl;
    cout<< "Asignaturas reprobadas: "<<estudiantes.cant_asig_perdidas<<endl;
    for(int a=0; a<estudiantes.cant_asig_perdidas  ; a++)
    {
        cout<<"=>        ASIGNATURA "<<a+1<<": "<<estudiantes.asig_perdidas[a]<<endl;
    }
    cout<<"Fecha de Nacimiento   : ";
    cout<< estudiantes.diacumple<<"/";
    cout<< estudiantes.mescumple<<"/";
    cout<< estudiantes.aniocumple<<endl;
    cout<< "Sexo                  : "<<estudiantes.sexo<<endl;
    cout<< "Semestres Cursados    : "<<estudiantes.semestres_vistos<<endl;
    cout<<"INFO.CARPETA SEMESTRAL: "<<endl;
    if(estudiantes.semestres_vistos==0)
    {
        cout<<"                      ES PRIMIPARO."<<endl;
    }
    for(int j=0; j<estudiantes.semestres_vistos; j++)
    {
        cout<<"=>      SEMESTRE #"<<j+1<<endl;
        cout<< "Situación académica (p= prueba)(n=normal) :"<<estudiantes.semestres[j].situacion_academica<<endl;
        cout<< "Promedio semestre                         : "<<estudiantes.semestres[j].promedio<<endl;
        cout<< "Creditos Semestre                         : "<<estudiantes.semestres[j].creditos<<endl;
    }
}

/**
ELIMINAR A UN ESTUDIANTE POR ÍNDICE
    Param [estudiante] estudiantes[]: Arreglo que contiene la información de los estudiantes.
    Param [int] indice_buscado: Índice del estudiante a ser eliminado.
    Param [int] cante: Cantidad actual de estudiantes en el sistema.

    Post: Se ha eliminado la información del estudiante con el índica indicado en el parámetro, y se han "corrido" hacia atrás a los estudiantes de ese punto en adelante en el arreglo.
*/
void borrar(estudiante estudiantes[], int indice_buscado, int cante)
{
    for(int i=indice_buscado; i<cante-1; i++)
    {
        estudiantes[i]=estudiantes[i+1];
    }
}


/**
IMPRIMIR ESTUDIANTES A SER EXCLUIDOS
    Param [estudiante] estudiantes[]: Arreglo que contiene la información de los estudiantes.
    Param [int] cante: Cantidad actual de estudiantes en el sistema.

    Post: Se imprimió los nombres y PPA de los estudiantes que llevan 10 o más semestres en la universidad (candidatos a grado). Si no hay candidatos aún se imprimió: "NO HAY CANDIDATOS TODAVIA".
*/
void verifi_exclu(estudiante estudiantes[], int cante)
{
    int veces,exc=0;
    for(int i=0; i<cante; i++)
    {
        veces=0;
        for(int j=estudiantes[i].semestres_vistos; j>=estudiantes[i].semestres_vistos-2; j--)
        {
            if(estudiantes[i].semestres[j].situacion_academica=='p')
            {
                veces++;//Debe sumar dos, para que sean los últimos dos semestres en prueba.
            }
        }
        if((veces==2) && (ppa(estudiantes[i])< 3.4))//imprime, si se cumplen losdos semestres en prueba y su PPA sea menor a 3.4.
        {
            cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
            cout<<"EXCLUIDO: ";
            cout<<"ESTUDIANTE #"<<i+1<<endl;
            prese_datos(estudiantes[i]);//se llama a la funciín de presentar datos DE ESE ESTUDIANTE.
            cout<<"SU PROMEDIO PONDERADO ACUMULADO ES: "<<ppa(estudiantes[i])<<endl;
            cout<<"°°°°°°°°                            °°°°°°°"<<endl;
            exc++;
        }
        else
        {
            cout<<endl;
            cout<<"Estudiante "<<i+1<<" se salva"<<endl;
            cout<<endl;
        }
    }
    if(exc==0)
    {
        cout<<"<AFORTUNADAMENTE NO EXISTEN ESTUDIANTES A SER EXCLUIDOS>"<<endl;
    }
}

/**
PROMEDIO PONDERADO ACUMULADO (PPA)
    Param[estudiante] est: Estudiante de cuyas notas se calculará el PPA a retornar.

    Retorna[float]: Promedio ponderado acumulado del estudiante.

    Post: Se ha calculado y retornado el PPA del estudiante pasado por parámetro.
*/
float ppa(estudiante est)
{
    float sum_cred = 0, prom = 0, sum_pond = 0;
    for(int i=0; i<est.semestres_vistos; i++)
    {
        sum_pond += (est.semestres[i].promedio*est.semestres[i].creditos);//Se acumula el producto entre promedio del semestre y creditos vistos.
        sum_cred += est.semestres[i].creditos;//se acumulan los creditos vistos.

    }
    if(sum_cred==0)
    {
        return 0;//Si no suman creditos, para que no haya errores matemáticos, devuelve 0.
    }
    prom = sum_pond / sum_cred;//Saca el promedio ponderado Acumulado, dividiendo ambos acumuladores respectivamente.
    return prom;
}

/**
IMPRIMIR LISTA DE CANDIDATOS A GRADO
    Param [estudiante] estudiantes[]: Arreglo que contiene la información de los estudiantes.
    Param [int] cante: Cantidad actual de estudiantes en el sistema.

    Post: Se imprimió los nombres y PPA de los estudiantes que llevan 10 o más semestres en la universidad (candidatos a grado). Si no hay candidatos aún se imprimió: "NO HAY CANDIDATOS TODAVIA".
*/
void grado(estudiante estudiantes[], int cante)
{
    int cont=0;
    cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
    cout<<"°°°°CANDIDATOS A GRADO°°°°°°°"<<endl;
    for(int i=0; i<cante ; i++)
    {
        if(estudiantes[i].semestres_vistos>=10)
        {
            cout<<"ESTUDIANTE #"<<i+1<<endl;
            cout<<"NOMBRE                      : "<<estudiantes[i].nombre<<endl;
            cout<<"Promedio Ponderado Acumulado: "<<ppa(estudiantes[i])<<endl;
            cout<<endl;
            cont++;
        }
    }
    if(cont==0)
    {
        cout<<"NO HAY CANDIDATOS TODAVIA"<<endl;
    }
}

/**
BUSCAR ESTUDIANTE POR CÉDULA
    Param [long int] cedula: Cédula del estudiante a ser buscado.
    Param [int] cant_est: Cantidad actual de estudiantes en el sistema.
    Param [estudiante] estudiantes[]: Arreglo que contiene la información de los estudiantes.

    Retorna [int]: Código (índice en el arreglo) del estudiante con la cédula definida, -1 si el estudiante no fue encontrado.

    Post: Se ha retornado el código (índice en el arreglo) del estudiante con la cédula definida, -1 si el estudiante no fue encontrado.
*/
int buscar_est(long int cedula, int cant_est, estudiante estudiantes[])
{
    int r = -1;
    bool buscar = true;

    for(int i=0; (i<cant_est)&& buscar; i++)
    {
        if(cedula == estudiantes[i].cedula)//compara con todas las cedulas del arreglo, si hay una similar, deja de buscar.
        {
            buscar = false;
            r = i;
        }
    }
    return r;//Indice.
}

/**
VERIFICACIÓN DE SEXO DE ESTUDIANTES
    Param [estudiante] estudiantes[]: Arreglo que contiene la información de los estudiantes.
    Param [int] cante: Cantidad actual de estudiantes en el sistema.
    Param [int] impresiones[]: Arreglo en el que se almacenarán los códigos de los estudiantes del sexo definido.
    Param [char] sexo: 'm' para estudiantes de sexo masculino y 'f' para estudiantes de sexo femenino.

    Retorna [int]:cantidad de estudiantes del sexo definido (cantidad de estudiantes a imprimir).

    Post: Se han los códigos de los estudiantes del sexo definido en el arreglo impresiones[] y se ha retornado el tamaño del mismo.
*/
int verifi_sexo (estudiante estudiantes[], int cante, int impresiones[],char sexo)
{
    int a=0;
    for(int i=0; i<cante; i++)
    {
        if(estudiantes[i].sexo==sexo)//verifica si el sexo de ese estudiante corresponde con el sexo requerido.
        {
            impresiones[a]=i;
            a++;
        }
    }
    return a;
}
