#include "som_c.h"

/* C18634 load_actor_cast_secondary_graphics   [class A, 25 bytes, 10 instructions]
 * Source: src/rom/load_actor_cast_secondary_graphics.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void load_actor_cast_secondary_graphics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0014);
    RAM16_SET(0x0008, 0x40);
    RAM16_SET(0x0000, 0x0800);
    r->a = 0xD4;
    r->x = value;
    r->y = 0xBA00;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x864B, 0x01C599); GUARD_JSL(c, sp_call, 0x864B); } /* dispatch_object_graphics_plane_conversion */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC18634, SOM_RTS, "gen", load_actor_cast_secondary_graphics, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 25, 10)
