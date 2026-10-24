#include "som_c.h"

/* C27AAA clear_descriptor_ten_actor_and_advance_when_animation_finishes   [class A, 19 bytes, 9 instructions]
 * Source: src/rom/clear_descriptor_ten_actor_and_advance_when_animation_finishes.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void clear_descriptor_ten_actor_and_advance_when_animation_finishes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x9E + value);
    if (value2 != 0) {
        SET_A8(r, value2);
        r->x = value;
        r->c = 0;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        RETURN_RTS(c);
    }
    BUS8_SET(c, (db << 0x10) + value, 0);
    BUS8_SET(c, (db << 0x10) + 0x96 + value, 0);
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x94 + value);
    BUS8_SET(c, (db << 0x10) + 0x94 + value, (uint8_t)(value3 + 1));
    SET_A8(r, value2);
    r->x = value;
    r->z = (uint8_t)(value3 + 1) == 0;
    r->n = (uint8_t)(value3 + 1) & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27AAA, SOM_RTS, "gen", clear_descriptor_ten_actor_and_advance_when_animation_finishes, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 19, 9)
