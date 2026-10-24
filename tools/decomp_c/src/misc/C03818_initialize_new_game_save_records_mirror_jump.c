#include "som_c.h"

/* C03818 initialize_new_game_save_records_mirror_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/initialize_new_game_save_records_mirror_jump.s
 * Documented in docs/ui-native-loaded-game-save-load.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: B.
 */
static void initialize_new_game_save_records_mirror_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC05745, SOM_RTL); /* initialize_new_game_save_records_preserving_context */
}
SOM_REGISTER(0xC03818, SOM_RTL, "gen", initialize_new_game_save_records_mirror_jump, 0, L_B, 1, 1, 0, 3, 1)
