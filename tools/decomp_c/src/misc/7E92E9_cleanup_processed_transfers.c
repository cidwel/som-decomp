#include "som_c.h"

/* 7E92E9 cleanup_processed_transfers   [class B, 102 bytes, 55 instructions]
 * Source: src/boot/cleanup_processed_transfers.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$4200.  Callers read: ABXYCZNV.
 */
static void cleanup_processed_transfers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x4200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
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
    uint16_t value = RAM16(0x1006E);
    bool x_flag;
    uint8_t a_hi3;
    uint16_t x2;
    uint16_t y3;
    uint8_t data_bank3;
    uint16_t direct_page3;
    if (value == 0) {
        x_flag = 0;
        a_hi3 = value >> 8;
        x2 = x;
        y3 = y;
        data_bank3 = 0x7F;
        direct_page3 = (uint16_t)(sp0 - 5);
    } else {
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), value);
        uint16_t value2 = RAM16(0x10066);
        uint8_t a_hi1 = value >> 8;
        uint16_t y1 = value2;
        bool carry1 = carry;
        bool overflow1 = overflow;
        uint8_t data_bank = 0x7F;
        uint16_t direct_page = (uint16_t)(sp0 - 5);
        for (;;) {
            RAM8(0x0000 + sp0 - 6) = y1 >> 8;
            RAM8(0x0000 + sp0 - 7) = (uint8_t)y1;
            uint16_t value3 = BUS16_RDP(c, (data_bank << 0x10) + y1);
            uint16_t value4 = BUS16_RDP(c, (data_bank << 0x10) + 0x0F + value3);
            bool m_flag;
            uint8_t a_hi2;
            uint16_t x1;
            uint16_t y2;
            bool carry2;
            bool zero1;
            bool negative1;
            bool overflow2;
            uint8_t data_bank2;
            uint16_t direct_page2;
            if ((value4 & 8) == 0) {
                m_flag = 0;
                a_hi2 = 0;
                x1 = value3;
                y2 = y1;
                carry2 = carry1;
                zero1 = (value4 & 8) == 0;
                negative1 = value4 & 8 & 0x8000;
                overflow2 = overflow1;
                data_bank2 = data_bank;
                direct_page2 = direct_page;
            } else {
                uint16_t value5 = BUS16_RDP(c, (data_bank << 0x10) + 2 + value3);
                r->a = value4 & 8;
                r->x = value5;
                r->y = value5;
                r->c = carry1;
                r->z = value5 == 0;
                r->n = value5 & 0x8000;
                r->v = overflow1;
                r->mf = 0;
                r->xf = 0;
                r->db = data_bank;
                r->dp = direct_page;
                r->sp -= 8;
                { const uint16_t sp_call = r->sp; JSR(c, 0x9315, 0x7EB0D6); GUARD_JSR(c, sp_call, 0x9315); } /* release_native_heap_suffix_through_bank_7f_api */
                r->sp += 8;
                uint16_t dp_ret = r->dp;
                uint8_t db_ret = r->db;
                bool m_ret = r->mf;
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all = r->a;
                bool carry_ret = r->c;
                bool overflow_ret = r->v;
                uint8_t value6 = RAM8(0x0000 + sp0 - 7);
                uint8_t value7 = RAM8(0x0000 + sp0 - 6);
                RAM8(0x0000 + sp0 - 6) = value7;
                RAM8(0x0000 + sp0 - 7) = (uint8_t)((value7 << 8) | value6);
                uint16_t value8 = BUS16_RDP(c, (db_ret << 0x10) + ((value7 << 8) | value6));
                m_flag = m_ret;
                a_hi2 = a_all >> 8;
                x1 = value8;
                y2 = (value7 << 8) | value6;
                carry2 = carry_ret;
                zero1 = value8 == 0;
                negative1 = value8 & 0x8000;
                overflow2 = overflow_ret;
                data_bank2 = db_ret;
                direct_page2 = dp_ret;
            }
            r->a = (a_hi2 << 8) | a;
            r->x = x1;
            r->y = y2;
            r->c = carry2;
            r->z = zero1;
            r->n = negative1;
            r->v = overflow2;
            r->mf = m_flag;
            r->xf = 0;
            r->db = data_bank2;
            r->dp = direct_page2;
            r->sp -= 8;
            { const uint16_t sp_call = r->sp; JSR(c, 0x931D, 0x7E9066); GUARD_JSR(c, sp_call, 0x931D); } /* release_transfer_descriptor */
            r->sp += 8;
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all2 = r->a;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            uint8_t value9 = RAM8(0x0000 + sp0 - 7);
            uint8_t value10 = RAM8(0x0000 + sp0 - 6);
            uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value11 - 1));
            a_hi1 = a_all2 >> 8;
            y1 = (uint16_t)(((value10 << 8) | value9) + 2);
            carry1 = carry_ret2;
            overflow1 = overflow_ret2;
            data_bank = db_ret2;
            direct_page = dp_ret2;
            if (!((uint16_t)(value11 - 1) != 0)) break;
        }
        uint16_t value12 = BUS16_RDP(c, (data_bank << 0x10) + 0x6E);
        uint16_t value13 = BUS16_RDP(c, (data_bank << 0x10) + 0x66);
        uint16_t value14 = BUS16_RDP(c, (data_bank << 0x10) + 0x6C);
        uint16_t value15 = BUS16_RDP(c, (data_bank << 0x10) + 0x6E);
        BUS16_SET(c, (data_bank << 0x10) + 0x6C, (uint16_t)(value14 - value15));
        uint16_t value16 = BUS16_RDP(c, (data_bank << 0x10) + 0x66);
        r->a = (uint16_t)((uint16_t)(value14 - value15) << 1);
        r->x = (uint16_t)(((uint16_t)(value12 << 1) & 0xFF) + value13);
        r->y = value16;
        r->c = (uint16_t)(value14 - value15) & 0x8000;
        r->z = value16 == 0;
        r->n = value16 & 0x8000;
        r->v = ((value14 ^ value15) & (value14 ^ (uint16_t)(value14 - value15)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9343, 0x7EC3BF); GUARD_JSR(c, sp_call, 0x9343); } /* copy_native_same_bank_memory_through_stack_generated_mvn */
        r->sp += 6;
        uint16_t dp_ret3 = r->dp;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret3 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret2 = r->y;
        BUS16_SET(c, (data_bank << 0x10) + 0x6E, 0);
        x_flag = x_ret3;
        a_hi3 = a_all3 >> 8;
        x2 = x_ret4;
        y3 = y_ret2;
        data_bank3 = data_bank;
        direct_page3 = dp_ret3;
    }
    uint8_t value17 = RAM8(0x0000 + sp0 - 5);
    uint8_t value19 = RAM8(0x0000 + sp0 - 3);
    uint8_t value20 = RAM8(0x0000 + sp0 - 2);
    uint8_t value21 = RAM8(0x0000 + sp0 - 1);
    uint8_t value22 = RAM8(0x0000 + sp0);
    r->a = (a_hi3 << 8) | value19;
    r->x = x2;
    r->y = y3;
    r->c = value20 & 0x01;
    r->z = ((value22 << 8) | value21) == 0;
    r->n = ((value22 << 8) | value21) & 0x8000;
    r->v = value20 & 0x40;
    r->mf = value20 & 0x20;
    r->xf = value20 & 0x10;
    r->db = value17;
    r->dp = (value22 << 8) | value21;
    r->i = value20 & 0x04;
    r->d = value20 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E92E9, SOM_RTS, "gen", cleanup_processed_transfers, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 8, 1, 0, 102, 55)
