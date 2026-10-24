#include "som_c.h"

/* C014EB compose_dialogue_glyph_planes_and_publish_active_palette   [class B, 47 bytes, 17 instructions]
 * Source: src/rom/compose_dialogue_glyph_planes_and_publish_active_palette.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void compose_dialogue_glyph_planes_and_publish_active_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x1D05);
    if (value == 7) {
        r->a = (a_hi << 8) | value;
        r->c = value >= 7;
        r->z = value == 7;
        r->n = (uint8_t)(value - 7) & 0x80;
        { const uint16_t sp_call = r->sp; JSR(c, 0x14F5, 0xC0040F); GUARD_JSR(c, sp_call, 0x14F5); } /* advance_dialogue_primary_window_phase */
        RAM8(0xA15C)--;
    }
    r->a = (a_hi << 8) | value;
    r->c = value >= 7;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x14FB, 0xC0159E); GUARD_JSR(c, sp_call, 0x14FB); } /* select_dialogue_background_mask_from_style_list */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x14FE, 0xC0151A); GUARD_JSR(c, sp_call, 0x14FE); } /* compose_first_dialogue_tile_bitplane_rows */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1501, 0xC01521); GUARD_JSR(c, sp_call, 0x1501); } /* compose_second_dialogue_tile_bitplane_rows */
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret3 = r->y;
    bool overflow_ret2 = r->v;
    uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0xA15D);
    BUS8_SET(c, (db_ret << 0x10) + 0xA15D, (uint8_t)(value2 + 1));
    uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0xA162);
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    uint8_t data_bank;
    if (value3 != 1) {
        x_flag = x_ret3;
        a1 = value3;
        a_hi1 = a_all3 >> 8;
        x1 = x_ret4;
        y1 = y_ret3;
        carry1 = value3 >= 1;
        zero1 = value3 == 1;
        negative1 = (uint8_t)(value3 - 1) & 0x80;
        overflow1 = overflow_ret2;
        data_bank = db_ret;
    } else {
        r->a = (a_all3 >> 8 << 8) | value3;
        r->c = value3 >= 1;
        r->z = value3 == 1;
        r->n = (uint8_t)(value3 - 1) & 0x80;
        { const uint16_t sp_call = r->sp; JSR(c, 0x150E, 0xC00968); GUARD_JSR(c, sp_call, 0x150E); } /* publish_dialogue_style_palette_banks */
        uint8_t db_ret2 = r->db;
        bool x_ret5 = r->xf;
        uint16_t a_all4 = r->a;
        uint16_t x_ret6 = r->x;
        uint16_t y_ret4 = r->y;
        bool carry_ret4 = r->c;
        bool overflow_ret3 = r->v;
        uint8_t value4 = RAM8(0x1D04);
        RAM8(0x1D04) = value4 | 0x20;
        x_flag = x_ret5;
        a1 = value4 | 0x20;
        a_hi1 = a_all4 >> 8;
        x1 = x_ret6;
        y1 = y_ret4;
        carry1 = carry_ret4;
        zero1 = (value4 | 0x20) == 0;
        negative1 = (value4 | 0x20) & 0x80;
        overflow1 = overflow_ret3;
        data_bank = db_ret2;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = x_flag;
    r->db = data_bank;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC014EB, SOM_RTS, "gen", compose_dialogue_glyph_planes_and_publish_active_palette, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 47, 17)
