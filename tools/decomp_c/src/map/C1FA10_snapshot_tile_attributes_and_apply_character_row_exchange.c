#include "som_c.h"

/* C1FA10 snapshot_tile_attributes_and_apply_character_row_exchange   [class D, 159 bytes, 60 instructions]
 * Source: src/rom/snapshot_tile_attributes_and_apply_character_row_exchange.s
 * Entry: M=8 bit X=8 bit DB=any D=any.  Callers read: BYCV.
 */
static void snapshot_tile_attributes_and_apply_character_row_exchange(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 1)) return;
    const uint16_t dp = r->dp;
    const uint8_t db = r->db;
    BUS8_SET(c, (db << 0x10) + 0x2115, 0x80);
    BUS8_SET(c, (db << 0x10) + 0x4374, 0x7E);
    BUS16_SET(c, (db << 0x10) + 0x4370, 0x3A80);
    BUS16_SET(c, (db << 0x10) + 0x4375, 0x1000);
    BUS16_SET(c, (db << 0x10) + 0x4372, 0xF000);
    BUS16_SET(c, (db << 0x10) + 0x2116, 0x2C00);
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x213A);
    BUS8_SET(c, (db << 0x10) + 0x420B, 0x80);
    BUS16_SET(c, (db << 0x10) + 0x4375, 0x0400);
    BUS16_SET(c, (db << 0x10) + 0x4372, 0xE800);
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + 0xE2));
    uint8_t a_hi1;
    if (!(value2 & 0x8000)) {
        a_hi1 = 0x3C;
    } else {
        a_hi1 = 0x28;
    }
    BUS16_SET(c, (db << 0x10) + 0x2116, (a_hi1 << 8) | 0);
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x213A);
    BUS8_SET(c, (db << 0x10) + 0x420B, 0x80);
    BUS16_SET(c, (db << 0x10) + 0x4375, 0x0400);
    BUS16_SET(c, (db << 0x10) + 0x4372, 0xEC00);
    uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp + 0xE2));
    uint8_t a_hi2;
    if (!(value4 & 0x8000)) {
        a_hi2 = 0x28;
    } else {
        a_hi2 = 0x3C;
    }
    BUS16_SET(c, (db << 0x10) + 0x2116, (a_hi2 << 8) | 0);
    uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0x213A);
    BUS8_SET(c, (db << 0x10) + 0x420B, 0x80);
    r->a = (a_hi2 << 8) | 0x80;
    r->z = 0;
    r->n = 1;
    r->v = value4 & 0x4000;
    { const uint16_t sp_call = r->sp; JSR(c, 0xFA8C, 0xC1FAAF); GUARD_JSR(c, sp_call, 0xFA8C); } /* copy_or_swap_character_attribute_row */
    BUS16_SET(c, (db << 0x10) + 0x4370, 0x1900);
    BUS16_SET(c, (db << 0x10) + 0x4375, 0x0400);
    BUS16_SET(c, (db << 0x10) + 0x4372, 0xEC00);
    BUS16_SET(c, (db << 0x10) + 0x2116, 0x2800);
    BUS8_SET(c, (db << 0x10) + 0x420B, 0x80);
    r->a = (r->a & 0x00FF) | (0x28 << 8);
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1FA10, SOM_RTS, "gen", snapshot_tile_attributes_and_apply_character_row_exchange, 0, L_B | L_Y | L_C | L_V, 1, 1, 1, 159, 60)
