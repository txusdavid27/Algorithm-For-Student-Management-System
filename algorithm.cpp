//Project: Final delivery, information management of the U.
///By JESUS ​​TRASLAVIÑA.
//PUJ, 05/25/2020.
#include <iostream>
#include <stdlib.h>
#define maxe 100
#define maxm 20
using namespace std;


///STRUCTURES
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

///PROTOTYPES OF FUNCTIONS

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
int infe_tres(estudiante estudiantes[],int  cante, int impresiones[]);


///PRINCIPAL FUNCTION
int main ()
{
    int cante=0,op,opcero=0,indice_buscado;//cante, is the amount of student; op, is the option; opcero, is the sentinel that checks the use of option zero; search_index is the student being searched for.
    long int cedutemp;//is the temporary card to add or delete.
    char seguro;//delete student sentinel.
    estudiante estudiantes[maxe]; //Array of type student structure that saves the information of each one.
    int impresiones[maxe];// this array stores the indices of some functions.
    bool fin=false;//sentinel to end the program
    int cuantos_imprimir;//ARRANGEMENT SIZE PRINTS
    int indice_mas_pruebas;//the position in the arrangement, the student has been more times in test.
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
        //system ("cls");//Clear screen.
        if((opcero==0 && op!=0 && op!=9)|| (op!=0 && op!=9 && op!=7 && cante==0))
        {
            //Conditional to Restrict use of other options before choosing zero, or when there are no students.
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
                    lectura(estudiantes,cante, cedutemp);//called to the reading function.
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
                cuantos_imprimir= verifi_sexo(estudiantes,cante, impresiones, 'm');//the array is filled with only male studentsand the quantity is obtained
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
                cuantos_imprimir= verifi_sexo(estudiantes,cante, impresiones, 'f');//the array is filled with only female students and the quantity is obtained.
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
                //DELETE ONE.
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
                //Wait for the restart of the cycle.
            }
        }
        //system ("cls");//clear screen.
    }
    while(!fin);
}


///FUNCTIONS
/**
FEATURE OF option 5 new.

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
READING FUNCTION
    Param [student] students[]: Array that contains the information of the students.
    Param [int] cante: Current number of students in the system.
    Param [long int] cedutemp: Number that saves the new cedula and defines if it is an initial entry or a single student.
    Post: Student data successfully registered
*/
void lectura (estudiante estudiantes[maxe], int cante, long int cedutemp)
{
    //Massive data entry in the pre-established order.
    int z,repetir;
    repetir=cante;
    if(cedutemp!=-1)
    {
        repetir=1;
    }
    for(int i=0; i<repetir; i++)//Depends on the option that has been chosen, it does it once or massively.
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
STUDENTS WITH MORE TIMES ON TEST (FOR OPTION 3)
    Param [student] students[]: Array that contains the information of the students.
    Param [int] cante: Current number of students in the system.
    Returns: Code (index in the array) of the student with the most semesters on academic probation.
    Post: The index of the student with more semesters in academic test has been returned.
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
                veces++;// Accumulates the times in test that each student has been.
            }
        }
        if(veces > mayor)//Define, each time, which is the largest.
        {
            mayor=veces;
            mejor=z;// is the index that exceeds the previous largest value, of the greatest number of times in the test
        }
    }
    if(mayor==0)
    {
        mejor=-1;
    }
    cout<<mayor;//WRITE THE NUMBER OF TIMES ON TEST, of that Student.
    return mejor;//index.

}

/**
    STUDENT VERIFICATION TEST (OPTION 4)
    Param [student] female: Female student who will be checked if she has been on probation.

    Post: If the student has been on a test, their name, number of subjects missed, and the names of the subjects were printed.
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
PRESENT DATA OF A STUDENT
    Param [student] students: Student for whom data is to be presented.

    Post: The complete data of the student was printed.
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
DELETE A STUDENT BY INDEX
    Param [student] students[]: Array that contains the information of the students.
    Param [int] search_index: Index of the student to be deleted.
    Param [int] cante: Current number of students in the system.

    Post: The information of the student with the index indicated in the parameter has been eliminated, and the students from that point forward in the array have been "moved" backwards.
*/
void borrar(estudiante estudiantes[], int indice_buscado, int cante)
{
    for(int i=indice_buscado; i<cante-1; i++)
    {
        estudiantes[i]=estudiantes[i+1];
    }
}


/**
PRINT STUDENTS TO BE EXCLUDED
    Param [student] students[]: Array that contains the information of the students.
    Param [int] cante: Current number of students in the system.

    Post: The names and PPA of the students who have spent 10 or more semesters at the university (degree candidates) were printed. If there are no candidates yet, "NO CANDIDATES YET" was printed.
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
                veces++;//You must add two, so that they are the last two semesters on probation.
            }
        }
        if((veces==2) && (ppa(estudiantes[i])< 3.4))//prints, if the two semesters have been tested and its PPA is less than 3.4.
        {
            cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
            cout<<"EXCLUIDO: ";
            cout<<"ESTUDIANTE #"<<i+1<<endl;
            prese_datos(estudiantes[i]);//call the function to present data FROM THAT STUDENT.
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
CUMULATIVE WEIGHTED AVERAGE (PPA)
    Param[student] est: Student from whose grades the PPA to be returned will be calculated.

    Returns[float]: Cumulative weighted average of the student.

    Post: The PPA of the student passed by parameter has been calculated and returned.
*/
float ppa(estudiante est)
{
    float sum_cred = 0, prom = 0, sum_pond = 0;
    for(int i=0; i<est.semestres_vistos; i++)
    {
        sum_pond += (est.semestres[i].promedio*est.semestres[i].creditos);//The product is accumulated between the average of the semester and credits seen.
        sum_cred += est.semestres[i].creditos;// the seen credits are accumulated.

    }
    if(sum_cred==0)
    {
        return 0;//If they do not add credits, so that there are no mathematical errors, it returns 0.
    }
    prom = sum_pond / sum_cred;//Get the Cumulative weighted average, dividing both accumulators respectively.
    return prom;
}

/**
PRINT LIST OF CANDIDATES TO DEGREE
    Param [student] students[]: Array that contains the information of the students.
    Param [int] cante: Current number of students in the system.

    Post: The names and PPA of the students who have spent 10 or more semesters at the university (degree candidates) were printed. If there are no candidates yet, "NO CANDIDATES YET" was printed.
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
SEARCH STUDENT BY ID
    Param [long int] cedula: Student ID to be searched.
    Param [int] cant_est: Current number of students in the system.
    Param [student] students[]: Array that contains the information of the students.

    Returns [int]: Code (index in the array) of the student with the defined identification card, -1 if the student was not found.

    Post: The code (index in the array) of the student with the defined identity card has been returned, -1 if the student was not found.
*/
int buscar_est(long int cedula, int cant_est, estudiante estudiantes[])
{
    int r = -1;
    bool buscar = true;

    for(int i=0; (i<cant_est)&& buscar; i++)
    {
        if(cedula == estudiantes[i].cedula)//compare with all the cells of the array, if there is a similar one, stop searching.
        {
            buscar = false;
            r = i;
        }
    }
    return r;//Index.
}

/**
STUDENT SEX VERIFICATION
    Param [student] students[]: Array that contains the information of the students.
    Param [int] cante: Current number of students in the system.
    Param [int] impressions[]: Array in which the codes of the students of the defined gender will be stored.
    Param [char] gender: 'm' for male students and 'f' for female students.

    Returns [int]: number of students of the defined sex (number of students to print).

    Post: The codes of the students of the gender defined in the array impressions[] have been found and its size has been returned.
*/
int verifi_sexo (estudiante estudiantes[], int cante, int impresiones[],char sexo)
{
    int a=0;
    for(int i=0; i<cante; i++)
    {
        if(estudiantes[i].sexo==sexo)//check if the gender of that student matches the required gender.
        {
            impresiones[a]=i;
            a++;
        }
    }
    return a;
}
