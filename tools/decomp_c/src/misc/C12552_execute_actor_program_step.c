#include "som_c.h"

/* C12552 execute_actor_program_step   [class B, 71 bytes, 39 instructions]
 * Source: src/rom/execute_actor_program_step.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BYCV.
 */
static void execute_actor_program_step(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp + 2;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0 - 2) = dp >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 4) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 5) = x >> 8;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 7) = 0x7E;
    RAM8(0x0000 + sp0 - 8) = 0x7E;
    uint8_t a_hi6;
    uint16_t y6;
    bool carry6;
    bool zero6;
    bool negative6;
    bool overflow6;
    uint8_t data_bank6;
    uint16_t direct_page6;
    if (((x & 0x1FFF) | 0xE000) >= 0xE600) {
        RAM8(0x0001 + (uint16_t)(sp0 - 7)) = 0;
        uint8_t a1 = (uint8_t)((x & 0x1FFF) | 0xE000);
        uint8_t a_hi1 = ((x & 0x1FFF) | 0xE000) >> 8;
        uint16_t y1 = (x & 0x1FFF) | 0xE000;
        bool carry1 = ((x & 0x1FFF) | 0xE000) >= 0xE600;
        bool zero1 = ((x & 0x1FFF) | 0xE000) == 0xE600;
        bool negative1 = (uint16_t)(((x & 0x1FFF) | 0xE000) - 0xE600) & 0x8000;
        bool overflow1 = overflow;
        uint8_t data_bank = 0x7E;
        uint16_t direct_page = (uint16_t)(sp0 - 7);
        for (;;) {
            r->y = y1;
            r->c = carry1;
            r->z = zero1;
            r->n = negative1;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0x257C, 0xC1251A); GUARD_JSR(c, sp_call, 0x257C); } /* dispatch_actor_script_opcode */
            r->sp += 6;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            uint16_t y_ret = r->y;
            bool overflow_ret = r->v;
            bool m_flag;
            bool x_flag;
            uint8_t a_hi2;
            uint16_t y2;
            bool carry2;
            bool zero2;
            bool negative2;
            bool overflow2;
            uint8_t data_bank2;
            uint16_t direct_page2;
            if ((uint8_t)a_all == 0) {
                m_flag = 1;
                x_flag = x_ret;
                a_hi2 = a_all >> 8;
                y2 = y_ret;
                carry2 = (uint8_t)a_all >= 0;
                zero2 = (uint8_t)a_all == 0;
                negative2 = (uint8_t)a_all & 0x80;
                overflow2 = overflow_ret;
                data_bank2 = db_ret;
                direct_page2 = dp_ret;
            } else {
                RAM8(0x0001 + dp_ret)--;
                if (RAM8(0x0001 + dp_ret) != 0) {
                    if (x_ret != 0) { c->fail = 3; return; }
                    a1 = (uint8_t)a_all;
                    a_hi1 = a_all >> 8;
                    y1 = y_ret;
                    carry1 = (uint8_t)a_all >= 0;
                    zero1 = RAM8(0x0001 + dp_ret) == 0;
                    negative1 = RAM8(0x0001 + dp_ret) & 0x80;
                    overflow1 = overflow_ret;
                    data_bank = db_ret;
                    direct_page = dp_ret;
                    continue;
                }
                r->c = (uint8_t)a_all >= 0;
                r->xf = 0;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2587, 0xC10100); GUARD_JSR(c, sp_call, 0x2587); } /* restart_actor_program_on_script_error */
                r->sp += 6;
                uint16_t dp_ret2 = r->dp;
                uint8_t db_ret2 = r->db;
                bool m_ret = r->mf;
                bool x_ret3 = r->xf;
                uint16_t a_all2 = r->a;
                uint16_t y_ret2 = r->y;
                bool carry_ret2 = r->c;
                bool zero_ret2 = r->z;
                bool negative_ret2 = r->n;
                bool overflow_ret2 = r->v;
                m_flag = m_ret;
                x_flag = x_ret3;
                a_hi2 = a_all2 >> 8;
                y2 = y_ret2;
                carry2 = carry_ret2;
                zero2 = zero_ret2;
                negative2 = negative_ret2;
                overflow2 = overflow_ret2;
                data_bank2 = db_ret2;
                direct_page2 = dp_ret2;
            }
            a_hi1 = a_hi2;
            y1 = y2;
            carry1 = carry2;
            zero1 = zero2;
            negative1 = negative2;
            overflow1 = overflow2;
            data_bank = data_bank2;
            direct_page = direct_page2;
            break;
        }
        a_hi6 = a_hi1;
        y6 = y1;
        carry6 = carry1;
        zero6 = zero1;
        negative6 = negative1;
        overflow6 = overflow1;
        data_bank6 = data_bank;
        direct_page6 = direct_page;
    } else {
        r->y = (x & 0x1FFF) | 0xE000;
        r->c = ((x & 0x1FFF) | 0xE000) >= 0xE600;
        r->z = ((x & 0x1FFF) | 0xE000) == 0xE600;
        r->n = (uint16_t)(((x & 0x1FFF) | 0xE000) - 0xE600) & 0x8000;
        r->dp = (uint16_t)(sp0 - 7);
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0x2573, 0xC12457); GUARD_JSR(c, sp_call, 0x2573); } /* preempt_hero_program_for_controller_action */
        r->sp += 6;
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        bool x_ret5 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t y_ret3 = r->y;
        bool overflow_ret3 = r->v;
        uint8_t a_hi5;
        uint16_t y5;
        bool carry5;
        bool zero5;
        bool negative5;
        bool overflow5;
        uint8_t data_bank5;
        uint16_t direct_page5;
        if ((uint8_t)a_all3 == 0) {
            a_hi5 = a_all3 >> 8;
            y5 = y_ret3;
            carry5 = (uint8_t)a_all3 >= 0;
            zero5 = (uint8_t)a_all3 == 0;
            negative5 = (uint8_t)a_all3 & 0x80;
            overflow5 = overflow_ret3;
            data_bank5 = db_ret3;
            direct_page5 = dp_ret3;
        } else {
            RAM8(0x0001 + dp_ret3) = 0;
            uint8_t a2 = (uint8_t)a_all3;
            uint8_t a_hi3 = a_all3 >> 8;
            uint16_t y3 = y_ret3;
            bool carry3 = (uint8_t)a_all3 >= 0;
            bool zero3 = (uint8_t)a_all3 == 0;
            bool negative3 = (uint8_t)a_all3 & 0x80;
            bool overflow3 = overflow_ret3;
            uint8_t data_bank3 = db_ret3;
            uint16_t direct_page3 = dp_ret3;
            for (;;) {
                r->y = y3;
                r->c = carry3;
                r->z = zero3;
                r->n = negative3;
                r->v = overflow3;
                r->mf = 1;
                r->xf = x_ret5;
                r->db = data_bank3;
                r->dp = direct_page3;
                r->sp -= 6;
                { const uint16_t sp_call = r->sp; JSR(c, 0x257C, 0xC1251A); GUARD_JSR(c, sp_call, 0x257C); } /* dispatch_actor_script_opcode */
                r->sp += 6;
                uint16_t dp_ret4 = r->dp;
                uint8_t db_ret4 = r->db;
                bool x_ret7 = r->xf;
                uint16_t a_all4 = r->a;
                uint16_t y_ret4 = r->y;
                bool overflow_ret4 = r->v;
                bool m_flag2;
                bool x_flag2;
                uint8_t a_hi4;
                uint16_t y4;
                bool carry4;
                bool zero4;
                bool negative4;
                bool overflow4;
                uint8_t data_bank4;
                uint16_t direct_page4;
                if ((uint8_t)a_all4 == 0) {
                    m_flag2 = 1;
                    x_flag2 = x_ret7;
                    a_hi4 = a_all4 >> 8;
                    y4 = y_ret4;
                    carry4 = (uint8_t)a_all4 >= 0;
                    zero4 = (uint8_t)a_all4 == 0;
                    negative4 = (uint8_t)a_all4 & 0x80;
                    overflow4 = overflow_ret4;
                    data_bank4 = db_ret4;
                    direct_page4 = dp_ret4;
                } else {
                    RAM8(0x0001 + dp_ret4)--;
                    if (RAM8(0x0001 + dp_ret4) != 0) {
                        a2 = (uint8_t)a_all4;
                        a_hi3 = a_all4 >> 8;
                        y3 = y_ret4;
                        carry3 = (uint8_t)a_all4 >= 0;
                        zero3 = RAM8(0x0001 + dp_ret4) == 0;
                        negative3 = RAM8(0x0001 + dp_ret4) & 0x80;
                        overflow3 = overflow_ret4;
                        data_bank3 = db_ret4;
                        direct_page3 = dp_ret4;
                        continue;
                    }
                    r->c = (uint8_t)a_all4 >= 0;
                    r->sp -= 6;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x2587, 0xC10100); GUARD_JSR(c, sp_call, 0x2587); } /* restart_actor_program_on_script_error */
                    r->sp += 6;
                    uint16_t dp_ret5 = r->dp;
                    uint8_t db_ret5 = r->db;
                    bool m_ret2 = r->mf;
                    bool x_ret9 = r->xf;
                    uint16_t a_all5 = r->a;
                    uint16_t y_ret5 = r->y;
                    bool carry_ret5 = r->c;
                    bool zero_ret5 = r->z;
                    bool negative_ret5 = r->n;
                    bool overflow_ret5 = r->v;
                    m_flag2 = m_ret2;
                    x_flag2 = x_ret9;
                    a_hi4 = a_all5 >> 8;
                    y4 = y_ret5;
                    carry4 = carry_ret5;
                    zero4 = zero_ret5;
                    negative4 = negative_ret5;
                    overflow4 = overflow_ret5;
                    data_bank4 = db_ret5;
                    direct_page4 = dp_ret5;
                }
                a_hi3 = a_hi4;
                y3 = y4;
                carry3 = carry4;
                zero3 = zero4;
                negative3 = negative4;
                overflow3 = overflow4;
                data_bank3 = data_bank4;
                direct_page3 = direct_page4;
                break;
            }
            a_hi5 = a_hi3;
            y5 = y3;
            carry5 = carry3;
            zero5 = zero3;
            negative5 = negative3;
            overflow5 = overflow3;
            data_bank5 = data_bank3;
            direct_page5 = direct_page3;
        }
        a_hi6 = a_hi5;
        y6 = y5;
        carry6 = carry5;
        zero6 = zero5;
        negative6 = negative5;
        overflow6 = overflow5;
        data_bank6 = data_bank5;
        direct_page6 = direct_page5;
    }
    r->y = y6;
    r->c = carry6;
    r->z = zero6;
    r->n = negative6;
    r->v = overflow6;
    r->db = data_bank6;
    r->dp = direct_page6;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x258A, 0xC124D7); GUARD_JSR(c, sp_call, 0x258A); } /* mirror_confused_actor_command_direction */
    r->sp += 6;
    bool m_ret3 = r->mf;
    if (m_ret3) {
        uint8_t value3 = BUS8_RDP(c, (data_bank6 << 0x10) + 0x0140 + y6);
        BUS8_SET(c, (data_bank6 << 0x10) + 0x014D + y6, value3);
        uint8_t value4 = RAM8(0x0000 + sp0 - 7);
        RAM8(0x0000 + sp0 - 5) = value3;
        uint8_t value7 = RAM8(0x0000 + sp0 - 4);
        uint8_t value8 = RAM8(0x0000 + sp0 - 3);
        uint8_t value9 = RAM8(0x0000 + sp0 - 2);
        r->c = value7 & 0x01;
        r->v = value7 & 0x40;
        r->mf = value7 & 0x20;
        r->xf = value7 & 0x10;
        r->db = value4;
        r->dp = (value9 << 8) | value8;
        r->i = value7 & 0x04;
        r->d = value7 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value10 = BUS16_RDP(c, (data_bank6 << 0x10) + 0x0140 + y6);
        BUS16_SET(c, (data_bank6 << 0x10) + 0x014D + y6, value10);
        uint8_t value11 = RAM8(0x0000 + sp0 - 7);
        RAM16_SET(0x0000 + sp0 - 5, value10);
        uint8_t value14 = RAM8(0x0000 + sp0 - 4);
        uint8_t value15 = RAM8(0x0000 + sp0 - 3);
        uint8_t value16 = RAM8(0x0000 + sp0 - 2);
        uint8_t value17 = RAM8(0x0000 + sp0 - 1);
        uint8_t value18 = RAM8(0x0000 + sp0);
        r->a = (value15 << 8) | value14;
        r->c = value16 & 0x01;
        r->v = value16 & 0x40;
        r->mf = value16 & 0x20;
        r->xf = value16 & 0x10;
        r->db = value11;
        r->dp = (value18 << 8) | value17;
        r->i = value16 & 0x04;
        r->d = value16 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        r->sp += 2;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC12552, SOM_RTS, "gen", execute_actor_program_step, SOM_UNWINDS, L_B | L_Y | L_C | L_V, 9, 1, 0, 71, 39)
