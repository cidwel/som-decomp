#include "som_c.h"

/* C2773E advance_descriptor_ten_global_axis_origins_by_velocity   [class A, 21 bytes, 9 instructions]
 * Source: src/rom/advance_descriptor_ten_global_axis_origins_by_velocity.s
 * Documented in docs/boss-descriptor-axis-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXY.
 */
static void advance_descriptor_ten_global_axis_origins_by_velocity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0358, (uint16_t)(RAM16(0x0358) + RAM16(0x003C + x)));
    uint16_t value3 = RAM16(0x035C);
    uint16_t value4 = RAM16(0x0040 + x);
    RAM16_SET(0x035C, (uint16_t)(value3 + value4));
    r->a = (uint16_t)(value3 + value4);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2773E, SOM_RTS, "gen", advance_descriptor_ten_global_axis_origins_by_velocity, 0, L_B | L_X | L_Y, 1, 0, 0, 21, 9)
