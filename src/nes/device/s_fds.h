#ifndef S_FDS_H__
#define S_FDS_H__
#ifdef __cplusplus
extern "C" {
#endif

void FDSSetState(S_STATE *state);
void FDSSetMask(char *mask);

void FDSSoundInstall(void);
void FDSSelect(unsigned type);

#ifdef __cplusplus
}
#endif
#endif /* S_FDS_H__ */
