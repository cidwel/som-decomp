#include "som_c.h"

/* C06922 poll_native_menu_frames_until_cancel_is_released   [class A, 11 bytes, 5 instructions]
 * Source: src/rom/poll_native_menu_frames_until_cancel_is_released.s
 * Entry: M=8 bit X=16 bit DB=$00 D=any.  Callers read: ABXYCZNV.
 */
static void poll_native_menu_frames_until_cancel_is_released(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a_6922 = 0;
    uint8_t a_hi_6922 = 0;
    uint16_t x_6922 = 0;
    uint16_t y_6922 = 0;
    bool carry_6922 = 0;
    bool zero_6922 = 0;
    bool negative_6922 = 0;
    bool overflow_6922 = 0;
    uint8_t a_69222 = 0;
    uint8_t a_hi_69222 = 0;
    uint8_t x_69222 = 0;
    uint8_t y_69222 = 0;
    bool carry_69222 = 0;
    bool zero_69222 = 0;
    bool negative_69222 = 0;
    bool overflow_69222 = 0;
    uint16_t direct_page_6922 = 0;
    uint8_t data_bank_6922 = 0;
    uint8_t a_69223 = 0;
    uint8_t a_hi_69223 = 0;
    uint16_t x_69223 = 0;
    uint16_t y_69223 = 0;
    bool carry_69223 = 0;
    bool zero_69223 = 0;
    bool negative_69223 = 0;
    bool overflow_69223 = 0;
    uint16_t direct_page_69222 = 0;
    uint8_t data_bank_69222 = 0;
    a_6922 = a;
    a_hi_6922 = a_hi;
    x_6922 = x;
    y_6922 = y;
    carry_6922 = carry;
    zero_6922 = zero;
    negative_6922 = negative;
    overflow_6922 = overflow;
    r->a = (a_hi_6922 << 8) | a_6922;
    r->x = x_6922;
    r->y = y_6922;
    r->c = carry_6922;
    r->z = zero_6922;
    r->n = negative_6922;
    r->v = overflow_6922;
    r->mf = 0;
    r->xf = 0;
    r->db = 0;
    r->dp = dp;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6926, 0xC0695E); GUARD_JSR(c, sp_call, 0x6926); } /* wait_vblank_before_polling_native_menu_input */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    if ((a_all & 0x4000) != 0) {
        if (x_ret) {
            a_69222 = (uint8_t)(a_all & 0x4000);
            a_hi_69222 = (a_all & 0x4000) >> 8;
            x_69222 = (uint8_t)x_ret2;
            y_69222 = (uint8_t)y_ret;
            carry_69222 = carry_ret;
            zero_69222 = (a_all & 0x4000) == 0;
            negative_69222 = a_all & 0x4000 & 0x8000;
            overflow_69222 = overflow_ret;
            direct_page_6922 = dp_ret;
            data_bank_6922 = db_ret;
            goto shared_6922_1;
        } else {
            a_69223 = (uint8_t)(a_all & 0x4000);
            a_hi_69223 = (a_all & 0x4000) >> 8;
            x_69223 = x_ret2;
            y_69223 = y_ret;
            carry_69223 = carry_ret;
            zero_69223 = (a_all & 0x4000) == 0;
            negative_69223 = a_all & 0x4000 & 0x8000;
            overflow_69223 = overflow_ret;
            direct_page_69222 = dp_ret;
            data_bank_69222 = db_ret;
            goto shared_6922_2;
        }
    }
    r->a = a_all & 0x4000;
    r->z = (a_all & 0x4000) == 0;
    r->n = a_all & 0x4000 & 0x8000;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_6922_1:;
    r->a = (a_hi_69222 << 8) | a_69222;
    r->x = x_69222;
    r->y = y_69222;
    r->c = carry_69222;
    r->z = zero_69222;
    r->n = negative_69222;
    r->v = overflow_69222;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_6922;
    r->dp = direct_page_6922;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6926, 0xC0695E); GUARD_JSR(c, sp_call, 0x6926); } /* wait_vblank_before_polling_native_menu_input */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    if ((a_all2 & 0x4000) != 0) {
        if (x_ret3) {
            a_69222 = (uint8_t)(a_all2 & 0x4000);
            a_hi_69222 = (a_all2 & 0x4000) >> 8;
            x_69222 = (uint8_t)x_ret4;
            y_69222 = (uint8_t)y_ret2;
            carry_69222 = carry_ret2;
            zero_69222 = (a_all2 & 0x4000) == 0;
            negative_69222 = a_all2 & 0x4000 & 0x8000;
            overflow_69222 = overflow_ret2;
            direct_page_6922 = dp_ret2;
            data_bank_6922 = db_ret2;
            goto shared_6922_1;
        } else {
            a_69223 = (uint8_t)(a_all2 & 0x4000);
            a_hi_69223 = (a_all2 & 0x4000) >> 8;
            x_69223 = x_ret4;
            y_69223 = y_ret2;
            carry_69223 = carry_ret2;
            zero_69223 = (a_all2 & 0x4000) == 0;
            negative_69223 = a_all2 & 0x4000 & 0x8000;
            overflow_69223 = overflow_ret2;
            direct_page_69222 = dp_ret2;
            data_bank_69222 = db_ret2;
            goto shared_6922_2;
        }
    }
    r->a = a_all2 & 0x4000;
    r->z = (a_all2 & 0x4000) == 0;
    r->n = a_all2 & 0x4000 & 0x8000;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_6922_2:;
    r->a = (a_hi_69223 << 8) | a_69223;
    r->x = x_69223;
    r->y = y_69223;
    r->c = carry_69223;
    r->z = zero_69223;
    r->n = negative_69223;
    r->v = overflow_69223;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_69222;
    r->dp = direct_page_69222;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6926, 0xC0695E); GUARD_JSR(c, sp_call, 0x6926); } /* wait_vblank_before_polling_native_menu_input */
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret5 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t x_ret6 = r->x;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    if ((a_all3 & 0x4000) != 0) {
        if (x_ret5) {
            a_69222 = (uint8_t)(a_all3 & 0x4000);
            a_hi_69222 = (a_all3 & 0x4000) >> 8;
            x_69222 = (uint8_t)x_ret6;
            y_69222 = (uint8_t)y_ret3;
            carry_69222 = carry_ret3;
            zero_69222 = (a_all3 & 0x4000) == 0;
            negative_69222 = a_all3 & 0x4000 & 0x8000;
            overflow_69222 = overflow_ret3;
            direct_page_6922 = dp_ret3;
            data_bank_6922 = db_ret3;
            goto shared_6922_1;
        } else {
            a_69223 = (uint8_t)(a_all3 & 0x4000);
            a_hi_69223 = (a_all3 & 0x4000) >> 8;
            x_69223 = x_ret6;
            y_69223 = y_ret3;
            carry_69223 = carry_ret3;
            zero_69223 = (a_all3 & 0x4000) == 0;
            negative_69223 = a_all3 & 0x4000 & 0x8000;
            overflow_69223 = overflow_ret3;
            direct_page_69222 = dp_ret3;
            data_bank_69222 = db_ret3;
            goto shared_6922_2;
        }
    }
    r->a = a_all3 & 0x4000;
    r->z = (a_all3 & 0x4000) == 0;
    r->n = a_all3 & 0x4000 & 0x8000;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06922, SOM_RTS, "gen", poll_native_menu_frames_until_cancel_is_released, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 11, 5)
