#include "som_c.h"

/* C0F4CB advance_actor_animation_and_resume_native_frame_stream   [class C, 1000 bytes, 515 instructions]
 * Source: src/rom/advance_actor_animation_and_resume_native_frame_stream.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void advance_actor_animation_and_resume_native_frame_stream(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    uint8_t a_f4e2 = 0;
    uint8_t a_hi_f4e2 = 0;
    uint16_t x_f4e2 = 0;
    uint16_t y_f4e2 = 0;
    bool carry_f4e2 = 0;
    bool overflow_f4e2 = 0;
    uint16_t direct_page_f4e2 = 0;
    uint8_t data_bank_f4e2 = 0;
    uint8_t a_hi_f4fb = 0;
    uint16_t x_f4fb = 0;
    uint16_t y_f4fb = 0;
    bool carry_f4fb = 0;
    bool overflow_f4fb = 0;
    uint16_t direct_page_f4fb = 0;
    uint8_t data_bank_f4fb = 0;
    uint8_t a_hi_f509 = 0;
    uint16_t x_f509 = 0;
    uint16_t y_f509 = 0;
    bool carry_f509 = 0;
    bool overflow_f509 = 0;
    uint16_t direct_page_f509 = 0;
    uint8_t data_bank_f509 = 0;
    uint8_t a_hi_f52d = 0;
    uint16_t x_f52d = 0;
    uint16_t y_f52d = 0;
    bool overflow_f52d = 0;
    uint16_t direct_page_f52d = 0;
    uint8_t data_bank_f52d = 0;
    uint8_t a_hi_f52d2 = 0;
    uint16_t x_f52d2 = 0;
    uint16_t y_f52d2 = 0;
    bool overflow_f52d2 = 0;
    uint16_t direct_page_f52d2 = 0;
    uint8_t data_bank_f52d2 = 0;
    uint8_t a_hi_f5a1 = 0;
    uint16_t x_f5a1 = 0;
    uint16_t y_f5a1 = 0;
    bool carry_f5a1 = 0;
    bool overflow_f5a1 = 0;
    uint16_t direct_page_f5a1 = 0;
    uint8_t data_bank_f5a1 = 0;
    uint8_t a_f57a = 0;
    uint8_t a_hi_f57a = 0;
    uint16_t x_f57a = 0;
    uint16_t y_f57a = 0;
    uint16_t direct_page_f57a = 0;
    uint8_t data_bank_f57a = 0;
    uint8_t a_f585 = 0;
    uint8_t a_hi_f585 = 0;
    uint16_t x_f585 = 0;
    uint16_t y_f585 = 0;
    bool carry_f585 = 0;
    bool overflow_f585 = 0;
    uint16_t direct_page_f585 = 0;
    uint8_t data_bank_f585 = 0;
    uint8_t a_hi_f5ac = 0;
    uint16_t x_f5ac = 0;
    uint16_t direct_page_f5ac = 0;
    uint8_t data_bank_f5ac = 0;
    uint8_t a_hi_f5a12 = 0;
    uint16_t x_f5a12 = 0;
    uint16_t y_f5a12 = 0;
    bool carry_f5a12 = 0;
    bool overflow_f5a12 = 0;
    uint16_t direct_page_f5a12 = 0;
    uint8_t data_bank_f5a12 = 0;
    uint8_t a_hi_f5ac2 = 0;
    uint16_t x_f5ac2 = 0;
    uint16_t direct_page_f5ac2 = 0;
    uint8_t data_bank_f5ac2 = 0;
    uint8_t a_f5c8 = 0;
    uint8_t a_hi_f5c8 = 0;
    uint16_t x_f5c8 = 0;
    uint16_t direct_page_f5c8 = 0;
    uint8_t data_bank_f5c8 = 0;
    uint8_t a_f5db = 0;
    uint8_t a_hi_f5db = 0;
    uint16_t x_f5db = 0;
    uint16_t direct_page_f5db = 0;
    uint8_t data_bank_f5db = 0;
    uint8_t a_f5eb = 0;
    uint8_t a_hi_f5eb = 0;
    uint16_t x_f5eb = 0;
    uint16_t direct_page_f5eb = 0;
    uint8_t data_bank_f5eb = 0;
    uint8_t a_f61e = 0;
    uint8_t a_hi_f61e = 0;
    uint16_t x_f61e = 0;
    uint16_t direct_page_f61e = 0;
    uint8_t data_bank_f61e = 0;
    uint8_t a_f62f = 0;
    uint8_t a_hi_f62f = 0;
    uint16_t x_f62f = 0;
    uint16_t direct_page_f62f = 0;
    uint8_t data_bank_f62f = 0;
    uint8_t a_f661 = 0;
    uint8_t a_hi_f661 = 0;
    uint16_t x_f661 = 0;
    uint16_t y_f661 = 0;
    uint16_t direct_page_f661 = 0;
    uint8_t data_bank_f661 = 0;
    uint8_t a_hi_f66e = 0;
    uint16_t x_f66e = 0;
    uint16_t y_f66e = 0;
    uint16_t direct_page_f66e = 0;
    uint8_t data_bank_f66e = 0;
    uint8_t a_f686 = 0;
    uint8_t a_hi_f686 = 0;
    uint16_t x_f686 = 0;
    uint16_t y_f686 = 0;
    uint16_t direct_page_f686 = 0;
    uint8_t data_bank_f686 = 0;
    uint8_t a_hi_f6c0 = 0;
    uint16_t direct_page_f6c0 = 0;
    uint8_t data_bank_f6c0 = 0;
    uint8_t a_f6b2 = 0;
    uint8_t a_hi_f6b2 = 0;
    uint16_t x_f6b2 = 0;
    uint16_t y_f6b2 = 0;
    uint16_t direct_page_f6b2 = 0;
    uint8_t data_bank_f6b2 = 0;
    uint8_t a_f69a = 0;
    uint8_t a_hi_f69a = 0;
    uint16_t x_f69a = 0;
    uint16_t y_f69a = 0;
    uint16_t direct_page_f69a = 0;
    uint8_t data_bank_f69a = 0;
    uint8_t a_hi_f6f6 = 0;
    uint16_t x_f6f6 = 0;
    uint16_t y_f6f6 = 0;
    uint16_t direct_page_f6f6 = 0;
    uint8_t data_bank_f6f6 = 0;
    uint8_t a_f6f2 = 0;
    uint8_t a_hi_f6f2 = 0;
    uint16_t x_f6f2 = 0;
    uint16_t y_f6f2 = 0;
    uint16_t direct_page_f6f2 = 0;
    uint8_t data_bank_f6f2 = 0;
    uint8_t a_hi_f704 = 0;
    uint16_t x_f704 = 0;
    uint16_t y_f704 = 0;
    uint16_t direct_page_f704 = 0;
    uint8_t data_bank_f704 = 0;
    uint8_t a_f721 = 0;
    uint8_t a_hi_f721 = 0;
    uint16_t x_f721 = 0;
    uint16_t y_f721 = 0;
    uint16_t direct_page_f721 = 0;
    uint8_t data_bank_f721 = 0;
    uint8_t a_f726 = 0;
    uint8_t a_hi_f726 = 0;
    uint16_t x_f726 = 0;
    uint16_t y_f726 = 0;
    uint16_t direct_page_f726 = 0;
    uint8_t data_bank_f726 = 0;
    uint8_t a_f72b = 0;
    uint8_t a_hi_f72b = 0;
    uint16_t x_f72b = 0;
    uint16_t y_f72b = 0;
    uint16_t direct_page_f72b = 0;
    uint8_t data_bank_f72b = 0;
    uint8_t a_f736 = 0;
    uint8_t a_hi_f736 = 0;
    uint16_t x_f736 = 0;
    uint16_t y_f736 = 0;
    uint16_t direct_page_f736 = 0;
    uint8_t data_bank_f736 = 0;
    uint8_t a_f73b = 0;
    uint8_t a_hi_f73b = 0;
    uint16_t x_f73b = 0;
    uint16_t y_f73b = 0;
    uint16_t direct_page_f73b = 0;
    uint8_t data_bank_f73b = 0;
    uint8_t a_f740 = 0;
    uint8_t a_hi_f740 = 0;
    uint16_t x_f740 = 0;
    uint16_t y_f740 = 0;
    uint16_t direct_page_f740 = 0;
    uint8_t data_bank_f740 = 0;
    uint8_t a_f75a = 0;
    uint8_t a_hi_f75a = 0;
    uint16_t x_f75a = 0;
    uint16_t y_f75a = 0;
    uint16_t direct_page_f75a = 0;
    uint8_t data_bank_f75a = 0;
    uint8_t a_f760 = 0;
    uint8_t a_hi_f760 = 0;
    uint16_t x_f760 = 0;
    uint16_t y_f760 = 0;
    uint16_t direct_page_f760 = 0;
    uint8_t data_bank_f760 = 0;
    uint8_t a_f775 = 0;
    uint8_t a_hi_f775 = 0;
    uint16_t x_f775 = 0;
    uint16_t y_f775 = 0;
    bool carry_f775 = 0;
    uint16_t direct_page_f775 = 0;
    uint8_t data_bank_f775 = 0;
    uint8_t a_hi_f82a = 0;
    uint16_t x_f82a = 0;
    uint16_t y_f82a = 0;
    bool carry_f82a = 0;
    uint16_t direct_page_f82a = 0;
    uint8_t data_bank_f82a = 0;
    uint8_t a_f7e0 = 0;
    uint8_t a_hi_f7e0 = 0;
    uint16_t x_f7e0 = 0;
    uint16_t y_f7e0 = 0;
    uint16_t direct_page_f7e0 = 0;
    uint8_t data_bank_f7e0 = 0;
    uint8_t a_f7b4 = 0;
    uint8_t a_hi_f7b4 = 0;
    uint16_t x_f7b4 = 0;
    uint16_t y_f7b4 = 0;
    uint16_t direct_page_f7b4 = 0;
    uint8_t data_bank_f7b4 = 0;
    uint8_t a_f873 = 0;
    uint8_t a_hi_f873 = 0;
    uint16_t x_f873 = 0;
    uint16_t y_f873 = 0;
    uint16_t direct_page_f873 = 0;
    uint8_t data_bank_f873 = 0;
    uint8_t a_f848 = 0;
    uint8_t a_hi_f848 = 0;
    uint16_t x_f848 = 0;
    uint16_t y_f848 = 0;
    uint16_t direct_page_f848 = 0;
    uint8_t data_bank_f848 = 0;
    uint8_t a_f7e9 = 0;
    uint8_t a_hi_f7e9 = 0;
    uint16_t x_f7e9 = 0;
    uint16_t y_f7e9 = 0;
    uint16_t direct_page_f7e9 = 0;
    uint8_t data_bank_f7e9 = 0;
    uint8_t a_f7bf = 0;
    uint8_t a_hi_f7bf = 0;
    uint16_t x_f7bf = 0;
    uint16_t y_f7bf = 0;
    uint16_t direct_page_f7bf = 0;
    uint8_t data_bank_f7bf = 0;
    uint8_t a_f87c = 0;
    uint8_t a_hi_f87c = 0;
    uint16_t x_f87c = 0;
    uint16_t y_f87c = 0;
    uint16_t direct_page_f87c = 0;
    uint8_t data_bank_f87c = 0;
    uint8_t a_f853 = 0;
    uint8_t a_hi_f853 = 0;
    uint16_t x_f853 = 0;
    uint16_t y_f853 = 0;
    uint16_t direct_page_f853 = 0;
    uint8_t data_bank_f853 = 0;
    uint8_t a_f7f7 = 0;
    uint8_t a_hi_f7f7 = 0;
    uint16_t x_f7f7 = 0;
    uint16_t y_f7f7 = 0;
    uint16_t direct_page_f7f7 = 0;
    uint8_t data_bank_f7f7 = 0;
    uint8_t a_f7cb = 0;
    uint8_t a_hi_f7cb = 0;
    uint16_t x_f7cb = 0;
    uint16_t y_f7cb = 0;
    uint16_t direct_page_f7cb = 0;
    uint8_t data_bank_f7cb = 0;
    uint8_t a_f88a = 0;
    uint8_t a_hi_f88a = 0;
    uint16_t x_f88a = 0;
    uint16_t y_f88a = 0;
    uint16_t direct_page_f88a = 0;
    uint8_t data_bank_f88a = 0;
    uint8_t a_f85f = 0;
    uint8_t a_hi_f85f = 0;
    uint16_t x_f85f = 0;
    uint16_t y_f85f = 0;
    bool overflow_f85f = 0;
    uint16_t direct_page_f85f = 0;
    uint8_t data_bank_f85f = 0;
    uint8_t a_f800 = 0;
    uint8_t a_hi_f800 = 0;
    uint16_t x_f800 = 0;
    uint16_t y_f800 = 0;
    uint16_t direct_page_f800 = 0;
    uint8_t data_bank_f800 = 0;
    uint8_t a_f810 = 0;
    uint8_t a_hi_f810 = 0;
    uint16_t x_f810 = 0;
    uint16_t y_f810 = 0;
    uint16_t direct_page_f810 = 0;
    uint8_t data_bank_f810 = 0;
    uint8_t a_f893 = 0;
    uint8_t a_hi_f893 = 0;
    uint16_t x_f893 = 0;
    uint16_t y_f893 = 0;
    uint16_t direct_page_f893 = 0;
    uint8_t data_bank_f893 = 0;
    uint8_t a_f8a2 = 0;
    uint8_t a_hi_f8a2 = 0;
    uint16_t x_f8a2 = 0;
    uint16_t y_f8a2 = 0;
    bool overflow_f8a2 = 0;
    uint16_t direct_page_f8a2 = 0;
    uint8_t data_bank_f8a2 = 0;
    uint8_t a_f80a = 0;
    uint8_t a_hi_f80a = 0;
    uint16_t x_f80a = 0;
    uint16_t y_f80a = 0;
    uint16_t direct_page_f80a = 0;
    uint8_t data_bank_f80a = 0;
    uint8_t a_f89d = 0;
    uint8_t a_hi_f89d = 0;
    uint16_t x_f89d = 0;
    uint16_t y_f89d = 0;
    bool overflow_f89d = 0;
    uint16_t direct_page_f89d = 0;
    uint8_t data_bank_f89d = 0;
    RAM16_SET(0x0014, x);
    uint8_t value = RAM8(0x00F1);
    if (value & 0x40) {
        a_f4e2 = a;
        a_hi_f4e2 = a_hi;
        x_f4e2 = x;
        y_f4e2 = y;
        carry_f4e2 = carry;
        overflow_f4e2 = value & 0x40;
        direct_page_f4e2 = 0;
        data_bank_f4e2 = 0x7E;
        goto shared_F4E2;
    }
    uint8_t value2 = RAM8(0xE000 + x);
    if (value2 != 0) {
        if (value2 & 0x80) {
            a_hi_f4fb = a_hi;
            x_f4fb = x;
            y_f4fb = y;
            carry_f4fb = carry;
            overflow_f4fb = value & 0x40;
            direct_page_f4fb = 0;
            data_bank_f4fb = 0x7E;
            goto shared_F4FB;
        }
        uint8_t value3 = RAM8(0xE043 + x);
        if (value3 == 0) {
            a_hi_f4fb = a_hi;
            x_f4fb = x;
            y_f4fb = y;
            carry_f4fb = carry;
            overflow_f4fb = value & 0x40;
            direct_page_f4fb = 0;
            data_bank_f4fb = 0x7E;
            goto shared_F4FB;
        }
        if (value3 & 0x80) {
            a_hi_f4fb = a_hi;
            x_f4fb = x;
            y_f4fb = y;
            carry_f4fb = carry;
            overflow_f4fb = value & 0x40;
            direct_page_f4fb = 0;
            data_bank_f4fb = 0x7E;
            goto shared_F4FB;
        }
        RAM8(0x0000 + sp0) = value3;
        RAM8(0x0000 + sp0 - 1) = x >> 8;
        RAM8(0x0000 + sp0 - 2) = (uint8_t)x;
        r->a = (a_hi << 8) | value3;
        r->z = value3 == 0;
        r->n = value3 & 0x80;
        r->v = value & 0x40;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xF4F0, 0xC0DFD4); GUARD_JSR(c, sp_call, 0xF4F0); } /* refill_actor_slot_from_directional_circular_map_cache */
        r->sp += 3;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        uint8_t value4 = RAM8(0x0000 + sp0 - 2);
        uint8_t value5 = RAM8(0x0000 + sp0 - 1);
        uint8_t value6 = RAM8(0x0000 + sp0);
        uint8_t value7 = BUS8_RDP(c, (db_ret << 0x10) + 0xE043 + ((value5 << 8) | value4));
        if (value6 == value7) {
            a_hi_f4fb = a_all >> 8;
            x_f4fb = (value5 << 8) | value4;
            y_f4fb = y_ret;
            carry_f4fb = value6 >= value7;
            overflow_f4fb = overflow_ret;
            direct_page_f4fb = dp_ret;
            data_bank_f4fb = db_ret;
            goto shared_F4FB;
        }
        SET_A8(r, value6);
        r->x = (value5 << 8) | value4;
        r->c = value6 >= value7;
        r->mf = 1;
        RETURN_RTS(c);
    }
    if (x < 0x0600) {
        a_f4e2 = value2;
        a_hi_f4e2 = a_hi;
        x_f4e2 = x;
        y_f4e2 = y;
        carry_f4e2 = x >= 0x0600;
        overflow_f4e2 = value & 0x40;
        direct_page_f4e2 = 0;
        data_bank_f4e2 = 0x7E;
        goto shared_F4E2;
    }
    r->a = (a_hi << 8) | value2;
    r->c = x >= 0x0600;
    r->z = x == 0x0600;
    r->n = (uint16_t)(x - 0x0600) & 0x8000;
    r->v = value & 0x40;
    TAIL_CALL(c, 0xC0DFD4, SOM_RTS); /* refill_actor_slot_from_directional_circular_map_cache */
    shared_F4E2:;
    r->a = (a_hi_f4e2 << 8) | a_f4e2;
    r->x = x_f4e2;
    r->y = y_f4e2;
    r->c = carry_f4e2;
    r->v = overflow_f4e2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_f4e2;
    r->dp = direct_page_f4e2;
    RETURN_RTS(c);
    shared_F4FB:;
    uint8_t value8 = BUS8_RDP(c, (data_bank_f4fb << 0x10) + 0xE041 + x_f4fb);
    if (value8 == 0) {
        a_hi_f509 = a_hi_f4fb;
        x_f509 = x_f4fb;
        y_f509 = y_f4fb;
        carry_f509 = carry_f4fb;
        overflow_f509 = overflow_f4fb;
        direct_page_f509 = direct_page_f4fb;
        data_bank_f509 = data_bank_f4fb;
        goto shared_F509;
    }
    BUS8_SET(c, (data_bank_f4fb << 0x10) + 0xE041 + x_f4fb, (uint8_t)(value8 - 1));
    BUS8_SET(c, (data_bank_f4fb << 0x10) + 0xE030 + x_f4fb, 0xFF);
    a_hi_f509 = a_hi_f4fb;
    x_f509 = x_f4fb;
    y_f509 = y_f4fb;
    carry_f509 = carry_f4fb;
    overflow_f509 = overflow_f4fb;
    direct_page_f509 = direct_page_f4fb;
    data_bank_f509 = data_bank_f4fb;
    goto shared_F509;
    shared_F509:;
    r->a = (a_hi_f509 << 8) | a;
    r->x = x_f509;
    r->y = y_f509;
    r->c = carry_f509;
    r->v = overflow_f509;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_f509;
    r->dp = direct_page_f509;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF50C, 0x018089); GUARD_JSL(c, sp_call, 0xF50C); } /* consume_complete_ordinary_actor_combat_requests */
    uint8_t db_ret2 = r->db;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    uint8_t value9 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xE060 + x_ret2);
    if (value9 & 0x80) {
        a_f4e2 = value9;
        a_hi_f4e2 = a_all2 >> 8;
        x_f4e2 = x_ret2;
        y_f4e2 = y_ret2;
        carry_f4e2 = carry_ret2;
        overflow_f4e2 = overflow_ret2;
        direct_page_f4e2 = direct_page_f509;
        data_bank_f4e2 = db_ret2;
        goto shared_F4E2;
    }
    uint8_t value10 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xE02C + x_ret2);
    uint8_t value11 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xE01C + x_ret2);
    uint8_t value12 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xE060 + x_ret2);
    if ((value10 | value11 | value12) != 0) {
        a_hi_f52d = a_all2 >> 8;
        x_f52d = x_ret2;
        y_f52d = y_ret2;
        overflow_f52d = overflow_ret2;
        direct_page_f52d = direct_page_f509;
        data_bank_f52d = db_ret2;
        goto shared_F52D;
    }
    uint8_t value13 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xE00A + x_ret2);
    uint8_t value14 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xE064 + x_ret2);
    uint8_t value15 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xE062 + x_ret2);
    if ((value13 | value14 | value15) != 0) {
        a_hi_f52d = a_all2 >> 8;
        x_f52d = x_ret2;
        y_f52d = y_ret2;
        overflow_f52d = overflow_ret2;
        direct_page_f52d = direct_page_f509;
        data_bank_f52d = db_ret2;
        goto shared_F52D;
    }
    r->a = (a_all2 >> 8 << 8) | (value13 | value14 | value15);
    r->z = (value13 | value14 | value15) == 0;
    r->n = (value13 | value14 | value15) & 0x80;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF52C, 0xC0F8B3); GUARD_JSR(c, sp_call, 0xF52C); } /* trigger_actor_program_under_native_animation_guards */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret3 = r->db;
    bool m_ret3 = r->mf;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all3 = r->a;
    uint16_t x_ret3 = r->x;
    uint16_t y_ret3 = r->y;
    bool overflow_ret3 = r->v;
    if (m_ret3) {
        a_hi_f52d = a_all3 >> 8;
        x_f52d = x_ret3;
        y_f52d = y_ret3;
        overflow_f52d = overflow_ret3;
        direct_page_f52d = dp_ret2;
        data_bank_f52d = db_ret3;
        goto shared_F52D;
    } else {
        a_hi_f52d2 = a_all3 >> 8;
        x_f52d2 = x_ret3;
        y_f52d2 = y_ret3;
        overflow_f52d2 = overflow_ret3;
        direct_page_f52d2 = dp_ret2;
        data_bank_f52d2 = db_ret3;
        goto shared_F52D_1;
    }
    shared_F52D:;
    BUS16_SET(c, (uint16_t)(direct_page_f52d + 2), 0xD1);
    uint16_t value16 = BUS16_RDP(c, (data_bank_f52d << 0x10) + 0xE010 + x_f52d);
    uint16_t value17 = BUS16_RDP(c, (data_bank_f52d << 0x10) + 0xE030 + x_f52d);
    BUS16_SET(c, (data_bank_f52d << 0x10) + 0xE030 + x_f52d, value16);
    if (value16 == value17) {
        uint8_t value18 = BUS8_RDP(c, (data_bank_f52d << 0x10) + 0xE012 + x_f52d);
        if (value18 == 0) {
            uint16_t value19 = BUS16_RDP(c, (data_bank_f52d << 0x10) + 0xE016 + x_f52d);
            BUS16_SET(c, direct_page_f52d, value19);
            a_hi_f5a1 = value19 >> 8;
            x_f5a1 = x_f52d;
            y_f5a1 = y_f52d;
            carry_f5a1 = value16 >= value17;
            overflow_f5a1 = overflow_f52d;
            direct_page_f5a1 = direct_page_f52d;
            data_bank_f5a1 = data_bank_f52d;
            goto shared_F5A1;
        }
        BUS8_SET(c, (data_bank_f52d << 0x10) + 0xE012 + x_f52d, (uint8_t)(value18 - 1));
        r->a = (value16 >> 8 << 8) | (uint8_t)(value18 - 1);
        r->x = x_f52d;
        r->y = y_f52d;
        r->c = value16 >= value17;
        r->v = overflow_f52d;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank_f52d;
        r->dp = direct_page_f52d;
        RETURN_RTS(c);
    }
    BUS8_SET(c, (data_bank_f52d << 0x10) + 0xE05D + x_f52d, 0);
    BUS8_SET(c, (data_bank_f52d << 0x10) + 0xE036 + x_f52d, 0);
    BUS8_SET(c, (data_bank_f52d << 0x10) + 0xE05A + x_f52d, 0);
    BUS8_SET(c, (uint16_t)(direct_page_f52d + 3), (uint8_t)value16 & 0x0F);
    BUS8_SET(c, (uint16_t)(direct_page_f52d + 4), 0);
    uint8_t value20 = BUS8_RDP(c, (data_bank_f52d << 0x10) + 0xE01C + x_f52d);
    if (value20 == 0) {
        a_f57a = ((value20 << 8) | (value16 >> 8)) & 0xFF;
        a_hi_f57a = 0;
        x_f57a = x_f52d;
        y_f57a = y_f52d;
        direct_page_f57a = direct_page_f52d;
        data_bank_f57a = data_bank_f52d;
        goto shared_F57A;
    }
    BUS8_SET(c, (data_bank_f52d << 0x10) + 0xE013 + x_f52d, 0);
    if (!(value16 >> 8 & 0x80)) {
        BUS16_SET(c, direct_page_f52d, ((value20 << 8) | (value16 >> 8)) & 0x7F);
        uint16_t value21 = BUS16_RDP(c, direct_page_f52d);
        uint16_t value22 = BUS16_RDP(c, (uint16_t)(direct_page_f52d + 3));
        uint16_t value23 = BUS16_RDP(c, (data_bank_f52d << 0x10) + 0xE065 + x_f52d);
        a_f585 = (uint8_t)((uint16_t)((uint16_t)((uint16_t)(((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F)) + value22 + (((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) << 1) + value23 + ((uint16_t)((uint16_t)(((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F)) + value22 + (((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) >> 0x0F));
        a_hi_f585 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)(((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F)) + value22 + (((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) << 1) + value23 + ((uint16_t)((uint16_t)(((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F)) + value22 + (((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) >> 0x0F)) >> 8;
        x_f585 = x_f52d;
        y_f585 = y_f52d;
        carry_f585 = (uint16_t)((uint16_t)((uint16_t)(((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F)) + value22 + (((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) << 1) + value23 + ((uint16_t)((uint16_t)(((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F)) + value22 + (((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) >> 0x0F) > 0xFFFF;
        overflow_f585 = (((uint16_t)((uint16_t)((uint16_t)(((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F)) + value22 + (((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) << 1) ^ (uint16_t)((uint16_t)((uint16_t)((uint16_t)(((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F)) + value22 + (((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) << 1) + value23 + ((uint16_t)((uint16_t)(((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F)) + value22 + (((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) >> 0x0F))) & (value23 ^ (uint16_t)((uint16_t)((uint16_t)((uint16_t)(((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F)) + value22 + (((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) << 1) + value23 + ((uint16_t)((uint16_t)(((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F)) + value22 + (((((value20 << 8) | (value16 >> 8)) & 0x7F) << 1) + value21 + ((((value20 << 8) | (value16 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) >> 0x0F))) & 0x8000) != 0;
        direct_page_f585 = direct_page_f52d;
        data_bank_f585 = data_bank_f52d;
        goto shared_F585;
    }
    a_f57a = ((value20 << 8) | (value16 >> 8)) & 0x7F;
    a_hi_f57a = 0;
    x_f57a = x_f52d;
    y_f57a = y_f52d;
    direct_page_f57a = direct_page_f52d;
    data_bank_f57a = data_bank_f52d;
    goto shared_F57A;
    shared_F52D_1:;
    BUS16_SET(c, (uint16_t)(direct_page_f52d2 + 2), 0xD1);
    uint16_t value24 = BUS16_RDP(c, (data_bank_f52d2 << 0x10) + 0xE010 + x_f52d2);
    uint16_t value25 = BUS16_RDP(c, (data_bank_f52d2 << 0x10) + 0xE030 + x_f52d2);
    BUS16_SET(c, (data_bank_f52d2 << 0x10) + 0xE030 + x_f52d2, value24);
    if (value24 == value25) {
        uint8_t value26 = BUS8_RDP(c, (data_bank_f52d2 << 0x10) + 0xE012 + x_f52d2);
        if (value26 == 0) {
            uint16_t value27 = BUS16_RDP(c, (data_bank_f52d2 << 0x10) + 0xE016 + x_f52d2);
            BUS16_SET(c, direct_page_f52d2, value27);
            a_hi_f5a1 = value27 >> 8;
            x_f5a1 = x_f52d2;
            y_f5a1 = y_f52d2;
            carry_f5a1 = value24 >= value25;
            overflow_f5a1 = overflow_f52d2;
            direct_page_f5a1 = direct_page_f52d2;
            data_bank_f5a1 = data_bank_f52d2;
            goto shared_F5A1;
        }
        BUS8_SET(c, (data_bank_f52d2 << 0x10) + 0xE012 + x_f52d2, (uint8_t)(value26 - 1));
        r->a = (value24 >> 8 << 8) | (uint8_t)(value26 - 1);
        r->x = x_f52d2;
        r->y = y_f52d2;
        r->c = value24 >= value25;
        r->v = overflow_f52d2;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank_f52d2;
        r->dp = direct_page_f52d2;
        RETURN_RTS(c);
    }
    BUS8_SET(c, (data_bank_f52d2 << 0x10) + 0xE05D + x_f52d2, 0);
    BUS8_SET(c, (data_bank_f52d2 << 0x10) + 0xE036 + x_f52d2, 0);
    BUS8_SET(c, (data_bank_f52d2 << 0x10) + 0xE05A + x_f52d2, 0);
    BUS8_SET(c, (uint16_t)(direct_page_f52d2 + 3), (uint8_t)value24 & 0x0F);
    BUS8_SET(c, (uint16_t)(direct_page_f52d2 + 4), 0);
    uint8_t value28 = BUS8_RDP(c, (data_bank_f52d2 << 0x10) + 0xE01C + x_f52d2);
    if (value28 == 0) {
        a_f57a = ((value28 << 8) | (value24 >> 8)) & 0xFF;
        a_hi_f57a = 0;
        x_f57a = x_f52d2;
        y_f57a = y_f52d2;
        direct_page_f57a = direct_page_f52d2;
        data_bank_f57a = data_bank_f52d2;
        goto shared_F57A;
    }
    BUS8_SET(c, (data_bank_f52d2 << 0x10) + 0xE013 + x_f52d2, 0);
    if (!(value24 >> 8 & 0x80)) {
        BUS16_SET(c, direct_page_f52d2, ((value28 << 8) | (value24 >> 8)) & 0x7F);
        uint16_t value29 = BUS16_RDP(c, direct_page_f52d2);
        uint16_t value30 = BUS16_RDP(c, (uint16_t)(direct_page_f52d2 + 3));
        uint16_t value31 = BUS16_RDP(c, (data_bank_f52d2 << 0x10) + 0xE065 + x_f52d2);
        a_f585 = (uint8_t)((uint16_t)((uint16_t)((uint16_t)(((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F)) + value30 + (((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) << 1) + value31 + ((uint16_t)((uint16_t)(((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F)) + value30 + (((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) >> 0x0F));
        a_hi_f585 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)(((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F)) + value30 + (((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) << 1) + value31 + ((uint16_t)((uint16_t)(((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F)) + value30 + (((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) >> 0x0F)) >> 8;
        x_f585 = x_f52d2;
        y_f585 = y_f52d2;
        carry_f585 = (uint16_t)((uint16_t)((uint16_t)(((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F)) + value30 + (((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) << 1) + value31 + ((uint16_t)((uint16_t)(((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F)) + value30 + (((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) >> 0x0F) > 0xFFFF;
        overflow_f585 = (((uint16_t)((uint16_t)((uint16_t)(((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F)) + value30 + (((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) << 1) ^ (uint16_t)((uint16_t)((uint16_t)((uint16_t)(((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F)) + value30 + (((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) << 1) + value31 + ((uint16_t)((uint16_t)(((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F)) + value30 + (((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) >> 0x0F))) & (value31 ^ (uint16_t)((uint16_t)((uint16_t)((uint16_t)(((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F)) + value30 + (((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) << 1) + value31 + ((uint16_t)((uint16_t)(((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F)) + value30 + (((((value28 << 8) | (value24 >> 8)) & 0x7F) << 1) + value29 + ((((value28 << 8) | (value24 >> 8)) & 0x7F) >> 0x0F) > 0xFFFF)) >> 0x0F))) & 0x8000) != 0;
        direct_page_f585 = direct_page_f52d2;
        data_bank_f585 = data_bank_f52d2;
        goto shared_F585;
    }
    a_f57a = ((value28 << 8) | (value24 >> 8)) & 0x7F;
    a_hi_f57a = 0;
    x_f57a = x_f52d2;
    y_f57a = y_f52d2;
    direct_page_f57a = direct_page_f52d2;
    data_bank_f57a = data_bank_f52d2;
    goto shared_F57A;
    shared_F5A1:;
    uint8_t value32 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f5a1 + 2)) << 0x10) + BUS16_RDP(c, direct_page_f5a1), BUS8_RDP(c, (uint16_t)(direct_page_f5a1 + 2)));
    if (!(value32 & 0x80)) {
        a_hi_f5ac = a_hi_f5a1;
        x_f5ac = x_f5a1;
        direct_page_f5ac = direct_page_f5a1;
        data_bank_f5ac = data_bank_f5a1;
        goto shared_F5AC;
    }
    r->a = (a_hi_f5a1 << 8) | value32;
    r->x = x_f5a1;
    r->y = y_f5a1;
    r->c = carry_f5a1;
    r->z = value32 == 0;
    r->n = value32 & 0x80;
    r->v = overflow_f5a1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_f5a1;
    r->dp = direct_page_f5a1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF5A9, 0xC0F90B); GUARD_JSR(c, sp_call, 0xF5A9); } /* read_actor_animation_commands_and_native_nonlocal_returns */
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret4 = r->db;
    bool m_ret4 = r->mf;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all4 = r->a;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret4 = r->y;
    bool carry_ret4 = r->c;
    bool overflow_ret4 = r->v;
    if (carry_ret4) {
        if (m_ret4) {
            a_hi_f5a12 = a_all4 >> 8;
            x_f5a12 = x_ret4;
            y_f5a12 = y_ret4;
            carry_f5a12 = carry_ret4;
            overflow_f5a12 = overflow_ret4;
            direct_page_f5a12 = dp_ret3;
            data_bank_f5a12 = db_ret4;
            goto shared_F5A1_1;
        } else {
            a_hi_f5a1 = a_all4 >> 8;
            x_f5a1 = x_ret4;
            y_f5a1 = y_ret4;
            carry_f5a1 = carry_ret4;
            overflow_f5a1 = overflow_ret4;
            direct_page_f5a1 = dp_ret3;
            data_bank_f5a1 = db_ret4;
            goto shared_F5A1;
        }
    }
    if (m_ret4) {
        a_hi_f5ac = a_all4 >> 8;
        x_f5ac = x_ret4;
        direct_page_f5ac = dp_ret3;
        data_bank_f5ac = db_ret4;
        goto shared_F5AC;
    } else {
        a_hi_f5ac2 = a_all4 >> 8;
        x_f5ac2 = x_ret4;
        direct_page_f5ac2 = dp_ret3;
        data_bank_f5ac2 = db_ret4;
        goto shared_F5AC_1;
    }
    shared_F57A:;
    BUS16_SET(c, direct_page_f57a, (a_hi_f57a << 8) | a_f57a);
    uint16_t value33 = BUS16_RDP(c, direct_page_f57a);
    uint16_t value34 = BUS16_RDP(c, (uint16_t)(direct_page_f57a + 3));
    uint16_t value35 = BUS16_RDP(c, (data_bank_f57a << 0x10) + 0xE075 + x_f57a);
    a_f585 = (uint8_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F)) + value34 + ((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F) > 0xFFFF)) << 1) + value35 + ((uint16_t)((uint16_t)((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F)) + value34 + ((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F) > 0xFFFF)) >> 0x0F));
    a_hi_f585 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F)) + value34 + ((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F) > 0xFFFF)) << 1) + value35 + ((uint16_t)((uint16_t)((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F)) + value34 + ((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F) > 0xFFFF)) >> 0x0F)) >> 8;
    x_f585 = x_f57a;
    y_f585 = y_f57a;
    carry_f585 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F)) + value34 + ((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F) > 0xFFFF)) << 1) + value35 + ((uint16_t)((uint16_t)((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F)) + value34 + ((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F) > 0xFFFF)) >> 0x0F) > 0xFFFF;
    overflow_f585 = (((uint16_t)((uint16_t)((uint16_t)((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F)) + value34 + ((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F) > 0xFFFF)) << 1) ^ (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F)) + value34 + ((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F) > 0xFFFF)) << 1) + value35 + ((uint16_t)((uint16_t)((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F)) + value34 + ((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F) > 0xFFFF)) >> 0x0F))) & (value35 ^ (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F)) + value34 + ((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F) > 0xFFFF)) << 1) + value35 + ((uint16_t)((uint16_t)((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F)) + value34 + ((uint16_t)(((a_hi_f57a << 8) | a_f57a) << 1) + value33 + (((a_hi_f57a << 8) | a_f57a) >> 0x0F) > 0xFFFF)) >> 0x0F))) & 0x8000) != 0;
    direct_page_f585 = direct_page_f57a;
    data_bank_f585 = data_bank_f57a;
    goto shared_F585;
    shared_F585:;
    BUS16_SET(c, direct_page_f585, (a_hi_f585 << 8) | a_f585);
    uint16_t value36 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f585 + 2)) << 0x10) + BUS16_RDP(c, direct_page_f585), BUS8_RDP(c, (uint16_t)(direct_page_f585 + 2)));
    BUS16_SET(c, (data_bank_f585 << 0x10) + 0xE018 + x_f585, value36);
    BUS16_SET(c, direct_page_f585, value36);
    a_hi_f5a1 = value36 >> 8;
    x_f5a1 = x_f585;
    y_f5a1 = y_f585;
    carry_f5a1 = carry_f585;
    overflow_f5a1 = overflow_f585;
    direct_page_f5a1 = direct_page_f585;
    data_bank_f5a1 = data_bank_f585;
    goto shared_F5A1;
    shared_F5AC:;
    uint16_t value37 = BUS16_RDP(c, direct_page_f5ac);
    BUS16_SET(c, (data_bank_f5ac << 0x10) + 0xE016 + x_f5ac, (uint16_t)(value37 + 2));
    uint8_t value38 = BUS8_RDP(c, (data_bank_f5ac << 0x10) + 0xE00C + x_f5ac);
    BUS8_SET(c, (data_bank_f5ac << 0x10) + 0xE00C + x_f5ac, (uint8_t)(value38 + 1));
    uint8_t value39 = BUS8_RDP(c, (data_bank_f5ac << 0x10) + 0xE010 + x_f5ac);
    uint16_t value40 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f5ac + 2)) << 0x10) + BUS16_RDP(c, direct_page_f5ac), BUS8_RDP(c, (uint16_t)(direct_page_f5ac + 2)));
    if (!(value39 & 0x80)) {
        a_f5c8 = (uint8_t)value40;
        a_hi_f5c8 = value40 >> 8;
        x_f5c8 = x_f5ac;
        direct_page_f5c8 = direct_page_f5ac;
        data_bank_f5c8 = data_bank_f5ac;
        goto shared_F5C8;
    }
    a_f5c8 = (uint8_t)value40 ^ 0x20;
    a_hi_f5c8 = value40 >> 8;
    x_f5c8 = x_f5ac;
    direct_page_f5c8 = direct_page_f5ac;
    data_bank_f5c8 = data_bank_f5ac;
    goto shared_F5C8;
    shared_F5A1_1:;
    uint8_t value41 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f5a12 + 2)) << 0x10) + BUS16_RDP(c, direct_page_f5a12), BUS8_RDP(c, (uint16_t)(direct_page_f5a12 + 2)));
    if (!(value41 & 0x80)) {
        a_hi_f5ac = a_hi_f5a12;
        x_f5ac = x_f5a12;
        direct_page_f5ac = direct_page_f5a12;
        data_bank_f5ac = data_bank_f5a12;
        goto shared_F5AC;
    }
    r->a = (a_hi_f5a12 << 8) | value41;
    r->x = x_f5a12;
    r->y = y_f5a12;
    r->c = carry_f5a12;
    r->z = value41 == 0;
    r->n = value41 & 0x80;
    r->v = overflow_f5a12;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_f5a12;
    r->dp = direct_page_f5a12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF5A9, 0xC0F90B); GUARD_JSR(c, sp_call, 0xF5A9); } /* read_actor_animation_commands_and_native_nonlocal_returns */
    uint16_t dp_ret4 = r->dp;
    uint8_t db_ret5 = r->db;
    bool m_ret5 = r->mf;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all5 = r->a;
    uint16_t x_ret5 = r->x;
    uint16_t y_ret5 = r->y;
    bool carry_ret5 = r->c;
    bool overflow_ret5 = r->v;
    if (carry_ret5) {
        if (m_ret5) {
            a_hi_f5a12 = a_all5 >> 8;
            x_f5a12 = x_ret5;
            y_f5a12 = y_ret5;
            carry_f5a12 = carry_ret5;
            overflow_f5a12 = overflow_ret5;
            direct_page_f5a12 = dp_ret4;
            data_bank_f5a12 = db_ret5;
            goto shared_F5A1_1;
        } else {
            a_hi_f5a1 = a_all5 >> 8;
            x_f5a1 = x_ret5;
            y_f5a1 = y_ret5;
            carry_f5a1 = carry_ret5;
            overflow_f5a1 = overflow_ret5;
            direct_page_f5a1 = dp_ret4;
            data_bank_f5a1 = db_ret5;
            goto shared_F5A1;
        }
    }
    if (m_ret5) {
        a_hi_f5ac = a_all5 >> 8;
        x_f5ac = x_ret5;
        direct_page_f5ac = dp_ret4;
        data_bank_f5ac = db_ret5;
        goto shared_F5AC;
    } else {
        a_hi_f5ac2 = a_all5 >> 8;
        x_f5ac2 = x_ret5;
        direct_page_f5ac2 = dp_ret4;
        data_bank_f5ac2 = db_ret5;
        goto shared_F5AC_1;
    }
    shared_F5AC_1:;
    uint16_t value42 = BUS16_RDP(c, direct_page_f5ac2);
    BUS16_SET(c, (data_bank_f5ac2 << 0x10) + 0xE016 + x_f5ac2, (uint16_t)(value42 + 2));
    uint8_t value43 = BUS8_RDP(c, (data_bank_f5ac2 << 0x10) + 0xE00C + x_f5ac2);
    BUS8_SET(c, (data_bank_f5ac2 << 0x10) + 0xE00C + x_f5ac2, (uint8_t)(value43 + 1));
    uint8_t value44 = BUS8_RDP(c, (data_bank_f5ac2 << 0x10) + 0xE010 + x_f5ac2);
    uint16_t value45 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f5ac2 + 2)) << 0x10) + BUS16_RDP(c, direct_page_f5ac2), BUS8_RDP(c, (uint16_t)(direct_page_f5ac2 + 2)));
    if (!(value44 & 0x80)) {
        a_f5c8 = (uint8_t)value45;
        a_hi_f5c8 = value45 >> 8;
        x_f5c8 = x_f5ac2;
        direct_page_f5c8 = direct_page_f5ac2;
        data_bank_f5c8 = data_bank_f5ac2;
        goto shared_F5C8;
    }
    a_f5c8 = (uint8_t)value45 ^ 0x20;
    a_hi_f5c8 = value45 >> 8;
    x_f5c8 = x_f5ac2;
    direct_page_f5c8 = direct_page_f5ac2;
    data_bank_f5c8 = data_bank_f5ac2;
    goto shared_F5C8;
    shared_F5C8:;
    RAM8(0x0000 + sp0) = a_f5c8;
    BUS8_SET(c, (data_bank_f5c8 << 0x10) + 0xE028 + x_f5c8, (uint8_t)(a_f5c8 << 1));
    uint8_t value46 = RAM8(0x0000 + sp0);
    if ((value46 & 7) < 4) {
        a_f5db = value46 & 7;
        a_hi_f5db = a_hi_f5c8;
        x_f5db = x_f5c8;
        direct_page_f5db = direct_page_f5c8;
        data_bank_f5db = data_bank_f5c8;
        goto shared_F5DB;
    }
    BUS8_SET(c, (data_bank_f5c8 << 0x10) + 0xE089 + x_f5c8, value46 & 3);
    a_f5db = 0;
    a_hi_f5db = a_hi_f5c8;
    x_f5db = x_f5c8;
    direct_page_f5db = direct_page_f5c8;
    data_bank_f5db = data_bank_f5c8;
    goto shared_F5DB;
    shared_F5DB:;
    BUS8_SET(c, (data_bank_f5db << 0x10) + 0xE012 + x_f5db, a_f5db);
    BUS8_SET(c, (uint16_t)(direct_page_f5db + 5), 0xD1);
    uint8_t value47 = BUS8_RDP(c, (data_bank_f5db << 0x10) + 0xE041 + x_f5db);
    if (value47 == 0) {
        a_f5eb = value47;
        a_hi_f5eb = a_hi_f5db;
        x_f5eb = x_f5db;
        direct_page_f5eb = direct_page_f5db;
        data_bank_f5eb = data_bank_f5db;
        goto shared_F5EB;
    }
    uint8_t value48 = BUS8_RDP(c, (data_bank_f5db << 0x10) + 0xE040 + x_f5db);
    a_f5eb = a_hi_f5db;
    a_hi_f5eb = value48;
    x_f5eb = x_f5db;
    direct_page_f5eb = direct_page_f5db;
    data_bank_f5eb = data_bank_f5db;
    goto shared_F5EB;
    shared_F5EB:;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = ((a_f5eb << 8) | a_hi_f5eb) & 0xFF;
    BUS16_SET(c, (data_bank_f5eb << 0x10) + 0xE026 + x_f5eb, (((a_f5eb << 8) | a_hi_f5eb) & 0xFF) << 1);
    uint16_t value49 = BUS16_RDP(c, (data_bank_f5eb << 0x10) + 0xE02A + x_f5eb);
    BUS16_SET(c, direct_page_f5eb, (uint16_t)(((((a_f5eb << 8) | a_hi_f5eb) & 0xFF) << 1) + value49));
    uint8_t value50 = RAM8(0x0000 + sp0 - 1);
    uint8_t value51 = RAM8(0x0000 + sp0);
    uint16_t value52 = BUS16_RDP(c, (data_bank_f5eb << 0x10) + 0xE07E + x_f5eb);
    BUS16_SET(c, (uint16_t)(direct_page_f5eb + 3), (uint16_t)(((value51 << 8) | value50) + value52));
    uint16_t value53 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f5eb + 2)) << 0x10) + BUS16_RDP(c, direct_page_f5eb), BUS8_RDP(c, (uint16_t)(direct_page_f5eb + 2)));
    RAM8(0x0000 + sp0) = value53 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value53;
    BUS16_SET(c, direct_page_f5eb, ((((uint8_t)value53 << 8) | (value53 >> 8)) & 0xFF) << 1);
    uint8_t value54 = RAM8(0x0000 + sp0 - 1);
    uint8_t value55 = RAM8(0x0000 + sp0);
    uint8_t value56 = BUS8_RDP(c, (data_bank_f5eb << 0x10) + 0xE041 + x_f5eb);
    if (value56 >= 1) {
        a_f61e = (uint8_t)((value55 << 8) | value54) & 0xC0;
        a_hi_f61e = value56;
        x_f61e = x_f5eb;
        direct_page_f61e = direct_page_f5eb;
        data_bank_f61e = data_bank_f5eb;
        goto shared_F61E;
    }
    uint8_t value57 = BUS8_RDP(c, (data_bank_f5eb << 0x10) + 0xE028 + x_f5eb);
    a_f61e = ((uint8_t)((value55 << 8) | value54) & 0xC0) ^ value57;
    a_hi_f61e = value56;
    x_f61e = x_f5eb;
    direct_page_f61e = direct_page_f5eb;
    data_bank_f61e = data_bank_f5eb;
    goto shared_F61E;
    shared_F61E:;
    BUS8_SET(c, (data_bank_f61e << 0x10) + 0xE088 + x_f61e, a_f61e);
    if (x_f61e == 0) {
        a_f62f = 0;
        a_hi_f62f = a_hi_f61e;
        x_f62f = x_f61e;
        direct_page_f62f = direct_page_f61e;
        data_bank_f62f = data_bank_f61e;
        goto shared_F62F;
    }
    if (x_f61e >= 0x0600) {
        a_f62f = 0;
        a_hi_f62f = a_hi_f61e;
        x_f62f = x_f61e;
        direct_page_f62f = direct_page_f61e;
        data_bank_f62f = data_bank_f61e;
        goto shared_F62F;
    }
    uint8_t value58 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f61e + 5)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page_f61e + 3)), BUS8_RDP(c, (uint16_t)(direct_page_f61e + 5)));
    a_f62f = value58;
    a_hi_f62f = a_hi_f61e;
    x_f62f = x_f61e;
    direct_page_f62f = direct_page_f61e;
    data_bank_f62f = data_bank_f61e;
    goto shared_F62F;
    shared_F62F:;
    BUS8_SET(c, (data_bank_f62f << 0x10) + 0xE025 + x_f62f, a_f62f);
    uint8_t value59 = BUS8_RDP(c, (data_bank_f62f << 0x10) + 0xE033 + x_f62f);
    BUS8_SET(c, (uint16_t)(direct_page_f62f + 2), value59);
    BUS8_SET(c, (uint16_t)(direct_page_f62f + 0x12), value59);
    uint16_t value60 = BUS16_RDP(c, (data_bank_f62f << 0x10) + 0xE072 + x_f62f);
    uint16_t value61 = BUS16_RDP(c, direct_page_f62f);
    BUS16_SET(c, direct_page_f62f, (uint16_t)(value60 + value61));
    uint16_t value62 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f62f + 2)) << 0x10) + BUS16_RDP(c, direct_page_f62f), BUS8_RDP(c, (uint16_t)(direct_page_f62f + 2)));
    uint16_t value63 = BUS16_RDP(c, (uint16_t)(direct_page_f62f + 0x14));
    BUS16_SET(c, (uint16_t)(direct_page_f62f + 0x10), value62);
    uint16_t value64 = BUS16_RDP(c, (data_bank_f62f << 0x10) + 0xE080 + value63);
    BUS16_SET(c, (uint16_t)(direct_page_f62f + 0x0A), value64);
    uint16_t value65 = BUS16_RDP(c, (data_bank_f62f << 0x10) + 0xE06E + value63);
    BUS8_SET(c, (uint16_t)(direct_page_f62f + 1), 0);
    uint8_t value66 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f62f + 0x12)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page_f62f + 0x10)), BUS8_RDP(c, (uint16_t)(direct_page_f62f + 0x12)));
    BUS8_SET(c, (uint16_t)(direct_page_f62f + 4), value66);
    if ((value66 & 0x0F) != 0) {
        a_f661 = value66 & 0x0F;
        a_hi_f661 = value64 >> 8;
        x_f661 = value63;
        y_f661 = value65;
        direct_page_f661 = direct_page_f62f;
        data_bank_f661 = data_bank_f62f;
        goto shared_F661;
    }
    a_f661 = 1;
    a_hi_f661 = value64 >> 8;
    x_f661 = value63;
    y_f661 = value65;
    direct_page_f661 = direct_page_f62f;
    data_bank_f661 = data_bank_f62f;
    goto shared_F661;
    shared_F661:;
    BUS8_SET(c, (data_bank_f661 << 0x10) + 0xE083 + x_f661, a_f661);
    BUS8_SET(c, direct_page_f661, (uint8_t)(a_f661 << 2));
    uint16_t value67 = BUS16_RDP(c, (uint16_t)(direct_page_f661 + 0x10));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_f661 + 0x10), (uint16_t)(value67 + 1));
    uint16_t value68 = BUS16_RDP(c, direct_page_f661);
    a_hi_f66e = a_hi_f661;
    x_f66e = value68;
    y_f66e = y_f661;
    direct_page_f66e = direct_page_f661;
    data_bank_f66e = data_bank_f661;
    goto shared_F66E;
    shared_F66E:;
    uint16_t value69 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f66e + 0x12)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page_f66e + 0x10)), BUS8_RDP(c, (uint16_t)(direct_page_f66e + 0x12)));
    if (value69 & 0x8000) {
        a_f686 = (uint8_t)value69;
        a_hi_f686 = value69 >> 8;
        x_f686 = x_f66e;
        y_f686 = y_f66e;
        direct_page_f686 = direct_page_f66e;
        data_bank_f686 = data_bank_f66e;
        goto shared_F686;
    }
    uint16_t value70 = BUS16_RDP(c, (uint16_t)(direct_page_f66e + 0x10));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_f66e + 0x10), (uint16_t)(value70 + 1));
    uint16_t value71 = BUS16_RDP(c, (uint16_t)(direct_page_f66e + 0x10));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_f66e + 0x10), (uint16_t)(value71 + 1));
    uint16_t value72 = BUS16_RDP(c, (uint16_t)(direct_page_f66e + 0x0A));
    BUS16_SET(c, (data_bank_f66e << 0x10) + y_f66e, (uint16_t)(((value69 & 0x3FF0) << 1) + value72 + ((value69 & 0x3FF0) >> 0x0F)));
    if ((uint16_t)(x_f66e - 1) != 0) {
        a_hi_f66e = (uint16_t)(((value69 & 0x3FF0) << 1) + value72 + ((value69 & 0x3FF0) >> 0x0F)) >> 8;
        x_f66e = (uint16_t)(x_f66e - 1);
        y_f66e = (uint16_t)(y_f66e + 2);
        goto shared_F66E;
    }
    if ((uint16_t)(x_f66e - 1) == 0) {
        a_hi_f6c0 = (uint16_t)(((value69 & 0x3FF0) << 1) + value72 + ((value69 & 0x3FF0) >> 0x0F)) >> 8;
        direct_page_f6c0 = direct_page_f66e;
        data_bank_f6c0 = data_bank_f66e;
        goto shared_F6C0;
    }
    a_f686 = (uint8_t)(((value69 & 0x3FF0) << 1) + value72 + ((value69 & 0x3FF0) >> 0x0F));
    a_hi_f686 = (uint16_t)(((value69 & 0x3FF0) << 1) + value72 + ((value69 & 0x3FF0) >> 0x0F)) >> 8;
    x_f686 = (uint16_t)(x_f66e - 1);
    y_f686 = (uint16_t)(y_f66e + 2);
    direct_page_f686 = direct_page_f66e;
    data_bank_f686 = data_bank_f66e;
    goto shared_F686;
    shared_F686:;
    uint16_t value73 = BUS16_RDP(c, (uint16_t)(direct_page_f686 + 0x10));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_f686 + 0x10), (uint16_t)(value73 + 1));
    uint16_t value74 = BUS16_RDP(c, (uint16_t)(direct_page_f686 + 0x10));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_f686 + 0x10), (uint16_t)(value74 + 1));
    RAM8(0x0000 + sp0) = a_hi_f686;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi_f686 << 8) | a_f686);
    BUS16_SET(c, (uint16_t)(direct_page_f686 + 2), ((a_hi_f686 << 8) | a_f686) & 0x0F);
    uint8_t value75 = RAM8(0x0000 + sp0 - 1);
    uint8_t value76 = RAM8(0x0000 + sp0);
    if (!((uint16_t)(((value76 << 8) | value75) << 1) & 0x8000)) {
        uint16_t value77 = BUS16_RDP(c, (uint16_t)(direct_page_f686 + 0x0A));
        a_f6b2 = (uint8_t)(((uint16_t)(((value76 << 8) | value75) << 1) & 0x7FE0) + value77);
        a_hi_f6b2 = (uint16_t)(((uint16_t)(((value76 << 8) | value75) << 1) & 0x7FE0) + value77) >> 8;
        x_f6b2 = x_f686;
        y_f6b2 = y_f686;
        direct_page_f6b2 = direct_page_f686;
        data_bank_f6b2 = data_bank_f686;
        goto shared_F6B2;
    }
    uint16_t value78 = BUS16_RDP(c, (uint16_t)(direct_page_f686 + 0x0A));
    a_f69a = (uint8_t)(((uint16_t)(((value76 << 8) | value75) << 1) & 0x7FE0) + value78);
    a_hi_f69a = (uint16_t)(((uint16_t)(((value76 << 8) | value75) << 1) & 0x7FE0) + value78) >> 8;
    x_f69a = x_f686;
    y_f69a = y_f686;
    direct_page_f69a = direct_page_f686;
    data_bank_f69a = data_bank_f686;
    goto shared_F69A;
    shared_F6C0:;
    uint16_t value79 = BUS16_RDP(c, (uint16_t)(direct_page_f6c0 + 0x14));
    uint16_t value80 = BUS16_RDP(c, (data_bank_f6c0 << 0x10) + 0xE083 + value79);
    BUS16_SET(c, (uint16_t)(direct_page_f6c0 + 6), value80 & 0x0F);
    uint16_t value81 = BUS16_RDP(c, (data_bank_f6c0 << 0x10) + 0xE08A + value79);
    BUS16_SET(c, (uint16_t)(direct_page_f6c0 + 0x0C), value81);
    BUS8_SET(c, (uint16_t)(direct_page_f6c0 + 1), 0);
    uint8_t value82 = BUS8_RDP(c, (data_bank_f6c0 << 0x10) + 0xE08E + value79);
    if (value82 == 0) {
        a_hi_f6f6 = value81 >> 8;
        x_f6f6 = value79;
        y_f6f6 = value80 & 0x0F;
        direct_page_f6f6 = direct_page_f6c0;
        data_bank_f6f6 = data_bank_f6c0;
        goto shared_F6F6;
    }
    if (value82 >= 4) {
        a_f6f2 = ((value82 & 3) << 1 << 1 << 1 << 1) ^ 0x20;
        a_hi_f6f2 = value81 >> 8;
        x_f6f2 = value79;
        y_f6f2 = value80 & 0x0F;
        direct_page_f6f2 = direct_page_f6c0;
        data_bank_f6f2 = data_bank_f6c0;
        goto shared_F6F2;
    }
    uint8_t value83 = BUS8_RDP(c, (uint16_t)(direct_page_f6c0 + 1));
    BUS8_SET(c, (uint16_t)(direct_page_f6c0 + 1), (value83 >> 1) | 0x80);
    if (value82 == 2) {
        a_hi_f6f6 = value81 >> 8;
        x_f6f6 = value79;
        y_f6f6 = value80 & 0x0F;
        direct_page_f6f6 = direct_page_f6c0;
        data_bank_f6f6 = data_bank_f6c0;
        goto shared_F6F6;
    }
    a_f6f2 = 0x30;
    a_hi_f6f2 = value81 >> 8;
    x_f6f2 = value79;
    y_f6f2 = value80 & 0x0F;
    direct_page_f6f2 = direct_page_f6c0;
    data_bank_f6f2 = data_bank_f6c0;
    goto shared_F6F2;
    shared_F6B2:;
    BUS16_SET(c, (data_bank_f6b2 << 0x10) + y_f6b2, (a_hi_f6b2 << 8) | a_f6b2);
    if ((uint16_t)(x_f6b2 - 1) == 0) {
        a_hi_f6c0 = a_hi_f6b2;
        direct_page_f6c0 = direct_page_f6b2;
        data_bank_f6c0 = data_bank_f6b2;
        goto shared_F6C0;
    }
    uint16_t value84 = BUS16_RDP(c, (uint16_t)(direct_page_f6b2 + 2));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_f6b2 + 2), (uint16_t)(value84 - 1));
    if (!((uint16_t)(value84 - 1) & 0x8000)) {
        x_f6b2 = (uint16_t)(x_f6b2 - 1);
        y_f6b2 = (uint16_t)(y_f6b2 + 2);
        goto shared_F6B2;
    }
    if ((uint16_t)(value84 - 1) & 0x8000) {
        a_hi_f66e = a_hi_f6b2;
        x_f66e = (uint16_t)(x_f6b2 - 1);
        y_f66e = (uint16_t)(y_f6b2 + 2);
        direct_page_f66e = direct_page_f6b2;
        data_bank_f66e = data_bank_f6b2;
        goto shared_F66E;
    }
    a_hi_f6c0 = a_hi_f6b2;
    direct_page_f6c0 = direct_page_f6b2;
    data_bank_f6c0 = data_bank_f6b2;
    goto shared_F6C0;
    shared_F69A:;
    BUS16_SET(c, (data_bank_f69a << 0x10) + y_f69a, (a_hi_f69a << 8) | a_f69a);
    if ((uint16_t)(x_f69a - 1) == 0) {
        a_hi_f6c0 = a_hi_f69a;
        direct_page_f6c0 = direct_page_f69a;
        data_bank_f6c0 = data_bank_f69a;
        goto shared_F6C0;
    }
    uint16_t value85 = BUS16_RDP(c, (uint16_t)(direct_page_f69a + 2));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_f69a + 2), (uint16_t)(value85 - 1));
    if ((uint16_t)(value85 - 1) & 0x8000) {
        a_hi_f66e = a_hi_f69a;
        x_f66e = (uint16_t)(x_f69a - 1);
        y_f66e = (uint16_t)(y_f69a + 2);
        direct_page_f66e = direct_page_f69a;
        data_bank_f66e = data_bank_f69a;
        goto shared_F66E;
    }
    uint8_t a_f69a_next = (uint8_t)(((a_hi_f69a << 8) | a_f69a) + 0x20);
    uint8_t a_hi_f69a_next = (uint16_t)(((a_hi_f69a << 8) | a_f69a) + 0x20) >> 8;
    uint16_t x_f69a_next = (uint16_t)(x_f69a - 1);
    uint16_t y_f69a_next = (uint16_t)(y_f69a + 2);
    a_f69a = a_f69a_next;
    a_hi_f69a = a_hi_f69a_next;
    x_f69a = x_f69a_next;
    y_f69a = y_f69a_next;
    goto shared_F69A;
    shared_F6F6:;
    uint8_t value86 = BUS8_RDP(c, (data_bank_f6f6 << 0x10) + 0xE088 + x_f6f6);
    BUS8_SET(c, (uint16_t)(direct_page_f6f6 + 2), value86 & 0xC0);
    uint8_t value87 = BUS8_RDP(c, (data_bank_f6f6 << 0x10) + 0xE074 + x_f6f6);
    BUS8_SET(c, (uint16_t)(direct_page_f6f6 + 3), value87 & 0x7F);
    a_hi_f704 = a_hi_f6f6;
    x_f704 = x_f6f6;
    y_f704 = y_f6f6;
    direct_page_f704 = direct_page_f6f6;
    data_bank_f704 = data_bank_f6f6;
    goto shared_F704;
    shared_F6F2:;
    uint8_t value88 = BUS8_RDP(c, (uint16_t)(direct_page_f6f2 + 0x0D));
    BUS8_SET(c, (uint16_t)(direct_page_f6f2 + 0x0D), a_f6f2 ^ value88);
    a_hi_f6f6 = a_hi_f6f2;
    x_f6f6 = x_f6f2;
    y_f6f6 = y_f6f2;
    direct_page_f6f6 = direct_page_f6f2;
    data_bank_f6f6 = data_bank_f6f2;
    goto shared_F6F6;
    shared_F704:;
    uint16_t value89 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f704 + 0x12)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page_f704 + 0x10)), BUS8_RDP(c, (uint16_t)(direct_page_f704 + 0x12)));
    uint16_t value90 = BUS16_RDP(c, (uint16_t)(direct_page_f704 + 0x10));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_f704 + 0x10), (uint16_t)(value90 + 1));
    uint16_t value91 = BUS16_RDP(c, (uint16_t)(direct_page_f704 + 0x10));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_f704 + 0x10), (uint16_t)(value91 + 1));
    uint8_t value92 = BUS8_RDP(c, direct_page_f704);
    BUS8_SET(c, direct_page_f704, (value92 >> 1) | (value89 >> 0x0F << 7));
    uint8_t value93 = BUS8_RDP(c, direct_page_f704);
    BUS8_SET(c, direct_page_f704, (value93 >> 1) | ((uint8_t)value89 >> 7 << 7));
    if ((uint8_t)((uint8_t)value89 << 1) < 0x80) {
        a_f721 = (uint8_t)((uint8_t)value89 << 1);
        a_hi_f721 = (uint8_t)(value89 >> 8 << 1);
        x_f721 = x_f704;
        y_f721 = y_f704;
        direct_page_f721 = direct_page_f704;
        data_bank_f721 = data_bank_f704;
        goto shared_F721;
    }
    uint8_t value94 = BUS8_RDP(c, (uint16_t)(direct_page_f704 + 2));
    if (value94 & 0x80) {
        a_f726 = ((uint8_t)((uint8_t)value89 << 1) >> 1) | (((uint8_t)((uint8_t)value89 << 1) >= 0x80) << 7);
        a_hi_f726 = (uint8_t)(value89 >> 8 << 1);
        x_f726 = x_f704;
        y_f726 = y_f704;
        direct_page_f726 = direct_page_f704;
        data_bank_f726 = data_bank_f704;
        goto shared_F726;
    }
    if (!(value94 & 0x80)) {
        a_f72b = ((uint8_t)((uint8_t)value89 << 1) >> 1) | (((uint8_t)((uint8_t)value89 << 1) >= 0x80) << 7);
        a_hi_f72b = (uint8_t)(value89 >> 8 << 1);
        x_f72b = x_f704;
        y_f72b = y_f704;
        direct_page_f72b = direct_page_f704;
        data_bank_f72b = data_bank_f704;
        goto shared_F72B;
    }
    a_f721 = ((uint8_t)((uint8_t)value89 << 1) >> 1) | (((uint8_t)((uint8_t)value89 << 1) >= 0x80) << 7);
    a_hi_f721 = (uint8_t)(value89 >> 8 << 1);
    x_f721 = x_f704;
    y_f721 = y_f704;
    direct_page_f721 = direct_page_f704;
    data_bank_f721 = data_bank_f704;
    goto shared_F721;
    shared_F721:;
    uint8_t value95 = BUS8_RDP(c, (uint16_t)(direct_page_f721 + 2));
    if (!(value95 & 0x80)) {
        a_f72b = a_f721 >> 1;
        a_hi_f72b = a_hi_f721;
        x_f72b = x_f721;
        y_f72b = y_f721;
        direct_page_f72b = direct_page_f721;
        data_bank_f72b = data_bank_f721;
        goto shared_F72B;
    }
    a_f726 = a_f721 >> 1;
    a_hi_f726 = a_hi_f721;
    x_f726 = x_f721;
    y_f726 = y_f721;
    direct_page_f726 = direct_page_f721;
    data_bank_f726 = data_bank_f721;
    goto shared_F726;
    shared_F726:;
    a_f72b = (uint8_t)(a_f726 + 0x0F) ^ 0xFF;
    a_hi_f72b = a_hi_f726;
    x_f72b = x_f726;
    y_f72b = y_f726;
    direct_page_f72b = direct_page_f726;
    data_bank_f72b = data_bank_f726;
    goto shared_F72B;
    shared_F72B:;
    if (!(a_hi_f72b & 0x80)) {
        a_f736 = a_hi_f72b;
        a_hi_f736 = a_f72b;
        x_f736 = x_f72b;
        y_f736 = y_f72b;
        direct_page_f736 = direct_page_f72b;
        data_bank_f736 = data_bank_f72b;
        goto shared_F736;
    }
    uint8_t value96 = BUS8_RDP(c, (uint16_t)(direct_page_f72b + 2));
    if (value96 & 0x40) {
        a_f73b = (a_hi_f72b >> 1) | 0x80;
        a_hi_f73b = a_f72b;
        x_f73b = x_f72b;
        y_f73b = y_f72b;
        direct_page_f73b = direct_page_f72b;
        data_bank_f73b = data_bank_f72b;
        goto shared_F73B;
    }
    if (!(value96 & 0x40)) {
        a_f740 = (a_hi_f72b >> 1) | 0x80;
        a_hi_f740 = a_f72b;
        x_f740 = x_f72b;
        y_f740 = y_f72b;
        direct_page_f740 = direct_page_f72b;
        data_bank_f740 = data_bank_f72b;
        goto shared_F740;
    }
    a_f736 = (a_hi_f72b >> 1) | 0x80;
    a_hi_f736 = a_f72b;
    x_f736 = x_f72b;
    y_f736 = y_f72b;
    direct_page_f736 = direct_page_f72b;
    data_bank_f736 = data_bank_f72b;
    goto shared_F736;
    shared_F736:;
    uint8_t value97 = BUS8_RDP(c, (uint16_t)(direct_page_f736 + 2));
    if (!(value97 & 0x40)) {
        a_f740 = a_f736 >> 1;
        a_hi_f740 = a_hi_f736;
        x_f740 = x_f736;
        y_f740 = y_f736;
        direct_page_f740 = direct_page_f736;
        data_bank_f740 = data_bank_f736;
        goto shared_F740;
    }
    a_f73b = a_f736 >> 1;
    a_hi_f73b = a_hi_f736;
    x_f73b = x_f736;
    y_f73b = y_f736;
    direct_page_f73b = direct_page_f736;
    data_bank_f73b = data_bank_f736;
    goto shared_F73B;
    shared_F73B:;
    a_f740 = (uint8_t)(a_f73b + 0x0F) ^ 0xFF;
    a_hi_f740 = a_hi_f73b;
    x_f740 = x_f73b;
    y_f740 = y_f73b;
    direct_page_f740 = direct_page_f73b;
    data_bank_f740 = data_bank_f73b;
    goto shared_F740;
    shared_F740:;
    BUS16_SET(c, (data_bank_f740 << 0x10) + 0xE090 + x_f740, (a_hi_f740 << 8) | a_f740);
    uint8_t value98 = BUS8_RDP(c, direct_page_f740);
    if (!(value98 & 0x80)) {
        a_f75a = value98;
        a_hi_f75a = a_hi_f740;
        x_f75a = x_f740;
        y_f75a = y_f740;
        direct_page_f75a = direct_page_f740;
        data_bank_f75a = data_bank_f740;
        goto shared_F75A;
    }
    uint8_t value99 = BUS8_RDP(c, (uint16_t)(direct_page_f740 + 1));
    if (!(value99 & 0x80)) {
        a_f75a = value98;
        a_hi_f75a = a_hi_f740;
        x_f75a = x_f740;
        y_f75a = y_f740;
        direct_page_f75a = direct_page_f740;
        data_bank_f75a = data_bank_f740;
        goto shared_F75A;
    }
    uint8_t value100 = BUS8_RDP(c, (uint16_t)(direct_page_f740 + 2));
    uint8_t value101 = BUS8_RDP(c, (uint16_t)(direct_page_f740 + 0x0D));
    a_f760 = (uint8_t)(((value98 & 0x40) ^ value100 | value101) + 0x10);
    a_hi_f760 = a_hi_f740;
    x_f760 = x_f740;
    y_f760 = y_f740;
    direct_page_f760 = direct_page_f740;
    data_bank_f760 = data_bank_f740;
    goto shared_F760;
    shared_F75A:;
    uint8_t value102 = BUS8_RDP(c, (uint16_t)(direct_page_f75a + 2));
    uint8_t value103 = BUS8_RDP(c, (uint16_t)(direct_page_f75a + 0x0D));
    a_f760 = (a_f75a & 0x40) ^ value102 | value103;
    a_hi_f760 = a_hi_f75a;
    x_f760 = x_f75a;
    y_f760 = y_f75a;
    direct_page_f760 = direct_page_f75a;
    data_bank_f760 = data_bank_f75a;
    goto shared_F760;
    shared_F760:;
    BUS8_SET(c, (data_bank_f760 << 0x10) + 0xE093 + x_f760, a_f760);
    uint8_t value104 = BUS8_RDP(c, (uint16_t)(direct_page_f760 + 0x0C));
    BUS8_SET(c, (data_bank_f760 << 0x10) + 0xE092 + x_f760, value104);
    if (((uint8_t)(value104 + 2) & 0x10) == 0) {
        a_f775 = (uint8_t)(value104 + 2);
        a_hi_f775 = a_hi_f760;
        x_f775 = x_f760;
        y_f775 = y_f760;
        carry_f775 = value104 + 2 > 0xFF;
        direct_page_f775 = direct_page_f760;
        data_bank_f775 = data_bank_f760;
        goto shared_F775;
    }
    if ((uint8_t)(value104 + 2) + 0x10 + (value104 + 2 > 0xFF) <= 0xFF) {
        a_f775 = (uint8_t)((uint8_t)(value104 + 2) + 0x10 + (value104 + 2 > 0xFF));
        a_hi_f775 = a_hi_f760;
        x_f775 = x_f760;
        y_f775 = y_f760;
        carry_f775 = (uint8_t)(value104 + 2) + 0x10 + (value104 + 2 > 0xFF) > 0xFF;
        direct_page_f775 = direct_page_f760;
        data_bank_f775 = data_bank_f760;
        goto shared_F775;
    }
    uint8_t value105 = BUS8_RDP(c, (uint16_t)(direct_page_f760 + 0x0D));
    BUS8_SET(c, (uint16_t)(direct_page_f760 + 0x0D), (uint8_t)(value105 + 1));
    a_f775 = (uint8_t)((uint8_t)(value104 + 2) + 0x10 + (value104 + 2 > 0xFF));
    a_hi_f775 = a_hi_f760;
    x_f775 = x_f760;
    y_f775 = y_f760;
    carry_f775 = (uint8_t)(value104 + 2) + 0x10 + (value104 + 2 > 0xFF) > 0xFF;
    direct_page_f775 = direct_page_f760;
    data_bank_f775 = data_bank_f760;
    goto shared_F775;
    shared_F775:;
    BUS8_SET(c, (uint16_t)(direct_page_f775 + 0x0C), a_f775);
    if ((uint16_t)(y_f775 - 1) != 0) {
        a_hi_f704 = a_hi_f775;
        x_f704 = (uint16_t)(x_f775 + 4);
        y_f704 = (uint16_t)(y_f775 - 1);
        direct_page_f704 = direct_page_f775;
        data_bank_f704 = data_bank_f775;
        goto shared_F704;
    }
    uint8_t value106 = BUS8_RDP(c, (uint16_t)(direct_page_f775 + 0xED));
    if (value106 & 0x80) {
        uint16_t value107 = BUS16_RDP(c, (uint16_t)(direct_page_f775 + 0x14));
        uint8_t value108 = BUS8_RDP(c, (uint16_t)(direct_page_f775 + 4));
        if ((value108 & 0x60) != 0) {
            uint8_t value109 = BUS8_RDP(c, (uint16_t)(direct_page_f775 + 4));
            if ((value109 & 0x40) == 0) {
                BUS8_SET(c, (data_bank_f775 << 0x10) + 0xE0CA + value107, 0);
                BUS8_SET(c, (data_bank_f775 << 0x10) + 0xE0CB + value107, 0);
                a_hi_f82a = a_hi_f775;
                x_f82a = value107;
                y_f82a = 0;
                carry_f82a = carry_f775;
                direct_page_f82a = direct_page_f775;
                data_bank_f82a = data_bank_f775;
                goto shared_F82A;
            }
            uint8_t value110 = BUS8_RDP(c, (uint16_t)(direct_page_f775 + 4));
            if ((value110 & 0x10) == 0) {
                uint8_t value111 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f775 + 0x12)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page_f775 + 0x10)), BUS8_RDP(c, (uint16_t)(direct_page_f775 + 0x12)));
                RAM8(0x0000 + sp0) = value111;
                if ((value111 & 0x0F) < 8) {
                    a_f7e0 = value111 & 0x0F;
                    a_hi_f7e0 = a_hi_f775;
                    x_f7e0 = value107;
                    y_f7e0 = 1;
                    direct_page_f7e0 = direct_page_f775;
                    data_bank_f7e0 = data_bank_f775;
                    goto shared_F7E0;
                }
                a_f7e0 = (value111 & 0x0F) | 0xF0;
                a_hi_f7e0 = a_hi_f775;
                x_f7e0 = value107;
                y_f7e0 = 1;
                direct_page_f7e0 = direct_page_f775;
                data_bank_f7e0 = data_bank_f775;
                goto shared_F7E0;
            }
            uint8_t value112 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f775 + 0x12)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page_f775 + 0x10)), BUS8_RDP(c, (uint16_t)(direct_page_f775 + 0x12)));
            uint8_t value113 = BUS8_RDP(c, (uint16_t)(direct_page_f775 + 2));
            if (!(value113 & 0x80)) {
                a_f7b4 = value112;
                a_hi_f7b4 = a_hi_f775;
                x_f7b4 = value107;
                y_f7b4 = 0;
                direct_page_f7b4 = direct_page_f775;
                data_bank_f7b4 = data_bank_f775;
                goto shared_F7B4;
            }
            a_f7b4 = (uint8_t)((value112 ^ 0xFF) + 1);
            a_hi_f7b4 = a_hi_f775;
            x_f7b4 = value107;
            y_f7b4 = 0;
            direct_page_f7b4 = direct_page_f775;
            data_bank_f7b4 = data_bank_f775;
            goto shared_F7B4;
        }
        BUS16_SET(c, (data_bank_f775 << 0x10) + 0xE0CA + value107, 0);
        BUS16_SET(c, (data_bank_f775 << 0x10) + 0xE0CE + value107, 0);
        r->a = 0;
        r->x = value107;
        r->y = (uint16_t)(y_f775 - 1);
        r->c = carry_f775;
        r->v = value108 & 0x40;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank_f775;
        r->dp = direct_page_f775;
        RETURN_RTS(c);
    }
    r->a = (a_hi_f775 << 8) | a_f775;
    r->x = (uint16_t)(x_f775 + 4);
    r->y = (uint16_t)(y_f775 - 1);
    r->c = carry_f775;
    r->v = value106 & 0x40;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_f775;
    r->dp = direct_page_f775;
    RETURN_RTS(c);
    shared_F82A:;
    uint8_t value114 = BUS8_RDP(c, (uint16_t)(direct_page_f82a + 4));
    if ((value114 & 0x20) != 0) {
        uint8_t value115 = BUS8_RDP(c, (uint16_t)(direct_page_f82a + 4));
        if ((value115 & 0x10) == 0) {
            uint8_t value116 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f82a + 0x12)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page_f82a + 0x10)) + y_f82a, BUS8_RDP(c, (uint16_t)(direct_page_f82a + 0x12)));
            RAM8(0x0000 + sp0) = value116;
            if ((value116 & 0x0F) < 8) {
                a_f873 = value116 & 0x0F;
                a_hi_f873 = a_hi_f82a;
                x_f873 = x_f82a;
                y_f873 = (uint16_t)(y_f82a + 1);
                direct_page_f873 = direct_page_f82a;
                data_bank_f873 = data_bank_f82a;
                goto shared_F873;
            }
            a_f873 = (value116 & 0x0F) | 0xF0;
            a_hi_f873 = a_hi_f82a;
            x_f873 = x_f82a;
            y_f873 = (uint16_t)(y_f82a + 1);
            direct_page_f873 = direct_page_f82a;
            data_bank_f873 = data_bank_f82a;
            goto shared_F873;
        }
        uint8_t value117 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f82a + 0x12)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page_f82a + 0x10)) + y_f82a, BUS8_RDP(c, (uint16_t)(direct_page_f82a + 0x12)));
        uint8_t value118 = BUS8_RDP(c, (uint16_t)(direct_page_f82a + 2));
        if (!(value118 & 0x80)) {
            a_f848 = value117;
            a_hi_f848 = a_hi_f82a;
            x_f848 = x_f82a;
            y_f848 = y_f82a;
            direct_page_f848 = direct_page_f82a;
            data_bank_f848 = data_bank_f82a;
            goto shared_F848;
        }
        a_f848 = (uint8_t)((value117 ^ 0xFF) + 1);
        a_hi_f848 = a_hi_f82a;
        x_f848 = x_f82a;
        y_f848 = y_f82a;
        direct_page_f848 = direct_page_f82a;
        data_bank_f848 = data_bank_f82a;
        goto shared_F848;
    }
    BUS8_SET(c, (data_bank_f82a << 0x10) + 0xE0CE + x_f82a, 0);
    BUS8_SET(c, (data_bank_f82a << 0x10) + 0xE0CF + x_f82a, 0);
    r->a = (a_hi_f82a << 8) | 0;
    r->x = x_f82a;
    r->y = y_f82a;
    r->c = carry_f82a;
    r->v = value114 & 0x40;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_f82a;
    r->dp = direct_page_f82a;
    RETURN_RTS(c);
    shared_F7E0:;
    uint8_t value119 = BUS8_RDP(c, (uint16_t)(direct_page_f7e0 + 2));
    if (!(value119 & 0x40)) {
        a_f7e9 = (uint8_t)(a_f7e0 << 2);
        a_hi_f7e9 = a_hi_f7e0;
        x_f7e9 = x_f7e0;
        y_f7e9 = y_f7e0;
        direct_page_f7e9 = direct_page_f7e0;
        data_bank_f7e9 = data_bank_f7e0;
        goto shared_F7E9;
    }
    a_f7e9 = (uint8_t)(((uint8_t)(a_f7e0 << 2) ^ 0xFF) + 1);
    a_hi_f7e9 = a_hi_f7e0;
    x_f7e9 = x_f7e0;
    y_f7e9 = y_f7e0;
    direct_page_f7e9 = direct_page_f7e0;
    data_bank_f7e9 = data_bank_f7e0;
    goto shared_F7E9;
    shared_F7B4:;
    uint8_t value120 = BUS8_RDP(c, (uint16_t)(direct_page_f7b4 + 3));
    uint8_t value121 = BUS8_RDP(c, (data_bank_f7b4 << 0x10) + 0xE045 + x_f7b4);
    if ((((uint8_t)(a_f7b4 - value120) ^ value121) & ((uint8_t)(a_f7b4 - value120) ^ (uint8_t)((uint8_t)(a_f7b4 - value120) - value121 - (a_f7b4 >= value120 ^ 1))) & 0x80) == 0) {
        a_f7bf = (uint8_t)((uint8_t)(a_f7b4 - value120) - value121 - (a_f7b4 >= value120 ^ 1));
        a_hi_f7bf = a_hi_f7b4;
        x_f7bf = x_f7b4;
        y_f7bf = (uint16_t)(y_f7b4 + 1);
        direct_page_f7bf = direct_page_f7b4;
        data_bank_f7bf = data_bank_f7b4;
        goto shared_F7BF;
    }
    a_f7bf = 0x80;
    a_hi_f7bf = a_hi_f7b4;
    x_f7bf = x_f7b4;
    y_f7bf = (uint16_t)(y_f7b4 + 1);
    direct_page_f7bf = direct_page_f7b4;
    data_bank_f7bf = data_bank_f7b4;
    goto shared_F7BF;
    shared_F873:;
    uint8_t value122 = BUS8_RDP(c, (uint16_t)(direct_page_f873 + 2));
    if (!(value122 & 0x40)) {
        a_f87c = (uint8_t)(a_f873 << 2);
        a_hi_f87c = a_hi_f873;
        x_f87c = x_f873;
        y_f87c = y_f873;
        direct_page_f87c = direct_page_f873;
        data_bank_f87c = data_bank_f873;
        goto shared_F87C;
    }
    a_f87c = (uint8_t)(((uint8_t)(a_f873 << 2) ^ 0xFF) + 1);
    a_hi_f87c = a_hi_f873;
    x_f87c = x_f873;
    y_f87c = y_f873;
    direct_page_f87c = direct_page_f873;
    data_bank_f87c = data_bank_f873;
    goto shared_F87C;
    shared_F848:;
    uint8_t value123 = BUS8_RDP(c, (uint16_t)(direct_page_f848 + 3));
    uint8_t value124 = BUS8_RDP(c, (data_bank_f848 << 0x10) + 0xE045 + x_f848);
    if ((((uint8_t)(a_f848 - value123) ^ value124) & ((uint8_t)(a_f848 - value123) ^ (uint8_t)((uint8_t)(a_f848 - value123) - value124 - (a_f848 >= value123 ^ 1))) & 0x80) == 0) {
        a_f853 = (uint8_t)((uint8_t)(a_f848 - value123) - value124 - (a_f848 >= value123 ^ 1));
        a_hi_f853 = a_hi_f848;
        x_f853 = x_f848;
        y_f853 = (uint16_t)(y_f848 + 1);
        direct_page_f853 = direct_page_f848;
        data_bank_f853 = data_bank_f848;
        goto shared_F853;
    }
    a_f853 = 0x80;
    a_hi_f853 = a_hi_f848;
    x_f853 = x_f848;
    y_f853 = (uint16_t)(y_f848 + 1);
    direct_page_f853 = direct_page_f848;
    data_bank_f853 = data_bank_f848;
    goto shared_F853;
    shared_F7E9:;
    BUS8_SET(c, (data_bank_f7e9 << 0x10) + 0xE0C8 + x_f7e9, a_f7e9);
    uint8_t value125 = RAM8(0x0000 + sp0);
    if (value125 >> 4 < 8) {
        a_f7f7 = value125 >> 4;
        a_hi_f7f7 = a_hi_f7e9;
        x_f7f7 = x_f7e9;
        y_f7f7 = y_f7e9;
        direct_page_f7f7 = direct_page_f7e9;
        data_bank_f7f7 = data_bank_f7e9;
        goto shared_F7F7;
    }
    a_f7f7 = (value125 >> 4) | 0xF0;
    a_hi_f7f7 = a_hi_f7e9;
    x_f7f7 = x_f7e9;
    y_f7f7 = y_f7e9;
    direct_page_f7f7 = direct_page_f7e9;
    data_bank_f7f7 = data_bank_f7e9;
    goto shared_F7F7;
    shared_F7BF:;
    BUS8_SET(c, (data_bank_f7bf << 0x10) + 0xE0C9 + x_f7bf, a_f7bf);
    uint8_t value126 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f7bf + 0x12)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page_f7bf + 0x10)) + y_f7bf, BUS8_RDP(c, (uint16_t)(direct_page_f7bf + 0x12)));
    uint8_t value127 = BUS8_RDP(c, (uint16_t)(direct_page_f7bf + 2));
    if (!(value127 & 0x40)) {
        a_f7cb = value126;
        a_hi_f7cb = a_hi_f7bf;
        x_f7cb = x_f7bf;
        y_f7cb = y_f7bf;
        direct_page_f7cb = direct_page_f7bf;
        data_bank_f7cb = data_bank_f7bf;
        goto shared_F7CB;
    }
    a_f7cb = (uint8_t)((value126 ^ 0xFF) + 1);
    a_hi_f7cb = a_hi_f7bf;
    x_f7cb = x_f7bf;
    y_f7cb = y_f7bf;
    direct_page_f7cb = direct_page_f7bf;
    data_bank_f7cb = data_bank_f7bf;
    goto shared_F7CB;
    shared_F87C:;
    BUS8_SET(c, (data_bank_f87c << 0x10) + 0xE0CC + x_f87c, a_f87c);
    uint8_t value128 = RAM8(0x0000 + sp0);
    if (value128 >> 4 < 8) {
        a_f88a = value128 >> 4;
        a_hi_f88a = a_hi_f87c;
        x_f88a = x_f87c;
        y_f88a = y_f87c;
        direct_page_f88a = direct_page_f87c;
        data_bank_f88a = data_bank_f87c;
        goto shared_F88A;
    }
    a_f88a = (value128 >> 4) | 0xF0;
    a_hi_f88a = a_hi_f87c;
    x_f88a = x_f87c;
    y_f88a = y_f87c;
    direct_page_f88a = direct_page_f87c;
    data_bank_f88a = data_bank_f87c;
    goto shared_F88A;
    shared_F853:;
    BUS8_SET(c, (data_bank_f853 << 0x10) + 0xE0CD + x_f853, a_f853);
    uint8_t value129 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f853 + 0x12)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page_f853 + 0x10)) + y_f853, BUS8_RDP(c, (uint16_t)(direct_page_f853 + 0x12)));
    uint8_t value130 = BUS8_RDP(c, (uint16_t)(direct_page_f853 + 2));
    if (!(value130 & 0x40)) {
        a_f85f = value129;
        a_hi_f85f = a_hi_f853;
        x_f85f = x_f853;
        y_f85f = y_f853;
        overflow_f85f = value130 & 0x40;
        direct_page_f85f = direct_page_f853;
        data_bank_f85f = data_bank_f853;
        goto shared_F85F;
    }
    a_f85f = (uint8_t)((value129 ^ 0xFF) + 1);
    a_hi_f85f = a_hi_f853;
    x_f85f = x_f853;
    y_f85f = y_f853;
    overflow_f85f = value130 & 0x40;
    direct_page_f85f = direct_page_f853;
    data_bank_f85f = data_bank_f853;
    goto shared_F85F;
    shared_F7F7:;
    uint8_t value131 = BUS8_RDP(c, (uint16_t)(direct_page_f7f7 + 2));
    if (!(value131 & 0x80)) {
        a_f800 = (uint8_t)(a_f7f7 << 2);
        a_hi_f800 = a_hi_f7f7;
        x_f800 = x_f7f7;
        y_f800 = y_f7f7;
        direct_page_f800 = direct_page_f7f7;
        data_bank_f800 = data_bank_f7f7;
        goto shared_F800;
    }
    a_f800 = (uint8_t)(((uint8_t)(a_f7f7 << 2) ^ 0xFF) + 1);
    a_hi_f800 = a_hi_f7f7;
    x_f800 = x_f7f7;
    y_f800 = y_f7f7;
    direct_page_f800 = direct_page_f7f7;
    data_bank_f800 = data_bank_f7f7;
    goto shared_F800;
    shared_F7CB:;
    BUS8_SET(c, (data_bank_f7cb << 0x10) + 0xE0C8 + x_f7cb, a_f7cb);
    uint8_t value132 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f7cb + 0x12)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page_f7cb + 0x10)) + (uint16_t)(y_f7cb + 1), BUS8_RDP(c, (uint16_t)(direct_page_f7cb + 0x12)));
    a_f810 = value132;
    a_hi_f810 = a_hi_f7cb;
    x_f810 = x_f7cb;
    y_f810 = (uint16_t)(y_f7cb + 2);
    direct_page_f810 = direct_page_f7cb;
    data_bank_f810 = data_bank_f7cb;
    goto shared_F810;
    shared_F88A:;
    uint8_t value133 = BUS8_RDP(c, (uint16_t)(direct_page_f88a + 2));
    if (!(value133 & 0x80)) {
        a_f893 = (uint8_t)(a_f88a << 2);
        a_hi_f893 = a_hi_f88a;
        x_f893 = x_f88a;
        y_f893 = y_f88a;
        direct_page_f893 = direct_page_f88a;
        data_bank_f893 = data_bank_f88a;
        goto shared_F893;
    }
    a_f893 = (uint8_t)(((uint8_t)(a_f88a << 2) ^ 0xFF) + 1);
    a_hi_f893 = a_hi_f88a;
    x_f893 = x_f88a;
    y_f893 = y_f88a;
    direct_page_f893 = direct_page_f88a;
    data_bank_f893 = data_bank_f88a;
    goto shared_F893;
    shared_F85F:;
    BUS8_SET(c, (data_bank_f85f << 0x10) + 0xE0CC + x_f85f, a_f85f);
    uint8_t value134 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f85f + 0x12)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page_f85f + 0x10)) + (uint16_t)(y_f85f + 1), BUS8_RDP(c, (uint16_t)(direct_page_f85f + 0x12)));
    a_f8a2 = value134;
    a_hi_f8a2 = a_hi_f85f;
    x_f8a2 = x_f85f;
    y_f8a2 = (uint16_t)(y_f85f + 1);
    overflow_f8a2 = overflow_f85f;
    direct_page_f8a2 = direct_page_f85f;
    data_bank_f8a2 = data_bank_f85f;
    goto shared_F8A2;
    shared_F800:;
    uint8_t value135 = BUS8_RDP(c, (uint16_t)(direct_page_f800 + 3));
    uint8_t value136 = BUS8_RDP(c, (data_bank_f800 << 0x10) + 0xE045 + x_f800);
    if ((((uint8_t)(a_f800 - value135) ^ value136) & ((uint8_t)(a_f800 - value135) ^ (uint8_t)((uint8_t)(a_f800 - value135) - value136 - (a_f800 >= value135 ^ 1))) & 0x80) == 0) {
        a_f80a = (uint8_t)((uint8_t)(a_f800 - value135) - value136 - (a_f800 >= value135 ^ 1));
        a_hi_f80a = a_hi_f800;
        x_f80a = x_f800;
        y_f80a = y_f800;
        direct_page_f80a = direct_page_f800;
        data_bank_f80a = data_bank_f800;
        goto shared_F80A;
    }
    a_f80a = 0x80;
    a_hi_f80a = a_hi_f800;
    x_f80a = x_f800;
    y_f80a = y_f800;
    direct_page_f80a = direct_page_f800;
    data_bank_f80a = data_bank_f800;
    goto shared_F80A;
    shared_F810:;
    RAM8(0x0000 + sp0) = a_f810;
    BUS8_SET(c, (data_bank_f810 << 0x10) + 0xE0CA + x_f810, (a_f810 & 0x0F) << 1 << 1);
    uint8_t value137 = RAM8(0x0000 + sp0);
    BUS8_SET(c, (data_bank_f810 << 0x10) + 0xE0CB + x_f810, (value137 >> 2) & 0x3C);
    a_hi_f82a = a_hi_f810;
    x_f82a = x_f810;
    y_f82a = y_f810;
    carry_f82a = value137 >> 1 & 0x01;
    direct_page_f82a = direct_page_f810;
    data_bank_f82a = data_bank_f810;
    goto shared_F82A;
    shared_F893:;
    uint8_t value138 = BUS8_RDP(c, (uint16_t)(direct_page_f893 + 3));
    uint8_t value139 = BUS8_RDP(c, (data_bank_f893 << 0x10) + 0xE045 + x_f893);
    if ((((uint8_t)(a_f893 - value138) ^ value139) & ((uint8_t)(a_f893 - value138) ^ (uint8_t)((uint8_t)(a_f893 - value138) - value139 - (a_f893 >= value138 ^ 1))) & 0x80) == 0) {
        a_f89d = (uint8_t)((uint8_t)(a_f893 - value138) - value139 - (a_f893 >= value138 ^ 1));
        a_hi_f89d = a_hi_f893;
        x_f89d = x_f893;
        y_f89d = y_f893;
        overflow_f89d = (((uint8_t)(a_f893 - value138) ^ value139) & ((uint8_t)(a_f893 - value138) ^ (uint8_t)((uint8_t)(a_f893 - value138) - value139 - (a_f893 >= value138 ^ 1))) & 0x80) != 0;
        direct_page_f89d = direct_page_f893;
        data_bank_f89d = data_bank_f893;
        goto shared_F89D;
    }
    a_f89d = 0x80;
    a_hi_f89d = a_hi_f893;
    x_f89d = x_f893;
    y_f89d = y_f893;
    overflow_f89d = (((uint8_t)(a_f893 - value138) ^ value139) & ((uint8_t)(a_f893 - value138) ^ (uint8_t)((uint8_t)(a_f893 - value138) - value139 - (a_f893 >= value138 ^ 1))) & 0x80) != 0;
    direct_page_f89d = direct_page_f893;
    data_bank_f89d = data_bank_f893;
    goto shared_F89D;
    shared_F8A2:;
    RAM8(0x0000 + sp0) = a_f8a2;
    BUS8_SET(c, (data_bank_f8a2 << 0x10) + 0xE0CE + x_f8a2, (a_f8a2 & 0x0F) << 1 << 1);
    uint8_t value140 = RAM8(0x0000 + sp0);
    BUS8_SET(c, (data_bank_f8a2 << 0x10) + 0xE0CF + x_f8a2, (value140 >> 2) & 0x3C);
    r->a = a_hi_f8a2 << 8 | ((value140 >> 2) & 0x3C);
    r->x = x_f8a2;
    r->y = y_f8a2;
    r->c = value140 >> 1 & 0x01;
    r->v = overflow_f8a2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_f8a2;
    r->dp = direct_page_f8a2;
    RETURN_RTS(c);
    shared_F80A:;
    BUS8_SET(c, (data_bank_f80a << 0x10) + 0xE0C9 + x_f80a, a_f80a);
    uint8_t value141 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f80a + 0x12)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page_f80a + 0x10)) + y_f80a, BUS8_RDP(c, (uint16_t)(direct_page_f80a + 0x12)));
    a_f810 = value141;
    a_hi_f810 = a_hi_f80a;
    x_f810 = x_f80a;
    y_f810 = (uint16_t)(y_f80a + 1);
    direct_page_f810 = direct_page_f80a;
    data_bank_f810 = data_bank_f80a;
    goto shared_F810;
    shared_F89D:;
    BUS8_SET(c, (data_bank_f89d << 0x10) + 0xE0CD + x_f89d, a_f89d);
    uint8_t value142 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(direct_page_f89d + 0x12)) << 0x10) + BUS16_RDP(c, (uint16_t)(direct_page_f89d + 0x10)) + y_f89d, BUS8_RDP(c, (uint16_t)(direct_page_f89d + 0x12)));
    a_f8a2 = value142;
    a_hi_f8a2 = a_hi_f89d;
    x_f8a2 = x_f89d;
    y_f8a2 = y_f89d;
    overflow_f8a2 = overflow_f89d;
    direct_page_f8a2 = direct_page_f89d;
    data_bank_f8a2 = data_bank_f89d;
    goto shared_F8A2;
}
SOM_REGISTER(0xC0F4CB, SOM_RTS, "gen", advance_actor_animation_and_resume_native_frame_stream, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 3, 1, 0, 1000, 515)
