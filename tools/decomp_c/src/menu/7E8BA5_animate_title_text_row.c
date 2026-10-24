#include "som_c.h"

/* 7E8BA5 animate_title_text_row   [class B, 257 bytes, 113 instructions]
 * Source: src/boot/animate_title_text_row.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$06F1.  Callers read: YCV.
 */
static void animate_title_text_row(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x06F1) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 6;
    RAM8(0x0000 + sp0 - 1) = 0xF1;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), x);
    uint8_t value = RAM8(0x10063);
    RAM8(0x10063) = (uint8_t)(value + 1);
    bool x_flag3;
    uint16_t y9;
    uint16_t direct_page9;
    if ((uint8_t)(value + 1) < 0x26) {
        r->a = ((uint16_t)(sp0 - 9) >> 8 << 8) | (uint8_t)(value + 1);
        r->x = 1;
        r->c = (uint8_t)(value + 1) >= 0x26;
        r->z = 0;
        r->n = 0;
        r->v = (((uint16_t)(sp0 - 3) ^ 6) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
        r->dp = (uint16_t)(sp0 - 9);
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8BDF, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8BDF); } /* wait_for_native_title_timer_with_pause_clear */
        r->sp += 9;
        uint16_t dp_ret = r->dp;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        RAM16_SET(0x1005D, 0xFFF8);
        uint8_t a1 = 0xF8;
        uint8_t a_hi1 = 0xFF;
        uint16_t y1 = y_ret;
        bool carry1 = carry_ret;
        bool overflow1 = overflow_ret;
        uint16_t direct_page = dp_ret;
        do {
            r->a = (a_hi1 << 8) | a1;
            r->x = 8;
            r->y = y1;
            r->c = carry1;
            r->z = 0;
            r->n = 0;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7F;
            r->dp = direct_page;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8BEB, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8BEB); } /* wait_for_native_title_timer_with_pause_clear */
            r->sp += 9;
            uint16_t dp_ret2 = r->dp;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all2 = r->a;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            RAM16_SET(0x1005D, (uint16_t)(RAM16(0x1005D) + 1));
            a1 = (uint8_t)a_all2;
            a_hi1 = a_all2 >> 8;
            y1 = y_ret2;
            carry1 = carry_ret2;
            overflow1 = overflow_ret2;
            direct_page = dp_ret2;
        } while (RAM16(0x1005D) != 0);
        x_flag3 = 0;
        y9 = y1;
        direct_page9 = direct_page;
    } else {
        bool x_flag2;
        uint16_t y8;
        uint16_t direct_page8;
        if ((uint8_t)(value + 1) < 0x2B) {
            uint16_t value3 = BUS16(c, 0x7F0004 + RAM16(0x10046));
            uint16_t value4 = RAM16(0x5E1E);
            uint16_t y4;
            uint16_t direct_page4;
            if (value3 == value4) {
                BUS8_SET(c, 0x7F0003 + RAM16(0x10052), 0xFF);
                BUS8_SET(c, 0x7F0003 + RAM16(0x10054), 0);
                r->a = (value3 >> 8 << 8) | 0xFF;
                r->x = 1;
                r->c = value3 >= value4;
                r->z = 0;
                r->n = 0;
                r->v = (((uint16_t)(sp0 - 3) ^ 6) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
                r->dp = (uint16_t)(sp0 - 9);
                r->sp -= 9;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8BDF, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8BDF); } /* wait_for_native_title_timer_with_pause_clear */
                r->sp += 9;
                uint16_t dp_ret3 = r->dp;
                if (r->mf != 0) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t y_ret3 = r->y;
                bool carry_ret3 = r->c;
                bool overflow_ret3 = r->v;
                RAM16_SET(0x1005D, 0xFFF8);
                uint8_t a2 = 0xF8;
                uint8_t a_hi2 = 0xFF;
                uint16_t y2 = y_ret3;
                bool carry2 = carry_ret3;
                bool overflow2 = overflow_ret3;
                uint16_t direct_page2 = dp_ret3;
                do {
                    r->a = (a_hi2 << 8) | a2;
                    r->x = 8;
                    r->y = y2;
                    r->c = carry2;
                    r->z = 0;
                    r->n = 0;
                    r->v = overflow2;
                    r->mf = 0;
                    r->xf = 0;
                    r->db = 0x7F;
                    r->dp = direct_page2;
                    r->sp -= 9;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8BEB, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8BEB); } /* wait_for_native_title_timer_with_pause_clear */
                    r->sp += 9;
                    uint16_t dp_ret4 = r->dp;
                    if (r->mf != 0) { c->fail = 3; return; }
                    if (r->xf != 0) { c->fail = 3; return; }
                    uint16_t a_all4 = r->a;
                    uint16_t y_ret4 = r->y;
                    bool carry_ret4 = r->c;
                    bool overflow_ret4 = r->v;
                    RAM16_SET(0x1005D, (uint16_t)(RAM16(0x1005D) + 1));
                    a2 = (uint8_t)a_all4;
                    a_hi2 = a_all4 >> 8;
                    y2 = y_ret4;
                    carry2 = carry_ret4;
                    overflow2 = overflow_ret4;
                    direct_page2 = dp_ret4;
                } while (RAM16(0x1005D) != 0);
                y4 = y2;
                direct_page4 = direct_page2;
            } else {
                uint16_t value7 = RAM16(0x0003 + (uint16_t)(sp0 - 9));
                r->a = (uint16_t)(value7 + 0x80);
                r->x = 0x01A0;
                r->y = (uint16_t)(value7 + 0x80);
                r->c = value7 + 0x80 > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = ((value7 ^ (uint16_t)(value7 + 0x80)) & ((uint16_t)(value7 + 0x80) ^ 0x80) & 0x8000) != 0;
                r->dp = (uint16_t)(sp0 - 9);
                r->sp -= 9;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8C0E, 0x7E8820); GUARD_JSR(c, sp_call, 0x8C0E); } /* expand_title_text_row */
                r->sp += 9;
                if (r->xf != 0) { c->fail = 3; return; }
                r->x = 1;
                r->z = 0;
                r->n = 0;
                r->sp -= 9;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8C14, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8C14); } /* wait_for_native_title_timer_with_pause_clear */
                r->sp += 9;
                uint16_t dp_ret6 = r->dp;
                if (r->mf != 0) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t y_ret6 = r->y;
                bool carry_ret6 = r->c;
                bool overflow_ret6 = r->v;
                RAM16_SET(0x1005D, 0xFFF8);
                BUS16_SET(c, (uint16_t)(dp_ret6 + 1), 0x20);
                BUS16_SET(c, (uint16_t)(dp_ret6 + 5), 0);
                uint8_t a3 = 0x20;
                uint8_t a_hi3 = 0;
                uint16_t y3 = y_ret6;
                bool carry3 = carry_ret6;
                bool overflow3 = overflow_ret6;
                uint16_t direct_page3 = dp_ret6;
                for (;;) {
                    r->a = (a_hi3 << 8) | a3;
                    r->x = 2;
                    r->y = y3;
                    r->c = carry3;
                    r->z = 0;
                    r->n = 0;
                    r->v = overflow3;
                    r->mf = 0;
                    r->xf = 0;
                    r->db = 0x7F;
                    r->dp = direct_page3;
                    r->sp -= 9;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8C27, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8C27); } /* wait_for_native_title_timer_with_pause_clear */
                    r->sp += 9;
                    uint16_t dp_ret7 = r->dp;
                    if (r->xf != 0) { c->fail = 3; return; }
                    uint16_t y_ret7 = r->y;
                    uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 5));
                    r->x = value8;
                    r->z = value8 == 0;
                    r->n = value8 & 0x8000;
                    r->sp -= 9;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8C2C, 0x7E8B15); GUARD_JSR(c, sp_call, 0x8C2C); } /* update_title_colour_at_offset4 */
                    r->sp += 9;
                    uint16_t dp_ret8 = r->dp;
                    if (r->mf != 0) { c->fail = 3; return; }
                    if (r->xf != 0) { c->fail = 3; return; }
                    uint16_t x_ret8 = r->x;
                    bool carry_ret8 = r->c;
                    bool overflow_ret8 = r->v;
                    BUS16_SET(c, (uint16_t)(dp_ret8 + 5), (uint16_t)(x_ret8 + 2));
                    uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret8 + 1));
                    if ((uint16_t)((value9 & 3) - 1) == 0) {
                        RAM16_SET(0x1005D, (uint16_t)(RAM16(0x1005D) + 1));
                    }
                    uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret8 + 1));
                    BUS16_RMW_SET(c, (uint16_t)(dp_ret8 + 1), (uint16_t)(value10 - 1));
                    a3 = (uint8_t)((value9 & 3) - 1);
                    a_hi3 = (uint16_t)((value9 & 3) - 1) >> 8;
                    y3 = y_ret7;
                    carry3 = carry_ret8;
                    overflow3 = overflow_ret8;
                    direct_page3 = dp_ret8;
                    if (!((uint16_t)(value10 - 1) != 0)) break;
                }
                y4 = y3;
                direct_page4 = direct_page3;
            }
            x_flag2 = 0;
            y8 = y4;
            direct_page8 = direct_page4;
        } else {
            bool x_flag;
            uint16_t y7;
            uint16_t direct_page7;
            if ((uint8_t)(value + 1) != 0x2B) {
                r->a = ((uint16_t)(sp0 - 9) >> 8 << 8) | (uint8_t)(value + 1);
                r->x = 1;
                r->c = (uint8_t)(value + 1) >= 0x2B;
                r->z = 0;
                r->n = 0;
                r->v = (((uint16_t)(sp0 - 3) ^ 6) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
                r->dp = (uint16_t)(sp0 - 9);
                r->sp -= 9;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8BDF, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8BDF); } /* wait_for_native_title_timer_with_pause_clear */
                r->sp += 9;
                uint16_t dp_ret9 = r->dp;
                if (r->mf != 0) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t y_ret8 = r->y;
                bool carry_ret9 = r->c;
                bool overflow_ret9 = r->v;
                RAM16_SET(0x1005D, 0xFFF8);
                uint8_t a4 = 0xF8;
                uint8_t a_hi4 = 0xFF;
                uint16_t y5 = y_ret8;
                bool carry4 = carry_ret9;
                bool overflow4 = overflow_ret9;
                uint16_t direct_page5 = dp_ret9;
                do {
                    r->a = (a_hi4 << 8) | a4;
                    r->x = 8;
                    r->y = y5;
                    r->c = carry4;
                    r->z = 0;
                    r->n = 0;
                    r->v = overflow4;
                    r->mf = 0;
                    r->xf = 0;
                    r->db = 0x7F;
                    r->dp = direct_page5;
                    r->sp -= 9;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8BEB, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8BEB); } /* wait_for_native_title_timer_with_pause_clear */
                    r->sp += 9;
                    uint16_t dp_ret10 = r->dp;
                    if (r->mf != 0) { c->fail = 3; return; }
                    if (r->xf != 0) { c->fail = 3; return; }
                    uint16_t a_all10 = r->a;
                    uint16_t y_ret9 = r->y;
                    bool carry_ret10 = r->c;
                    bool overflow_ret10 = r->v;
                    RAM16_SET(0x1005D, (uint16_t)(RAM16(0x1005D) + 1));
                    a4 = (uint8_t)a_all10;
                    a_hi4 = a_all10 >> 8;
                    y5 = y_ret9;
                    carry4 = carry_ret10;
                    overflow4 = overflow_ret10;
                    direct_page5 = dp_ret10;
                } while (RAM16(0x1005D) != 0);
                x_flag = 0;
                y7 = y5;
                direct_page7 = direct_page5;
            } else {
                BUS8_SET(c, 0x7F0003 + RAM16(0x10052), 0);
                BUS8_SET(c, 0x7F0003 + RAM16(0x10054), 2);
                r->a = ((uint16_t)(sp0 - 9) >> 8 << 8) | 2;
                r->x = 1;
                r->c = (uint8_t)(value + 1) >= 0x2B;
                r->z = 0;
                r->n = 0;
                r->v = (((uint16_t)(sp0 - 3) ^ 6) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
                r->dp = (uint16_t)(sp0 - 9);
                r->sp -= 9;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8C57, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8C57); } /* wait_for_native_title_timer_with_pause_clear */
                r->sp += 9;
                if (r->mf != 0) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                RAM16_SET(0x1005D, 0xFFF8);
                r->a = 0xFFF8;
                r->x = 1;
                r->z = 0;
                r->n = 0;
                r->sp -= 9;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8C63, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8C63); } /* wait_for_native_title_timer_with_pause_clear */
                r->sp += 9;
                uint16_t dp_ret12 = r->dp;
                if (r->mf != 0) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t y_ret11 = r->y;
                bool overflow_ret12 = r->v;
                RAM16_SET(0x1005D, 0xFFF8);
                BUS16_SET(c, (uint16_t)(dp_ret12 + 1), 0x20);
                BUS16_SET(c, (uint16_t)(dp_ret12 + 5), 0x40);
                uint8_t a5 = 0x40;
                uint8_t a_hi5 = 0;
                uint16_t y6 = y_ret11;
                bool carry5 = 0;
                bool overflow5 = overflow_ret12;
                uint16_t direct_page6 = dp_ret12;
                for (;;) {
                    r->a = (a_hi5 << 8) | a5;
                    r->x = 2;
                    r->y = y6;
                    r->c = carry5;
                    r->z = 0;
                    r->n = 0;
                    r->v = overflow5;
                    r->mf = 0;
                    r->xf = 0;
                    r->db = 0x7F;
                    r->dp = direct_page6;
                    r->sp -= 9;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8C77, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8C77); } /* wait_for_native_title_timer_with_pause_clear */
                    r->sp += 9;
                    uint16_t dp_ret13 = r->dp;
                    if (r->xf != 0) { c->fail = 3; return; }
                    uint16_t y_ret12 = r->y;
                    uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret13 + 5));
                    r->x = (uint16_t)(value13 - 2);
                    r->z = (uint16_t)(value13 - 2) == 0;
                    r->n = (uint16_t)(value13 - 2) & 0x8000;
                    r->sp -= 9;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8C7E, 0x7E8B15); GUARD_JSR(c, sp_call, 0x8C7E); } /* update_title_colour_at_offset4 */
                    r->sp += 9;
                    uint16_t dp_ret14 = r->dp;
                    if (r->mf != 0) { c->fail = 3; return; }
                    if (r->xf != 0) { c->fail = 3; return; }
                    uint16_t x_ret14 = r->x;
                    bool carry_ret14 = r->c;
                    bool overflow_ret14 = r->v;
                    BUS16_SET(c, (uint16_t)(dp_ret14 + 5), x_ret14);
                    uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret14 + 1));
                    if ((uint16_t)((value14 & 3) - 1) == 0) {
                        RAM16_SET(0x1005D, (uint16_t)(RAM16(0x1005D) + 1));
                    }
                    uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret14 + 1));
                    BUS16_RMW_SET(c, (uint16_t)(dp_ret14 + 1), (uint16_t)(value15 - 1));
                    a5 = (uint8_t)((value14 & 3) - 1);
                    a_hi5 = (uint16_t)((value14 & 3) - 1) >> 8;
                    y6 = y_ret12;
                    carry5 = carry_ret14;
                    overflow5 = overflow_ret14;
                    direct_page6 = dp_ret14;
                    if (!((uint16_t)(value15 - 1) != 0)) break;
                }
                uint16_t value16 = BUS16_RDP(c, (uint16_t)(direct_page6 + 3));
                r->a = (uint16_t)(value16 + 0x80);
                r->x = 0x019E;
                r->y = (uint16_t)(value16 + 0x80);
                r->c = value16 + 0x80 > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = ((value16 ^ (uint16_t)(value16 + 0x80)) & ((uint16_t)(value16 + 0x80) ^ 0x80) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                r->db = 0x7F;
                r->dp = direct_page6;
                r->sp -= 9;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8C9C, 0x7E8820); GUARD_JSR(c, sp_call, 0x8C9C); } /* expand_title_text_row */
                r->sp += 9;
                uint16_t dp_ret15 = r->dp;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret15 = r->xf;
                uint16_t y_ret13 = r->y;
                x_flag = x_ret15;
                y7 = y_ret13;
                direct_page7 = dp_ret15;
            }
            x_flag2 = x_flag;
            y8 = y7;
            direct_page8 = direct_page7;
        }
        x_flag3 = x_flag2;
        y9 = y8;
        direct_page9 = direct_page8;
    }
    uint8_t value17 = RAM8(0x0000 + sp0 - 2);
    uint8_t value18 = RAM8(0x0000 + sp0 - 1);
    uint8_t value19 = RAM8(0x0000 + sp0);
    r->y = y9;
    r->c = value17 & 0x01;
    r->v = value17 & 0x40;
    r->mf = value17 & 0x20;
    r->xf = value17 & 0x10;
    r->db = 0x7F;
    r->dp = (value19 << 8) | value18;
    r->i = value17 & 0x04;
    r->d = value17 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E8BA5, SOM_RTS, "gen", animate_title_text_row, 0, L_Y | L_C | L_V, 9, 0, 0, 257, 113)
