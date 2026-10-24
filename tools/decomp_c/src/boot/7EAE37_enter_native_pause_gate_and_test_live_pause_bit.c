#include "som_c.h"

/* 7EAE37 enter_native_pause_gate_and_test_live_pause_bit   [class C, 141 bytes, 66 instructions]
 * Source: src/boot/enter_native_pause_gate_and_test_live_pause_bit.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BXYV.
 */
static void enter_native_pause_gate_and_test_live_pause_bit(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = db;
    RAM8(0x0000 + sp0 - 4) = x >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 6) = x >> 8;
    RAM8(0x0000 + sp0 - 7) = (uint8_t)x;
    r->a = (uint16_t)(sp0 - 6);
    r->z = (uint16_t)(sp0 - 6) == 0;
    r->n = (uint16_t)(sp0 - 6) & 0x8000;
    r->dp = (uint16_t)(sp0 - 6);
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAE44, 0x7EA814); GUARD_JSR(c, sp_call, 0xAE44); } /* read_native_scheduler_flags_from_bank_7f */
    r->sp += 8;
    uint16_t a_all = r->a;
    uint8_t a_hi5;
    uint16_t y5;
    uint8_t data_bank5;
    uint16_t direct_page5;
    if (((uint8_t)a_all & 0x40) == 0) {
        a_hi5 = a_all >> 8;
        y5 = y;
        data_bank5 = db;
        direct_page5 = (uint16_t)(sp0 - 6);
    } else {
        r->a = a_all >> 8 << 8 | ((uint8_t)a_all & 0x40);
        r->z = ((uint8_t)a_all & 0x40) == 0;
        r->n = (uint8_t)a_all & 0x40 & 0x80;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0xAE4B, 0x7EC01E); GUARD_JSR(c, sp_call, 0xAE4B); } /* read_native_current_program_header_pointer */
        r->sp += 8;
        uint16_t a_all2 = r->a;
        uint16_t x_ret = r->x;
        uint8_t value = BUS8_RDP(c, (db << 0x10) + x_ret);
        uint8_t a_hi4;
        uint16_t y4;
        uint8_t data_bank4;
        uint16_t direct_page4;
        if (value != 0x0F) {
            a_hi4 = a_all2 >> 8;
            y4 = y;
            data_bank4 = db;
            direct_page4 = (uint16_t)(sp0 - 6);
        } else {
            RAM8(0x1E00) = 0xF6;
            r->a = (a_all2 >> 8 << 8) | 0xF6;
            r->c = value >= 0x0F;
            r->z = 0;
            r->n = 1;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 8;
            { const uint16_t sp_call = r->sp; JSL(c, 0xAE5C, 0xC30004); GUARD_JSL(c, sp_call, 0xAE5C); } /* audio_command_sender_public_jump */
            r->sp += 8;
            r->sp -= 8;
            { const uint16_t sp_call = r->sp; JSR(c, 0xAE5F, 0x7EACE9); GUARD_JSR(c, sp_call, 0xAE5F); } /* current_task_id */
            r->sp += 8;
            uint16_t dp_ret = r->dp;
            r->sp -= 8;
            { const uint16_t sp_call = r->sp; JSR(c, 0xAE62, 0x7ECB86); GUARD_JSR(c, sp_call, 0xAE62); } /* allocate_timer_registration */
            r->sp += 8;
            uint8_t db_ret2 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all5 = r->a;
            uint16_t x_ret6 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret5 = r->c;
            bool overflow_ret5 = r->v;
            BUS16_SET(c, (uint16_t)(dp_ret + 2), x_ret6);
            BUS8_SET(c, (uint16_t)(dp_ret + 1), 0xFF);
            uint8_t a_hi1 = a_all5 >> 8;
            uint16_t y1 = y_ret2;
            bool carry1 = carry_ret5;
            bool overflow1 = overflow_ret5;
            uint8_t data_bank = db_ret2;
            uint16_t direct_page = dp_ret;
            for (;;) {
                uint8_t value2 = BUS8_RDP(c, (uint16_t)(direct_page + 1));
                r->a = (a_hi1 << 8) | value2;
                r->y = y1;
                r->c = carry1;
                r->z = value2 == 0;
                r->n = value2 & 0x80;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = data_bank;
                r->dp = direct_page;
                r->sp -= 8;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAE6D, 0x7ED52F); GUARD_JSR(c, sp_call, 0xAE6D); } /* render_and_queue_native_interface_protocol_overlay */
                r->sp += 8;
                uint16_t dp_ret2 = r->dp;
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 2));
                r->x = value3;
                r->y = 0x30;
                r->z = value3 == 0;
                r->n = value3 & 0x8000;
                r->sp -= 8;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAE75, 0x7ECC16); GUARD_JSR(c, sp_call, 0xAE75); } /* set_timer_countdown */
                r->sp += 8;
                uint16_t dp_ret3 = r->dp;
                uint8_t db_ret4 = r->db;
                bool m_ret4 = r->mf;
                bool x_ret8 = r->xf;
                uint16_t a_all7 = r->a;
                bool carry_ret7 = r->c;
                bool zero_ret7 = r->z;
                bool negative_ret7 = r->n;
                bool overflow_ret7 = r->v;
                uint8_t a1 = (uint8_t)a_all7;
                uint8_t a_hi2 = a_all7 >> 8;
                uint16_t x1 = value3;
                uint16_t y2 = 0x30;
                bool carry2 = carry_ret7;
                bool zero1 = zero_ret7;
                bool negative1 = negative_ret7;
                bool overflow2 = overflow_ret7;
                uint8_t data_bank2 = db_ret4;
                uint16_t direct_page2 = dp_ret3;
                for (;;) {
                    r->a = (a_hi2 << 8) | a1;
                    r->x = x1;
                    r->y = y2;
                    r->c = carry2;
                    r->z = zero1;
                    r->n = negative1;
                    r->v = overflow2;
                    r->mf = m_ret4;
                    r->xf = x_ret8;
                    r->db = data_bank2;
                    r->dp = direct_page2;
                    r->sp -= 8;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xAE78, 0x7EA814); GUARD_JSR(c, sp_call, 0xAE78); } /* read_native_scheduler_flags_from_bank_7f */
                    r->sp += 8;
                    if (r->mf != 1) { c->fail = 3; return; }
                    if (r->xf != 0) { c->fail = 3; return; }
                    uint16_t a_all8 = r->a;
                    bool carry_ret8 = r->c;
                    bool overflow_ret8 = r->v;
                    if (((uint8_t)a_all8 & 0x40) != 0) {
                        r->a = a_all8 >> 8 << 8 | ((uint8_t)a_all8 & 0x40);
                        r->z = ((uint8_t)a_all8 & 0x40) == 0;
                        r->n = (uint8_t)a_all8 & 0x40 & 0x80;
                        r->sp -= 8;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAE7F, 0x7EB2FB); GUARD_JSR(c, sp_call, 0xAE7F); } /* receive_raw_task_record */
                        r->sp += 8;
                        uint16_t dp_ret4 = r->dp;
                        uint8_t db_ret5 = r->db;
                        if (r->mf != 1) { c->fail = 3; return; }
                        if (r->xf != 0) { c->fail = 3; return; }
                        uint16_t a_all9 = r->a;
                        uint16_t x_ret9 = r->x;
                        uint16_t y_ret4 = r->y;
                        bool overflow_ret9 = r->v;
                        uint8_t value4 = BUS8_RDP(c, (db_ret5 << 0x10) + 2 + x_ret9);
                        if (value4 == 0xFF) {
                            a1 = value4;
                            a_hi2 = a_all9 >> 8;
                            x1 = x_ret9;
                            y2 = y_ret4;
                            carry2 = value4 >= 0xFF;
                            zero1 = value4 == 0xFF;
                            negative1 = (uint8_t)(value4 - 0xFF) & 0x80;
                            overflow2 = overflow_ret9;
                            data_bank2 = db_ret5;
                            direct_page2 = dp_ret4;
                            break;
                        }
                        if (value4 == 0xFE) {
                            r->a = (a_all9 >> 8 << 8) | value4;
                            r->c = value4 >= 0xFE;
                            r->z = value4 == 0xFE;
                            r->n = (uint8_t)(value4 - 0xFE) & 0x80;
                            r->sp -= 8;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xAE97, 0x7EB1DD); GUARD_JSR(c, sp_call, 0xAE97); } /* release_eight_byte_record */
                            r->sp += 8;
                            uint16_t dp_ret5 = r->dp;
                            uint8_t db_ret6 = r->db;
                            uint16_t a_all10 = r->a;
                            bool carry_ret10 = r->c;
                            bool zero_ret10 = r->z;
                            bool negative_ret10 = r->n;
                            bool overflow_ret10 = r->v;
                            a1 = (uint8_t)a_all10;
                            a_hi2 = a_all10 >> 8;
                            x1 = x_ret9;
                            y2 = y_ret4;
                            carry2 = carry_ret10;
                            zero1 = zero_ret10;
                            negative1 = negative_ret10;
                            overflow2 = overflow_ret10;
                            data_bank2 = db_ret6;
                            direct_page2 = dp_ret5;
                            continue;
                        }
                        RAM8(0x0000 + sp0 - 8) = x_ret9 >> 8;
                        RAM8(0x0000 + sp0 - 9) = (uint8_t)x_ret9;
                        r->a = (a_all9 >> 8 << 8) | value4;
                        r->c = value4 >= 0xFE;
                        r->z = value4 == 0xFE;
                        r->n = (uint8_t)(value4 - 0xFE) & 0x80;
                        r->sp -= 10;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAE8E, 0x7EACE9); GUARD_JSR(c, sp_call, 0xAE8E); } /* current_task_id */
                        r->sp += 10;
                        if (r->xf != 0) { c->fail = 3; return; }
                        uint8_t value5 = RAM8(0x0000 + sp0 - 9);
                        uint8_t value6 = RAM8(0x0000 + sp0 - 8);
                        r->x = (value6 << 8) | value5;
                        r->z = ((value6 << 8) | value5) == 0;
                        r->n = ((value6 << 8) | value5) & 0x8000;
                        r->sp -= 8;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xAE92, 0x7EB258); GUARD_JSR(c, sp_call, 0xAE92); } /* append_pending_record */
                        r->sp += 8;
                        uint16_t dp_ret7 = r->dp;
                        uint8_t db_ret8 = r->db;
                        uint16_t a_all12 = r->a;
                        uint16_t x_ret13 = r->x;
                        uint16_t y_ret5 = r->y;
                        bool carry_ret12 = r->c;
                        bool zero_ret12 = r->z;
                        bool negative_ret12 = r->n;
                        bool overflow_ret12 = r->v;
                        a1 = (uint8_t)a_all12;
                        a_hi2 = a_all12 >> 8;
                        x1 = x_ret13;
                        y2 = y_ret5;
                        carry2 = carry_ret12;
                        zero1 = zero_ret12;
                        negative1 = negative_ret12;
                        overflow2 = overflow_ret12;
                        data_bank2 = db_ret8;
                        direct_page2 = dp_ret7;
                        continue;
                    }
                    a_hi1 = a_all8 >> 8;
                    y1 = y2;
                    carry1 = carry_ret8;
                    overflow1 = overflow_ret8;
                    data_bank = data_bank2;
                    direct_page = direct_page2;
                    goto leave_loop_7EAE69_3;
                }
                r->a = (a_hi2 << 8) | a1;
                r->x = x1;
                r->y = y2;
                r->c = carry2;
                r->z = zero1;
                r->n = negative1;
                r->v = overflow2;
                r->mf = 1;
                r->xf = 0;
                r->db = data_bank2;
                r->dp = direct_page2;
                r->sp -= 8;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAE9C, 0x7EB1DD); GUARD_JSR(c, sp_call, 0xAE9C); } /* release_eight_byte_record */
                r->sp += 8;
                uint16_t dp_ret8 = r->dp;
                uint8_t db_ret9 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                bool x_ret14 = r->xf;
                uint16_t a_all13 = r->a;
                bool carry_ret13 = r->c;
                bool overflow_ret13 = r->v;
                uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret8 + 1));
                BUS8_SET(c, (uint16_t)(dp_ret8 + 1), value7 ^ 0xFF);
                if (x_ret14 != 0) { c->fail = 3; return; }
                a_hi1 = a_all13 >> 8;
                y1 = y2;
                carry1 = carry_ret13;
                overflow1 = overflow_ret13;
                data_bank = db_ret9;
                direct_page = dp_ret8;
            }
            leave_loop_7EAE69_3:;
            uint8_t value8 = BUS8_RDP(c, (uint16_t)(direct_page + 1));
            bool m_flag;
            uint8_t a_hi3;
            uint16_t y3;
            bool carry3;
            bool overflow3;
            uint8_t data_bank3;
            uint16_t direct_page3;
            if (value8 == 0) {
                m_flag = 1;
                a_hi3 = a_hi1;
                y3 = y1;
                carry3 = carry1;
                overflow3 = overflow1;
                data_bank3 = data_bank;
                direct_page3 = direct_page;
            } else {
                r->a = (a_hi1 << 8) | (value8 ^ 0xFF);
                r->y = y1;
                r->c = carry1;
                r->z = (value8 ^ 0xFF) == 0;
                r->n = (value8 ^ 0xFF) & 0x80;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = data_bank;
                r->dp = direct_page;
                r->sp -= 8;
                { const uint16_t sp_call = r->sp; JSR(c, 0xAEAD, 0x7ED52F); GUARD_JSR(c, sp_call, 0xAEAD); } /* render_and_queue_native_interface_protocol_overlay */
                r->sp += 8;
                uint16_t dp_ret9 = r->dp;
                uint8_t db_ret10 = r->db;
                bool m_ret8 = r->mf;
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all14 = r->a;
                uint16_t y_ret6 = r->y;
                bool carry_ret14 = r->c;
                bool overflow_ret14 = r->v;
                m_flag = m_ret8;
                a_hi3 = a_all14 >> 8;
                y3 = y_ret6;
                carry3 = carry_ret14;
                overflow3 = overflow_ret14;
                data_bank3 = db_ret10;
                direct_page3 = dp_ret9;
            }
            uint16_t value9 = BUS16_RDP(c, (uint16_t)(direct_page3 + 2));
            r->a = (a_hi3 << 8) | a;
            r->x = value9;
            r->y = y3;
            r->c = carry3;
            r->z = value9 == 0;
            r->n = value9 & 0x8000;
            r->v = overflow3;
            r->mf = m_flag;
            r->xf = 0;
            r->db = data_bank3;
            r->dp = direct_page3;
            r->sp -= 8;
            { const uint16_t sp_call = r->sp; JSR(c, 0xAEB2, 0x7ECBCA); GUARD_JSR(c, sp_call, 0xAEB2); } /* release_native_timer_registration */
            r->sp += 8;
            uint16_t dp_ret10 = r->dp;
            uint8_t db_ret11 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            uint16_t a_all15 = r->a;
            RAM8(0x1E00) = 0xF7;
            r->a = (a_all15 >> 8 << 8) | 0xF7;
            r->z = 0;
            r->n = 1;
            r->sp -= 8;
            { const uint16_t sp_call = r->sp; JSL(c, 0xAEBC, 0xC30004); GUARD_JSL(c, sp_call, 0xAEBC); } /* audio_command_sender_public_jump */
            r->sp += 8;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all16 = r->a;
            uint16_t y_ret7 = r->y;
            a_hi4 = a_all16 >> 8;
            y4 = y_ret7;
            data_bank4 = db_ret11;
            direct_page4 = dp_ret10;
        }
        a_hi5 = a_hi4;
        y5 = y4;
        data_bank5 = data_bank4;
        direct_page5 = direct_page4;
    }
    uint8_t value10 = RAM8(0x0000 + sp0 - 7);
    uint8_t value11 = RAM8(0x0000 + sp0 - 6);
    uint8_t value14 = RAM8(0x0000 + sp0 - 3);
    uint8_t value15 = RAM8(0x0000 + sp0 - 2);
    uint8_t value16 = RAM8(0x0000 + sp0 - 1);
    uint8_t value17 = RAM8(0x0000 + sp0);
    r->a = (a_hi5 << 8) | value14;
    r->x = (value11 << 8) | value10;
    r->y = y5;
    r->v = value15 & 0x40;
    r->mf = value15 & 0x20;
    r->xf = value15 & 0x10;
    r->db = data_bank5;
    r->dp = (value17 << 8) | value16;
    r->i = value15 & 0x04;
    r->d = value15 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EAE37, SOM_RTS, "gen", enter_native_pause_gate_and_test_live_pause_bit, 0, L_B | L_X | L_Y | L_V, 10, 1, 0, 141, 66)
