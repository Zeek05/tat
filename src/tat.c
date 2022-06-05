#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

// tat.c
// Apply text attributes from virtual terminal sequences to the console
// Each attribute has two states "on" and "off".
// The following attributes can be applied:
//  bold, underline, blink, negative


// define a function that takes in a bool for each attribute (bold, underline, blink, negative)
// and ENABLES the attribute with terminal sequences
bool enableAttribute(bool bold, bool underline, bool blink, bool negative, bool dim, bool bigunderline, bool strike, bool overline, bool italic) {
    // if any of the attributes are true, then enable the attribute with terminal sequences
    if (bold || underline || blink || negative || dim || bigunderline || strike || overline || italic) {
        // if bold is true, then enable bold with terminal sequences
        if (bold) {
            printf("\x1b[1m");
        }
        // if underline is true, then enable underline with terminal sequences
        if (underline) {
            printf("\x1b[4m");
        }
        // if blink is true, then enable blink with terminal sequences
        if (blink) {
            printf("\x1b[5m");
        }
        // if negative is true, then enable negative with terminal sequences
        if (negative) {
            printf("\x1b[7m");
        }
        // if dim is true, then enable dim with terminal sequences
        if (dim) {
            printf("\x1b[2m");
        }
        if (bigunderline) {
            printf("\x1b[21m");
        }
        if (strike) {
            printf("\x1b[9m");
        }
        if (overline) {
            printf("\x1b[53m");
        }
        if (italic) {
            printf("\x1b[3m");
        }
        return true;
    }
    // if all attributes are false, then return false
    else {
        return false;
    }
}

// define a function that takes in a bool for each attribute (bold, underline, blink, negative)
// and DISABLES the attribute with terminal sequences
bool disableAttribute(bool bold, bool underline, bool blink, bool negative, bool dim, bool bigunderline, bool strike, bool overline, bool italic) {
    // if any of the attributes are true, then disable the attribute with terminal sequences
    if (bold || underline || blink || negative || dim || bigunderline || strike || overline || italic)  {
        // if bold is true, then disable bold with terminal sequences
        if (bold) {
            printf("\x1b[22m");
        }
        // if underline is true, then disable underline with terminal sequences
        if (underline) {
            printf("\x1b[24m");
        }
        // if blink is true, then disable blink with terminal sequences
        if (blink) {
            printf("\x1b[25m");
        }
        // if negative is true, then disable negative with terminal sequences
        if (negative) {
            printf("\x1b[27m");
        }
        // if dim is true, then disable dim with terminal sequences
        if (dim) {
            printf("\x1b[22m");
        }
        if (bigunderline) {
            printf("\x1b[24m");
        }
        if (strike) {
            printf("\x1b[29m");
        }
        if (overline) {
            printf("\x1b[55m");
        }
        if (italic) {
            printf("\x1b[23m");
        }
        return true;
    }
    // if all attributes are false, then return false
    else {
        return false;
    }
}

// define macros for each attributes escape sequence
// post-build note: Yes I am aware I could have done this from the start, in V2 I may consider fixing this.
#define BOLD_ON "\x1b[1m"
#define BOLD_OFF "\x1b[22m"
#define UNDERLINE_ON "\x1b[4m"
#define UNDERLINE_OFF "\x1b[24m"
#define BLINK_ON "\x1b[5m"
#define BLINK_OFF "\x1b[25m"
#define NEGATIVE_ON "\x1b[7m"
#define NEGATIVE_OFF "\x1b[27m"
#define DIM_ON "\x1b[2m"
#define DIM_OFF "\x1b[22m"
#define BIGUNDERLINE_ON "\x1b[21m"
#define BIGUNDERLINE_OFF "\x1b[24m"
#define STRIKE_ON "\x1b[9m"
#define STRIKE_OFF "\x1b[29m"
#define OVERLINE_ON "\x1b[53m"
#define OVERLINE_OFF "\x1b[55m"
#define ITALIC_ON "\x1b[3m"
#define ITALIC_OFF "\x1b[23m"

void enableVT() {
    // enable virtual terminal processing with setconsolemode
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0; 
    GetConsoleMode(hConsole, &mode);
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hConsole, mode);
}

int SetColor(char* string) {
    enableVT();
    // the string should be in the format R,G,B where R,G,B are integers between 0 and 255
    // if the string is not in the correct format, then return -1
    // if the string is in the correct format then set the foreground color to the specified color
    // and return 0
    int r, g, b;
    char* token = strtok(string, ",");
    if (token == NULL) {
        return -1;
    }
    r = atoi(token);
    token = strtok(NULL, ",");
    if (token == NULL) {
        return -1;
    }
    g = atoi(token);
    token = strtok(NULL, ",");
    if (token == NULL) {
        return -1;
    }
    b = atoi(token);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        return -2;
    }
    printf("\x1b[38;2;%d;%d;%dm", r, g, b);
}

int SetBackground(char* string) {
    enableVT();
    // the same as SetColor() but for the background
    int r, g, b;
    char* token = strtok(string, ",");
    if (token == NULL) {
        return -1;
    }
    r = atoi(token);
    token = strtok(NULL, ",");
    if (token == NULL) {
        return -1;
    }
    g = atoi(token);
    token = strtok(NULL, ",");
    if (token == NULL) {
        return -1;
    }
    b = atoi(token);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        return -2;
    }
    printf("\x1b[48;2;%d;%d;%dm", r, g, b);

}

void Help() {
    enableVT();
    printf("\n");
    printf(BIGUNDERLINE_ON);
    printf("Text Attributes for Terminal (tat.exe)%s\n", BIGUNDERLINE_OFF);
    printf(ITALIC_ON);
    printf("By ZeekHalkyr\n");
    printf(ITALIC_OFF);
    printf("Usage: tat.exe <attributes>\n\n");
    printf("Press any key to see the attributes list.");
    getc(stdin);    
    printf(BIGUNDERLINE_ON);
    printf("Attributes:%s\n", BIGUNDERLINE_OFF);
    printf("\n The attributes you can supply (in no given order) are:\n");
    printf(ITALIC_ON);
    printf("  bold, underline, blink, negative, dim, bigunderline, strike, overline, italic, normal, foreground, and background.\n");
    printf(ITALIC_OFF);
    printf("\n");
    printf("  bold | b: ");
    printf(BOLD_ON);
    printf("Bold undoes the dim attribute, by default all CMD text is bold.\n\n");
    printf(BOLD_OFF);
    printf("  underline | ul: ");
    printf(UNDERLINE_ON);
    printf("Underline adds an underline to subsequent text. It is half as large as bigunderline.\n\n");
    printf(UNDERLINE_OFF);
    printf("  blink | bk: ");
    printf(BLINK_ON);
    printf("Blink adds a blinking effect to subsequent text.\n\n");
    printf(BLINK_OFF);
    printf("  negative | ng: ");
    printf(NEGATIVE_ON);
    printf("Negative inverts the colors of subsequent text.\n\n");
    printf(NEGATIVE_OFF);
    printf("  dim | d: ");
    printf(DIM_ON);
    printf("Dim makes subsequent text dimmer.\n\n");
    printf(DIM_OFF);
    printf("  bigunderline | bu: ");
    printf(BIGUNDERLINE_ON);
    printf("Bigunderline adds an underline to subsequent text. It is twice as large as underline.%s\n\n", BIGUNDERLINE_OFF);
    printf("  strike | st: ");
    printf(STRIKE_ON);
    printf("Strike adds a strike-through to subsequent text.\n\n");
    printf(STRIKE_OFF);
    printf("  overline | ol: ");
    printf(OVERLINE_ON);
    printf("Overline adds an overline to subsequent text.\n\n");
    printf(OVERLINE_OFF);
    printf("  italic | it: ");
    printf(ITALIC_ON);
    printf("Italic makes subsequent text italic.\n\n");
    printf(ITALIC_OFF);
    printf("  normal | n: ");
    printf("Resets all attributes to their default values.\n\n");
    printf("\x1b[38;2;0;0;255m  foreground | fg: ");
    printf("Sets the foreground color to the next argument (format is r,g,b).\x1b[38;2;255;255;255m\n\n");
    printf("\x1b[48;2;0;0;255m  background | bg: ");
    printf("Sets the background color to the next argument (format is r,g,b).\x1b[0m\n\n");
    printf("\n");
    printf("Press any key to see the examples.");
    getc(stdin);
    printf(BIGUNDERLINE_ON);
    printf("Example: %s", BIGUNDERLINE_OFF);
    printf("\n\n");
    printf("tat blink underline overline\n");
    printf("\n");
    printf("This will make the next text blink, underline, and have an overline. %s %s %s like this. %s %s %s ", BOLD_ON, UNDERLINE_ON, OVERLINE_ON, BOLD_OFF, UNDERLINE_OFF, OVERLINE_OFF);
    printf("\n\n");
    printf("Press any key to see developer notes.");
    getc(stdin);
    printf(BIGUNDERLINE_ON);
    printf("Notes: ");
    printf(BIGUNDERLINE_OFF);
    printf("\n");
    printf("  -%s%s%sIf you resize the console window, some attributes will expand to the entire width of the window.%s%s%s\n", BLINK_ON, UNDERLINE_ON, ITALIC_ON, ITALIC_OFF, UNDERLINE_OFF, BLINK_OFF);
    printf("  - Duplicate attributes apply the last one.\n");
    printf("  - Running the color command will reset the attributes on the screen.\n");
    printf("  - The attributes will inherit the foreground/background color.\n");
    return;

}





int main (int argc, char* argv[]) {
    // if the function is called with no arguments, then Help()
    if (argc == 1) {
        Help();
        return 1;
    }
    // if the function is called with one or more arguments, then:
    bool bold;
    bool underline;
    bool blink;
    bool negative;
    bool dim;
    bool bigunderline;
    bool strike;
    bool overline;
    bool italic;
    // set the above variables to false
    bold = false;
    underline = false;
    blink = false;
    negative = false;
    dim = false;
    bigunderline = false;
    strike = false;
    overline = false;
    italic = false;

    // if the first argument is /? or -? then print usage
    if (strcmp(argv[1], "/?") == 0 || strcmp(argv[1], "-?") == 0) {
        Help();
        return 1;
    }

    // if the first argument is "reset" then set all attributes to false and go to skip
    if (strcmp(argv[1], "reset") == 0) {
        bold = false;
        underline = false;
        blink = false;
        negative = false;
        dim = false;
        bigunderline = false;
        strike = false;
        overline = false;
        italic = false;
        goto skip;

    }

    // for each argument, check if the argument is <attr>
    // if it is, then set the corresponding attribute to true
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "bold") == 0 || strcmp(argv[i], "b") == 0) {
            bold = true;
        }
        else if (strcmp(argv[i], "underline") == 0 || strcmp(argv[i], "ul") == 0) {
            underline = true;

        }
        else if (strcmp(argv[i], "blink") == 0 || strcmp(argv[i], "bk") == 0) {
            blink = true;
        }
        else if (strcmp(argv[i], "negative") == 0 || strcmp(argv[i], "ng") == 0) {
            negative = true;
        }
        else if (strcmp(argv[i], "dim") == 0 || strcmp(argv[i], "d") == 0) {
            dim = true;
        }
        else if (strcmp(argv[i], "bigunderline") == 0 || strcmp(argv[i], "bu") == 0) {
            bigunderline = true;
        }
        else if (strcmp(argv[i], "strike") == 0 || strcmp(argv[i], "st") == 0) {
            strike = true;
        }
        else if (strcmp(argv[i], "overline") == 0 || strcmp(argv[i], "ol") == 0) {
            overline = true;
        }
        else if (strcmp(argv[i], "italic") == 0 || strcmp(argv[i], "it") == 0) {
            italic = true;
        }
        // not unique modifiers
        else if (strcmp(argv[i], "normal") == 0 || strcmp(argv[i], "n") == 0) {
            // set dim and negative to false
            dim = false;
            negative = false;
        }
        // if the argument is "fg" or "bg" then set the corresponding color
        else if (strcmp(argv[i], "foreground") == 0 || strcmp(argv[i], "fg") == 0) {
            i++;
            // if there is no argument after "fg" then error
            if (i == argc) {
                printf("Error: No color specified in fg.\n");
                return 1;
            }
            // if the argument is "default or df" then set the foreground color to the default white.
            if (strcmp(argv[i], "default") == 0 || strcmp(argv[i], "df") == 0) {
                SetColor("255,255,255");
                return 0;
            }

            int r = SetColor(argv[i]);
            // if r is 0 then the color was set, carry on
            // if r is -1 then the format was invalid
            // if r is -2 then the value was less than 0 or greater than 255
            if (r == 0) {
                continue;
            }
            else if (r == -1) {
                printf("Invalid format, second argument to fg should be <r>,<g>,<b>.\n");
                return 1;
            }
            else if (r == -2) {
                printf("Invalid value. Values must be between 0 and 255.\n");
                return 1;
            }
        }
        else if (strcmp(argv[i], "background") == 0 || strcmp(argv[i], "bg") == 0) {
            i++;
            // if there is no argument after "bg" then error
            if (i == argc) {
                printf("Error: No color specified in bg.\n");
                return 1;
            }
            // if the argument is "default or df" then set the background color to the default black.
            if (strcmp(argv[i], "default") == 0 || strcmp(argv[i], "df") == 0) {
                SetBackground("0,0,0");
                return 0;
            }
            int r = SetBackground(argv[i]);
            // if r is 0 then the color was set, carry on
            // if r is -1 then the format was invalid
            // if r is -2 then the value was less than 0 or greater than 255
            if (r == 0) {
                continue;
            }
            else if (r == -1) {
                printf("Invalid format, second argument to bg should be <r>,<g>,<b>.\n");
                return 1;
            }
            else if (r == -2) {
                printf("Invalid value. Values must be between 0 and 255.\n");
                return 1;
            }

        }
    }
    

    skip:
    enableVT();

    // call disableAttribute() with the attributes that are false
    disableAttribute(!bold, !underline, !blink, !negative, !dim, !bigunderline, !strike, !overline, !italic);
    // call enableAttribute() with the attributes that are true
    enableAttribute(bold, underline, blink, negative, dim, bigunderline, strike, overline, italic);
    return 0;


}

