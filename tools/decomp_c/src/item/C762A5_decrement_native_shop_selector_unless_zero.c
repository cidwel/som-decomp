#include "som_c.h"

/* C762A5 decrement_native_shop_selector_unless_zero   [class A, 19 bytes, 8 instructions]
 * Source: src/rom/decrement_native_shop_selector_unless_zero.s
 * Documented in docs/event-menu-shop-actions.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYV.
 */
static void decrement_native_shop_selector_unless_zero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA1D1 + y);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t y1;
    bool overflow1;
    if ((uint8_t)(value - 1) == 0xFF) {
        m_flag = 1;
        x_flag = 0;
        a_hi1 = a_hi;
        y1 = y;
        overflow1 = overflow;
    } else {
        RAM8(0xA1D1 + y) = (uint8_t)(value - 1);
        r->a = (a_hi << 8) | (uint8_t)(value - 1);
        { const uint16_t sp_call = r->sp; JSR(c, 0x62B2, 0xC762B8); GUARD_JSR(c, sp_call, 0x62B2); } /* pack_three_native_shop_selectors_and_refresh_icon_oam */
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x62B6, 0xC02AF2); GUARD_JSL(c, sp_call, 0x62B6); } /* native_menu_change_sound_long_wrapper */
        bool m_ret = r->mf;
        bool x_ret2 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t y_ret2 = r->y;
        bool overflow_ret2 = r->v;
        m_flag = m_ret;
        x_flag = x_ret2;
        a_hi1 = a_all2 >> 8;
        y1 = y_ret2;
        overflow1 = overflow_ret2;
    }
    r->a = (a_hi1 << 8) | a;
    r->y = y1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC762A5, SOM_RTL, "gen", decrement_native_shop_selector_unless_zero, 0, L_B | L_Y | L_V, 1, 1, 0, 19, 8)
