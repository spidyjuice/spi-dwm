/* See LICENSE file for copyright and license details. */

/* aappearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Bitstream Vera Sans Mono:pixelsize=11:antialiasing=true:autohint=true" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_bar[]        = "#447944";
static const char col_borderdesel[]       = "#447944";
static const char col_bordersel[]        = "#ffffff";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_borderdesel },
	[SchemeSel]  = { col_gray4, col_bar,  col_bordersel  },
/* FF8200 790000 007900*/
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     switchtotag    isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            0,		   1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,		   0,           -1 },
	{ "qutebrowser", NULL,    NULL,       1,            0,		   0,           -1 },
	{ "Nitrogen", NULL,       NULL,       1 << 6,       1,		   0,           -1 },
	{ "Element", NULL,       NULL,        1 << 2,       1,		   0,           -1 },
	{ "TelegramDesktop", NULL, NULL,      1 << 2,       1,		   0,           -1 },
	{ "Claws-mail", NULL,       NULL,     1 << 3,       1,		   0,           -1 },
	/* tag 8 - games      									*/
	{ "openmsx",     NULL,    NULL,       1 << 7,       1,		   0,           -1 },
	{ "Snes9x-gtk",       NULL,       NULL,    1 << 7,       1,		   0,           -1 },
	{ "mGBA",     NULL,    NULL,       1 << 7,       1,		   0,           -1 },
	{ "scummvm",     NULL,    NULL,       1 << 7,       1,		   0,           -1 },
	{ "EasyRPG Player", NULL,    NULL,    1 << 7,       1,		   0,           -1 },
	{ "Fceux", NULL,    NULL,    1 << 7,       1,		   0,           -1 },
	{ "fceux", NULL,    NULL,    1 << 7,       1,		   0,           -1 },
	/* tag 9 - media      									*/
	{ "feh",      NULL,       NULL,       1 << 8,       	    1,		   0,           -1 },
	{ "mpv",      NULL,       NULL,       0,       	    0,		   1,           -1 },
	/* tag -names      									*/
	{ NULL,      "float",      NULL,       0,       	    0,		   1,           -1 },
	{ NULL,      "tag1",       NULL,       1,       	    1,		   0,           -1 },
	{ NULL,      "tag2",       NULL,       1 << 1,       	    1,		   0,           -1 },
	{ NULL,      "tag3",       NULL,       1 << 2,       	    1,		   0,           -1 },
	{ NULL,      "tag4",       NULL,       1 << 3,       	    1,		   0,           -1 },
	{ NULL,      "tag5",       NULL,       1 << 4,       	    1,		   0,           -1 },
	{ NULL,      "tag6",       NULL,       1 << 5,       	    1,		   0,           -1 },
	{ NULL,      "tag7",       NULL,       1 << 6,       	    1,		   0,           -1 },
	{ NULL,      "tag8",       NULL,       1 << 7,       	    1,		   0,           -1 },
	{ NULL,      "tag9",       NULL,       1 << 8,       	    1,		   0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#include "fibonacci.c"
 static const Layout layouts[] = {
 	/* symbol     arrange function */
 	{ "[@]",      spiral },
 	{ "><>",      NULL },    /* no layout function means floating behavior */
 	{ "[]=",      tile },    /* first entry is default */
 	{ "[M]",      monocle },
 	{ "[\\]",      dwindle },
 };

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */

/*obsolete*/
/*static const char *weblscmd[]  = { "dmenu_webs", NULL };*/
/*static const char *chatlscmd[]  = { "launch_chat", NULL };*/
/*static const char *gamecmd[]  = { "launch_game", NULL };*/
/*static const char *sysmoncmd[]  = { "st", "htop", NULL };*/
/*static const char *netcmd[]  = { "wicd-client", NULL };*/
/*static const char *rsslaunch[]  = { "echo", "no rss cmd yet...", NULL };*/
/*static const char *scriptscmd[]  = { "dmenu_scripts", NULL };*/
/*static const char *pcmd[]  = { "secret", NULL };*/
/*static const char *rest1cmd[]  = { "echo", "no command yet", NULL };*/
/*static const char *rest2cmd[]  = { "sudo", "systemctl", "start", "systemd-suspend", NULL };*/
/*static const char *rest3cmd[]  = { "sudo", "systemctl", "start", "systemd-hibernate", NULL };*/
/*static const char *sfxdo[]  = { "sfx-do", NULL };*/
/*static const char *windowfindcmd[]  = { "rofi", "show", "window", NULL };*/


/*shortcuts*/
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_bar, "-sf", col_gray4, NULL };
static const char *spawn_term[]  = { "st", NULL };
static const char *launch_web[]  = { "launch-web", NULL };
static const char *launch_web_discord[]  = { "launch-web", "https://www.discord.com/channels/@me", NULL };
static const char *launch_chat[]  = { "launch-chat", NULL };
static const char *launch_game[]  = { "launch-game", NULL };
static const char *launch_mail[]  = { "claws-mail", NULL };

/*menus*/
static const char *menu_rest[]  = { "dmenu_rest", NULL };
static const char *menu_system[]  = { "dmenu_sys", NULL };
static const char *menu_todo[]  = { "dmenu_todo", NULL };
static const char *menu_passwords[]  = { "dmenu_passty", NULL };
static const char *menu_drug[]  = { "dmenu_druglog", NULL };
static const char *menu_clipboard[]  = { "dmenu_clipmenu", NULL };

/*other*/
static const char *bonkcmd[]  = { "bonkcmd", NULL };
static const char *screen_snap[]  = { "scrot $DATEFORMAT_scrot.png -e 'mv $f /home/storage/gallery/snaps_roll/'", NULL }; /*not set up right*/
static const char *vol_up[]  = { "vol-up", NULL };
static const char *vol_down[]  = { "vol-dwn", NULL };
static const char *vol_toggle[]  = { "vol-tog", NULL };
static const char *mic_toggle[]  = { "mic-tog", NULL };
static const char *toggle_compositor[]  = { "compositor-switch", NULL };
static const char *toggle_red[]  = { "red-switch", NULL };
static const char *rest_display[]  = { "rest-display", NULL };
static const char *middleclick[]  = { "xdotool", "click", "2", NULL };

/*music*/
static const char *music_menu[]  = { "st", "-n", "tag7", "ncmpcpp", "--port=6601", NULL };
static const char *music_pause[]  = { "mpc", "--port=6601", "toggle", NULL };
static const char *music_next[]  = { "mpc", "--port=6601", "next", NULL };
static const char *music_previous[]  = { "mpc", "--port=6601", "prev", NULL };
static const char *music_seek_foward[]  = { "mpc", "--port=6601", "seek", "+3", NULL };
static const char *music_seek_backward[]  = { "mpc", "--port=6601", "seek", "-3", NULL };


static Key keys[] = {
	/* modifier                     key        function        argument */

/*   right hand*/
	{ MODKEY,                       XK_j,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = +1 } },

	{ MODKEY,           		XK_i,	   viewtoleft,     {0} },
	{ MODKEY,           		XK_o,  	   viewtoright,    {0} },
	{ MODKEY|ShiftMask,             XK_i,  	   tagtoleft,      {0} },
	{ MODKEY|ShiftMask,             XK_o,  	   tagtoright,     {0} },     

	{ MODKEY,           		XK_n,  	   focusmon,       {.i = -1 } },
	{ MODKEY,          		XK_m,	   focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask, 		XK_n,      tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask, 		XK_m,      tagmon,         {.i = +1 } },

	{ MODKEY,                       XK_h, setmfact,    {.f = -0.05} }, 
	{ MODKEY,                       XK_l,  setmfact,    {.f = +0.05} },

	{ MODKEY,             		XK_semicolon,      setlayout,      {0} },
	{ MODKEY,             		XK_apostrophe,  togglefloating,     {0} }, /*nearly unecessary*/

	{ MODKEY,           		XK_comma, incnmaster, {.i = -1 } },
	{ MODKEY,           		XK_period, incnmaster, {.i = +1 } },

	{ MODKEY,           		XK_slash,  	   spawn,  	   {.v = menu_clipboard } },

	{ MODKEY,           		XK_p,  	   spawn,  	   {.v = menu_passwords } },

/*   left hand*/
	{ MODKEY,           		XK_a,  	   spawn,  	   {.v = middleclick } },
	{ MODKEY,                       XK_s,      spawn,          {.v = screen_snap } },

	{ MODKEY,                       XK_g,  	   zoom,           	   {0} },

	{ MODKEY,           		XK_r,  	   spawn,  	   {.v = menu_drug } },
	{ MODKEY,        		XK_t,      spawn,          {.v = menu_todo } }, 

/*   sides*/
	{ MODKEY,           		XK_BackSpace, spawn,  	   {.v = bonkcmd } },
	{ MODKEY,           		XK_backslash, spawn,  	   {.v = menu_system } },
	{ MODKEY|ControlMask,           XK_Delete, quit,           {0} },

	{ MODKEY,           		XK_Escape, spawn,  	   {.v = menu_rest } },
	{ MODKEY,                       XK_Tab,    view,           {0} },

	{ MODKEY,                       XK_Up,     spawn,          {.v = vol_up } },
	{ MODKEY,                       XK_Down,   spawn,          {.v = vol_down } },
	{ MODKEY,                       XK_Right,  spawn,          {.v = vol_toggle } },
	{ MODKEY,                       XK_Left,   spawn,          {.v = mic_toggle } },

/*   settings*/
	{ MODKEY|ControlMask,           XK_b,      togglebar,      {0} },
	{ MODKEY|ControlMask,           XK_c, 	   spawn,  	   {.v = toggle_compositor } },
	{ MODKEY|ControlMask,           XK_v, 	   spawn,  	   {.v = toggle_red } },

/*   shortcuts*/
	{ MODKEY|ShiftMask,           	XK_BackSpace, killclient,  {0} },

	{ MODKEY|ShiftMask,           	XK_m,   spawn,  	   {.v = rest_display} },

	{ MODKEY,                       XK_Return, spawn,          {.v = spawn_term } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = dmenucmd } },

	{ MODKEY|ShiftMask,        	XK_w,       spawn,          {.v = launch_web } },
	{ MODKEY|ShiftMask,        	XK_d,       spawn,          {.v = launch_web_discord } },
	{ MODKEY|ShiftMask,        	XK_e,       spawn,          {.v = launch_mail } },
	{ MODKEY|ShiftMask,        	XK_c,       spawn,          {.v = launch_chat } },
	{ MODKEY|ShiftMask,        	XK_g,       spawn,          {.v = launch_game } },

/*   music*/
	{ MODKEY|Mod1Mask,           	XK_Return, spawn,  	   {.v = music_menu } },
	{ MODKEY|Mod1Mask,           	XK_space,  spawn,  	   {.v = music_pause } },
	{ MODKEY|Mod1Mask,           	XK_n,   spawn,  	   {.v = music_next } },
	{ MODKEY|Mod1Mask,    		XK_b,     spawn,  	   {.v = music_previous } },
	{ MODKEY|ShiftMask|Mod1Mask,    XK_n,     spawn,  	   {.v = music_previous } },
	{ MODKEY|Mod1Mask,           	XK_Right,  spawn,  	   {.v = music_seek_foward } },
	{ MODKEY|Mod1Mask,           	XK_Left,   spawn,  	   {.v = music_seek_backward } },

/*   num*/
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY,                       XK_quotedbl, view,         {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },




/*:) navigation*/
	/*not perfectly sure if this belongs here*/
/*:) (far)*/
	/*sys*/

	/*{ MODKEY,           		XK_F2,   spawn,  	   {.v = rest2cmd} },*/
	/*{ MODKEY,           		XK_F3,   spawn,  	   {.v = rest3cmd} },*/
	/*{ MODKEY,           		XK_F8,   spawn,  	   {.v = rest-display} },*/
	/*audio*/		
	/*music*/
/*:) scripts (bottom-row)*/
	/*{ MODKEY,           		XK_slash,  spawn,  	   {.v = scriptscmd } },*/
	/*{ MODKEY|ShiftMask,           	XK_period,      spawn,  	   {.v = pcmd } },*/
/*:) manipulation (left home-row)*/
/*:) tile layout (left top-row)*/
	/*{ MODKEY|ControlMask,           XK_q,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ControlMask,           XK_w,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_e,      setlayout,      {.v = &layouts[2]} },*/
/*:) screen controls (bottom-row)*/
	/* super z power/screen save command? */
/*:) launchers*/
/*	{ MODKEY,             		XK_F2,      spawn,          {.v = launch_web } },*/
/*	{ MODKEY, 			XK_F3,      spawn,          {.v = rsslaunch } },*/
/*	{ MODKEY|ShiftMask,        	XK_r,       spawn,          {.v = rsslaunch } },*/
/*	{ MODKEY, 			XK_F4,      spawn,          {.v = launch_mail } },*/
/*	{ MODKEY,             		XK_F5,      spawn,          {.v = launch_chat } },*/
/*	{ MODKEY|ShiftMask|ControlMask, XK_c,       spawn,          {.v = chatlscmd } },*/
/*	{ MODKEY, 			XK_F6,      spawn,          {.v = launch_game } },*/
/*:) NUM*/


};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = spawn_term } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
/*	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },*/
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

