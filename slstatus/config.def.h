/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 500;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "";

/* maximum command output length */
#define CMDLEN 128

/* maximum output string length */
#define MAXLEN CMDLEN * LEN(args)

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cat                 read arbitrary file             path
 * cpu_freq            cpu frequency in MHz            NULL
 * cpu_perc            cpu usage in percent            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/)
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * up                  interface is running            interface name (eth0)
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 *                                                     NULL on OpenBSD/FreeBSD
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 */
static const struct arg args[] = {
	/* function         format              argument                                   trun     signal */
	{ run_command,     "%s",                "~/scripts/middle_status.sh",              2,       -1 },
	{ run_command,     "%s",                "echo ';'",                                0,       -1 },
	// { netspeed_rx,     "  %s ",            "wlan0",                                   2,       -1 },
	// { netspeed_tx,     "  %s | ",          "wlan0",                                   2,       -1 },
	{ run_command,     "%s | ",             "~/scripts/volume.sh",                     1,       -1 },
	{ ram_used,        "  %s | ",           NULL,                                     4,       -1 },
	{ cpu_perc,	   "  %s%%",            NULL,                                     4,       -1 },
	{ temp,  	   " %s󰔄 | ",           "/sys/class/thermal/thermal_zone1/temp",  10,       -1 },
	{ wifi_essid,	   "  %s | ",          "wlan0",                                  10,       -1 },
	{ run_command,	   "%s | ",             "~/scripts/bluetooth.sh",                  2,       -1 },
	{ run_command,     "%s | ",             "~/scripts/battery.sh",                    2,       -1 },
	{ datetime,        "%s ",               "%a %b %d - %H:%M",                        2,       -1 },
};
