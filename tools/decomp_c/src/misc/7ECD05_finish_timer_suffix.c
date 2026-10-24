#include "som_c.h"

/* 7ECD05 finish_timer_suffix   [class B, 75 bytes, 44 instructions]
 * Source: src/boot/finish_timer_suffix.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$4200.  Callers read: BXYCZNV.
 */
static void finish_timer_suffix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x4200) { c->fail = 3; return; }
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
    RAM8(0x0000 + sp0) = 0x42;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    uint16_t value = RAM16(0x10304);
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if (value == 0) {
        a_hi2 = value >> 8;
        x2 = x;
        y2 = y;
        data_bank2 = 0x7F;
        direct_page2 = (uint16_t)(sp0 - 5);
    } else {
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), value);
        uint16_t value2 = RAM16(0x10302);
        uint8_t a_hi1 = (uint16_t)((uint16_t)((uint16_t)(((uint16_t)(value - 0x20) ^ 0xFFFF) + 1) << 2) + value2) >> 8;
        uint16_t x1 = (uint16_t)((uint16_t)((uint16_t)(((uint16_t)(value - 0x20) ^ 0xFFFF) + 1) << 2) + value2);
        uint16_t y1 = y;
        bool overflow1 = (((uint16_t)((uint16_t)(((uint16_t)(value - 0x20) ^ 0xFFFF) + 1) << 2) ^ (uint16_t)((uint16_t)((uint16_t)(((uint16_t)(value - 0x20) ^ 0xFFFF) + 1) << 2) + value2)) & (value2 ^ (uint16_t)((uint16_t)((uint16_t)(((uint16_t)(value - 0x20) ^ 0xFFFF) + 1) << 2) + value2)) & 0x8000) != 0;
        uint8_t data_bank = 0x7F;
        uint16_t direct_page = (uint16_t)(sp0 - 5);
        for (;;) {
            uint16_t value3 = BUS16_RDP(c, (data_bank << 0x10) + x1);
            if ((value3 & 0xFF) != 2) {
                uint16_t value4 = BUS16_RDP(c, (uint16_t)(direct_page + 1));
                BUS16_RMW_SET(c, (uint16_t)(direct_page + 1), (uint16_t)(value4 - 1));
                if ((uint16_t)(value4 - 1) != 0) {
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
            uint16_t value5 = BUS16_RDP(c, (data_bank << 0x10) + 2 + x1);
            BUS16_RMW_SET(c, (data_bank << 0x10) + 2 + x1, (uint16_t)(value5 - 1));
            if ((uint16_t)(value5 - 1) != 0) {
                uint16_t value6 = BUS16_RDP(c, (uint16_t)(direct_page + 1));
                BUS16_RMW_SET(c, (uint16_t)(direct_page + 1), (uint16_t)(value6 - 1));
                if ((uint16_t)(value6 - 1) != 0) {
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
            r->a = value3 & 0xFF;
            r->x = x1;
            r->y = y1;
            r->c = (value3 & 0xFF) >= 2;
            r->z = (uint16_t)(value5 - 1) == 0;
            r->n = (uint16_t)(value5 - 1) & 0x8000;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCD3D, 0x7ECC8C); GUARD_JSR(c, sp_call, 0xCD3D); } /* notify_timer_expired */
            r->sp += 6;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t x_ret = r->x;
            uint16_t y_ret = r->y;
            uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret + 1), (uint16_t)(value7 - 1));
            if ((uint16_t)(value7 - 1) != 0) {
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
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    uint8_t value8 = RAM8(0x0000 + sp0 - 5);
    uint8_t value10 = RAM8(0x0000 + sp0 - 3);
    uint8_t value11 = RAM8(0x0000 + sp0 - 2);
    uint8_t value12 = RAM8(0x0000 + sp0 - 1);
    uint8_t value13 = RAM8(0x0000 + sp0);
    r->a = (a_hi2 << 8) | value10;
    r->x = x2;
    r->y = y2;
    r->c = value11 & 0x01;
    r->z = ((value13 << 8) | value12) == 0;
    r->n = ((value13 << 8) | value12) & 0x8000;
    r->v = value11 & 0x40;
    r->mf = value11 & 0x20;
    r->xf = value11 & 0x10;
    r->db = value8;
    r->dp = (value13 << 8) | value12;
    r->i = value11 & 0x04;
    r->d = value11 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ECD05, SOM_RTS, "gen", finish_timer_suffix, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 7, 1, 0, 75, 44)
