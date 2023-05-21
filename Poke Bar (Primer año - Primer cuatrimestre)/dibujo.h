#pragma once

#include <stdio.h>
#include <windows.h>
#include "const.h"

void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void simpleLineHori(int move,int size,int x,int y) {

    for (int i = 0; i < size; i++) {
        gotoxy(i + x, y);
        printf("%c", HORI);

        if (!move) { // Move 1 (sin movimiento) , Move 0 (con movimiento)
            Sleep(1);
        }
    }
}

void simpleLineVert(int move,int size,int x,int y) {

    for (int i = 0; i < size; i++) {
        gotoxy(x, i+y);
        printf("%c", VERT);

        if (!move) { // Move 1 (sin movimiento) , Move 0 (con movimiento)
            Sleep(1);
        }
    }
}

void dibujoCopa() {
    system("color 0D");
    printf("   {_}                              \n");
    printf("   |(|                                               __                   __                  \n");
    printf("   |=|                               ____   ____    / /__  ___           / /_   ____ _   _____\n");
    printf("  /   \\                             / __ \\ / __ \\  / //_/ / _ \\         / __ \\ / __ `/  / ___/\n");
    printf("  |.--|                            / /_/ // /_/ / / ,<   /  __/        / /_/ // /_/ /  / /    \n");
    printf("  ||  |                           / .___/ \\____/ /_/|_|  \\___/        /_.___/ \\__,_/  /_/     \n");
    printf("  ||  |    .    ' .              /_/                                                          \n");
    printf("  |'--|  '     \\~~~/            \n");
    printf("  '-=-' \\~~~/   \\_/            \n");
    printf("         \\_/     Y              \n");
    printf("          Y     _|_              \n");
    printf("         _|_ ...                                    \n");
    simpleLineHori(0,30,0,12);

}

void squirtle() {
    system("color 0B");
    printf("                  _,........__   \n");
    printf("               ,-'            '`-.   \n");
    printf("             ,'                   `-.   \n");
    printf("           ,'                        \\   \n");
    printf("         ,'                           .   \n");
    printf("         .'\\               ,''.       `   \n");
    printf("        ._.'|             / |  `       \\   \n");
    printf("        |   |            `-.'  ||       `.   \n");
    printf("        |   |            '-._,'||       | \\   \n");
    printf("        .`.,'             `..,'.'       , |`-.   \n");
    printf("        l                       .'`.  _/  |   `.   \n");
    printf("        `-.._'-   ,          _ _'   -'' \\  .     `   \n");
    printf("   `.'''''''''-.`-...,---------','         `. `....__.   \n");
    printf("   .'        `'-..___      __,'\\          \\  \\     \\   \n");
    printf("   \\_ .          |   `'''''''''    `.           . \\     \\   \n");
    printf("     `.          |              `.          |  .     L   \n");
    printf("       `.        |`--...________.'.        j   |     |   \n");
    printf("         `._    .'      |          `.     .|   ,     |   \n");
    printf("            `--,\\       .            `7''' |  ,      |   \n");
    printf("               ` `      `            /     |  |      |    _,-'''''''`-.   \n");
    printf("                \\ `.     .          /      |  '      |  ,'          `.   \n");
    printf("                 \\  v.__  .        '       .   \\    /| /              \\   \n");
    printf("                  \\/    `''''\\''''''''''`.       \\   \\  /.''          |   \n");
    printf("                   `        .        `._ ___,j.  `/ .-       ,---.     |   \n");
    printf("                   ,`-.      \\         .''     `.  |/        j     `    |   \n");
    printf("                  /    `.     \\       /         \\ /         |     /    j   \n");
    printf("                 |       `-.   7-.._ .          |''          '         /   \n");
    printf("                 |          `./_    `|          |            .     _,'   \n");
    printf("                 `.           / `----|          |-............`---'   \n");
    printf("                   \\          \\      |          |   \n");
    printf("                  ,'           )     `.         |   \n");
    printf("                   7____,,..--'      /          |   \n");
    printf("                                     `---.__,--.'   \n");

}

void charizard(int x,int y) {
        system("color 0C");
        gotoxy(x,y);
        y++;
        printf("                 .\"-,.__\n");

        gotoxy(x,y);
        y++;
        printf("                 `.     `.  ,\n");

        gotoxy(x,y);
        y++;
        printf("              .--'  .._,'\"-' `.\n");

        gotoxy(x,y);
        y++;
        printf("             .    .'         `'\n");

        gotoxy(x,y);
        y++;
        printf("             `.   /          ,'\n");

        gotoxy(x,y);
        y++;
        printf("               `  '--.   ,-\"'\n");

        gotoxy(x,y);
        y++;
        printf("                `\"`   |  \\\n");

        gotoxy(x,y);
        y++;
        printf("                   -. \\, |\n");

        gotoxy(x,y);
        y++;
        printf("                    `--Y.'      ___.\n");

        gotoxy(x,y);
        y++;
        printf("                         \\     L._, \\\n");

        gotoxy(x,y);
        y++;
        printf("               _.,        `.   <  <\\                _\n");

        gotoxy(x,y);
        y++;
        printf("             ,' '           `, `.   | \\            ( `\n");

        gotoxy(x,y);
        y++;
        printf("          ../, `.            `  |    .\\`.           \\ \\_\n");

        gotoxy(x,y);
        y++;
        printf("         ,' ,..  .           _.,'    ||\\l            )  '\".\n");

        gotoxy(x,y);
        y++;
        printf("        , ,'   \\           ,'.-.`-._,'  |           .  _._`.\n");

        gotoxy(x,y);
        y++;
        printf("      ,' /      \\ \\        `' ' `--/   | \\          / /   ..\\\n");

        gotoxy(x,y);
        y++;
        printf("    .'  /        \\ .         |\\__ - _ ,'` `        / /     `.`.\n");

        gotoxy(x,y);
        y++;
        printf("    |  '          ..         `-...-\"  |  `-'      / /        . `.\n");

        gotoxy(x,y);
        y++;
        printf("    | /           |L__           |    |          / /          `. `.\n");

        gotoxy(x,y);
        y++;
        printf("   , /            .   .          |    |         / /             ` `\n");

        gotoxy(x,y);
        y++;
        printf("  / /          ,. ,`._ `-_       |    |  _   ,-' /               ` \\\n");

        gotoxy(x,y);
        y++;
        printf(" / .           \\\"`_/. `-_ \\_,.  ,'    +-' `-'  _,        ..,-.    \\`.\n");

        gotoxy(x,y);
        y++;
        printf(".  '         .-f    ,'   `    '.       \\__.---'     _   .'   '     \\ \\\n");

        gotoxy(x,y);
        y++;
        printf("' /          `.'    l     .' /          \\..      ,_|/   `.  ,'`     L`\n");

        gotoxy(x,y);
        y++;
        printf("|'      _.-\"\"` `.    \\ _,'  `            \\ `.___`.'\"`-.  , |   |    | \\\n");

        gotoxy(x,y);
        y++;
        printf("||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .|\n");

        gotoxy(x,y);
        y++;
        printf("||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||\n");

        gotoxy(x,y);
        y++;
        printf("|| '              V      / /           `   | `   ,'   ,' '.    !  `. ||\n");

        gotoxy(x,y);
        y++;
        printf("||/            _,-------7 '              . |  `-'    l         /    `||\n");

        gotoxy(x,y);
        y++;
        printf(". |          ,' .-   ,' ||               | .-.        `.      .'     ||\n");

        gotoxy(x,y);
        y++;
        printf(" `'        ,'    `\".'    |               |    `.        '. -.'       `'\n");

        gotoxy(x,y);
        y++;
        printf("          /      ,'      |               |,'    \\-.._,.'/'\n");

        gotoxy(x,y);
        y++;
        printf("          .     /        .               .       \\    .''\n");

        gotoxy(x,y);
        y++;
        printf("        .`.    |         `.             /         :_,'.'\n");

        gotoxy(x,y);
        y++;
        printf("          \\ `...\\   _     ,'-.        .'         /_.-'\n");

        gotoxy(x,y);
        y++;
        printf("           `-.__ `,  `'   .  _.>----''.  _  __  /\n");

        gotoxy(x,y);
        y++;
        printf("                .'        /\"'          |  \"'   '_\n");

        gotoxy(x,y);
        y++;
        printf("               /_|.-'\\ ,\".             '.'`__'-( \\\n");

        gotoxy(x,y);
        y++;
        printf("                 / ,\"'\"\\,'               `/  `-.|\" \n");

}

void charmander() {

    system("color 0C");
    printf("\n");
    printf("                _.--''`-..   \n");
    printf("              ,'          `.   \n");
    printf("            ,'          __  `.   \n");
    printf("           /|         '' __   \\   \n");
    printf("          , |           / |.   .   \n");
    printf("          |,'          !_.'|   |   \n");
    printf("        ,'             '   |   |   \n");
    printf("       /              |`--'|   |   \n");
    printf("      |                `---'   |   \n");
    printf("       .   ,                   |                       ,''.   \n");
    printf("        ._     '           _'  |                    , ' \\ `   \n");
    printf("    `.. `.`-...___,...---'''    |       __,.        ,`''   L,|   \n");
    printf("    |, `- .`._        _,-,.'   .  __.-'-. /        .   ,    \\   \n");
    printf("  -:..     `. `-..--_.,.<       `''      / `.        `/ |   .   \n");
    printf("    `,         '''''     `.              ,'         |   |  ',,   \n");
    printf("      `.      '            '            /          '    |'. |/   \n");
    printf("         `.   |              \\       _,-'           |       ''   \n");
    printf("           `._'               \\   '''\\                .      |   \n");
    printf("              |                '     \\                `._  ,'   \n");
    printf("              |                 '     \\                 .'|   \n");
    printf("              |                 .      \\                | |   \n");
    printf("              |                 |       L              ,' |   \n");
    printf("              `                 |       |             /   '   \n");
    printf("               \\                |       |           ,'   /   \n");
    printf("             ,' \\               |  _.._ ,-..___,..-'    ,'   \n");
    printf("            /     .             .      `!             ,j'   \n");
    printf("           /       `.          /        .           .'/   \n");
    printf("          .          `.       /         |        _.'.'   \n");
    printf("           `.          7`'---'          |------'''_.'   \n");
    printf("          _,.`,_     _'                ,''-----'''   \n");
    printf("     _,-_    '       `.     .'      ,\\   \n");
    printf("     -'' /`.         _,'     | _  _  _.|   \n");
    printf("      ''''--'---'''''''''        `' '! |! /   \n");

}

void bulbasaur(int x,int y) {

    gotoxy(x,y);
    printf("                `;,;.;,;.;.'       \n");
    gotoxy(x,y+1);
    printf("                 ..:;:;::;:        \n");
    gotoxy(x,y+2);
    printf("           ..--''' '' ' ' '''--.         \n");
    gotoxy(x,y+3);
    printf("         /' .   .'        '.   .`\\       \n");
    gotoxy(x,y+4);
    printf("        | /    /            \\   '.|       \n");
    gotoxy(x,y+5);
    printf("        | |   :             :    :|       \n");
    gotoxy(x,y+6);
    printf("      .'| |   :             :    :|       \n");
    gotoxy(x,y+7);
    printf("    ,: /\\ \\.._\\ __..===..__/_../ /`.       \n");
    gotoxy(x,y+8);
    printf("   |'' |  :.|  `'          `'  |.'  ::.       \n");
    gotoxy(x,y+9);
    printf("   |   |  ''|    :'';          | ,  `''\\       \n");
    gotoxy(x,y+10);
    printf("   |.:  \\/  | /'-.`'   ':'.-'\\ |  \\,   |       \n");
    gotoxy(x,y+11);
    printf("   | '  /  /  | / |...   | \\ |  |  |';'|       \n");
    gotoxy(x,y+12);
    printf("    \\ _ |:.|  |_\\_|`.'   |_/_|  |.:| _ |       \n");
    gotoxy(x,y+13);
    printf("   /,.,.|' \\__       . .      __/ '|.,.,\\       \n");
    gotoxy(x,y+14);
    printf("        | ':`.`----._____.---'.'   |          \n");
    gotoxy(x,y+15);
    printf("         \\   `:''''''-------'''' |   |       \n");
    gotoxy(x,y+16);
    printf("          ',-,-',             .'-=,=,       \n");

}

void pikachuChico(int x,int y) {

    gotoxy(x,y);
    printf("   `;-.          ___,      \n");
    gotoxy(x,y+1);
    printf("     `.`\\_...._/`.-'`      \n");
    gotoxy(x,y+2);
    printf("       \\        /      ,      \n");
    gotoxy(x,y+3);
    printf("       /()   () \\    .' `-._      \n");
    gotoxy(x,y+4);
    printf("      |)  .    ()\\  /   _.'      \n");
    gotoxy(x,y+5);
    printf("      \\  -'-     ,; '. <      \n");
    gotoxy(x,y+6);
    printf("       ;.__     ,;|   > \\      \n");
    gotoxy(x,y+7);
    printf("      / ,    / ,  |.-'.-'      \n");
    gotoxy(x,y+8);
    printf("     (_/    (_/ ,;|.<`      \n");
    gotoxy(x,y+9);
    printf("       \\    ,     ;-`      \n");
    gotoxy(x,y+10);
    printf("        >   \\    /      \n");
    gotoxy(x,y+11);
    printf("       (_,-'`> .'      \n");
    gotoxy(x,y+12);
    printf("            (_,'      \n");
}

void diglett(int x,int y) {

    gotoxy(x,y);
    printf("                     _,.---'\"\"'\"--.._\n");
    y++;
    gotoxy(x,y);
    printf("                   ,\"                `-.\n");
    y++;
    gotoxy(x,y);
    printf("                 ,'                     `.\n");
    y++;
    gotoxy(x,y);
    printf("                /     _       ,.          `.\n");
    y++;
    gotoxy(x,y);
    printf("               /     ||      |\"|            \\\n");
    y++;
    gotoxy(x,y);
    printf("              /      ||      | |             \\\n");
    y++;
    gotoxy(x,y);
    printf("             /       .'      `_'              L\n");
    y++;
    gotoxy(x,y);
    printf("            j                                 |\n");
    y++;
    gotoxy(x,y);
    printf("            |        __,...._                 |\n");
    y++;
    gotoxy(x,y);
    printf("            |      .\"        `.               |\n");
    y++;
    gotoxy(x,y);
    printf("            |      '           )              |\n");
    y++;
    gotoxy(x,y);
    printf("            |       `-...__,.-'               |\n");
    y++;
    gotoxy(x,y);
    y++;
    printf("            |                                 |\n");
    gotoxy(x,y);
    y++;
    printf("         ...|                                 |\n");
    gotoxy(x,y);
    y++;
    printf("      _,'   |                                 |\n");
    gotoxy(x,y);
    y++;
    printf("  _,-'  ___ |                                 |.-----_\n");
    gotoxy(x,y);
    y++;
    printf("-' ,.--`.  \\|                                 |     . \\\n");
    gotoxy(x,y);
    y++;
    printf(",-'     ,  |--,                               |  _,'   `- -----._\n");
    gotoxy(x,y);
    y++;
    printf("      ,' ,'    - ----.            _,..       _|.',               \\\n");
    gotoxy(x,y);
    y++;
    printf(" ,-\"\"' .-             \\  ____   `'  _-'`  ,-'     `.              `-\n");
    gotoxy(x,y);
    y++;
    printf(" .--'\"`   ,--:`.       --    ,\"'. ,'  ,'`,_\n");
    gotoxy(x,y);
    y++;
    printf("        _'__,' |  _,..'_    ,:______,-     --.         _.\n");
    gotoxy(x,y);
    y++;
    printf("        -__..--' '      ` ..`L________,___ _,     _,.-'\n");
    gotoxy(x,y);
    y++;
    printf("                                              '\" ' \n");
}

void gengar(int x,int y) {
    system("color 0D");

    gotoxy(x,y);
    printf("                   |`._         |\\   \n");
    gotoxy(x,y+1);
    printf("                   `   `.  .    | `.    |`.   \n");
    gotoxy(x,y+2);
    printf("                   |.    `.|`-. |   `-..'  \\           _,.-'   \n");
    gotoxy(x,y+3);
    printf("                    '      `-. `.           \\ /|   _,-'   /   \n");
    gotoxy(x,y+4);
    printf("                .--..'        `._`           ` |.-'      /   \n");
    gotoxy(x,y+5);
    printf("                 \\   |                                  /   \n");
    gotoxy(x,y+6);
    printf("              ,..'   '                                 /   \n");
    gotoxy(x,y+7);
    printf("              `.                                      /   \n");
    gotoxy(x,y+8);
    printf("              _`.---                                 /   \n");
    gotoxy(x,y+9);
    printf("          _,-'               `.                 ,-  /\"-._   \n");
    gotoxy(x,y+10);
    printf("        ,\"                   | `.             ,'|   `    `.   \n");
    gotoxy(x,y+11);
    printf("      .'                     |   `.         .'  |    .     `.   \n");
    gotoxy(x,y+12);
    printf("    ,'                       '   ()`.     ,'()  '    |       `.   \n");
    gotoxy(x,y+13);
    printf("  '-.                    |`.  `.....-'    -----' _   |         .   \n");
    gotoxy(x,y+14);
    printf("   / ,   ________..'     '  `-._              _.'/   |         :   \n");
    gotoxy(x,y+15);
    printf("   ` '-\"\" _,.--\"'         \\   | `\"+--......-+' //   j `\"--.. , '   \n");
    gotoxy(x,y+16);
    printf("      `.'\"    .'           `. |   |     |   / //    .       ` '   \n");
    gotoxy(x,y+17);
    printf("        `.   /               `'   |    j   /,.'     '   \n");
    gotoxy(x,y+18);
    printf("          \\ /                  `-.|_   |_.-'       /\\   \n");
    gotoxy(x,y+19);
    printf("           /                        `\"\"          .'  \\   \n");
    gotoxy(x,y+20);
    printf("          j                                           .   \n");
    gotoxy(x,y+21);
    printf("          |                                 _,        |   \n");
    gotoxy(x,y+22);
    printf("          |             ,^._            _.-\"          '   \n");
    gotoxy(x,y+23);
    printf("          |          _.'    `'\"\"`----`\"'   `._       '   \n");
    gotoxy(x,y+24);
    printf("          j__     _,'                         `-.'-.\"`   \n");
    gotoxy(x,y+25);
    printf("            ',-.,'    \n");

}

void machamp(int x,int y) {

    gotoxy(x,y);
    printf("           ,-\"\"\",.--\n");
    gotoxy(x,y+1);
    printf("         ,:-'_.--\"\"\"\\\n");
    gotoxy(x,y+2);
    printf("       ,\"/,-'  _,..--+-.\n");
    gotoxy(x,y+3);
    printf("      .,'/ _.-'         \\\n");
    gotoxy(x,y+4);
    printf("      |||,'_.-.          \\ ____\n");
    gotoxy(x,y+5);
    printf("      |.','U| |         .-'    `-.\n");
    gotoxy(x,y+6);
    printf("    ,\"   |_L:/        ,'          `.\n");
    gotoxy(x,y+7);
    printf("   j                 /              .\n");
    gotoxy(x,y+8);
    printf("   \\_______...-7    j           ___ |\n");
    gotoxy(x,y+9);
    printf("    V V/     _.'    |    _,.---- ,_`\"-.\n");
    gotoxy(x,y+10);
    printf("     ,/_...-\"   __.-|  -\"    `,.   ``.'`.\n");
    gotoxy(x,y+11);
    printf("     `..,......\"    `.  | \\    `+`. `  \\ .\n");
    gotoxy(x,y+12);
    printf("       j /            `./ \\\\    ` .  \\\\ . .\n");
    gotoxy(x,y+13);
    printf("       | |               ` `\\     \\'  \\' \\|\n");
    gotoxy(x,y+14);
    printf("       | |              | `.`+. /         \\\n");
    gotoxy(x,y+15);
    printf("       ` '              |   `\".',  `\\  `|  )\n");
    gotoxy(x,y+16);
    printf("        \\ \\           .'     . ||   || ||.'\n");
    gotoxy(x,y+17);
    printf("         `>`.,.....-----\"'\"\"\"\"\\`|   |' |||\n");
    gotoxy(x,y+18);
    printf("         / .||D.\\\\|.'\\ () (_) (\\|  j|  j/|\n");
    gotoxy(x,y+19);
    printf("        / +,|| ||||_____........|  || / .'\n");
    gotoxy(x,y+20);
    printf("     _,'.\"'_|\\.'/|   _,---._    |  .' ,'\n");
    gotoxy(x,y+21);
    printf("  .\"' .   '\"j-...' ,' ,     `. .'  '  |\n");
    gotoxy(x,y+22);
    printf(" /  ,/  ,'.'`     /  /       ,'       `.\n");
    gotoxy(x,y+23);
    printf(" | /| ,`./   \\   / .'        |         |.\n");
    gotoxy(x,y+24);
    printf(" | ||_|./ .   `.j /          `.        | )\n");
    gotoxy(x,y+25);
    printf(" `-'`.+' /      | `          ,'`.__     Y\n");
    gotoxy(x,y+26);
    printf("     .' /       | `.       .'   /  `\"\"'\"\n");
    gotoxy(x,y+27);
    printf("     |  '      /|    .___.'   ,'\n");
    gotoxy(x,y+28);
    printf("      `.   / -' `.        ,   `.\n");
    gotoxy(x,y+29);
    printf("       |  /       `+.     |     `.\n");
    gotoxy(x,y+30);
    printf("       |  \\        | `    `       \\\n");
    gotoxy(x,y+31);
    printf("        \\  `.      |`.`.   `.      |\n");
    gotoxy(x,y+32);
    printf("         \\   `.    |  `..    `.    '\n");
    gotoxy(x,y+33);
    printf("         /     `-. |    `.     `  /\n");
    gotoxy(x,y+34);
    printf("  ____.-'          `.  _,'      --\\\n");
    gotoxy(x,y+35);
    printf(",' .'_.,_.         __:\"            `.\n");
    gotoxy(x,y+36);
    printf("| ( | (         ,-\" ,-'.\" ,'_.      |\n");
    gotoxy(x,y+37);
    printf("`-`-^--`--------'__|__(  | /   _,--\"\n");
    gotoxy(x,y+38);
    printf("                       \"\"--'..'  \n");
}

void psyduck (int x,int y) {

    gotoxy(x,y);
    printf("                              ,-'   ,\"\",\n");
    gotoxy(x,y+1);
    printf("                             / / ,-'.-'\n");
    gotoxy(x,y+2);
    printf("                   _,..-----+-\".\".-'_,..\n");
    gotoxy(x,y+3);
    printf("           ,...,.\"'             `--.---'\n");
    gotoxy(x,y+4);
    printf("         /,..,'                     `.\n");
    gotoxy(x,y+5);
    printf("       ,'  .'                         `.\n");
    gotoxy(x,y+6);
    printf("      j   /                             `.\n");
    gotoxy(x,y+7);
    printf("      |  /,----._           ,.----.       .\n");
    gotoxy(x,y+8);
    printf("     ,  j    _   \\        .'  .,   `.     |\n");
    gotoxy(x,y+9);
    printf("   ,'   |        |  ____  |         | .\"--+,^.\n");
    gotoxy(x,y+10);
    printf("  /     |`-....-',-'    `._`--....-' _/      |\n");
    gotoxy(x,y+11);
    printf(" /      |     _,'          `--..__  `        '\n");
    gotoxy(x,y+12);
    printf("j       | ,-\"'    `    .'         `. `        `.\n");
    gotoxy(x,y+13);
    printf("|        .\\                        /  |         \\\n");
    gotoxy(x,y+14);
    printf("|         `\\                     ,'   |          \\\n");
    gotoxy(x,y+15);
    printf("|          |                    |   ,-|           `.\n");
    gotoxy(x,y+16);
    printf(".         ,'                    |-\"'  |             \\\n");
    gotoxy(x,y+17);
    printf(" \\       /                      `.    |              .\n");
    gotoxy(x,y+18);
    printf("  ` /  ,'                        |    `              |\n");
    gotoxy(x,y+19);
    printf("   /  /                          |     \\             |\n");
    gotoxy(x,y+20);
    printf("  /  |                           |      \\           /\n");
    gotoxy(x,y+21);
    printf(" /   |                           |       `.       _,\n");
    gotoxy(x,y+22);
    printf(".     .                         .'         `.__,.',.----,\n");
    gotoxy(x,y+23);
    printf("|      `.                     ,'             .-\"\"      /\n");
    gotoxy(x,y+24);
    printf("|        `._               _.'               |        /\n");
    gotoxy(x,y+25);
    printf("|           `---.......,--\"                  |      ,'\n");
    gotoxy(x,y+26);
    printf("'                                            '    ,'\n");
    gotoxy(x,y+27);
    printf(" \\                                          /   ,'\n");
    gotoxy(x,y+28);
    printf("  \\                                        /  ,'\n");
    gotoxy(x,y+29);
    printf("   \\                                      / ,'\n");
    gotoxy(x,y+30);
    printf("    `.                                   ,+'\n");
    gotoxy(x,y+31);
    printf("      >.                               ,'\n");
    gotoxy(x,y+32);
    printf("  _.-'  `-.._                      _,-'-._\n");
    gotoxy(x,y+33);
    printf(",__          `\",-............,.---\"       `.\n");
    gotoxy(x,y+34);
    printf("   \\..---. _,-'            ,'               `.\n");
    gotoxy(x,y+35);
    printf("          \"                '..,--.___,-\"\"\"---' \n");

}

void meowth(int x ,int y) {
        gotoxy(x,y);
        printf("                                        .\n");
        gotoxy(x,y+1);
        printf("                         |              |\n");
        gotoxy(x,y+2);
        printf("                         |             ,|\n");
        gotoxy(x,y+3);
        printf("                ,_       |\\            F'   ,.-\"\"`.\n");
        gotoxy(x,y+4);
        printf("               /  `-._   |`           // ,-\"_,..  |\n");
        gotoxy(x,y+5);
        printf("              |   ___ `. | \\ ,\"\"\"`-. /.-' ,'    ' |_....._\n");
        gotoxy(x,y+6);
        printf("              |  /   `-.`.  L......|j j_.'      ` |       `._\n");
        gotoxy(x,y+7);
        printf("              | |      _,'| |______|' | '-._     ||  ,.-.    `.\n");
        gotoxy(x,y+8);
        printf("               L|    ,'   | |      | j      `-.  || '    `.    \\\n");
        gotoxy(x,y+9);
        printf("___            | \\_,'     | |`\"----| |         `.||       |\\    \\\n");
        gotoxy(x,y+10);
        printf(" \"\"=+...__     `,'   ,.-.   |....._|   _....     Y \\      j_),..+=--\n");
        gotoxy(x,y+11);
        printf("     `\"-._\"._  .   ,' |  `   \\    /  ,' |   \\     \\ j,..-\"_..+-\"  L\n");
        gotoxy(x,y+12);
        printf("          `-._-+. j   !   \\   `--'  .   !    \\  ,.-\" _..<._  |    |\n");
        gotoxy(x,y+13);
        printf("              |-. |   |    L        |   !     |  .-/'      `.|-.,-|\n");
        gotoxy(x,y+14);
        printf("              |__ '   '    |        '   |    /    /|   `, -. |   j\n");
        gotoxy(x,y+15);
        printf("        _..--'\"__  `-.___,'          `.___,.'  __/_|_  /   / '   |\n");
        gotoxy(x,y+16);
        printf("   _.-_..---\"\"_.-\\                            .,...__\"\"--./L/_   |\n");
        gotoxy(x,y+17);
        printf(" -'\"\"'     ,\"\"  ,-`-.    .___.,...___,    _,.+\"      \"\"\"\"`-+-==++-\n");
        gotoxy(x,y+18);
        printf("          / /  `.   )\"-.._`v \\|    V/  /-'    \\._,._.'\"-. /    /\n");
        gotoxy(x,y+19);
        printf("          ` `.  )---.     `\"\"\\\\__  / .'        /    \\    Y\"._.'\n");
        gotoxy(x,y+20);
        printf("           `\"'`\"     `-.     /|._\"\"_/         |  ,..   _ |  |\n");
        gotoxy(x,y+21);
        printf("                        `\"\"\"' |  \"'           `. `-'  (_|,-.'\n");
        gotoxy(x,y+22);
        printf("                               \\               |`       .`-\n");
        gotoxy(x,y+23);
        printf("                                `.           . j`._    /\n");
        gotoxy(x,y+24);
        printf("                                 |`.._     _.'|    `\"\"/\n");
        gotoxy(x,y+25);
        printf("                                 |    /\"\"'\"   |  .\". j\n");
        gotoxy(x,y+26);
        printf("                                .`.__j         \\ `.' |\n");
        gotoxy(x,y+27);
        printf("                                j    |          `._.'\n");
        gotoxy(x,y+28);
        printf("                               /     |\n");
        gotoxy(x,y+29);
        printf("                              /,  ,  \\\n");
        gotoxy(x,y+30);
        printf("                              \\|  |   L\n");
        gotoxy(x,y+31);
        printf("                               `..|_..' \n");
}

void JIGGlypuff() {

        printf("   ,..__\n");
        printf("  |  _  `--._                                  _.--\"\"\"`.\n");
        printf("  |   |._    `-.        __________         _.-'    ,|' |\n");
        printf("  |   |  `.     `-..--\"\"_.        `\"\"-..,-'      ,' |  |\n");
        printf("  L   |    `.        ,-'                      _,'   |  |\n");
        printf("   .  |     ,'     ,'            .           '.     |  |\n");
        printf("   |  |   ,'      /               \\            `.   |  |\n");
        printf("   |  . ,'      ,'                |              \\ /  j\n");
        printf("   `   \"       ,                  '               `   /\n");
        printf("    `,         |                ,'                  '+\n");
        printf("    /          |             _,'                     `\n");
        printf("   /     .-\"\"\"'L          ,-' \\  ,-'\"\"\"\"`-.           `\n");
        printf("  j    ,' ,.+--.\\        '    ',' ,.,-\"--._`.          \\\n");
        printf("  |   / .'  L    `.        _.'/ .'  |      \\ \\          .\n");
        printf(" j   | | `--'     |`+-----'  . j`._,'       L |         |\n");
        printf(" |   L .          | |        | |            | |         |\n");
        printf(" |   `\\ \\        / j         | |            | |         |\n");
        printf(" |     \\ `-.._,.- /           . `         .'  '         |\n");
        printf(" l      `-..__,.-'             `.`-.....-' _.'          '\n");
        printf(" '                               `-.....--'            j\n");
        printf("  .                  -.....                            |\n");
        printf("   L                  `---'                            '\n");
        printf("    \\                                                 /\n");
        printf("     ` \\                                        ,   ,'\n");
        printf("      `.`.    |                        /      ,'   .\n");
        printf("        . `._,                        |     ,'   .'\n");
        printf("         `.                           `._.-'  ,-'\n");
        printf("    _,-\"\"\"\"`-,                             _,'\"-.._\n");
        printf("  ,'          `-.._                     ,-'        `.\n");
        printf(" /             _,' `\"-..___     _,..--\"`.            `.\n");
        printf("|         _,.-'            `\"\"\"'         `-._          \\\n");
        printf("`-....---'                                   `-.._      |\n");
        printf("                                                  `--...' \n");
}
