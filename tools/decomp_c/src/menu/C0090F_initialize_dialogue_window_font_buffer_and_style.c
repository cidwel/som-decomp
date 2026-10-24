#include "som_c.h"

/* C0090F initialize_dialogue_window_font_buffer_and_style   [class C, 89 bytes, 35 instructions]
 * Source: src/rom/initialize_dialogue_window_font_buffer_and_style.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void initialize_dialogue_window_font_buffer_and_style(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    RAM8(0xA16E) = 2;
    RAM16_SET(0xA19B, 0x9C00);
    RAM8(0x9400) = 0;
    r->a = 0x06FF;
    r->x = 0x9400;
    r->y = 0x9401;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    i_mvn(c, 0x7E, 0x7E); /* copy up bank $7E to bank $7E */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x092F, 0xC009BA); GUARD_JSR(c, sp_call, 0x092F); } /* copy_dialogue_window_style_and_fill_graphics_page */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool overflow_ret = r->v;
    uint8_t value = RAM8(0xA162);
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    if (value == 1) {
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
        carry1 = value >= 1;
        overflow1 = overflow_ret;
        data_bank = 0x7E;
    } else {
        r->a = (a_all >> 8 << 8) | value;
        r->c = value >= 1;
        r->z = value == 1;
        r->n = (uint8_t)(value - 1) & 0x80;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0939, 0xC00968); GUARD_JSR(c, sp_call, 0x0939); } /* publish_dialogue_style_palette_banks */
        uint8_t db_ret = r->db;
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret2;
        y1 = y_ret2;
        carry1 = carry_ret2;
        overflow1 = overflow_ret2;
        data_bank = db_ret;
    }
    RAM8(0x1D04) = 0x0F;
    uint8_t value2 = BUS8_RDP(c, (data_bank << 0x10) + 0xA15C);
    BUS8_SET(c, (data_bank << 0x10) + 0xA15C, (uint8_t)(value2 + 1));
    uint8_t value3 = BUS8_RDP(c, (data_bank << 0x10) + 0xCFF8);
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    uint8_t data_bank2;
    if (value3 == 0) {
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        carry2 = carry1;
        data_bank2 = data_bank;
    } else {
        uint8_t value4 = BUS8_RDP(c, (data_bank << 0x10) + 0xA24E);
        uint8_t value5 = BUS8_RDP(c, (data_bank << 0x10) + 0xA24F + value4);
        BUS8_SET(c, (data_bank << 0x10) + 0xA21B, value5);
        BUS8_SET(c, (data_bank << 0x10) + 0xA24F + value4, 4);
        BUS8_SET(c, (data_bank << 0x10) + 0xA15C, 5);
        r->a = 5;
        r->x = value4;
        r->y = y1;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0961, 0xC00D8B); GUARD_JSR(c, sp_call, 0x0961); } /* select_dialogue_window_geometry_from_state */
        uint8_t db_ret2 = r->db;
        uint16_t a_all3 = r->a;
        uint16_t x_ret3 = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        a_hi2 = a_all3 >> 8;
        x2 = x_ret3;
        y2 = y_ret3;
        carry2 = carry_ret3;
        data_bank2 = db_ret2;
    }
    r->a = (a_hi2 << 8) | 0x20;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->z = 0;
    r->n = 0;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0966, 0xC00FFA); GUARD_JSR(c, sp_call, 0x0966); } /* request_dialogue_transfer_and_conditional_window_flags */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0090F, SOM_RTS, "gen", initialize_dialogue_window_font_buffer_and_style, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 89, 35)
