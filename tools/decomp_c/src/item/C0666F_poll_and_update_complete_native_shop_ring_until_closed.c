#include "som_c.h"

/* C0666F poll_and_update_complete_native_shop_ring_until_closed   [class B, 39 bytes, 15 instructions]
 * Source: src/rom/poll_and_update_complete_native_shop_ring_until_closed.s
 * Documented in docs/event-menu-shop-public.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: XYCV.
 */
static void poll_and_update_complete_native_shop_ring_until_closed(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t a1 = (uint8_t)a;
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = zero;
    bool negative1 = negative;
    bool overflow1 = overflow;
    uint8_t data_bank = db;
    uint16_t direct_page = dp;
    for (;;) {
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6671, 0xC0695E); GUARD_JSR(c, sp_call, 0x6671); } /* wait_vblank_before_polling_native_menu_input */
        { const uint16_t sp_call = r->sp; JSR(c, 0x6674, 0xC06BF8); GUARD_JSR(c, sp_call, 0x6674); } /* dispatch_native_menu_ring_phase_from_original_jump_table */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        uint16_t a_all2 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        uint8_t value = BUS8(c, (db_ret2 << 0x10) + 0x1812);
        bool m_flag;
        bool x_flag2;
        uint8_t a_hi3;
        uint16_t x3;
        uint16_t y3;
        bool carry2;
        bool overflow2;
        uint8_t data_bank2;
        uint16_t direct_page2;
        if (value != 0) {
            m_flag = 1;
            x_flag2 = 1;
            a_hi3 = a_all2 >> 8;
            x3 = (uint8_t)x_ret4;
            y3 = (uint8_t)y_ret2;
            carry2 = carry_ret2;
            overflow2 = overflow_ret2;
            data_bank2 = db_ret2;
            direct_page2 = dp_ret2;
        } else {
            uint8_t value2 = BUS8(c, (db_ret2 << 0x10) + 0x1847);
            bool x_flag;
            uint8_t a_hi2;
            uint16_t x2;
            uint16_t y2;
            if (value2 != 2) {
                x_flag = 1;
                a_hi2 = a_all2 >> 8;
                x2 = (uint8_t)x_ret4;
                y2 = (uint8_t)y_ret2;
            } else {
                r->a = (a_all2 >> 8 << 8) | value2;
                r->x = (uint8_t)x_ret4;
                r->y = (uint8_t)y_ret2;
                r->c = value2 >= 2;
                r->mf = 1;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x6685, 0xC06740); GUARD_JSR(c, sp_call, 0x6685); } /* request_native_menu_vertical_inventory_transition */
                bool x_ret5 = r->xf;
                uint16_t a_all3 = r->a;
                uint16_t x_ret6 = r->x;
                uint16_t y_ret3 = r->y;
                x_flag = x_ret5;
                a_hi2 = a_all3 >> 8;
                x2 = x_ret6;
                y2 = y_ret3;
            }
            r->a = (a_hi2 << 8) | (uint8_t)a;
            r->x = x2;
            r->y = y2;
            r->c = value2 >= 2;
            r->mf = 1;
            r->xf = x_flag;
            { const uint16_t sp_call = r->sp; JSR(c, 0x6688, 0xC066F3); GUARD_JSR(c, sp_call, 0x6688); } /* update_native_menu_horizontal_repeat_and_description_request */
            { const uint16_t sp_call = r->sp; JSR(c, 0x668B, 0xC067A8); GUARD_JSR(c, sp_call, 0x668B); } /* process_native_ring_cancel_and_confirm_input */
            uint16_t dp_ret3 = r->dp;
            uint8_t db_ret3 = r->db;
            bool m_ret4 = r->mf;
            bool x_ret9 = r->xf;
            uint16_t a_all5 = r->a;
            uint16_t x_ret10 = r->x;
            uint16_t y_ret4 = r->y;
            bool carry_ret4 = r->c;
            bool overflow_ret4 = r->v;
            m_flag = m_ret4;
            x_flag2 = x_ret9;
            a_hi3 = a_all5 >> 8;
            x3 = x_ret10;
            y3 = y_ret4;
            carry2 = carry_ret4;
            overflow2 = overflow_ret4;
            data_bank2 = db_ret3;
            direct_page2 = dp_ret3;
        }
        uint16_t value3 = BUS16(c, (data_bank2 << 0x10) + 0x1826);
        a1 = (uint8_t)value3;
        a_hi1 = value3 >> 8;
        x1 = x3;
        y1 = y3;
        carry1 = carry2;
        zero1 = value3 == 0;
        negative1 = value3 & 0x8000;
        overflow1 = overflow2;
        data_bank = data_bank2;
        direct_page = direct_page2;
        if (!(value3 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    TAIL_CALL(c, 0xC06608, SOM_RTS); /* close_native_ring_dialogue_and_restore_shadow_palette */
}
SOM_REGISTER(0xC0666F, SOM_RTS, "gen", poll_and_update_complete_native_shop_ring_until_closed, 0, L_X | L_Y | L_C | L_V, 1, 0, 0, 39, 15)
