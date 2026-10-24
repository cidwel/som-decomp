#include "som_c.h"

/* C29158 advance_native7f_fractional_y_and_subtract_gravity   [class A, 39 bytes, 15 instructions]
 * Source: src/rom/advance_native7f_fractional_y_and_subtract_gravity.s
 * Documented in docs/boss-native7f-entrance-chain.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void advance_native7f_fractional_y_and_subtract_gravity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0x30 + x);
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0x3E + x);
    BUS16_SET(c, (db << 0x10) + 0x30 + x, (uint16_t)(value + value2));
    uint16_t value3 = BUS16_RDP(c, (db << 0x10) + 0x32 + x);
    uint16_t value4 = BUS16_RDP(c, (db << 0x10) + 0x40 + x);
    BUS16_SET(c, (db << 0x10) + 0x32 + x, (uint16_t)(value3 + value4 + (value + value2 > 0xFFFF)));
    uint16_t value5 = BUS16_RDP(c, (db << 0x10) + 0x3E + x);
    BUS16_SET(c, (db << 0x10) + 0x3E + x, (uint16_t)(value5 - 0x0100));
    uint16_t value6 = BUS16_RDP(c, (db << 0x10) + 0x40 + x);
    BUS16_SET(c, (db << 0x10) + 0x40 + x, (uint16_t)(value6 - (value5 >= 0x0100 ^ 1)));
    r->a = (uint16_t)(value6 - (value5 >= 0x0100 ^ 1));
    r->c = value6 >= (value5 >= 0x0100 ^ 1);
    r->z = (uint16_t)(value6 - (value5 >= 0x0100 ^ 1)) == 0;
    r->n = (uint16_t)(value6 - (value5 >= 0x0100 ^ 1)) & 0x8000;
    r->v = (value6 & (value6 ^ (uint16_t)(value6 - (value5 >= 0x0100 ^ 1))) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29158, SOM_RTS, "gen", advance_native7f_fractional_y_and_subtract_gravity, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 39, 15)
