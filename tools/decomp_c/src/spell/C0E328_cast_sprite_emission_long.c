#include "som_c.h"

/* C0E328 cast_sprite_emission_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/cast_sprite_emission_long.s
 * Documented in docs/actor-cast-sprite-publication.md
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void cast_sprite_emission_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xE32A, 0xC0E32C); /* emit_cast_sprite_workspace */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0E328, SOM_RTL, "gen", cast_sprite_emission_long, 0, L_B | L_X | L_Y | L_C | L_V, 1, -1, 0, 4, 2)
