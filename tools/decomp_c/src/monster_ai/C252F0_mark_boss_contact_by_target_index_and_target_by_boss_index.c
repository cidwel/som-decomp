#include "som_c.h"

/* C252F0 mark_boss_contact_by_target_index_and_target_by_boss_index   [class B, 57 bytes, 28 instructions]
 * Source: src/rom/mark_boss_contact_by_target_index_and_target_by_boss_index.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void mark_boss_contact_by_target_index_and_target_by_boss_index(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0xA9 + x);
    uint8_t value2 = BUS8(c, 0xC205F0 + ((a_hi << 8) | value));
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x59 + x);
    BUS8_SET(c, (db << 0x10) + 0x59 + x, value2 | value3);
    uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value5 = BUS16_RDP(c, (db << 0x10) + 0xA9 + value4);
    uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint8_t value7 = BUS8(c, 0xC205F0 + (((uint8_t)((uint16_t)(value6 - 0xE600) >> 1) << 8) | ((uint16_t)(value6 - 0xE600) >> 1 >> 8)));
    uint8_t value8 = BUS8_RDP(c, (db << 0x10) + 0x5A + (uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000));
    BUS8_SET(c, (db << 0x10) + 0x5A + (uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000), value7 | value8);
    uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    r->a = ((uint8_t)((uint16_t)(value6 - 0xE600) >> 1) << 8) | (value7 | value8);
    r->x = value9;
    r->y = (uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000);
    r->c = (uint16_t)(value6 - 0xE600) & 0x01;
    r->z = value9 == 0;
    r->n = value9 & 0x8000;
    r->v = ((value6 ^ 0xE600) & (value6 ^ (uint16_t)(value6 - 0xE600)) & 0x8000) != 0;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC252F0, SOM_RTS, "gen", mark_boss_contact_by_target_index_and_target_by_boss_index, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 57, 28)
