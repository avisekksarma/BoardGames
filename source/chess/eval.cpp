#include "../../include/chess/boardstate.h"
#include "../../include/chess/eval.h"



/* values from Rofchade: http://www.talkchess.com/forum3/viewtopic.php?f=2&t=68311&start=19 */



const int gamephasepiecevalue[6] = {0,1,1,2,4,0};

int boardstate::eval() {

    int mgw{0};
    int mgb{0};
    int egw{0};
    int egb{0};

    int gamephase{0};

    int pc;

    for(int i{0};i<8;i++){
        for (int j{0};j<8;j++){
                pc=piece(board[i][j]);
                if(pc != empty){
                    if(pc>empty){
                        mgw+=mg_table_white[pc-7][i][j];
                        egw+=eg_table_white[pc-7][i][j];
                        gamephase+=gamephasepiecevalue[pc-7];
                    }
                    else{
                        mgb+=mg_table_black[pc][i][j];
                        egb+=eg_table_black[pc][i][j];
                        gamephase+=gamephasepiecevalue[pc];
                    }

                }
        }
    }

    int mgScore = mgw - mgb;
    int egScore = egw - egb;

    int mgPhase = gamephase;
    if (mgPhase > 24) mgPhase = 24; // in case of early promotion
    int egPhase = 24 - mgPhase;
    return (mgScore * mgPhase + egScore * egPhase) / 24;

};

extern const int mg_table_white[6][8][8] =    //in order of p n b r q k
{
{

{82,    82,     82,     82,     82,     82,     82,     82      },

{71,    116,    208,    150,    177,    143,    216,    180     },

{62,    107,    138,    147,    113,    108,    89,     76      },

{59,    99,     94,     105,    103,    88,     95,     68      },

{57,    92,     88,     99,     94,     77,     80,     55      },

{70,    115,    85,     85,     72,     78,     78,     56      },

{60,    120,    106,    67,     59,     62,     81,     47      },

{82,    82,     82,     82,     82,     82,     82,     82      }

},
{

{230,   322,    240,    398,    288,    303,    248,    170     },

{320,   344,    399,    360,    373,    409,    296,    264     },

{381,   410,    466,    421,    402,    374,    397,    290     },

{359,   355,    406,    374,    390,    356,    354,    328     },

{329,   358,    356,    365,    350,    353,    341,    324     },

{321,   362,    354,    356,    347,    349,    328,    314     },

{318,   323,    355,    336,    334,    325,    284,    308     },

{314,   318,    309,    320,    304,    279,    316,    232     }

},
{

{357,   372,    323,    340,    328,    283,    369,    336     },

{318,   383,    424,    395,    352,    347,    381,    339     },

{363,   402,    415,    400,    405,    408,    402,    349     },

{363,   372,    402,    402,    415,    384,    370,    361     },

{369,   375,    377,    399,    391,    378,    378,    359     },

{375,   383,    392,    379,    380,    380,    380,    365     },

{366,   398,    386,    372,    365,    381,    380,    369     },

{344,   326,    353,    352,    344,    351,    362,    332     }

},
{

{520,   508,    486,    540,    528,    509,    509,    509     },

{521,   503,    544,    557,    539,    535,    509,    504     },

{493,   538,    522,    494,    513,    503,    496,    472     },

{457,   469,    512,    501,    503,    484,    466,    453     },

{454,   483,    470,    486,    476,    465,    451,    441     },

{444,   472,    477,    480,    460,    461,    452,    432     },

{406,   471,    488,    476,    468,    457,    461,    433     },

{451,   440,    484,    493,    494,    478,    464,    458     }

},
{

{1070,  1068,   1069,   1084,   1037,   1054,   1025,   997     },

{1079,  1053,   1082,   1009,   1026,   1020,   986,    1001    },

{1082,  1072,   1081,   1054,   1033,   1032,   1008,   1012    },

{1026,  1023,   1042,   1024,   1009,   1009,   998,    998     },

{1022,  1028,   1021,   1023,   1015,   1016,   999,    1016    },

{1030,  1039,   1027,   1020,   1023,   1014,   1027,   1011    },

{1026,  1022,   1040,   1033,   1027,   1036,   1017,   990     },

{975,   994,    1000,   1010,   1035,   1016,   1007,   1024    }

},
{

{20013, 20002,  19966,  19944,  19985,  20016,  20023,  19935   },

{19971, 19962,  19996,  19992,  19993,  19980,  19999,  20029   },

{19978, 20022,  20006,  19980,  19984,  20002,  20024,  19991   },

{19964, 19986,  19975,  19970,  19973,  19988,  19980,  19983   },

{19949, 19967,  19956,  19954,  19961,  19973,  19999,  19951   },

{19973, 19985,  19970,  19956,  19954,  19978,  19986,  19986   },

{20008, 20009,  19984,  19957,  19936,  19992,  20007,  20001   },

{20014, 20024,  19972,  20008,  19946,  20012,  20036,  19985   }

}
};


extern const int mg_table_black[6][8][8] =
{
{

{ 82    ,82     ,82     ,82     ,82     ,82     ,82     ,82 },
{ 60    ,120    ,106    ,67     ,59     ,62     ,81     ,47 },
{ 70    ,115    ,85     ,85     ,72     ,78     ,78     ,56 },
{ 57    ,92     ,88     ,99     ,94     ,77     ,80     ,55 },
{ 59    ,99     ,94     ,105    ,103    ,88     ,95     ,68 },
{ 62    ,107    ,138    ,147    ,113    ,108    ,89     ,76 },
{ 71    ,116    ,208    ,150    ,177    ,143    ,216    ,180 },
{ 82    ,82     ,82     ,82     ,82     ,82     ,82     ,82 },
},
{

{ 314   ,318    ,309    ,320    ,304    ,279    ,316    ,232 },
{ 318   ,323    ,355    ,336    ,334    ,325    ,284    ,308 },
{ 321   ,362    ,354    ,356    ,347    ,349    ,328    ,314 },
{ 329   ,358    ,356    ,365    ,350    ,353    ,341    ,324 },
{ 359   ,355    ,406    ,374    ,390    ,356    ,354    ,328 },
{ 381   ,410    ,466    ,421    ,402    ,374    ,397    ,290 },
{ 320   ,344    ,399    ,360    ,373    ,409    ,296    ,264 },
{ 230   ,322    ,240    ,398    ,288    ,303    ,248    ,170 },
},
{

{ 344   ,326    ,353    ,352    ,344    ,351    ,362    ,332 },
{ 366   ,398    ,386    ,372    ,365    ,381    ,380    ,369 },
{ 375   ,383    ,392    ,379    ,380    ,380    ,380    ,365 },
{ 369   ,375    ,377    ,399    ,391    ,378    ,378    ,359 },
{ 363   ,372    ,402    ,402    ,415    ,384    ,370    ,361 },
{ 363   ,402    ,415    ,400    ,405    ,408    ,402    ,349 },
{ 318   ,383    ,424    ,395    ,352    ,347    ,381    ,339 },
{ 357   ,372    ,323    ,340    ,328    ,283    ,369    ,336 },
},
{

{ 451   ,440    ,484    ,493    ,494    ,478    ,464    ,458 },
{ 406   ,471    ,488    ,476    ,468    ,457    ,461    ,433 },
{ 444   ,472    ,477    ,480    ,460    ,461    ,452    ,432 },
{ 454   ,483    ,470    ,486    ,476    ,465    ,451    ,441 },
{ 457   ,469    ,512    ,501    ,503    ,484    ,466    ,453 },
{ 493   ,538    ,522    ,494    ,513    ,503    ,496    ,472 },
{ 521   ,503    ,544    ,557    ,539    ,535    ,509    ,504 },
{ 520   ,508    ,486    ,540    ,528    ,509    ,509    ,509 },
},
{

{ 975   ,994    ,1000   ,1010   ,1035   ,1016   ,1007   ,1024 },
{ 1026  ,1022   ,1040   ,1033   ,1027   ,1036   ,1017   ,990 },
{ 1030  ,1039   ,1027   ,1020   ,1023   ,1014   ,1027   ,1011 },
{ 1022  ,1028   ,1021   ,1023   ,1015   ,1016   ,999    ,1016 },
{ 1026  ,1023   ,1042   ,1024   ,1009   ,1009   ,998    ,998 },
{ 1082  ,1072   ,1081   ,1054   ,1033   ,1032   ,1008   ,1012 },
{ 1079  ,1053   ,1082   ,1009   ,1026   ,1020   ,986    ,1001 },
{ 1070  ,1068   ,1069   ,1084   ,1037   ,1054   ,1025   ,997 },
},
{

{ 20014 ,20024  ,19972  ,20008  ,19946  ,20012  ,20036  ,19985 },
{ 20008 ,20009  ,19984  ,19957  ,19936  ,19992  ,20007  ,20001 },
{ 19973 ,19985  ,19970  ,19956  ,19954  ,19978  ,19986  ,19986 },
{ 19949 ,19967  ,19956  ,19954  ,19961  ,19973  ,19999  ,19951 },
{ 19964 ,19986  ,19975  ,19970  ,19973  ,19988  ,19980  ,19983 },
{ 19978 ,20022  ,20006  ,19980  ,19984  ,20002  ,20024  ,19991 },
{ 19971 ,19962  ,19996  ,19992  ,19993  ,19980  ,19999  ,20029 },
{ 20013 ,20002  ,19966  ,19944  ,19985  ,20016  ,20023  ,19935 },
}

};

extern const int eg_table_black[6][8][8] =
{
{

{94,    94,     94,     94,     94,     94,     94,     94      },

{281,   259,    226,    241,    228,    252,    267,    272     },

{178,   176,    147,    150,    161,    179,    194,    188     },

{111,   111,    98,     92,     99,     107,    118,    126     },

{93,    97,     86,     87,     87,     91,     103,    107     },

{86,    93,     89,     94,     95,     88,     101,    98      },

{87,    96,     94,     107,    104,    102,    102,    107     },

{94,    94,     94,     94,     94,     94,     94,     94      }

},
{

{182,   218,    254,    250,    253,    268,    243,    223     },

{229,   257,    256,    272,    279,    256,    273,    256     },

{240,   262,    272,    280,    290,    291,    261,    257     },

{263,   289,    292,    303,    303,    303,    284,    264     },

{263,   285,    298,    297,    306,    297,    275,    263     },

{259,   261,    278,    291,    296,    280,    278,    258     },

{237,   258,    261,    279,    276,    271,    261,    239     },

{217,   231,    263,    259,    266,    258,    230,    252     }

},
{

{273,   280,    288,    290,    289,    286,    276,    283     },

{283,   293,    284,    294,    285,    304,    293,    289     },

{301,   297,    303,    295,    296,    297,    289,    299     },

{299,   300,    307,    311,    306,    309,    306,    294     },

{288,   294,    307,    304,    316,    310,    300,    291     },

{282,   290,    300,    310,    307,    305,    294,    285     },

{270,   282,    288,    301,    296,    290,    279,    283     },

{280,   292,    281,    288,    292,    274,    288,    274     }

},
{

{517,   520,    524,    524,    527,    530,    522,    525     },

{515,   520,    515,    509,    523,    525,    525,    523     },

{509,   507,    509,    516,    517,    519,    519,    519     },

{514,   511,    513,    514,    513,    525,    515,    516     },

{501,   504,    506,    507,    516,    520,    517,    515     },

{496,   504,    500,    505,    511,    507,    512,    508     },

{509,   501,    503,    503,    514,    512,    506,    506     },

{492,   516,    499,    507,    511,    515,    514,    503     }

},
{

{956,   946,    955,    963,    963,    958,    958,    927     },

{936,   966,    961,    994,    977,    968,    956,    919     },

{945,   955,    971,    983,    985,    945,    942,    916     },

{972,   993,    976,    993,    981,    960,    958,    939     },

{959,   975,    970,    967,    983,    955,    964,    918     },

{941,   946,    953,    945,    942,    951,    909,    920     },

{904,   900,    913,    920,    920,    906,    913,    914     },

{895,   916,    904,    931,    893,    914,    908,    903     }

},
{

{19983, 20004,  20015,  19989,  19982,  19982,  19965,  19926   },

{20011, 20023,  20038,  20017,  20017,  20014,  20017,  19988   },

{20013, 20044,  20045,  20020,  20015,  20023,  20017,  20010   },

{20003, 20026,  20033,  20026,  20027,  20024,  20022,  19992   },

{19989, 20009,  20023,  20027,  20024,  20021,  19996,  19982   },

{19991, 20007,  20016,  20023,  20021,  20011,  19997,  19981   },

{19983, 19995,  20004,  20014,  20013,  20004,  19989,  19973   },

{19957, 19976,  19986,  19972,  19989,  19979,  19966,  19947   }

}
};

extern const int eg_table_white[6][8][8] =
{
{

{ 94    ,94     ,94     ,94     ,94     ,94     ,94     ,94 },
{ 87    ,96     ,94     ,107    ,104    ,102    ,102    ,107 },
{ 86    ,93     ,89     ,94     ,95     ,88     ,101    ,98 },
{ 93    ,97     ,86     ,87     ,87     ,91     ,103    ,107 },
{ 111   ,111    ,98     ,92     ,99     ,107    ,118    ,126 },
{ 178   ,176    ,147    ,150    ,161    ,179    ,194    ,188 },
{ 281   ,259    ,226    ,241    ,228    ,252    ,267    ,272 },
{ 94    ,94     ,94     ,94     ,94     ,94     ,94     ,94 },
},
{

{ 217   ,231    ,263    ,259    ,266    ,258    ,230    ,252 },
{ 237   ,258    ,261    ,279    ,276    ,271    ,261    ,239 },
{ 259   ,261    ,278    ,291    ,296    ,280    ,278    ,258 },
{ 263   ,285    ,298    ,297    ,306    ,297    ,275    ,263 },
{ 263   ,289    ,292    ,303    ,303    ,303    ,284    ,264 },
{ 240   ,262    ,272    ,280    ,290    ,291    ,261    ,257 },
{ 229   ,257    ,256    ,272    ,279    ,256    ,273    ,256 },
{ 182   ,218    ,254    ,250    ,253    ,268    ,243    ,223 },
},
{

{ 280   ,292    ,281    ,288    ,292    ,274    ,288    ,274 },
{ 270   ,282    ,288    ,301    ,296    ,290    ,279    ,283 },
{ 282   ,290    ,300    ,310    ,307    ,305    ,294    ,285 },
{ 288   ,294    ,307    ,304    ,316    ,310    ,300    ,291 },
{ 299   ,300    ,307    ,311    ,306    ,309    ,306    ,294 },
{ 301   ,297    ,303    ,295    ,296    ,297    ,289    ,299 },
{ 283   ,293    ,284    ,294    ,285    ,304    ,293    ,289 },
{ 273   ,280    ,288    ,290    ,289    ,286    ,276    ,283 },
},
{

{ 492   ,516    ,499    ,507    ,511    ,515    ,514    ,503 },
{ 509   ,501    ,503    ,503    ,514    ,512    ,506    ,506 },
{ 496   ,504    ,500    ,505    ,511    ,507    ,512    ,508 },
{ 501   ,504    ,506    ,507    ,516    ,520    ,517    ,515 },
{ 514   ,511    ,513    ,514    ,513    ,525    ,515    ,516 },
{ 509   ,507    ,509    ,516    ,517    ,519    ,519    ,519 },
{ 515   ,520    ,515    ,509    ,523    ,525    ,525    ,523 },
{ 517   ,520    ,524    ,524    ,527    ,530    ,522    ,525 },
},
{

{ 895   ,916    ,904    ,931    ,893    ,914    ,908    ,903 },
{ 904   ,900    ,913    ,920    ,920    ,906    ,913    ,914 },
{ 941   ,946    ,953    ,945    ,942    ,951    ,909    ,920 },
{ 959   ,975    ,970    ,967    ,983    ,955    ,964    ,918 },
{ 972   ,993    ,976    ,993    ,981    ,960    ,958    ,939 },
{ 945   ,955    ,971    ,983    ,985    ,945    ,942    ,916 },
{ 936   ,966    ,961    ,994    ,977    ,968    ,956    ,919 },
{ 956   ,946    ,955    ,963    ,963    ,958    ,958    ,927 },
},
{

{ 19957 ,19976  ,19986  ,19972  ,19989  ,19979  ,19966  ,19947 },
{ 19983 ,19995  ,20004  ,20014  ,20013  ,20004  ,19989  ,19973 },
{ 19991 ,20007  ,20016  ,20023  ,20021  ,20011  ,19997  ,19981 },
{ 19989 ,20009  ,20023  ,20027  ,20024  ,20021  ,19996  ,19982 },
{ 20003 ,20026  ,20033  ,20026  ,20027  ,20024  ,20022  ,19992 },
{ 20013 ,20044  ,20045  ,20020  ,20015  ,20023  ,20017  ,20010 },
{ 20011 ,20023  ,20038  ,20017  ,20017  ,20014  ,20017  ,19988 },
{ 19983 ,20004  ,20015  ,19989  ,19982  ,19982  ,19965  ,19926 },
}
};
