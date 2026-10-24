#include "som_c.h"

/* C12E84 publish_spell_frame_projection_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/publish_spell_frame_projection_long.s
 * Documented in docs/map-oam-spell-frames.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$01E4.  Callers read: Y.
 */
static void publish_spell_frame_projection_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01E4) { c->fail = 3; return; }
    JSR(c, 0x2E86, 0xC14118); /* publish_spell_entity_individual_sprite_projection */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12E84, SOM_RTL, "gen", publish_spell_frame_projection_long, 0, L_Y, 1, 0, 0, 4, 2)
