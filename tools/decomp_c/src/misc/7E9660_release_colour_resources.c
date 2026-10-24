#include "som_c.h"

/* 7E9660 release_colour_resources   [class B, 21 bytes, 11 instructions]
 * Source: src/boot/release_colour_resources.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$0500.  Callers read: nothing.
 */
static void release_colour_resources(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x0500) { c->fail = 3; return; }
    r->sp -= 3;
    JSR(c, 0x9668, 0x7E994D); /* release_low_colour_scene_template */
    r->sp += 3;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x966B, 0x7E8363); /* release_auxiliary_graphics_buffers */
    r->sp += 3;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x966E, 0x7EA07B); /* release_colour_tree */
    r->sp += 3;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 3;
    JSR(c, 0x9671, 0x7EBF10); /* release_colour_scene */
    r->sp += 3;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9660, SOM_RTS, "gen", release_colour_resources, 0, 0, 3, 1, 0, 21, 11)
