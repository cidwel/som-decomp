#include "som_c.h"

/* C12E80 activate_native_entity_sprite_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/activate_native_entity_sprite_long.s
 * Documented in docs/event-dialogue-scroll.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$01D7.  Callers read: XYCV.
 */
static void activate_native_entity_sprite_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01D7) { c->fail = 3; return; }
    JSR(c, 0x2E82, 0xC1402F); /* activate_spell_entity_sprite_instance */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12E80, SOM_RTL, "gen", activate_native_entity_sprite_long, 0, L_X | L_Y | L_C | L_V, 1, 0, 0, 4, 2)
