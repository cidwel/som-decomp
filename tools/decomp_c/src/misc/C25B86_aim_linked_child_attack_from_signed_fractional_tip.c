#include "som_c.h"

/* C25B86 aim_linked_child_attack_from_signed_fractional_tip   [class B, 133 bytes, 69 instructions]
 * Source: src/rom/aim_linked_child_attack_from_signed_fractional_tip.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void aim_linked_child_attack_from_signed_fractional_tip(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00A9 + x);
    RAM16_SET(0x0246, RAM16(0x0002 + (uint16_t)((((uint8_t)(value << 1) << 8) | ((uint16_t)(value << 1) >> 8)) + 0xE000)));
    RAM16_SET(0x024E, RAM16(0x0004 + (uint16_t)((((uint8_t)(value << 1) << 8) | ((uint16_t)(value << 1) >> 8)) + 0xE000)));
    uint16_t value4 = RAM16(0x00B8 + x);
    RAM8(0x0000 + sp0) = ((((value4 >> 0x0F << 7) | (((((((uint8_t)(value << 1) << 8) | ((uint16_t)(value << 1) >> 8)) ^ (uint16_t)((((uint8_t)(value << 1) << 8) | ((uint16_t)(value << 1) >> 8)) + 0xE000)) & ((uint16_t)((((uint8_t)(value << 1) << 8) | ((uint16_t)(value << 1) >> 8)) + 0xE000) ^ 0xE000) & 0x8000) != 0) << 6)) | (d_entry << 3)) | (i_entry << 2)) | ((value4 == 0) << 1) | (((uint8_t)(value << 1) << 8) | ((uint16_t)(value << 1) >> 8)) + 0xE000 > 0xFFFF;
    uint8_t a1;
    uint8_t a_hi1;
    if (!(value4 & 0x8000)) {
        a1 = (((uint8_t)value4 << 8) | (value4 >> 8)) & 0xFF;
        a_hi1 = 0;
    } else {
        a1 = (uint8_t)(((((uint8_t)value4 << 8) | (value4 >> 8)) & 0xFF) | 0xFF00);
        a_hi1 = (((((uint8_t)value4 << 8) | (value4 >> 8)) & 0xFF) | 0xFF00) >> 8;
    }
    uint16_t value5 = RAM16(0x002B + x);
    RAM16_SET(0x0256, (uint16_t)(((a_hi1 << 8) | a1) + value5));
    uint16_t value6 = RAM16(0x00BA + x);
    RAM8(0x0000 + sp0) = ((((value6 >> 0x0F << 7) | ((((((a_hi1 << 8) | a1) ^ (uint16_t)(((a_hi1 << 8) | a1) + value5)) & (value5 ^ (uint16_t)(((a_hi1 << 8) | a1) + value5)) & 0x8000) != 0) << 6)) | (d_entry << 3)) | (i_entry << 2)) | ((value6 == 0) << 1) | ((a_hi1 << 8) | a1) + value5 > 0xFFFF;
    uint8_t a2;
    uint8_t a_hi2;
    if (!(value6 & 0x8000)) {
        a2 = (((uint8_t)value6 << 8) | (value6 >> 8)) & 0xFF;
        a_hi2 = 0;
    } else {
        a2 = (uint8_t)(((((uint8_t)value6 << 8) | (value6 >> 8)) & 0xFF) | 0xFF00);
        a_hi2 = (((((uint8_t)value6 << 8) | (value6 >> 8)) & 0xFF) | 0xFF00) >> 8;
    }
    uint16_t value7 = RAM16(0x0032 + x);
    RAM16_SET(0x025E, (uint16_t)(((a_hi2 << 8) | a2) + value7));
    r->a = (uint16_t)(((a_hi2 << 8) | a2) + value7);
    r->y = (uint16_t)((((uint8_t)(value << 1) << 8) | ((uint16_t)(value << 1) >> 8)) + 0xE000);
    r->c = ((a_hi2 << 8) | a2) + value7 > 0xFFFF;
    r->z = (uint16_t)(((a_hi2 << 8) | a2) + value7) == 0;
    r->n = (uint16_t)(((a_hi2 << 8) | a2) + value7) & 0x8000;
    r->v = ((((a_hi2 << 8) | a2) ^ (uint16_t)(((a_hi2 << 8) | a2) + value7)) & (value7 ^ (uint16_t)(((a_hi2 << 8) | a2) + value7)) & 0x8000) != 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5BC4, 0xC22E77); GUARD_JSR(c, sp_call, 0x5BC4); } /* derive_fine_direction_from_coordinate_pairs */
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    RAM16_SET(0x0202, (uint16_t)(a_all << 2));
    r->a = (uint16_t)(a_all << 2);
    r->c = (uint16_t)(a_all << 1) & 0x8000;
    r->z = (uint16_t)(a_all << 2) == 0;
    r->n = (uint16_t)(a_all << 2) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5BCB, 0xC22A59); GUARD_JSR(c, sp_call, 0x5BCB); } /* derive_cosine_by_adding_quarter_turn */
    uint16_t a_all2 = r->a;
    RAM8(0x0000 + sp0) = a_all2 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)a_all2;
    uint16_t value8 = RAM16(0x0287);
    RAM16_SET(0x0076 + value8, (uint16_t)(a_all2 << 3));
    uint8_t value9 = RAM8(0x0000 + sp0 - 1);
    uint8_t value10 = RAM8(0x0000 + sp0);
    RAM16_SET(0x00BC + value8, (uint16_t)((uint16_t)((((value10 << 8) | value9) ^ 0xFFFF) + 1) << 2));
    uint16_t value11 = RAM16(0x0202);
    r->a = value11;
    r->x = value8;
    r->c = (uint16_t)((uint16_t)((((value10 << 8) | value9) ^ 0xFFFF) + 1) << 1) & 0x8000;
    r->z = value11 == 0;
    r->n = value11 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5BE3, 0xC22A60); GUARD_JSR(c, sp_call, 0x5BE3); } /* mask_angle_and_derive_native_sine */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    uint16_t a_all3 = r->a;
    if (x_ret3) {
        uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        RAM8(0x0000 + sp0) = a_all3 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)a_all3;
        BUS16_SET(c, (db_ret << 0x10) + 0x78 + value12, (uint16_t)(a_all3 << 3));
        uint8_t value13 = RAM8(0x0000 + sp0 - 1);
        uint8_t value14 = RAM8(0x0000 + sp0);
        BUS16_SET(c, (db_ret << 0x10) + 0xBE + value12, (uint16_t)((uint16_t)((((value14 << 8) | value13) ^ 0xFFFF) + 1) << 2));
        BUS16_SET(c, (db_ret << 0x10) + 0x90 + value12, 0x5C0B);
        BUS16_SET(c, (db_ret << 0x10) + 0x8E + value12, 0x5C06);
        BUS16_SET(c, (db_ret << 0x10) + 0x96 + value12, 0);
        r->a = 0x5C06;
        r->x = value12;
        r->y = (uint8_t)y_ret;
        r->c = (uint16_t)((uint16_t)((((value14 << 8) | value13) ^ 0xFFFF) + 1) << 1) & 0x8000;
        r->z = 0;
        r->n = 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5C08, 0xC25D87); GUARD_JSR(c, sp_call, 0x5C08); } /* select_target_and_heading_from_linked_child_fractional_tip */
        r->c = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        RAM8(0x0000 + sp0) = a_all3 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)a_all3;
        BUS16_SET(c, (db_ret << 0x10) + 0x78 + value15, (uint16_t)(a_all3 << 3));
        uint8_t value16 = RAM8(0x0000 + sp0 - 1);
        uint8_t value17 = RAM8(0x0000 + sp0);
        BUS16_SET(c, (db_ret << 0x10) + 0xBE + value15, (uint16_t)((uint16_t)((((value17 << 8) | value16) ^ 0xFFFF) + 1) << 2));
        BUS16_SET(c, (db_ret << 0x10) + 0x90 + value15, 0x5C0B);
        BUS16_SET(c, (db_ret << 0x10) + 0x8E + value15, 0x5C06);
        BUS16_SET(c, (db_ret << 0x10) + 0x96 + value15, 0);
        r->a = 0x5C06;
        r->x = value15;
        r->c = (uint16_t)((uint16_t)((((value17 << 8) | value16) ^ 0xFFFF) + 1) << 1) & 0x8000;
        r->z = 0;
        r->n = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5C08, 0xC25D87); GUARD_JSR(c, sp_call, 0x5C08); } /* select_target_and_heading_from_linked_child_fractional_tip */
        r->c = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC25B86, SOM_RTS, "gen", aim_linked_child_attack_from_signed_fractional_tip, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 133, 69)
