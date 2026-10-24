#include "som_c.h"

/* C0E324 emit_packed_actor_sprite_list_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/emit_packed_actor_sprite_list_long.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void emit_packed_actor_sprite_list_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xE326, 0xC0E640); /* emit_packed_actor_sprite_list */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0E324, SOM_RTL, "gen", emit_packed_actor_sprite_list_long, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 4, 2)
