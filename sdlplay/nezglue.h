#ifndef __NEZGLUE_H__
#define __NEZGLUE_H__

/* Build Driver and Song on Memory */
int LoadHeader(void *src, int len);
int LoadDriver(void *src, int len);
int LoadSong(void *src, int len);

/* Driver Info */
int GetNRTDRVVer(void);

/* Basic Methods */
int LoadNSF(const char *file, int freq, int ch, int vol, int songno);

void SetSongNoNSF(int song);
void SetSongNSF(int song);
void SetFreqNSF(int freq);
void SetChannelNSF(int ch);
void SetVolumeNSF(int vol);

/* Extended for Load */
int LoadFileNSF(const char *file);
int LoadNSFData( int freq , int ch , int vol , int songno );

/* Volume
 ---- Device Name ----
 DMG
 HES
 ZXAY
 ---- NSF Device Name ----
 APU
 FDS
 FME7
 MMC5
 N106
 VRC6
 VRC7
 */

float GetDeviceVolumeNSF(const char *name);
void SetDeviceVolumeNSF(const char *name, float vol);
void SetAllDeviceVolumeNSF(float vol);

/* Controls */
void ResetNSF(void);
void TerminateNSF(void);
void FreeBufferNSF(void);
int LoadSongNSF(void);
int NextSongNSF(void);
int PrevSongNSF(void);

/* Get Info */
void GetTitleNSF(char *title);
int GetSongLengthNSF(void);
int GetChannelNSF(void);
int GetSongNoNSF(void);
int GetTotalSecNSF(void);
int GetExtDeviceNSF(void);
void GetExtDeviceStringNSF(char *dest);

/* Playlist */
int GetTotalSongsPLNSF(void);
void GetTitlePLNSF(char *title, int pos);
int GetLengthPLNSF(int pos);

/* Devices */
#define EXT_VRC6	(1 << 0)
#define EXT_VRC7	(1 << 1)
#define EXT_FDS     (1 << 2)
#define EXT_MMC5	(1 << 3)
#define EXT_N106	(1 << 4)
#define EXT_FME7	(1 << 5)
#define EXT_J86     (1 << 6)

/* Rendering */
void RenderNSF(void *bufp, unsigned samples);

void SeekNSF(unsigned frames);
int GetFramesNSF(void);
int GetFrameCyclesNSF(void);
float GetFramePerSecondsNSF(void);

int GetAvgCyclesNSF(void);
int GetMaxCyclesNSF(void);
int GetMaxCyclesPositionNSF(void);

/* Debug */
enum REG_TAG
{
    REG_PC,
    REG_A,
    REG_X,
    REG_Y,
    REG_S,
    REG_P
};

unsigned ReadLinearNSF(unsigned address);
unsigned ReadMemoryNSF(unsigned address);
unsigned ReadRegisterNSF(unsigned address);

void DebugPauseNSF(void);
void DebugRunNSF(void);
void DebugStepNSF(void);
void DebugFrameStepNSF(void);
void DebugSetBPNSF(int address);
void DebugStepOverNSF(void);

/* Util */
void getNote(char *dest,int freq);


/* Setting */
void N163SetOldMode(int flag);

/* in dasm6502.c */
int len6502(int op);
void dasm6502(char *dest,unsigned char *mem,int pc);

/* Log */
void OpenLogNSF(const char *filename);
void CloseLogNSF(void);

void CreateNLG_NSF(const char *filename);
void CloseNLG_NSF();


#endif