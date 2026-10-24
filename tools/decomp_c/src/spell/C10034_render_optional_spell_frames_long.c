#include "som_c.h"

/* C10034 render_optional_spell_frames_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/render_optional_spell_frames_long.s
 * Documented in docs/map-oam-spell-frames.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void render_optional_spell_frames_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x0036, 0xC14892); /* render_optional_spell_frames */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC10034, SOM_RTL, "gen", render_optional_spell_frames_long, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 4, 2)
