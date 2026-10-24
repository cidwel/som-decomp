#include "som_c.h"

/* C25DEF derive_linked_child_random_wave_velocity_toward_variant_origin   [class B, 85 bytes, 39 instructions]
 * Source: src/rom/derive_linked_child_random_wave_velocity_toward_variant_origin.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void derive_linked_child_random_wave_velocity_toward_variant_origin(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = 0x7F;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5DF4, 0xC2300B); GUARD_JSR(c, sp_call, 0x5DF4); } /* draw_boss_frame_random_number */
    uint16_t a_all = r->a;
    RAM16_SET(0x0200, (uint16_t)(a_all - 0x40));
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x007A + value);
    uint16_t value3 = BUS16(c, 0xC25A39 + (uint16_t)(value2 << 2));
    RAM16_SET(0x0246, value3);
    uint16_t value4 = BUS16(c, 0xC25A3B + (uint16_t)(value2 << 2));
    RAM16_SET(0x024E, value4);
    RAM16_SET(0x0256, RAM16(0x00B8 + value));
    uint16_t value6 = RAM16(0x00BA + value);
    RAM16_SET(0x025E, value6);
    r->a = value6;
    r->x = (uint16_t)(value2 << 2);
    r->y = value;
    r->c = (uint16_t)(value2 << 1) & 0x8000;
    r->z = value6 == 0;
    r->n = value6 & 0x8000;
    r->v = ((a_all ^ 0x40) & (a_all ^ (uint16_t)(a_all - 0x40)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5E1B, 0xC22E77); GUARD_JSR(c, sp_call, 0x5E1B); } /* derive_fine_direction_from_coordinate_pairs */
    uint16_t a_all2 = r->a;
    uint16_t value7 = RAM16(0x0200);
    uint16_t value8 = RAM16(0x0287);
    RAM16_SET(0x0200, (uint16_t)((uint16_t)(a_all2 << 2) + value7));
    r->a = (uint16_t)((uint16_t)(a_all2 << 2) + value7);
    r->x = value8;
    r->c = (uint16_t)(a_all2 << 2) + value7 > 0xFFFF;
    r->z = value8 == 0;
    r->n = value8 & 0x8000;
    r->v = (((uint16_t)(a_all2 << 2) ^ (uint16_t)((uint16_t)(a_all2 << 2) + value7)) & (value7 ^ (uint16_t)((uint16_t)(a_all2 << 2) + value7)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5E27, 0xC22A59); GUARD_JSR(c, sp_call, 0x5E27); } /* derive_cosine_by_adding_quarter_turn */
    uint16_t a_all3 = r->a;
    uint16_t value9 = RAM16(0x0287);
    RAM16_SET(0x0076 + value9, (uint16_t)(a_all3 << 1));
    uint16_t value10 = RAM16(0x0200);
    r->a = value10;
    r->x = value9;
    r->c = a_all3 & 0x8000;
    r->z = value10 == 0;
    r->n = value10 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5E32, 0xC22A60); GUARD_JSR(c, sp_call, 0x5E32); } /* mask_angle_and_derive_native_sine */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    uint16_t a_all4 = r->a;
    BUS16_SET(c, dp_ret, a_all4);
    r->a = 0x7F;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5E3A, 0xC2300B); GUARD_JSR(c, sp_call, 0x5E3A); } /* draw_boss_frame_random_number */
    uint16_t a_all5 = r->a;
    uint16_t value11 = BUS16_RDP(c, dp_ret);
    uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
    BUS16_SET(c, (db_ret << 0x10) + 0x78 + value12, (uint16_t)(a_all5 + value11));
    r->a = (uint16_t)(a_all5 + value11);
    r->x = value12;
    r->c = a_all5 + value11 > 0xFFFF;
    r->v = ((a_all5 ^ (uint16_t)(a_all5 + value11)) & (value11 ^ (uint16_t)(a_all5 + value11)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25DEF, SOM_RTS, "gen", derive_linked_child_random_wave_velocity_toward_variant_origin, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 85, 39)
