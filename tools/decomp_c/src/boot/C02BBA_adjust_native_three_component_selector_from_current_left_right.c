#include "som_c.h"

/* C02BBA adjust_native_three_component_selector_from_current_left_right   [class B, 31 bytes, 14 instructions]
 * Source: src/rom/adjust_native_three_component_selector_from_current_left_right.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void adjust_native_three_component_selector_from_current_left_right(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2BBC, 0xC03269); GUARD_JSR(c, sp_call, 0x2BBC); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    RAM8(0x0000 + sp0) = x_ret >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret;
    uint8_t value = BUS8_RDP(c, (uint16_t)(x_ret + 0x43));
    bool x_flag;
    uint8_t a_hi1;
    uint16_t y1;
    bool overflow1;
    if ((value & 2) == 0) {
        x_flag = 0;
        a_hi1 = a_all >> 8;
        y1 = y;
        overflow1 = overflow;
    } else {
        r->a = a_all >> 8 << 8 | (value & 2);
        r->z = (value & 2) == 0;
        r->n = value & 2 & 0x80;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSL(c, 0x2BC7, 0xC762A5); GUARD_JSL(c, sp_call, 0x2BC7); } /* decrement_native_shop_selector_unless_zero */
        r->sp += 2;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret2 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        x_flag = x_ret2;
        a_hi1 = a_all2 >> 8;
        y1 = y_ret;
        overflow1 = overflow_ret;
    }
    if (x_flag) {
        c->fail = 3;
        return;
    } else {
        uint8_t value5 = RAM8(0x0000 + sp0 - 1);
        uint8_t value6 = RAM8(0x0000 + sp0);
        uint8_t value7 = BUS8_RDP(c, (uint16_t)(((value6 << 8) | value5) + 0x43));
        bool x_flag3;
        if ((value7 & 1) == 0) {
            x_flag3 = 0;
        } else {
            r->a = a_hi1 << 8 | (value7 & 1);
            r->x = (value6 << 8) | value5;
            r->y = y1;
            r->z = (value7 & 1) == 0;
            r->n = value7 & 1 & 0x80;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2BD2, 0xC76292); GUARD_JSL(c, sp_call, 0x2BD2); } /* increment_native_shop_selector_unless_thirty_one */
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret6 = r->xf;
            RAM8(0xA212) |= 0x80;
            x_flag3 = x_ret6;
        }
        r->mf = 1;
        r->xf = x_flag3;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC02BBA, SOM_RTS, "gen", adjust_native_three_component_selector_from_current_left_right, 0, 0, 2, 1, 0, 31, 14)
