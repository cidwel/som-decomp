#include "som_c.h"

/* 7EA6FF update_controller_states_and_messages   [class B, 277 bytes, 126 instructions]
 * Source: src/boot/update_controller_states_and_messages.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: BXYCZNV.
 */
static void update_controller_states_and_messages(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 0x0D) = 0x7F;
    RAM8(0x0000 + sp0 - 0x0E) = 0x7F;
    uint16_t value = RAM16(0x10090);
    if ((value & 1) != 0) {
        r->a = value & 1;
        r->c = (uint16_t)(sp0 - 3) >= 0x0A;
        r->z = (value & 1) == 0;
        r->n = value & 1 & 0x8000;
        r->v = (((uint16_t)(sp0 - 3) ^ 0x0A) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0D)) & 0x8000) != 0;
        r->mf = 0;
        r->dp = (uint16_t)(sp0 - 0x0D);
        r->sp -= 14;
        { const uint16_t sp_call = r->sp; JSR(c, 0xA720, 0x7EA4E9); GUARD_JSR(c, sp_call, 0xA720); } /* detect_controller_interface */
        r->sp += 14;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        RAM16_SET(0x0001 + dp_ret, 5);
        uint16_t value2 = BUS16_RDP(c, (db_ret << 0x10) + 0x92);
        uint8_t a1 = 5;
        uint8_t a_hi1 = 0;
        uint16_t x1 = 0;
        uint16_t y1 = value2;
        bool carry1 = carry_ret;
        bool zero1 = value2 == 0;
        bool negative1 = value2 & 0x8000;
        bool overflow1 = overflow_ret;
        uint8_t data_bank = db_ret;
        uint16_t direct_page = dp_ret;
        for (;;) {
            RAM16_SET(0x0007 + direct_page, x1);
            RAM16_SET(0x0009 + direct_page, y1);
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
            r->sp -= 14;
            { const uint16_t sp_call = r->sp; JSR(c, 0xA732, 0x7EA6B7); GUARD_JSR(c, sp_call, 0xA732); } /* select_input_interface_reader */
            r->sp += 14;
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all2 = r->a;
            uint16_t y_ret2 = r->y;
            if (a_all2 == 0x3030) {
                uint16_t value3 = BUS16(c, 0x00FFFC);
                RAM8(0x0000 + sp0 - 0x0E) = 0;
                r->a = (uint16_t)(value3 - 1);
                r->c = a_all2 >= 0x3030;
                r->z = (uint16_t)(value3 - 1) == 0;
                r->n = (uint16_t)(value3 - 1) & 0x8000;
                TAIL_CALL_FRAME(c, (0 << 16) | (uint16_t)((uint16_t)(value3 - 1) + 1), SOM_RTS, 15); /* jump through a pushed address */
            }
            if ((a_all2 & 0x0F) == 0) {
                RAM16_SET(0x0005 + dp_ret2, a_all2);
                RAM16_SET(0x0003 + dp_ret2, a_all2 ^ 0xFFF0);
                uint16_t value4 = BUS16_RDP(c, (db_ret2 << 0x10) + 2 + y_ret2);
                uint16_t value5 = RAM16(0x0005 + dp_ret2);
                BUS16_SET(c, (db_ret2 << 0x10) + 4 + y_ret2, (value4 ^ value5) & value5);
                uint16_t value6 = BUS16_RDP(c, (db_ret2 << 0x10) + 8 + y_ret2);
                if (((value4 ^ value5) & value5 & value6) == 0) {
                    uint16_t value7 = BUS16_RDP(c, (db_ret2 << 0x10) + 2 + y_ret2);
                    uint16_t value8 = RAM16(0x0005 + dp_ret2);
                    uint16_t value9 = RAM16(0x0003 + dp_ret2);
                    BUS16_SET(c, (db_ret2 << 0x10) + 6 + y_ret2, (value7 ^ value8) & value9);
                    uint16_t value10 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x0A + y_ret2);
                    bool m_flag2;
                    uint8_t a_hi3;
                    uint16_t y3;
                    uint8_t data_bank3;
                    uint16_t direct_page3;
                    if (((value7 ^ value8) & value9 & value10) == 0) {
                        m_flag2 = 0;
                        a_hi3 = ((value7 ^ value8) & value9 & value10) >> 8;
                        y3 = y_ret2;
                        data_bank3 = db_ret2;
                        direct_page3 = dp_ret2;
                    } else {
                        uint16_t value11 = BUS16_RDP(c, (db_ret2 << 0x10) + 1 + y_ret2);
                        bool m_flag;
                        uint8_t a_hi2;
                        uint16_t y2;
                        uint8_t data_bank2;
                        uint16_t direct_page2;
                        if ((value11 & 0xFF) < 2) {
                            m_flag = 0;
                            a_hi2 = 0;
                            y2 = y_ret2;
                            data_bank2 = db_ret2;
                            direct_page2 = dp_ret2;
                        } else {
                            r->c = (value11 & 0xFF) >= 2;
                            r->z = (value11 & 0xFF) == 2;
                            r->n = (uint16_t)((value11 & 0xFF) - 2) & 0x8000;
                            r->sp -= 14;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xA7B4, 0x7EB1A9); GUARD_JSR(c, sp_call, 0xA7B4); } /* allocate_eight_byte_record */
                            r->sp += 14;
                            uint16_t dp_ret3 = r->dp;
                            uint8_t db_ret3 = r->db;
                            if (r->xf != 0) { c->fail = 3; return; }
                            uint16_t x_ret3 = r->x;
                            BUS8_SET(c, (db_ret3 << 0x10) + 2 + x_ret3, 0xFE);
                            BUS8_SET(c, (db_ret3 << 0x10) + 4 + x_ret3, 2);
                            uint8_t value12 = RAM8(0x0001 + dp_ret3);
                            BUS8_SET(c, (db_ret3 << 0x10) + 5 + x_ret3, (uint8_t)(5 - value12));
                            uint16_t value13 = RAM16(0x0009 + dp_ret3);
                            uint16_t value14 = BUS16_RDP(c, (db_ret3 << 0x10) + 6 + value13);
                            uint16_t value15 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0A + value13);
                            BUS16_SET(c, (db_ret3 << 0x10) + 6 + x_ret3, value14 & value15);
                            uint16_t value16 = BUS16_RDP(c, (db_ret3 << 0x10) + 1 + value13);
                            r->a = value16;
                            r->y = value13;
                            r->c = value12 <= 5;
                            r->z = value16 == 0;
                            r->n = value16 & 0x8000;
                            r->v = ((value12 ^ 5) & ((uint8_t)(5 - value12) ^ 5) & 0x80) != 0;
                            r->mf = 0;
                            r->sp -= 14;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xA7DB, 0x7EB258); GUARD_JSR(c, sp_call, 0xA7DB); } /* append_pending_record */
                            r->sp += 14;
                            uint16_t dp_ret4 = r->dp;
                            uint8_t db_ret4 = r->db;
                            bool m_ret2 = r->mf;
                            if (r->xf != 0) { c->fail = 3; return; }
                            uint16_t a_all4 = r->a;
                            uint16_t value17 = RAM16(0x0009 + dp_ret4);
                            m_flag = m_ret2;
                            a_hi2 = a_all4 >> 8;
                            y2 = value17;
                            data_bank2 = db_ret4;
                            direct_page2 = dp_ret4;
                        }
                        m_flag2 = m_flag;
                        a_hi3 = a_hi2;
                        y3 = y2;
                        data_bank3 = data_bank2;
                        direct_page3 = direct_page2;
                    }
                    BUS8_SET(c, (data_bank3 << 0x10) + y3, 1);
                    BUS16_SET(c, (data_bank3 << 0x10) + 2 + y3, RAM16(0x0005 + direct_page3));
                    uint16_t value19 = RAM16(0x0007 + direct_page3);
                    RAM16_SET(0x0001 + direct_page3, (uint16_t)(RAM16(0x0001 + direct_page3) - 1));
                    if (RAM16(0x0001 + direct_page3) == 0) {
                        a1 = (uint8_t)(y3 + 0x10);
                        a_hi1 = (uint16_t)(y3 + 0x10) >> 8;
                        x1 = (uint16_t)(value19 + 2);
                        y1 = (uint16_t)(y3 + 0x10);
                        carry1 = y3 + 0x10 > 0xFFFF;
                        zero1 = RAM16(0x0001 + direct_page3) == 0;
                        negative1 = RAM16(0x0001 + direct_page3) & 0x8000;
                        overflow1 = ((y3 ^ (uint16_t)(y3 + 0x10)) & ((uint16_t)(y3 + 0x10) ^ 0x10) & 0x8000) != 0;
                        data_bank = data_bank3;
                        direct_page = direct_page3;
                        break;
                    }
                    a1 = (uint8_t)(y3 + 0x10);
                    a_hi1 = (uint16_t)(y3 + 0x10) >> 8;
                    x1 = (uint16_t)(value19 + 2);
                    y1 = (uint16_t)(y3 + 0x10);
                    carry1 = y3 + 0x10 > 0xFFFF;
                    zero1 = RAM16(0x0001 + direct_page3) == 0;
                    negative1 = RAM16(0x0001 + direct_page3) & 0x8000;
                    overflow1 = ((y3 ^ (uint16_t)(y3 + 0x10)) & ((uint16_t)(y3 + 0x10) ^ 0x10) & 0x8000) != 0;
                    data_bank = data_bank3;
                    direct_page = direct_page3;
                    continue;
                }
                uint16_t value20 = BUS16_RDP(c, (db_ret2 << 0x10) + 1 + y_ret2);
                if ((value20 & 0xFF) < 2) {
                    uint16_t value21 = BUS16_RDP(c, (db_ret2 << 0x10) + 2 + y_ret2);
                    uint16_t value22 = RAM16(0x0005 + dp_ret2);
                    uint16_t value23 = RAM16(0x0003 + dp_ret2);
                    BUS16_SET(c, (db_ret2 << 0x10) + 6 + y_ret2, (value21 ^ value22) & value23);
                    uint16_t value24 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x0A + y_ret2);
                    bool m_flag4;
                    uint8_t a_hi5;
                    uint16_t y5;
                    uint8_t data_bank5;
                    uint16_t direct_page5;
                    if (((value21 ^ value22) & value23 & value24) == 0) {
                        m_flag4 = 0;
                        a_hi5 = ((value21 ^ value22) & value23 & value24) >> 8;
                        y5 = y_ret2;
                        data_bank5 = db_ret2;
                        direct_page5 = dp_ret2;
                    } else {
                        uint16_t value25 = BUS16_RDP(c, (db_ret2 << 0x10) + 1 + y_ret2);
                        bool m_flag3;
                        uint8_t a_hi4;
                        uint16_t y4;
                        uint8_t data_bank4;
                        uint16_t direct_page4;
                        if ((value25 & 0xFF) < 2) {
                            m_flag3 = 0;
                            a_hi4 = 0;
                            y4 = y_ret2;
                            data_bank4 = db_ret2;
                            direct_page4 = dp_ret2;
                        } else {
                            r->c = (value25 & 0xFF) >= 2;
                            r->z = (value25 & 0xFF) == 2;
                            r->n = (uint16_t)((value25 & 0xFF) - 2) & 0x8000;
                            r->sp -= 14;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xA7B4, 0x7EB1A9); GUARD_JSR(c, sp_call, 0xA7B4); } /* allocate_eight_byte_record */
                            r->sp += 14;
                            uint16_t dp_ret5 = r->dp;
                            uint8_t db_ret5 = r->db;
                            if (r->xf != 0) { c->fail = 3; return; }
                            uint16_t x_ret5 = r->x;
                            BUS8_SET(c, (db_ret5 << 0x10) + 2 + x_ret5, 0xFE);
                            BUS8_SET(c, (db_ret5 << 0x10) + 4 + x_ret5, 2);
                            uint8_t value26 = RAM8(0x0001 + dp_ret5);
                            BUS8_SET(c, (db_ret5 << 0x10) + 5 + x_ret5, (uint8_t)(5 - value26));
                            uint16_t value27 = RAM16(0x0009 + dp_ret5);
                            uint16_t value28 = BUS16_RDP(c, (db_ret5 << 0x10) + 6 + value27);
                            uint16_t value29 = BUS16_RDP(c, (db_ret5 << 0x10) + 0x0A + value27);
                            BUS16_SET(c, (db_ret5 << 0x10) + 6 + x_ret5, value28 & value29);
                            uint16_t value30 = BUS16_RDP(c, (db_ret5 << 0x10) + 1 + value27);
                            r->a = value30;
                            r->y = value27;
                            r->c = value26 <= 5;
                            r->z = value30 == 0;
                            r->n = value30 & 0x8000;
                            r->v = ((value26 ^ 5) & ((uint8_t)(5 - value26) ^ 5) & 0x80) != 0;
                            r->mf = 0;
                            r->sp -= 14;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xA7DB, 0x7EB258); GUARD_JSR(c, sp_call, 0xA7DB); } /* append_pending_record */
                            r->sp += 14;
                            uint16_t dp_ret6 = r->dp;
                            uint8_t db_ret6 = r->db;
                            bool m_ret4 = r->mf;
                            if (r->xf != 0) { c->fail = 3; return; }
                            uint16_t a_all6 = r->a;
                            uint16_t value31 = RAM16(0x0009 + dp_ret6);
                            m_flag3 = m_ret4;
                            a_hi4 = a_all6 >> 8;
                            y4 = value31;
                            data_bank4 = db_ret6;
                            direct_page4 = dp_ret6;
                        }
                        m_flag4 = m_flag3;
                        a_hi5 = a_hi4;
                        y5 = y4;
                        data_bank5 = data_bank4;
                        direct_page5 = direct_page4;
                    }
                    BUS8_SET(c, (data_bank5 << 0x10) + y5, 1);
                    BUS16_SET(c, (data_bank5 << 0x10) + 2 + y5, RAM16(0x0005 + direct_page5));
                    uint16_t value33 = RAM16(0x0007 + direct_page5);
                    RAM16_SET(0x0001 + direct_page5, (uint16_t)(RAM16(0x0001 + direct_page5) - 1));
                    if (RAM16(0x0001 + direct_page5) == 0) {
                        a1 = (uint8_t)(y5 + 0x10);
                        a_hi1 = (uint16_t)(y5 + 0x10) >> 8;
                        x1 = (uint16_t)(value33 + 2);
                        y1 = (uint16_t)(y5 + 0x10);
                        carry1 = y5 + 0x10 > 0xFFFF;
                        zero1 = RAM16(0x0001 + direct_page5) == 0;
                        negative1 = RAM16(0x0001 + direct_page5) & 0x8000;
                        overflow1 = ((y5 ^ (uint16_t)(y5 + 0x10)) & ((uint16_t)(y5 + 0x10) ^ 0x10) & 0x8000) != 0;
                        data_bank = data_bank5;
                        direct_page = direct_page5;
                        break;
                    }
                    a1 = (uint8_t)(y5 + 0x10);
                    a_hi1 = (uint16_t)(y5 + 0x10) >> 8;
                    x1 = (uint16_t)(value33 + 2);
                    y1 = (uint16_t)(y5 + 0x10);
                    carry1 = y5 + 0x10 > 0xFFFF;
                    zero1 = RAM16(0x0001 + direct_page5) == 0;
                    negative1 = RAM16(0x0001 + direct_page5) & 0x8000;
                    overflow1 = ((y5 ^ (uint16_t)(y5 + 0x10)) & ((uint16_t)(y5 + 0x10) ^ 0x10) & 0x8000) != 0;
                    data_bank = data_bank5;
                    direct_page = direct_page5;
                    continue;
                }
                r->c = (value20 & 0xFF) >= 2;
                r->z = (value20 & 0xFF) == 2;
                r->n = (uint16_t)((value20 & 0xFF) - 2) & 0x8000;
                r->sp -= 14;
                { const uint16_t sp_call = r->sp; JSR(c, 0xA76E, 0x7EB1A9); GUARD_JSR(c, sp_call, 0xA76E); } /* allocate_eight_byte_record */
                r->sp += 14;
                uint16_t dp_ret7 = r->dp;
                uint8_t db_ret7 = r->db;
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t x_ret7 = r->x;
                BUS8_SET(c, (db_ret7 << 0x10) + 2 + x_ret7, 0xFE);
                BUS8_SET(c, (db_ret7 << 0x10) + 4 + x_ret7, 1);
                uint8_t value34 = RAM8(0x0001 + dp_ret7);
                BUS8_SET(c, (db_ret7 << 0x10) + 5 + x_ret7, (uint8_t)(5 - value34));
                uint16_t value35 = RAM16(0x0009 + dp_ret7);
                uint16_t value36 = BUS16_RDP(c, (db_ret7 << 0x10) + 4 + value35);
                uint16_t value37 = BUS16_RDP(c, (db_ret7 << 0x10) + 8 + value35);
                BUS16_SET(c, (db_ret7 << 0x10) + 6 + x_ret7, value36 & value37);
                uint16_t value38 = BUS16_RDP(c, (db_ret7 << 0x10) + 1 + value35);
                r->a = value38;
                r->y = value35;
                r->c = value34 <= 5;
                r->z = value38 == 0;
                r->n = value38 & 0x8000;
                r->v = ((value34 ^ 5) & ((uint8_t)(5 - value34) ^ 5) & 0x80) != 0;
                r->mf = 0;
                r->sp -= 14;
                { const uint16_t sp_call = r->sp; JSR(c, 0xA795, 0x7EB258); GUARD_JSR(c, sp_call, 0xA795); } /* append_pending_record */
                r->sp += 14;
                uint16_t dp_ret8 = r->dp;
                uint8_t db_ret8 = r->db;
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t value39 = RAM16(0x0009 + dp_ret8);
                uint16_t value40 = BUS16_RDP(c, (db_ret8 << 0x10) + 2 + value39);
                uint16_t value41 = RAM16(0x0005 + dp_ret8);
                uint16_t value42 = RAM16(0x0003 + dp_ret8);
                BUS16_SET(c, (db_ret8 << 0x10) + 6 + value39, (value40 ^ value41) & value42);
                uint16_t value43 = BUS16_RDP(c, (db_ret8 << 0x10) + 0x0A + value39);
                bool m_flag6;
                uint8_t a_hi7;
                uint16_t y7;
                uint8_t data_bank7;
                uint16_t direct_page7;
                if (((value40 ^ value41) & value42 & value43) == 0) {
                    m_flag6 = 0;
                    a_hi7 = ((value40 ^ value41) & value42 & value43) >> 8;
                    y7 = value39;
                    data_bank7 = db_ret8;
                    direct_page7 = dp_ret8;
                } else {
                    uint16_t value44 = BUS16_RDP(c, (db_ret8 << 0x10) + 1 + value39);
                    bool m_flag5;
                    uint8_t a_hi6;
                    uint16_t y6;
                    uint8_t data_bank6;
                    uint16_t direct_page6;
                    if ((value44 & 0xFF) < 2) {
                        m_flag5 = 0;
                        a_hi6 = 0;
                        y6 = value39;
                        data_bank6 = db_ret8;
                        direct_page6 = dp_ret8;
                    } else {
                        r->y = value39;
                        r->c = (value44 & 0xFF) >= 2;
                        r->z = (value44 & 0xFF) == 2;
                        r->n = (uint16_t)((value44 & 0xFF) - 2) & 0x8000;
                        r->sp -= 14;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xA7B4, 0x7EB1A9); GUARD_JSR(c, sp_call, 0xA7B4); } /* allocate_eight_byte_record */
                        r->sp += 14;
                        uint16_t dp_ret9 = r->dp;
                        uint8_t db_ret9 = r->db;
                        if (r->xf != 0) { c->fail = 3; return; }
                        uint16_t x_ret9 = r->x;
                        BUS8_SET(c, (db_ret9 << 0x10) + 2 + x_ret9, 0xFE);
                        BUS8_SET(c, (db_ret9 << 0x10) + 4 + x_ret9, 2);
                        uint8_t value45 = RAM8(0x0001 + dp_ret9);
                        BUS8_SET(c, (db_ret9 << 0x10) + 5 + x_ret9, (uint8_t)(5 - value45));
                        uint16_t value46 = RAM16(0x0009 + dp_ret9);
                        uint16_t value47 = BUS16_RDP(c, (db_ret9 << 0x10) + 6 + value46);
                        uint16_t value48 = BUS16_RDP(c, (db_ret9 << 0x10) + 0x0A + value46);
                        BUS16_SET(c, (db_ret9 << 0x10) + 6 + x_ret9, value47 & value48);
                        uint16_t value49 = BUS16_RDP(c, (db_ret9 << 0x10) + 1 + value46);
                        r->a = value49;
                        r->y = value46;
                        r->c = value45 <= 5;
                        r->z = value49 == 0;
                        r->n = value49 & 0x8000;
                        r->v = ((value45 ^ 5) & ((uint8_t)(5 - value45) ^ 5) & 0x80) != 0;
                        r->mf = 0;
                        r->sp -= 14;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xA7DB, 0x7EB258); GUARD_JSR(c, sp_call, 0xA7DB); } /* append_pending_record */
                        r->sp += 14;
                        uint16_t dp_ret10 = r->dp;
                        uint8_t db_ret10 = r->db;
                        bool m_ret7 = r->mf;
                        if (r->xf != 0) { c->fail = 3; return; }
                        uint16_t a_all10 = r->a;
                        uint16_t value50 = RAM16(0x0009 + dp_ret10);
                        m_flag5 = m_ret7;
                        a_hi6 = a_all10 >> 8;
                        y6 = value50;
                        data_bank6 = db_ret10;
                        direct_page6 = dp_ret10;
                    }
                    m_flag6 = m_flag5;
                    a_hi7 = a_hi6;
                    y7 = y6;
                    data_bank7 = data_bank6;
                    direct_page7 = direct_page6;
                }
                BUS8_SET(c, (data_bank7 << 0x10) + y7, 1);
                BUS16_SET(c, (data_bank7 << 0x10) + 2 + y7, RAM16(0x0005 + direct_page7));
                uint16_t value52 = RAM16(0x0007 + direct_page7);
                RAM16_SET(0x0001 + direct_page7, (uint16_t)(RAM16(0x0001 + direct_page7) - 1));
                if (RAM16(0x0001 + direct_page7) == 0) {
                    a1 = (uint8_t)(y7 + 0x10);
                    a_hi1 = (uint16_t)(y7 + 0x10) >> 8;
                    x1 = (uint16_t)(value52 + 2);
                    y1 = (uint16_t)(y7 + 0x10);
                    carry1 = y7 + 0x10 > 0xFFFF;
                    zero1 = RAM16(0x0001 + direct_page7) == 0;
                    negative1 = RAM16(0x0001 + direct_page7) & 0x8000;
                    overflow1 = ((y7 ^ (uint16_t)(y7 + 0x10)) & ((uint16_t)(y7 + 0x10) ^ 0x10) & 0x8000) != 0;
                    data_bank = data_bank7;
                    direct_page = direct_page7;
                    break;
                }
                a1 = (uint8_t)(y7 + 0x10);
                a_hi1 = (uint16_t)(y7 + 0x10) >> 8;
                x1 = (uint16_t)(value52 + 2);
                y1 = (uint16_t)(y7 + 0x10);
                carry1 = y7 + 0x10 > 0xFFFF;
                zero1 = RAM16(0x0001 + direct_page7) == 0;
                negative1 = RAM16(0x0001 + direct_page7) & 0x8000;
                overflow1 = ((y7 ^ (uint16_t)(y7 + 0x10)) & ((uint16_t)(y7 + 0x10) ^ 0x10) & 0x8000) != 0;
                data_bank = data_bank7;
                direct_page = direct_page7;
                continue;
            }
            RAM16_SET(0x0005 + dp_ret2, 0);
            BUS8_SET(c, (db_ret2 << 0x10) + y_ret2, 0);
            BUS16_SET(c, (db_ret2 << 0x10) + 2 + y_ret2, RAM16(0x0005 + dp_ret2));
            uint16_t value54 = RAM16(0x0007 + dp_ret2);
            RAM16_SET(0x0001 + dp_ret2, (uint16_t)(RAM16(0x0001 + dp_ret2) - 1));
            if (RAM16(0x0001 + dp_ret2) == 0) {
                a1 = (uint8_t)(y_ret2 + 0x10);
                a_hi1 = (uint16_t)(y_ret2 + 0x10) >> 8;
                x1 = (uint16_t)(value54 + 2);
                y1 = (uint16_t)(y_ret2 + 0x10);
                carry1 = y_ret2 + 0x10 > 0xFFFF;
                zero1 = RAM16(0x0001 + dp_ret2) == 0;
                negative1 = RAM16(0x0001 + dp_ret2) & 0x8000;
                overflow1 = ((y_ret2 ^ (uint16_t)(y_ret2 + 0x10)) & ((uint16_t)(y_ret2 + 0x10) ^ 0x10) & 0x8000) != 0;
                data_bank = db_ret2;
                direct_page = dp_ret2;
                break;
            }
            a1 = (uint8_t)(y_ret2 + 0x10);
            a_hi1 = (uint16_t)(y_ret2 + 0x10) >> 8;
            x1 = (uint16_t)(value54 + 2);
            y1 = (uint16_t)(y_ret2 + 0x10);
            carry1 = y_ret2 + 0x10 > 0xFFFF;
            zero1 = RAM16(0x0001 + dp_ret2) == 0;
            negative1 = RAM16(0x0001 + dp_ret2) & 0x8000;
            overflow1 = ((y_ret2 ^ (uint16_t)(y_ret2 + 0x10)) & ((uint16_t)(y_ret2 + 0x10) ^ 0x10) & 0x8000) != 0;
            data_bank = db_ret2;
            direct_page = dp_ret2;
            continue;
        }
        uint8_t value55 = RAM8(0x0000 + sp0 - 0x0D);
        uint8_t value56 = RAM8(0x0000 + sp0 - 2);
        uint8_t value57 = RAM8(0x0000 + sp0 - 1);
        uint8_t value58 = RAM8(0x0000 + sp0);
        r->a = (uint16_t)((uint16_t)(sp0 - 0x0D) + 0x0A);
        r->x = x1;
        r->y = y1;
        r->c = value56 & 0x01;
        r->z = ((value58 << 8) | value57) == 0;
        r->n = ((value58 << 8) | value57) & 0x8000;
        r->v = value56 & 0x40;
        r->mf = value56 & 0x20;
        r->xf = value56 & 0x10;
        r->db = value55;
        r->dp = (value58 << 8) | value57;
        r->i = value56 & 0x04;
        r->d = value56 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    r->a = (r->a & 0x00FF) | (((uint16_t)((uint16_t)(sp0 - 0x0D) + 0x0A) >> 8) << 8);
    r->z = dp == 0;
    r->n = dp & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA6FF, SOM_RTS, "gen", update_controller_states_and_messages, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 18, 1, 0, 277, 126)
