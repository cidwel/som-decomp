#include "som_c.h"

/* C19566 select_first_boss_auxiliary_tiles   [class D, 3176 bytes, 1347 instructions]
 * Source: src/rom/select_first_boss_auxiliary_tiles.s
 * Entry: M=16 bit X=8 bit DB=$00 D=$4300.  Callers read: ABXYCZNV.
 */
static void select_first_boss_auxiliary_tiles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x4300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 2;
    uint64_t loop_guard = 0;
    const uint16_t a = r->a;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t x1 = 0x0600;
    for (;;) {
        LOOP_GUARD(loop_guard);
        break;
    }
    uint8_t value = RAM8(0xE060 + x1);
    if (value == 0) {
        uint8_t value2 = RAM8(0x0000 + sp0 - 1);
        uint8_t value3 = RAM8(0x0000 + sp0);
        r->a = (a >> 8 << 8) | value;
        r->x = x1;
        r->y = y;
        r->c = carry;
        r->z = ((value3 << 8) | value2) == 0;
        r->n = ((value3 << 8) | value2) & 0x8000;
        r->v = overflow;
        r->xf = 0;
        r->dp = (value3 << 8) | value2;
        r->sp += 2;
        { const uint16_t sp_call = r->sp; JSL(c, 0x95BA, 0xC20009); GUARD_JSL(c, sp_call, 0x95BA); } /* upload_boss_frame_entry */
        r->sp -= 2;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        r->sp += 2;
        RETURN_RTL(c);
    }
    if (value & 0x80) {
        if (x1 == 0x0600) {
            uint8_t a1 = value;
            uint8_t a_hi1 = a >> 8;
            uint8_t y1 = y;
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint16_t value4 = RAM16(0xE684);
                a1 = (uint8_t)value4;
                a_hi1 = value4 >> 8;
                break;
            }
            uint8_t a_hi10;
            uint8_t y2;
            if ((uint8_t)((a_hi1 << 8) | a1) != 0) {
                BUS16_SET(c, 0x002116, 0x6C80);
                BUS16_SET(c, 0x004342, RAM16(0x0D60));
                BUS16_SET(c, 0x004352, RAM16(0x0D62));
                BUS16_SET(c, 0x004362, RAM16(0x0D68));
                BUS16_SET(c, 0x004372, RAM16(0x0D6A));
                BUS16_SET(c, 0x004344, 0x207E);
                BUS16_SET(c, 0x004354, 0x207E);
                BUS16_SET(c, 0x004364, 0x207E);
                BUS16_SET(c, 0x004374, 0x207E);
                BUS8_SET(c, 0x00420B, 0xF0);
                BUS16_SET(c, 0x002116, 0x6D80);
                BUS16_SET(c, 0x004342, RAM16(0x0D64));
                BUS16_SET(c, 0x004352, RAM16(0x0D66));
                BUS16_SET(c, 0x004362, RAM16(0x0D6C));
                uint16_t value12 = RAM16(0x0D6E);
                BUS16_SET(c, 0x004372, value12);
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                uint8_t a_hi9;
                if ((uint8_t)((uint8_t)((a_hi1 << 8) | a1) - 1) != 0) {
                    uint8_t a_hi8;
                    if ((uint8_t)((uint8_t)((a_hi1 << 8) | a1) - 2) == 0) {
                        a_hi8 = value12 >> 8;
                    } else {
                        BUS16_SET(c, 0x002116, 0x6CC0);
                        BUS16_SET(c, 0x004342, RAM16(0x0D70));
                        BUS16_SET(c, 0x004352, RAM16(0x0D72));
                        BUS16_SET(c, 0x004362, RAM16(0x0D78));
                        BUS16_SET(c, 0x004372, RAM16(0x0D7A));
                        BUS8_SET(c, 0x004345, 0x20);
                        BUS8_SET(c, 0x004355, 0x20);
                        BUS8_SET(c, 0x004365, 0x20);
                        BUS8_SET(c, 0x004375, 0x20);
                        BUS8_SET(c, 0x00420B, 0xF0);
                        BUS16_SET(c, 0x002116, 0x6DC0);
                        BUS16_SET(c, 0x004342, RAM16(0x0D74));
                        BUS16_SET(c, 0x004352, RAM16(0x0D76));
                        BUS16_SET(c, 0x004362, RAM16(0x0D7C));
                        uint16_t value20 = RAM16(0x0D7E);
                        BUS16_SET(c, 0x004372, value20);
                        BUS8_SET(c, 0x004345, 0x20);
                        BUS8_SET(c, 0x004355, 0x20);
                        BUS8_SET(c, 0x004365, 0x20);
                        BUS8_SET(c, 0x004375, 0x20);
                        BUS8_SET(c, 0x00420B, 0xF0);
                        uint8_t a_hi7;
                        if ((uint8_t)((uint8_t)((a_hi1 << 8) | a1) - 3) != 0) {
                            uint8_t a_hi6;
                            if ((uint8_t)((uint8_t)((a_hi1 << 8) | a1) - 4) == 0) {
                                a_hi6 = value20 >> 8;
                            } else {
                                BUS16_SET(c, 0x002116, 0x6E00);
                                BUS16_SET(c, 0x004342, RAM16(0x0D80));
                                BUS16_SET(c, 0x004352, RAM16(0x0D82));
                                BUS16_SET(c, 0x004362, RAM16(0x0D88));
                                BUS16_SET(c, 0x004372, RAM16(0x0D8A));
                                BUS8_SET(c, 0x004345, 0x20);
                                BUS8_SET(c, 0x004355, 0x20);
                                BUS8_SET(c, 0x004365, 0x20);
                                BUS8_SET(c, 0x004375, 0x20);
                                BUS8_SET(c, 0x00420B, 0xF0);
                                BUS16_SET(c, 0x002116, 0x6F00);
                                BUS16_SET(c, 0x004342, RAM16(0x0D84));
                                BUS16_SET(c, 0x004352, RAM16(0x0D86));
                                BUS16_SET(c, 0x004362, RAM16(0x0D8C));
                                uint16_t value28 = RAM16(0x0D8E);
                                BUS16_SET(c, 0x004372, value28);
                                BUS8_SET(c, 0x004345, 0x20);
                                BUS8_SET(c, 0x004355, 0x20);
                                BUS8_SET(c, 0x004365, 0x20);
                                BUS8_SET(c, 0x004375, 0x20);
                                BUS8_SET(c, 0x00420B, 0xF0);
                                uint8_t a_hi5;
                                if ((uint8_t)((uint8_t)((a_hi1 << 8) | a1) - 5) != 0) {
                                    uint8_t a_hi4;
                                    if ((uint8_t)((uint8_t)((a_hi1 << 8) | a1) - 6) == 0) {
                                        a_hi4 = value28 >> 8;
                                    } else {
                                        BUS16_SET(c, 0x002116, 0x6E40);
                                        BUS16_SET(c, 0x004342, RAM16(0x0D90));
                                        BUS16_SET(c, 0x004352, RAM16(0x0D92));
                                        BUS16_SET(c, 0x004362, RAM16(0x0D98));
                                        BUS16_SET(c, 0x004372, RAM16(0x0D9A));
                                        BUS8_SET(c, 0x004345, 0x20);
                                        BUS8_SET(c, 0x004355, 0x20);
                                        BUS8_SET(c, 0x004365, 0x20);
                                        BUS8_SET(c, 0x004375, 0x20);
                                        BUS8_SET(c, 0x00420B, 0xF0);
                                        BUS16_SET(c, 0x002116, 0x6F40);
                                        BUS16_SET(c, 0x004342, RAM16(0x0D94));
                                        BUS16_SET(c, 0x004352, RAM16(0x0D96));
                                        BUS16_SET(c, 0x004362, RAM16(0x0D9C));
                                        uint16_t value36 = RAM16(0x0D9E);
                                        BUS16_SET(c, 0x004372, value36);
                                        BUS8_SET(c, 0x004345, 0x20);
                                        BUS8_SET(c, 0x004355, 0x20);
                                        BUS8_SET(c, 0x004365, 0x20);
                                        BUS8_SET(c, 0x004375, 0x20);
                                        BUS8_SET(c, 0x00420B, 0xF0);
                                        uint8_t a_hi3;
                                        if ((uint8_t)((uint8_t)((a_hi1 << 8) | a1) - 7) == 0) {
                                            a_hi3 = value36 >> 8;
                                        } else {
                                            uint8_t a_hi2;
                                            if ((uint8_t)((uint8_t)((a_hi1 << 8) | a1) - 8) == 0) {
                                                a_hi2 = value36 >> 8;
                                            } else {
                                                BUS16_SET(c, 0x002116, 0x6E80);
                                                BUS16_SET(c, 0x004342, RAM16(0x0DA0));
                                                BUS16_SET(c, 0x004352, RAM16(0x0DA2));
                                                BUS16_SET(c, 0x004362, RAM16(0x0DA8));
                                                BUS16_SET(c, 0x004372, RAM16(0x0DAA));
                                                BUS8_SET(c, 0x004345, 0x20);
                                                BUS8_SET(c, 0x004355, 0x20);
                                                BUS8_SET(c, 0x004365, 0x20);
                                                BUS8_SET(c, 0x004375, 0x20);
                                                BUS8_SET(c, 0x00420B, 0xF0);
                                                BUS16_SET(c, 0x002116, 0x6F80);
                                                BUS16_SET(c, 0x004342, RAM16(0x0DA4));
                                                BUS16_SET(c, 0x004352, RAM16(0x0DA6));
                                                BUS16_SET(c, 0x004362, RAM16(0x0DAC));
                                                uint16_t value44 = RAM16(0x0DAE);
                                                BUS16_SET(c, 0x004372, value44);
                                                BUS8_SET(c, 0x004345, 0x20);
                                                BUS8_SET(c, 0x004355, 0x20);
                                                BUS8_SET(c, 0x004365, 0x20);
                                                BUS8_SET(c, 0x004375, 0x20);
                                                BUS8_SET(c, 0x00420B, 0xF0);
                                                a_hi2 = value44 >> 8;
                                            }
                                            a_hi3 = a_hi2;
                                        }
                                        a_hi4 = a_hi3;
                                    }
                                    a_hi5 = a_hi4;
                                } else {
                                    a_hi5 = value28 >> 8;
                                }
                                a_hi6 = a_hi5;
                            }
                            a_hi7 = a_hi6;
                        } else {
                            a_hi7 = value20 >> 8;
                        }
                        a_hi8 = a_hi7;
                    }
                    a_hi9 = a_hi8;
                } else {
                    a_hi9 = value12 >> 8;
                }
                a_hi10 = a_hi9;
                y2 = 0xF0;
            } else {
                a_hi10 = a_hi1;
                y2 = y1;
            }
            uint16_t value45 = RAM16(0xE68D);
            uint8_t a3;
            uint8_t a_hi12;
            uint8_t x3;
            uint8_t y4;
            bool zero2;
            bool negative2;
            if ((uint8_t)value45 == 0) {
                a3 = (uint8_t)value45;
                a_hi12 = value45 >> 8;
                x3 = (uint8_t)value45;
                y4 = y2;
                zero2 = (uint8_t)value45 == 0;
                negative2 = (uint8_t)value45 & 0x80;
            } else {
                RAM16_SET(0xE68D, value45 & 0xFF00);
                uint8_t a2 = (uint8_t)(value45 & 0xFF00);
                uint8_t a_hi11 = (value45 & 0xFF00) >> 8;
                uint8_t x2 = 4;
                uint8_t y3 = y2;
                bool zero1 = 0;
                bool negative1 = 0;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    BUS16_SET(c, 0x002116, 0x6E80);
                    BUS16_SET(c, 0x004342, RAM16(0x0DA0));
                    BUS16_SET(c, 0x004352, RAM16(0x0DA2));
                    BUS16_SET(c, 0x004362, RAM16(0x0DA8));
                    BUS16_SET(c, 0x004372, RAM16(0x0DAA));
                    BUS8_SET(c, 0x004345, 0x20);
                    BUS8_SET(c, 0x004355, 0x20);
                    BUS8_SET(c, 0x004365, 0x20);
                    BUS8_SET(c, 0x004375, 0x20);
                    BUS8_SET(c, 0x00420B, 0xF0);
                    BUS16_SET(c, 0x002116, 0x6F80);
                    BUS16_SET(c, 0x004342, RAM16(0x0DA4));
                    BUS16_SET(c, 0x004352, RAM16(0x0DA6));
                    BUS16_SET(c, 0x004362, RAM16(0x0DAC));
                    BUS16_SET(c, 0x004372, RAM16(0x0DAE));
                    BUS8_SET(c, 0x004345, 0x20);
                    BUS8_SET(c, 0x004355, 0x20);
                    BUS8_SET(c, 0x004365, 0x20);
                    BUS8_SET(c, 0x004375, 0x20);
                    BUS8_SET(c, 0x00420B, 0xF0);
                    uint16_t value54 = RAM16(0xE68D);
                    if ((uint8_t)value54 != 0) {
                        RAM16_SET(0xE68D, value54 & 0xFF00);
                        a2 = (uint8_t)(value54 & 0xFF00);
                        a_hi11 = (value54 & 0xFF00) >> 8;
                        x2 = 4;
                        y3 = 0xF0;
                        zero1 = 0;
                        negative1 = 0;
                        continue;
                    }
                    a2 = (uint8_t)value54;
                    a_hi11 = value54 >> 8;
                    x2 = (uint8_t)value54;
                    y3 = 0xF0;
                    zero1 = (uint8_t)value54 == 0;
                    negative1 = (uint8_t)value54 & 0x80;
                    break;
                }
                a3 = a2;
                a_hi12 = a_hi11;
                x3 = x2;
                y4 = y3;
                zero2 = zero1;
                negative2 = negative1;
            }
            uint8_t value55 = RAM8(0x0000 + sp0 - 1);
            uint8_t value56 = RAM8(0x0000 + sp0);
            r->a = (a_hi12 << 8) | a3;
            r->x = x3;
            r->y = y4;
            r->c = x1 >= 0x0600;
            r->z = ((value56 << 8) | value55) == 0;
            r->n = ((value56 << 8) | value55) & 0x8000;
            r->v = overflow;
            r->dp = (value56 << 8) | value55;
            r->sp += 2;
            RETURN_RTL(c);
        }
        if (x1 == 0x0800) {
            uint8_t a4 = value;
            uint8_t a_hi13 = a >> 8;
            uint8_t y5 = y;
            for (;;) {
                LOOP_GUARD(loop_guard);
                uint16_t value57 = RAM16(0xE884);
                a4 = (uint8_t)value57;
                a_hi13 = value57 >> 8;
                break;
            }
            uint8_t a_hi22;
            uint8_t y6;
            if ((uint8_t)((a_hi13 << 8) | a4) != 0) {
                BUS16_SET(c, 0x002116, 0x6EC0);
                BUS16_SET(c, 0x004342, RAM16(0x0DB0));
                BUS16_SET(c, 0x004352, RAM16(0x0DB2));
                BUS16_SET(c, 0x004362, RAM16(0x0DB8));
                BUS16_SET(c, 0x004372, RAM16(0x0DBA));
                BUS16_SET(c, 0x004344, 0x207E);
                BUS16_SET(c, 0x004354, 0x207E);
                BUS16_SET(c, 0x004364, 0x207E);
                BUS16_SET(c, 0x004374, 0x207E);
                BUS8_SET(c, 0x00420B, 0xF0);
                BUS16_SET(c, 0x002116, 0x6FC0);
                BUS16_SET(c, 0x004342, RAM16(0x0DB4));
                BUS16_SET(c, 0x004352, RAM16(0x0DB6));
                BUS16_SET(c, 0x004362, RAM16(0x0DBC));
                uint16_t value65 = RAM16(0x0DBE);
                BUS16_SET(c, 0x004372, value65);
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                uint8_t a_hi21;
                if ((uint8_t)((uint8_t)((a_hi13 << 8) | a4) - 1) != 0) {
                    uint8_t a_hi20;
                    if ((uint8_t)((uint8_t)((a_hi13 << 8) | a4) - 2) == 0) {
                        a_hi20 = value65 >> 8;
                    } else {
                        BUS16_SET(c, 0x002116, 0x7000);
                        BUS16_SET(c, 0x004342, RAM16(0x0DC0));
                        BUS16_SET(c, 0x004352, RAM16(0x0DC2));
                        BUS16_SET(c, 0x004362, RAM16(0x0DC8));
                        BUS16_SET(c, 0x004372, RAM16(0x0DCA));
                        BUS8_SET(c, 0x004345, 0x20);
                        BUS8_SET(c, 0x004355, 0x20);
                        BUS8_SET(c, 0x004365, 0x20);
                        BUS8_SET(c, 0x004375, 0x20);
                        BUS8_SET(c, 0x00420B, 0xF0);
                        BUS16_SET(c, 0x002116, 0x7100);
                        BUS16_SET(c, 0x004342, RAM16(0x0DC4));
                        BUS16_SET(c, 0x004352, RAM16(0x0DC6));
                        BUS16_SET(c, 0x004362, RAM16(0x0DCC));
                        uint16_t value73 = RAM16(0x0DCE);
                        BUS16_SET(c, 0x004372, value73);
                        BUS8_SET(c, 0x004345, 0x20);
                        BUS8_SET(c, 0x004355, 0x20);
                        BUS8_SET(c, 0x004365, 0x20);
                        BUS8_SET(c, 0x004375, 0x20);
                        BUS8_SET(c, 0x00420B, 0xF0);
                        uint8_t a_hi19;
                        if ((uint8_t)((uint8_t)((a_hi13 << 8) | a4) - 3) != 0) {
                            uint8_t a_hi18;
                            if ((uint8_t)((uint8_t)((a_hi13 << 8) | a4) - 4) == 0) {
                                a_hi18 = value73 >> 8;
                            } else {
                                BUS16_SET(c, 0x002116, 0x7040);
                                BUS16_SET(c, 0x004342, RAM16(0x0DD0));
                                BUS16_SET(c, 0x004352, RAM16(0x0DD2));
                                BUS16_SET(c, 0x004362, RAM16(0x0DD8));
                                BUS16_SET(c, 0x004372, RAM16(0x0DDA));
                                BUS8_SET(c, 0x004345, 0x20);
                                BUS8_SET(c, 0x004355, 0x20);
                                BUS8_SET(c, 0x004365, 0x20);
                                BUS8_SET(c, 0x004375, 0x20);
                                BUS8_SET(c, 0x00420B, 0xF0);
                                BUS16_SET(c, 0x002116, 0x7140);
                                BUS16_SET(c, 0x004342, RAM16(0x0DD4));
                                BUS16_SET(c, 0x004352, RAM16(0x0DD6));
                                BUS16_SET(c, 0x004362, RAM16(0x0DDC));
                                uint16_t value81 = RAM16(0x0DDE);
                                BUS16_SET(c, 0x004372, value81);
                                BUS8_SET(c, 0x004345, 0x20);
                                BUS8_SET(c, 0x004355, 0x20);
                                BUS8_SET(c, 0x004365, 0x20);
                                BUS8_SET(c, 0x004375, 0x20);
                                BUS8_SET(c, 0x00420B, 0xF0);
                                uint8_t a_hi17;
                                if ((uint8_t)((uint8_t)((a_hi13 << 8) | a4) - 5) != 0) {
                                    uint8_t a_hi16;
                                    if ((uint8_t)((uint8_t)((a_hi13 << 8) | a4) - 6) == 0) {
                                        a_hi16 = value81 >> 8;
                                    } else {
                                        BUS16_SET(c, 0x002116, 0x7080);
                                        BUS16_SET(c, 0x004342, RAM16(0x0DE0));
                                        BUS16_SET(c, 0x004352, RAM16(0x0DE2));
                                        BUS16_SET(c, 0x004362, RAM16(0x0DE8));
                                        BUS16_SET(c, 0x004372, RAM16(0x0DEA));
                                        BUS8_SET(c, 0x004345, 0x20);
                                        BUS8_SET(c, 0x004355, 0x20);
                                        BUS8_SET(c, 0x004365, 0x20);
                                        BUS8_SET(c, 0x004375, 0x20);
                                        BUS8_SET(c, 0x00420B, 0xF0);
                                        BUS16_SET(c, 0x002116, 0x7180);
                                        BUS16_SET(c, 0x004342, RAM16(0x0DE4));
                                        BUS16_SET(c, 0x004352, RAM16(0x0DE6));
                                        BUS16_SET(c, 0x004362, RAM16(0x0DEC));
                                        uint16_t value89 = RAM16(0x0DEE);
                                        BUS16_SET(c, 0x004372, value89);
                                        BUS8_SET(c, 0x004345, 0x20);
                                        BUS8_SET(c, 0x004355, 0x20);
                                        BUS8_SET(c, 0x004365, 0x20);
                                        BUS8_SET(c, 0x004375, 0x20);
                                        BUS8_SET(c, 0x00420B, 0xF0);
                                        uint8_t a_hi15;
                                        if ((uint8_t)((uint8_t)((a_hi13 << 8) | a4) - 7) == 0) {
                                            a_hi15 = value89 >> 8;
                                        } else {
                                            uint8_t a_hi14;
                                            if ((uint8_t)((uint8_t)((a_hi13 << 8) | a4) - 8) == 0) {
                                                a_hi14 = value89 >> 8;
                                            } else {
                                                BUS16_SET(c, 0x002116, 0x70C0);
                                                BUS16_SET(c, 0x004342, RAM16(0x0DF0));
                                                BUS16_SET(c, 0x004352, RAM16(0x0DF2));
                                                BUS16_SET(c, 0x004362, RAM16(0x0DF8));
                                                BUS16_SET(c, 0x004372, RAM16(0x0DFA));
                                                BUS8_SET(c, 0x004345, 0x20);
                                                BUS8_SET(c, 0x004355, 0x20);
                                                BUS8_SET(c, 0x004365, 0x20);
                                                BUS8_SET(c, 0x004375, 0x20);
                                                BUS8_SET(c, 0x00420B, 0xF0);
                                                BUS16_SET(c, 0x002116, 0x71C0);
                                                BUS16_SET(c, 0x004342, RAM16(0x0DF4));
                                                BUS16_SET(c, 0x004352, RAM16(0x0DF6));
                                                BUS16_SET(c, 0x004362, RAM16(0x0DFC));
                                                uint16_t value97 = RAM16(0x0DFE);
                                                BUS16_SET(c, 0x004372, value97);
                                                BUS8_SET(c, 0x004345, 0x20);
                                                BUS8_SET(c, 0x004355, 0x20);
                                                BUS8_SET(c, 0x004365, 0x20);
                                                BUS8_SET(c, 0x004375, 0x20);
                                                BUS8_SET(c, 0x00420B, 0xF0);
                                                a_hi14 = value97 >> 8;
                                            }
                                            a_hi15 = a_hi14;
                                        }
                                        a_hi16 = a_hi15;
                                    }
                                    a_hi17 = a_hi16;
                                } else {
                                    a_hi17 = value81 >> 8;
                                }
                                a_hi18 = a_hi17;
                            }
                            a_hi19 = a_hi18;
                        } else {
                            a_hi19 = value73 >> 8;
                        }
                        a_hi20 = a_hi19;
                    }
                    a_hi21 = a_hi20;
                } else {
                    a_hi21 = value65 >> 8;
                }
                a_hi22 = a_hi21;
                y6 = 0xF0;
            } else {
                a_hi22 = a_hi13;
                y6 = y5;
            }
            uint16_t value98 = RAM16(0xE88D);
            uint8_t a6;
            uint8_t a_hi24;
            uint8_t x5;
            uint8_t y8;
            bool zero4;
            bool negative4;
            if ((uint8_t)value98 == 0) {
                a6 = (uint8_t)value98;
                a_hi24 = value98 >> 8;
                x5 = (uint8_t)value98;
                y8 = y6;
                zero4 = (uint8_t)value98 == 0;
                negative4 = (uint8_t)value98 & 0x80;
            } else {
                RAM16_SET(0xE88D, value98 & 0xFF00);
                uint8_t a5 = (uint8_t)(value98 & 0xFF00);
                uint8_t a_hi23 = (value98 & 0xFF00) >> 8;
                uint8_t x4 = 4;
                uint8_t y7 = y6;
                bool zero3 = 0;
                bool negative3 = 0;
                for (;;) {
                    LOOP_GUARD(loop_guard);
                    BUS16_SET(c, 0x002116, 0x70C0);
                    BUS16_SET(c, 0x004342, RAM16(0x0DF0));
                    BUS16_SET(c, 0x004352, RAM16(0x0DF2));
                    BUS16_SET(c, 0x004362, RAM16(0x0DF8));
                    BUS16_SET(c, 0x004372, RAM16(0x0DFA));
                    BUS8_SET(c, 0x004345, 0x20);
                    BUS8_SET(c, 0x004355, 0x20);
                    BUS8_SET(c, 0x004365, 0x20);
                    BUS8_SET(c, 0x004375, 0x20);
                    BUS8_SET(c, 0x00420B, 0xF0);
                    BUS16_SET(c, 0x002116, 0x71C0);
                    BUS16_SET(c, 0x004342, RAM16(0x0DF4));
                    BUS16_SET(c, 0x004352, RAM16(0x0DF6));
                    BUS16_SET(c, 0x004362, RAM16(0x0DFC));
                    BUS16_SET(c, 0x004372, RAM16(0x0DFE));
                    BUS8_SET(c, 0x004345, 0x20);
                    BUS8_SET(c, 0x004355, 0x20);
                    BUS8_SET(c, 0x004365, 0x20);
                    BUS8_SET(c, 0x004375, 0x20);
                    BUS8_SET(c, 0x00420B, 0xF0);
                    uint16_t value107 = RAM16(0xE88D);
                    if ((uint8_t)value107 != 0) {
                        RAM16_SET(0xE88D, value107 & 0xFF00);
                        a5 = (uint8_t)(value107 & 0xFF00);
                        a_hi23 = (value107 & 0xFF00) >> 8;
                        x4 = 4;
                        y7 = 0xF0;
                        zero3 = 0;
                        negative3 = 0;
                        continue;
                    }
                    a5 = (uint8_t)value107;
                    a_hi23 = value107 >> 8;
                    x4 = (uint8_t)value107;
                    y7 = 0xF0;
                    zero3 = (uint8_t)value107 == 0;
                    negative3 = (uint8_t)value107 & 0x80;
                    break;
                }
                a6 = a5;
                a_hi24 = a_hi23;
                x5 = x4;
                y8 = y7;
                zero4 = zero3;
                negative4 = negative3;
            }
            uint8_t value108 = RAM8(0x0000 + sp0 - 1);
            uint8_t value109 = RAM8(0x0000 + sp0);
            r->a = (a_hi24 << 8) | a6;
            r->x = x5;
            r->y = y8;
            r->c = x1 >= 0x0800;
            r->z = ((value109 << 8) | value108) == 0;
            r->n = ((value109 << 8) | value108) & 0x8000;
            r->v = overflow;
            r->dp = (value109 << 8) | value108;
            r->sp += 2;
            RETURN_RTL(c);
        }
        uint8_t a7 = value;
        uint8_t a_hi25 = a >> 8;
        uint8_t y9 = y;
        for (;;) {
            LOOP_GUARD(loop_guard);
            uint16_t value110 = RAM16(0xEA84);
            a7 = (uint8_t)value110;
            a_hi25 = value110 >> 8;
            break;
        }
        uint8_t a_hi34;
        uint8_t y10;
        if ((uint8_t)((a_hi25 << 8) | a7) != 0) {
            BUS16_SET(c, 0x002116, 0x7200);
            BUS16_SET(c, 0x004342, RAM16(0x0E00));
            BUS16_SET(c, 0x004352, RAM16(0x0E02));
            BUS16_SET(c, 0x004362, RAM16(0x0E08));
            BUS16_SET(c, 0x004372, RAM16(0x0E0A));
            BUS16_SET(c, 0x004344, 0x207E);
            BUS16_SET(c, 0x004354, 0x207E);
            BUS16_SET(c, 0x004364, 0x207E);
            BUS16_SET(c, 0x004374, 0x207E);
            BUS8_SET(c, 0x00420B, 0xF0);
            BUS16_SET(c, 0x002116, 0x7300);
            BUS16_SET(c, 0x004342, RAM16(0x0E04));
            BUS16_SET(c, 0x004352, RAM16(0x0E06));
            BUS16_SET(c, 0x004362, RAM16(0x0E0C));
            uint16_t value118 = RAM16(0x0E0E);
            BUS16_SET(c, 0x004372, value118);
            BUS8_SET(c, 0x004345, 0x20);
            BUS8_SET(c, 0x004355, 0x20);
            BUS8_SET(c, 0x004365, 0x20);
            BUS8_SET(c, 0x004375, 0x20);
            BUS8_SET(c, 0x00420B, 0xF0);
            uint8_t a_hi33;
            if ((uint8_t)((uint8_t)((a_hi25 << 8) | a7) - 1) != 0) {
                uint8_t a_hi32;
                if ((uint8_t)((uint8_t)((a_hi25 << 8) | a7) - 2) == 0) {
                    a_hi32 = value118 >> 8;
                } else {
                    BUS16_SET(c, 0x002116, 0x7240);
                    BUS16_SET(c, 0x004342, RAM16(0x0E10));
                    BUS16_SET(c, 0x004352, RAM16(0x0E12));
                    BUS16_SET(c, 0x004362, RAM16(0x0E18));
                    BUS16_SET(c, 0x004372, RAM16(0x0E1A));
                    BUS8_SET(c, 0x004345, 0x20);
                    BUS8_SET(c, 0x004355, 0x20);
                    BUS8_SET(c, 0x004365, 0x20);
                    BUS8_SET(c, 0x004375, 0x20);
                    BUS8_SET(c, 0x00420B, 0xF0);
                    BUS16_SET(c, 0x002116, 0x7340);
                    BUS16_SET(c, 0x004342, RAM16(0x0E14));
                    BUS16_SET(c, 0x004352, RAM16(0x0E16));
                    BUS16_SET(c, 0x004362, RAM16(0x0E1C));
                    uint16_t value126 = RAM16(0x0E1E);
                    BUS16_SET(c, 0x004372, value126);
                    BUS8_SET(c, 0x004345, 0x20);
                    BUS8_SET(c, 0x004355, 0x20);
                    BUS8_SET(c, 0x004365, 0x20);
                    BUS8_SET(c, 0x004375, 0x20);
                    BUS8_SET(c, 0x00420B, 0xF0);
                    uint8_t a_hi31;
                    if ((uint8_t)((uint8_t)((a_hi25 << 8) | a7) - 3) != 0) {
                        uint8_t a_hi30;
                        if ((uint8_t)((uint8_t)((a_hi25 << 8) | a7) - 4) == 0) {
                            a_hi30 = value126 >> 8;
                        } else {
                            BUS16_SET(c, 0x002116, 0x7280);
                            BUS16_SET(c, 0x004342, RAM16(0x0E20));
                            BUS16_SET(c, 0x004352, RAM16(0x0E22));
                            BUS16_SET(c, 0x004362, RAM16(0x0E28));
                            BUS16_SET(c, 0x004372, RAM16(0x0E2A));
                            BUS8_SET(c, 0x004345, 0x20);
                            BUS8_SET(c, 0x004355, 0x20);
                            BUS8_SET(c, 0x004365, 0x20);
                            BUS8_SET(c, 0x004375, 0x20);
                            BUS8_SET(c, 0x00420B, 0xF0);
                            BUS16_SET(c, 0x002116, 0x7380);
                            BUS16_SET(c, 0x004342, RAM16(0x0E24));
                            BUS16_SET(c, 0x004352, RAM16(0x0E26));
                            BUS16_SET(c, 0x004362, RAM16(0x0E2C));
                            uint16_t value134 = RAM16(0x0E2E);
                            BUS16_SET(c, 0x004372, value134);
                            BUS8_SET(c, 0x004345, 0x20);
                            BUS8_SET(c, 0x004355, 0x20);
                            BUS8_SET(c, 0x004365, 0x20);
                            BUS8_SET(c, 0x004375, 0x20);
                            BUS8_SET(c, 0x00420B, 0xF0);
                            uint8_t a_hi29;
                            if ((uint8_t)((uint8_t)((a_hi25 << 8) | a7) - 5) != 0) {
                                uint8_t a_hi28;
                                if ((uint8_t)((uint8_t)((a_hi25 << 8) | a7) - 6) == 0) {
                                    a_hi28 = value134 >> 8;
                                } else {
                                    BUS16_SET(c, 0x002116, 0x72C0);
                                    BUS16_SET(c, 0x004342, RAM16(0x0E30));
                                    BUS16_SET(c, 0x004352, RAM16(0x0E32));
                                    BUS16_SET(c, 0x004362, RAM16(0x0E38));
                                    BUS16_SET(c, 0x004372, RAM16(0x0E3A));
                                    BUS8_SET(c, 0x004345, 0x20);
                                    BUS8_SET(c, 0x004355, 0x20);
                                    BUS8_SET(c, 0x004365, 0x20);
                                    BUS8_SET(c, 0x004375, 0x20);
                                    BUS8_SET(c, 0x00420B, 0xF0);
                                    BUS16_SET(c, 0x002116, 0x73C0);
                                    BUS16_SET(c, 0x004342, RAM16(0x0E34));
                                    BUS16_SET(c, 0x004352, RAM16(0x0E36));
                                    BUS16_SET(c, 0x004362, RAM16(0x0E3C));
                                    uint16_t value142 = RAM16(0x0E3E);
                                    BUS16_SET(c, 0x004372, value142);
                                    BUS8_SET(c, 0x004345, 0x20);
                                    BUS8_SET(c, 0x004355, 0x20);
                                    BUS8_SET(c, 0x004365, 0x20);
                                    BUS8_SET(c, 0x004375, 0x20);
                                    BUS8_SET(c, 0x00420B, 0xF0);
                                    uint8_t a_hi27;
                                    if ((uint8_t)((uint8_t)((a_hi25 << 8) | a7) - 7) == 0) {
                                        a_hi27 = value142 >> 8;
                                    } else {
                                        uint8_t a_hi26;
                                        if ((uint8_t)((uint8_t)((a_hi25 << 8) | a7) - 8) == 0) {
                                            a_hi26 = value142 >> 8;
                                        } else {
                                            BUS16_SET(c, 0x002116, 0x7400);
                                            BUS16_SET(c, 0x004342, RAM16(0x0E40));
                                            BUS16_SET(c, 0x004352, RAM16(0x0E42));
                                            BUS16_SET(c, 0x004362, RAM16(0x0E48));
                                            BUS16_SET(c, 0x004372, RAM16(0x0E4A));
                                            BUS8_SET(c, 0x004345, 0x20);
                                            BUS8_SET(c, 0x004355, 0x20);
                                            BUS8_SET(c, 0x004365, 0x20);
                                            BUS8_SET(c, 0x004375, 0x20);
                                            BUS8_SET(c, 0x00420B, 0xF0);
                                            BUS16_SET(c, 0x002116, 0x7500);
                                            BUS16_SET(c, 0x004342, RAM16(0x0E44));
                                            BUS16_SET(c, 0x004352, RAM16(0x0E46));
                                            BUS16_SET(c, 0x004362, RAM16(0x0E4C));
                                            uint16_t value150 = RAM16(0x0E4E);
                                            BUS16_SET(c, 0x004372, value150);
                                            BUS8_SET(c, 0x004345, 0x20);
                                            BUS8_SET(c, 0x004355, 0x20);
                                            BUS8_SET(c, 0x004365, 0x20);
                                            BUS8_SET(c, 0x004375, 0x20);
                                            BUS8_SET(c, 0x00420B, 0xF0);
                                            a_hi26 = value150 >> 8;
                                        }
                                        a_hi27 = a_hi26;
                                    }
                                    a_hi28 = a_hi27;
                                }
                                a_hi29 = a_hi28;
                            } else {
                                a_hi29 = value134 >> 8;
                            }
                            a_hi30 = a_hi29;
                        }
                        a_hi31 = a_hi30;
                    } else {
                        a_hi31 = value126 >> 8;
                    }
                    a_hi32 = a_hi31;
                }
                a_hi33 = a_hi32;
            } else {
                a_hi33 = value118 >> 8;
            }
            a_hi34 = a_hi33;
            y10 = 0xF0;
        } else {
            a_hi34 = a_hi25;
            y10 = y9;
        }
        uint16_t value151 = RAM16(0xEA8D);
        uint8_t a9;
        uint8_t a_hi36;
        uint8_t x7;
        uint8_t y12;
        bool zero6;
        bool negative6;
        if ((uint8_t)value151 == 0) {
            a9 = (uint8_t)value151;
            a_hi36 = value151 >> 8;
            x7 = (uint8_t)value151;
            y12 = y10;
            zero6 = (uint8_t)value151 == 0;
            negative6 = (uint8_t)value151 & 0x80;
        } else {
            RAM16_SET(0xEA8D, value151 & 0xFF00);
            uint8_t a8 = (uint8_t)(value151 & 0xFF00);
            uint8_t a_hi35 = (value151 & 0xFF00) >> 8;
            uint8_t x6 = 4;
            uint8_t y11 = y10;
            bool zero5 = 0;
            bool negative5 = 0;
            for (;;) {
                LOOP_GUARD(loop_guard);
                BUS16_SET(c, 0x002116, 0x7400);
                BUS16_SET(c, 0x004342, RAM16(0x0E40));
                BUS16_SET(c, 0x004352, RAM16(0x0E42));
                BUS16_SET(c, 0x004362, RAM16(0x0E48));
                BUS16_SET(c, 0x004372, RAM16(0x0E4A));
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                BUS16_SET(c, 0x002116, 0x7500);
                BUS16_SET(c, 0x004342, RAM16(0x0E44));
                BUS16_SET(c, 0x004352, RAM16(0x0E46));
                BUS16_SET(c, 0x004362, RAM16(0x0E4C));
                BUS16_SET(c, 0x004372, RAM16(0x0E4E));
                BUS8_SET(c, 0x004345, 0x20);
                BUS8_SET(c, 0x004355, 0x20);
                BUS8_SET(c, 0x004365, 0x20);
                BUS8_SET(c, 0x004375, 0x20);
                BUS8_SET(c, 0x00420B, 0xF0);
                uint16_t value160 = RAM16(0xEA8D);
                if ((uint8_t)value160 != 0) {
                    RAM16_SET(0xEA8D, value160 & 0xFF00);
                    a8 = (uint8_t)(value160 & 0xFF00);
                    a_hi35 = (value160 & 0xFF00) >> 8;
                    x6 = 4;
                    y11 = 0xF0;
                    zero5 = 0;
                    negative5 = 0;
                    continue;
                }
                a8 = (uint8_t)value160;
                a_hi35 = value160 >> 8;
                x6 = (uint8_t)value160;
                y11 = 0xF0;
                zero5 = (uint8_t)value160 == 0;
                negative5 = (uint8_t)value160 & 0x80;
                break;
            }
            a9 = a8;
            a_hi36 = a_hi35;
            x7 = x6;
            y12 = y11;
            zero6 = zero5;
            negative6 = negative5;
        }
        uint8_t value161 = RAM8(0x0000 + sp0 - 1);
        uint8_t value162 = RAM8(0x0000 + sp0);
        r->a = (a_hi36 << 8) | a9;
        r->x = x7;
        r->y = y12;
        r->c = x1 >= 0x0800;
        r->z = ((value162 << 8) | value161) == 0;
        r->n = ((value162 << 8) | value161) & 0x8000;
        r->v = overflow;
        r->dp = (value162 << 8) | value161;
        r->sp += 2;
        RETURN_RTL(c);
    }
    uint8_t value163 = RAM8(0xE061 + x1);
    if (value163 == 0) {
        uint8_t value164 = RAM8(0x0000 + sp0 - 1);
        uint8_t value165 = RAM8(0x0000 + sp0);
        r->a = (a >> 8 << 8) | value163;
        r->x = x1;
        r->y = y;
        r->c = carry;
        r->z = ((value165 << 8) | value164) == 0;
        r->n = ((value165 << 8) | value164) & 0x8000;
        r->v = overflow;
        r->xf = 0;
        r->dp = (value165 << 8) | value164;
        r->sp += 2;
        { const uint16_t sp_call = r->sp; JSL(c, 0x95BA, 0xC20009); GUARD_JSL(c, sp_call, 0x95BA); } /* upload_boss_frame_entry */
        r->sp -= 2;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        r->sp += 2;
        RETURN_RTL(c);
    }
    RAM8(0xE061 + x1) = 0;
    RAM8(0x0000 + sp0 - 2) = x1 >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)x1;
    r->a = (a >> 8 << 8) | 0;
    r->x = x1;
    r->y = y;
    r->c = carry;
    r->z = 1;
    r->n = 0;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0x9593, 0xC20009); GUARD_JSL(c, sp_call, 0x9593); } /* upload_boss_frame_entry */
    r->sp += 2;
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all3 = r->a;
    uint16_t y_ret3 = r->y;
    bool overflow_ret3 = r->v;
    uint8_t value166 = RAM8(0x0000 + sp0 - 3);
    uint8_t value167 = RAM8(0x0000 + sp0 - 2);
    if (((value167 << 8) | value166) == 0x0600) {
        uint8_t a10 = (uint8_t)a_all3;
        uint8_t a_hi37 = a_all3 >> 8;
        uint8_t y13 = (uint8_t)y_ret3;
        for (;;) {
            LOOP_GUARD(loop_guard);
            uint16_t value168 = RAM16(0xE684);
            a10 = (uint8_t)value168;
            a_hi37 = value168 >> 8;
            break;
        }
        uint8_t a_hi46;
        uint8_t y14;
        if ((uint8_t)((a_hi37 << 8) | a10) != 0) {
            BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x6C80);
            uint16_t value169 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D60);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value169);
            uint16_t value170 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D62);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value170);
            uint16_t value171 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D68);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value171);
            uint16_t value172 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D6A);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value172);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x44), 0x207E);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x54), 0x207E);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x64), 0x207E);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x74), 0x207E);
            BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
            BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x6D80);
            uint16_t value173 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D64);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value173);
            uint16_t value174 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D66);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value174);
            uint16_t value175 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D6C);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value175);
            uint16_t value176 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D6E);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value176);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
            BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
            uint8_t a_hi45;
            if ((uint8_t)((uint8_t)((a_hi37 << 8) | a10) - 1) != 0) {
                uint8_t a_hi44;
                if ((uint8_t)((uint8_t)((a_hi37 << 8) | a10) - 2) == 0) {
                    a_hi44 = value176 >> 8;
                } else {
                    BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x6CC0);
                    uint16_t value177 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D70);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value177);
                    uint16_t value178 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D72);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value178);
                    uint16_t value179 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D78);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value179);
                    uint16_t value180 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D7A);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value180);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                    BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                    BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x6DC0);
                    uint16_t value181 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D74);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value181);
                    uint16_t value182 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D76);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value182);
                    uint16_t value183 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D7C);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value183);
                    uint16_t value184 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D7E);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value184);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                    BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                    uint8_t a_hi43;
                    if ((uint8_t)((uint8_t)((a_hi37 << 8) | a10) - 3) != 0) {
                        uint8_t a_hi42;
                        if ((uint8_t)((uint8_t)((a_hi37 << 8) | a10) - 4) == 0) {
                            a_hi42 = value184 >> 8;
                        } else {
                            BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x6E00);
                            uint16_t value185 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D80);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value185);
                            uint16_t value186 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D82);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value186);
                            uint16_t value187 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D88);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value187);
                            uint16_t value188 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D8A);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value188);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                            BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                            BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x6F00);
                            uint16_t value189 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D84);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value189);
                            uint16_t value190 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D86);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value190);
                            uint16_t value191 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D8C);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value191);
                            uint16_t value192 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D8E);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value192);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                            BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                            uint8_t a_hi41;
                            if ((uint8_t)((uint8_t)((a_hi37 << 8) | a10) - 5) != 0) {
                                uint8_t a_hi40;
                                if ((uint8_t)((uint8_t)((a_hi37 << 8) | a10) - 6) == 0) {
                                    a_hi40 = value192 >> 8;
                                } else {
                                    BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x6E40);
                                    uint16_t value193 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D90);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value193);
                                    uint16_t value194 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D92);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value194);
                                    uint16_t value195 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D98);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value195);
                                    uint16_t value196 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D9A);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value196);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                                    BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                                    BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x6F40);
                                    uint16_t value197 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D94);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value197);
                                    uint16_t value198 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D96);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value198);
                                    uint16_t value199 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D9C);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value199);
                                    uint16_t value200 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0D9E);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value200);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                                    BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                                    uint8_t a_hi39;
                                    if ((uint8_t)((uint8_t)((a_hi37 << 8) | a10) - 7) == 0) {
                                        a_hi39 = value200 >> 8;
                                    } else {
                                        uint8_t a_hi38;
                                        if ((uint8_t)((uint8_t)((a_hi37 << 8) | a10) - 8) == 0) {
                                            a_hi38 = value200 >> 8;
                                        } else {
                                            BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x6E80);
                                            uint16_t value201 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DA0);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value201);
                                            uint16_t value202 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DA2);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value202);
                                            uint16_t value203 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DA8);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value203);
                                            uint16_t value204 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DAA);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value204);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                                            BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                                            BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x6F80);
                                            uint16_t value205 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DA4);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value205);
                                            uint16_t value206 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DA6);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value206);
                                            uint16_t value207 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DAC);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value207);
                                            uint16_t value208 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DAE);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value208);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                                            BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                                            a_hi38 = value208 >> 8;
                                        }
                                        a_hi39 = a_hi38;
                                    }
                                    a_hi40 = a_hi39;
                                }
                                a_hi41 = a_hi40;
                            } else {
                                a_hi41 = value192 >> 8;
                            }
                            a_hi42 = a_hi41;
                        }
                        a_hi43 = a_hi42;
                    } else {
                        a_hi43 = value184 >> 8;
                    }
                    a_hi44 = a_hi43;
                }
                a_hi45 = a_hi44;
            } else {
                a_hi45 = value176 >> 8;
            }
            a_hi46 = a_hi45;
            y14 = 0xF0;
        } else {
            a_hi46 = a_hi37;
            y14 = y13;
        }
        uint16_t value209 = RAM16(0xE68D);
        uint8_t a12;
        uint8_t a_hi48;
        uint8_t x9;
        uint8_t y16;
        bool zero8;
        bool negative8;
        if ((uint8_t)value209 == 0) {
            a12 = (uint8_t)value209;
            a_hi48 = value209 >> 8;
            x9 = (uint8_t)value209;
            y16 = y14;
            zero8 = (uint8_t)value209 == 0;
            negative8 = (uint8_t)value209 & 0x80;
        } else {
            RAM16_SET(0xE68D, value209 & 0xFF00);
            uint8_t a11 = (uint8_t)(value209 & 0xFF00);
            uint8_t a_hi47 = (value209 & 0xFF00) >> 8;
            uint8_t x8 = 4;
            uint8_t y15 = y14;
            bool zero7 = 0;
            bool negative7 = 0;
            for (;;) {
                LOOP_GUARD(loop_guard);
                BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x6E80);
                uint16_t value210 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DA0);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value210);
                uint16_t value211 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DA2);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value211);
                uint16_t value212 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DA8);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value212);
                uint16_t value213 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DAA);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value213);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x6F80);
                uint16_t value214 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DA4);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value214);
                uint16_t value215 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DA6);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value215);
                uint16_t value216 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DAC);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value216);
                uint16_t value217 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DAE);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value217);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                uint16_t value218 = RAM16(0xE68D);
                if ((uint8_t)value218 != 0) {
                    RAM16_SET(0xE68D, value218 & 0xFF00);
                    a11 = (uint8_t)(value218 & 0xFF00);
                    a_hi47 = (value218 & 0xFF00) >> 8;
                    x8 = 4;
                    y15 = 0xF0;
                    zero7 = 0;
                    negative7 = 0;
                    continue;
                }
                a11 = (uint8_t)value218;
                a_hi47 = value218 >> 8;
                x8 = (uint8_t)value218;
                y15 = 0xF0;
                zero7 = (uint8_t)value218 == 0;
                negative7 = (uint8_t)value218 & 0x80;
                break;
            }
            a12 = a11;
            a_hi48 = a_hi47;
            x9 = x8;
            y16 = y15;
            zero8 = zero7;
            negative8 = negative7;
        }
        uint8_t value219 = RAM8(0x0000 + sp0 - 1);
        uint8_t value220 = RAM8(0x0000 + sp0);
        r->a = (a_hi48 << 8) | a12;
        r->x = x9;
        r->y = y16;
        r->c = ((value167 << 8) | value166) >= 0x0600;
        r->z = ((value220 << 8) | value219) == 0;
        r->n = ((value220 << 8) | value219) & 0x8000;
        r->v = overflow_ret3;
        r->mf = 0;
        r->xf = 1;
        r->dp = (value220 << 8) | value219;
        r->sp += 2;
        RETURN_RTL(c);
    }
    if (((value167 << 8) | value166) == 0x0800) {
        uint8_t a13 = (uint8_t)a_all3;
        uint8_t a_hi49 = a_all3 >> 8;
        uint8_t y17 = (uint8_t)y_ret3;
        for (;;) {
            LOOP_GUARD(loop_guard);
            uint16_t value221 = RAM16(0xE884);
            a13 = (uint8_t)value221;
            a_hi49 = value221 >> 8;
            break;
        }
        uint8_t a_hi58;
        uint8_t y18;
        if ((uint8_t)((a_hi49 << 8) | a13) != 0) {
            BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x6EC0);
            uint16_t value222 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DB0);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value222);
            uint16_t value223 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DB2);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value223);
            uint16_t value224 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DB8);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value224);
            uint16_t value225 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DBA);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value225);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x44), 0x207E);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x54), 0x207E);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x64), 0x207E);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x74), 0x207E);
            BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
            BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x6FC0);
            uint16_t value226 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DB4);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value226);
            uint16_t value227 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DB6);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value227);
            uint16_t value228 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DBC);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value228);
            uint16_t value229 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DBE);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value229);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
            BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
            uint8_t a_hi57;
            if ((uint8_t)((uint8_t)((a_hi49 << 8) | a13) - 1) != 0) {
                uint8_t a_hi56;
                if ((uint8_t)((uint8_t)((a_hi49 << 8) | a13) - 2) == 0) {
                    a_hi56 = value229 >> 8;
                } else {
                    BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7000);
                    uint16_t value230 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DC0);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value230);
                    uint16_t value231 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DC2);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value231);
                    uint16_t value232 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DC8);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value232);
                    uint16_t value233 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DCA);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value233);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                    BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                    BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7100);
                    uint16_t value234 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DC4);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value234);
                    uint16_t value235 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DC6);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value235);
                    uint16_t value236 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DCC);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value236);
                    uint16_t value237 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DCE);
                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value237);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                    BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                    uint8_t a_hi55;
                    if ((uint8_t)((uint8_t)((a_hi49 << 8) | a13) - 3) != 0) {
                        uint8_t a_hi54;
                        if ((uint8_t)((uint8_t)((a_hi49 << 8) | a13) - 4) == 0) {
                            a_hi54 = value237 >> 8;
                        } else {
                            BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7040);
                            uint16_t value238 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DD0);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value238);
                            uint16_t value239 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DD2);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value239);
                            uint16_t value240 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DD8);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value240);
                            uint16_t value241 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DDA);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value241);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                            BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                            BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7140);
                            uint16_t value242 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DD4);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value242);
                            uint16_t value243 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DD6);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value243);
                            uint16_t value244 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DDC);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value244);
                            uint16_t value245 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DDE);
                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value245);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                            BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                            uint8_t a_hi53;
                            if ((uint8_t)((uint8_t)((a_hi49 << 8) | a13) - 5) != 0) {
                                uint8_t a_hi52;
                                if ((uint8_t)((uint8_t)((a_hi49 << 8) | a13) - 6) == 0) {
                                    a_hi52 = value245 >> 8;
                                } else {
                                    BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7080);
                                    uint16_t value246 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DE0);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value246);
                                    uint16_t value247 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DE2);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value247);
                                    uint16_t value248 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DE8);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value248);
                                    uint16_t value249 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DEA);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value249);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                                    BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                                    BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7180);
                                    uint16_t value250 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DE4);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value250);
                                    uint16_t value251 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DE6);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value251);
                                    uint16_t value252 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DEC);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value252);
                                    uint16_t value253 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DEE);
                                    BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value253);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                                    BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                                    uint8_t a_hi51;
                                    if ((uint8_t)((uint8_t)((a_hi49 << 8) | a13) - 7) == 0) {
                                        a_hi51 = value253 >> 8;
                                    } else {
                                        uint8_t a_hi50;
                                        if ((uint8_t)((uint8_t)((a_hi49 << 8) | a13) - 8) == 0) {
                                            a_hi50 = value253 >> 8;
                                        } else {
                                            BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x70C0);
                                            uint16_t value254 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DF0);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value254);
                                            uint16_t value255 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DF2);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value255);
                                            uint16_t value256 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DF8);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value256);
                                            uint16_t value257 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DFA);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value257);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                                            BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                                            BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x71C0);
                                            uint16_t value258 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DF4);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value258);
                                            uint16_t value259 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DF6);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value259);
                                            uint16_t value260 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DFC);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value260);
                                            uint16_t value261 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DFE);
                                            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value261);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                                            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                                            BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                                            a_hi50 = value261 >> 8;
                                        }
                                        a_hi51 = a_hi50;
                                    }
                                    a_hi52 = a_hi51;
                                }
                                a_hi53 = a_hi52;
                            } else {
                                a_hi53 = value245 >> 8;
                            }
                            a_hi54 = a_hi53;
                        }
                        a_hi55 = a_hi54;
                    } else {
                        a_hi55 = value237 >> 8;
                    }
                    a_hi56 = a_hi55;
                }
                a_hi57 = a_hi56;
            } else {
                a_hi57 = value229 >> 8;
            }
            a_hi58 = a_hi57;
            y18 = 0xF0;
        } else {
            a_hi58 = a_hi49;
            y18 = y17;
        }
        uint16_t value262 = RAM16(0xE88D);
        uint8_t a15;
        uint8_t a_hi60;
        uint8_t x11;
        uint8_t y20;
        bool zero10;
        bool negative10;
        if ((uint8_t)value262 == 0) {
            a15 = (uint8_t)value262;
            a_hi60 = value262 >> 8;
            x11 = (uint8_t)value262;
            y20 = y18;
            zero10 = (uint8_t)value262 == 0;
            negative10 = (uint8_t)value262 & 0x80;
        } else {
            RAM16_SET(0xE88D, value262 & 0xFF00);
            uint8_t a14 = (uint8_t)(value262 & 0xFF00);
            uint8_t a_hi59 = (value262 & 0xFF00) >> 8;
            uint8_t x10 = 4;
            uint8_t y19 = y18;
            bool zero9 = 0;
            bool negative9 = 0;
            for (;;) {
                LOOP_GUARD(loop_guard);
                BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x70C0);
                uint16_t value263 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DF0);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value263);
                uint16_t value264 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DF2);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value264);
                uint16_t value265 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DF8);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value265);
                uint16_t value266 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DFA);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value266);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x71C0);
                uint16_t value267 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DF4);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value267);
                uint16_t value268 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DF6);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value268);
                uint16_t value269 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DFC);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value269);
                uint16_t value270 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0DFE);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value270);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                uint16_t value271 = RAM16(0xE88D);
                if ((uint8_t)value271 != 0) {
                    RAM16_SET(0xE88D, value271 & 0xFF00);
                    a14 = (uint8_t)(value271 & 0xFF00);
                    a_hi59 = (value271 & 0xFF00) >> 8;
                    x10 = 4;
                    y19 = 0xF0;
                    zero9 = 0;
                    negative9 = 0;
                    continue;
                }
                a14 = (uint8_t)value271;
                a_hi59 = value271 >> 8;
                x10 = (uint8_t)value271;
                y19 = 0xF0;
                zero9 = (uint8_t)value271 == 0;
                negative9 = (uint8_t)value271 & 0x80;
                break;
            }
            a15 = a14;
            a_hi60 = a_hi59;
            x11 = x10;
            y20 = y19;
            zero10 = zero9;
            negative10 = negative9;
        }
        uint8_t value272 = RAM8(0x0000 + sp0 - 1);
        uint8_t value273 = RAM8(0x0000 + sp0);
        r->a = (a_hi60 << 8) | a15;
        r->x = x11;
        r->y = y20;
        r->c = ((value167 << 8) | value166) >= 0x0800;
        r->z = ((value273 << 8) | value272) == 0;
        r->n = ((value273 << 8) | value272) & 0x8000;
        r->v = overflow_ret3;
        r->mf = 0;
        r->xf = 1;
        r->dp = (value273 << 8) | value272;
        r->sp += 2;
        RETURN_RTL(c);
    }
    uint8_t a16 = (uint8_t)a_all3;
    uint8_t a_hi61 = a_all3 >> 8;
    uint8_t y21 = (uint8_t)y_ret3;
    for (;;) {
        LOOP_GUARD(loop_guard);
        uint16_t value274 = RAM16(0xEA84);
        a16 = (uint8_t)value274;
        a_hi61 = value274 >> 8;
        break;
    }
    uint8_t a_hi70;
    uint8_t y22;
    if ((uint8_t)((a_hi61 << 8) | a16) != 0) {
        BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7200);
        uint16_t value275 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E00);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value275);
        uint16_t value276 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E02);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value276);
        uint16_t value277 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E08);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value277);
        uint16_t value278 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E0A);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value278);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x44), 0x207E);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x54), 0x207E);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x64), 0x207E);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x74), 0x207E);
        BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
        BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7300);
        uint16_t value279 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E04);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value279);
        uint16_t value280 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E06);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value280);
        uint16_t value281 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E0C);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value281);
        uint16_t value282 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E0E);
        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value282);
        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
        BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
        uint8_t a_hi69;
        if ((uint8_t)((uint8_t)((a_hi61 << 8) | a16) - 1) != 0) {
            uint8_t a_hi68;
            if ((uint8_t)((uint8_t)((a_hi61 << 8) | a16) - 2) == 0) {
                a_hi68 = value282 >> 8;
            } else {
                BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7240);
                uint16_t value283 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E10);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value283);
                uint16_t value284 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E12);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value284);
                uint16_t value285 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E18);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value285);
                uint16_t value286 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E1A);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value286);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7340);
                uint16_t value287 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E14);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value287);
                uint16_t value288 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E16);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value288);
                uint16_t value289 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E1C);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value289);
                uint16_t value290 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E1E);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value290);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                uint8_t a_hi67;
                if ((uint8_t)((uint8_t)((a_hi61 << 8) | a16) - 3) != 0) {
                    uint8_t a_hi66;
                    if ((uint8_t)((uint8_t)((a_hi61 << 8) | a16) - 4) == 0) {
                        a_hi66 = value290 >> 8;
                    } else {
                        BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7280);
                        uint16_t value291 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E20);
                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value291);
                        uint16_t value292 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E22);
                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value292);
                        uint16_t value293 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E28);
                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value293);
                        uint16_t value294 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E2A);
                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value294);
                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                        BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                        BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7380);
                        uint16_t value295 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E24);
                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value295);
                        uint16_t value296 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E26);
                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value296);
                        uint16_t value297 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E2C);
                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value297);
                        uint16_t value298 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E2E);
                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value298);
                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                        BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                        uint8_t a_hi65;
                        if ((uint8_t)((uint8_t)((a_hi61 << 8) | a16) - 5) != 0) {
                            uint8_t a_hi64;
                            if ((uint8_t)((uint8_t)((a_hi61 << 8) | a16) - 6) == 0) {
                                a_hi64 = value298 >> 8;
                            } else {
                                BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x72C0);
                                uint16_t value299 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E30);
                                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value299);
                                uint16_t value300 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E32);
                                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value300);
                                uint16_t value301 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E38);
                                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value301);
                                uint16_t value302 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E3A);
                                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value302);
                                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                                BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                                BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x73C0);
                                uint16_t value303 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E34);
                                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value303);
                                uint16_t value304 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E36);
                                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value304);
                                uint16_t value305 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E3C);
                                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value305);
                                uint16_t value306 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E3E);
                                BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value306);
                                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                                BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                                uint8_t a_hi63;
                                if ((uint8_t)((uint8_t)((a_hi61 << 8) | a16) - 7) == 0) {
                                    a_hi63 = value306 >> 8;
                                } else {
                                    uint8_t a_hi62;
                                    if ((uint8_t)((uint8_t)((a_hi61 << 8) | a16) - 8) == 0) {
                                        a_hi62 = value306 >> 8;
                                    } else {
                                        BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7400);
                                        uint16_t value307 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E40);
                                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value307);
                                        uint16_t value308 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E42);
                                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value308);
                                        uint16_t value309 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E48);
                                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value309);
                                        uint16_t value310 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E4A);
                                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value310);
                                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                                        BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                                        BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7500);
                                        uint16_t value311 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E44);
                                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value311);
                                        uint16_t value312 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E46);
                                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value312);
                                        uint16_t value313 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E4C);
                                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value313);
                                        uint16_t value314 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E4E);
                                        BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value314);
                                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
                                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
                                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
                                        BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
                                        BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
                                        a_hi62 = value314 >> 8;
                                    }
                                    a_hi63 = a_hi62;
                                }
                                a_hi64 = a_hi63;
                            }
                            a_hi65 = a_hi64;
                        } else {
                            a_hi65 = value298 >> 8;
                        }
                        a_hi66 = a_hi65;
                    }
                    a_hi67 = a_hi66;
                } else {
                    a_hi67 = value290 >> 8;
                }
                a_hi68 = a_hi67;
            }
            a_hi69 = a_hi68;
        } else {
            a_hi69 = value282 >> 8;
        }
        a_hi70 = a_hi69;
        y22 = 0xF0;
    } else {
        a_hi70 = a_hi61;
        y22 = y21;
    }
    uint16_t value315 = RAM16(0xEA8D);
    uint8_t a18;
    uint8_t a_hi72;
    uint8_t x13;
    uint8_t y24;
    bool zero12;
    bool negative12;
    if ((uint8_t)value315 == 0) {
        a18 = (uint8_t)value315;
        a_hi72 = value315 >> 8;
        x13 = (uint8_t)value315;
        y24 = y22;
        zero12 = (uint8_t)value315 == 0;
        negative12 = (uint8_t)value315 & 0x80;
    } else {
        RAM16_SET(0xEA8D, value315 & 0xFF00);
        uint8_t a17 = (uint8_t)(value315 & 0xFF00);
        uint8_t a_hi71 = (value315 & 0xFF00) >> 8;
        uint8_t x12 = 4;
        uint8_t y23 = y22;
        bool zero11 = 0;
        bool negative11 = 0;
        for (;;) {
            LOOP_GUARD(loop_guard);
            BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7400);
            uint16_t value316 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E40);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value316);
            uint16_t value317 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E42);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value317);
            uint16_t value318 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E48);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value318);
            uint16_t value319 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E4A);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value319);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
            BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
            BUS16_SET(c, (db_ret3 << 0x10) + 0x2116, 0x7500);
            uint16_t value320 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E44);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x42), value320);
            uint16_t value321 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E46);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x52), value321);
            uint16_t value322 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E4C);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x62), value322);
            uint16_t value323 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0E4E);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x72), value323);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x45), 0x20);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x55), 0x20);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x65), 0x20);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x75), 0x20);
            BUS8_SET(c, (db_ret3 << 0x10) + 0x420B, 0xF0);
            uint16_t value324 = RAM16(0xEA8D);
            if ((uint8_t)value324 != 0) {
                RAM16_SET(0xEA8D, value324 & 0xFF00);
                a17 = (uint8_t)(value324 & 0xFF00);
                a_hi71 = (value324 & 0xFF00) >> 8;
                x12 = 4;
                y23 = 0xF0;
                zero11 = 0;
                negative11 = 0;
                continue;
            }
            a17 = (uint8_t)value324;
            a_hi71 = value324 >> 8;
            x12 = (uint8_t)value324;
            y23 = 0xF0;
            zero11 = (uint8_t)value324 == 0;
            negative11 = (uint8_t)value324 & 0x80;
            break;
        }
        a18 = a17;
        a_hi72 = a_hi71;
        x13 = x12;
        y24 = y23;
        zero12 = zero11;
        negative12 = negative11;
    }
    uint8_t value325 = RAM8(0x0000 + sp0 - 1);
    uint8_t value326 = RAM8(0x0000 + sp0);
    r->a = (a_hi72 << 8) | a18;
    r->x = x13;
    r->y = y24;
    r->c = ((value167 << 8) | value166) >= 0x0800;
    r->z = ((value326 << 8) | value325) == 0;
    r->n = ((value326 << 8) | value325) & 0x8000;
    r->v = overflow_ret3;
    r->mf = 0;
    r->xf = 1;
    r->dp = (value326 << 8) | value325;
    r->sp += 2;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC19566, SOM_RTL, "gen", select_first_boss_auxiliary_tiles, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 4, 0, 1, 5163, 1347)
