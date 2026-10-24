#include "som_c.h"

/* C00006 upload_menu_frame_entry   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/upload_menu_frame_entry.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: CV.
 */
static void upload_menu_frame_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC00086, SOM_RTL); /* upload_menu_frame_jump */
}
SOM_REGISTER(0xC00006, SOM_RTL, "gen", upload_menu_frame_entry, 0, L_C | L_V, 1, 1, -1, 3, 1)
