#include "som_c.h"

/* C76549 render_eight_native_spell_class_labels_and_decimal_fields   [class B, 107 bytes, 46 instructions]
 * Source: src/rom/render_eight_native_spell_class_labels_and_decimal_fields.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void render_eight_native_spell_class_labels_and_decimal_fields(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0xA175) = 0;
    uint8_t a1 = 0;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = 0;
    for (;;) {
        BUS16_SET(c, (data_bank << 0x10) + 0xA178, x1);
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6559, 0xC75386); GUARD_JSR(c, sp_call, 0x6559); } /* append_two_native_saved_slot_text_space_tokens */
        { const uint16_t sp_call = r->sp; JSR(c, 0x655C, 0xC75386); GUARD_JSR(c, sp_call, 0x655C); } /* append_two_native_saved_slot_text_space_tokens */
        { const uint16_t sp_call = r->sp; JSR(c, 0x655F, 0xC76661); GUARD_JSR(c, sp_call, 0x655F); } /* read_native_spell_class_availability_field */
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all3 = r->a;
        uint16_t x_ret5 = r->x;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        bool carry2;
        bool overflow2;
        if (((uint8_t)a_all3 & 0x3F) == 0) {
            a_hi2 = a_all3 >> 8;
            x2 = x_ret5;
            y2 = y1;
            carry2 = carry_ret;
            overflow2 = overflow_ret;
        } else {
            RAM8(0x0000 + sp0) = y1 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)y1;
            r->a = a_all3 >> 8 << 8 | ((uint8_t)a_all3 & 0x3F);
            r->z = ((uint8_t)a_all3 & 0x3F) == 0;
            r->n = (uint8_t)a_all3 & 0x3F & 0x80;
            r->mf = 1;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x6567, 0xC76670); GUARD_JSR(c, sp_call, 0x6567); } /* append_native_packed_spell_skill_glyph_prefix */
            r->sp += 2;
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all4 = r->a;
            uint16_t x_ret6 = r->x;
            BUS8_SET(c, (data_bank << 0x10) + 0x9C00 + x_ret6, 0xC5);
            r->a = (a_all4 >> 8 << 8) | 0xC5;
            r->x = (uint16_t)(x_ret6 + 1);
            r->z = (uint16_t)(x_ret6 + 1) == 0;
            r->n = (uint16_t)(x_ret6 + 1) & 0x8000;
            r->mf = 1;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x6570, 0xC7664E); GUARD_JSR(c, sp_call, 0x6570); } /* append_native_spell_field_decimal_pair */
            r->sp += 2;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all5 = r->a;
            uint16_t x_ret7 = r->x;
            uint8_t value = RAM8(0x0000 + sp0 - 1);
            uint8_t value2 = RAM8(0x0000 + sp0);
            uint8_t value3 = BUS8_RDP(c, (data_bank << 0x10) + 0xA175);
            BUS8_SET(c, (data_bank << 0x10) + 0x9C01 + x_ret7, (uint8_t)(value3 + 0x2A));
            BUS8_SET(c, (data_bank << 0x10) + 0x9C00 + x_ret7, 0x56);
            a_hi2 = a_all5 >> 8;
            x2 = (uint16_t)(x_ret7 + 2);
            y2 = (value2 << 8) | value;
            carry2 = value3 + 0x2A > 0xFF;
            overflow2 = ((value3 ^ (uint8_t)(value3 + 0x2A)) & ((uint8_t)(value3 + 0x2A) ^ 0x2A) & 0x80) != 0;
        }
        r->a = (a_hi2 << 8) | a;
        r->x = x2;
        r->y = y2;
        r->c = carry2;
        r->v = overflow2;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6584, 0xC7538D); GUARD_JSR(c, sp_call, 0x6584); } /* append_native_saved_slot_text_line_token */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all6 = r->a;
        uint16_t x_ret8 = r->x;
        BUS16_SET(c, (db_ret << 0x10) + 0xA178, x_ret8);
        uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0xA178);
        uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 0xA175);
        BUS8_SET(c, (db_ret << 0x10) + 0xA175, (uint8_t)(value5 + 1));
        a1 = (uint8_t)(value5 + 1);
        a_hi1 = a_all6 >> 8;
        x1 = value4;
        y1 = (uint16_t)(y2 + 1);
        carry1 = (uint8_t)(value5 + 1) >= 8;
        overflow1 = overflow2;
        data_bank = db_ret;
        direct_page = dp_ret;
        if (!(a1 != 8)) break;
    }
    RAM8(0x0000 + sp0) = x1 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x1;
    BUS16_SET(c, (data_bank << 0x10) + 0xA18C, 0x7040);
    BUS16_SET(c, (data_bank << 0x10) + 0xA191, 0x0380);
    BUS16_SET(c, (data_bank << 0x10) + 0xA199, 0x01C0);
    BUS8_SET(c, (data_bank << 0x10) + 0xA171, 8);
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | 8;
    r->x = (value7 << 8) | value6;
    r->y = y1;
    r->c = carry1;
    r->z = ((value7 << 8) | value6) == 0;
    r->n = ((value7 << 8) | value6) & 0x8000;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    { const uint16_t sp_call = r->sp; JSR(c, 0x65B2, 0xC75D9A); GUARD_JSR(c, sp_call, 0x65B2); } /* render_native_saved_slot_text_rows_with_real_vblank */
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76549, SOM_RTS, "gen", render_eight_native_spell_class_labels_and_decimal_fields, 0, L_B | L_Y | L_C | L_V, 2, 1, 0, 107, 46)
