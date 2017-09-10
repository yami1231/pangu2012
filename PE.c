#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
    DWORD FileSize,PeHeaderAddress,Signature,exports,Characteristics_export;
    FILE *err;
    FILE *fp=NULL;
    //fp=fopen("C:\\Users\\yami\\Desktop\\roboonline\\src_c++\\getbtc.exe","rb");
    //fp=fopen("C:\\Program Files\\UltraISO\\UltraISO.exe","rb");
    //fp=fopen("C:\\Program Files\\Opera\\launcher.exe","rb");
    //fp=fopen("C:\\dnschef-0.3\\dnschef.exe","rb");
    //fp=fopen("I:\\programas\\ChromeStandaloneSetup.exe","rb");
    //fp=fopen("msg.exe","rb");
    //fp=fopen("v1.exe","rb");
    fp=fopen("msg2.exe","rb");
    IMAGE_DOS_HEADER DosHeader={0};
    PIMAGE_DOS_HEADER dosHeader={0};
    PIMAGE_NT_HEADERS PeHeader={0};
    IMAGE_FILE_HEADER FileHeader={0};
    IMAGE_OPTIONAL_HEADER OpHeader={0};
    IMAGE_SECTION_HEADER SectionHeader={0};
    IMAGE_EXPORT_DIRECTORY Export={0};
    fseek(fp,0,SEEK_END);//
    FileSize=ftell(fp);//
    if(FileSize<sizeof(IMAGE_DOS_HEADER)+sizeof(IMAGE_NT_HEADERS)){
        printf("NOT PE file ");
    }
    else
        printf("Reading PE FILE\n----------------------\n\n");
        printf("Reading DOS header \n----------------------\n");
        printf("size of DosHeder:\t\t %d \n",sizeof DosHeader);
        fseek(fp,0,SEEK_SET);//
        fread(&DosHeader,sizeof DosHeader,1,fp);
        if (DosHeader.e_magic != 0x5a4d ){
            printf("NOT PE file");
        }
        printf("Magic number:\t\t\t MZ(%#x) \n",DosHeader.e_magic);//e_magic(MZ)
        printf("Adress of PE header(e_lfanew):\t %#xh \n", DosHeader.e_lfanew);//offset donde se encuentra el PE HEADER
        printf("-------------------------------------------------\n\n");
        PeHeaderAddress=DosHeader.e_lfanew;
        if(FileSize<=PeHeaderAddress+sizeof(IMAGE_NT_HEADERS)){
            printf("NOT PE file");
        }
        else
            printf("Reading PE Header \n----------------------\n");
            printf("\nPE File signature \n----------------------\n");
            fseek(fp,PeHeaderAddress,SEEK_SET);
            fread(&Signature,sizeof(DWORD),1,fp);
            printf("Signature:\t\t %#x \n",Signature);
            fread(&FileHeader,sizeof FileHeader,1,fp);
            printf("number of section:\t %d \n",FileHeader.NumberOfSections);
            printf("Size of optional Header: %d \n",FileHeader.SizeOfOptionalHeader);
            printf("Characteristics:\t\t %x",FileHeader.Characteristics);
            printf("\nPE Optional Header \n----------------------\n");
            fread(&OpHeader,1,sizeof OpHeader,fp);
            printf("Address of Entry Point:\t\t %#x\n",OpHeader.AddressOfEntryPoint);
            printf("ImageBase:\t\t\t %#x \n",OpHeader.ImageBase);
            printf("BaseofCode:\t\t\t %#x \n",OpHeader.BaseOfCode);
            printf("FileAlignment:\t\t\t %#x \n",OpHeader.FileAlignment);
            printf("SizeOfImage:\t\t\t %#x \n",OpHeader.SizeOfImage);
            printf("CheckSum:\t\t\t %#x \n",OpHeader.CheckSum);
            printf("-------------------------------------------------\n\n");
            fread(&SectionHeader,PeHeaderAddress+sizeof(IMAGE_NT_HEADERS),sizeof SectionHeader,fp);
            int secCount=1;
            while(secCount<=FileHeader.NumberOfSections)
            {
                printf("section header (%d or %d) \n",secCount,FileHeader.NumberOfSections);
                printf("---------------------\n");
                printf("Section Header name \t\t:%s\n",SectionHeader.Name);
                printf("Virtual Size  \t\t\t:%#x\n",SectionHeader.Misc.VirtualSize);
                printf("Virtual Address \t\t:%#x\n",SectionHeader.VirtualAddress);
                printf("Size of raw data  \t\t:%#x\n",SectionHeader.SizeOfRawData);
                printf("Pointer to Raw Data \t\t:%#x\n\n",SectionHeader.PointerToRawData);
                fseek(fp,PeHeaderAddress+sizeof(IMAGE_NT_HEADERS)+secCount*sizeof(IMAGE_SECTION_HEADER),SEEK_SET);
                fread(&SectionHeader,sizeof SectionHeader,1,fp);
                secCount++;
            }
            printf("Reading ExPort \n----------------------\n");
            exports=SectionHeader.Characteristics;
            fseek(fp,exports,SEEK_SET);
            fread(&Characteristics_export,sizeof(DWORD),1,fp);
            printf("characteristics \t: %#x \n",Characteristics_export);
            fread(&Export,sizeof Export,1,fp);
            printf("nName \t\t\t: %x \n",Export.Name);
            printf("nBase \t\t\t: %x \n",Export.Base);
            printf("Number of Function \t: %d \n",Export.NumberOfFunctions);
            printf("Number of Name \t\t: %d \n",Export.NumberOfNames);
            printf("Address of function \t: %x \n",Export.AddressOfFunctions);
            printf("Adress Of Name \t\t: %x \n",Export.AddressOfNames);
            printf("Address of name ordinals: %x \n",Export.AddressOfNameOrdinals);
            fclose(fp);
            _getch();
}
