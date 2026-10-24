#include "som_c.h"

/* C20009 upload_boss_frame_entry   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/upload_boss_frame_entry.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void upload_boss_frame_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC20266, SOM_RTL); /* upload_complete_boss_frame */
}
SOM_REGISTER(0xC20009, SOM_RTL, "gen", upload_boss_frame_entry, 0, 0, 1, 0, 0, 3, 1)
