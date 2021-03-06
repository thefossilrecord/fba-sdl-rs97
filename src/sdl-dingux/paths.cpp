
// Paths module
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include "burner.h"

char szAppHomePath[MAX_PATH] = "./.fba";			// ~/.fba
char szAppSavePath[MAX_PATH] = "./.fba/saves";		// ~/.fba/saves
char szAppConfigPath[MAX_PATH] = "./.fba/configs";	// ~/.fba/configs
char szAppHiscorePath[MAX_PATH] = "./.fba/hiscore";	// ~/.fba/highscore // for burn/hiscore.cpp
char szAppSamplesPath[MAX_PATH] = "./.fba/samples";	// ~/.fba/samples // for burn/snd/samples.cpp
char szAppPreviewPath[MAX_PATH] = "./.fba/previews";	// ~/.fba/previews
char szAppRomPaths[DIRS_MAX][MAX_PATH] = {{"./"}, {"/usr/local/share/roms/"}, {"roms/"}, };
char szAppBlendPath[MAX_PATH] = "./.fba/blend"; 	// for cps_obj.cpp, neo_sprite.cpp, pgm_draw.cpp

void BurnPathsInit()
{
#ifndef WIN32
	char *home = getenv("HOME");
	if(home) sprintf(szAppHomePath, "%s/.fba", home);
	mkdir(szAppHomePath, S_IRWXU);
	if(!errno) {
		getcwd(szAppHomePath, MAX_PATH);
		strcat(szAppHomePath, "/.fba");
		mkdir(szAppHomePath, S_IRWXU);
	}

	sprintf(szAppSavePath, "%s/saves", szAppHomePath);
	mkdir(szAppSavePath, S_IRWXU);

	sprintf(szAppConfigPath, "%s/configs", szAppHomePath);
	mkdir(szAppConfigPath, S_IRWXU);

	sprintf(szAppPreviewPath, "%s/previews", szAppHomePath);
	mkdir(szAppPreviewPath, S_IRWXU);

	sprintf(szAppSamplesPath, "%s/samples", szAppHomePath);
	mkdir(szAppSamplesPath, S_IRWXU);
#else
	getcwd(szAppHomePath, MAX_PATH);
	strcat(szAppHomePath, "/.fba");
	mkdir(szAppHomePath);

	sprintf(szAppSavePath, "%s/saves", szAppHomePath);
	mkdir(szAppSavePath);

	sprintf(szAppConfigPath, "%s/configs", szAppHomePath);
	mkdir(szAppConfigPath);

	sprintf(szAppPreviewPath, "%s/previews", szAppHomePath);
	mkdir(szAppPreviewPath);

	sprintf(szAppSamplesPath, "%s/samples", szAppHomePath);
	mkdir(szAppSamplesPath);
#endif
}
