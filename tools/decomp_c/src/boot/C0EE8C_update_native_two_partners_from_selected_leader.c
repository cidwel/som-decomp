#include "som_c.h"

/* C0EE8C update_native_two_partners_from_selected_leader   [class C, 409 bytes, 183 instructions]
 * Source: src/rom/update_native_two_partners_from_selected_leader.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void update_native_two_partners_from_selected_leader(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_ef02 = 0;
    uint8_t a_hi_ef02 = 0;
    uint16_t x_ef02 = 0;
    uint16_t y_ef02 = 0;
    bool carry_ef02 = 0;
    bool overflow_ef02 = 0;
    if (RAM8(0x004E) == 0) {
        uint8_t value2 = RAM8(0x00F1);
        if (value2 == 0) {
            uint8_t value3 = RAM8(0x00D9);
            if ((value3 & 0x0F) == 0) {
                uint8_t value4 = RAM8(0x00DA);
                if ((value4 & 0x0F) == 0) {
                    uint8_t value5 = RAM8(0x00DB);
                    if ((value5 & 0x0F) == 0) {
                        SET_A8(r, value5 & 0x0F);
                        RETURN_RTS(c);
                    }
                    uint8_t a_hi2;
                    uint16_t x2;
                    uint16_t y1;
                    bool carry1;
                    if (value5 & 0x0F & 0x01) {
                        RAM16_SET(0x0014, 0x0200);
                        a_hi2 = 0;
                        x2 = 0;
                        y1 = 0x0400;
                        carry1 = value5 & 0x0F & 0x01;
                    } else {
                        uint8_t a_hi1;
                        uint16_t x1;
                        if ((value5 & 0x0F) >> 1 & 0x01) {
                            RAM16_SET(0x0014, 0x0400);
                            a_hi1 = 2;
                            x1 = 0x0200;
                        } else {
                            RAM16_SET(0x0014, 0x0200);
                            a_hi1 = 4;
                            x1 = 0x0400;
                        }
                        a_hi2 = a_hi1;
                        x2 = x1;
                        y1 = 0;
                        carry1 = (value5 & 0x0F) >> 1 & 0x01;
                    }
                    a_ef02 = 0;
                    a_hi_ef02 = a_hi2;
                    x_ef02 = x2;
                    y_ef02 = y1;
                    carry_ef02 = carry1;
                    overflow_ef02 = overflow;
                    goto shared_EF02;
                }
                uint8_t a_hi4;
                uint16_t x4;
                uint16_t y2;
                bool carry2;
                if (value4 & 0x0F & 0x01) {
                    RAM16_SET(0x0014, 0x0200);
                    a_hi4 = 0;
                    x4 = 0;
                    y2 = 0x0400;
                    carry2 = value4 & 0x0F & 0x01;
                } else {
                    uint8_t a_hi3;
                    uint16_t x3;
                    if ((value4 & 0x0F) >> 1 & 0x01) {
                        RAM16_SET(0x0014, 0x0400);
                        a_hi3 = 2;
                        x3 = 0x0200;
                    } else {
                        RAM16_SET(0x0014, 0x0200);
                        a_hi3 = 4;
                        x3 = 0x0400;
                    }
                    a_hi4 = a_hi3;
                    x4 = x3;
                    y2 = 0;
                    carry2 = (value4 & 0x0F) >> 1 & 0x01;
                }
                a_ef02 = 0;
                a_hi_ef02 = a_hi4;
                x_ef02 = x4;
                y_ef02 = y2;
                carry_ef02 = carry2;
                overflow_ef02 = overflow;
                goto shared_EF02;
            }
            uint8_t a_hi6;
            uint16_t x6;
            uint16_t y3;
            bool carry3;
            if (value3 & 0x0F & 0x01) {
                RAM16_SET(0x0014, 0x0200);
                a_hi6 = 0;
                x6 = 0;
                y3 = 0x0400;
                carry3 = value3 & 0x0F & 0x01;
            } else {
                uint8_t a_hi5;
                uint16_t x5;
                if ((value3 & 0x0F) >> 1 & 0x01) {
                    RAM16_SET(0x0014, 0x0400);
                    a_hi5 = 2;
                    x5 = 0x0200;
                } else {
                    RAM16_SET(0x0014, 0x0200);
                    a_hi5 = 4;
                    x5 = 0x0400;
                }
                a_hi6 = a_hi5;
                x6 = x5;
                y3 = 0;
                carry3 = (value3 & 0x0F) >> 1 & 0x01;
            }
            a_ef02 = 0;
            a_hi_ef02 = a_hi6;
            x_ef02 = x6;
            y_ef02 = y3;
            carry_ef02 = carry3;
            overflow_ef02 = overflow;
            goto shared_EF02;
        }
        SET_A8(r, value2);
        RETURN_RTS(c);
    }
    uint8_t value6 = RAM8(0x00D5);
    uint8_t a_hi8;
    uint16_t x8;
    uint16_t y4;
    bool carry4;
    if ((value6 & 7) == 0) {
        RAM16_SET(0x0014, 0x0200);
        a_hi8 = 0;
        x8 = 0;
        y4 = 0x0400;
        carry4 = carry;
    } else {
        uint8_t a_hi7;
        uint16_t x7;
        if ((value6 & 7) == 2) {
            RAM16_SET(0x0014, 0x0400);
            a_hi7 = 2;
            x7 = 0x0200;
        } else {
            RAM16_SET(0x0014, 0x0200);
            a_hi7 = 4;
            x7 = 0x0400;
        }
        a_hi8 = a_hi7;
        x8 = x7;
        y4 = 0;
        carry4 = (value6 & 7) >= 2;
    }
    a_ef02 = 0;
    a_hi_ef02 = a_hi8;
    x_ef02 = x8;
    y_ef02 = y4;
    carry_ef02 = carry4;
    overflow_ef02 = overflow;
    shared_EF02:;
    RAM16_SET(0x00BA, (a_hi_ef02 << 8) | a_ef02);
    RAM16_SET(0x0012, x_ef02);
    RAM16_SET(0x001C, RAM16(0xE002 + x_ef02));
    RAM16_SET(0x001E, RAM16(0xE004 + x_ef02));
    RAM16_SET(0x0016, RAM16(0xE006 + x_ef02) & 0x7F7F);
    uint16_t value10 = RAM16(0x004E);
    uint8_t a_hi11;
    if (value10 != 0) {
        RAM16_SET(0x0018, 0);
        RAM16_SET(0x001A, 0);
        a_hi11 = value10 >> 8;
    } else {
        uint16_t value11 = RAM16(0xE00B + x_ef02);
        uint8_t a_hi10;
        if ((value11 & 8) == 0) {
            RAM16_SET(0x0018, 0x40);
            RAM16_SET(0x001A, 0x40);
            uint16_t value12 = RAM16(0x0016);
            uint8_t a_hi9;
            if (value12 == 0) {
                a_hi9 = value12 >> 8;
            } else {
                if ((value12 & 0x7F) == 0) {
                    if ((value12 & 0x7F00) != 0) {
                        RAM16_SET(0x0018, 0);
                    }
                } else {
                    if ((value12 & 0x7F00) == 0) {
                        RAM16_SET(0x001A, 0);
                    }
                }
                a_hi9 = (value12 & 0x7F00) >> 8;
            }
            a_hi10 = a_hi9;
        } else {
            RAM16_SET(0x0018, 0);
            RAM16_SET(0x001A, 0);
            a_hi10 = 0;
        }
        a_hi11 = a_hi10;
    }
    uint8_t value13 = RAM8(0x00F1);
    uint8_t value14 = RAM8(0x004E);
    bool m_flag12;
    bool x_flag12;
    uint8_t a_hi27;
    uint16_t x20;
    bool carry16;
    bool overflow12;
    if (value13 & value14 & 0x80) {
        uint8_t value15 = RAM8(0xE000 + y_ef02);
        bool m_flag5;
        bool x_flag5;
        uint8_t a_hi18;
        uint16_t x13;
        bool carry9;
        bool overflow5;
        if (value15 == 0) {
            m_flag5 = 1;
            x_flag5 = 0;
            a_hi18 = a_hi11;
            x13 = x_ef02;
            carry9 = carry_ef02;
            overflow5 = overflow_ef02;
        } else {
            bool m_flag4;
            bool x_flag4;
            uint8_t a_hi17;
            uint16_t x12;
            bool carry8;
            bool overflow4;
            if (value15 & 0x80) {
                m_flag4 = 1;
                x_flag4 = 0;
                a_hi17 = a_hi11;
                x12 = x_ef02;
                carry8 = carry_ef02;
                overflow4 = overflow_ef02;
            } else {
                uint8_t value16 = RAM8(0xE00A + y_ef02);
                bool m_flag3;
                bool x_flag3;
                uint8_t a_hi16;
                uint16_t x11;
                bool carry7;
                bool overflow3;
                if (value16 != 0) {
                    m_flag3 = 1;
                    x_flag3 = 0;
                    a_hi16 = a_hi11;
                    x11 = x_ef02;
                    carry7 = carry_ef02;
                    overflow3 = overflow_ef02;
                } else {
                    RAM16_SET(0x000C, RAM16(0xE002 + y_ef02));
                    uint16_t value18 = RAM16(0xE004 + y_ef02);
                    RAM16_SET(0x000E, value18);
                    RAM8(0x0000 + sp0) = y_ef02 >> 8;
                    RAM8(0x0000 + sp0 - 1) = (uint8_t)y_ef02;
                    r->a = value18;
                    r->x = x_ef02;
                    r->y = y_ef02;
                    r->c = carry_ef02;
                    r->z = value18 == 0;
                    r->n = value18 & 0x8000;
                    r->v = overflow_ef02;
                    r->mf = 0;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0;
                    r->sp -= 2;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xEF82, 0xC0F124); GUARD_JSR(c, sp_call, 0xEF82); } /* compute_native_wrapped_partner_steering_velocity */
                    r->sp += 2;
                    uint8_t x_ret = r->x;
                    bool carry_ret = r->c;
                    bool overflow_ret = r->v;
                    uint8_t value19 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value20 = RAM8(0x0000 + sp0);
                    uint16_t value21 = RAM16(0x0006);
                    bool m_flag2;
                    bool x_flag2;
                    uint8_t a_hi13;
                    uint16_t x10;
                    bool carry6;
                    bool overflow2;
                    if (value21 != 0) {
                        uint8_t value22 = RAM8(0xE02D + ((value20 << 8) | value19));
                        bool m_flag;
                        bool x_flag;
                        uint8_t a_hi12;
                        uint16_t x9;
                        bool carry5;
                        bool overflow1;
                        if (value22 < 6) {
                            RAM16_SET(0xE006 + ((value20 << 8) | value19), value21);
                            m_flag = 0;
                            x_flag = 0;
                            a_hi12 = value21 >> 8;
                            x9 = x_ret;
                            carry5 = value22 >= 6;
                            overflow1 = overflow_ret;
                        } else {
                            RAM8(0xE02D + ((value20 << 8) | value19)) = 0;
                            r->a = (value21 >> 8 << 8) | 0;
                            r->y = (value20 << 8) | value19;
                            r->c = value22 >= 6;
                            r->z = 1;
                            r->n = 0;
                            r->mf = 1;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSL(c, 0xEFA5, 0x01B729); GUARD_JSL(c, sp_call, 0xEFA5); } /* prepare_native_partner_obstacle_detour */
                            bool m_ret2 = r->mf;
                            bool x_ret2 = r->xf;
                            uint16_t a_all2 = r->a;
                            uint16_t x_ret3 = r->x;
                            bool carry_ret2 = r->c;
                            bool overflow_ret2 = r->v;
                            m_flag = m_ret2;
                            x_flag = x_ret2;
                            a_hi12 = a_all2 >> 8;
                            x9 = x_ret3;
                            carry5 = carry_ret2;
                            overflow1 = overflow_ret2;
                        }
                        m_flag2 = m_flag;
                        x_flag2 = x_flag;
                        a_hi13 = a_hi12;
                        x10 = x9;
                        carry6 = carry5;
                        overflow2 = overflow1;
                    } else {
                        RAM16_SET(0xE006 + ((value20 << 8) | value19), value21);
                        RAM8(0xE02D + ((value20 << 8) | value19)) = (uint8_t)value21;
                        m_flag2 = 1;
                        x_flag2 = 0;
                        a_hi13 = value21 >> 8;
                        x10 = x_ret;
                        carry6 = carry_ret;
                        overflow2 = overflow_ret;
                    }
                    uint16_t value23 = RAM16(0x0018);
                    uint8_t a_hi14;
                    if (value23 == 0) {
                        a_hi14 = value23 >> 8;
                    } else {
                        RAM16_SET(0x0018, 0x80);
                        a_hi14 = 0;
                    }
                    uint16_t value24 = RAM16(0x001A);
                    uint8_t a_hi15;
                    if (value24 == 0) {
                        a_hi15 = value24 >> 8;
                    } else {
                        RAM16_SET(0x001A, 0x80);
                        a_hi15 = 0;
                    }
                    m_flag3 = 0;
                    x_flag3 = x_flag2;
                    a_hi16 = a_hi15;
                    x11 = x10;
                    carry7 = carry6;
                    overflow3 = overflow2;
                }
                m_flag4 = m_flag3;
                x_flag4 = x_flag3;
                a_hi17 = a_hi16;
                x12 = x11;
                carry8 = carry7;
                overflow4 = overflow3;
            }
            m_flag5 = m_flag4;
            x_flag5 = x_flag4;
            a_hi18 = a_hi17;
            x13 = x12;
            carry9 = carry8;
            overflow5 = overflow4;
        }
        m_flag12 = m_flag5;
        x_flag12 = x_flag5;
        a_hi27 = a_hi18;
        x20 = x13;
        carry16 = carry9;
        overflow12 = overflow5;
    } else {
        uint8_t value25 = RAM8(0xE02C + y_ef02);
        uint8_t value26 = RAM8(0xE01C + y_ef02);
        uint8_t value27 = RAM8(0xE060 + y_ef02);
        uint8_t value28 = RAM8(0xE067 + y_ef02);
        bool m_flag11;
        bool x_flag11;
        uint8_t a_hi26;
        uint16_t x19;
        bool carry15;
        bool overflow11;
        if ((value25 | value26 | value27 | value28) != 0) {
            m_flag11 = 1;
            x_flag11 = 0;
            a_hi26 = a_hi11;
            x19 = x_ef02;
            carry15 = carry_ef02;
            overflow11 = overflow_ef02;
        } else {
            uint8_t value29 = RAM8(0xE000 + y_ef02);
            bool m_flag10;
            bool x_flag10;
            uint8_t a_hi25;
            uint16_t x18;
            bool carry14;
            bool overflow10;
            if (value29 == 0) {
                m_flag10 = 1;
                x_flag10 = 0;
                a_hi25 = a_hi11;
                x18 = x_ef02;
                carry14 = carry_ef02;
                overflow10 = overflow_ef02;
            } else {
                bool m_flag9;
                bool x_flag9;
                uint8_t a_hi24;
                uint16_t x17;
                bool carry13;
                bool overflow9;
                if (value29 & 0x80) {
                    m_flag9 = 1;
                    x_flag9 = 0;
                    a_hi24 = a_hi11;
                    x17 = x_ef02;
                    carry13 = carry_ef02;
                    overflow9 = overflow_ef02;
                } else {
                    uint8_t value30 = RAM8(0xE00A + y_ef02);
                    bool m_flag8;
                    bool x_flag8;
                    uint8_t a_hi23;
                    uint16_t x16;
                    bool carry12;
                    bool overflow8;
                    if (value30 != 0) {
                        m_flag8 = 1;
                        x_flag8 = 0;
                        a_hi23 = a_hi11;
                        x16 = x_ef02;
                        carry12 = carry_ef02;
                        overflow8 = overflow_ef02;
                    } else {
                        RAM16_SET(0x000C, RAM16(0xE002 + y_ef02));
                        uint16_t value32 = RAM16(0xE004 + y_ef02);
                        RAM16_SET(0x000E, value32);
                        RAM8(0x0000 + sp0) = y_ef02 >> 8;
                        RAM8(0x0000 + sp0 - 1) = (uint8_t)y_ef02;
                        r->a = value32;
                        r->x = x_ef02;
                        r->y = y_ef02;
                        r->c = carry_ef02;
                        r->z = value32 == 0;
                        r->n = value32 & 0x8000;
                        r->v = overflow_ef02;
                        r->mf = 0;
                        r->xf = 0;
                        r->db = 0x7E;
                        r->dp = 0;
                        r->sp -= 2;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xEF82, 0xC0F124); GUARD_JSR(c, sp_call, 0xEF82); } /* compute_native_wrapped_partner_steering_velocity */
                        r->sp += 2;
                        uint8_t x_ret4 = r->x;
                        bool carry_ret3 = r->c;
                        bool overflow_ret3 = r->v;
                        uint8_t value33 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value34 = RAM8(0x0000 + sp0);
                        uint16_t value35 = RAM16(0x0006);
                        bool m_flag7;
                        bool x_flag7;
                        uint8_t a_hi20;
                        uint16_t x15;
                        bool carry11;
                        bool overflow7;
                        if (value35 != 0) {
                            uint8_t value36 = RAM8(0xE02D + ((value34 << 8) | value33));
                            bool m_flag6;
                            bool x_flag6;
                            uint8_t a_hi19;
                            uint16_t x14;
                            bool carry10;
                            bool overflow6;
                            if (value36 < 6) {
                                RAM16_SET(0xE006 + ((value34 << 8) | value33), value35);
                                m_flag6 = 0;
                                x_flag6 = 0;
                                a_hi19 = value35 >> 8;
                                x14 = x_ret4;
                                carry10 = value36 >= 6;
                                overflow6 = overflow_ret3;
                            } else {
                                RAM8(0xE02D + ((value34 << 8) | value33)) = 0;
                                r->a = (value35 >> 8 << 8) | 0;
                                r->y = (value34 << 8) | value33;
                                r->c = value36 >= 6;
                                r->z = 1;
                                r->n = 0;
                                r->mf = 1;
                                r->xf = 0;
                                { const uint16_t sp_call = r->sp; JSL(c, 0xEFA5, 0x01B729); GUARD_JSL(c, sp_call, 0xEFA5); } /* prepare_native_partner_obstacle_detour */
                                bool m_ret4 = r->mf;
                                bool x_ret5 = r->xf;
                                uint16_t a_all4 = r->a;
                                uint16_t x_ret6 = r->x;
                                bool carry_ret4 = r->c;
                                bool overflow_ret4 = r->v;
                                m_flag6 = m_ret4;
                                x_flag6 = x_ret5;
                                a_hi19 = a_all4 >> 8;
                                x14 = x_ret6;
                                carry10 = carry_ret4;
                                overflow6 = overflow_ret4;
                            }
                            m_flag7 = m_flag6;
                            x_flag7 = x_flag6;
                            a_hi20 = a_hi19;
                            x15 = x14;
                            carry11 = carry10;
                            overflow7 = overflow6;
                        } else {
                            RAM16_SET(0xE006 + ((value34 << 8) | value33), value35);
                            RAM8(0xE02D + ((value34 << 8) | value33)) = (uint8_t)value35;
                            m_flag7 = 1;
                            x_flag7 = 0;
                            a_hi20 = value35 >> 8;
                            x15 = x_ret4;
                            carry11 = carry_ret3;
                            overflow7 = overflow_ret3;
                        }
                        uint16_t value37 = RAM16(0x0018);
                        uint8_t a_hi21;
                        if (value37 == 0) {
                            a_hi21 = value37 >> 8;
                        } else {
                            RAM16_SET(0x0018, 0x80);
                            a_hi21 = 0;
                        }
                        uint16_t value38 = RAM16(0x001A);
                        uint8_t a_hi22;
                        if (value38 == 0) {
                            a_hi22 = value38 >> 8;
                        } else {
                            RAM16_SET(0x001A, 0x80);
                            a_hi22 = 0;
                        }
                        m_flag8 = 0;
                        x_flag8 = x_flag7;
                        a_hi23 = a_hi22;
                        x16 = x15;
                        carry12 = carry11;
                        overflow8 = overflow7;
                    }
                    m_flag9 = m_flag8;
                    x_flag9 = x_flag8;
                    a_hi24 = a_hi23;
                    x17 = x16;
                    carry13 = carry12;
                    overflow9 = overflow8;
                }
                m_flag10 = m_flag9;
                x_flag10 = x_flag9;
                a_hi25 = a_hi24;
                x18 = x17;
                carry14 = carry13;
                overflow10 = overflow9;
            }
            m_flag11 = m_flag10;
            x_flag11 = x_flag10;
            a_hi26 = a_hi25;
            x19 = x18;
            carry15 = carry14;
            overflow11 = overflow10;
        }
        m_flag12 = m_flag11;
        x_flag12 = x_flag11;
        a_hi27 = a_hi26;
        x20 = x19;
        carry16 = carry15;
        overflow12 = overflow11;
    }
    uint16_t value39 = RAM16(0x0014);
    if (RAM8(0x00F1) & RAM8(0x004E) & 0x80) {
        uint8_t value42 = RAM8(0xE000 + value39);
        if (value42 == 0) {
            r->a = (a_hi27 << 8) | value42;
            r->x = x20;
            r->y = value39;
            r->c = carry16;
            r->v = overflow12;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if (value42 & 0x80) {
            r->a = (a_hi27 << 8) | value42;
            r->x = x20;
            r->y = value39;
            r->c = carry16;
            r->v = overflow12;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value43 = RAM8(0xE00A + value39);
        if (value43 != 0) {
            r->a = (a_hi27 << 8) | value43;
            r->x = x20;
            r->y = value39;
            r->c = carry16;
            r->v = overflow12;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        RAM16_SET(0x000C, RAM16(0xE002 + value39));
        uint16_t value45 = RAM16(0xE004 + value39);
        RAM16_SET(0x000E, value45);
        RAM8(0x0000 + sp0) = value39 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)value39;
        r->a = value45;
        r->x = x20;
        r->y = value39;
        r->c = carry16;
        r->z = value45 == 0;
        r->n = value45 & 0x8000;
        r->v = overflow12;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEFF8, 0xC0F124); GUARD_JSR(c, sp_call, 0xEFF8); } /* compute_native_wrapped_partner_steering_velocity */
        r->sp += 2;
        uint8_t value46 = RAM8(0x0000 + sp0 - 1);
        uint8_t value47 = RAM8(0x0000 + sp0);
        uint16_t value48 = RAM16(0x0006);
        if (value48 != 0) {
            uint8_t value49 = RAM8(0xE02D + ((value47 << 8) | value46));
            if (value49 < 6) {
                RAM16_SET(0xE006 + ((value47 << 8) | value46), value48);
                r->a = value48;
                r->y = (value47 << 8) | value46;
                r->c = value49 >= 6;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            RAM8(0xE02D + ((value47 << 8) | value46)) = 0;
            r->a = (value48 >> 8 << 8) | 0;
            r->y = (value47 << 8) | value46;
            r->c = value49 >= 6;
            r->z = 1;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xF01B, 0x01B729); GUARD_JSL(c, sp_call, 0xF01B); } /* prepare_native_partner_obstacle_detour */
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        RAM16_SET(0xE006 + ((value47 << 8) | value46), value48);
        RAM8(0xE02D + ((value47 << 8) | value46)) = (uint8_t)value48;
        r->a = value48;
        r->y = (value47 << 8) | value46;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value50 = RAM8(0xE02C + value39);
    uint8_t value51 = RAM8(0xE01C + value39);
    uint8_t value52 = RAM8(0xE060 + value39);
    uint8_t value53 = RAM8(0xE067 + value39);
    if ((value50 | value51 | value52 | value53) != 0) {
        r->a = (a_hi27 << 8) | (value50 | value51 | value52 | value53);
        r->x = x20;
        r->y = value39;
        r->c = carry16;
        r->v = overflow12;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    uint8_t value54 = RAM8(0xE000 + value39);
    if (value54 == 0) {
        r->a = (a_hi27 << 8) | value54;
        r->x = x20;
        r->y = value39;
        r->c = carry16;
        r->v = overflow12;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    if (value54 & 0x80) {
        r->a = (a_hi27 << 8) | value54;
        r->x = x20;
        r->y = value39;
        r->c = carry16;
        r->v = overflow12;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    uint8_t value55 = RAM8(0xE00A + value39);
    if (value55 != 0) {
        r->a = (a_hi27 << 8) | value55;
        r->x = x20;
        r->y = value39;
        r->c = carry16;
        r->v = overflow12;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x000C, RAM16(0xE002 + value39));
    uint16_t value57 = RAM16(0xE004 + value39);
    RAM16_SET(0x000E, value57);
    RAM8(0x0000 + sp0) = value39 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value39;
    r->a = value57;
    r->x = x20;
    r->y = value39;
    r->c = carry16;
    r->z = value57 == 0;
    r->n = value57 & 0x8000;
    r->v = overflow12;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEFF8, 0xC0F124); GUARD_JSR(c, sp_call, 0xEFF8); } /* compute_native_wrapped_partner_steering_velocity */
    r->sp += 2;
    uint8_t value58 = RAM8(0x0000 + sp0 - 1);
    uint8_t value59 = RAM8(0x0000 + sp0);
    uint16_t value60 = RAM16(0x0006);
    if (value60 != 0) {
        uint8_t value61 = RAM8(0xE02D + ((value59 << 8) | value58));
        if (value61 < 6) {
            RAM16_SET(0xE006 + ((value59 << 8) | value58), value60);
            r->a = value60;
            r->y = (value59 << 8) | value58;
            r->c = value61 >= 6;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        RAM8(0xE02D + ((value59 << 8) | value58)) = 0;
        r->a = (value60 >> 8 << 8) | 0;
        r->y = (value59 << 8) | value58;
        r->c = value61 >= 6;
        r->z = 1;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF01B, 0x01B729); GUARD_JSL(c, sp_call, 0xF01B); } /* prepare_native_partner_obstacle_detour */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    RAM16_SET(0xE006 + ((value59 << 8) | value58), value60);
    RAM8(0xE02D + ((value59 << 8) | value58)) = (uint8_t)value60;
    r->a = value60;
    r->y = (value59 << 8) | value58;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0EE8C, SOM_RTS, "gen", update_native_two_partners_from_selected_leader, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 409, 183)
