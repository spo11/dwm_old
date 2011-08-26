/* See LICENSE file for copyright and license details. */

/* appearance */
//static const char font[]            = "-*-terminusmod-medium-r-*-*-12-*-*-*-*-*-*-*";
//static const char font[]            = "-*-profont-*-*-*-*-12-*-*-*-*-*-*-*";
static const char font[]            = "-*-terminusmod-medium-*-*-*-12-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#D4D4D4";
static const char normbgcolor[]     = "#EBEBEB";
static const char normfgcolor[]     = "#A8B0B2";
static const char selbordercolor[]  = "#D1D1D1";
static const char selbgcolor[]      = "#DBDBDB";
static const char selfgcolor[]      = "#95B2C1";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappx     = 3;        /* gap pixel between windows */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char      *tags[] = { "main", "www", "code", "edit", "music", "video", "office" };

#define ALL 0
#define MAIN 1 << 0
#define WWW 1 << 1
#define CODE 1 << 2
#define EDIT 1 << 3
#define MUSIC 1 << 4
#define VIDEO 1 << 5
#define OFFICE 1 << 6
static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	//{ "Gimp",     NULL,       NULL,       0,            True,        -1 },
	//{ "Firefox",  NULL,       NULL,       1 << 8,       False,       -1 },
	{ "luakit",     NULL,       NULL,       WWW,          False,       -1 },
	{ "Gvim",       NULL,       NULL,       CODE,         False,       -1 },
	{ "Minitube",   NULL,       NULL,       VIDEO,        False,       -1 },
	{ "MPlayer",   NULL,       NULL,       VIDEO,        False,       -1 },
	{ "Emacs",      NULL,       NULL,       OFFICE,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

#include "bstack.c"
#include "bstackhoriz.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
//	{ "[]=",      tile },    /* first entry is default */
//	{ "><>",      NULL },    /* no layout function means floating behavior */
//	{ "[M]",      monocle },
//	{ "TTT",      bstack },
//	{ "===",      bstackhoriz },
	{ "ÿ",      tile },
	{ "ý",      NULL },
	{ "ú",      monocle },
	{ "þ",      bstack },  /* first entry is default */
	{ "û",      bstackhoriz },
}; 

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "uxterm", NULL };
static const char *mutecmd[] = { "amixer", "-q", "sset", "Master", "toggle", NULL };
static const char *volupcmd[] = { "amixer", "-q", "sset", "Master", "3+", "unmute", NULL };
static const char *voldowncmd[] = { "amixer", "-q", "sset", "Master", "3-", "unmute", NULL };
static const char *mpctoggle[] = { "mpc", "toggle", NULL };
static const char *mpcnext[] = { "mpc", "next", NULL };
static const char *mpcprev[] = { "mpc", "prev", NULL };
static const char *mpcstop[] = { "mpc", "stop", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ControlMask,           XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
        { MODKEY,                       XK_s,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ 0,                            0x1008ff11,  spawn,      {.v = voldowncmd } },
	{ 0,                            0x1008ff13,  spawn,      {.v = volupcmd } },
	{ 0,                            0x1008ff12,  spawn,      {.v = mutecmd } },
	{ 0,                            0x1008ff14,  spawn,      {.v = mpctoggle } },
	{ 0,                            0x1008ff17,  spawn,      {.v = mpcnext } },
	{ 0,                            0x1008ff16,  spawn,      {.v = mpcprev } },
	{ 0,                            0x1008ff15,  spawn,      {.v = mpcstop } },
        //{ 0,                       0x1008ff11,     spawn,         {.v = voldowncmd } },
        //{ 0,                       0x1008ff13,     spawn,         {.v = volupcmd } },
        //{ 0,                       0x1008ff12,     spawn,         {.v = mutecmd } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

/* Patches */

