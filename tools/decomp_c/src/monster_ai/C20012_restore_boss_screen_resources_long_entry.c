#include "som_c.h"

/* C20012 restore_boss_screen_resources_long_entry   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/restore_boss_screen_resources_long_entry.s
 * Documented in docs/event-boss-screen-restore.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: XYCV.
 */
static void restore_boss_screen_resources_long_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC2019E, SOM_RTL); /* restore_complete_boss_screen_resources_and_character_tiles */
}
SOM_REGISTER(0xC20012, SOM_RTL, "gen", restore_boss_screen_resources_long_entry, 0, L_X | L_Y | L_C | L_V, 1, 0, 0, 3, 1)
