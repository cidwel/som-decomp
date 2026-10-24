#include "som_c.h"

/* 7E809B create_graphics_buffer   [class B, 271 bytes, 144 instructions]
 * Source: src/boot/create_graphics_buffer.s
 * Entry: M=any X=16 bit DB=$7F D=any.  Callers read: BXYCV.
 */
static void create_graphics_buffer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_818c = 0;
    uint8_t x_818c = 0;
    uint8_t y_818c = 0;
    bool carry_818c = 0;
    bool zero_818c = 0;
    bool negative_818c = 0;
    bool overflow_818c = 0;
    uint16_t direct_page_818c = 0;
    uint8_t data_bank_818c = 0;
    uint8_t a_hi_818c2 = 0;
    uint16_t x_818c2 = 0;
    uint16_t y_818c2 = 0;
    bool carry_818c2 = 0;
    bool zero_818c2 = 0;
    bool negative_818c2 = 0;
    bool overflow_818c2 = 0;
    uint16_t direct_page_818c2 = 0;
    uint8_t data_bank_818c2 = 0;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 9) = 0x7F;
    RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7F;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), value);
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 9), x);
    r->a = value;
    r->c = (uint16_t)(sp0 - 5) >= 4;
    r->z = (uint8_t)value == 0;
    r->n = (uint8_t)value & 0x80;
    r->v = (((uint16_t)(sp0 - 5) ^ 4) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 9);
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x80BA, 0x7E805F); GUARD_JSR(c, sp_call, 0x80BA); } /* select_graphics_registration */
    r->sp += 10;
    uint16_t a_all = r->a;
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 9), a_all);
    uint16_t value2 = RAM16(0x0002 + (uint16_t)(sp0 - 9));
    r->a = 0;
    r->x = value2;
    r->z = 1;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x80C6, 0x7EB0A1); GUARD_JSR(c, sp_call, 0x80C6); } /* allocate_and_fill_bytes */
    r->sp += 10;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (m_ret) {
        if (x_ret) {
            uint8_t value3 = RAM8(0x0004 + (uint16_t)(sp0 - 9));
            RAM8(0x10006 + value3) = (uint8_t)x_ret2;
            RAM8(0x10004 + value3) = (uint8_t)x_ret2;
            uint8_t value4 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
            RAM8(0x10002 + value3) = value4 & 3;
            r->a = (a_all2 >> 8 << 8) | (uint8_t)((value4 & 3) - 1);
            r->x = value3;
            r->y = (uint8_t)y_ret;
            r->z = (uint8_t)((value4 & 3) - 1) == 0;
            r->n = (uint8_t)((value4 & 3) - 1) & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0x80DC, 0x7EC34D); GUARD_JSR(c, sp_call, 0x80DC); } /* derive_sixteen_bit_mask_from_low_nibble */
            r->sp += 10;
            uint8_t x_ret3 = r->x;
            uint8_t a1 = x_ret3;
            uint8_t a_hi1 = 0;
            for (;;) {
                if (!(((a_hi1 << 8) | a1) & 0x01)) {
                    RAM16_SET(0x0002 + (uint16_t)(sp0 - 9), (uint16_t)(RAM16(0x0002 + (uint16_t)(sp0 - 9)) << 1));
                    uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) >> 1);
                    uint8_t a_hi1_next = ((a_hi1 << 8) | a1) >> 9;
                    a1 = a1_next;
                    a_hi1 = a_hi1_next;
                    continue;
                }
                uint8_t a1_next2 = (uint8_t)(((a_hi1 << 8) | a1) >> 1);
                uint8_t a_hi1_next2 = ((a_hi1 << 8) | a1) >> 1 >> 8;
                a1 = a1_next2;
                a_hi1 = a_hi1_next2;
                break;
            }
            uint16_t value6 = RAM16(0x0002 + (uint16_t)(sp0 - 9));
            uint8_t value7 = RAM8(0x0004 + (uint16_t)(sp0 - 9));
            RAM8(0x10001 + value7) = (uint8_t)(((uint16_t)(value6 + 0x7F) & 0xFF80) >> 7);
            r->a = ((RAM8(0x0001 + (uint16_t)(sp0 - 9)) & 0xFC) << 8) | (uint8_t)(((uint16_t)(value6 + 0x7F) & 0xFF80) >> 7);
            r->x = value7;
            r->y = (uint8_t)y_ret;
            r->c = ((uint16_t)(value6 + 0x7F) & 0xFF80) >> 6 & 0x01;
            r->z = (uint8_t)(((uint16_t)(value6 + 0x7F) & 0xFF80) >> 7) == 0;
            r->n = (uint8_t)(((uint16_t)(value6 + 0x7F) & 0xFF80) >> 7) & 0x80;
            r->v = ((value6 ^ (uint16_t)(value6 + 0x7F)) & ((uint16_t)(value6 + 0x7F) ^ 0x7F) & 0x8000) != 0;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8106, 0x7ED5F3); GUARD_JSR(c, sp_call, 0x8106); } /* allocate_vram_pages */
            r->sp += 10;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret4 = r->xf;
            uint16_t a_all4 = r->a;
            if (x_ret4) {
                uint8_t value9 = RAM8(0x0004 + (uint16_t)(sp0 - 9));
                RAM8(0x10000 + value9) = (uint8_t)a_all4;
                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)a_all4 >> 2;
                uint8_t value10 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
                bool x_flag4;
                uint8_t a_hi5;
                uint16_t x4;
                uint16_t y4;
                bool carry4;
                bool zero4;
                bool negative4;
                bool overflow4;
                uint8_t data_bank4;
                uint16_t direct_page4;
                if ((value10 & 0xFC) == 0x80) {
                    uint8_t value11 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                    RAM8(0x0006 + (uint16_t)(sp0 - 9)) = value11 >> 1;
                    r->a = (a_all4 >> 8 << 8) | 1;
                    r->x = value9;
                    r->c = value11 & 0x01;
                    r->z = 0;
                    r->n = 0;
                    r->xf = 1;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8181, 0x7EC030); GUARD_JSR(c, sp_call, 0x8181); } /* allocate_ppu_register_entry */
                    r->sp += 10;
                    uint16_t dp_ret = r->dp;
                    uint8_t db_ret = r->db;
                    if (r->mf != 1) { c->fail = 3; return; }
                    bool x_ret6 = r->xf;
                    uint16_t a_all5 = r->a;
                    uint16_t x_ret7 = r->x;
                    uint16_t y_ret2 = r->y;
                    bool carry_ret5 = r->c;
                    bool overflow_ret5 = r->v;
                    uint8_t value12 = BUS8_RDP(c, (db_ret << 0x10) + 2 + x_ret7);
                    uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp_ret + 6));
                    BUS8_SET(c, (db_ret << 0x10) + 2 + x_ret7, (value12 & 0xF8) | value13);
                    x_flag4 = x_ret6;
                    a_hi5 = a_all5 >> 8;
                    x4 = x_ret7;
                    y4 = y_ret2;
                    carry4 = carry_ret5;
                    zero4 = ((value12 & 0xF8) | value13) == 0;
                    negative4 = ((value12 & 0xF8) | value13) & 0x80;
                    overflow4 = overflow_ret5;
                    data_bank4 = db_ret;
                    direct_page4 = dp_ret;
                } else {
                    bool x_flag3;
                    uint8_t a_hi4;
                    uint16_t x3;
                    uint16_t y3;
                    bool carry3;
                    bool zero3;
                    bool negative3;
                    bool overflow3;
                    uint8_t data_bank3;
                    uint16_t direct_page3;
                    if ((value10 & 0xFC) == 0x40) {
                        r->a = (a_all4 >> 8 << 8) | 0x0B;
                        r->x = value9;
                        r->c = (value10 & 0xFC) >= 0x40;
                        r->z = 0;
                        r->n = 0;
                        r->xf = 1;
                        r->sp -= 10;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x816B, 0x7EC030); GUARD_JSR(c, sp_call, 0x816B); } /* allocate_ppu_register_entry */
                        r->sp += 10;
                        uint16_t dp_ret2 = r->dp;
                        uint8_t db_ret2 = r->db;
                        if (r->mf != 1) { c->fail = 3; return; }
                        bool x_ret8 = r->xf;
                        uint16_t a_all6 = r->a;
                        uint16_t x_ret9 = r->x;
                        uint16_t y_ret3 = r->y;
                        bool carry_ret6 = r->c;
                        bool overflow_ret6 = r->v;
                        uint8_t value14 = BUS8_RDP(c, (db_ret2 << 0x10) + 2 + x_ret9);
                        uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 6));
                        BUS8_SET(c, (db_ret2 << 0x10) + 2 + x_ret9, (value14 & 0xF0) | value15);
                        x_flag3 = x_ret8;
                        a_hi4 = a_all6 >> 8;
                        x3 = x_ret9;
                        y3 = y_ret3;
                        carry3 = carry_ret6;
                        zero3 = ((value14 & 0xF0) | value15) == 0;
                        negative3 = ((value14 & 0xF0) | value15) & 0x80;
                        overflow3 = overflow_ret6;
                        data_bank3 = db_ret2;
                        direct_page3 = dp_ret2;
                    } else {
                        bool x_flag2;
                        uint8_t a_hi3;
                        uint16_t x2;
                        uint16_t y2;
                        bool carry2;
                        bool zero2;
                        bool negative2;
                        bool overflow2;
                        uint8_t data_bank2;
                        uint16_t direct_page2;
                        if ((value10 & 0xFC) == 0x44) {
                            uint8_t value16 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value16 << 4);
                            r->a = (a_all4 >> 8 << 8) | 0x0B;
                            r->x = value9;
                            r->c = (uint8_t)(value16 << 3) & 0x80;
                            r->z = 0;
                            r->n = 0;
                            r->xf = 1;
                            r->sp -= 10;
                            { const uint16_t sp_call = r->sp; JSR(c, 0x815A, 0x7EC030); GUARD_JSR(c, sp_call, 0x815A); } /* allocate_ppu_register_entry */
                            r->sp += 10;
                            uint16_t dp_ret3 = r->dp;
                            uint8_t db_ret3 = r->db;
                            if (r->mf != 1) { c->fail = 3; return; }
                            bool x_ret10 = r->xf;
                            uint16_t a_all7 = r->a;
                            uint16_t x_ret11 = r->x;
                            uint16_t y_ret4 = r->y;
                            bool carry_ret7 = r->c;
                            bool overflow_ret7 = r->v;
                            uint8_t value17 = BUS8_RDP(c, (db_ret3 << 0x10) + 2 + x_ret11);
                            uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 6));
                            BUS8_SET(c, (db_ret3 << 0x10) + 2 + x_ret11, (value17 & 0x0F) | value18);
                            x_flag2 = x_ret10;
                            a_hi3 = a_all7 >> 8;
                            x2 = x_ret11;
                            y2 = y_ret4;
                            carry2 = carry_ret7;
                            zero2 = ((value17 & 0x0F) | value18) == 0;
                            negative2 = ((value17 & 0x0F) | value18) & 0x80;
                            overflow2 = overflow_ret7;
                            data_bank2 = db_ret3;
                            direct_page2 = dp_ret3;
                        } else {
                            bool x_flag;
                            uint8_t a_hi2;
                            uint16_t x1;
                            uint16_t y1;
                            bool carry1;
                            bool zero1;
                            bool negative1;
                            bool overflow1;
                            uint8_t data_bank;
                            uint16_t direct_page;
                            if ((value10 & 0xFC) == 0x48) {
                                r->a = (a_all4 >> 8 << 8) | 0x0C;
                                r->x = value9;
                                r->c = (value10 & 0xFC) >= 0x48;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 1;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8141, 0x7EC030); GUARD_JSR(c, sp_call, 0x8141); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret4 = r->dp;
                                uint8_t db_ret4 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret12 = r->xf;
                                uint16_t a_all8 = r->a;
                                uint16_t x_ret13 = r->x;
                                uint16_t y_ret5 = r->y;
                                bool carry_ret8 = r->c;
                                bool overflow_ret8 = r->v;
                                uint8_t value19 = BUS8_RDP(c, (db_ret4 << 0x10) + 2 + x_ret13);
                                uint8_t value20 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 6));
                                BUS8_SET(c, (db_ret4 << 0x10) + 2 + x_ret13, (value19 & 0xF0) | value20);
                                x_flag = x_ret12;
                                a_hi2 = a_all8 >> 8;
                                x1 = x_ret13;
                                y1 = y_ret5;
                                carry1 = carry_ret8;
                                zero1 = ((value19 & 0xF0) | value20) == 0;
                                negative1 = ((value19 & 0xF0) | value20) & 0x80;
                                overflow1 = overflow_ret8;
                                data_bank = db_ret4;
                                direct_page = dp_ret4;
                            } else {
                                uint8_t value21 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value21 << 4);
                                r->a = (a_all4 >> 8 << 8) | 0x0C;
                                r->x = value9;
                                r->c = (uint8_t)(value21 << 3) & 0x80;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 1;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8130, 0x7EC030); GUARD_JSR(c, sp_call, 0x8130); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret5 = r->dp;
                                uint8_t db_ret5 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret14 = r->xf;
                                uint16_t a_all9 = r->a;
                                uint16_t x_ret15 = r->x;
                                uint16_t y_ret6 = r->y;
                                bool carry_ret9 = r->c;
                                bool overflow_ret9 = r->v;
                                uint8_t value22 = BUS8_RDP(c, (db_ret5 << 0x10) + 2 + x_ret15);
                                uint8_t value23 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 6));
                                BUS8_SET(c, (db_ret5 << 0x10) + 2 + x_ret15, (value22 & 0x0F) | value23);
                                x_flag = x_ret14;
                                a_hi2 = a_all9 >> 8;
                                x1 = x_ret15;
                                y1 = y_ret6;
                                carry1 = carry_ret9;
                                zero1 = ((value22 & 0x0F) | value23) == 0;
                                negative1 = ((value22 & 0x0F) | value23) & 0x80;
                                overflow1 = overflow_ret9;
                                data_bank = db_ret5;
                                direct_page = dp_ret5;
                            }
                            x_flag2 = x_flag;
                            a_hi3 = a_hi2;
                            x2 = x1;
                            y2 = y1;
                            carry2 = carry1;
                            zero2 = zero1;
                            negative2 = negative1;
                            overflow2 = overflow1;
                            data_bank2 = data_bank;
                            direct_page2 = direct_page;
                        }
                        x_flag3 = x_flag2;
                        a_hi4 = a_hi3;
                        x3 = x2;
                        y3 = y2;
                        carry3 = carry2;
                        zero3 = zero2;
                        negative3 = negative2;
                        overflow3 = overflow2;
                        data_bank3 = data_bank2;
                        direct_page3 = direct_page2;
                    }
                    x_flag4 = x_flag3;
                    a_hi5 = a_hi4;
                    x4 = x3;
                    y4 = y3;
                    carry4 = carry3;
                    zero4 = zero3;
                    negative4 = negative3;
                    overflow4 = overflow3;
                    data_bank4 = data_bank3;
                    direct_page4 = direct_page3;
                }
                if (x_flag4) {
                    a_hi_818c = a_hi5;
                    x_818c = (uint8_t)x4;
                    y_818c = (uint8_t)y4;
                    carry_818c = carry4;
                    zero_818c = zero4;
                    negative_818c = negative4;
                    overflow_818c = overflow4;
                    direct_page_818c = direct_page4;
                    data_bank_818c = data_bank4;
                    goto shared_818C;
                } else {
                    a_hi_818c2 = a_hi5;
                    x_818c2 = x4;
                    y_818c2 = y4;
                    carry_818c2 = carry4;
                    zero_818c2 = zero4;
                    negative_818c2 = negative4;
                    overflow_818c2 = overflow4;
                    direct_page_818c2 = direct_page4;
                    data_bank_818c2 = data_bank4;
                    goto shared_818C_1;
                }
            } else {
                uint16_t value24 = RAM16(0x0004 + (uint16_t)(sp0 - 9));
                RAM8(0x10000 + value24) = (uint8_t)a_all4;
                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)a_all4 >> 2;
                uint8_t value25 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
                bool x_flag8;
                uint8_t a_hi9;
                uint16_t x8;
                uint16_t y8;
                bool carry8;
                bool zero8;
                bool negative8;
                bool overflow8;
                uint8_t data_bank8;
                uint16_t direct_page8;
                if ((value25 & 0xFC) == 0x80) {
                    uint8_t value26 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                    RAM8(0x0006 + (uint16_t)(sp0 - 9)) = value26 >> 1;
                    r->a = (a_all4 >> 8 << 8) | 1;
                    r->x = value24;
                    r->c = value26 & 0x01;
                    r->z = 0;
                    r->n = 0;
                    r->xf = 0;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8181, 0x7EC030); GUARD_JSR(c, sp_call, 0x8181); } /* allocate_ppu_register_entry */
                    r->sp += 10;
                    uint16_t dp_ret6 = r->dp;
                    uint8_t db_ret6 = r->db;
                    if (r->mf != 1) { c->fail = 3; return; }
                    bool x_ret16 = r->xf;
                    uint16_t a_all10 = r->a;
                    uint16_t x_ret17 = r->x;
                    uint16_t y_ret7 = r->y;
                    bool carry_ret10 = r->c;
                    bool overflow_ret10 = r->v;
                    uint8_t value27 = BUS8_RDP(c, (db_ret6 << 0x10) + 2 + x_ret17);
                    uint8_t value28 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 6));
                    BUS8_SET(c, (db_ret6 << 0x10) + 2 + x_ret17, (value27 & 0xF8) | value28);
                    x_flag8 = x_ret16;
                    a_hi9 = a_all10 >> 8;
                    x8 = x_ret17;
                    y8 = y_ret7;
                    carry8 = carry_ret10;
                    zero8 = ((value27 & 0xF8) | value28) == 0;
                    negative8 = ((value27 & 0xF8) | value28) & 0x80;
                    overflow8 = overflow_ret10;
                    data_bank8 = db_ret6;
                    direct_page8 = dp_ret6;
                } else {
                    bool x_flag7;
                    uint8_t a_hi8;
                    uint16_t x7;
                    uint16_t y7;
                    bool carry7;
                    bool zero7;
                    bool negative7;
                    bool overflow7;
                    uint8_t data_bank7;
                    uint16_t direct_page7;
                    if ((value25 & 0xFC) == 0x40) {
                        r->a = (a_all4 >> 8 << 8) | 0x0B;
                        r->x = value24;
                        r->c = (value25 & 0xFC) >= 0x40;
                        r->z = 0;
                        r->n = 0;
                        r->xf = 0;
                        r->sp -= 10;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x816B, 0x7EC030); GUARD_JSR(c, sp_call, 0x816B); } /* allocate_ppu_register_entry */
                        r->sp += 10;
                        uint16_t dp_ret7 = r->dp;
                        uint8_t db_ret7 = r->db;
                        if (r->mf != 1) { c->fail = 3; return; }
                        bool x_ret18 = r->xf;
                        uint16_t a_all11 = r->a;
                        uint16_t x_ret19 = r->x;
                        uint16_t y_ret8 = r->y;
                        bool carry_ret11 = r->c;
                        bool overflow_ret11 = r->v;
                        uint8_t value29 = BUS8_RDP(c, (db_ret7 << 0x10) + 2 + x_ret19);
                        uint8_t value30 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 6));
                        BUS8_SET(c, (db_ret7 << 0x10) + 2 + x_ret19, (value29 & 0xF0) | value30);
                        x_flag7 = x_ret18;
                        a_hi8 = a_all11 >> 8;
                        x7 = x_ret19;
                        y7 = y_ret8;
                        carry7 = carry_ret11;
                        zero7 = ((value29 & 0xF0) | value30) == 0;
                        negative7 = ((value29 & 0xF0) | value30) & 0x80;
                        overflow7 = overflow_ret11;
                        data_bank7 = db_ret7;
                        direct_page7 = dp_ret7;
                    } else {
                        bool x_flag6;
                        uint8_t a_hi7;
                        uint16_t x6;
                        uint16_t y6;
                        bool carry6;
                        bool zero6;
                        bool negative6;
                        bool overflow6;
                        uint8_t data_bank6;
                        uint16_t direct_page6;
                        if ((value25 & 0xFC) == 0x44) {
                            uint8_t value31 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value31 << 4);
                            r->a = (a_all4 >> 8 << 8) | 0x0B;
                            r->x = value24;
                            r->c = (uint8_t)(value31 << 3) & 0x80;
                            r->z = 0;
                            r->n = 0;
                            r->xf = 0;
                            r->sp -= 10;
                            { const uint16_t sp_call = r->sp; JSR(c, 0x815A, 0x7EC030); GUARD_JSR(c, sp_call, 0x815A); } /* allocate_ppu_register_entry */
                            r->sp += 10;
                            uint16_t dp_ret8 = r->dp;
                            uint8_t db_ret8 = r->db;
                            if (r->mf != 1) { c->fail = 3; return; }
                            bool x_ret20 = r->xf;
                            uint16_t a_all12 = r->a;
                            uint16_t x_ret21 = r->x;
                            uint16_t y_ret9 = r->y;
                            bool carry_ret12 = r->c;
                            bool overflow_ret12 = r->v;
                            uint8_t value32 = BUS8_RDP(c, (db_ret8 << 0x10) + 2 + x_ret21);
                            uint8_t value33 = BUS8_RDP(c, (uint16_t)(dp_ret8 + 6));
                            BUS8_SET(c, (db_ret8 << 0x10) + 2 + x_ret21, (value32 & 0x0F) | value33);
                            x_flag6 = x_ret20;
                            a_hi7 = a_all12 >> 8;
                            x6 = x_ret21;
                            y6 = y_ret9;
                            carry6 = carry_ret12;
                            zero6 = ((value32 & 0x0F) | value33) == 0;
                            negative6 = ((value32 & 0x0F) | value33) & 0x80;
                            overflow6 = overflow_ret12;
                            data_bank6 = db_ret8;
                            direct_page6 = dp_ret8;
                        } else {
                            bool x_flag5;
                            uint8_t a_hi6;
                            uint16_t x5;
                            uint16_t y5;
                            bool carry5;
                            bool zero5;
                            bool negative5;
                            bool overflow5;
                            uint8_t data_bank5;
                            uint16_t direct_page5;
                            if ((value25 & 0xFC) == 0x48) {
                                r->a = (a_all4 >> 8 << 8) | 0x0C;
                                r->x = value24;
                                r->c = (value25 & 0xFC) >= 0x48;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 0;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8141, 0x7EC030); GUARD_JSR(c, sp_call, 0x8141); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret9 = r->dp;
                                uint8_t db_ret9 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret22 = r->xf;
                                uint16_t a_all13 = r->a;
                                uint16_t x_ret23 = r->x;
                                uint16_t y_ret10 = r->y;
                                bool carry_ret13 = r->c;
                                bool overflow_ret13 = r->v;
                                uint8_t value34 = BUS8_RDP(c, (db_ret9 << 0x10) + 2 + x_ret23);
                                uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp_ret9 + 6));
                                BUS8_SET(c, (db_ret9 << 0x10) + 2 + x_ret23, (value34 & 0xF0) | value35);
                                x_flag5 = x_ret22;
                                a_hi6 = a_all13 >> 8;
                                x5 = x_ret23;
                                y5 = y_ret10;
                                carry5 = carry_ret13;
                                zero5 = ((value34 & 0xF0) | value35) == 0;
                                negative5 = ((value34 & 0xF0) | value35) & 0x80;
                                overflow5 = overflow_ret13;
                                data_bank5 = db_ret9;
                                direct_page5 = dp_ret9;
                            } else {
                                uint8_t value36 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value36 << 4);
                                r->a = (a_all4 >> 8 << 8) | 0x0C;
                                r->x = value24;
                                r->c = (uint8_t)(value36 << 3) & 0x80;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 0;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8130, 0x7EC030); GUARD_JSR(c, sp_call, 0x8130); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret10 = r->dp;
                                uint8_t db_ret10 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret24 = r->xf;
                                uint16_t a_all14 = r->a;
                                uint16_t x_ret25 = r->x;
                                uint16_t y_ret11 = r->y;
                                bool carry_ret14 = r->c;
                                bool overflow_ret14 = r->v;
                                uint8_t value37 = BUS8_RDP(c, (db_ret10 << 0x10) + 2 + x_ret25);
                                uint8_t value38 = BUS8_RDP(c, (uint16_t)(dp_ret10 + 6));
                                BUS8_SET(c, (db_ret10 << 0x10) + 2 + x_ret25, (value37 & 0x0F) | value38);
                                x_flag5 = x_ret24;
                                a_hi6 = a_all14 >> 8;
                                x5 = x_ret25;
                                y5 = y_ret11;
                                carry5 = carry_ret14;
                                zero5 = ((value37 & 0x0F) | value38) == 0;
                                negative5 = ((value37 & 0x0F) | value38) & 0x80;
                                overflow5 = overflow_ret14;
                                data_bank5 = db_ret10;
                                direct_page5 = dp_ret10;
                            }
                            x_flag6 = x_flag5;
                            a_hi7 = a_hi6;
                            x6 = x5;
                            y6 = y5;
                            carry6 = carry5;
                            zero6 = zero5;
                            negative6 = negative5;
                            overflow6 = overflow5;
                            data_bank6 = data_bank5;
                            direct_page6 = direct_page5;
                        }
                        x_flag7 = x_flag6;
                        a_hi8 = a_hi7;
                        x7 = x6;
                        y7 = y6;
                        carry7 = carry6;
                        zero7 = zero6;
                        negative7 = negative6;
                        overflow7 = overflow6;
                        data_bank7 = data_bank6;
                        direct_page7 = direct_page6;
                    }
                    x_flag8 = x_flag7;
                    a_hi9 = a_hi8;
                    x8 = x7;
                    y8 = y7;
                    carry8 = carry7;
                    zero8 = zero7;
                    negative8 = negative7;
                    overflow8 = overflow7;
                    data_bank8 = data_bank7;
                    direct_page8 = direct_page7;
                }
                if (x_flag8) {
                    a_hi_818c = a_hi9;
                    x_818c = (uint8_t)x8;
                    y_818c = (uint8_t)y8;
                    carry_818c = carry8;
                    zero_818c = zero8;
                    negative_818c = negative8;
                    overflow_818c = overflow8;
                    direct_page_818c = direct_page8;
                    data_bank_818c = data_bank8;
                    goto shared_818C;
                } else {
                    a_hi_818c2 = a_hi9;
                    x_818c2 = x8;
                    y_818c2 = y8;
                    carry_818c2 = carry8;
                    zero_818c2 = zero8;
                    negative_818c2 = negative8;
                    overflow_818c2 = overflow8;
                    direct_page_818c2 = direct_page8;
                    data_bank_818c2 = data_bank8;
                    goto shared_818C_1;
                }
            }
        } else {
            uint16_t value39 = RAM16(0x0004 + (uint16_t)(sp0 - 9));
            BUS8_SET(c, 0x7F0006 + value39, (uint8_t)x_ret2);
            BUS8_SET(c, 0x7F0004 + value39, (uint8_t)x_ret2);
            uint8_t value40 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
            BUS8_SET(c, 0x7F0002 + value39, value40 & 3);
            r->a = (a_all2 >> 8 << 8) | (uint8_t)((value40 & 3) - 1);
            r->x = value39;
            r->z = (uint8_t)((value40 & 3) - 1) == 0;
            r->n = (uint8_t)((value40 & 3) - 1) & 0x80;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0x80DC, 0x7EC34D); GUARD_JSR(c, sp_call, 0x80DC); } /* derive_sixteen_bit_mask_from_low_nibble */
            r->sp += 10;
            uint16_t x_ret26 = r->x;
            uint8_t a2 = (uint8_t)x_ret26;
            uint8_t a_hi10 = x_ret26 >> 8;
            for (;;) {
                if (!(((a_hi10 << 8) | a2) & 0x01)) {
                    RAM16_SET(0x0002 + (uint16_t)(sp0 - 9), (uint16_t)(RAM16(0x0002 + (uint16_t)(sp0 - 9)) << 1));
                    uint8_t a2_next = (uint8_t)(((a_hi10 << 8) | a2) >> 1);
                    uint8_t a_hi10_next = ((a_hi10 << 8) | a2) >> 9;
                    a2 = a2_next;
                    a_hi10 = a_hi10_next;
                    continue;
                }
                uint8_t a2_next2 = (uint8_t)(((a_hi10 << 8) | a2) >> 1);
                uint8_t a_hi10_next2 = ((a_hi10 << 8) | a2) >> 1 >> 8;
                a2 = a2_next2;
                a_hi10 = a_hi10_next2;
                break;
            }
            uint16_t value42 = RAM16(0x0002 + (uint16_t)(sp0 - 9));
            uint16_t value43 = RAM16(0x0004 + (uint16_t)(sp0 - 9));
            BUS8_SET(c, 0x7F0001 + value43, (uint8_t)(((uint16_t)(value42 + 0x7F) & 0xFF80) >> 7));
            r->a = ((RAM8(0x0001 + (uint16_t)(sp0 - 9)) & 0xFC) << 8) | (uint8_t)(((uint16_t)(value42 + 0x7F) & 0xFF80) >> 7);
            r->x = value43;
            r->y = y_ret;
            r->c = ((uint16_t)(value42 + 0x7F) & 0xFF80) >> 6 & 0x01;
            r->z = (uint8_t)(((uint16_t)(value42 + 0x7F) & 0xFF80) >> 7) == 0;
            r->n = (uint8_t)(((uint16_t)(value42 + 0x7F) & 0xFF80) >> 7) & 0x80;
            r->v = ((value42 ^ (uint16_t)(value42 + 0x7F)) & ((uint16_t)(value42 + 0x7F) ^ 0x7F) & 0x8000) != 0;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8106, 0x7ED5F3); GUARD_JSR(c, sp_call, 0x8106); } /* allocate_vram_pages */
            r->sp += 10;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret27 = r->xf;
            uint16_t a_all16 = r->a;
            if (x_ret27) {
                uint8_t value45 = RAM8(0x0004 + (uint16_t)(sp0 - 9));
                RAM8(0x10000 + value45) = (uint8_t)a_all16;
                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)a_all16 >> 2;
                uint8_t value46 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
                bool x_flag12;
                uint8_t a_hi14;
                uint16_t x12;
                uint16_t y12;
                bool carry12;
                bool zero12;
                bool negative12;
                bool overflow12;
                uint8_t data_bank12;
                uint16_t direct_page12;
                if ((value46 & 0xFC) == 0x80) {
                    uint8_t value47 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                    RAM8(0x0006 + (uint16_t)(sp0 - 9)) = value47 >> 1;
                    r->a = (a_all16 >> 8 << 8) | 1;
                    r->x = value45;
                    r->y = (uint8_t)y_ret;
                    r->c = value47 & 0x01;
                    r->z = 0;
                    r->n = 0;
                    r->xf = 1;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8181, 0x7EC030); GUARD_JSR(c, sp_call, 0x8181); } /* allocate_ppu_register_entry */
                    r->sp += 10;
                    uint16_t dp_ret11 = r->dp;
                    uint8_t db_ret11 = r->db;
                    if (r->mf != 1) { c->fail = 3; return; }
                    bool x_ret29 = r->xf;
                    uint16_t a_all17 = r->a;
                    uint16_t x_ret30 = r->x;
                    uint16_t y_ret12 = r->y;
                    bool carry_ret17 = r->c;
                    bool overflow_ret17 = r->v;
                    uint8_t value48 = BUS8_RDP(c, (db_ret11 << 0x10) + 2 + x_ret30);
                    uint8_t value49 = BUS8_RDP(c, (uint16_t)(dp_ret11 + 6));
                    BUS8_SET(c, (db_ret11 << 0x10) + 2 + x_ret30, (value48 & 0xF8) | value49);
                    x_flag12 = x_ret29;
                    a_hi14 = a_all17 >> 8;
                    x12 = x_ret30;
                    y12 = y_ret12;
                    carry12 = carry_ret17;
                    zero12 = ((value48 & 0xF8) | value49) == 0;
                    negative12 = ((value48 & 0xF8) | value49) & 0x80;
                    overflow12 = overflow_ret17;
                    data_bank12 = db_ret11;
                    direct_page12 = dp_ret11;
                } else {
                    bool x_flag11;
                    uint8_t a_hi13;
                    uint16_t x11;
                    uint16_t y11;
                    bool carry11;
                    bool zero11;
                    bool negative11;
                    bool overflow11;
                    uint8_t data_bank11;
                    uint16_t direct_page11;
                    if ((value46 & 0xFC) == 0x40) {
                        r->a = (a_all16 >> 8 << 8) | 0x0B;
                        r->x = value45;
                        r->y = (uint8_t)y_ret;
                        r->c = (value46 & 0xFC) >= 0x40;
                        r->z = 0;
                        r->n = 0;
                        r->xf = 1;
                        r->sp -= 10;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x816B, 0x7EC030); GUARD_JSR(c, sp_call, 0x816B); } /* allocate_ppu_register_entry */
                        r->sp += 10;
                        uint16_t dp_ret12 = r->dp;
                        uint8_t db_ret12 = r->db;
                        if (r->mf != 1) { c->fail = 3; return; }
                        bool x_ret31 = r->xf;
                        uint16_t a_all18 = r->a;
                        uint16_t x_ret32 = r->x;
                        uint16_t y_ret13 = r->y;
                        bool carry_ret18 = r->c;
                        bool overflow_ret18 = r->v;
                        uint8_t value50 = BUS8_RDP(c, (db_ret12 << 0x10) + 2 + x_ret32);
                        uint8_t value51 = BUS8_RDP(c, (uint16_t)(dp_ret12 + 6));
                        BUS8_SET(c, (db_ret12 << 0x10) + 2 + x_ret32, (value50 & 0xF0) | value51);
                        x_flag11 = x_ret31;
                        a_hi13 = a_all18 >> 8;
                        x11 = x_ret32;
                        y11 = y_ret13;
                        carry11 = carry_ret18;
                        zero11 = ((value50 & 0xF0) | value51) == 0;
                        negative11 = ((value50 & 0xF0) | value51) & 0x80;
                        overflow11 = overflow_ret18;
                        data_bank11 = db_ret12;
                        direct_page11 = dp_ret12;
                    } else {
                        bool x_flag10;
                        uint8_t a_hi12;
                        uint16_t x10;
                        uint16_t y10;
                        bool carry10;
                        bool zero10;
                        bool negative10;
                        bool overflow10;
                        uint8_t data_bank10;
                        uint16_t direct_page10;
                        if ((value46 & 0xFC) == 0x44) {
                            uint8_t value52 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value52 << 4);
                            r->a = (a_all16 >> 8 << 8) | 0x0B;
                            r->x = value45;
                            r->y = (uint8_t)y_ret;
                            r->c = (uint8_t)(value52 << 3) & 0x80;
                            r->z = 0;
                            r->n = 0;
                            r->xf = 1;
                            r->sp -= 10;
                            { const uint16_t sp_call = r->sp; JSR(c, 0x815A, 0x7EC030); GUARD_JSR(c, sp_call, 0x815A); } /* allocate_ppu_register_entry */
                            r->sp += 10;
                            uint16_t dp_ret13 = r->dp;
                            uint8_t db_ret13 = r->db;
                            if (r->mf != 1) { c->fail = 3; return; }
                            bool x_ret33 = r->xf;
                            uint16_t a_all19 = r->a;
                            uint16_t x_ret34 = r->x;
                            uint16_t y_ret14 = r->y;
                            bool carry_ret19 = r->c;
                            bool overflow_ret19 = r->v;
                            uint8_t value53 = BUS8_RDP(c, (db_ret13 << 0x10) + 2 + x_ret34);
                            uint8_t value54 = BUS8_RDP(c, (uint16_t)(dp_ret13 + 6));
                            BUS8_SET(c, (db_ret13 << 0x10) + 2 + x_ret34, (value53 & 0x0F) | value54);
                            x_flag10 = x_ret33;
                            a_hi12 = a_all19 >> 8;
                            x10 = x_ret34;
                            y10 = y_ret14;
                            carry10 = carry_ret19;
                            zero10 = ((value53 & 0x0F) | value54) == 0;
                            negative10 = ((value53 & 0x0F) | value54) & 0x80;
                            overflow10 = overflow_ret19;
                            data_bank10 = db_ret13;
                            direct_page10 = dp_ret13;
                        } else {
                            bool x_flag9;
                            uint8_t a_hi11;
                            uint16_t x9;
                            uint16_t y9;
                            bool carry9;
                            bool zero9;
                            bool negative9;
                            bool overflow9;
                            uint8_t data_bank9;
                            uint16_t direct_page9;
                            if ((value46 & 0xFC) == 0x48) {
                                r->a = (a_all16 >> 8 << 8) | 0x0C;
                                r->x = value45;
                                r->y = (uint8_t)y_ret;
                                r->c = (value46 & 0xFC) >= 0x48;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 1;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8141, 0x7EC030); GUARD_JSR(c, sp_call, 0x8141); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret14 = r->dp;
                                uint8_t db_ret14 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret35 = r->xf;
                                uint16_t a_all20 = r->a;
                                uint16_t x_ret36 = r->x;
                                uint16_t y_ret15 = r->y;
                                bool carry_ret20 = r->c;
                                bool overflow_ret20 = r->v;
                                uint8_t value55 = BUS8_RDP(c, (db_ret14 << 0x10) + 2 + x_ret36);
                                uint8_t value56 = BUS8_RDP(c, (uint16_t)(dp_ret14 + 6));
                                BUS8_SET(c, (db_ret14 << 0x10) + 2 + x_ret36, (value55 & 0xF0) | value56);
                                x_flag9 = x_ret35;
                                a_hi11 = a_all20 >> 8;
                                x9 = x_ret36;
                                y9 = y_ret15;
                                carry9 = carry_ret20;
                                zero9 = ((value55 & 0xF0) | value56) == 0;
                                negative9 = ((value55 & 0xF0) | value56) & 0x80;
                                overflow9 = overflow_ret20;
                                data_bank9 = db_ret14;
                                direct_page9 = dp_ret14;
                            } else {
                                uint8_t value57 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value57 << 4);
                                r->a = (a_all16 >> 8 << 8) | 0x0C;
                                r->x = value45;
                                r->y = (uint8_t)y_ret;
                                r->c = (uint8_t)(value57 << 3) & 0x80;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 1;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8130, 0x7EC030); GUARD_JSR(c, sp_call, 0x8130); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret15 = r->dp;
                                uint8_t db_ret15 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret37 = r->xf;
                                uint16_t a_all21 = r->a;
                                uint16_t x_ret38 = r->x;
                                uint16_t y_ret16 = r->y;
                                bool carry_ret21 = r->c;
                                bool overflow_ret21 = r->v;
                                uint8_t value58 = BUS8_RDP(c, (db_ret15 << 0x10) + 2 + x_ret38);
                                uint8_t value59 = BUS8_RDP(c, (uint16_t)(dp_ret15 + 6));
                                BUS8_SET(c, (db_ret15 << 0x10) + 2 + x_ret38, (value58 & 0x0F) | value59);
                                x_flag9 = x_ret37;
                                a_hi11 = a_all21 >> 8;
                                x9 = x_ret38;
                                y9 = y_ret16;
                                carry9 = carry_ret21;
                                zero9 = ((value58 & 0x0F) | value59) == 0;
                                negative9 = ((value58 & 0x0F) | value59) & 0x80;
                                overflow9 = overflow_ret21;
                                data_bank9 = db_ret15;
                                direct_page9 = dp_ret15;
                            }
                            x_flag10 = x_flag9;
                            a_hi12 = a_hi11;
                            x10 = x9;
                            y10 = y9;
                            carry10 = carry9;
                            zero10 = zero9;
                            negative10 = negative9;
                            overflow10 = overflow9;
                            data_bank10 = data_bank9;
                            direct_page10 = direct_page9;
                        }
                        x_flag11 = x_flag10;
                        a_hi13 = a_hi12;
                        x11 = x10;
                        y11 = y10;
                        carry11 = carry10;
                        zero11 = zero10;
                        negative11 = negative10;
                        overflow11 = overflow10;
                        data_bank11 = data_bank10;
                        direct_page11 = direct_page10;
                    }
                    x_flag12 = x_flag11;
                    a_hi14 = a_hi13;
                    x12 = x11;
                    y12 = y11;
                    carry12 = carry11;
                    zero12 = zero11;
                    negative12 = negative11;
                    overflow12 = overflow11;
                    data_bank12 = data_bank11;
                    direct_page12 = direct_page11;
                }
                if (x_flag12) {
                    a_hi_818c = a_hi14;
                    x_818c = (uint8_t)x12;
                    y_818c = (uint8_t)y12;
                    carry_818c = carry12;
                    zero_818c = zero12;
                    negative_818c = negative12;
                    overflow_818c = overflow12;
                    direct_page_818c = direct_page12;
                    data_bank_818c = data_bank12;
                    goto shared_818C;
                } else {
                    a_hi_818c2 = a_hi14;
                    x_818c2 = x12;
                    y_818c2 = y12;
                    carry_818c2 = carry12;
                    zero_818c2 = zero12;
                    negative_818c2 = negative12;
                    overflow_818c2 = overflow12;
                    direct_page_818c2 = direct_page12;
                    data_bank_818c2 = data_bank12;
                    goto shared_818C_1;
                }
            } else {
                uint16_t value60 = RAM16(0x0004 + (uint16_t)(sp0 - 9));
                RAM8(0x10000 + value60) = (uint8_t)a_all16;
                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)a_all16 >> 2;
                uint8_t value61 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
                bool x_flag16;
                uint8_t a_hi18;
                uint16_t x16;
                uint16_t y16;
                bool carry16;
                bool zero16;
                bool negative16;
                bool overflow16;
                uint8_t data_bank16;
                uint16_t direct_page16;
                if ((value61 & 0xFC) == 0x80) {
                    uint8_t value62 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                    RAM8(0x0006 + (uint16_t)(sp0 - 9)) = value62 >> 1;
                    r->a = (a_all16 >> 8 << 8) | 1;
                    r->x = value60;
                    r->c = value62 & 0x01;
                    r->z = 0;
                    r->n = 0;
                    r->xf = 0;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8181, 0x7EC030); GUARD_JSR(c, sp_call, 0x8181); } /* allocate_ppu_register_entry */
                    r->sp += 10;
                    uint16_t dp_ret16 = r->dp;
                    uint8_t db_ret16 = r->db;
                    if (r->mf != 1) { c->fail = 3; return; }
                    bool x_ret39 = r->xf;
                    uint16_t a_all22 = r->a;
                    uint16_t x_ret40 = r->x;
                    uint16_t y_ret17 = r->y;
                    bool carry_ret22 = r->c;
                    bool overflow_ret22 = r->v;
                    uint8_t value63 = BUS8_RDP(c, (db_ret16 << 0x10) + 2 + x_ret40);
                    uint8_t value64 = BUS8_RDP(c, (uint16_t)(dp_ret16 + 6));
                    BUS8_SET(c, (db_ret16 << 0x10) + 2 + x_ret40, (value63 & 0xF8) | value64);
                    x_flag16 = x_ret39;
                    a_hi18 = a_all22 >> 8;
                    x16 = x_ret40;
                    y16 = y_ret17;
                    carry16 = carry_ret22;
                    zero16 = ((value63 & 0xF8) | value64) == 0;
                    negative16 = ((value63 & 0xF8) | value64) & 0x80;
                    overflow16 = overflow_ret22;
                    data_bank16 = db_ret16;
                    direct_page16 = dp_ret16;
                } else {
                    bool x_flag15;
                    uint8_t a_hi17;
                    uint16_t x15;
                    uint16_t y15;
                    bool carry15;
                    bool zero15;
                    bool negative15;
                    bool overflow15;
                    uint8_t data_bank15;
                    uint16_t direct_page15;
                    if ((value61 & 0xFC) == 0x40) {
                        r->a = (a_all16 >> 8 << 8) | 0x0B;
                        r->x = value60;
                        r->c = (value61 & 0xFC) >= 0x40;
                        r->z = 0;
                        r->n = 0;
                        r->xf = 0;
                        r->sp -= 10;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x816B, 0x7EC030); GUARD_JSR(c, sp_call, 0x816B); } /* allocate_ppu_register_entry */
                        r->sp += 10;
                        uint16_t dp_ret17 = r->dp;
                        uint8_t db_ret17 = r->db;
                        if (r->mf != 1) { c->fail = 3; return; }
                        bool x_ret41 = r->xf;
                        uint16_t a_all23 = r->a;
                        uint16_t x_ret42 = r->x;
                        uint16_t y_ret18 = r->y;
                        bool carry_ret23 = r->c;
                        bool overflow_ret23 = r->v;
                        uint8_t value65 = BUS8_RDP(c, (db_ret17 << 0x10) + 2 + x_ret42);
                        uint8_t value66 = BUS8_RDP(c, (uint16_t)(dp_ret17 + 6));
                        BUS8_SET(c, (db_ret17 << 0x10) + 2 + x_ret42, (value65 & 0xF0) | value66);
                        x_flag15 = x_ret41;
                        a_hi17 = a_all23 >> 8;
                        x15 = x_ret42;
                        y15 = y_ret18;
                        carry15 = carry_ret23;
                        zero15 = ((value65 & 0xF0) | value66) == 0;
                        negative15 = ((value65 & 0xF0) | value66) & 0x80;
                        overflow15 = overflow_ret23;
                        data_bank15 = db_ret17;
                        direct_page15 = dp_ret17;
                    } else {
                        bool x_flag14;
                        uint8_t a_hi16;
                        uint16_t x14;
                        uint16_t y14;
                        bool carry14;
                        bool zero14;
                        bool negative14;
                        bool overflow14;
                        uint8_t data_bank14;
                        uint16_t direct_page14;
                        if ((value61 & 0xFC) == 0x44) {
                            uint8_t value67 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value67 << 4);
                            r->a = (a_all16 >> 8 << 8) | 0x0B;
                            r->x = value60;
                            r->c = (uint8_t)(value67 << 3) & 0x80;
                            r->z = 0;
                            r->n = 0;
                            r->xf = 0;
                            r->sp -= 10;
                            { const uint16_t sp_call = r->sp; JSR(c, 0x815A, 0x7EC030); GUARD_JSR(c, sp_call, 0x815A); } /* allocate_ppu_register_entry */
                            r->sp += 10;
                            uint16_t dp_ret18 = r->dp;
                            uint8_t db_ret18 = r->db;
                            if (r->mf != 1) { c->fail = 3; return; }
                            bool x_ret43 = r->xf;
                            uint16_t a_all24 = r->a;
                            uint16_t x_ret44 = r->x;
                            uint16_t y_ret19 = r->y;
                            bool carry_ret24 = r->c;
                            bool overflow_ret24 = r->v;
                            uint8_t value68 = BUS8_RDP(c, (db_ret18 << 0x10) + 2 + x_ret44);
                            uint8_t value69 = BUS8_RDP(c, (uint16_t)(dp_ret18 + 6));
                            BUS8_SET(c, (db_ret18 << 0x10) + 2 + x_ret44, (value68 & 0x0F) | value69);
                            x_flag14 = x_ret43;
                            a_hi16 = a_all24 >> 8;
                            x14 = x_ret44;
                            y14 = y_ret19;
                            carry14 = carry_ret24;
                            zero14 = ((value68 & 0x0F) | value69) == 0;
                            negative14 = ((value68 & 0x0F) | value69) & 0x80;
                            overflow14 = overflow_ret24;
                            data_bank14 = db_ret18;
                            direct_page14 = dp_ret18;
                        } else {
                            bool x_flag13;
                            uint8_t a_hi15;
                            uint16_t x13;
                            uint16_t y13;
                            bool carry13;
                            bool zero13;
                            bool negative13;
                            bool overflow13;
                            uint8_t data_bank13;
                            uint16_t direct_page13;
                            if ((value61 & 0xFC) == 0x48) {
                                r->a = (a_all16 >> 8 << 8) | 0x0C;
                                r->x = value60;
                                r->c = (value61 & 0xFC) >= 0x48;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 0;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8141, 0x7EC030); GUARD_JSR(c, sp_call, 0x8141); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret19 = r->dp;
                                uint8_t db_ret19 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret45 = r->xf;
                                uint16_t a_all25 = r->a;
                                uint16_t x_ret46 = r->x;
                                uint16_t y_ret20 = r->y;
                                bool carry_ret25 = r->c;
                                bool overflow_ret25 = r->v;
                                uint8_t value70 = BUS8_RDP(c, (db_ret19 << 0x10) + 2 + x_ret46);
                                uint8_t value71 = BUS8_RDP(c, (uint16_t)(dp_ret19 + 6));
                                BUS8_SET(c, (db_ret19 << 0x10) + 2 + x_ret46, (value70 & 0xF0) | value71);
                                x_flag13 = x_ret45;
                                a_hi15 = a_all25 >> 8;
                                x13 = x_ret46;
                                y13 = y_ret20;
                                carry13 = carry_ret25;
                                zero13 = ((value70 & 0xF0) | value71) == 0;
                                negative13 = ((value70 & 0xF0) | value71) & 0x80;
                                overflow13 = overflow_ret25;
                                data_bank13 = db_ret19;
                                direct_page13 = dp_ret19;
                            } else {
                                uint8_t value72 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value72 << 4);
                                r->a = (a_all16 >> 8 << 8) | 0x0C;
                                r->x = value60;
                                r->c = (uint8_t)(value72 << 3) & 0x80;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 0;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8130, 0x7EC030); GUARD_JSR(c, sp_call, 0x8130); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret20 = r->dp;
                                uint8_t db_ret20 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret47 = r->xf;
                                uint16_t a_all26 = r->a;
                                uint16_t x_ret48 = r->x;
                                uint16_t y_ret21 = r->y;
                                bool carry_ret26 = r->c;
                                bool overflow_ret26 = r->v;
                                uint8_t value73 = BUS8_RDP(c, (db_ret20 << 0x10) + 2 + x_ret48);
                                uint8_t value74 = BUS8_RDP(c, (uint16_t)(dp_ret20 + 6));
                                BUS8_SET(c, (db_ret20 << 0x10) + 2 + x_ret48, (value73 & 0x0F) | value74);
                                x_flag13 = x_ret47;
                                a_hi15 = a_all26 >> 8;
                                x13 = x_ret48;
                                y13 = y_ret21;
                                carry13 = carry_ret26;
                                zero13 = ((value73 & 0x0F) | value74) == 0;
                                negative13 = ((value73 & 0x0F) | value74) & 0x80;
                                overflow13 = overflow_ret26;
                                data_bank13 = db_ret20;
                                direct_page13 = dp_ret20;
                            }
                            x_flag14 = x_flag13;
                            a_hi16 = a_hi15;
                            x14 = x13;
                            y14 = y13;
                            carry14 = carry13;
                            zero14 = zero13;
                            negative14 = negative13;
                            overflow14 = overflow13;
                            data_bank14 = data_bank13;
                            direct_page14 = direct_page13;
                        }
                        x_flag15 = x_flag14;
                        a_hi17 = a_hi16;
                        x15 = x14;
                        y15 = y14;
                        carry15 = carry14;
                        zero15 = zero14;
                        negative15 = negative14;
                        overflow15 = overflow14;
                        data_bank15 = data_bank14;
                        direct_page15 = direct_page14;
                    }
                    x_flag16 = x_flag15;
                    a_hi18 = a_hi17;
                    x16 = x15;
                    y16 = y15;
                    carry16 = carry15;
                    zero16 = zero15;
                    negative16 = negative15;
                    overflow16 = overflow15;
                    data_bank16 = data_bank15;
                    direct_page16 = direct_page15;
                }
                if (x_flag16) {
                    a_hi_818c = a_hi18;
                    x_818c = (uint8_t)x16;
                    y_818c = (uint8_t)y16;
                    carry_818c = carry16;
                    zero_818c = zero16;
                    negative_818c = negative16;
                    overflow_818c = overflow16;
                    direct_page_818c = direct_page16;
                    data_bank_818c = data_bank16;
                    goto shared_818C;
                } else {
                    a_hi_818c2 = a_hi18;
                    x_818c2 = x16;
                    y_818c2 = y16;
                    carry_818c2 = carry16;
                    zero_818c2 = zero16;
                    negative_818c2 = negative16;
                    overflow_818c2 = overflow16;
                    direct_page_818c2 = direct_page16;
                    data_bank_818c2 = data_bank16;
                    goto shared_818C_1;
                }
            }
        }
    } else {
        if (x_ret) {
            uint8_t value75 = RAM8(0x0004 + (uint16_t)(sp0 - 9));
            RAM16_SET(0x10006 + value75, (uint8_t)x_ret2);
            RAM16_SET(0x10004 + value75, (uint8_t)x_ret2);
            uint8_t value76 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
            RAM8(0x10002 + value75) = value76 & 3;
            r->a = (uint8_t)((value76 & 3) - 1);
            r->x = value75;
            r->y = (uint8_t)y_ret;
            r->z = (uint8_t)((value76 & 3) - 1) == 0;
            r->n = (uint8_t)((value76 & 3) - 1) & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0x80DC, 0x7EC34D); GUARD_JSR(c, sp_call, 0x80DC); } /* derive_sixteen_bit_mask_from_low_nibble */
            r->sp += 10;
            uint8_t x_ret49 = r->x;
            uint8_t a3 = x_ret49;
            uint8_t a_hi19 = 0;
            for (;;) {
                if (!(((a_hi19 << 8) | a3) & 0x01)) {
                    RAM16_SET(0x0002 + (uint16_t)(sp0 - 9), (uint16_t)(RAM16(0x0002 + (uint16_t)(sp0 - 9)) << 1));
                    uint8_t a3_next = (uint8_t)(((a_hi19 << 8) | a3) >> 1);
                    uint8_t a_hi19_next = ((a_hi19 << 8) | a3) >> 9;
                    a3 = a3_next;
                    a_hi19 = a_hi19_next;
                    continue;
                }
                uint8_t a3_next2 = (uint8_t)(((a_hi19 << 8) | a3) >> 1);
                uint8_t a_hi19_next2 = ((a_hi19 << 8) | a3) >> 1 >> 8;
                a3 = a3_next2;
                a_hi19 = a_hi19_next2;
                break;
            }
            uint16_t value78 = RAM16(0x0002 + (uint16_t)(sp0 - 9));
            uint8_t value79 = RAM8(0x0004 + (uint16_t)(sp0 - 9));
            RAM8(0x10001 + value79) = (uint8_t)(((uint16_t)(value78 + 0x7F) & 0xFF80) >> 7);
            r->a = ((RAM8(0x0001 + (uint16_t)(sp0 - 9)) & 0xFC) << 8) | (uint8_t)(((uint16_t)(value78 + 0x7F) & 0xFF80) >> 7);
            r->x = value79;
            r->y = (uint8_t)y_ret;
            r->c = ((uint16_t)(value78 + 0x7F) & 0xFF80) >> 6 & 0x01;
            r->z = (uint8_t)(((uint16_t)(value78 + 0x7F) & 0xFF80) >> 7) == 0;
            r->n = (uint8_t)(((uint16_t)(value78 + 0x7F) & 0xFF80) >> 7) & 0x80;
            r->v = ((value78 ^ (uint16_t)(value78 + 0x7F)) & ((uint16_t)(value78 + 0x7F) ^ 0x7F) & 0x8000) != 0;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8106, 0x7ED5F3); GUARD_JSR(c, sp_call, 0x8106); } /* allocate_vram_pages */
            r->sp += 10;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret50 = r->xf;
            uint16_t a_all28 = r->a;
            if (x_ret50) {
                uint8_t value81 = RAM8(0x0004 + (uint16_t)(sp0 - 9));
                RAM8(0x10000 + value81) = (uint8_t)a_all28;
                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)a_all28 >> 2;
                uint8_t value82 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
                bool x_flag20;
                uint8_t a_hi23;
                uint16_t x20;
                uint16_t y20;
                bool carry20;
                bool zero20;
                bool negative20;
                bool overflow20;
                uint8_t data_bank20;
                uint16_t direct_page20;
                if ((value82 & 0xFC) == 0x80) {
                    uint8_t value83 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                    RAM8(0x0006 + (uint16_t)(sp0 - 9)) = value83 >> 1;
                    r->a = (a_all28 >> 8 << 8) | 1;
                    r->x = value81;
                    r->c = value83 & 0x01;
                    r->z = 0;
                    r->n = 0;
                    r->xf = 1;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8181, 0x7EC030); GUARD_JSR(c, sp_call, 0x8181); } /* allocate_ppu_register_entry */
                    r->sp += 10;
                    uint16_t dp_ret21 = r->dp;
                    uint8_t db_ret21 = r->db;
                    if (r->mf != 1) { c->fail = 3; return; }
                    bool x_ret52 = r->xf;
                    uint16_t a_all29 = r->a;
                    uint16_t x_ret53 = r->x;
                    uint16_t y_ret22 = r->y;
                    bool carry_ret29 = r->c;
                    bool overflow_ret29 = r->v;
                    uint8_t value84 = BUS8_RDP(c, (db_ret21 << 0x10) + 2 + x_ret53);
                    uint8_t value85 = BUS8_RDP(c, (uint16_t)(dp_ret21 + 6));
                    BUS8_SET(c, (db_ret21 << 0x10) + 2 + x_ret53, (value84 & 0xF8) | value85);
                    x_flag20 = x_ret52;
                    a_hi23 = a_all29 >> 8;
                    x20 = x_ret53;
                    y20 = y_ret22;
                    carry20 = carry_ret29;
                    zero20 = ((value84 & 0xF8) | value85) == 0;
                    negative20 = ((value84 & 0xF8) | value85) & 0x80;
                    overflow20 = overflow_ret29;
                    data_bank20 = db_ret21;
                    direct_page20 = dp_ret21;
                } else {
                    bool x_flag19;
                    uint8_t a_hi22;
                    uint16_t x19;
                    uint16_t y19;
                    bool carry19;
                    bool zero19;
                    bool negative19;
                    bool overflow19;
                    uint8_t data_bank19;
                    uint16_t direct_page19;
                    if ((value82 & 0xFC) == 0x40) {
                        r->a = (a_all28 >> 8 << 8) | 0x0B;
                        r->x = value81;
                        r->c = (value82 & 0xFC) >= 0x40;
                        r->z = 0;
                        r->n = 0;
                        r->xf = 1;
                        r->sp -= 10;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x816B, 0x7EC030); GUARD_JSR(c, sp_call, 0x816B); } /* allocate_ppu_register_entry */
                        r->sp += 10;
                        uint16_t dp_ret22 = r->dp;
                        uint8_t db_ret22 = r->db;
                        if (r->mf != 1) { c->fail = 3; return; }
                        bool x_ret54 = r->xf;
                        uint16_t a_all30 = r->a;
                        uint16_t x_ret55 = r->x;
                        uint16_t y_ret23 = r->y;
                        bool carry_ret30 = r->c;
                        bool overflow_ret30 = r->v;
                        uint8_t value86 = BUS8_RDP(c, (db_ret22 << 0x10) + 2 + x_ret55);
                        uint8_t value87 = BUS8_RDP(c, (uint16_t)(dp_ret22 + 6));
                        BUS8_SET(c, (db_ret22 << 0x10) + 2 + x_ret55, (value86 & 0xF0) | value87);
                        x_flag19 = x_ret54;
                        a_hi22 = a_all30 >> 8;
                        x19 = x_ret55;
                        y19 = y_ret23;
                        carry19 = carry_ret30;
                        zero19 = ((value86 & 0xF0) | value87) == 0;
                        negative19 = ((value86 & 0xF0) | value87) & 0x80;
                        overflow19 = overflow_ret30;
                        data_bank19 = db_ret22;
                        direct_page19 = dp_ret22;
                    } else {
                        bool x_flag18;
                        uint8_t a_hi21;
                        uint16_t x18;
                        uint16_t y18;
                        bool carry18;
                        bool zero18;
                        bool negative18;
                        bool overflow18;
                        uint8_t data_bank18;
                        uint16_t direct_page18;
                        if ((value82 & 0xFC) == 0x44) {
                            uint8_t value88 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value88 << 4);
                            r->a = (a_all28 >> 8 << 8) | 0x0B;
                            r->x = value81;
                            r->c = (uint8_t)(value88 << 3) & 0x80;
                            r->z = 0;
                            r->n = 0;
                            r->xf = 1;
                            r->sp -= 10;
                            { const uint16_t sp_call = r->sp; JSR(c, 0x815A, 0x7EC030); GUARD_JSR(c, sp_call, 0x815A); } /* allocate_ppu_register_entry */
                            r->sp += 10;
                            uint16_t dp_ret23 = r->dp;
                            uint8_t db_ret23 = r->db;
                            if (r->mf != 1) { c->fail = 3; return; }
                            bool x_ret56 = r->xf;
                            uint16_t a_all31 = r->a;
                            uint16_t x_ret57 = r->x;
                            uint16_t y_ret24 = r->y;
                            bool carry_ret31 = r->c;
                            bool overflow_ret31 = r->v;
                            uint8_t value89 = BUS8_RDP(c, (db_ret23 << 0x10) + 2 + x_ret57);
                            uint8_t value90 = BUS8_RDP(c, (uint16_t)(dp_ret23 + 6));
                            BUS8_SET(c, (db_ret23 << 0x10) + 2 + x_ret57, (value89 & 0x0F) | value90);
                            x_flag18 = x_ret56;
                            a_hi21 = a_all31 >> 8;
                            x18 = x_ret57;
                            y18 = y_ret24;
                            carry18 = carry_ret31;
                            zero18 = ((value89 & 0x0F) | value90) == 0;
                            negative18 = ((value89 & 0x0F) | value90) & 0x80;
                            overflow18 = overflow_ret31;
                            data_bank18 = db_ret23;
                            direct_page18 = dp_ret23;
                        } else {
                            bool x_flag17;
                            uint8_t a_hi20;
                            uint16_t x17;
                            uint16_t y17;
                            bool carry17;
                            bool zero17;
                            bool negative17;
                            bool overflow17;
                            uint8_t data_bank17;
                            uint16_t direct_page17;
                            if ((value82 & 0xFC) == 0x48) {
                                r->a = (a_all28 >> 8 << 8) | 0x0C;
                                r->x = value81;
                                r->c = (value82 & 0xFC) >= 0x48;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 1;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8141, 0x7EC030); GUARD_JSR(c, sp_call, 0x8141); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret24 = r->dp;
                                uint8_t db_ret24 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret58 = r->xf;
                                uint16_t a_all32 = r->a;
                                uint16_t x_ret59 = r->x;
                                uint16_t y_ret25 = r->y;
                                bool carry_ret32 = r->c;
                                bool overflow_ret32 = r->v;
                                uint8_t value91 = BUS8_RDP(c, (db_ret24 << 0x10) + 2 + x_ret59);
                                uint8_t value92 = BUS8_RDP(c, (uint16_t)(dp_ret24 + 6));
                                BUS8_SET(c, (db_ret24 << 0x10) + 2 + x_ret59, (value91 & 0xF0) | value92);
                                x_flag17 = x_ret58;
                                a_hi20 = a_all32 >> 8;
                                x17 = x_ret59;
                                y17 = y_ret25;
                                carry17 = carry_ret32;
                                zero17 = ((value91 & 0xF0) | value92) == 0;
                                negative17 = ((value91 & 0xF0) | value92) & 0x80;
                                overflow17 = overflow_ret32;
                                data_bank17 = db_ret24;
                                direct_page17 = dp_ret24;
                            } else {
                                uint8_t value93 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value93 << 4);
                                r->a = (a_all28 >> 8 << 8) | 0x0C;
                                r->x = value81;
                                r->c = (uint8_t)(value93 << 3) & 0x80;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 1;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8130, 0x7EC030); GUARD_JSR(c, sp_call, 0x8130); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret25 = r->dp;
                                uint8_t db_ret25 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret60 = r->xf;
                                uint16_t a_all33 = r->a;
                                uint16_t x_ret61 = r->x;
                                uint16_t y_ret26 = r->y;
                                bool carry_ret33 = r->c;
                                bool overflow_ret33 = r->v;
                                uint8_t value94 = BUS8_RDP(c, (db_ret25 << 0x10) + 2 + x_ret61);
                                uint8_t value95 = BUS8_RDP(c, (uint16_t)(dp_ret25 + 6));
                                BUS8_SET(c, (db_ret25 << 0x10) + 2 + x_ret61, (value94 & 0x0F) | value95);
                                x_flag17 = x_ret60;
                                a_hi20 = a_all33 >> 8;
                                x17 = x_ret61;
                                y17 = y_ret26;
                                carry17 = carry_ret33;
                                zero17 = ((value94 & 0x0F) | value95) == 0;
                                negative17 = ((value94 & 0x0F) | value95) & 0x80;
                                overflow17 = overflow_ret33;
                                data_bank17 = db_ret25;
                                direct_page17 = dp_ret25;
                            }
                            x_flag18 = x_flag17;
                            a_hi21 = a_hi20;
                            x18 = x17;
                            y18 = y17;
                            carry18 = carry17;
                            zero18 = zero17;
                            negative18 = negative17;
                            overflow18 = overflow17;
                            data_bank18 = data_bank17;
                            direct_page18 = direct_page17;
                        }
                        x_flag19 = x_flag18;
                        a_hi22 = a_hi21;
                        x19 = x18;
                        y19 = y18;
                        carry19 = carry18;
                        zero19 = zero18;
                        negative19 = negative18;
                        overflow19 = overflow18;
                        data_bank19 = data_bank18;
                        direct_page19 = direct_page18;
                    }
                    x_flag20 = x_flag19;
                    a_hi23 = a_hi22;
                    x20 = x19;
                    y20 = y19;
                    carry20 = carry19;
                    zero20 = zero19;
                    negative20 = negative19;
                    overflow20 = overflow19;
                    data_bank20 = data_bank19;
                    direct_page20 = direct_page19;
                }
                if (x_flag20) {
                    a_hi_818c = a_hi23;
                    x_818c = (uint8_t)x20;
                    y_818c = (uint8_t)y20;
                    carry_818c = carry20;
                    zero_818c = zero20;
                    negative_818c = negative20;
                    overflow_818c = overflow20;
                    direct_page_818c = direct_page20;
                    data_bank_818c = data_bank20;
                    goto shared_818C;
                } else {
                    a_hi_818c2 = a_hi23;
                    x_818c2 = x20;
                    y_818c2 = y20;
                    carry_818c2 = carry20;
                    zero_818c2 = zero20;
                    negative_818c2 = negative20;
                    overflow_818c2 = overflow20;
                    direct_page_818c2 = direct_page20;
                    data_bank_818c2 = data_bank20;
                    goto shared_818C_1;
                }
            } else {
                uint16_t value96 = RAM16(0x0004 + (uint16_t)(sp0 - 9));
                RAM8(0x10000 + value96) = (uint8_t)a_all28;
                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)a_all28 >> 2;
                uint8_t value97 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
                bool x_flag24;
                uint8_t a_hi27;
                uint16_t x24;
                uint16_t y24;
                bool carry24;
                bool zero24;
                bool negative24;
                bool overflow24;
                uint8_t data_bank24;
                uint16_t direct_page24;
                if ((value97 & 0xFC) == 0x80) {
                    uint8_t value98 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                    RAM8(0x0006 + (uint16_t)(sp0 - 9)) = value98 >> 1;
                    r->a = (a_all28 >> 8 << 8) | 1;
                    r->x = value96;
                    r->c = value98 & 0x01;
                    r->z = 0;
                    r->n = 0;
                    r->xf = 0;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8181, 0x7EC030); GUARD_JSR(c, sp_call, 0x8181); } /* allocate_ppu_register_entry */
                    r->sp += 10;
                    uint16_t dp_ret26 = r->dp;
                    uint8_t db_ret26 = r->db;
                    if (r->mf != 1) { c->fail = 3; return; }
                    bool x_ret62 = r->xf;
                    uint16_t a_all34 = r->a;
                    uint16_t x_ret63 = r->x;
                    uint16_t y_ret27 = r->y;
                    bool carry_ret34 = r->c;
                    bool overflow_ret34 = r->v;
                    uint8_t value99 = BUS8_RDP(c, (db_ret26 << 0x10) + 2 + x_ret63);
                    uint8_t value100 = BUS8_RDP(c, (uint16_t)(dp_ret26 + 6));
                    BUS8_SET(c, (db_ret26 << 0x10) + 2 + x_ret63, (value99 & 0xF8) | value100);
                    x_flag24 = x_ret62;
                    a_hi27 = a_all34 >> 8;
                    x24 = x_ret63;
                    y24 = y_ret27;
                    carry24 = carry_ret34;
                    zero24 = ((value99 & 0xF8) | value100) == 0;
                    negative24 = ((value99 & 0xF8) | value100) & 0x80;
                    overflow24 = overflow_ret34;
                    data_bank24 = db_ret26;
                    direct_page24 = dp_ret26;
                } else {
                    bool x_flag23;
                    uint8_t a_hi26;
                    uint16_t x23;
                    uint16_t y23;
                    bool carry23;
                    bool zero23;
                    bool negative23;
                    bool overflow23;
                    uint8_t data_bank23;
                    uint16_t direct_page23;
                    if ((value97 & 0xFC) == 0x40) {
                        r->a = (a_all28 >> 8 << 8) | 0x0B;
                        r->x = value96;
                        r->c = (value97 & 0xFC) >= 0x40;
                        r->z = 0;
                        r->n = 0;
                        r->xf = 0;
                        r->sp -= 10;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x816B, 0x7EC030); GUARD_JSR(c, sp_call, 0x816B); } /* allocate_ppu_register_entry */
                        r->sp += 10;
                        uint16_t dp_ret27 = r->dp;
                        uint8_t db_ret27 = r->db;
                        if (r->mf != 1) { c->fail = 3; return; }
                        bool x_ret64 = r->xf;
                        uint16_t a_all35 = r->a;
                        uint16_t x_ret65 = r->x;
                        uint16_t y_ret28 = r->y;
                        bool carry_ret35 = r->c;
                        bool overflow_ret35 = r->v;
                        uint8_t value101 = BUS8_RDP(c, (db_ret27 << 0x10) + 2 + x_ret65);
                        uint8_t value102 = BUS8_RDP(c, (uint16_t)(dp_ret27 + 6));
                        BUS8_SET(c, (db_ret27 << 0x10) + 2 + x_ret65, (value101 & 0xF0) | value102);
                        x_flag23 = x_ret64;
                        a_hi26 = a_all35 >> 8;
                        x23 = x_ret65;
                        y23 = y_ret28;
                        carry23 = carry_ret35;
                        zero23 = ((value101 & 0xF0) | value102) == 0;
                        negative23 = ((value101 & 0xF0) | value102) & 0x80;
                        overflow23 = overflow_ret35;
                        data_bank23 = db_ret27;
                        direct_page23 = dp_ret27;
                    } else {
                        bool x_flag22;
                        uint8_t a_hi25;
                        uint16_t x22;
                        uint16_t y22;
                        bool carry22;
                        bool zero22;
                        bool negative22;
                        bool overflow22;
                        uint8_t data_bank22;
                        uint16_t direct_page22;
                        if ((value97 & 0xFC) == 0x44) {
                            uint8_t value103 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value103 << 4);
                            r->a = (a_all28 >> 8 << 8) | 0x0B;
                            r->x = value96;
                            r->c = (uint8_t)(value103 << 3) & 0x80;
                            r->z = 0;
                            r->n = 0;
                            r->xf = 0;
                            r->sp -= 10;
                            { const uint16_t sp_call = r->sp; JSR(c, 0x815A, 0x7EC030); GUARD_JSR(c, sp_call, 0x815A); } /* allocate_ppu_register_entry */
                            r->sp += 10;
                            uint16_t dp_ret28 = r->dp;
                            uint8_t db_ret28 = r->db;
                            if (r->mf != 1) { c->fail = 3; return; }
                            bool x_ret66 = r->xf;
                            uint16_t a_all36 = r->a;
                            uint16_t x_ret67 = r->x;
                            uint16_t y_ret29 = r->y;
                            bool carry_ret36 = r->c;
                            bool overflow_ret36 = r->v;
                            uint8_t value104 = BUS8_RDP(c, (db_ret28 << 0x10) + 2 + x_ret67);
                            uint8_t value105 = BUS8_RDP(c, (uint16_t)(dp_ret28 + 6));
                            BUS8_SET(c, (db_ret28 << 0x10) + 2 + x_ret67, (value104 & 0x0F) | value105);
                            x_flag22 = x_ret66;
                            a_hi25 = a_all36 >> 8;
                            x22 = x_ret67;
                            y22 = y_ret29;
                            carry22 = carry_ret36;
                            zero22 = ((value104 & 0x0F) | value105) == 0;
                            negative22 = ((value104 & 0x0F) | value105) & 0x80;
                            overflow22 = overflow_ret36;
                            data_bank22 = db_ret28;
                            direct_page22 = dp_ret28;
                        } else {
                            bool x_flag21;
                            uint8_t a_hi24;
                            uint16_t x21;
                            uint16_t y21;
                            bool carry21;
                            bool zero21;
                            bool negative21;
                            bool overflow21;
                            uint8_t data_bank21;
                            uint16_t direct_page21;
                            if ((value97 & 0xFC) == 0x48) {
                                r->a = (a_all28 >> 8 << 8) | 0x0C;
                                r->x = value96;
                                r->c = (value97 & 0xFC) >= 0x48;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 0;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8141, 0x7EC030); GUARD_JSR(c, sp_call, 0x8141); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret29 = r->dp;
                                uint8_t db_ret29 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret68 = r->xf;
                                uint16_t a_all37 = r->a;
                                uint16_t x_ret69 = r->x;
                                uint16_t y_ret30 = r->y;
                                bool carry_ret37 = r->c;
                                bool overflow_ret37 = r->v;
                                uint8_t value106 = BUS8_RDP(c, (db_ret29 << 0x10) + 2 + x_ret69);
                                uint8_t value107 = BUS8_RDP(c, (uint16_t)(dp_ret29 + 6));
                                BUS8_SET(c, (db_ret29 << 0x10) + 2 + x_ret69, (value106 & 0xF0) | value107);
                                x_flag21 = x_ret68;
                                a_hi24 = a_all37 >> 8;
                                x21 = x_ret69;
                                y21 = y_ret30;
                                carry21 = carry_ret37;
                                zero21 = ((value106 & 0xF0) | value107) == 0;
                                negative21 = ((value106 & 0xF0) | value107) & 0x80;
                                overflow21 = overflow_ret37;
                                data_bank21 = db_ret29;
                                direct_page21 = dp_ret29;
                            } else {
                                uint8_t value108 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value108 << 4);
                                r->a = (a_all28 >> 8 << 8) | 0x0C;
                                r->x = value96;
                                r->c = (uint8_t)(value108 << 3) & 0x80;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 0;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8130, 0x7EC030); GUARD_JSR(c, sp_call, 0x8130); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret30 = r->dp;
                                uint8_t db_ret30 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret70 = r->xf;
                                uint16_t a_all38 = r->a;
                                uint16_t x_ret71 = r->x;
                                uint16_t y_ret31 = r->y;
                                bool carry_ret38 = r->c;
                                bool overflow_ret38 = r->v;
                                uint8_t value109 = BUS8_RDP(c, (db_ret30 << 0x10) + 2 + x_ret71);
                                uint8_t value110 = BUS8_RDP(c, (uint16_t)(dp_ret30 + 6));
                                BUS8_SET(c, (db_ret30 << 0x10) + 2 + x_ret71, (value109 & 0x0F) | value110);
                                x_flag21 = x_ret70;
                                a_hi24 = a_all38 >> 8;
                                x21 = x_ret71;
                                y21 = y_ret31;
                                carry21 = carry_ret38;
                                zero21 = ((value109 & 0x0F) | value110) == 0;
                                negative21 = ((value109 & 0x0F) | value110) & 0x80;
                                overflow21 = overflow_ret38;
                                data_bank21 = db_ret30;
                                direct_page21 = dp_ret30;
                            }
                            x_flag22 = x_flag21;
                            a_hi25 = a_hi24;
                            x22 = x21;
                            y22 = y21;
                            carry22 = carry21;
                            zero22 = zero21;
                            negative22 = negative21;
                            overflow22 = overflow21;
                            data_bank22 = data_bank21;
                            direct_page22 = direct_page21;
                        }
                        x_flag23 = x_flag22;
                        a_hi26 = a_hi25;
                        x23 = x22;
                        y23 = y22;
                        carry23 = carry22;
                        zero23 = zero22;
                        negative23 = negative22;
                        overflow23 = overflow22;
                        data_bank23 = data_bank22;
                        direct_page23 = direct_page22;
                    }
                    x_flag24 = x_flag23;
                    a_hi27 = a_hi26;
                    x24 = x23;
                    y24 = y23;
                    carry24 = carry23;
                    zero24 = zero23;
                    negative24 = negative23;
                    overflow24 = overflow23;
                    data_bank24 = data_bank23;
                    direct_page24 = direct_page23;
                }
                if (x_flag24) {
                    a_hi_818c = a_hi27;
                    x_818c = (uint8_t)x24;
                    y_818c = (uint8_t)y24;
                    carry_818c = carry24;
                    zero_818c = zero24;
                    negative_818c = negative24;
                    overflow_818c = overflow24;
                    direct_page_818c = direct_page24;
                    data_bank_818c = data_bank24;
                    goto shared_818C;
                } else {
                    a_hi_818c2 = a_hi27;
                    x_818c2 = x24;
                    y_818c2 = y24;
                    carry_818c2 = carry24;
                    zero_818c2 = zero24;
                    negative_818c2 = negative24;
                    overflow_818c2 = overflow24;
                    direct_page_818c2 = direct_page24;
                    data_bank_818c2 = data_bank24;
                    goto shared_818C_1;
                }
            }
        } else {
            uint16_t value111 = RAM16(0x0004 + (uint16_t)(sp0 - 9));
            BUS16_SET(c, 0x7F0006 + value111, x_ret2);
            BUS16_SET(c, 0x7F0004 + value111, x_ret2);
            uint8_t value112 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
            BUS8_SET(c, 0x7F0002 + value111, value112 & 3);
            r->a = (x_ret2 >> 8 << 8) | (uint8_t)((value112 & 3) - 1);
            r->x = value111;
            r->z = (uint8_t)((value112 & 3) - 1) == 0;
            r->n = (uint8_t)((value112 & 3) - 1) & 0x80;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0x80DC, 0x7EC34D); GUARD_JSR(c, sp_call, 0x80DC); } /* derive_sixteen_bit_mask_from_low_nibble */
            r->sp += 10;
            uint16_t x_ret72 = r->x;
            uint8_t a4 = (uint8_t)x_ret72;
            uint8_t a_hi28 = x_ret72 >> 8;
            for (;;) {
                if (!(((a_hi28 << 8) | a4) & 0x01)) {
                    RAM16_SET(0x0002 + (uint16_t)(sp0 - 9), (uint16_t)(RAM16(0x0002 + (uint16_t)(sp0 - 9)) << 1));
                    uint8_t a4_next = (uint8_t)(((a_hi28 << 8) | a4) >> 1);
                    uint8_t a_hi28_next = ((a_hi28 << 8) | a4) >> 9;
                    a4 = a4_next;
                    a_hi28 = a_hi28_next;
                    continue;
                }
                uint8_t a4_next2 = (uint8_t)(((a_hi28 << 8) | a4) >> 1);
                uint8_t a_hi28_next2 = ((a_hi28 << 8) | a4) >> 1 >> 8;
                a4 = a4_next2;
                a_hi28 = a_hi28_next2;
                break;
            }
            uint16_t value114 = RAM16(0x0002 + (uint16_t)(sp0 - 9));
            uint16_t value115 = RAM16(0x0004 + (uint16_t)(sp0 - 9));
            BUS8_SET(c, 0x7F0001 + value115, (uint8_t)(((uint16_t)(value114 + 0x7F) & 0xFF80) >> 7));
            r->a = ((RAM8(0x0001 + (uint16_t)(sp0 - 9)) & 0xFC) << 8) | (uint8_t)(((uint16_t)(value114 + 0x7F) & 0xFF80) >> 7);
            r->x = value115;
            r->y = y_ret;
            r->c = ((uint16_t)(value114 + 0x7F) & 0xFF80) >> 6 & 0x01;
            r->z = (uint8_t)(((uint16_t)(value114 + 0x7F) & 0xFF80) >> 7) == 0;
            r->n = (uint8_t)(((uint16_t)(value114 + 0x7F) & 0xFF80) >> 7) & 0x80;
            r->v = ((value114 ^ (uint16_t)(value114 + 0x7F)) & ((uint16_t)(value114 + 0x7F) ^ 0x7F) & 0x8000) != 0;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8106, 0x7ED5F3); GUARD_JSR(c, sp_call, 0x8106); } /* allocate_vram_pages */
            r->sp += 10;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret73 = r->xf;
            uint16_t a_all40 = r->a;
            if (x_ret73) {
                uint8_t value117 = RAM8(0x0004 + (uint16_t)(sp0 - 9));
                RAM8(0x10000 + value117) = (uint8_t)a_all40;
                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)a_all40 >> 2;
                uint8_t value118 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
                bool x_flag28;
                uint8_t a_hi32;
                uint16_t x28;
                uint16_t y28;
                bool carry28;
                bool zero28;
                bool negative28;
                bool overflow28;
                uint8_t data_bank28;
                uint16_t direct_page28;
                if ((value118 & 0xFC) == 0x80) {
                    uint8_t value119 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                    RAM8(0x0006 + (uint16_t)(sp0 - 9)) = value119 >> 1;
                    r->a = (a_all40 >> 8 << 8) | 1;
                    r->x = value117;
                    r->y = (uint8_t)y_ret;
                    r->c = value119 & 0x01;
                    r->z = 0;
                    r->n = 0;
                    r->xf = 1;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8181, 0x7EC030); GUARD_JSR(c, sp_call, 0x8181); } /* allocate_ppu_register_entry */
                    r->sp += 10;
                    uint16_t dp_ret31 = r->dp;
                    uint8_t db_ret31 = r->db;
                    if (r->mf != 1) { c->fail = 3; return; }
                    bool x_ret75 = r->xf;
                    uint16_t a_all41 = r->a;
                    uint16_t x_ret76 = r->x;
                    uint16_t y_ret32 = r->y;
                    bool carry_ret41 = r->c;
                    bool overflow_ret41 = r->v;
                    uint8_t value120 = BUS8_RDP(c, (db_ret31 << 0x10) + 2 + x_ret76);
                    uint8_t value121 = BUS8_RDP(c, (uint16_t)(dp_ret31 + 6));
                    BUS8_SET(c, (db_ret31 << 0x10) + 2 + x_ret76, (value120 & 0xF8) | value121);
                    x_flag28 = x_ret75;
                    a_hi32 = a_all41 >> 8;
                    x28 = x_ret76;
                    y28 = y_ret32;
                    carry28 = carry_ret41;
                    zero28 = ((value120 & 0xF8) | value121) == 0;
                    negative28 = ((value120 & 0xF8) | value121) & 0x80;
                    overflow28 = overflow_ret41;
                    data_bank28 = db_ret31;
                    direct_page28 = dp_ret31;
                } else {
                    bool x_flag27;
                    uint8_t a_hi31;
                    uint16_t x27;
                    uint16_t y27;
                    bool carry27;
                    bool zero27;
                    bool negative27;
                    bool overflow27;
                    uint8_t data_bank27;
                    uint16_t direct_page27;
                    if ((value118 & 0xFC) == 0x40) {
                        r->a = (a_all40 >> 8 << 8) | 0x0B;
                        r->x = value117;
                        r->y = (uint8_t)y_ret;
                        r->c = (value118 & 0xFC) >= 0x40;
                        r->z = 0;
                        r->n = 0;
                        r->xf = 1;
                        r->sp -= 10;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x816B, 0x7EC030); GUARD_JSR(c, sp_call, 0x816B); } /* allocate_ppu_register_entry */
                        r->sp += 10;
                        uint16_t dp_ret32 = r->dp;
                        uint8_t db_ret32 = r->db;
                        if (r->mf != 1) { c->fail = 3; return; }
                        bool x_ret77 = r->xf;
                        uint16_t a_all42 = r->a;
                        uint16_t x_ret78 = r->x;
                        uint16_t y_ret33 = r->y;
                        bool carry_ret42 = r->c;
                        bool overflow_ret42 = r->v;
                        uint8_t value122 = BUS8_RDP(c, (db_ret32 << 0x10) + 2 + x_ret78);
                        uint8_t value123 = BUS8_RDP(c, (uint16_t)(dp_ret32 + 6));
                        BUS8_SET(c, (db_ret32 << 0x10) + 2 + x_ret78, (value122 & 0xF0) | value123);
                        x_flag27 = x_ret77;
                        a_hi31 = a_all42 >> 8;
                        x27 = x_ret78;
                        y27 = y_ret33;
                        carry27 = carry_ret42;
                        zero27 = ((value122 & 0xF0) | value123) == 0;
                        negative27 = ((value122 & 0xF0) | value123) & 0x80;
                        overflow27 = overflow_ret42;
                        data_bank27 = db_ret32;
                        direct_page27 = dp_ret32;
                    } else {
                        bool x_flag26;
                        uint8_t a_hi30;
                        uint16_t x26;
                        uint16_t y26;
                        bool carry26;
                        bool zero26;
                        bool negative26;
                        bool overflow26;
                        uint8_t data_bank26;
                        uint16_t direct_page26;
                        if ((value118 & 0xFC) == 0x44) {
                            uint8_t value124 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value124 << 4);
                            r->a = (a_all40 >> 8 << 8) | 0x0B;
                            r->x = value117;
                            r->y = (uint8_t)y_ret;
                            r->c = (uint8_t)(value124 << 3) & 0x80;
                            r->z = 0;
                            r->n = 0;
                            r->xf = 1;
                            r->sp -= 10;
                            { const uint16_t sp_call = r->sp; JSR(c, 0x815A, 0x7EC030); GUARD_JSR(c, sp_call, 0x815A); } /* allocate_ppu_register_entry */
                            r->sp += 10;
                            uint16_t dp_ret33 = r->dp;
                            uint8_t db_ret33 = r->db;
                            if (r->mf != 1) { c->fail = 3; return; }
                            bool x_ret79 = r->xf;
                            uint16_t a_all43 = r->a;
                            uint16_t x_ret80 = r->x;
                            uint16_t y_ret34 = r->y;
                            bool carry_ret43 = r->c;
                            bool overflow_ret43 = r->v;
                            uint8_t value125 = BUS8_RDP(c, (db_ret33 << 0x10) + 2 + x_ret80);
                            uint8_t value126 = BUS8_RDP(c, (uint16_t)(dp_ret33 + 6));
                            BUS8_SET(c, (db_ret33 << 0x10) + 2 + x_ret80, (value125 & 0x0F) | value126);
                            x_flag26 = x_ret79;
                            a_hi30 = a_all43 >> 8;
                            x26 = x_ret80;
                            y26 = y_ret34;
                            carry26 = carry_ret43;
                            zero26 = ((value125 & 0x0F) | value126) == 0;
                            negative26 = ((value125 & 0x0F) | value126) & 0x80;
                            overflow26 = overflow_ret43;
                            data_bank26 = db_ret33;
                            direct_page26 = dp_ret33;
                        } else {
                            bool x_flag25;
                            uint8_t a_hi29;
                            uint16_t x25;
                            uint16_t y25;
                            bool carry25;
                            bool zero25;
                            bool negative25;
                            bool overflow25;
                            uint8_t data_bank25;
                            uint16_t direct_page25;
                            if ((value118 & 0xFC) == 0x48) {
                                r->a = (a_all40 >> 8 << 8) | 0x0C;
                                r->x = value117;
                                r->y = (uint8_t)y_ret;
                                r->c = (value118 & 0xFC) >= 0x48;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 1;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8141, 0x7EC030); GUARD_JSR(c, sp_call, 0x8141); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret34 = r->dp;
                                uint8_t db_ret34 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret81 = r->xf;
                                uint16_t a_all44 = r->a;
                                uint16_t x_ret82 = r->x;
                                uint16_t y_ret35 = r->y;
                                bool carry_ret44 = r->c;
                                bool overflow_ret44 = r->v;
                                uint8_t value127 = BUS8_RDP(c, (db_ret34 << 0x10) + 2 + x_ret82);
                                uint8_t value128 = BUS8_RDP(c, (uint16_t)(dp_ret34 + 6));
                                BUS8_SET(c, (db_ret34 << 0x10) + 2 + x_ret82, (value127 & 0xF0) | value128);
                                x_flag25 = x_ret81;
                                a_hi29 = a_all44 >> 8;
                                x25 = x_ret82;
                                y25 = y_ret35;
                                carry25 = carry_ret44;
                                zero25 = ((value127 & 0xF0) | value128) == 0;
                                negative25 = ((value127 & 0xF0) | value128) & 0x80;
                                overflow25 = overflow_ret44;
                                data_bank25 = db_ret34;
                                direct_page25 = dp_ret34;
                            } else {
                                uint8_t value129 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value129 << 4);
                                r->a = (a_all40 >> 8 << 8) | 0x0C;
                                r->x = value117;
                                r->y = (uint8_t)y_ret;
                                r->c = (uint8_t)(value129 << 3) & 0x80;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 1;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8130, 0x7EC030); GUARD_JSR(c, sp_call, 0x8130); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret35 = r->dp;
                                uint8_t db_ret35 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret83 = r->xf;
                                uint16_t a_all45 = r->a;
                                uint16_t x_ret84 = r->x;
                                uint16_t y_ret36 = r->y;
                                bool carry_ret45 = r->c;
                                bool overflow_ret45 = r->v;
                                uint8_t value130 = BUS8_RDP(c, (db_ret35 << 0x10) + 2 + x_ret84);
                                uint8_t value131 = BUS8_RDP(c, (uint16_t)(dp_ret35 + 6));
                                BUS8_SET(c, (db_ret35 << 0x10) + 2 + x_ret84, (value130 & 0x0F) | value131);
                                x_flag25 = x_ret83;
                                a_hi29 = a_all45 >> 8;
                                x25 = x_ret84;
                                y25 = y_ret36;
                                carry25 = carry_ret45;
                                zero25 = ((value130 & 0x0F) | value131) == 0;
                                negative25 = ((value130 & 0x0F) | value131) & 0x80;
                                overflow25 = overflow_ret45;
                                data_bank25 = db_ret35;
                                direct_page25 = dp_ret35;
                            }
                            x_flag26 = x_flag25;
                            a_hi30 = a_hi29;
                            x26 = x25;
                            y26 = y25;
                            carry26 = carry25;
                            zero26 = zero25;
                            negative26 = negative25;
                            overflow26 = overflow25;
                            data_bank26 = data_bank25;
                            direct_page26 = direct_page25;
                        }
                        x_flag27 = x_flag26;
                        a_hi31 = a_hi30;
                        x27 = x26;
                        y27 = y26;
                        carry27 = carry26;
                        zero27 = zero26;
                        negative27 = negative26;
                        overflow27 = overflow26;
                        data_bank27 = data_bank26;
                        direct_page27 = direct_page26;
                    }
                    x_flag28 = x_flag27;
                    a_hi32 = a_hi31;
                    x28 = x27;
                    y28 = y27;
                    carry28 = carry27;
                    zero28 = zero27;
                    negative28 = negative27;
                    overflow28 = overflow27;
                    data_bank28 = data_bank27;
                    direct_page28 = direct_page27;
                }
                if (x_flag28) {
                    a_hi_818c = a_hi32;
                    x_818c = (uint8_t)x28;
                    y_818c = (uint8_t)y28;
                    carry_818c = carry28;
                    zero_818c = zero28;
                    negative_818c = negative28;
                    overflow_818c = overflow28;
                    direct_page_818c = direct_page28;
                    data_bank_818c = data_bank28;
                    goto shared_818C;
                } else {
                    a_hi_818c2 = a_hi32;
                    x_818c2 = x28;
                    y_818c2 = y28;
                    carry_818c2 = carry28;
                    zero_818c2 = zero28;
                    negative_818c2 = negative28;
                    overflow_818c2 = overflow28;
                    direct_page_818c2 = direct_page28;
                    data_bank_818c2 = data_bank28;
                    goto shared_818C_1;
                }
            } else {
                uint16_t value132 = RAM16(0x0004 + (uint16_t)(sp0 - 9));
                RAM8(0x10000 + value132) = (uint8_t)a_all40;
                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)a_all40 >> 2;
                uint8_t value133 = RAM8(0x0001 + (uint16_t)(sp0 - 9));
                bool x_flag32;
                uint8_t a_hi36;
                uint16_t x32;
                uint16_t y32;
                bool carry32;
                bool zero32;
                bool negative32;
                bool overflow32;
                uint8_t data_bank32;
                uint16_t direct_page32;
                if ((value133 & 0xFC) == 0x80) {
                    uint8_t value134 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                    RAM8(0x0006 + (uint16_t)(sp0 - 9)) = value134 >> 1;
                    r->a = (a_all40 >> 8 << 8) | 1;
                    r->x = value132;
                    r->c = value134 & 0x01;
                    r->z = 0;
                    r->n = 0;
                    r->xf = 0;
                    r->sp -= 10;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8181, 0x7EC030); GUARD_JSR(c, sp_call, 0x8181); } /* allocate_ppu_register_entry */
                    r->sp += 10;
                    uint16_t dp_ret36 = r->dp;
                    uint8_t db_ret36 = r->db;
                    if (r->mf != 1) { c->fail = 3; return; }
                    bool x_ret85 = r->xf;
                    uint16_t a_all46 = r->a;
                    uint16_t x_ret86 = r->x;
                    uint16_t y_ret37 = r->y;
                    bool carry_ret46 = r->c;
                    bool overflow_ret46 = r->v;
                    uint8_t value135 = BUS8_RDP(c, (db_ret36 << 0x10) + 2 + x_ret86);
                    uint8_t value136 = BUS8_RDP(c, (uint16_t)(dp_ret36 + 6));
                    BUS8_SET(c, (db_ret36 << 0x10) + 2 + x_ret86, (value135 & 0xF8) | value136);
                    x_flag32 = x_ret85;
                    a_hi36 = a_all46 >> 8;
                    x32 = x_ret86;
                    y32 = y_ret37;
                    carry32 = carry_ret46;
                    zero32 = ((value135 & 0xF8) | value136) == 0;
                    negative32 = ((value135 & 0xF8) | value136) & 0x80;
                    overflow32 = overflow_ret46;
                    data_bank32 = db_ret36;
                    direct_page32 = dp_ret36;
                } else {
                    bool x_flag31;
                    uint8_t a_hi35;
                    uint16_t x31;
                    uint16_t y31;
                    bool carry31;
                    bool zero31;
                    bool negative31;
                    bool overflow31;
                    uint8_t data_bank31;
                    uint16_t direct_page31;
                    if ((value133 & 0xFC) == 0x40) {
                        r->a = (a_all40 >> 8 << 8) | 0x0B;
                        r->x = value132;
                        r->c = (value133 & 0xFC) >= 0x40;
                        r->z = 0;
                        r->n = 0;
                        r->xf = 0;
                        r->sp -= 10;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x816B, 0x7EC030); GUARD_JSR(c, sp_call, 0x816B); } /* allocate_ppu_register_entry */
                        r->sp += 10;
                        uint16_t dp_ret37 = r->dp;
                        uint8_t db_ret37 = r->db;
                        if (r->mf != 1) { c->fail = 3; return; }
                        bool x_ret87 = r->xf;
                        uint16_t a_all47 = r->a;
                        uint16_t x_ret88 = r->x;
                        uint16_t y_ret38 = r->y;
                        bool carry_ret47 = r->c;
                        bool overflow_ret47 = r->v;
                        uint8_t value137 = BUS8_RDP(c, (db_ret37 << 0x10) + 2 + x_ret88);
                        uint8_t value138 = BUS8_RDP(c, (uint16_t)(dp_ret37 + 6));
                        BUS8_SET(c, (db_ret37 << 0x10) + 2 + x_ret88, (value137 & 0xF0) | value138);
                        x_flag31 = x_ret87;
                        a_hi35 = a_all47 >> 8;
                        x31 = x_ret88;
                        y31 = y_ret38;
                        carry31 = carry_ret47;
                        zero31 = ((value137 & 0xF0) | value138) == 0;
                        negative31 = ((value137 & 0xF0) | value138) & 0x80;
                        overflow31 = overflow_ret47;
                        data_bank31 = db_ret37;
                        direct_page31 = dp_ret37;
                    } else {
                        bool x_flag30;
                        uint8_t a_hi34;
                        uint16_t x30;
                        uint16_t y30;
                        bool carry30;
                        bool zero30;
                        bool negative30;
                        bool overflow30;
                        uint8_t data_bank30;
                        uint16_t direct_page30;
                        if ((value133 & 0xFC) == 0x44) {
                            uint8_t value139 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                            RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value139 << 4);
                            r->a = (a_all40 >> 8 << 8) | 0x0B;
                            r->x = value132;
                            r->c = (uint8_t)(value139 << 3) & 0x80;
                            r->z = 0;
                            r->n = 0;
                            r->xf = 0;
                            r->sp -= 10;
                            { const uint16_t sp_call = r->sp; JSR(c, 0x815A, 0x7EC030); GUARD_JSR(c, sp_call, 0x815A); } /* allocate_ppu_register_entry */
                            r->sp += 10;
                            uint16_t dp_ret38 = r->dp;
                            uint8_t db_ret38 = r->db;
                            if (r->mf != 1) { c->fail = 3; return; }
                            bool x_ret89 = r->xf;
                            uint16_t a_all48 = r->a;
                            uint16_t x_ret90 = r->x;
                            uint16_t y_ret39 = r->y;
                            bool carry_ret48 = r->c;
                            bool overflow_ret48 = r->v;
                            uint8_t value140 = BUS8_RDP(c, (db_ret38 << 0x10) + 2 + x_ret90);
                            uint8_t value141 = BUS8_RDP(c, (uint16_t)(dp_ret38 + 6));
                            BUS8_SET(c, (db_ret38 << 0x10) + 2 + x_ret90, (value140 & 0x0F) | value141);
                            x_flag30 = x_ret89;
                            a_hi34 = a_all48 >> 8;
                            x30 = x_ret90;
                            y30 = y_ret39;
                            carry30 = carry_ret48;
                            zero30 = ((value140 & 0x0F) | value141) == 0;
                            negative30 = ((value140 & 0x0F) | value141) & 0x80;
                            overflow30 = overflow_ret48;
                            data_bank30 = db_ret38;
                            direct_page30 = dp_ret38;
                        } else {
                            bool x_flag29;
                            uint8_t a_hi33;
                            uint16_t x29;
                            uint16_t y29;
                            bool carry29;
                            bool zero29;
                            bool negative29;
                            bool overflow29;
                            uint8_t data_bank29;
                            uint16_t direct_page29;
                            if ((value133 & 0xFC) == 0x48) {
                                r->a = (a_all40 >> 8 << 8) | 0x0C;
                                r->x = value132;
                                r->c = (value133 & 0xFC) >= 0x48;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 0;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8141, 0x7EC030); GUARD_JSR(c, sp_call, 0x8141); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret39 = r->dp;
                                uint8_t db_ret39 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret91 = r->xf;
                                uint16_t a_all49 = r->a;
                                uint16_t x_ret92 = r->x;
                                uint16_t y_ret40 = r->y;
                                bool carry_ret49 = r->c;
                                bool overflow_ret49 = r->v;
                                uint8_t value142 = BUS8_RDP(c, (db_ret39 << 0x10) + 2 + x_ret92);
                                uint8_t value143 = BUS8_RDP(c, (uint16_t)(dp_ret39 + 6));
                                BUS8_SET(c, (db_ret39 << 0x10) + 2 + x_ret92, (value142 & 0xF0) | value143);
                                x_flag29 = x_ret91;
                                a_hi33 = a_all49 >> 8;
                                x29 = x_ret92;
                                y29 = y_ret40;
                                carry29 = carry_ret49;
                                zero29 = ((value142 & 0xF0) | value143) == 0;
                                negative29 = ((value142 & 0xF0) | value143) & 0x80;
                                overflow29 = overflow_ret49;
                                data_bank29 = db_ret39;
                                direct_page29 = dp_ret39;
                            } else {
                                uint8_t value144 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                                RAM8(0x0006 + (uint16_t)(sp0 - 9)) = (uint8_t)(value144 << 4);
                                r->a = (a_all40 >> 8 << 8) | 0x0C;
                                r->x = value132;
                                r->c = (uint8_t)(value144 << 3) & 0x80;
                                r->z = 0;
                                r->n = 0;
                                r->xf = 0;
                                r->sp -= 10;
                                { const uint16_t sp_call = r->sp; JSR(c, 0x8130, 0x7EC030); GUARD_JSR(c, sp_call, 0x8130); } /* allocate_ppu_register_entry */
                                r->sp += 10;
                                uint16_t dp_ret40 = r->dp;
                                uint8_t db_ret40 = r->db;
                                if (r->mf != 1) { c->fail = 3; return; }
                                bool x_ret93 = r->xf;
                                uint16_t a_all50 = r->a;
                                uint16_t x_ret94 = r->x;
                                uint16_t y_ret41 = r->y;
                                bool carry_ret50 = r->c;
                                bool overflow_ret50 = r->v;
                                uint8_t value145 = BUS8_RDP(c, (db_ret40 << 0x10) + 2 + x_ret94);
                                uint8_t value146 = BUS8_RDP(c, (uint16_t)(dp_ret40 + 6));
                                BUS8_SET(c, (db_ret40 << 0x10) + 2 + x_ret94, (value145 & 0x0F) | value146);
                                x_flag29 = x_ret93;
                                a_hi33 = a_all50 >> 8;
                                x29 = x_ret94;
                                y29 = y_ret41;
                                carry29 = carry_ret50;
                                zero29 = ((value145 & 0x0F) | value146) == 0;
                                negative29 = ((value145 & 0x0F) | value146) & 0x80;
                                overflow29 = overflow_ret50;
                                data_bank29 = db_ret40;
                                direct_page29 = dp_ret40;
                            }
                            x_flag30 = x_flag29;
                            a_hi34 = a_hi33;
                            x30 = x29;
                            y30 = y29;
                            carry30 = carry29;
                            zero30 = zero29;
                            negative30 = negative29;
                            overflow30 = overflow29;
                            data_bank30 = data_bank29;
                            direct_page30 = direct_page29;
                        }
                        x_flag31 = x_flag30;
                        a_hi35 = a_hi34;
                        x31 = x30;
                        y31 = y30;
                        carry31 = carry30;
                        zero31 = zero30;
                        negative31 = negative30;
                        overflow31 = overflow30;
                        data_bank31 = data_bank30;
                        direct_page31 = direct_page30;
                    }
                    x_flag32 = x_flag31;
                    a_hi36 = a_hi35;
                    x32 = x31;
                    y32 = y31;
                    carry32 = carry31;
                    zero32 = zero31;
                    negative32 = negative31;
                    overflow32 = overflow31;
                    data_bank32 = data_bank31;
                    direct_page32 = direct_page31;
                }
                if (x_flag32) {
                    a_hi_818c = a_hi36;
                    x_818c = (uint8_t)x32;
                    y_818c = (uint8_t)y32;
                    carry_818c = carry32;
                    zero_818c = zero32;
                    negative_818c = negative32;
                    overflow_818c = overflow32;
                    direct_page_818c = direct_page32;
                    data_bank_818c = data_bank32;
                    goto shared_818C;
                } else {
                    a_hi_818c2 = a_hi36;
                    x_818c2 = x32;
                    y_818c2 = y32;
                    carry_818c2 = carry32;
                    zero_818c2 = zero32;
                    negative_818c2 = negative32;
                    overflow_818c2 = overflow32;
                    direct_page_818c2 = direct_page32;
                    data_bank_818c2 = data_bank32;
                    goto shared_818C_1;
                }
            }
        }
    }
    shared_818C:;
    r->x = x_818c;
    r->y = y_818c;
    r->c = carry_818c;
    r->z = zero_818c;
    r->n = negative_818c;
    r->v = overflow_818c;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_818c;
    r->dp = direct_page_818c;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x818E, 0x7EC097); GUARD_JSR(c, sp_call, 0x818E); } /* append_oneshot_ppu_entry */
    r->sp += 10;
    uint16_t dp_ret41 = r->dp;
    uint8_t db_ret41 = r->db;
    bool m_ret2 = r->mf;
    bool x_ret95 = r->xf;
    uint16_t a_all51 = r->a;
    uint16_t y_ret42 = r->y;
    if (x_ret95) {
        uint8_t value147 = BUS8_RDP(c, (uint16_t)(dp_ret41 + 4));
        if (m_ret2) {
            uint8_t value148 = BUS8_RDP(c, (db_ret41 << 0x10) + value147);
            uint8_t value149 = RAM8(0x0000 + sp0 - 9);
            RAM16_SET(0x0000 + sp0 - 4, (((uint8_t)(value148 << 2) << 8) | (a_all51 >> 8)) & 0xFF00);
            uint8_t value150 = RAM8(0x0000 + sp0 - 4);
            uint8_t value151 = RAM8(0x0000 + sp0 - 3);
            uint8_t value152 = RAM8(0x0000 + sp0 - 2);
            uint8_t value153 = RAM8(0x0000 + sp0 - 1);
            uint8_t value154 = RAM8(0x0000 + sp0);
            r->a = (value151 << 8) | value150;
            r->x = (uint8_t)((((uint8_t)(value148 << 2) << 8) | (a_all51 >> 8)) & 0xFF00);
            r->y = (uint8_t)y_ret42;
            r->c = value152 & 0x01;
            r->v = value152 & 0x40;
            r->mf = value152 & 0x20;
            r->xf = value152 & 0x10;
            r->db = value149;
            r->dp = (value154 << 8) | value153;
            r->i = value152 & 0x04;
            r->d = value152 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value155 = BUS16_RDP(c, (db_ret41 << 0x10) + value147);
            uint8_t value156 = RAM8(0x0000 + sp0 - 9);
            RAM16_SET(0x0000 + sp0 - 4, (((uint8_t)(value155 << 2) << 8) | ((uint16_t)(value155 << 2) >> 8)) & 0xFF00);
            uint8_t value157 = RAM8(0x0000 + sp0 - 4);
            uint8_t value158 = RAM8(0x0000 + sp0 - 3);
            uint8_t value159 = RAM8(0x0000 + sp0 - 2);
            uint8_t value160 = RAM8(0x0000 + sp0 - 1);
            uint8_t value161 = RAM8(0x0000 + sp0);
            r->a = (value158 << 8) | value157;
            r->x = (uint8_t)((((uint8_t)(value155 << 2) << 8) | ((uint16_t)(value155 << 2) >> 8)) & 0xFF00);
            r->y = (uint8_t)y_ret42;
            r->c = value159 & 0x01;
            r->v = value159 & 0x40;
            r->mf = value159 & 0x20;
            r->xf = value159 & 0x10;
            r->db = value156;
            r->dp = (value161 << 8) | value160;
            r->i = value159 & 0x04;
            r->d = value159 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        uint16_t value162 = BUS16_RDP(c, (uint16_t)(dp_ret41 + 4));
        if (m_ret2) {
            uint8_t value163 = BUS8_RDP(c, (db_ret41 << 0x10) + value162);
            uint8_t value164 = RAM8(0x0000 + sp0 - 9);
            RAM16_SET(0x0000 + sp0 - 4, (((uint8_t)(value163 << 2) << 8) | (a_all51 >> 8)) & 0xFF00);
            uint8_t value165 = RAM8(0x0000 + sp0 - 4);
            uint8_t value166 = RAM8(0x0000 + sp0 - 3);
            uint8_t value167 = RAM8(0x0000 + sp0 - 2);
            uint8_t value168 = RAM8(0x0000 + sp0 - 1);
            uint8_t value169 = RAM8(0x0000 + sp0);
            r->a = (value166 << 8) | value165;
            r->x = (((uint8_t)(value163 << 2) << 8) | (a_all51 >> 8)) & 0xFF00;
            r->c = value167 & 0x01;
            r->v = value167 & 0x40;
            r->mf = value167 & 0x20;
            r->xf = value167 & 0x10;
            r->db = value164;
            r->dp = (value169 << 8) | value168;
            r->i = value167 & 0x04;
            r->d = value167 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value170 = BUS16_RDP(c, (db_ret41 << 0x10) + value162);
            uint8_t value171 = RAM8(0x0000 + sp0 - 9);
            RAM16_SET(0x0000 + sp0 - 4, (((uint8_t)(value170 << 2) << 8) | ((uint16_t)(value170 << 2) >> 8)) & 0xFF00);
            uint8_t value172 = RAM8(0x0000 + sp0 - 4);
            uint8_t value173 = RAM8(0x0000 + sp0 - 3);
            uint8_t value174 = RAM8(0x0000 + sp0 - 2);
            uint8_t value175 = RAM8(0x0000 + sp0 - 1);
            uint8_t value176 = RAM8(0x0000 + sp0);
            r->a = (value173 << 8) | value172;
            r->x = (((uint8_t)(value170 << 2) << 8) | ((uint16_t)(value170 << 2) >> 8)) & 0xFF00;
            r->c = value174 & 0x01;
            r->v = value174 & 0x40;
            r->mf = value174 & 0x20;
            r->xf = value174 & 0x10;
            r->db = value171;
            r->dp = (value176 << 8) | value175;
            r->i = value174 & 0x04;
            r->d = value174 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
    shared_818C_1:;
    r->x = x_818c2;
    r->y = y_818c2;
    r->c = carry_818c2;
    r->z = zero_818c2;
    r->n = negative_818c2;
    r->v = overflow_818c2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_818c2;
    r->dp = direct_page_818c2;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x818E, 0x7EC097); GUARD_JSR(c, sp_call, 0x818E); } /* append_oneshot_ppu_entry */
    r->sp += 10;
    uint16_t dp_ret42 = r->dp;
    uint8_t db_ret42 = r->db;
    bool m_ret3 = r->mf;
    bool x_ret96 = r->xf;
    uint16_t a_all52 = r->a;
    uint16_t y_ret43 = r->y;
    if (x_ret96) {
        uint8_t value177 = BUS8_RDP(c, (uint16_t)(dp_ret42 + 4));
        if (m_ret3) {
            uint8_t value178 = BUS8_RDP(c, (db_ret42 << 0x10) + value177);
            uint8_t value179 = RAM8(0x0000 + sp0 - 9);
            RAM16_SET(0x0000 + sp0 - 4, (((uint8_t)(value178 << 2) << 8) | (a_all52 >> 8)) & 0xFF00);
            uint8_t value180 = RAM8(0x0000 + sp0 - 4);
            uint8_t value181 = RAM8(0x0000 + sp0 - 3);
            uint8_t value182 = RAM8(0x0000 + sp0 - 2);
            uint8_t value183 = RAM8(0x0000 + sp0 - 1);
            uint8_t value184 = RAM8(0x0000 + sp0);
            r->a = (value181 << 8) | value180;
            r->x = (uint8_t)((((uint8_t)(value178 << 2) << 8) | (a_all52 >> 8)) & 0xFF00);
            r->y = (uint8_t)y_ret43;
            r->c = value182 & 0x01;
            r->v = value182 & 0x40;
            r->mf = value182 & 0x20;
            r->xf = value182 & 0x10;
            r->db = value179;
            r->dp = (value184 << 8) | value183;
            r->i = value182 & 0x04;
            r->d = value182 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value185 = BUS16_RDP(c, (db_ret42 << 0x10) + value177);
            uint8_t value186 = RAM8(0x0000 + sp0 - 9);
            RAM16_SET(0x0000 + sp0 - 4, (((uint8_t)(value185 << 2) << 8) | ((uint16_t)(value185 << 2) >> 8)) & 0xFF00);
            uint8_t value187 = RAM8(0x0000 + sp0 - 4);
            uint8_t value188 = RAM8(0x0000 + sp0 - 3);
            uint8_t value189 = RAM8(0x0000 + sp0 - 2);
            uint8_t value190 = RAM8(0x0000 + sp0 - 1);
            uint8_t value191 = RAM8(0x0000 + sp0);
            r->a = (value188 << 8) | value187;
            r->x = (uint8_t)((((uint8_t)(value185 << 2) << 8) | ((uint16_t)(value185 << 2) >> 8)) & 0xFF00);
            r->y = (uint8_t)y_ret43;
            r->c = value189 & 0x01;
            r->v = value189 & 0x40;
            r->mf = value189 & 0x20;
            r->xf = value189 & 0x10;
            r->db = value186;
            r->dp = (value191 << 8) | value190;
            r->i = value189 & 0x04;
            r->d = value189 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        uint16_t value192 = BUS16_RDP(c, (uint16_t)(dp_ret42 + 4));
        if (m_ret3) {
            uint8_t value193 = BUS8_RDP(c, (db_ret42 << 0x10) + value192);
            uint8_t value194 = RAM8(0x0000 + sp0 - 9);
            RAM16_SET(0x0000 + sp0 - 4, (((uint8_t)(value193 << 2) << 8) | (a_all52 >> 8)) & 0xFF00);
            uint8_t value195 = RAM8(0x0000 + sp0 - 4);
            uint8_t value196 = RAM8(0x0000 + sp0 - 3);
            uint8_t value197 = RAM8(0x0000 + sp0 - 2);
            uint8_t value198 = RAM8(0x0000 + sp0 - 1);
            uint8_t value199 = RAM8(0x0000 + sp0);
            r->a = (value196 << 8) | value195;
            r->x = (((uint8_t)(value193 << 2) << 8) | (a_all52 >> 8)) & 0xFF00;
            r->c = value197 & 0x01;
            r->v = value197 & 0x40;
            r->mf = value197 & 0x20;
            r->xf = value197 & 0x10;
            r->db = value194;
            r->dp = (value199 << 8) | value198;
            r->i = value197 & 0x04;
            r->d = value197 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value200 = BUS16_RDP(c, (db_ret42 << 0x10) + value192);
            uint8_t value201 = RAM8(0x0000 + sp0 - 9);
            RAM16_SET(0x0000 + sp0 - 4, (((uint8_t)(value200 << 2) << 8) | ((uint16_t)(value200 << 2) >> 8)) & 0xFF00);
            uint8_t value202 = RAM8(0x0000 + sp0 - 4);
            uint8_t value203 = RAM8(0x0000 + sp0 - 3);
            uint8_t value204 = RAM8(0x0000 + sp0 - 2);
            uint8_t value205 = RAM8(0x0000 + sp0 - 1);
            uint8_t value206 = RAM8(0x0000 + sp0);
            r->a = (value203 << 8) | value202;
            r->x = (((uint8_t)(value200 << 2) << 8) | ((uint16_t)(value200 << 2) >> 8)) & 0xFF00;
            r->c = value204 & 0x01;
            r->v = value204 & 0x40;
            r->mf = value204 & 0x20;
            r->xf = value204 & 0x10;
            r->db = value201;
            r->dp = (value206 << 8) | value205;
            r->i = value204 & 0x04;
            r->d = value204 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0x7E809B, SOM_RTS, "gen", create_graphics_buffer, 0, L_B | L_X | L_Y | L_C | L_V, 12, -1, 0, 271, 144)
