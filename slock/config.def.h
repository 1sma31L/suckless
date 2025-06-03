/* user and group to drop privileges to */
static const char *user  = "ismail";
static const char *group = "users";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#1d1f21",     /* after initialization */
	[INPUT] =  "#1d1f21",   /* during input */
	[FAILED] = "#581c1c",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;

/* default message */
static const char * message = "He who doth battle with monsters should see to it that he becometh not a monster thereby. For if thou gaze long into an abyss, the abyss will also gaze into thee.";

/* text color */
static const char * text_color = "#928374";

/* text size (must be a valid size) */
static const char * font_name = "fixed";

/* allow control key to trigger fail on clear */
static const int controlkeyclear = 1;
