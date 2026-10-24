#include "som_c.h"

/* C765B4 render_eight_native_item_slot_labels_and_percentages   [class B, 101 bytes, 43 instructions]
 * Source: src/rom/render_eight_native_item_slot_labels_and_percentages.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void render_eight_native_item_slot_labels_and_percentages(SomCtx *c)
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
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = 0;
    for (;;) {
        BUS16_SET(c, (data_bank << 0x10) + 0xA178, x1);
        r->a = (a_hi1 << 8) | a;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSR(c, 0x65C4, 0xC75386); GUARD_JSR(c, sp_call, 0x65C4); } /* append_two_native_saved_slot_text_space_tokens */
        { const uint16_t sp_call = r->sp; JSR(c, 0x65C7, 0xC75386); GUARD_JSR(c, sp_call, 0x65C7); } /* append_two_native_saved_slot_text_space_tokens */
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        uint16_t x_ret3 = r->x;
        uint8_t value = BUS8_RDP(c, (data_bank << 0x10) + 0xCC54 + y1);
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        bool carry2;
        bool overflow2;
        uint8_t data_bank2;
        uint16_t direct_page2;
        if ((uint8_t)(value + 1) == 0) {
            a_hi2 = a_all2 >> 8;
            x2 = x_ret3;
            y2 = y1;
            carry2 = carry1;
            overflow2 = overflow1;
            data_bank2 = data_bank;
            direct_page2 = direct_page;
        } else {
            RAM8(0x0000 + sp0) = y1 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)y1;
            r->a = (a_all2 >> 8 << 8) | (uint8_t)(value + 1);
            r->z = (uint8_t)(value + 1) == 0;
            r->n = (uint8_t)(value + 1) & 0x80;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x65D1, 0xC76679); GUARD_JSR(c, sp_call, 0x65D1); } /* read_packed_native_weapon_skill_nibble_and_publish_glyph */
            r->sp += 2;
            uint8_t db_ret = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all3 = r->a;
            uint16_t x_ret4 = r->x;
            BUS8_SET(c, (db_ret << 0x10) + 0x9C00 + x_ret4, 0xC5);
            r->a = (a_all3 >> 8 << 8) | 0xC5;
            r->x = (uint16_t)(x_ret4 + 1);
            r->z = (uint16_t)(x_ret4 + 1) == 0;
            r->n = (uint16_t)(x_ret4 + 1) & 0x8000;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x65DA, 0xC76619); GUARD_JSR(c, sp_call, 0x65DA); } /* append_native_spell_percentage_from_actor_skill_field */
            r->sp += 2;
            if (r->xf != 0) { c->fail = 3; return; }
            uint8_t value2 = RAM8(0x0000 + sp0 - 1);
            uint8_t value3 = RAM8(0x0000 + sp0);
            r->y = (value3 << 8) | value2;
            r->z = ((value3 << 8) | value2) == 0;
            r->n = ((value3 << 8) | value2) & 0x8000;
            { const uint16_t sp_call = r->sp; JSL(c, 0x65DF, 0xC06426); GUARD_JSL(c, sp_call, 0x65DF); } /* jump_native_item_slot_description_index_api */
            uint16_t dp_ret3 = r->dp;
            uint8_t db_ret3 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all5 = r->a;
            uint16_t x_ret6 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            BUS8_SET(c, (db_ret3 << 0x10) + 0x9C01 + x_ret6, (uint8_t)a_all5);
            BUS8_SET(c, (db_ret3 << 0x10) + 0x9C00 + x_ret6, 0x55);
            a_hi2 = a_all5 >> 8;
            x2 = (uint16_t)(x_ret6 + 2);
            y2 = y_ret2;
            carry2 = carry_ret3;
            overflow2 = overflow_ret3;
            data_bank2 = db_ret3;
            direct_page2 = dp_ret3;
        }
        r->a = (a_hi2 << 8) | a;
        r->x = x2;
        r->y = y2;
        r->c = carry2;
        r->v = overflow2;
        r->db = data_bank2;
        r->dp = direct_page2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x65EC, 0xC7538D); GUARD_JSR(c, sp_call, 0x65EC); } /* append_native_saved_slot_text_line_token */
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all6 = r->a;
        uint16_t x_ret7 = r->x;
        BUS16_SET(c, (db_ret4 << 0x10) + 0xA178, x_ret7);
        uint8_t value4 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA175);
        BUS8_SET(c, (db_ret4 << 0x10) + 0xA175, (uint8_t)(value4 + 1));
        a_hi1 = a_all6 >> 8;
        x1 = x_ret7;
        y1 = (uint16_t)(y2 + 1);
        carry1 = (uint8_t)(value4 + 1) >= 8;
        overflow1 = overflow2;
        data_bank = db_ret4;
        direct_page = dp_ret4;
        if (!((uint8_t)(value4 + 1) != 8)) break;
    }
    RAM8(0x0000 + sp0) = x1 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x1;
    BUS16_SET(c, (data_bank << 0x10) + 0xA18C, 0x7040);
    BUS16_SET(c, (data_bank << 0x10) + 0xA191, 0x0380);
    BUS16_SET(c, (data_bank << 0x10) + 0xA199, 0x01C0);
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    BUS8_SET(c, (data_bank << 0x10) + 0xA171, 8);
    r->a = (a_hi1 << 8) | 8;
    r->x = (value6 << 8) | value5;
    r->y = y1;
    r->c = carry1;
    r->z = 0;
    r->n = 0;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6617, 0xC75D9A); GUARD_JSR(c, sp_call, 0x6617); } /* render_native_saved_slot_text_rows_with_real_vblank */
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC765B4, SOM_RTS, "gen", render_eight_native_item_slot_labels_and_percentages, 0, L_B | L_Y | L_C | L_V, 2, 1, 0, 101, 43)
