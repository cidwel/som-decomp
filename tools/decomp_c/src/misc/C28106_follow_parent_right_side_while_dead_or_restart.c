#include "som_c.h"

/* C28106 follow_parent_right_side_while_dead_or_restart   [class B, 48 bytes, 21 instructions]
 * Source: src/rom/follow_parent_right_side_while_dead_or_restart.s
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void follow_parent_right_side_while_dead_or_restart(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0xB0 + value);
    uint16_t value3 = BUS16_RDP(c, (db << 0x10) + 0x2B + value2);
    BUS16_SET(c, (db << 0x10) + 0x2B + value, (uint16_t)(value3 + 0x40));
    uint16_t value4 = BUS16_RDP(c, (db << 0x10) + 0x32 + value2);
    BUS16_SET(c, (db << 0x10) + 0x32 + value, (uint16_t)(value4 + 0x10));
    uint16_t value5 = BUS16_RDP(c, (db << 0x10) + 0x94 + value2);
    if (value5 == 6) {
        r->a = value5;
        r->x = value;
        r->y = value2;
        r->c = 1;
        r->z = value5 == 6;
        r->n = (uint16_t)(value5 - 6) & 0x8000;
        r->v = ((value4 ^ (uint16_t)(value4 + 0x10)) & ((uint16_t)(value4 + 0x10) ^ 0x10) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint16_t value6 = BUS16_RDP(c, (db << 0x10) + 0x0190 + value);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value6 & 0x8000) {
        a1 = (uint8_t)value6;
        a_hi1 = value6 >> 8;
        zero1 = value6 == 0;
        negative1 = value6 & 0x8000;
    } else {
        BUS16_SET(c, (db << 0x10) + 0x94 + value, 1);
        a1 = 1;
        a_hi1 = 0;
        zero1 = 0;
        negative1 = 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = value;
    r->y = value2;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = ((value4 ^ (uint16_t)(value4 + 0x10)) & ((uint16_t)(value4 + 0x10) ^ 0x10) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28106, SOM_RTS, "gen", follow_parent_right_side_while_dead_or_restart, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 48, 21)
