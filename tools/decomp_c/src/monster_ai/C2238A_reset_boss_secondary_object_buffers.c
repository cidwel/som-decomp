#include "som_c.h"

/* C2238A reset_boss_secondary_object_buffers   [class D, 80 bytes, 27 instructions]
 * Source: src/rom/reset_boss_secondary_object_buffers.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void reset_boss_secondary_object_buffers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    BUS16_SET(c, 0x002181, 0xEC00);
    BUS16_SET(c, 0x004372, 0x0D52);
    BUS16_SET(c, 0x004375, 0x1080);
    BUS8_SET(c, 0x002183, 0);
    BUS8_SET(c, 0x004370, 8);
    BUS8_SET(c, 0x004371, 0x80);
    BUS8_SET(c, 0x004374, 0xC2);
    BUS8_SET(c, 0x00420B, 0x80);
    BUS16_SET(c, 0x002181, 0x0E60);
    BUS16_SET(c, 0x004375, 0x0200);
    BUS8_SET(c, 0x00420B, 0x80);
    r->a = 0x0280;
    r->z = 0;
    r->n = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2238A, SOM_RTS, "gen", reset_boss_secondary_object_buffers, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 80, 27)
