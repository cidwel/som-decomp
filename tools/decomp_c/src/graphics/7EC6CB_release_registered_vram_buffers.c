#include "som_c.h"

/* 7EC6CB release_registered_vram_buffers   [class B, 69 bytes, 41 instructions]
 * Source: src/boot/release_registered_vram_buffers.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$0200.  Callers read: ABXYCZNV.
 */
static void release_registered_vram_buffers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    uint16_t value = RAM16(0x102F4);
    if (value == 0) {
        r->a = ((uint16_t)(sp0 - 5) >> 8 << 8) | (x >> 8);
        r->y = value;
        r->z = 0;
        r->n = 0;
        RETURN_RTS(c);
    }
    RAM8(0x0001 + (uint16_t)(sp0 - 5)) = 4;
    uint8_t a_hi1 = (uint16_t)(sp0 - 5) >> 8;
    uint16_t y1 = value;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7F;
    uint16_t direct_page = (uint16_t)(sp0 - 5);
    for (;;) {
        uint16_t value2 = BUS16_RDP(c, (data_bank << 0x10) + 2 + y1);
        if (value2 == 0) {
            uint8_t value3 = BUS8_RDP(c, (data_bank << 0x10) + y1);
            if (value3 == 0) {
                uint8_t value4 = BUS8_RDP(c, (uint16_t)(direct_page + 1));
                BUS8_SET(c, (uint16_t)(direct_page + 1), (uint8_t)(value4 - 1));
                if ((uint8_t)(value4 - 1) != 0) {
                    uint8_t a_hi1_next = (uint16_t)(y1 + 8) >> 8;
                    uint16_t y1_next = (uint16_t)(y1 + 8);
                    bool carry1_next = y1 + 8 > 0xFFFF;
                    bool overflow1_next = ((y1 ^ (uint16_t)(y1 + 8)) & ((uint16_t)(y1 + 8) ^ 8) & 0x8000) != 0;
                    a_hi1 = a_hi1_next;
                    y1 = y1_next;
                    carry1 = carry1_next;
                    overflow1 = overflow1_next;
                    continue;
                }
                uint8_t a_hi1_next2 = (uint16_t)(y1 + 8) >> 8;
                uint16_t y1_next2 = (uint16_t)(y1 + 8);
                bool carry1_next2 = y1 + 8 > 0xFFFF;
                bool overflow1_next2 = ((y1 ^ (uint16_t)(y1 + 8)) & ((uint16_t)(y1 + 8) ^ 8) & 0x8000) != 0;
                a_hi1 = a_hi1_next2;
                y1 = y1_next2;
                carry1 = carry1_next2;
                overflow1 = overflow1_next2;
                break;
            }
            RAM8(0x0000 + sp0 - 6) = y1 >> 8;
            RAM8(0x0000 + sp0 - 7) = (uint8_t)y1;
            r->a = (a_hi1 << 8) | value3;
            r->x = value2;
            r->y = y1;
            r->c = carry1;
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            r->sp -= 8;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC6F4, 0x7ED678); GUARD_JSR(c, sp_call, 0xC6F4); } /* release_matching_vram_tag */
            r->sp += 8;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            if (r->xf != 0) { c->fail = 3; return; }
            uint8_t value5 = RAM8(0x0000 + sp0 - 7);
            uint8_t value6 = RAM8(0x0000 + sp0 - 6);
            uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
            BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value7 - 1));
            if ((uint8_t)(value7 - 1) != 0) {
                a_hi1 = (uint16_t)(((value6 << 8) | value5) + 8) >> 8;
                y1 = (uint16_t)(((value6 << 8) | value5) + 8);
                carry1 = ((value6 << 8) | value5) + 8 > 0xFFFF;
                overflow1 = ((((value6 << 8) | value5) ^ (uint16_t)(((value6 << 8) | value5) + 8)) & ((uint16_t)(((value6 << 8) | value5) + 8) ^ 8) & 0x8000) != 0;
                data_bank = db_ret;
                direct_page = dp_ret;
                continue;
            }
            a_hi1 = (uint16_t)(((value6 << 8) | value5) + 8) >> 8;
            y1 = (uint16_t)(((value6 << 8) | value5) + 8);
            carry1 = ((value6 << 8) | value5) + 8 > 0xFFFF;
            overflow1 = ((((value6 << 8) | value5) ^ (uint16_t)(((value6 << 8) | value5) + 8)) & ((uint16_t)(((value6 << 8) | value5) + 8) ^ 8) & 0x8000) != 0;
            data_bank = db_ret;
            direct_page = dp_ret;
            break;
        }
        RAM8(0x0000 + sp0 - 6) = y1 >> 8;
        RAM8(0x0000 + sp0 - 7) = (uint8_t)y1;
        r->a = (a_hi1 << 8) | a;
        r->x = value2;
        r->y = y1;
        r->c = carry1;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC6EA, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xC6EA); } /* release_native_heap_suffix_through_bank_7f_api */
        r->sp += 8;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        uint8_t value8 = RAM8(0x0000 + sp0 - 7);
        uint8_t value9 = RAM8(0x0000 + sp0 - 6);
        uint8_t value10 = BUS8_RDP(c, (db_ret2 << 0x10) + ((value9 << 8) | value8));
        if (value10 == 0) {
            uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
            BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value11 - 1));
            if ((uint8_t)(value11 - 1) != 0) {
                a_hi1 = (uint16_t)(((value9 << 8) | value8) + 8) >> 8;
                y1 = (uint16_t)(((value9 << 8) | value8) + 8);
                carry1 = ((value9 << 8) | value8) + 8 > 0xFFFF;
                overflow1 = ((((value9 << 8) | value8) ^ (uint16_t)(((value9 << 8) | value8) + 8)) & ((uint16_t)(((value9 << 8) | value8) + 8) ^ 8) & 0x8000) != 0;
                data_bank = db_ret2;
                direct_page = dp_ret2;
                continue;
            }
            a_hi1 = (uint16_t)(((value9 << 8) | value8) + 8) >> 8;
            y1 = (uint16_t)(((value9 << 8) | value8) + 8);
            carry1 = ((value9 << 8) | value8) + 8 > 0xFFFF;
            overflow1 = ((((value9 << 8) | value8) ^ (uint16_t)(((value9 << 8) | value8) + 8)) & ((uint16_t)(((value9 << 8) | value8) + 8) ^ 8) & 0x8000) != 0;
            data_bank = db_ret2;
            direct_page = dp_ret2;
            break;
        }
        RAM8(0x0000 + sp0 - 6) = value9;
        RAM8(0x0000 + sp0 - 7) = (uint8_t)((value9 << 8) | value8);
        r->a = (a_all2 >> 8 << 8) | value10;
        r->y = (value9 << 8) | value8;
        r->z = value10 == 0;
        r->n = value10 & 0x80;
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC6F4, 0x7ED678); GUARD_JSR(c, sp_call, 0xC6F4); } /* release_matching_vram_tag */
        r->sp += 8;
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        if (r->xf != 0) { c->fail = 3; return; }
        uint8_t value12 = RAM8(0x0000 + sp0 - 7);
        uint8_t value13 = RAM8(0x0000 + sp0 - 6);
        uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
        BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (uint8_t)(value14 - 1));
        if ((uint8_t)(value14 - 1) != 0) {
            a_hi1 = (uint16_t)(((value13 << 8) | value12) + 8) >> 8;
            y1 = (uint16_t)(((value13 << 8) | value12) + 8);
            carry1 = ((value13 << 8) | value12) + 8 > 0xFFFF;
            overflow1 = ((((value13 << 8) | value12) ^ (uint16_t)(((value13 << 8) | value12) + 8)) & ((uint16_t)(((value13 << 8) | value12) + 8) ^ 8) & 0x8000) != 0;
            data_bank = db_ret3;
            direct_page = dp_ret3;
            continue;
        }
        a_hi1 = (uint16_t)(((value13 << 8) | value12) + 8) >> 8;
        y1 = (uint16_t)(((value13 << 8) | value12) + 8);
        carry1 = ((value13 << 8) | value12) + 8 > 0xFFFF;
        overflow1 = ((((value13 << 8) | value12) ^ (uint16_t)(((value13 << 8) | value12) + 8)) & ((uint16_t)(((value13 << 8) | value12) + 8) ^ 8) & 0x8000) != 0;
        data_bank = db_ret3;
        direct_page = dp_ret3;
        break;
    }
    uint16_t value15 = BUS16_RDP(c, (data_bank << 0x10) + 0x02F4);
    r->a = (a_hi1 << 8) | a;
    r->x = value15;
    r->y = y1;
    r->c = carry1;
    r->z = value15 == 0;
    r->n = value15 & 0x8000;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC709, 0x7EB0D6); GUARD_JSR(c, sp_call, 0xC709); } /* release_native_heap_suffix_through_bank_7f_api */
    r->sp += 6;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all4 = r->a;
    uint8_t value16 = RAM8(0x0000 + sp0 - 5);
    uint8_t value18 = RAM8(0x0000 + sp0 - 3);
    uint8_t value19 = RAM8(0x0000 + sp0 - 2);
    uint8_t value20 = RAM8(0x0000 + sp0 - 1);
    uint8_t value21 = RAM8(0x0000 + sp0);
    r->a = (a_all4 >> 8 << 8) | value18;
    r->c = value19 & 0x01;
    r->z = ((value21 << 8) | value20) == 0;
    r->n = ((value21 << 8) | value20) & 0x8000;
    r->v = value19 & 0x40;
    r->mf = value19 & 0x20;
    r->xf = value19 & 0x10;
    r->db = value16;
    r->dp = (value21 << 8) | value20;
    r->i = value19 & 0x04;
    r->d = value19 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC6CB, SOM_RTS, "gen", release_registered_vram_buffers, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 8, 1, 0, 69, 41)
