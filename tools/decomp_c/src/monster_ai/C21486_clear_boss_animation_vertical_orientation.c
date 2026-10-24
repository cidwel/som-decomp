#include "som_c.h"

/* C21486 clear_boss_animation_vertical_orientation   [class A, 12 bytes, 5 instructions]
 * Source: src/rom/clear_boss_animation_vertical_orientation.s
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void clear_boss_animation_vertical_orientation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0x98 + value);
    BUS16_SET(c, (db << 0x10) + 0x98 + value, value2 & 0xFF7F);
    r->a = value2 & 0xFF7F;
    r->x = value;
    r->z = (value2 & 0xFF7F) == 0;
    r->n = value2 & 0xFF7F & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21486, SOM_RTS, "gen", clear_boss_animation_vertical_orientation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 12, 5)
