#ifndef ccsprt_appvar_include_file
#define ccsprt_appvar_include_file

#ifdef __cplusplus
extern "C" {
#endif

#define sizeof_global_palette 26
#define global_palette (ccsprt_appvar[0])
#define sprites_palette_offset 0
#define mouse1_width 11
#define mouse1_height 16
#define ccsprt_sprites_mouse1_compressed_index 1
#define mouse1_compressed ccsprt_appvar[1]
#define perfectCookie_width 95
#define perfectCookie_height 95
#define ccsprt_sprites_perfectCookie_compressed_index 2
#define perfectCookie_compressed ccsprt_appvar[2]
#define ccsprt_entries_num 3
extern unsigned char *ccsprt_appvar[3];
unsigned char ccsprt_init(void);

#ifdef __cplusplus
}
#endif

#endif
