#include "som_c.h"

/* C1824E advance_native_cell_cast_frame_script_and_homing_cell   [class C, 408 bytes, 179 instructions]
 * Source: src/rom/advance_native_cell_cast_frame_script_and_homing_cell.s
 * Documented in docs/actor-visual-effect-scripts.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void advance_native_cell_cast_frame_script_and_homing_cell(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        r->a = (a_hi1 << 8) | a;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        JSR(c, 0x8250, 0xC18276); /* consume_native_visual_frame_script_pose_or_terminator */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        if (carry_ret) {
            uint16_t value = RAM16(0xE0FE + x_ret);
            RAM16_SET(0xE0FC + x_ret, value);
            uint8_t value2 = RAM8(0xE110 + x_ret);
            if (value2 != 4) {
                a_hi1 = value >> 8;
                x1 = x_ret;
                y1 = y_ret;
                carry1 = value2 >= 4;
                overflow1 = overflow_ret;
                continue;
            }
            r->mf = 1;
            r->xf = 0;
            JSR(c, 0x8271, 0xC1894D); /* advance_native_homing_cast_cell_and_deliver_target */
            r->mf = 1; /* sep */
            uint16_t a_all2 = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            a_hi1 = a_all2 >> 8;
            x1 = x_ret2;
            y1 = y_ret2;
            carry1 = carry_ret2;
            overflow1 = overflow_ret2;
            continue;
        }
        uint8_t value3 = RAM8(0xE110 + x_ret);
        if (value3 != 4) {
            r->c = value3 >= 4;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
        carry1 = value3 >= 4;
        overflow1 = overflow_ret;
        break;
    }
    uint16_t value4 = RAM16(0xE113 + x1);
    if ((value4 & 0x7F) != 0) {
        RAM16_SET(0xE11C + x1, (uint16_t)((value4 & 0x7F) + RAM16(0xE11C + x1)) & 0x3F);
        RAM16_SET(0xE12C + x1, (uint16_t)(RAM16(0xE12C + x1) + RAM16(0xE123 + x1)) & 0x3F);
        uint16_t value8 = RAM16(0xE13C + x1);
        uint16_t value9 = RAM16(0xE133 + x1);
        RAM16_SET(0xE13C + x1, (uint16_t)(value8 + value9) & 0x3F);
        RAM8(0xE133 + x1) = RAM8(0xE132 + x1);
        RAM8(0xE132 + x1) = RAM8(0xE123 + x1);
        RAM8(0xE123 + x1) = RAM8(0xE122 + x1);
        RAM8(0xE122 + x1) = RAM8(0xE113 + x1);
        uint8_t value14 = RAM8(0xE124 + x1);
        if (value14 == 0) {
            r->a = value14;
            r->x = x1;
            r->y = y1;
            r->c = value8 + value9 > 0xFFFF;
            r->v = ((value8 ^ (uint16_t)(value8 + value9)) & (value9 ^ (uint16_t)(value8 + value9)) & 0x8000) != 0;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        RAM8(0xE124 + x1) = (uint8_t)(value14 - 1);
        if ((uint8_t)(value14 - 1) == 0) {
            uint8_t value15 = RAM8(0xE11E + x1);
            RAM8(0x000E) = value15;
            uint8_t a1;
            if (!((uint8_t)(value15 - 0x10) & 0x80)) {
                a1 = (uint8_t)(value15 - 0x10);
            } else {
                a1 = 0x20;
            }
            RAM8(0x000C) = a1;
            RAM8(0x000D) = 0;
            RAM8(0x000F) = 0;
            uint16_t value16 = RAM16(0x000C);
            RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + (x1 | value16)) + RAM16(0xE020 + x1)));
            uint16_t value19 = RAM16(0xE074 + x1);
            uint16_t value20 = RAM16(0xE045 + x1);
            uint16_t value21 = RAM16(0xE022 + x1);
            RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value19 & 0x7F) + value20) ^ 0xFFFF) + value21 + 1) + RAM16(0xE11A + (x1 | value16)) + (((uint16_t)((value19 & 0x7F) + value20) ^ 0xFFFF) + value21 + 1 > 0xFFFF)));
            uint16_t value23 = RAM16(0xE116 + x1);
            RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((RAM16(0xE074 + value23) & 0x7F) + RAM16(0xE045 + value23)) ^ 0xFFFF) + RAM16(0xE022 + value23) + 1) - RAM16(0x0006)));
            RAM16_SET(0x0004, (uint16_t)(RAM16(0xE020 + value23) - RAM16(0x0004)));
            uint16_t value30 = RAM16(0x000E);
            uint16_t value31 = RAM16(0x0004);
            uint8_t a4;
            uint8_t a_hi4;
            if (!(value31 & 0x8000)) {
                uint8_t a2;
                uint8_t a_hi2;
                if (value31 < 0x1E) {
                    a2 = (uint8_t)value31;
                    a_hi2 = value31 >> 8;
                } else {
                    a2 = 0x1E;
                    a_hi2 = 0;
                }
                a4 = a2;
                a_hi4 = a_hi2;
            } else {
                uint8_t a3;
                uint8_t a_hi3;
                if (value31 >= 0xFFE2) {
                    a3 = (uint8_t)value31;
                    a_hi3 = value31 >> 8;
                } else {
                    a3 = 0xE2;
                    a_hi3 = 0xFF;
                }
                a4 = a3;
                a_hi4 = a_hi3;
            }
            RAM16_SET(0xE118 + (x1 | value30), (uint16_t)(((a_hi4 << 8) | a4) + RAM16(0xE118 + (x1 | value16))));
            uint16_t value33 = RAM16(0x0006);
            uint8_t a7;
            uint8_t a_hi7;
            if (!(value33 & 0x8000)) {
                uint8_t a5;
                uint8_t a_hi5;
                if (value33 < 0x1E) {
                    a5 = (uint8_t)value33;
                    a_hi5 = value33 >> 8;
                } else {
                    a5 = 0x1E;
                    a_hi5 = 0;
                }
                a7 = a5;
                a_hi7 = a_hi5;
            } else {
                uint8_t a6;
                uint8_t a_hi6;
                if (value33 >= 0xFFE2) {
                    a6 = (uint8_t)value33;
                    a_hi6 = value33 >> 8;
                } else {
                    a6 = 0xE2;
                    a_hi6 = 0xFF;
                }
                a7 = a6;
                a_hi7 = a_hi6;
            }
            RAM16_SET(0xE11A + (x1 | value30), (uint16_t)(((a_hi7 << 8) | a7) + RAM16(0xE11A + (x1 | value16))));
            uint8_t value35 = RAM8(0xE11E + x1);
            uint8_t a8;
            if ((uint8_t)(value35 + 0x10) < 0x30) {
                a8 = (uint8_t)(value35 + 0x10);
            } else {
                a8 = 0;
            }
            RAM8(0xE11E + x1) = a8;
            uint16_t value36 = RAM16(0x0004);
            uint8_t a9;
            uint8_t a_hi8;
            if (!(value36 & 0x8000)) {
                a9 = (uint8_t)value36;
                a_hi8 = value36 >> 8;
            } else {
                a9 = (uint8_t)(value36 ^ 0xFFFF);
                a_hi8 = (value36 ^ 0xFFFF) >> 8;
            }
            if (((a_hi8 << 8) | a9) >= 8) {
                uint16_t value37 = RAM16(0xE116 + x1);
                uint8_t value38 = RAM8(0xE000 + value37);
                if (value38 == 0) {
                    r->a = (a_hi8 << 8) | value38;
                    r->x = x1;
                    r->y = value37;
                    r->c = ((a_hi8 << 8) | a9) >= 8;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    r->sp -= 2;
                    JSR(c, 0x8A2A, 0xC18D12); /* deliver_complete_cast_hit_to_target */
                    r->sp += 2;
                    uint16_t a_all3 = r->a;
                    bool carry_ret3 = r->c;
                    RAM16_SET(0x0014, x1);
                    if (carry_ret3) {
                        RAM16_SET(0xE116 + x1, a_all3);
                        RAM8(0xE127 + x1) = 0x80;
                        RAM8(0xE137 + x1) = 0x80;
                        r->x = x1;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    uint16_t value39 = RAM16(0xE126 + x1);
                    if (!(value39 & 0x8000)) {
                        RAM16_SET(0xE116 + x1, value39);
                        RAM16_SET(0xE126 + x1, RAM16(0xE136 + x1));
                        RAM16_SET(0xE136 + x1, 0x8000);
                        r->a = 0x8000;
                        r->x = x1;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    RAM16_SET(0xE110 + x1, 0);
                    RAM16_SET(0xE120 + x1, 0);
                    RAM16_SET(0xE130 + x1, 0);
                    r->a = value39;
                    r->x = x1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                if (value38 & 0x80) {
                    r->a = (a_hi8 << 8) | value38;
                    r->x = x1;
                    r->y = value37;
                    r->c = ((a_hi8 << 8) | a9) >= 8;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    r->sp -= 2;
                    JSR(c, 0x8A2A, 0xC18D12); /* deliver_complete_cast_hit_to_target */
                    r->sp += 2;
                    uint16_t a_all4 = r->a;
                    bool carry_ret4 = r->c;
                    RAM16_SET(0x0014, x1);
                    if (carry_ret4) {
                        RAM16_SET(0xE116 + x1, a_all4);
                        RAM8(0xE127 + x1) = 0x80;
                        RAM8(0xE137 + x1) = 0x80;
                        r->x = x1;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    uint16_t value41 = RAM16(0xE126 + x1);
                    if (!(value41 & 0x8000)) {
                        RAM16_SET(0xE116 + x1, value41);
                        RAM16_SET(0xE126 + x1, RAM16(0xE136 + x1));
                        RAM16_SET(0xE136 + x1, 0x8000);
                        r->a = 0x8000;
                        r->x = x1;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    RAM16_SET(0xE110 + x1, 0);
                    RAM16_SET(0xE120 + x1, 0);
                    RAM16_SET(0xE130 + x1, 0);
                    r->a = value41;
                    r->x = x1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = (a_hi8 << 8) | value38;
                r->x = x1;
                r->y = value37;
                r->c = ((a_hi8 << 8) | a9) >= 8;
                r->v = ((value35 ^ (uint8_t)(value35 + 0x10)) & ((uint8_t)(value35 + 0x10) ^ 0x10) & 0x80) != 0;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            uint16_t value43 = RAM16(0x0006);
            uint8_t a10;
            uint8_t a_hi9;
            if (!(value43 & 0x8000)) {
                a10 = (uint8_t)value43;
                a_hi9 = value43 >> 8;
            } else {
                a10 = (uint8_t)(value43 ^ 0xFFFF);
                a_hi9 = (value43 ^ 0xFFFF) >> 8;
            }
            if (((a_hi9 << 8) | a10) < 8) {
                uint16_t value44 = RAM16(0xE116 + x1);
                r->a = (a_hi9 << 8) | a10;
                r->x = x1;
                r->y = value44;
                r->c = ((a_hi9 << 8) | a10) >= 8;
                r->mf = 0;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                r->sp -= 2;
                JSR(c, 0x8A2A, 0xC18D12); /* deliver_complete_cast_hit_to_target */
                r->sp += 2;
                uint16_t a_all5 = r->a;
                bool carry_ret5 = r->c;
                RAM16_SET(0x0014, x1);
                if (carry_ret5) {
                    RAM16_SET(0xE116 + x1, a_all5);
                    RAM8(0xE127 + x1) = 0x80;
                    RAM8(0xE137 + x1) = 0x80;
                    r->x = x1;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint16_t value45 = RAM16(0xE126 + x1);
                if (!(value45 & 0x8000)) {
                    RAM16_SET(0xE116 + x1, value45);
                    RAM16_SET(0xE126 + x1, RAM16(0xE136 + x1));
                    RAM16_SET(0xE136 + x1, 0x8000);
                    r->a = 0x8000;
                    r->x = x1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                RAM16_SET(0xE110 + x1, 0);
                RAM16_SET(0xE120 + x1, 0);
                RAM16_SET(0xE130 + x1, 0);
                r->a = value45;
                r->x = x1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value47 = RAM16(0xE116 + x1);
            uint8_t value48 = RAM8(0xE000 + value47);
            if (value48 == 0) {
                r->a = (a_hi9 << 8) | value48;
                r->x = x1;
                r->y = value47;
                r->c = ((a_hi9 << 8) | a10) >= 8;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                r->sp -= 2;
                JSR(c, 0x8A2A, 0xC18D12); /* deliver_complete_cast_hit_to_target */
                r->sp += 2;
                uint16_t a_all6 = r->a;
                bool carry_ret6 = r->c;
                RAM16_SET(0x0014, x1);
                if (carry_ret6) {
                    RAM16_SET(0xE116 + x1, a_all6);
                    RAM8(0xE127 + x1) = 0x80;
                    RAM8(0xE137 + x1) = 0x80;
                    r->x = x1;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint16_t value49 = RAM16(0xE126 + x1);
                if (!(value49 & 0x8000)) {
                    RAM16_SET(0xE116 + x1, value49);
                    RAM16_SET(0xE126 + x1, RAM16(0xE136 + x1));
                    RAM16_SET(0xE136 + x1, 0x8000);
                    r->a = 0x8000;
                    r->x = x1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                RAM16_SET(0xE110 + x1, 0);
                RAM16_SET(0xE120 + x1, 0);
                RAM16_SET(0xE130 + x1, 0);
                r->a = value49;
                r->x = x1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if (value48 & 0x80) {
                r->a = (a_hi9 << 8) | value48;
                r->x = x1;
                r->y = value47;
                r->c = ((a_hi9 << 8) | a10) >= 8;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                r->sp -= 2;
                JSR(c, 0x8A2A, 0xC18D12); /* deliver_complete_cast_hit_to_target */
                r->sp += 2;
                uint16_t a_all7 = r->a;
                bool carry_ret7 = r->c;
                RAM16_SET(0x0014, x1);
                if (carry_ret7) {
                    RAM16_SET(0xE116 + x1, a_all7);
                    RAM8(0xE127 + x1) = 0x80;
                    RAM8(0xE137 + x1) = 0x80;
                    r->x = x1;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint16_t value51 = RAM16(0xE126 + x1);
                if (!(value51 & 0x8000)) {
                    RAM16_SET(0xE116 + x1, value51);
                    RAM16_SET(0xE126 + x1, RAM16(0xE136 + x1));
                    RAM16_SET(0xE136 + x1, 0x8000);
                    r->a = 0x8000;
                    r->x = x1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                RAM16_SET(0xE110 + x1, 0);
                RAM16_SET(0xE120 + x1, 0);
                RAM16_SET(0xE130 + x1, 0);
                r->a = value51;
                r->x = x1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = (a_hi9 << 8) | value48;
            r->x = x1;
            r->y = value47;
            r->c = ((a_hi9 << 8) | a10) >= 8;
            r->v = ((value35 ^ (uint8_t)(value35 + 0x10)) & ((uint8_t)(value35 + 0x10) ^ 0x10) & 0x80) != 0;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if ((uint8_t)(value14 - 1) == 2) {
            uint8_t value53 = RAM8(0xE11E + x1);
            RAM8(0x000E) = value53;
            uint8_t a11;
            if (!((uint8_t)(value53 - 0x10) & 0x80)) {
                a11 = (uint8_t)(value53 - 0x10);
            } else {
                a11 = 0x20;
            }
            RAM8(0x000C) = a11;
            RAM8(0x000D) = 0;
            RAM8(0x000F) = 0;
            uint16_t value54 = RAM16(0x000C);
            RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + (x1 | value54)) + RAM16(0xE020 + x1)));
            uint16_t value57 = RAM16(0xE074 + x1);
            uint16_t value58 = RAM16(0xE045 + x1);
            uint16_t value59 = RAM16(0xE022 + x1);
            RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value57 & 0x7F) + value58) ^ 0xFFFF) + value59 + 1) + RAM16(0xE11A + (x1 | value54)) + (((uint16_t)((value57 & 0x7F) + value58) ^ 0xFFFF) + value59 + 1 > 0xFFFF)));
            uint16_t value61 = RAM16(0xE116 + x1);
            RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((RAM16(0xE074 + value61) & 0x7F) + RAM16(0xE045 + value61)) ^ 0xFFFF) + RAM16(0xE022 + value61) + 1) - RAM16(0x0006)));
            RAM16_SET(0x0004, (uint16_t)(RAM16(0xE020 + value61) - RAM16(0x0004)));
            uint16_t value68 = RAM16(0x000E);
            uint16_t value69 = RAM16(0x0004);
            uint8_t a14;
            uint8_t a_hi12;
            if (!(value69 & 0x8000)) {
                uint8_t a12;
                uint8_t a_hi10;
                if (value69 < 0x1E) {
                    a12 = (uint8_t)value69;
                    a_hi10 = value69 >> 8;
                } else {
                    a12 = 0x1E;
                    a_hi10 = 0;
                }
                a14 = a12;
                a_hi12 = a_hi10;
            } else {
                uint8_t a13;
                uint8_t a_hi11;
                if (value69 >= 0xFFE2) {
                    a13 = (uint8_t)value69;
                    a_hi11 = value69 >> 8;
                } else {
                    a13 = 0xE2;
                    a_hi11 = 0xFF;
                }
                a14 = a13;
                a_hi12 = a_hi11;
            }
            RAM16_SET(0xE118 + (x1 | value68), (uint16_t)(((a_hi12 << 8) | a14) + RAM16(0xE118 + (x1 | value54))));
            uint16_t value71 = RAM16(0x0006);
            uint8_t a17;
            uint8_t a_hi15;
            if (!(value71 & 0x8000)) {
                uint8_t a15;
                uint8_t a_hi13;
                if (value71 < 0x1E) {
                    a15 = (uint8_t)value71;
                    a_hi13 = value71 >> 8;
                } else {
                    a15 = 0x1E;
                    a_hi13 = 0;
                }
                a17 = a15;
                a_hi15 = a_hi13;
            } else {
                uint8_t a16;
                uint8_t a_hi14;
                if (value71 >= 0xFFE2) {
                    a16 = (uint8_t)value71;
                    a_hi14 = value71 >> 8;
                } else {
                    a16 = 0xE2;
                    a_hi14 = 0xFF;
                }
                a17 = a16;
                a_hi15 = a_hi14;
            }
            RAM16_SET(0xE11A + (x1 | value68), (uint16_t)(((a_hi15 << 8) | a17) + RAM16(0xE11A + (x1 | value54))));
            uint8_t value73 = RAM8(0xE11E + x1);
            uint8_t a18;
            if ((uint8_t)(value73 + 0x10) < 0x30) {
                a18 = (uint8_t)(value73 + 0x10);
            } else {
                a18 = 0;
            }
            RAM8(0xE11E + x1) = a18;
            uint16_t value74 = RAM16(0x0004);
            uint8_t a19;
            uint8_t a_hi16;
            if (!(value74 & 0x8000)) {
                a19 = (uint8_t)value74;
                a_hi16 = value74 >> 8;
            } else {
                a19 = (uint8_t)(value74 ^ 0xFFFF);
                a_hi16 = (value74 ^ 0xFFFF) >> 8;
            }
            if (((a_hi16 << 8) | a19) >= 8) {
                uint16_t value75 = RAM16(0xE116 + x1);
                uint8_t value76 = RAM8(0xE000 + value75);
                if (value76 == 0) {
                    r->a = (a_hi16 << 8) | value76;
                    r->x = x1;
                    r->y = value75;
                    r->c = ((a_hi16 << 8) | a19) >= 8;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    r->sp -= 2;
                    JSR(c, 0x8A2A, 0xC18D12); /* deliver_complete_cast_hit_to_target */
                    r->sp += 2;
                    uint16_t a_all8 = r->a;
                    bool carry_ret8 = r->c;
                    RAM16_SET(0x0014, x1);
                    if (carry_ret8) {
                        RAM16_SET(0xE116 + x1, a_all8);
                        RAM8(0xE127 + x1) = 0x80;
                        RAM8(0xE137 + x1) = 0x80;
                        r->x = x1;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    uint16_t value77 = RAM16(0xE126 + x1);
                    if (!(value77 & 0x8000)) {
                        RAM16_SET(0xE116 + x1, value77);
                        RAM16_SET(0xE126 + x1, RAM16(0xE136 + x1));
                        RAM16_SET(0xE136 + x1, 0x8000);
                        r->a = 0x8000;
                        r->x = x1;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    RAM16_SET(0xE110 + x1, 0);
                    RAM16_SET(0xE120 + x1, 0);
                    RAM16_SET(0xE130 + x1, 0);
                    r->a = value77;
                    r->x = x1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                if (value76 & 0x80) {
                    r->a = (a_hi16 << 8) | value76;
                    r->x = x1;
                    r->y = value75;
                    r->c = ((a_hi16 << 8) | a19) >= 8;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    r->sp -= 2;
                    JSR(c, 0x8A2A, 0xC18D12); /* deliver_complete_cast_hit_to_target */
                    r->sp += 2;
                    uint16_t a_all9 = r->a;
                    bool carry_ret9 = r->c;
                    RAM16_SET(0x0014, x1);
                    if (carry_ret9) {
                        RAM16_SET(0xE116 + x1, a_all9);
                        RAM8(0xE127 + x1) = 0x80;
                        RAM8(0xE137 + x1) = 0x80;
                        r->x = x1;
                        r->mf = 1;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    uint16_t value79 = RAM16(0xE126 + x1);
                    if (!(value79 & 0x8000)) {
                        RAM16_SET(0xE116 + x1, value79);
                        RAM16_SET(0xE126 + x1, RAM16(0xE136 + x1));
                        RAM16_SET(0xE136 + x1, 0x8000);
                        r->a = 0x8000;
                        r->x = x1;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                    RAM16_SET(0xE110 + x1, 0);
                    RAM16_SET(0xE120 + x1, 0);
                    RAM16_SET(0xE130 + x1, 0);
                    r->a = value79;
                    r->x = x1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                r->a = (a_hi16 << 8) | value76;
                r->x = x1;
                r->y = value75;
                r->c = ((a_hi16 << 8) | a19) >= 8;
                r->v = ((value73 ^ (uint8_t)(value73 + 0x10)) & ((uint8_t)(value73 + 0x10) ^ 0x10) & 0x80) != 0;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                RETURN_RTS(c);
            }
            uint16_t value81 = RAM16(0x0006);
            uint8_t a20;
            uint8_t a_hi17;
            if (!(value81 & 0x8000)) {
                a20 = (uint8_t)value81;
                a_hi17 = value81 >> 8;
            } else {
                a20 = (uint8_t)(value81 ^ 0xFFFF);
                a_hi17 = (value81 ^ 0xFFFF) >> 8;
            }
            if (((a_hi17 << 8) | a20) < 8) {
                uint16_t value82 = RAM16(0xE116 + x1);
                r->a = (a_hi17 << 8) | a20;
                r->x = x1;
                r->y = value82;
                r->c = ((a_hi17 << 8) | a20) >= 8;
                r->mf = 0;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                r->sp -= 2;
                JSR(c, 0x8A2A, 0xC18D12); /* deliver_complete_cast_hit_to_target */
                r->sp += 2;
                uint16_t a_all10 = r->a;
                bool carry_ret10 = r->c;
                RAM16_SET(0x0014, x1);
                if (carry_ret10) {
                    RAM16_SET(0xE116 + x1, a_all10);
                    RAM8(0xE127 + x1) = 0x80;
                    RAM8(0xE137 + x1) = 0x80;
                    r->x = x1;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint16_t value83 = RAM16(0xE126 + x1);
                if (!(value83 & 0x8000)) {
                    RAM16_SET(0xE116 + x1, value83);
                    RAM16_SET(0xE126 + x1, RAM16(0xE136 + x1));
                    RAM16_SET(0xE136 + x1, 0x8000);
                    r->a = 0x8000;
                    r->x = x1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                RAM16_SET(0xE110 + x1, 0);
                RAM16_SET(0xE120 + x1, 0);
                RAM16_SET(0xE130 + x1, 0);
                r->a = value83;
                r->x = x1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint16_t value85 = RAM16(0xE116 + x1);
            uint8_t value86 = RAM8(0xE000 + value85);
            if (value86 == 0) {
                r->a = (a_hi17 << 8) | value86;
                r->x = x1;
                r->y = value85;
                r->c = ((a_hi17 << 8) | a20) >= 8;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                r->sp -= 2;
                JSR(c, 0x8A2A, 0xC18D12); /* deliver_complete_cast_hit_to_target */
                r->sp += 2;
                uint16_t a_all11 = r->a;
                bool carry_ret11 = r->c;
                RAM16_SET(0x0014, x1);
                if (carry_ret11) {
                    RAM16_SET(0xE116 + x1, a_all11);
                    RAM8(0xE127 + x1) = 0x80;
                    RAM8(0xE137 + x1) = 0x80;
                    r->x = x1;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint16_t value87 = RAM16(0xE126 + x1);
                if (!(value87 & 0x8000)) {
                    RAM16_SET(0xE116 + x1, value87);
                    RAM16_SET(0xE126 + x1, RAM16(0xE136 + x1));
                    RAM16_SET(0xE136 + x1, 0x8000);
                    r->a = 0x8000;
                    r->x = x1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                RAM16_SET(0xE110 + x1, 0);
                RAM16_SET(0xE120 + x1, 0);
                RAM16_SET(0xE130 + x1, 0);
                r->a = value87;
                r->x = x1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if (value86 & 0x80) {
                r->a = (a_hi17 << 8) | value86;
                r->x = x1;
                r->y = value85;
                r->c = ((a_hi17 << 8) | a20) >= 8;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0;
                r->sp -= 2;
                JSR(c, 0x8A2A, 0xC18D12); /* deliver_complete_cast_hit_to_target */
                r->sp += 2;
                uint16_t a_all12 = r->a;
                bool carry_ret12 = r->c;
                RAM16_SET(0x0014, x1);
                if (carry_ret12) {
                    RAM16_SET(0xE116 + x1, a_all12);
                    RAM8(0xE127 + x1) = 0x80;
                    RAM8(0xE137 + x1) = 0x80;
                    r->x = x1;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint16_t value89 = RAM16(0xE126 + x1);
                if (!(value89 & 0x8000)) {
                    RAM16_SET(0xE116 + x1, value89);
                    RAM16_SET(0xE126 + x1, RAM16(0xE136 + x1));
                    RAM16_SET(0xE136 + x1, 0x8000);
                    r->a = 0x8000;
                    r->x = x1;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                RAM16_SET(0xE110 + x1, 0);
                RAM16_SET(0xE120 + x1, 0);
                RAM16_SET(0xE130 + x1, 0);
                r->a = value89;
                r->x = x1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = (a_hi17 << 8) | value86;
            r->x = x1;
            r->y = value85;
            r->c = ((a_hi17 << 8) | a20) >= 8;
            r->v = ((value73 ^ (uint8_t)(value73 + 0x10)) & ((uint8_t)(value73 + 0x10) ^ 0x10) & 0x80) != 0;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        r->a = (uint8_t)(value14 - 1);
        r->x = x1;
        r->y = y1;
        r->c = (uint8_t)(value14 - 1) >= 2;
        r->v = ((value8 ^ (uint16_t)(value8 + value9)) & (value9 ^ (uint16_t)(value8 + value9)) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    r->a = value4 & 0x7F;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1824E, SOM_RTS, "hand", advance_native_cell_cast_frame_script_and_homing_cell, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 2356, 179)
