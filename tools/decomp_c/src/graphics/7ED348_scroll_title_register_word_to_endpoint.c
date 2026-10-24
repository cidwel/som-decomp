#include "som_c.h"

/* 7ED348 scroll_title_register_word_to_endpoint   [class B, 47 bytes, 22 instructions]
 * Source: src/boot/scroll_title_register_word_to_endpoint.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABXYV.
 */
static void scroll_title_register_word_to_endpoint(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7F;
    uint16_t direct_page = 0x02EE;
    for (;;) {
        r->a = 0x0E;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD351, 0x7EC030); GUARD_JSR(c, sp_call, 0xD351); } /* allocate_ppu_register_entry */
        r->sp += 3;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        uint16_t x_ret2 = r->x;
        if (m_ret) {
            c->fail = 3;
            return;
        } else {
            uint16_t value5 = BUS16_RDP(c, (db_ret << 0x10) + 2 + x_ret2);
            BUS16_SET(c, (db_ret << 0x10) + 2 + x_ret2, (uint16_t)(value5 - 1));
            RAM8(0x0000 + sp0 - 3) = (uint16_t)(value5 - 1) >> 8;
            RAM8(0x0000 + sp0 - 4) = (uint8_t)(value5 - 1);
            r->a = (uint16_t)(value5 - 1);
            r->z = (uint16_t)(value5 - 1) == 0;
            r->n = (uint16_t)(value5 - 1) & 0x8000;
            r->mf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD35C, 0x7EC097); GUARD_JSR(c, sp_call, 0xD35C); } /* append_oneshot_ppu_entry */
            r->sp += 5;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint8_t value6 = RAM8(0x0000 + sp0 - 4);
            uint8_t value7 = RAM8(0x0000 + sp0 - 3);
            if (((value7 << 8) | value6) == 0xFFF0) {
                uint8_t value8 = RAM8(0x0000 + sp0 - 2);
                uint8_t value9 = RAM8(0x0000 + sp0 - 1);
                uint8_t value10 = RAM8(0x0000 + sp0);
                r->a = ((value7 << 8) | value6) ^ 0x80;
                r->v = value8 & 0x40;
                r->mf = value8 & 0x20;
                r->xf = value8 & 0x10;
                r->dp = (value10 << 8) | value9;
                r->i = value8 & 0x04;
                r->d = value8 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            r->a = (value7 << 8) | value6;
            r->x = 8;
            r->c = ((value7 << 8) | value6) >= 0xFFF0;
            r->z = 0;
            r->n = 0;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD368, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD368); } /* dispatch_parent_messages */
            r->sp += 3;
            uint16_t dp_ret4 = r->dp;
            uint8_t db_ret4 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret3 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret4 = r->x;
            uint16_t y_ret4 = r->y;
            bool carry_ret4 = r->c;
            bool overflow_ret4 = r->v;
            if ((a_all4 & 0xFF) != 0) {
                if (x_ret3 != 0) { c->fail = 3; return; }
                a_hi1 = 0;
                x1 = x_ret4;
                y1 = y_ret4;
                carry1 = carry_ret4;
                overflow1 = overflow_ret4;
                data_bank = db_ret4;
                direct_page = dp_ret4;
                continue;
            }
            uint8_t value11 = RAM8(0x0000 + sp0 - 2);
            uint8_t value12 = RAM8(0x0000 + sp0 - 1);
            uint8_t value13 = RAM8(0x0000 + sp0);
            r->a = 0;
            r->v = value11 & 0x40;
            r->mf = value11 & 0x20;
            r->xf = value11 & 0x10;
            r->dp = (value13 << 8) | value12;
            r->i = value11 & 0x04;
            r->d = value11 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0x7ED348, SOM_RTS, "gen", scroll_title_register_word_to_endpoint, 0, L_A | L_B | L_X | L_Y | L_V, 5, 1, 0, 47, 22)
