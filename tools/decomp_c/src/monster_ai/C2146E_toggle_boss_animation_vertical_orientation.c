#include "som_c.h"

/* C2146E toggle_boss_animation_vertical_orientation   [class A, 12 bytes, 5 instructions]
 * Source: src/rom/toggle_boss_animation_vertical_orientation.s
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void toggle_boss_animation_vertical_orientation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0x98 + value);
    BUS16_SET(c, (db << 0x10) + 0x98 + value, value2 ^ 0x80);
    r->a = value2 ^ 0x80;
    r->x = value;
    r->z = (value2 ^ 0x80) == 0;
    r->n = (value2 ^ 0x80) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2146E, SOM_RTS, "gen", toggle_boss_animation_vertical_orientation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 12, 5)
