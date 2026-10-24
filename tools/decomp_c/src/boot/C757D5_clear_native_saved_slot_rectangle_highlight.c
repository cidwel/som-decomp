#include "som_c.h"

/* C757D5 clear_native_saved_slot_rectangle_highlight   [class B, 103 bytes, 49 instructions]
 * Source: src/rom/clear_native_saved_slot_rectangle_highlight.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void clear_native_saved_slot_rectangle_highlight(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    RAM8(0xA1CB) = 0;
    uint16_t value = RAM16(0xA211);
    uint16_t value2 = RAM16(0xA1E0 + ((value & 0xFF) << 1 << 1));
    RAM8(0x0000 + sp0) = value2 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value2;
    uint16_t value3 = RAM16(0xA1E2 + ((value & 0xFF) << 1 << 1));
    RAM16_SET(0xA16B, value3);
    RAM8(0xA163) = (uint8_t)(RAM8(0xA16B) + 2);
    uint8_t a_hi1 = value3 >> 8;
    uint16_t x1 = value2;
    bool overflow1 = overflow;
    do {
        RAM8(0xA164) = (uint8_t)(RAM8(0xA16C) + 2);
        RAM8(0x0000 + sp0) = x1 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x1;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        do {
            RAM8(0x9001 + x2) = (RAM8(0x9001 + x2) & 0xE3) | RAM8(0xA1CB);
            RAM8(0xA164)--;
            x2 = (uint16_t)(x2 + 2);
        } while (RAM8(0xA164) != 0);
        uint8_t value8 = RAM8(0x0000 + sp0 - 1);
        uint8_t value9 = RAM8(0x0000 + sp0);
        RAM8(0xA163)--;
        a_hi1 = (uint16_t)(((value9 << 8) | value8) + 0x40) >> 8;
        x1 = (uint16_t)(((value9 << 8) | value8) + 0x40);
        overflow1 = ((((value9 << 8) | value8) ^ (uint16_t)(((value9 << 8) | value8) + 0x40)) & ((uint16_t)(((value9 << 8) | value8) + 0x40) ^ 0x40) & 0x8000) != 0;
    } while (RAM8(0xA163) != 0);
    uint8_t value10 = RAM8(0xA202);
    bool x_flag;
    uint8_t a_hi3;
    uint16_t x3;
    uint16_t y1;
    bool carry1;
    bool overflow2;
    if (value10 == 6) {
        x_flag = 0;
        a_hi3 = a_hi1;
        x3 = x1;
        y1 = y;
        carry1 = value10 >= 6;
        overflow2 = overflow1;
    } else {
        r->a = (a_hi1 << 8) | value10;
        r->x = x1;
        r->y = y;
        r->c = value10 >= 6;
        r->z = value10 == 6;
        r->n = (uint8_t)(value10 - 6) & 0x80;
        r->v = overflow1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x5835, 0xC02AF2); GUARD_JSL(c, sp_call, 0x5835); } /* native_menu_change_sound_long_wrapper */
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        x_flag = x_ret;
        a_hi3 = a_all >> 8;
        x3 = x_ret2;
        y1 = y_ret;
        carry1 = carry_ret;
        overflow2 = overflow_ret;
    }
    RAM8(0xA20A) |= 2;
    r->a = (a_hi3 << 8) | 2;
    r->x = x3;
    r->y = y1;
    r->c = carry1;
    r->v = overflow2;
    r->xf = x_flag;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC757D5, SOM_RTL, "gen", clear_native_saved_slot_rectangle_highlight, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 103, 49)
