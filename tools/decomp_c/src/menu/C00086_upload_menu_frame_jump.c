#include "som_c.h"

/* C00086 upload_menu_frame_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/upload_menu_frame_jump.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: CV.
 */
static void upload_menu_frame_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC01BF7, SOM_RTL); /* upload_complete_menu_frame */
}
SOM_REGISTER(0xC00086, SOM_RTL, "gen", upload_menu_frame_jump, 0, L_C | L_V, 1, 1, -1, 3, 1)
