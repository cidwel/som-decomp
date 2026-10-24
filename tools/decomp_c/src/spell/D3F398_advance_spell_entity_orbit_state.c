#include "som_c.h"

/* D3F398 advance_spell_entity_orbit_state   [class B, 228 bytes, 106 instructions]
 * Source: src/rom/advance_spell_entity_orbit_state.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: CV.
 */
static void advance_spell_entity_orbit_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x13) + 0x8 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_f3e2 = 0;
    uint8_t a_hi_f3e2 = 0;
    uint16_t x_f3e2 = 0;
    uint16_t y_f3e2 = 0;
    uint16_t direct_page_f3e2 = 0;
    uint8_t data_bank_f3e2 = 0;
    uint8_t a_f3dc = 0;
    uint8_t a_hi_f3dc = 0;
    uint16_t x_f3dc = 0;
    uint16_t y_f3dc = 0;
    uint16_t direct_page_f3dc = 0;
    uint8_t data_bank_f3dc = 0;
    uint8_t a_f3dc2 = 0;
    uint8_t a_hi_f3dc2 = 0;
    uint8_t x_f3dc2 = 0;
    uint8_t y_f3dc2 = 0;
    uint16_t direct_page_f3dc2 = 0;
    uint8_t data_bank_f3dc2 = 0;
    uint16_t direct_page_f473 = 0;
    uint8_t data_bank_f473 = 0;
    uint8_t a_f3e22 = 0;
    uint8_t a_hi_f3e22 = 0;
    uint8_t x_f3e22 = 0;
    uint8_t y_f3e22 = 0;
    uint16_t direct_page_f3e22 = 0;
    uint8_t data_bank_f3e22 = 0;
    uint16_t direct_page_f4732 = 0;
    uint8_t data_bank_f4732 = 0;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x13), x);
    RAM16_SET(0x00E8 + x, 5);
    uint16_t value = RAM16(0x00EA + x);
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 0x13), value);
    if ((uint16_t)(value + 1) < 8) {
        a_f3e2 = (uint8_t)(value + 1);
        a_hi_f3e2 = (uint16_t)(value + 1) >> 8;
        x_f3e2 = x;
        y_f3e2 = y;
        direct_page_f3e2 = (uint16_t)(sp0 - 0x13);
        data_bank_f3e2 = 0x7E;
        goto shared_F3E2;
    }
    uint16_t value2 = RAM16(0x00EC + x);
    if ((uint16_t)(value2 + 1) < 3) {
        a_f3dc = (uint8_t)(value2 + 1);
        a_hi_f3dc = (uint16_t)(value2 + 1) >> 8;
        x_f3dc = x;
        y_f3dc = y;
        direct_page_f3dc = (uint16_t)(sp0 - 0x13);
        data_bank_f3dc = 0x7E;
        goto shared_F3DC;
    }
    r->a = (RAM8(0x00E2 + x) << 8) | 0x49;
    r->c = (uint16_t)(value2 + 1) >= 3;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 0x10) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x13)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 0x13);
    r->sp -= 19;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF3CC, 0xC12EBD); GUARD_JSL(c, sp_call, 0xF3CC); } /* send_spell_entity_positional_sound_long */
    r->sp += 19;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 7));
        uint16_t value5 = BUS16_RDP(c, (db_ret << 0x10) + 0xE6 + value4);
        BUS16_SET(c, (db_ret << 0x10) + 0xE6 + value4, (uint16_t)((value5 ^ 0xFFFF) + 1));
        a_f3dc2 = 0;
        a_hi_f3dc2 = 0;
        x_f3dc2 = value4;
        y_f3dc2 = (uint8_t)y_ret;
        direct_page_f3dc2 = dp_ret;
        data_bank_f3dc2 = db_ret;
        goto shared_F3DC_1;
    } else {
        uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 7));
        uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0xE6 + value6);
        BUS16_SET(c, (db_ret << 0x10) + 0xE6 + value6, (uint16_t)((value7 ^ 0xFFFF) + 1));
        a_f3dc = 0;
        a_hi_f3dc = 0;
        x_f3dc = value6;
        y_f3dc = y_ret;
        direct_page_f3dc = dp_ret;
        data_bank_f3dc = db_ret;
        goto shared_F3DC;
    }
    shared_F3E2:;
    BUS16_SET(c, (data_bank_f3e2 << 0x10) + 0xEA + x_f3e2, (a_hi_f3e2 << 8) | a_f3e2);
    uint16_t value8 = BUS16_RDP(c, (data_bank_f3e2 << 0x10) + 0xEC + x_f3e2);
    if (value8 < 2) {
        uint16_t value9 = BUS16_RDP(c, (data_bank_f3e2 << 0x10) + 0xE4 + x_f3e2);
        BUS16_SET(c, (uint16_t)(direct_page_f3e2 + 9), value9);
        uint16_t value10 = BUS16_RDP(c, (data_bank_f3e2 << 0x10) + 0xE6 + x_f3e2);
        BUS16_SET(c, (data_bank_f3e2 << 0x10) + 0xE4 + x_f3e2, (uint16_t)(value9 + value10));
        uint16_t value11 = BUS16_RDP(c, (data_bank_f3e2 << 0x10) + 0xE0 + x_f3e2);
        BUS16_SET(c, (uint16_t)(direct_page_f3e2 + 0x0D), value11);
        uint16_t value12 = BUS16_RDP(c, (data_bank_f3e2 << 0x10) + 0xE2 + x_f3e2);
        BUS16_SET(c, (uint16_t)(direct_page_f3e2 + 0x0B), value12);
        uint8_t value13 = BUS8_RDP(c, (uint16_t)(direct_page_f3e2 + 3));
        BUS16_SET(c, 0x004202, (0x1C << 8) | value13);
        RAM8(0x0000 + sp0 - 0x13) = 0x1C;
        RAM8(0x0000 + sp0 - 0x14) = (uint8_t)((0x1C << 8) | value13);
        uint16_t value14 = BUS16(c, 0x004216);
        uint16_t value15 = BUS16_RDP(c, (uint16_t)(direct_page_f3e2 + 7));
        BUS16_SET(c, (uint16_t)(direct_page_f3e2 + 3), (uint16_t)(value14 + value15));
        BUS16_SET(c, (uint16_t)(direct_page_f3e2 + 5), (uint16_t)((uint16_t)(value14 + value15) + 0x0C));
        BUS16_SET(c, (data_bank_f3e2 << 0x10) + 0x18 + (uint16_t)(value14 + value15), 1);
        BUS16_SET(c, (data_bank_f3e2 << 0x10) + 0x1A + (uint16_t)(value14 + value15), 0);
        uint16_t value16 = BUS16_RDP(c, (uint16_t)(direct_page_f3e2 + 9));
        r->a = value16;
        r->x = 0x30;
        r->y = y_f3e2;
        r->c = (uint16_t)(value14 + value15) + 0x0C > 0xFFFF;
        r->z = value16 == 0;
        r->n = value16 & 0x8000;
        r->v = (((uint16_t)(value14 + value15) ^ (uint16_t)((uint16_t)(value14 + value15) + 0x0C)) & ((uint16_t)((uint16_t)(value14 + value15) + 0x0C) ^ 0x0C) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank_f3e2;
        r->dp = direct_page_f3e2;
        r->sp -= 19;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF437, 0xC12EC9); GUARD_JSL(c, sp_call, 0xF437); } /* scale_spell_entity_signed_angle_vector_long */
        r->sp += 19;
        uint16_t x_ret3 = r->x;
        BUS16_SET(c, (uint16_t)(direct_page_f3e2 + 0x0F), x_ret3);
        uint16_t value17 = BUS16_RDP(c, (uint16_t)(direct_page_f3e2 + 0x0D));
        uint16_t value18 = BUS16_RDP(c, (uint16_t)(direct_page_f3e2 + 5));
        BUS16_SET(c, (data_bank_f3e2 << 0x10) + 8 + value18, (uint16_t)((uint16_t)((x_ret3 ^ 0xFFFF) + 1) + value17));
        uint16_t value19 = BUS16_RDP(c, (uint16_t)(direct_page_f3e2 + 0x0F));
        uint16_t value20 = BUS16_RDP(c, (uint16_t)(direct_page_f3e2 + 0x0D));
        uint16_t value21 = BUS16_RDP(c, (uint16_t)(direct_page_f3e2 + 3));
        BUS16_SET(c, (data_bank_f3e2 << 0x10) + 8 + value21, (uint16_t)(value19 + value20));
        uint16_t value22 = BUS16_RDP(c, (uint16_t)(direct_page_f3e2 + 9));
        r->a = value22;
        r->x = 0x30;
        r->c = value19 + value20 > 0xFFFF;
        r->z = value22 == 0;
        r->n = value22 & 0x8000;
        r->v = ((value19 ^ (uint16_t)(value19 + value20)) & (value20 ^ (uint16_t)(value19 + value20)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 19;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF459, 0xC12ECD); GUARD_JSL(c, sp_call, 0xF459); } /* scale_spell_entity_signed_quarter_turn_vector_long */
        r->sp += 19;
        uint16_t x_ret4 = r->x;
        BUS16_SET(c, (uint16_t)(direct_page_f3e2 + 0x0F), x_ret4);
        uint16_t value23 = BUS16_RDP(c, (uint16_t)(direct_page_f3e2 + 0x0B));
        uint16_t value24 = BUS16_RDP(c, (uint16_t)(direct_page_f3e2 + 5));
        BUS16_SET(c, (data_bank_f3e2 << 0x10) + 0x0A + value24, (uint16_t)((uint16_t)((x_ret4 ^ 0xFFFF) + 1) + value23));
        uint16_t value25 = BUS16_RDP(c, (uint16_t)(direct_page_f3e2 + 0x0F));
        uint16_t value26 = BUS16_RDP(c, (uint16_t)(direct_page_f3e2 + 0x0B));
        uint16_t value27 = BUS16_RDP(c, (uint16_t)(direct_page_f3e2 + 3));
        BUS16_SET(c, (data_bank_f3e2 << 0x10) + 0x0A + value27, (uint16_t)(value25 + value26));
        direct_page_f473 = direct_page_f3e2;
        data_bank_f473 = data_bank_f3e2;
        goto shared_F473;
    }
    direct_page_f473 = direct_page_f3e2;
    data_bank_f473 = data_bank_f3e2;
    goto shared_F473;
    shared_F3DC:;
    BUS16_SET(c, (data_bank_f3dc << 0x10) + 0xEC + x_f3dc, (a_hi_f3dc << 8) | a_f3dc);
    a_f3e2 = 0;
    a_hi_f3e2 = 0;
    x_f3e2 = x_f3dc;
    y_f3e2 = y_f3dc;
    direct_page_f3e2 = direct_page_f3dc;
    data_bank_f3e2 = data_bank_f3dc;
    goto shared_F3E2;
    shared_F3DC_1:;
    BUS16_SET(c, (data_bank_f3dc2 << 0x10) + 0xEC + x_f3dc2, (a_hi_f3dc2 << 8) | a_f3dc2);
    a_f3e22 = 0;
    a_hi_f3e22 = 0;
    x_f3e22 = x_f3dc2;
    y_f3e22 = y_f3dc2;
    direct_page_f3e22 = direct_page_f3dc2;
    data_bank_f3e22 = data_bank_f3dc2;
    goto shared_F3E2_1;
    shared_F473:;
    uint8_t value28 = RAM8(0x0000 + sp0 - 2);
    uint8_t value29 = RAM8(0x0000 + sp0 - 1);
    uint8_t value30 = RAM8(0x0000 + sp0);
    r->c = value28 & 0x01;
    r->v = value28 & 0x40;
    r->mf = value28 & 0x20;
    r->xf = value28 & 0x10;
    r->db = data_bank_f473;
    r->dp = (value30 << 8) | value29;
    r->i = value28 & 0x04;
    r->d = value28 & 0x08;
    RETURN_RTS(c);
    shared_F3E2_1:;
    BUS16_SET(c, (data_bank_f3e22 << 0x10) + 0xEA + x_f3e22, (a_hi_f3e22 << 8) | a_f3e22);
    uint16_t value31 = BUS16_RDP(c, (data_bank_f3e22 << 0x10) + 0xEC + x_f3e22);
    if (value31 < 2) {
        uint16_t value32 = BUS16_RDP(c, (data_bank_f3e22 << 0x10) + 0xE4 + x_f3e22);
        BUS16_SET(c, (uint16_t)(direct_page_f3e22 + 9), value32);
        uint16_t value33 = BUS16_RDP(c, (data_bank_f3e22 << 0x10) + 0xE6 + x_f3e22);
        BUS16_SET(c, (data_bank_f3e22 << 0x10) + 0xE4 + x_f3e22, (uint16_t)(value32 + value33));
        uint16_t value34 = BUS16_RDP(c, (data_bank_f3e22 << 0x10) + 0xE0 + x_f3e22);
        BUS16_SET(c, (uint16_t)(direct_page_f3e22 + 0x0D), value34);
        uint16_t value35 = BUS16_RDP(c, (data_bank_f3e22 << 0x10) + 0xE2 + x_f3e22);
        BUS16_SET(c, (uint16_t)(direct_page_f3e22 + 0x0B), value35);
        uint8_t value36 = BUS8_RDP(c, (uint16_t)(direct_page_f3e22 + 3));
        BUS16_SET(c, 0x004202, (0x1C << 8) | value36);
        RAM8(0x0000 + sp0 - 0x13) = 0x1C;
        RAM8(0x0000 + sp0 - 0x14) = (uint8_t)((0x1C << 8) | value36);
        uint16_t value37 = BUS16(c, 0x004216);
        uint16_t value38 = BUS16_RDP(c, (uint16_t)(direct_page_f3e22 + 7));
        BUS16_SET(c, (uint16_t)(direct_page_f3e22 + 3), (uint16_t)(value37 + value38));
        BUS16_SET(c, (uint16_t)(direct_page_f3e22 + 5), (uint16_t)((uint16_t)(value37 + value38) + 0x0C));
        BUS16_SET(c, (data_bank_f3e22 << 0x10) + 0x18 + (uint8_t)(value37 + value38), 1);
        BUS16_SET(c, (data_bank_f3e22 << 0x10) + 0x1A + (uint8_t)(value37 + value38), 0);
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    }
    direct_page_f4732 = direct_page_f3e22;
    data_bank_f4732 = data_bank_f3e22;
    goto shared_F473_1;
    shared_F473_1:;
    uint8_t value39 = RAM8(0x0000 + sp0 - 2);
    uint8_t value40 = RAM8(0x0000 + sp0 - 1);
    uint8_t value41 = RAM8(0x0000 + sp0);
    r->c = value39 & 0x01;
    r->v = value39 & 0x40;
    r->mf = value39 & 0x20;
    r->xf = value39 & 0x10;
    r->db = data_bank_f4732;
    r->dp = (value41 << 8) | value40;
    r->i = value39 & 0x04;
    r->d = value39 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3F398, SOM_RTS, "gen", advance_spell_entity_orbit_state, 0, L_C | L_V, 21, 1, 0, 228, 106)
