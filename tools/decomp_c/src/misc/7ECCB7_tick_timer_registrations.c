#include "som_c.h"

/* 7ECCB7 tick_timer_registrations   [class D, 78 bytes, 42 instructions]
 * Source: src/boot/tick_timer_registrations.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$4200.  Callers read: BXYV.
 */
static void tick_timer_registrations(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x4200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 4) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 0x42;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    uint16_t value = RAM16(0x10302);
    RAM8(0x0001 + (uint16_t)(sp0 - 4)) = 0x20;
    uint8_t a_hi1 = (uint16_t)(sp0 - 4) >> 8;
    uint16_t x1 = value;
    uint16_t y1 = y;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7F;
    uint16_t direct_page = (uint16_t)(sp0 - 4);
    for (;;) {
        uint8_t value2 = BUS8(c, 0x002137);
        uint8_t value3 = BUS8(c, 0x00213D);
        uint8_t value4 = BUS8(c, 0x00213D);
        if (value3 >= 0xDE) {
            a_hi1 = value4;
            break;
        }
        uint8_t value5 = BUS8_RDP(c, (data_bank << 0x10) + x1);
        if (value5 != 2) {
            uint8_t value6 = BUS8_RDP(c, (uint16_t)(direct_page + 1));
            BUS8_SET(c, (uint16_t)(direct_page + 1), (uint8_t)(value6 - 1));
            if ((uint8_t)(value6 - 1) != 0) {
                uint8_t a_hi1_next = (uint16_t)(x1 + 4) >> 8;
                uint16_t x1_next = (uint16_t)(x1 + 4);
                bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 4)) & ((uint16_t)(x1 + 4) ^ 4) & 0x8000) != 0;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                overflow1 = overflow1_next;
                continue;
            }
            uint8_t a_hi1_next4 = (uint16_t)(x1 + 4) >> 8;
            uint16_t x1_next4 = (uint16_t)(x1 + 4);
            bool overflow1_next4 = ((x1 ^ (uint16_t)(x1 + 4)) & ((uint16_t)(x1 + 4) ^ 4) & 0x8000) != 0;
            a_hi1 = a_hi1_next4;
            x1 = x1_next4;
            overflow1 = overflow1_next4;
            break;
        }
        uint16_t value7 = BUS16_RDP(c, (data_bank << 0x10) + 2 + x1);
        BUS16_RMW_SET(c, (data_bank << 0x10) + 2 + x1, (uint16_t)(value7 - 1));
        if ((uint16_t)(value7 - 1) != 0) {
            uint8_t value8 = BUS8_RDP(c, (uint16_t)(direct_page + 1));
            BUS8_SET(c, (uint16_t)(direct_page + 1), (uint8_t)(value8 - 1));
            if ((uint8_t)(value8 - 1) != 0) {
                uint8_t a_hi1_next2 = (uint16_t)(x1 + 4) >> 8;
                uint16_t x1_next2 = (uint16_t)(x1 + 4);
                bool overflow1_next2 = ((x1 ^ (uint16_t)(x1 + 4)) & ((uint16_t)(x1 + 4) ^ 4) & 0x8000) != 0;
                a_hi1 = a_hi1_next2;
                x1 = x1_next2;
                overflow1 = overflow1_next2;
                continue;
            }
            uint8_t a_hi1_next3 = (uint16_t)(x1 + 4) >> 8;
            uint16_t x1_next3 = (uint16_t)(x1 + 4);
            bool overflow1_next3 = ((x1 ^ (uint16_t)(x1 + 4)) & ((uint16_t)(x1 + 4) ^ 4) & 0x8000) != 0;
            a_hi1 = a_hi1_next3;
            x1 = x1_next3;
            overflow1 = overflow1_next3;
            break;
        }
        r->a = (value4 << 8) | value5;
        r->x = x1;
        r->y = y1;
        r->c = value5 >= 2;
        r->z = (uint16_t)(value7 - 1) == 0;
        r->n = (uint16_t)(value7 - 1) & 0x8000;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCCEE, 0x7ECC8C); GUARD_JSR(c, sp_call, 0xCCEE); } /* notify_timer_expired */
        r->sp += 5;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value9 - 1));
        if ((uint8_t)(value9 - 1) != 0) {
            a_hi1 = (uint16_t)(x_ret + 4) >> 8;
            x1 = (uint16_t)(x_ret + 4);
            y1 = y_ret;
            overflow1 = ((x_ret ^ (uint16_t)(x_ret + 4)) & ((uint16_t)(x_ret + 4) ^ 4) & 0x8000) != 0;
            data_bank = db_ret;
            direct_page = dp_ret;
            continue;
        }
        a_hi1 = (uint16_t)(x_ret + 4) >> 8;
        x1 = (uint16_t)(x_ret + 4);
        y1 = y_ret;
        overflow1 = ((x_ret ^ (uint16_t)(x_ret + 4)) & ((uint16_t)(x_ret + 4) ^ 4) & 0x8000) != 0;
        data_bank = db_ret;
        direct_page = dp_ret;
        break;
    }
    uint8_t value10 = BUS8_RDP(c, (uint16_t)(direct_page + 1));
    BUS8_SET(c, (data_bank << 0x10) + 0x0304, value10);
    uint8_t value11 = RAM8(0x0000 + sp0 - 4);
    uint8_t value12 = RAM8(0x0000 + sp0 - 3);
    uint8_t value13 = RAM8(0x0000 + sp0 - 2);
    uint8_t value14 = RAM8(0x0000 + sp0 - 1);
    uint8_t value15 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value12;
    r->x = x1;
    r->y = y1;
    r->v = value13 & 0x40;
    r->mf = value13 & 0x20;
    r->xf = value13 & 0x10;
    r->db = value11;
    r->dp = (value15 << 8) | value14;
    r->i = value13 & 0x04;
    r->d = value13 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ECCB7, SOM_RTS, "gen", tick_timer_registrations, 0, L_B | L_X | L_Y | L_V, 6, 1, 0, 78, 42)
