#include "som_c.h"

/* C20CEA reset_boss_object_pool_through_dma   [class D, 104 bytes, 35 instructions]
 * Source: src/rom/reset_boss_object_pool_through_dma.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void reset_boss_object_pool_through_dma(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    BUS16_SET(c, 0x002181, 0xE600);
    BUS16_SET(c, 0x004372, 0x0D52);
    BUS16_SET(c, 0x004375, 0x1200);
    BUS8_SET(c, 0x002183, 0);
    BUS8_SET(c, 0x004370, 8);
    BUS8_SET(c, 0x004371, 0x80);
    BUS8_SET(c, 0x004374, 0xC2);
    BUS8_SET(c, 0x00420B, 0x80);
    BUS16_SET(c, 0x002181, 0x0800);
    BUS16_SET(c, 0x004375, 0x0220);
    BUS8_SET(c, 0x00420B, 0x80);
    BUS16_SET(c, 0x002181, 0x0E60);
    BUS16_SET(c, 0x004375, 0x0200);
    BUS8_SET(c, 0x00420B, 0x80);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20CEA, SOM_RTS, "gen", reset_boss_object_pool_through_dma, 0, 0, 1, 0, 0, 104, 35)
