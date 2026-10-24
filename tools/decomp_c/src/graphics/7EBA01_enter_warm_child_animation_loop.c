#include "som_c.h"

/* 7EBA01 enter_warm_child_animation_loop   [class C, 27 bytes, 15 instructions]
 * Source: src/boot/enter_warm_child_animation_loop.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void enter_warm_child_animation_loop(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x);
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = (uint16_t)(sp0 - 5);
    for (;;) {
        uint16_t value = BUS16_RDP(c, (uint16_t)(direct_page + 1));
        r->x = value;
        r->y = y1;
        r->c = carry1;
        r->z = value == 0;
        r->n = value & 0x8000;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBA10, 0x7EBA21); GUARD_JSR(c, sp_call, 0xBA10); } /* update_nine_warm_child_sprite_animation_records */
        r->sp += 5;
        uint8_t db_ret = r->db;
        bool x_ret = r->xf;
        if (x_ret) {
            uint8_t value2 = BUS8_RDP(c, (uint16_t)(direct_page + 1));
            uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0x14 + value2);
            r->x = value3;
            r->y = value3;
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            r->xf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBA19, 0x7EABE7); GUARD_JSR(c, sp_call, 0xBA19); } /* receive_with_supplied_delay */
            r->sp += 5;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret2 = r->db;
            bool m_ret2 = r->mf;
            bool x_ret3 = r->xf;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            if (m_ret2 != 1) { c->fail = 3; return; }
            if (x_ret3 != 0) { c->fail = 3; return; }
            y1 = y_ret2;
            carry1 = carry_ret2;
            overflow1 = overflow_ret2;
            data_bank = db_ret2;
            direct_page = dp_ret;
        } else {
            uint16_t value4 = BUS16_RDP(c, (uint16_t)(direct_page + 1));
            uint16_t value5 = BUS16_RDP(c, (db_ret << 0x10) + 0x14 + value4);
            r->x = value5;
            r->y = value5;
            r->z = value5 == 0;
            r->n = value5 & 0x8000;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBA19, 0x7EABE7); GUARD_JSR(c, sp_call, 0xBA19); } /* receive_with_supplied_delay */
            r->sp += 5;
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret3 = r->db;
            bool m_ret3 = r->mf;
            bool x_ret5 = r->xf;
            uint16_t y_ret3 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            if (m_ret3 != 1) { c->fail = 3; return; }
            if (x_ret5 != 0) { c->fail = 3; return; }
            y1 = y_ret3;
            carry1 = carry_ret3;
            overflow1 = overflow_ret3;
            data_bank = db_ret3;
            direct_page = dp_ret2;
        }
    }
}
SOM_REGISTER(0x7EBA01, SOM_RTS, "gen", enter_warm_child_animation_loop, 0, 0, 5, 1, 0, 27, 15)
