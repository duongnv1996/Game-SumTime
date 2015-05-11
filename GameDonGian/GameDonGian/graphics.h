#if !defined _GRAPHICS_FOR_DOS_H_
#define _GRAPHICS_FOR_DOS_H_

#define M_PI 3.14159265358979

// -----------------------------------------------------------

void EnableDosMemoryMapping(int flag);
void EnableAutoRedraw(int flag);
void ForceRedraw();

// -----------------------------------------------------------

void delay(int ms);
void randomize();
int random(int num);

// -----------------------------------------------------------

enum graphics_errors {
    grOk           =   0,
    grNoInitGraph      =  -1,
    grNotDetected      =  -2,
    grFileNotFound     =  -3,
    grInvalidDriver    =  -4,
    grNoLoadMem    =  -5,
    grNoScanMem    =  -6,
    grNoFloodMem       =  -7,
    grFontNotFound     =  -8,
    grNoFontMem    =  -9,
    grInvalidMode      = -10,
    grError        = -11,
    grIOerror      = -12,
    grInvalidFont      = -13,
    grInvalidFontNum   = -14,
    grInvalidVersion   = -18
};

enum graphics_drivers { 
    DETECT,         
    CGA, MCGA, EGA, EGA64, EGAMONO, IBM8514, 
    HERCMONO, ATT400, VGA, PC3270,          
    CURRENT_DRIVER = -1
};

enum graphics_modes { 
    CGAC0      = 0,  /* 320x200 palette 0; 1 page   */
    CGAC1      = 1,  /* 320x200 palette 1; 1 page   */
    CGAC2      = 2,  /* 320x200 palette 2: 1 page   */
    CGAC3      = 3,  /* 320x200 palette 3; 1 page   */
    CGAHI      = 4,  /* 640x200 1 page          */
    MCGAC0     = 0,  /* 320x200 palette 0; 1 page   */
    MCGAC1     = 1,  /* 320x200 palette 1; 1 page   */
    MCGAC2     = 2,  /* 320x200 palette 2; 1 page   */
    MCGAC3     = 3,  /* 320x200 palette 3; 1 page   */
    MCGAMED    = 4,  /* 640x200 1 page          */
    MCGAHI     = 5,  /* 640x480 1 page          */
    EGALO      = 0,  /* 640x200 16 color 4 pages    */
    EGAHI      = 1,  /* 640x350 16 color 2 pages    */
    EGA64LO    = 0,  /* 640x200 16 color 1 page     */
    EGA64HI    = 1,  /* 640x350 4 color  1 page     */
    EGAMONOHI  = 0,  /* 640x350 64K on card, 1 page - 256K on card, 4 pages */
    HERCMONOHI = 0,  /* 720x348 2 pages         */
    ATT400C0   = 0,  /* 320x200 palette 0; 1 page   */
    ATT400C1   = 1,  /* 320x200 palette 1; 1 page   */
    ATT400C2   = 2,  /* 320x200 palette 2; 1 page   */
    ATT400C3   = 3,  /* 320x200 palette 3; 1 page   */
    ATT400MED  = 4,  /* 640x200 1 page          */
    ATT400HI   = 5,  /* 640x400 1 page          */
    VGALO      = 0,  /* 640x200 16 color 4 pages    */
    VGAMED     = 1,  /* 640x350 16 color 2 pages    */
    VGAHI      = 2,  /* 640x480 16 color 1 page     */
    PC3270HI   = 0,  /* 720x350 1 page          */
    IBM8514LO  = 0,  /* 640x480 256 colors      */
    IBM8514HI  = 1   /*1024x768 256 colors      */
};

enum COLORS {
    BLACK,  
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

enum CGA_COLORS {
    CGA_LIGHTGREEN     = 1,  
    CGA_LIGHTRED       = 2,
    CGA_YELLOW         = 3,

    CGA_LIGHTCYAN      = 1,  
    CGA_LIGHTMAGENTA   = 2,
    CGA_WHITE          = 3,

    CGA_GREEN          = 1,  
    CGA_RED        = 2,
    CGA_BROWN          = 3,

    CGA_CYAN           = 1,  
    CGA_MAGENTA        = 2,
    CGA_LIGHTGRAY      = 3
};


enum EGA_COLORS {
    EGA_BLACK        =  0,   
    EGA_BLUE         =  1,
    EGA_GREEN        =  2,
    EGA_CYAN         =  3,
    EGA_RED      =  4,
    EGA_MAGENTA      =  5,
    EGA_BROWN        =  20,
    EGA_LIGHTGRAY    =  7,
    EGA_DARKGRAY     =  56,  
    EGA_LIGHTBLUE    =  57,
    EGA_LIGHTGREEN   =  58,
    EGA_LIGHTCYAN    =  59,
    EGA_LIGHTRED     =  60,
    EGA_LIGHTMAGENTA     =  61,
    EGA_YELLOW       =  62,
    EGA_WHITE        =  63
};

enum line_styles {     
    SOLID_LINE   = 0,
    DOTTED_LINE  = 1,
    CENTER_LINE  = 2,
    DASHED_LINE  = 3,
    USERBIT_LINE = 4,  
};

enum line_widths {     
    NORM_WIDTH  = 1,
    THICK_WIDTH = 3,
};

enum font_names {
    DEFAULT_FONT    = 0,
    TRIPLEX_FONT    = 1,
    SMALL_FONT  = 2,
    SANS_SERIF_FONT = 3,
    GOTHIC_FONT = 4,
    SCRIPT_FONT = 5,
    SIMPLEX_FONT = 6,
    TRIPLEX_SCR_FONT = 7,
    COMPLEX_FONT = 8,
    EUROPEAN_FONT = 9,
    BOLD_FONT = 10
};

#define HORIZ_DIR   0   
#define VERT_DIR    1   

#define USER_CHAR_SIZE  0

enum fill_patterns {     
    EMPTY_FILL,     
    SOLID_FILL,     
    LINE_FILL,      
    LTSLASH_FILL,   
    SLASH_FILL,     
    BKSLASH_FILL,   
    LTBKSLASH_FILL, 
    HATCH_FILL,     
    XHATCH_FILL,    
    INTERLEAVE_FILL,
    WIDE_DOT_FILL,  
    CLOSE_DOT_FILL, 
    USER_FILL       
};

enum putimage_ops { 
    COPY_PUT,       
    XOR_PUT,        
    OR_PUT,         
    AND_PUT,        
    NOT_PUT         
};

enum text_just {    
                   
    LEFT_TEXT   = 0,
    CENTER_TEXT = 1,
    RIGHT_TEXT  = 2,

    BOTTOM_TEXT = 0,
    TOP_TEXT    = 2
};


#define MAXCOLORS 15

struct palettetype {
    unsigned char size;
    signed char colors[MAXCOLORS+1];
};

struct linesettingstype {
    int linestyle;
    unsigned upattern;
    int thickness;
};

struct textsettingstype {
    int font;
    int direction;
    int charsize;
    int horiz;
    int vert;
};

struct fillsettingstype {
    int pattern;
    int color;
};

struct pointtype {
    int x, y;
};

struct viewporttype {
    int left, top, right, bottom;
    int clip;
};

struct arccoordstype {
    int x, y;
    int xstart, ystart, xend, yend;
};


void arc(int x, int y, int stangle, int endangle,int radius);
void bar(int left, int top, int right, int bottom);
void bar3d(int left, int top, int right, int bottom, int depth, int topflag);
void circle(int x, int y, int radius);
void cleardevice(void);
void clearviewport(void);
void closegraph(void);
void detectgraph(int  *graphdriver,int  *graphmode);
void drawpoly(int numpoints, const int  *polypoints);
void ellipse(int x, int y, int stangle, int endangle, int xradius, int yradius);
void fillellipse( int x, int y, int xradius, int yradius );
void fillpoly(int numpoints, const int  *polypoints);
void floodfill(int x, int y, int border);
void getarccoords(struct arccoordstype  *arccoords);
void getaspectratio(int  *xasp, int  *yasp);
int getbkcolor(void);
int getcolor(void);
struct palettetype * getdefaultpalette( void );
char * getdrivername( void );
void getfillpattern(char  *pattern);
void getfillsettings(struct fillsettingstype  *fillinfo);
int getgraphmode(void);
void getimage(int left, int top, int right, int bottom, void  *bitmap);
void getlinesettings(struct linesettingstype  *lineinfo);
int getmaxcolor(void);
int getmaxmode(void);
int getmaxx(void);
int getmaxy(void);
char * getmodename( int mode_number );
void getmoderange(int graphdriver, int  *lomode, int  *himode);
unsigned getpixel(int x, int y);
void getpalette(struct palettetype  *palette);
int getpalettesize( void );
void gettextsettings(struct textsettingstype  *texttypeinfo);
void getviewsettings(struct viewporttype  *viewport);
int getx(void);
int gety(void);
void graphdefaults(void);
char * grapherrormsg(int errorcode);
void _graphfreemem(void  *ptr, unsigned size);
void * _graphgetmem(unsigned size);
int graphresult(void);
unsigned imagesize(int left, int top, int right, int bottom);
void initgraph(int   *graphdriver, int   *graphmode, const char  *pathtodriver);
void line(int x1, int y1, int x2, int y2);
void linerel(int dx, int dy);
void lineto(int x, int y);
void moverel(int dx, int dy);
void moveto(int x, int y);
void outtext(const char  *textstring);
void outtextxy(int x, int y, const char  *textstring);
void pieslice(int x, int y, int stangle, int endangle, int radius);
void putimage(int left, int top, const void  *bitmap, int op);
void putpixel(int x, int y, int color);
void rectangle(int left, int top, int right, int bottom);
void restorecrtmode(void);
void sector( int X, int Y, int StAngle, int EndAngle, int XRadius, int YRadius );
void setactivepage(int page);
void setallpalette(const struct palettetype  *palette);
void setaspectratio( int xasp, int yasp );
void setbkcolor(int color);
void setcolor(int color);
void setfillpattern(const char  *upattern, int color);
void setfillstyle(int pattern, int color);
unsigned setgraphbufsize(unsigned bufsize);
void setgraphmode(int mode);
void setlinestyle(int linestyle, unsigned upattern, int thickness);
void setpalette(int colornum, int color);
void setrgbpalette(int colornum, int red, int green, int blue);
void settextjustify(int horiz, int vert);
void settextstyle(int font, int direction, int charsize);
void setusercharsize(int multx, int divx, int multy, int divy);
void setviewport(int left, int top, int right, int bottom, int clip);
void setvisualpage(int page);
void setwritemode( int mode );
int textheight(const char  *textstring);
int textwidth(const char  *textstring);

// -----------------------------------------------------------

#endif
