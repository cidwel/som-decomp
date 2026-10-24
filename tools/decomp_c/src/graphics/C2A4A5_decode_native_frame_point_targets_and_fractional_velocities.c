#include "som_c.h"

/* C2A4A5 decode_native_frame_point_targets_and_fractional_velocities   [class C, 396 bytes, 219 instructions]
 * Source: src/rom/decode_native_frame_point_targets_and_fractional_velocities.s
 * Documented in docs/actor-visual-effect-point-producer.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void decode_native_frame_point_targets_and_fractional_velocities(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(0x0002, 0xD1);
    uint16_t value = RAM16(0xE0FC + x);
    RAM16_SET(0x0000, value);
    uint8_t a_hi1 = value >> 8;
    uint16_t x1 = x;
    uint16_t y1 = y;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = 0;
    for (;;) {
        uint8_t value2 = BUS8_RDL(c, (RAM8(0x0002 + direct_page) << 0x10) + RAM16(0x0000 + direct_page), RAM8(0x0002 + direct_page));
        if (value2 & 0x80) {
            r->a = (a_hi1 << 8) | value2;
            r->x = x1;
            r->y = y1;
            r->mf = true;
            r->xf = false;
            r->db = data_bank;
            r->dp = direct_page;
            { const uint16_t sp_call = r->sp; JSR(c, 0xA4B9, 0xC2A69C); GUARD_JSR(c, sp_call, 0xA4B9); } /* skip_native_point_frame_control_command */
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            bool m_ret = r->mf;
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            uint16_t y_ret = r->y;
            if (m_ret != 0) { c->fail = 3; return; }
            if (x_ret != 0) { c->fail = 3; return; }
            a_hi1 = a_all >> 8;
            y1 = y_ret;
            data_bank = db_ret;
            direct_page = dp_ret;
            continue;
        }
        break;
    }
    uint16_t value3 = BUS16_RDL(c, (RAM8(0x0002 + direct_page) << 0x10) + RAM16(0x0000 + direct_page), RAM8(0x0002 + direct_page));
    RAM8(0x0008 + direct_page) = (uint8_t)((uint8_t)value3 << 1);
    uint16_t value4 = BUS16_RDP(c, (data_bank << 0x10) + 0xE06A + x1);
    RAM16_SET(0x0010 + direct_page, (uint16_t)((((((uint8_t)((uint8_t)value3 << 1) << 8) | (value3 >> 8)) & 0xFF) << 1) + value4 + (((((uint8_t)((uint8_t)value3 << 1) << 8) | (value3 >> 8)) & 0xFF) >> 0x0F)));
    uint16_t value5 = BUS16_RDL(c, (RAM8(0x0012 + direct_page) << 0x10) + RAM16(0x0010 + direct_page), RAM8(0x0012 + direct_page));
    RAM16_SET(0x0010 + direct_page, value5);
    RAM8(0x0001 + direct_page) = 0;
    uint8_t value6 = BUS8_RDL(c, (RAM8(0x0012 + direct_page) << 0x10) + RAM16(0x0010 + direct_page), RAM8(0x0012 + direct_page));
    RAM8(0x0004 + direct_page) = value6;
    RAM8(0x0005 + direct_page) = (uint8_t)(value6 << 2);
    uint8_t value7 = RAM8(0x0004 + direct_page);
    RAM8(0x000A + direct_page) = value7 & 0x0F;
    if ((value7 & 0x0F) != 0) {
        RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
        uint8_t a_hi2 = 0;
        uint16_t x2 = ((value5 >> 8 << 8) | ((value7 & 0x0F) << 1 << 1)) & 0xFF;
        for (;;) {
            uint16_t value9 = BUS16_RDL(c, (RAM8(0x0012 + direct_page) << 0x10) + RAM16(0x0010 + direct_page), RAM8(0x0012 + direct_page));
            uint8_t a_hi12;
            if ((value9 & 0x80) != 0) {
                RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                uint8_t a_hi6;
                if ((value9 & 0x40) == 0) {
                    uint16_t x3 = x2;
                    uint16_t y2 = value9 & 0x3F;
                    bool negative1 = value9 & 0x3F & 0x8000;
                    for (;;) {
                        if ((uint16_t)(x3 - 1) != 0) {
                            if (!((uint16_t)(y2 - 1) & 0x8000)) {
                                uint16_t x3_next = (uint16_t)(x3 - 1);
                                uint16_t y2_next = (uint16_t)(y2 - 1);
                                bool negative1_next = (uint16_t)(y2 - 1) & 0x8000;
                                x3 = x3_next;
                                y2 = y2_next;
                                negative1 = negative1_next;
                                continue;
                            }
                            uint16_t x3_next2 = (uint16_t)(x3 - 1);
                            uint16_t y2_next2 = (uint16_t)(y2 - 1);
                            bool negative1_next2 = (uint16_t)(y2 - 1) & 0x8000;
                            x3 = x3_next2;
                            y2 = y2_next2;
                            negative1 = negative1_next2;
                            break;
                        }
                        a_hi2 = 0;
                        x2 = (uint16_t)(x3 - 1);
                        goto leave_loop_C2A4F4;
                    }
                    if (negative1) {
                        a_hi2 = 0;
                        x2 = x3;
                        continue;
                    }
                    a_hi6 = 0;
                } else {
                    uint16_t x4 = x2;
                    uint16_t y3 = value9 & 0x3F;
                    for (;;) {
                        if ((uint16_t)(x4 - 1) != 0) {
                            if ((uint16_t)(y3 - 1) & 0x8000) {
                                x4 = (uint16_t)(x4 - 1);
                                y3 = (uint16_t)(y3 - 1);
                                break;
                            }
                            x4 = (uint16_t)(x4 - 1);
                            y3 = (uint16_t)(y3 - 1);
                            continue;
                        }
                        a_hi2 = 0;
                        x2 = (uint16_t)(x4 - 1);
                        goto leave_loop_C2A4F4;
                    }
                    uint8_t a_hi3 = 0;
                    uint16_t x5 = x4;
                    for (;;) {
                        uint16_t value10 = BUS16_RDL(c, (RAM8(0x0012 + direct_page) << 0x10) + RAM16(0x0010 + direct_page), RAM8(0x0012 + direct_page));
                        uint8_t a_hi5;
                        if ((value10 & 0x80) != 0) {
                            RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                            RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                            if ((value10 & 0x40) != 0) {
                                uint16_t x7 = x5;
                                uint16_t y5 = value10 & 0x3F;
                                for (;;) {
                                    if ((uint16_t)(x7 - 1) != 0) {
                                        if ((uint16_t)(y5 - 1) & 0x8000) {
                                            x7 = (uint16_t)(x7 - 1);
                                            y5 = (uint16_t)(y5 - 1);
                                            break;
                                        }
                                        x7 = (uint16_t)(x7 - 1);
                                        y5 = (uint16_t)(y5 - 1);
                                        continue;
                                    }
                                    a_hi3 = 0;
                                    x5 = (uint16_t)(x7 - 1);
                                    goto leave_loop_C2A4F4_2;
                                }
                                a_hi2 = 0;
                                x2 = x7;
                                goto next_pass_C2A4F4;
                            }
                            uint16_t x6 = x5;
                            uint16_t y4 = value10 & 0x3F;
                            bool negative2 = value10 & 0x3F & 0x8000;
                            for (;;) {
                                if ((uint16_t)(x6 - 1) != 0) {
                                    if (!((uint16_t)(y4 - 1) & 0x8000)) {
                                        uint16_t x6_next = (uint16_t)(x6 - 1);
                                        uint16_t y4_next = (uint16_t)(y4 - 1);
                                        bool negative2_next = (uint16_t)(y4 - 1) & 0x8000;
                                        x6 = x6_next;
                                        y4 = y4_next;
                                        negative2 = negative2_next;
                                        continue;
                                    }
                                    uint16_t x6_next2 = (uint16_t)(x6 - 1);
                                    uint16_t y4_next2 = (uint16_t)(y4 - 1);
                                    bool negative2_next2 = (uint16_t)(y4 - 1) & 0x8000;
                                    x6 = x6_next2;
                                    y4 = y4_next2;
                                    negative2 = negative2_next2;
                                    break;
                                }
                                a_hi3 = 0;
                                x5 = (uint16_t)(x6 - 1);
                                goto leave_loop_C2A4F4_2;
                            }
                            if (negative2) {
                                a_hi3 = 0;
                                x5 = x6;
                                continue;
                            }
                            a_hi5 = 0;
                        } else {
                            RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                            if ((uint16_t)(x5 - 1) != 0) {
                                a_hi3 = value10 >> 8;
                                x5 = (uint16_t)(x5 - 1);
                                continue;
                            }
                            uint8_t a_hi4;
                            if ((uint16_t)(x5 - 1) == 0) {
                                a_hi4 = value10 >> 8;
                            } else {
                                RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                                RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                                if ((value10 & 0x40) != 0) {
                                    uint16_t x9 = (uint16_t)(x5 - 1);
                                    uint16_t y7 = value10 & 0x3F;
                                    for (;;) {
                                        if ((uint16_t)(x9 - 1) != 0) {
                                            if ((uint16_t)(y7 - 1) & 0x8000) {
                                                x9 = (uint16_t)(x9 - 1);
                                                y7 = (uint16_t)(y7 - 1);
                                                break;
                                            }
                                            x9 = (uint16_t)(x9 - 1);
                                            y7 = (uint16_t)(y7 - 1);
                                            continue;
                                        }
                                        a_hi3 = 0;
                                        x5 = (uint16_t)(x9 - 1);
                                        goto leave_loop_C2A4F4_2;
                                    }
                                    a_hi2 = 0;
                                    x2 = x9;
                                    goto next_pass_C2A4F4;
                                }
                                uint16_t x8 = (uint16_t)(x5 - 1);
                                uint16_t y6 = value10 & 0x3F;
                                bool negative3 = value10 & 0x3F & 0x8000;
                                for (;;) {
                                    if ((uint16_t)(x8 - 1) != 0) {
                                        if (!((uint16_t)(y6 - 1) & 0x8000)) {
                                            uint16_t x8_next = (uint16_t)(x8 - 1);
                                            uint16_t y6_next = (uint16_t)(y6 - 1);
                                            bool negative3_next = (uint16_t)(y6 - 1) & 0x8000;
                                            x8 = x8_next;
                                            y6 = y6_next;
                                            negative3 = negative3_next;
                                            continue;
                                        }
                                        uint16_t x8_next2 = (uint16_t)(x8 - 1);
                                        uint16_t y6_next2 = (uint16_t)(y6 - 1);
                                        bool negative3_next2 = (uint16_t)(y6 - 1) & 0x8000;
                                        x8 = x8_next2;
                                        y6 = y6_next2;
                                        negative3 = negative3_next2;
                                        break;
                                    }
                                    a_hi3 = 0;
                                    x5 = (uint16_t)(x8 - 1);
                                    goto leave_loop_C2A4F4_2;
                                }
                                if (negative3) {
                                    a_hi3 = 0;
                                    x5 = x8;
                                    continue;
                                }
                                a_hi4 = 0;
                            }
                            a_hi5 = a_hi4;
                        }
                        a_hi3 = a_hi5;
                        break;
                    }
                    leave_loop_C2A4F4_2:;
                    a_hi6 = a_hi3;
                }
                a_hi12 = a_hi6;
            } else {
                RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                if ((uint16_t)(x2 - 1) != 0) {
                    a_hi2 = value9 >> 8;
                    x2 = (uint16_t)(x2 - 1);
                    continue;
                }
                uint8_t a_hi11;
                if ((uint16_t)(x2 - 1) == 0) {
                    a_hi11 = value9 >> 8;
                } else {
                    RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                    RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                    uint8_t a_hi10;
                    if ((value9 & 0x40) == 0) {
                        uint16_t x10 = (uint16_t)(x2 - 1);
                        uint16_t y8 = value9 & 0x3F;
                        bool negative4 = value9 & 0x3F & 0x8000;
                        for (;;) {
                            if ((uint16_t)(x10 - 1) != 0) {
                                if (!((uint16_t)(y8 - 1) & 0x8000)) {
                                    uint16_t x10_next = (uint16_t)(x10 - 1);
                                    uint16_t y8_next = (uint16_t)(y8 - 1);
                                    bool negative4_next = (uint16_t)(y8 - 1) & 0x8000;
                                    x10 = x10_next;
                                    y8 = y8_next;
                                    negative4 = negative4_next;
                                    continue;
                                }
                                uint16_t x10_next2 = (uint16_t)(x10 - 1);
                                uint16_t y8_next2 = (uint16_t)(y8 - 1);
                                bool negative4_next2 = (uint16_t)(y8 - 1) & 0x8000;
                                x10 = x10_next2;
                                y8 = y8_next2;
                                negative4 = negative4_next2;
                                break;
                            }
                            a_hi2 = 0;
                            x2 = (uint16_t)(x10 - 1);
                            goto leave_loop_C2A4F4;
                        }
                        if (negative4) {
                            a_hi2 = 0;
                            x2 = x10;
                            continue;
                        }
                        a_hi10 = 0;
                    } else {
                        uint16_t x11 = (uint16_t)(x2 - 1);
                        uint16_t y9 = value9 & 0x3F;
                        for (;;) {
                            if ((uint16_t)(x11 - 1) != 0) {
                                if ((uint16_t)(y9 - 1) & 0x8000) {
                                    x11 = (uint16_t)(x11 - 1);
                                    y9 = (uint16_t)(y9 - 1);
                                    break;
                                }
                                x11 = (uint16_t)(x11 - 1);
                                y9 = (uint16_t)(y9 - 1);
                                continue;
                            }
                            a_hi2 = 0;
                            x2 = (uint16_t)(x11 - 1);
                            goto leave_loop_C2A4F4;
                        }
                        uint8_t a_hi7 = 0;
                        uint16_t x12 = x11;
                        for (;;) {
                            uint16_t value11 = BUS16_RDL(c, (RAM8(0x0012 + direct_page) << 0x10) + RAM16(0x0010 + direct_page), RAM8(0x0012 + direct_page));
                            uint8_t a_hi9;
                            if ((value11 & 0x80) != 0) {
                                RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                                RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                                if ((value11 & 0x40) != 0) {
                                    uint16_t x14 = x12;
                                    uint16_t y11 = value11 & 0x3F;
                                    for (;;) {
                                        if ((uint16_t)(x14 - 1) != 0) {
                                            if ((uint16_t)(y11 - 1) & 0x8000) {
                                                x14 = (uint16_t)(x14 - 1);
                                                y11 = (uint16_t)(y11 - 1);
                                                break;
                                            }
                                            x14 = (uint16_t)(x14 - 1);
                                            y11 = (uint16_t)(y11 - 1);
                                            continue;
                                        }
                                        a_hi7 = 0;
                                        x12 = (uint16_t)(x14 - 1);
                                        goto leave_loop_C2A4F4_3;
                                    }
                                    a_hi2 = 0;
                                    x2 = x14;
                                    goto next_pass_C2A4F4;
                                }
                                uint16_t x13 = x12;
                                uint16_t y10 = value11 & 0x3F;
                                bool negative5 = value11 & 0x3F & 0x8000;
                                for (;;) {
                                    if ((uint16_t)(x13 - 1) != 0) {
                                        if (!((uint16_t)(y10 - 1) & 0x8000)) {
                                            uint16_t x13_next = (uint16_t)(x13 - 1);
                                            uint16_t y10_next = (uint16_t)(y10 - 1);
                                            bool negative5_next = (uint16_t)(y10 - 1) & 0x8000;
                                            x13 = x13_next;
                                            y10 = y10_next;
                                            negative5 = negative5_next;
                                            continue;
                                        }
                                        uint16_t x13_next2 = (uint16_t)(x13 - 1);
                                        uint16_t y10_next2 = (uint16_t)(y10 - 1);
                                        bool negative5_next2 = (uint16_t)(y10 - 1) & 0x8000;
                                        x13 = x13_next2;
                                        y10 = y10_next2;
                                        negative5 = negative5_next2;
                                        break;
                                    }
                                    a_hi7 = 0;
                                    x12 = (uint16_t)(x13 - 1);
                                    goto leave_loop_C2A4F4_3;
                                }
                                if (negative5) {
                                    a_hi7 = 0;
                                    x12 = x13;
                                    continue;
                                }
                                a_hi9 = 0;
                            } else {
                                RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                                if ((uint16_t)(x12 - 1) != 0) {
                                    a_hi7 = value11 >> 8;
                                    x12 = (uint16_t)(x12 - 1);
                                    continue;
                                }
                                uint8_t a_hi8;
                                if ((uint16_t)(x12 - 1) == 0) {
                                    a_hi8 = value11 >> 8;
                                } else {
                                    RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                                    RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                                    if ((value11 & 0x40) != 0) {
                                        uint16_t x16 = (uint16_t)(x12 - 1);
                                        uint16_t y13 = value11 & 0x3F;
                                        for (;;) {
                                            if ((uint16_t)(x16 - 1) != 0) {
                                                if ((uint16_t)(y13 - 1) & 0x8000) {
                                                    x16 = (uint16_t)(x16 - 1);
                                                    y13 = (uint16_t)(y13 - 1);
                                                    break;
                                                }
                                                x16 = (uint16_t)(x16 - 1);
                                                y13 = (uint16_t)(y13 - 1);
                                                continue;
                                            }
                                            a_hi7 = 0;
                                            x12 = (uint16_t)(x16 - 1);
                                            goto leave_loop_C2A4F4_3;
                                        }
                                        a_hi2 = 0;
                                        x2 = x16;
                                        goto next_pass_C2A4F4;
                                    }
                                    uint16_t x15 = (uint16_t)(x12 - 1);
                                    uint16_t y12 = value11 & 0x3F;
                                    bool negative6 = value11 & 0x3F & 0x8000;
                                    for (;;) {
                                        if ((uint16_t)(x15 - 1) != 0) {
                                            if (!((uint16_t)(y12 - 1) & 0x8000)) {
                                                uint16_t x15_next = (uint16_t)(x15 - 1);
                                                uint16_t y12_next = (uint16_t)(y12 - 1);
                                                bool negative6_next = (uint16_t)(y12 - 1) & 0x8000;
                                                x15 = x15_next;
                                                y12 = y12_next;
                                                negative6 = negative6_next;
                                                continue;
                                            }
                                            uint16_t x15_next2 = (uint16_t)(x15 - 1);
                                            uint16_t y12_next2 = (uint16_t)(y12 - 1);
                                            bool negative6_next2 = (uint16_t)(y12 - 1) & 0x8000;
                                            x15 = x15_next2;
                                            y12 = y12_next2;
                                            negative6 = negative6_next2;
                                            break;
                                        }
                                        a_hi7 = 0;
                                        x12 = (uint16_t)(x15 - 1);
                                        goto leave_loop_C2A4F4_3;
                                    }
                                    if (negative6) {
                                        a_hi7 = 0;
                                        x12 = x15;
                                        continue;
                                    }
                                    a_hi8 = 0;
                                }
                                a_hi9 = a_hi8;
                            }
                            a_hi7 = a_hi9;
                            break;
                        }
                        leave_loop_C2A4F4_3:;
                        a_hi10 = a_hi7;
                    }
                    a_hi11 = a_hi10;
                }
                a_hi12 = a_hi11;
            }
            a_hi2 = a_hi12;
            break;
            next_pass_C2A4F4:;
        }
        leave_loop_C2A4F4:;
        uint16_t value12 = RAM16(0x0014 + direct_page);
        uint16_t value13 = BUS16_RDP(c, (data_bank << 0x10) + 0xE084 + value12);
        RAM8(0x0000 + sp0) = 0;
        RAM8(0x0000 + sp0 - 1) = value13 & 0x0F;
        uint16_t value14 = RAM16(0x000A + direct_page);
        RAM16_SET(0x0006 + direct_page, value14 & 0x0F);
        RAM16_SET(0x0002 + direct_page, RAM16(0x0008 + direct_page) & 0xC0);
        uint8_t value16 = RAM8(0x0000 + sp0 - 1);
        uint8_t value17 = RAM8(0x0000 + sp0);
        uint8_t value18 = RAM8(0x000A + direct_page);
        uint8_t a_hi15;
        uint16_t x19;
        if ((uint8_t)((value17 << 8) | value16) == value18) {
            a_hi15 = value17;
            x19 = value12 >> 1;
        } else {
            uint8_t a_hi14;
            uint16_t x18;
            if ((uint8_t)((value17 << 8) | value16) < value18) {
                a_hi14 = value17;
                x18 = value12 >> 1;
            } else {
                uint8_t a1 = (uint8_t)((uint8_t)((value17 << 8) | value16) - value18 - ((uint8_t)((value17 << 8) | value16) >= value18 ^ 1));
                uint8_t a_hi13 = value17;
                uint16_t x17 = value12 >> 1;
                for (;;) {
                    a1 = (uint8_t)(a1 - 1);
                    x17 = (uint16_t)(x17 + 4);
                    if (!(a1 != 0)) break;
                }
                a_hi14 = a_hi13;
                x18 = x17;
            }
            a_hi15 = a_hi14;
            x19 = x18;
        }
        uint8_t a_hi16 = a_hi15;
        uint16_t x20 = x19;
        uint16_t y14 = value14 & 0x0F;
        bool first_pass = true;
        for (;;) {
            if (first_pass) {
                uint16_t value19 = BUS16_RDL(c, (RAM8(0x0012 + direct_page) << 0x10) + RAM16(0x0010 + direct_page), RAM8(0x0012 + direct_page));
                RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                RAM8(0x0001 + direct_page) = (RAM8(0x0001 + direct_page) >> 1) | (value19 >> 0x0F << 7);
                RAM8(0x0001 + direct_page) = (RAM8(0x0001 + direct_page) >> 1) | ((uint8_t)value19 >> 7 << 7);
                uint8_t a9;
                if ((uint8_t)((uint8_t)value19 << 1) < 0x80) {
                    uint8_t value22 = RAM8(0x0005 + direct_page);
                    uint8_t a2;
                    if (value22 & 0x40) {
                        a2 = (uint8_t)((uint8_t)value19 << 1);
                    } else {
                        a2 = (uint8_t)((uint8_t)value19 << 1) >> 1;
                    }
                    uint8_t value23 = RAM8(0x0002 + direct_page);
                    uint8_t a3;
                    if (!(value23 & 0x80)) {
                        a3 = a2;
                    } else {
                        a3 = (uint8_t)(a2 + 0x0F) ^ 0xFF;
                    }
                    a9 = a3;
                } else {
                    uint8_t value24 = RAM8(0x0005 + direct_page);
                    uint8_t a4;
                    if (value24 & 0x40) {
                        a4 = (uint8_t)((uint8_t)value19 << 1);
                    } else {
                        a4 = ((uint8_t)((uint8_t)value19 << 1) >> 1) | (((uint8_t)((uint8_t)value19 << 1) >= 0x80) << 7);
                    }
                    uint8_t value25 = RAM8(0x0002 + direct_page);
                    uint8_t a8;
                    if (value25 & 0x80) {
                        a8 = (uint8_t)(a4 + 0x0F) ^ 0xFF;
                    } else {
                        uint8_t a7;
                        if (!(value25 & 0x80)) {
                            a7 = a4;
                        } else {
                            uint8_t a5;
                            if (value24 & 0x40) {
                                a5 = a4;
                            } else {
                                a5 = a4 >> 1;
                            }
                            uint8_t a6;
                            if (!(value25 & 0x80)) {
                                a6 = a5;
                            } else {
                                a6 = (uint8_t)(a5 + 0x0F) ^ 0xFF;
                            }
                            a7 = a6;
                        }
                        a8 = a7;
                    }
                    a9 = a8;
                }
                uint8_t a17;
                if (!((uint8_t)(value19 >> 8 << 1) & 0x80)) {
                    uint8_t value26 = RAM8(0x0005 + direct_page);
                    uint8_t a10;
                    if (value26 & 0x40) {
                        a10 = (uint8_t)(value19 >> 8 << 1);
                    } else {
                        a10 = (uint8_t)(value19 >> 8 << 1) >> 1;
                    }
                    uint8_t value27 = RAM8(0x0002 + direct_page);
                    uint8_t a11;
                    if (!(value27 & 0x40)) {
                        a11 = a10;
                    } else {
                        a11 = (uint8_t)(a10 + 0x0F) ^ 0xFF;
                    }
                    a17 = a11;
                } else {
                    uint8_t value28 = RAM8(0x0005 + direct_page);
                    uint8_t a12;
                    if (value28 & 0x40) {
                        a12 = (uint8_t)(value19 >> 8 << 1);
                    } else {
                        a12 = ((uint8_t)(value19 >> 8 << 1) >> 1) | 0x80;
                    }
                    uint8_t value29 = RAM8(0x0002 + direct_page);
                    uint8_t a16;
                    if (value29 & 0x40) {
                        a16 = (uint8_t)(a12 + 0x0F) ^ 0xFF;
                    } else {
                        uint8_t a15;
                        if (!(value29 & 0x40)) {
                            a15 = a12;
                        } else {
                            uint8_t a13;
                            if (value28 & 0x40) {
                                a13 = a12;
                            } else {
                                a13 = a12 >> 1;
                            }
                            uint8_t a14;
                            if (!(value29 & 0x40)) {
                                a14 = a13;
                            } else {
                                a14 = (uint8_t)(a13 + 0x0F) ^ 0xFF;
                            }
                            a15 = a14;
                        }
                        a16 = a15;
                    }
                    a17 = a16;
                }
                BUS16_SET(c, (data_bank << 0x10) + 0xC000 + x20, (a9 << 8) | a17);
                if ((uint16_t)(y14 - 1) != 0) {
                    a_hi16 = a9;
                    x20 = (uint16_t)(x20 + 4);
                    y14 = (uint16_t)(y14 - 1);
                    first_pass = false;
                    continue;
                }
                a_hi16 = a9;
                x20 = (uint16_t)(x20 + 4);
                y14 = (uint16_t)(y14 - 1);
                break;
            } else {
                uint16_t value30 = BUS16_RDL(c, (RAM8(0x0012 + direct_page) << 0x10) + RAM16(0x0010 + direct_page), RAM8(0x0012 + direct_page));
                RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                RAM16_SET(0x0010 + direct_page, (uint16_t)(RAM16(0x0010 + direct_page) + 1));
                RAM8(0x0001 + direct_page) = (RAM8(0x0001 + direct_page) >> 1) | (value30 >> 0x0F << 7);
                RAM8(0x0001 + direct_page) = (RAM8(0x0001 + direct_page) >> 1) | ((uint8_t)value30 >> 7 << 7);
                uint8_t a25;
                if ((uint8_t)((uint8_t)value30 << 1) < 0x80) {
                    uint8_t value33 = RAM8(0x0005 + direct_page);
                    uint8_t a18;
                    if (value33 & 0x40) {
                        a18 = (uint8_t)((uint8_t)value30 << 1);
                    } else {
                        a18 = (uint8_t)((uint8_t)value30 << 1) >> 1;
                    }
                    uint8_t value34 = RAM8(0x0002 + direct_page);
                    uint8_t a19;
                    if (!(value34 & 0x80)) {
                        a19 = a18;
                    } else {
                        a19 = (uint8_t)(a18 + 0x0F) ^ 0xFF;
                    }
                    a25 = a19;
                } else {
                    uint8_t value35 = RAM8(0x0005 + direct_page);
                    uint8_t a20;
                    if (value35 & 0x40) {
                        a20 = (uint8_t)((uint8_t)value30 << 1);
                    } else {
                        a20 = ((uint8_t)((uint8_t)value30 << 1) >> 1) | (((uint8_t)((uint8_t)value30 << 1) >= 0x80) << 7);
                    }
                    uint8_t value36 = RAM8(0x0002 + direct_page);
                    uint8_t a24;
                    if (value36 & 0x80) {
                        a24 = (uint8_t)(a20 + 0x0F) ^ 0xFF;
                    } else {
                        uint8_t a23;
                        if (!(value36 & 0x80)) {
                            a23 = a20;
                        } else {
                            uint8_t a21;
                            if (value35 & 0x40) {
                                a21 = a20;
                            } else {
                                a21 = a20 >> 1;
                            }
                            uint8_t a22;
                            if (!(value36 & 0x80)) {
                                a22 = a21;
                            } else {
                                a22 = (uint8_t)(a21 + 0x0F) ^ 0xFF;
                            }
                            a23 = a22;
                        }
                        a24 = a23;
                    }
                    a25 = a24;
                }
                uint8_t a33;
                if (!((uint8_t)(value30 >> 8 << 1) & 0x80)) {
                    uint8_t value37 = RAM8(0x0005 + direct_page);
                    uint8_t a26;
                    if (value37 & 0x40) {
                        a26 = (uint8_t)(value30 >> 8 << 1);
                    } else {
                        a26 = (uint8_t)(value30 >> 8 << 1) >> 1;
                    }
                    uint8_t value38 = RAM8(0x0002 + direct_page);
                    uint8_t a27;
                    if (!(value38 & 0x40)) {
                        a27 = a26;
                    } else {
                        a27 = (uint8_t)(a26 + 0x0F) ^ 0xFF;
                    }
                    a33 = a27;
                } else {
                    uint8_t value39 = RAM8(0x0005 + direct_page);
                    uint8_t a28;
                    if (value39 & 0x40) {
                        a28 = (uint8_t)(value30 >> 8 << 1);
                    } else {
                        a28 = ((uint8_t)(value30 >> 8 << 1) >> 1) | 0x80;
                    }
                    uint8_t value40 = RAM8(0x0002 + direct_page);
                    uint8_t a32;
                    if (value40 & 0x40) {
                        a32 = (uint8_t)(a28 + 0x0F) ^ 0xFF;
                    } else {
                        uint8_t a31;
                        if (!(value40 & 0x40)) {
                            a31 = a28;
                        } else {
                            uint8_t a29;
                            if (value39 & 0x40) {
                                a29 = a28;
                            } else {
                                a29 = a28 >> 1;
                            }
                            uint8_t a30;
                            if (!(value40 & 0x40)) {
                                a30 = a29;
                            } else {
                                a30 = (uint8_t)(a29 + 0x0F) ^ 0xFF;
                            }
                            a31 = a30;
                        }
                        a32 = a31;
                    }
                    a33 = a32;
                }
                BUS16_SET(c, (data_bank << 0x10) + 0xC000 + x20, (a25 << 8) | a33);
                if ((uint16_t)(y14 - 1) != 0) {
                    a_hi16 = a25;
                    x20 = (uint16_t)(x20 + 4);
                    y14 = (uint16_t)(y14 - 1);
                    continue;
                }
                a_hi16 = a25;
                x20 = (uint16_t)(x20 + 4);
                y14 = (uint16_t)(y14 - 1);
                break;
            }
        }
        uint16_t value41 = RAM16(0x0014 + direct_page);
        uint8_t value42 = BUS8_RDP(c, (data_bank << 0x10) + 0xE084 + value41);
        uint8_t value43 = RAM8(0x000A + direct_page);
        if ((value42 & 0x0F) != value43) {
            if ((value42 & 0x0F) < value43) {
                RAM8(0x000A + direct_page) = value42 & 0x0F;
            }
        }
        BUS8_SET(c, (data_bank << 0x10) + 0xC060 + (value41 >> 1), value42 & 0x0F);
        uint8_t value44 = BUS8_RDP(c, (data_bank << 0x10) + 0xE012 + value41);
        RAM8(0x0000 + direct_page) = value44;
        uint8_t value45 = RAM8(0x0000 + direct_page);
        RAM8(0x0008 + direct_page) = (uint8_t)((uint8_t)((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7)) + 5 + ((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7) > 0xFF));
        BUS8_SET(c, (data_bank << 0x10) + 0xC061 + (value41 >> 1), (uint8_t)((uint8_t)((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7)) + 5 + ((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7) > 0xFF)));
        BUS8_SET(c, (data_bank << 0x10) + 0xE114 + value41, 0x80);
        uint8_t value46 = BUS8_RDP(c, (data_bank << 0x10) + 0xC060 + (value41 >> 1));
        uint8_t value47 = RAM8(0x000A + direct_page);
        uint8_t a_hi19;
        uint16_t x23;
        uint16_t y17;
        bool carry2;
        bool overflow2;
        if (value46 == value47) {
            a_hi19 = value41 >> 1 >> 8;
            x23 = value41;
            y17 = value41 >> 1;
            carry2 = value46 >= value47;
            overflow2 = (((uint8_t)((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7)) + 5 + ((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7) > 0xFF))) & ((uint8_t)((uint8_t)((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7)) + 5 + ((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7) > 0xFF)) ^ 5) & 0x80) != 0;
        } else {
            uint8_t a_hi18;
            uint16_t x22;
            uint16_t y16;
            bool carry1;
            bool overflow1;
            if (value46 < value47) {
                a_hi18 = value41 >> 1 >> 8;
                x22 = value41;
                y16 = value41 >> 1;
                carry1 = value46 >= value47;
                overflow1 = (((uint8_t)((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7)) + 5 + ((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7) > 0xFF))) & ((uint8_t)((uint8_t)((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7)) + 5 + ((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7) > 0xFF)) ^ 5) & 0x80) != 0;
            } else {
                RAM8(0x0000 + direct_page) = (uint8_t)(value46 - value47 - (value46 >= value47 ^ 1));
                RAM8(0x0000 + sp0) = value41 >> 8;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)value41;
                RAM8(0x0000 + sp0 - 2) = value41 >> 1 >> 8;
                RAM8(0x0000 + sp0 - 3) = (uint8_t)(value41 >> 1);
                uint8_t a_hi17 = value41 >> 1 >> 8;
                uint16_t x21 = value41;
                uint16_t y15 = value41 >> 1;
                do {
                    uint8_t value48 = BUS8_RDP(c, (data_bank << 0x10) + 0xE0D0 + x21);
                    BUS8_SET(c, (data_bank << 0x10) + 0xC000 + y15, value48);
                    uint8_t value49 = BUS8_RDP(c, (data_bank << 0x10) + 0xE0D1 + x21);
                    BUS8_SET(c, (data_bank << 0x10) + 0xC001 + y15, value49);
                    RAM8(0x0000 + direct_page)--;
                    x21 = (uint16_t)(x21 + 4);
                    y15 = (uint16_t)(y15 + 4);
                } while (RAM8(0x0000 + direct_page) != 0);
                uint8_t value50 = RAM8(0x0000 + sp0 - 3);
                uint8_t value51 = RAM8(0x0000 + sp0 - 2);
                uint8_t value52 = RAM8(0x0000 + sp0 - 1);
                uint8_t value53 = RAM8(0x0000 + sp0);
                a_hi18 = a_hi17;
                x22 = (value53 << 8) | value52;
                y16 = (value51 << 8) | value50;
                carry1 = value46 - value47 >= (value46 >= value47 ^ 1);
                overflow1 = ((value46 ^ value47) & (value46 ^ (uint8_t)(value46 - value47 - (value46 >= value47 ^ 1))) & 0x80) != 0;
            }
            a_hi19 = a_hi18;
            x23 = x22;
            y17 = y16;
            carry2 = carry1;
            overflow2 = overflow1;
        }
        uint8_t a_hi20 = a_hi19;
        uint16_t x24 = x23;
        uint16_t y18 = y17;
        bool carry3 = carry2;
        bool overflow3 = overflow2;
        do {
            uint16_t value54 = BUS16_RDP(c, (data_bank << 0x10) + 0xE0D0 + x24);
            RAM16_SET(0x0000 + direct_page, value54);
            uint16_t value55 = BUS16_RDP(c, (data_bank << 0x10) + 0xC000 + y18);
            r->a = value55;
            r->x = x24;
            r->y = y18;
            r->mf = false;
            r->xf = false;
            r->db = data_bank;
            r->dp = direct_page;
            { const uint16_t sp_call = r->sp; JSR(c, 0xA60F, 0xC2A631); GUARD_JSR(c, sp_call, 0xA60F); } /* divide_signed_native_point_delta_into_velocity_and_remainder */
            uint16_t a_all2 = r->a;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            BUS16_SET(c, (data_bank << 0x10) + 0xC000 + y18, a_all2);
            uint16_t value56 = RAM16(0x0002 + direct_page);
            BUS16_SET(c, (data_bank << 0x10) + 0xC002 + y18, value56);
            BUS16_SET(c, (data_bank << 0x10) + 0xC032 + y18, value56);
            uint16_t value57 = RAM16(0x0000 + direct_page);
            BUS16_SET(c, (data_bank << 0x10) + 0xC030 + y18, value57);
            RAM8(0x000A + direct_page)--;
            a_hi20 = value57 >> 8;
            x24 = (uint16_t)(x24 + 4);
            y18 = (uint16_t)(y18 + 4);
            carry3 = carry_ret2;
            overflow3 = overflow_ret2;
        } while (RAM8(0x000A + direct_page) != 0);
        r->a = (a_hi20 << 8) | a;
        r->y = y18;
        r->c = carry3;
        r->v = overflow3;
        r->mf = true;
        r->xf = false;
        r->db = data_bank;
        r->dp = direct_page;
        RETURN_RTS(c);
    }
    r->a = value5 >> 8 << 8 | (value7 & 0x0F);
    r->y = y1;
    r->c = (uint8_t)(value6 << 1) & 0x80;
    r->v = (((((((uint8_t)((uint8_t)value3 << 1) << 8) | (value3 >> 8)) & 0xFF) << 1) ^ (uint16_t)((((((uint8_t)((uint8_t)value3 << 1) << 8) | (value3 >> 8)) & 0xFF) << 1) + value4 + (((((uint8_t)((uint8_t)value3 << 1) << 8) | (value3 >> 8)) & 0xFF) >> 0x0F))) & (value4 ^ (uint16_t)((((((uint8_t)((uint8_t)value3 << 1) << 8) | (value3 >> 8)) & 0xFF) << 1) + value4 + (((((uint8_t)((uint8_t)value3 << 1) << 8) | (value3 >> 8)) & 0xFF) >> 0x0F))) & 0x8000) != 0;
    r->mf = true;
    r->xf = false;
    r->db = data_bank;
    r->dp = direct_page;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2A4A5, SOM_RTS, "hand", decode_native_frame_point_targets_and_fractional_velocities, 0, L_B | L_Y | L_C | L_V, 4, 1, 0, 396, 219)
