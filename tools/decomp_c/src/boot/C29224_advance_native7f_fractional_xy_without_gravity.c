#include "som_c.h"

/* C29224 advance_native7f_fractional_xy_without_gravity   [class A, 39 bytes, 15 instructions]
 * Source: src/rom/advance_native7f_fractional_xy_without_gravity.s
 * Documented in docs/boss-native7f-entrance-chain.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void advance_native7f_fractional_xy_without_gravity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x29 + x);
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x3A + x);
    BUS8_SET(c, (db << 0x10) + 0x29 + x, (uint8_t)(value + value2));
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x2B + x);
    uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0x3C + x);
    BUS8_SET(c, (db << 0x10) + 0x2B + x, (uint8_t)(value3 + value4 + (value + value2 > 0xFF)));
    uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0x30 + x);
    uint8_t value6 = BUS8_RDP(c, (db << 0x10) + 0x3E + x);
    BUS8_SET(c, (db << 0x10) + 0x30 + x, (uint8_t)(value5 + value6));
    uint8_t value7 = BUS8_RDP(c, (db << 0x10) + 0x32 + x);
    uint8_t value8 = BUS8_RDP(c, (db << 0x10) + 0x40 + x);
    BUS8_SET(c, (db << 0x10) + 0x32 + x, (uint8_t)(value7 + value8 + (value5 + value6 > 0xFF)));
    SET_A8(r, (uint8_t)(value7 + value8 + (value5 + value6 > 0xFF)));
    r->c = value7 + value8 + (value5 + value6 > 0xFF) > 0xFF;
    r->z = (uint8_t)(value7 + value8 + (value5 + value6 > 0xFF)) == 0;
    r->n = (uint8_t)(value7 + value8 + (value5 + value6 > 0xFF)) & 0x80;
    r->v = ((value7 ^ (uint8_t)(value7 + value8 + (value5 + value6 > 0xFF))) & (value8 ^ (uint8_t)(value7 + value8 + (value5 + value6 > 0xFF))) & 0x80) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29224, SOM_RTS, "gen", advance_native7f_fractional_xy_without_gravity, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 39, 15)
