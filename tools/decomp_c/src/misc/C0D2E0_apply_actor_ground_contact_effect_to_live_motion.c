#include "som_c.h"

static void publish_hero_facing_pose_and_status_limited_motion(SomCtx *c);
static void publish_hero_facing_pose_and_status_limited_motion_v2(SomCtx *c);

/* C0D2E0 apply_actor_ground_contact_effect_to_live_motion   [class C, 736 bytes, 363 instructions]
 * Source: src/rom/apply_actor_ground_contact_effect_to_live_motion.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void apply_actor_ground_contact_effect_to_live_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0010);
    uint8_t value2 = RAM8(0xE029 + value);
    uint8_t a_hi3;
    if (value2 == 0) {
        a_hi3 = a >> 8;
    } else {
        uint8_t a1;
        if ((value2 & 1) == 0) {
            a1 = value2;
        } else {
            RAM8(0x001E) = 0;
            a1 = value2 & 0x8A;
        }
        uint8_t a2;
        if ((a1 & 2) == 0) {
            a2 = a1;
        } else {
            RAM8(0x001F) = 0;
            a2 = a1 & 0x85;
        }
        uint8_t a_hi1;
        if ((a2 & 4) == 0) {
            a_hi1 = a >> 8;
        } else {
            uint8_t value3 = RAM8(0xE03A + value);
            RAM8(0x001E) = value3;
            a_hi1 = value3;
        }
        uint8_t a_hi2;
        if ((a2 & 8) == 0) {
            a_hi2 = a_hi1;
        } else {
            uint8_t value4 = RAM8(0xE03B + value);
            RAM8(0x001F) = value4;
            a_hi2 = value4;
        }
        RAM8(0xE029 + value) = a2 & 0x80;
        a_hi3 = a_hi2;
    }
    uint8_t value5 = RAM8(0xE060 + value);
    if (value5 != 0) {
        r->a = (a_hi3 << 8) | value5;
        r->x = value;
        r->z = value5 == 0;
        r->n = value5 & 0x80;
        r->mf = 1;
        publish_hero_facing_pose_and_status_limited_motion(c); return;
    }
    uint8_t value6 = RAM8(0xE01C + value);
    if (value6 != 0) {
        r->a = (a_hi3 << 8) | value6;
        r->x = value;
        r->z = value6 == 0;
        r->n = value6 & 0x80;
        r->mf = 1;
        publish_hero_facing_pose_and_status_limited_motion(c); return;
    }
    uint8_t value7 = RAM8(0x00F1);
    if (value7 & 0x80) {
        r->a = (a_hi3 << 8) | value7;
        r->x = value;
        r->z = value7 == 0;
        r->n = value7 & 0x80;
        r->mf = 1;
        publish_hero_facing_pose_and_status_limited_motion(c); return;
    }
    uint8_t value8 = RAM8(0x00D0);
    if (value8 == 0) {
        if (RAM8(0xE01B + value) != 0) {
            uint8_t value10 = RAM8(0x001E);
            if (value10 != 0) {
                RAM8(0x001E) = (value10 >> 7 << 7) | 1;
            }
            uint8_t value11 = RAM8(0x001F);
            if (value11 != 0) {
                RAM8(0x001F) = (value11 >> 7 << 7) | 1;
            }
        } else {
            if (RAM8(0xE01A + value) >= 2) {
                uint8_t value13 = RAM8(0x001E);
                if (value13 != 0) {
                    RAM8(0x001E) = (value13 >> 7 << 7) | 1;
                }
                uint8_t value14 = RAM8(0x001F);
                if (value14 != 0) {
                    RAM8(0x001F) = (value14 >> 7 << 7) | 1;
                }
            }
        }
        uint8_t value15 = RAM8(0xE048 + value);
        RAM8(0x0000) = value15;
        if ((value15 & 0xF0) == 0) {
            r->a = a_hi3 << 8 | (value15 & 0xF0);
            r->x = value;
            r->z = (value15 & 0xF0) == 0;
            r->n = value15 & 0xF0 & 0x80;
            r->mf = 1;
            publish_hero_facing_pose_and_status_limited_motion(c); return;
        }
        if ((value15 & 0xF0) != 0xD0) {
            if ((value15 & 0xF0) == 0x20) {
                uint8_t value16 = RAM8(0x00F4);
                bool m_flag10;
                bool x_flag10;
                uint8_t a_hi13;
                bool overflow4;
                uint8_t data_bank10;
                uint16_t direct_page10;
                if ((value16 & 4) == 0) {
                    uint8_t value17 = RAM8(0x0000);
                    bool m_flag9;
                    bool x_flag9;
                    uint8_t a_hi12;
                    bool overflow3;
                    uint8_t data_bank9;
                    uint16_t direct_page9;
                    if ((value17 & 2) == 0) {
                        uint8_t value18 = RAM8(0x001F);
                        bool m_flag4;
                        bool x_flag4;
                        uint8_t a_hi7;
                        bool overflow1;
                        uint8_t data_bank4;
                        uint16_t direct_page4;
                        if (value18 != 0) {
                            RAM8(0x001E) = 0;
                            RAM8(0x001F) = 0;
                            uint8_t value19 = RAM8(0x0095);
                            bool m_flag3;
                            bool x_flag3;
                            uint8_t a_hi6;
                            uint8_t data_bank3;
                            uint16_t direct_page3;
                            if (value19 & 0x80) {
                                m_flag3 = 1;
                                x_flag3 = 0;
                                a_hi6 = a_hi3;
                                data_bank3 = 0x7E;
                                direct_page3 = 0;
                            } else {
                                uint8_t value20 = RAM8(0xE02C + value);
                                bool m_flag2;
                                bool x_flag2;
                                uint8_t a_hi5;
                                uint8_t data_bank2;
                                uint16_t direct_page2;
                                if (value20 == 0) {
                                    m_flag2 = 1;
                                    x_flag2 = 0;
                                    a_hi5 = a_hi3;
                                    data_bank2 = 0x7E;
                                    direct_page2 = 0;
                                } else {
                                    bool m_flag;
                                    bool x_flag;
                                    uint8_t a_hi4;
                                    uint8_t data_bank;
                                    uint16_t direct_page;
                                    if ((value16 & 7) != 0) {
                                        m_flag = 1;
                                        x_flag = 0;
                                        a_hi4 = a_hi3;
                                        data_bank = 0x7E;
                                        direct_page = 0;
                                    } else {
                                        r->a = (a_hi3 << 8) | 0xEF;
                                        r->x = value;
                                        r->c = (value15 & 0xF0) >= 0x20;
                                        r->z = 0;
                                        r->n = 1;
                                        r->v = value19 & 0x40;
                                        r->mf = 1;
                                        { const uint16_t sp_call = r->sp; JSR(c, 0xD3D2, 0xC0BB11); GUARD_JSR(c, sp_call, 0xD3D2); } /* external */
                                        uint16_t dp_ret = r->dp;
                                        uint8_t db_ret = r->db;
                                        bool m_ret = r->mf;
                                        bool x_ret = r->xf;
                                        uint16_t a_all = r->a;
                                        m_flag = m_ret;
                                        x_flag = x_ret;
                                        a_hi4 = a_all >> 8;
                                        data_bank = db_ret;
                                        direct_page = dp_ret;
                                    }
                                    m_flag2 = m_flag;
                                    x_flag2 = x_flag;
                                    a_hi5 = a_hi4;
                                    data_bank2 = data_bank;
                                    direct_page2 = direct_page;
                                }
                                m_flag3 = m_flag2;
                                x_flag3 = x_flag2;
                                a_hi6 = a_hi5;
                                data_bank3 = data_bank2;
                                direct_page3 = direct_page2;
                            }
                            m_flag4 = m_flag3;
                            x_flag4 = x_flag3;
                            a_hi7 = a_hi6;
                            overflow1 = value19 & 0x40;
                            data_bank4 = data_bank3;
                            direct_page4 = direct_page3;
                        } else {
                            m_flag4 = 1;
                            x_flag4 = 0;
                            a_hi7 = a_hi3;
                            overflow1 = overflow;
                            data_bank4 = 0x7E;
                            direct_page4 = 0;
                        }
                        m_flag9 = m_flag4;
                        x_flag9 = x_flag4;
                        a_hi12 = a_hi7;
                        overflow3 = overflow1;
                        data_bank9 = data_bank4;
                        direct_page9 = direct_page4;
                    } else {
                        uint8_t value21 = RAM8(0x001E);
                        bool m_flag8;
                        bool x_flag8;
                        uint8_t a_hi11;
                        bool overflow2;
                        uint8_t data_bank8;
                        uint16_t direct_page8;
                        if (value21 == 0) {
                            m_flag8 = 1;
                            x_flag8 = 0;
                            a_hi11 = a_hi3;
                            overflow2 = overflow;
                            data_bank8 = 0x7E;
                            direct_page8 = 0;
                        } else {
                            RAM8(0x001E) = 0;
                            RAM8(0x001F) = 0;
                            uint8_t value22 = RAM8(0x0095);
                            bool m_flag7;
                            bool x_flag7;
                            uint8_t a_hi10;
                            uint8_t data_bank7;
                            uint16_t direct_page7;
                            if (value22 & 0x80) {
                                m_flag7 = 1;
                                x_flag7 = 0;
                                a_hi10 = a_hi3;
                                data_bank7 = 0x7E;
                                direct_page7 = 0;
                            } else {
                                uint8_t value23 = RAM8(0xE02C + value);
                                bool m_flag6;
                                bool x_flag6;
                                uint8_t a_hi9;
                                uint8_t data_bank6;
                                uint16_t direct_page6;
                                if (value23 == 0) {
                                    m_flag6 = 1;
                                    x_flag6 = 0;
                                    a_hi9 = a_hi3;
                                    data_bank6 = 0x7E;
                                    direct_page6 = 0;
                                } else {
                                    bool m_flag5;
                                    bool x_flag5;
                                    uint8_t a_hi8;
                                    uint8_t data_bank5;
                                    uint16_t direct_page5;
                                    if ((value16 & 7) != 0) {
                                        m_flag5 = 1;
                                        x_flag5 = 0;
                                        a_hi8 = a_hi3;
                                        data_bank5 = 0x7E;
                                        direct_page5 = 0;
                                    } else {
                                        r->a = (a_hi3 << 8) | 0xEF;
                                        r->x = value;
                                        r->c = (value15 & 0xF0) >= 0x20;
                                        r->z = 0;
                                        r->n = 1;
                                        r->v = value22 & 0x40;
                                        r->mf = 1;
                                        { const uint16_t sp_call = r->sp; JSR(c, 0xD3D2, 0xC0BB11); GUARD_JSR(c, sp_call, 0xD3D2); } /* external */
                                        uint16_t dp_ret2 = r->dp;
                                        uint8_t db_ret2 = r->db;
                                        bool m_ret2 = r->mf;
                                        bool x_ret2 = r->xf;
                                        uint16_t a_all2 = r->a;
                                        m_flag5 = m_ret2;
                                        x_flag5 = x_ret2;
                                        a_hi8 = a_all2 >> 8;
                                        data_bank5 = db_ret2;
                                        direct_page5 = dp_ret2;
                                    }
                                    m_flag6 = m_flag5;
                                    x_flag6 = x_flag5;
                                    a_hi9 = a_hi8;
                                    data_bank6 = data_bank5;
                                    direct_page6 = direct_page5;
                                }
                                m_flag7 = m_flag6;
                                x_flag7 = x_flag6;
                                a_hi10 = a_hi9;
                                data_bank7 = data_bank6;
                                direct_page7 = direct_page6;
                            }
                            m_flag8 = m_flag7;
                            x_flag8 = x_flag7;
                            a_hi11 = a_hi10;
                            overflow2 = value22 & 0x40;
                            data_bank8 = data_bank7;
                            direct_page8 = direct_page7;
                        }
                        m_flag9 = m_flag8;
                        x_flag9 = x_flag8;
                        a_hi12 = a_hi11;
                        overflow3 = overflow2;
                        data_bank9 = data_bank8;
                        direct_page9 = direct_page8;
                    }
                    m_flag10 = m_flag9;
                    x_flag10 = x_flag9;
                    a_hi13 = a_hi12;
                    overflow4 = overflow3;
                    data_bank10 = data_bank9;
                    direct_page10 = direct_page9;
                } else {
                    if ((RAM8(0x0000) & 2) != 0) {
                        if (!(value16 & 0x01)) {
                            uint8_t value25 = RAM8(0x0000);
                            RAM8(0x0000) >>= 1;
                            uint8_t value26 = RAM8(0x001E);
                            if (value26 != 0) {
                                uint8_t a3;
                                if (value25 & 0x01) {
                                    a3 = value26;
                                } else {
                                    a3 = value26 ^ 0x80;
                                }
                                RAM8(0x001F) = a3;
                            }
                        }
                    }
                    m_flag10 = 1;
                    x_flag10 = 0;
                    a_hi13 = a_hi3;
                    overflow4 = overflow;
                    data_bank10 = 0x7E;
                    direct_page10 = 0;
                }
                r->a = (a_hi13 << 8) | (uint8_t)a;
                r->x = value;
                r->v = overflow4;
                r->mf = m_flag10;
                r->xf = x_flag10;
                r->db = data_bank10;
                r->dp = direct_page10;
                publish_hero_facing_pose_and_status_limited_motion_v2(c); return;
            }
            if ((value15 & 0xF0) == 0x30) {
                uint8_t value27 = RAM8(0x0000);
                RAM8(0x0000 + sp0) = value27;
                r->a = (a_hi3 << 8) | value27;
                r->x = value;
                r->c = (value15 & 0xF0) >= 0x30;
                r->z = value27 == 0;
                r->n = value27 & 0x80;
                r->mf = 1;
                r->sp -= 1;
                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xD3E2, publish_hero_facing_pose_and_status_limited_motion, sp_in, 2); GUARD_JSR(c, sp_call, 0xD3E2); }
                r->sp += 1;
                uint16_t dp_ret3 = r->dp;
                uint8_t value28 = RAM8(0x0000 + sp0);
                BUS8_SET(c, dp_ret3, ((value28 & 0x0F) >> 2) + 1);
                if ((value28 & 3) == 0) {
                    uint8_t value29 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x1F));
                    uint8_t a4;
                    if (!(value29 & 0x80)) {
                        a4 = value29;
                    } else {
                        a4 = (uint8_t)((value29 ^ 0x7F) + 1);
                    }
                    uint8_t value30 = BUS8_RDP(c, dp_ret3);
                    uint8_t a5;
                    if (!((uint8_t)(a4 - value30) & 0x80)) {
                        a5 = (uint8_t)(a4 - value30);
                    } else {
                        a5 = (uint8_t)(((uint8_t)(a4 - value30) ^ 0x7F) + 1) | 0x80;
                    }
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x1F), a5);
                    r->c = a4 >= value30;
                    r->v = ((a4 ^ value30) & (a4 ^ (uint8_t)(a4 - value30)) & 0x80) != 0;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                if ((uint8_t)((value28 & 3) - 1) == 0) {
                    uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x1F));
                    uint8_t a6;
                    if (!(value31 & 0x80)) {
                        a6 = value31;
                    } else {
                        a6 = (uint8_t)((value31 ^ 0x7F) + 1);
                    }
                    uint8_t value32 = BUS8_RDP(c, dp_ret3);
                    uint8_t a7;
                    if (!((uint8_t)(a6 + value32) & 0x80)) {
                        a7 = (uint8_t)(a6 + value32);
                    } else {
                        a7 = (uint8_t)(((uint8_t)(a6 + value32) ^ 0x7F) + 1) | 0x80;
                    }
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x1F), a7);
                    r->c = a6 + value32 > 0xFF;
                    r->v = ((a6 ^ (uint8_t)(a6 + value32)) & (value32 ^ (uint8_t)(a6 + value32)) & 0x80) != 0;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                if ((uint8_t)((value28 & 3) - 2) == 0) {
                    uint8_t value33 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x1E));
                    uint8_t a8;
                    if (!(value33 & 0x80)) {
                        a8 = value33;
                    } else {
                        a8 = (uint8_t)((value33 ^ 0x7F) + 1);
                    }
                    uint8_t value34 = BUS8_RDP(c, dp_ret3);
                    uint8_t a9;
                    if (!((uint8_t)(a8 - value34) & 0x80)) {
                        a9 = (uint8_t)(a8 - value34);
                    } else {
                        a9 = (uint8_t)(((uint8_t)(a8 - value34) ^ 0x7F) + 1) | 0x80;
                    }
                    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x1E), a9);
                    r->c = a8 >= value34;
                    r->v = ((a8 ^ value34) & (a8 ^ (uint8_t)(a8 - value34)) & 0x80) != 0;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x1E));
                uint8_t a10;
                if (!(value35 & 0x80)) {
                    a10 = value35;
                } else {
                    a10 = (uint8_t)((value35 ^ 0x7F) + 1);
                }
                uint8_t value36 = BUS8_RDP(c, dp_ret3);
                uint8_t a11;
                if (!((uint8_t)(a10 + value36) & 0x80)) {
                    a11 = (uint8_t)(a10 + value36);
                } else {
                    a11 = (uint8_t)(((uint8_t)(a10 + value36) ^ 0x7F) + 1) | 0x80;
                }
                BUS8_SET(c, (uint16_t)(dp_ret3 + 0x1E), a11);
                r->c = a10 + value36 > 0xFF;
                r->v = ((a10 ^ (uint8_t)(a10 + value36)) & (value36 ^ (uint8_t)(a10 + value36)) & 0x80) != 0;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t a_hi15;
            uint16_t y2;
            bool overflow6;
            if ((value15 & 0xF0) != 0x40) {
                a_hi15 = a_hi3;
                y2 = y;
                overflow6 = overflow;
            } else {
                uint8_t value37 = RAM8(0x0000);
                uint8_t value38 = RAM8(0x0095);
                uint8_t a_hi14;
                uint16_t y1;
                bool overflow5;
                if (((value37 & 0x0F) | 0x70) == value38) {
                    a_hi14 = a_hi3;
                    y1 = y;
                    overflow5 = overflow;
                } else {
                    r->a = (a_hi3 << 8) | ((value37 & 0x0F) | 0x70 | 0x80);
                    r->x = value;
                    r->c = ((value37 & 0x0F) | 0x70) >= value38;
                    r->z = ((value37 & 0x0F) | 0x70 | 0x80) == 0;
                    r->n = ((value37 & 0x0F) | 0x70 | 0x80) & 0x80;
                    r->mf = 1;
                    { const uint16_t sp_call = r->sp; JSL(c, 0xD38D, 0x01D28F); GUARD_JSL(c, sp_call, 0xD38D); } /* public_contact_presentation_byte */
                    uint16_t a_all4 = r->a;
                    uint16_t y_ret2 = r->y;
                    bool overflow_ret2 = r->v;
                    a_hi14 = a_all4 >> 8;
                    y1 = y_ret2;
                    overflow5 = overflow_ret2;
                }
                a_hi15 = a_hi14;
                y2 = y1;
                overflow6 = overflow5;
            }
            r->a = (a_hi15 << 8) | (uint8_t)a;
            r->x = value;
            r->y = y2;
            r->v = overflow6;
            r->mf = 1;
            r->xf = 0;
            publish_hero_facing_pose_and_status_limited_motion(c); return;
        }
        uint8_t value39 = RAM8(0xE071 + value);
        if (!(value39 & 0x80)) {
            r->a = a_hi3 << 8 | (value15 & 0xF0);
            r->x = value;
            r->c = (value15 & 0xF0) >= 0xD0;
            r->z = (value15 & 0xF0 & value39) == 0;
            r->n = value39 & 0x80;
            r->v = value39 & 0x40;
            r->mf = 1;
            publish_hero_facing_pose_and_status_limited_motion(c); return;
        }
        if (value8 != 0) {
            r->a = (a_hi3 << 8) | value8;
            r->x = value;
            r->c = (value15 & 0xF0) >= 0xD0;
            r->z = value8 == 0;
            r->n = value8 & 0x80;
            r->v = value39 & 0x40;
            r->mf = 1;
            publish_hero_facing_pose_and_status_limited_motion(c); return;
        }
        uint8_t value40 = RAM8(0xE01C + value);
        uint8_t value41 = RAM8(0xE045 + value);
        bool x_flag11;
        uint8_t a_hi16;
        uint16_t x1;
        uint16_t y3;
        bool carry1;
        bool overflow7;
        uint8_t data_bank11;
        if ((value40 | value41) != 0) {
            x_flag11 = 0;
            a_hi16 = a_hi3;
            x1 = value;
            y3 = y;
            carry1 = (value15 & 0xF0) >= 0xD0;
            overflow7 = value39 & 0x40;
            data_bank11 = 0x7E;
        } else {
            RAM16_SET(0x00D4, RAM16(0xE05B + value));
            RAM16_SET(0x003A, value);
            RAM16_SET(0x001E, 0);
            RAM16_SET(0xE006 + value, 0);
            uint16_t value43 = RAM16(0xE048 + value);
            RAM16_SET(0xE048 + value, 0);
            RAM8(0x0000 + sp0) = value43 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)value43;
            RAM16_SET(0x0000, value43 & 0x0F);
            uint16_t value44 = RAM16(0x0000);
            r->a = ((value43 >> 4) & 0x0FF0) | value44;
            r->x = value;
            r->c = value43 >> 3 & 0x01;
            r->z = (((value43 >> 4) & 0x0FF0) | value44) == 0;
            r->n = (((value43 >> 4) & 0x0FF0) | value44) & 0x8000;
            r->v = value39 & 0x40;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD478, 0x01E76D); GUARD_JSL(c, sp_call, 0xD478); } /* event_command_map_context_entry */
            uint8_t db_ret4 = r->db;
            bool x_ret4 = r->xf;
            uint16_t a_all5 = r->a;
            uint16_t x_ret5 = r->x;
            uint16_t y_ret3 = r->y;
            bool carry_ret5 = r->c;
            bool overflow_ret3 = r->v;
            x_flag11 = x_ret4;
            a_hi16 = a_all5 >> 8;
            x1 = x_ret5;
            y3 = y_ret3;
            carry1 = carry_ret5;
            overflow7 = overflow_ret3;
            data_bank11 = db_ret4;
        }
        r->a = (a_hi16 << 8) | (uint8_t)a;
        r->x = x1;
        r->y = y3;
        r->c = carry1;
        r->v = overflow7;
        r->mf = 1;
        r->xf = x_flag11;
        r->db = data_bank11;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if (value < 0x0600) {
        uint16_t value45 = RAM16(0x00D4);
        if (value == value45) {
            r->a = (a_hi3 << 8) | value8;
            r->x = value;
            r->c = value >= value45;
            r->z = value == value45;
            r->n = (uint16_t)(value - value45) & 0x8000;
            r->mf = 1;
            publish_hero_facing_pose_and_status_limited_motion(c); return;
        }
        if (RAM8(0xE01B + value) != 0) {
            uint8_t value47 = RAM8(0x001E);
            if (value47 != 0) {
                RAM8(0x001E) = (value47 >> 7 << 7) | 1;
            }
            uint8_t value48 = RAM8(0x001F);
            if (value48 != 0) {
                RAM8(0x001F) = (value48 >> 7 << 7) | 1;
            }
        } else {
            if (RAM8(0xE01A + value) >= 2) {
                uint8_t value50 = RAM8(0x001E);
                if (value50 != 0) {
                    RAM8(0x001E) = (value50 >> 7 << 7) | 1;
                }
                uint8_t value51 = RAM8(0x001F);
                if (value51 != 0) {
                    RAM8(0x001F) = (value51 >> 7 << 7) | 1;
                }
            }
        }
        uint8_t value52 = RAM8(0xE048 + value);
        RAM8(0x0000) = value52;
        if ((value52 & 0xF0) == 0) {
            r->a = a_hi3 << 8 | (value52 & 0xF0);
            r->x = value;
            r->z = (value52 & 0xF0) == 0;
            r->n = value52 & 0xF0 & 0x80;
            r->mf = 1;
            publish_hero_facing_pose_and_status_limited_motion(c); return;
        }
        if ((value52 & 0xF0) != 0xD0) {
            if ((value52 & 0xF0) == 0x20) {
                uint8_t value53 = RAM8(0x00F4);
                bool m_flag20;
                bool x_flag21;
                uint8_t a_hi26;
                bool overflow11;
                uint8_t data_bank21;
                uint16_t direct_page20;
                if ((value53 & 4) == 0) {
                    uint8_t value54 = RAM8(0x0000);
                    bool m_flag19;
                    bool x_flag20;
                    uint8_t a_hi25;
                    bool overflow10;
                    uint8_t data_bank20;
                    uint16_t direct_page19;
                    if ((value54 & 2) == 0) {
                        uint8_t value55 = RAM8(0x001F);
                        bool m_flag14;
                        bool x_flag15;
                        uint8_t a_hi20;
                        bool overflow8;
                        uint8_t data_bank15;
                        uint16_t direct_page14;
                        if (value55 != 0) {
                            RAM8(0x001E) = 0;
                            RAM8(0x001F) = 0;
                            uint8_t value56 = RAM8(0x0095);
                            bool m_flag13;
                            bool x_flag14;
                            uint8_t a_hi19;
                            uint8_t data_bank14;
                            uint16_t direct_page13;
                            if (value56 & 0x80) {
                                m_flag13 = 1;
                                x_flag14 = 0;
                                a_hi19 = a_hi3;
                                data_bank14 = 0x7E;
                                direct_page13 = 0;
                            } else {
                                uint8_t value57 = RAM8(0xE02C + value);
                                bool m_flag12;
                                bool x_flag13;
                                uint8_t a_hi18;
                                uint8_t data_bank13;
                                uint16_t direct_page12;
                                if (value57 == 0) {
                                    m_flag12 = 1;
                                    x_flag13 = 0;
                                    a_hi18 = a_hi3;
                                    data_bank13 = 0x7E;
                                    direct_page12 = 0;
                                } else {
                                    bool m_flag11;
                                    bool x_flag12;
                                    uint8_t a_hi17;
                                    uint8_t data_bank12;
                                    uint16_t direct_page11;
                                    if ((value53 & 7) != 0) {
                                        m_flag11 = 1;
                                        x_flag12 = 0;
                                        a_hi17 = a_hi3;
                                        data_bank12 = 0x7E;
                                        direct_page11 = 0;
                                    } else {
                                        r->a = (a_hi3 << 8) | 0xEF;
                                        r->x = value;
                                        r->c = (value52 & 0xF0) >= 0x20;
                                        r->z = 0;
                                        r->n = 1;
                                        r->v = value56 & 0x40;
                                        r->mf = 1;
                                        { const uint16_t sp_call = r->sp; JSR(c, 0xD3D2, 0xC0BB11); GUARD_JSR(c, sp_call, 0xD3D2); } /* external */
                                        uint16_t dp_ret4 = r->dp;
                                        uint8_t db_ret5 = r->db;
                                        bool m_ret3 = r->mf;
                                        bool x_ret6 = r->xf;
                                        uint16_t a_all6 = r->a;
                                        m_flag11 = m_ret3;
                                        x_flag12 = x_ret6;
                                        a_hi17 = a_all6 >> 8;
                                        data_bank12 = db_ret5;
                                        direct_page11 = dp_ret4;
                                    }
                                    m_flag12 = m_flag11;
                                    x_flag13 = x_flag12;
                                    a_hi18 = a_hi17;
                                    data_bank13 = data_bank12;
                                    direct_page12 = direct_page11;
                                }
                                m_flag13 = m_flag12;
                                x_flag14 = x_flag13;
                                a_hi19 = a_hi18;
                                data_bank14 = data_bank13;
                                direct_page13 = direct_page12;
                            }
                            m_flag14 = m_flag13;
                            x_flag15 = x_flag14;
                            a_hi20 = a_hi19;
                            overflow8 = value56 & 0x40;
                            data_bank15 = data_bank14;
                            direct_page14 = direct_page13;
                        } else {
                            m_flag14 = 1;
                            x_flag15 = 0;
                            a_hi20 = a_hi3;
                            overflow8 = overflow;
                            data_bank15 = 0x7E;
                            direct_page14 = 0;
                        }
                        m_flag19 = m_flag14;
                        x_flag20 = x_flag15;
                        a_hi25 = a_hi20;
                        overflow10 = overflow8;
                        data_bank20 = data_bank15;
                        direct_page19 = direct_page14;
                    } else {
                        uint8_t value58 = RAM8(0x001E);
                        bool m_flag18;
                        bool x_flag19;
                        uint8_t a_hi24;
                        bool overflow9;
                        uint8_t data_bank19;
                        uint16_t direct_page18;
                        if (value58 == 0) {
                            m_flag18 = 1;
                            x_flag19 = 0;
                            a_hi24 = a_hi3;
                            overflow9 = overflow;
                            data_bank19 = 0x7E;
                            direct_page18 = 0;
                        } else {
                            RAM8(0x001E) = 0;
                            RAM8(0x001F) = 0;
                            uint8_t value59 = RAM8(0x0095);
                            bool m_flag17;
                            bool x_flag18;
                            uint8_t a_hi23;
                            uint8_t data_bank18;
                            uint16_t direct_page17;
                            if (value59 & 0x80) {
                                m_flag17 = 1;
                                x_flag18 = 0;
                                a_hi23 = a_hi3;
                                data_bank18 = 0x7E;
                                direct_page17 = 0;
                            } else {
                                uint8_t value60 = RAM8(0xE02C + value);
                                bool m_flag16;
                                bool x_flag17;
                                uint8_t a_hi22;
                                uint8_t data_bank17;
                                uint16_t direct_page16;
                                if (value60 == 0) {
                                    m_flag16 = 1;
                                    x_flag17 = 0;
                                    a_hi22 = a_hi3;
                                    data_bank17 = 0x7E;
                                    direct_page16 = 0;
                                } else {
                                    bool m_flag15;
                                    bool x_flag16;
                                    uint8_t a_hi21;
                                    uint8_t data_bank16;
                                    uint16_t direct_page15;
                                    if ((value53 & 7) != 0) {
                                        m_flag15 = 1;
                                        x_flag16 = 0;
                                        a_hi21 = a_hi3;
                                        data_bank16 = 0x7E;
                                        direct_page15 = 0;
                                    } else {
                                        r->a = (a_hi3 << 8) | 0xEF;
                                        r->x = value;
                                        r->c = (value52 & 0xF0) >= 0x20;
                                        r->z = 0;
                                        r->n = 1;
                                        r->v = value59 & 0x40;
                                        r->mf = 1;
                                        { const uint16_t sp_call = r->sp; JSR(c, 0xD3D2, 0xC0BB11); GUARD_JSR(c, sp_call, 0xD3D2); } /* external */
                                        uint16_t dp_ret5 = r->dp;
                                        uint8_t db_ret6 = r->db;
                                        bool m_ret4 = r->mf;
                                        bool x_ret7 = r->xf;
                                        uint16_t a_all7 = r->a;
                                        m_flag15 = m_ret4;
                                        x_flag16 = x_ret7;
                                        a_hi21 = a_all7 >> 8;
                                        data_bank16 = db_ret6;
                                        direct_page15 = dp_ret5;
                                    }
                                    m_flag16 = m_flag15;
                                    x_flag17 = x_flag16;
                                    a_hi22 = a_hi21;
                                    data_bank17 = data_bank16;
                                    direct_page16 = direct_page15;
                                }
                                m_flag17 = m_flag16;
                                x_flag18 = x_flag17;
                                a_hi23 = a_hi22;
                                data_bank18 = data_bank17;
                                direct_page17 = direct_page16;
                            }
                            m_flag18 = m_flag17;
                            x_flag19 = x_flag18;
                            a_hi24 = a_hi23;
                            overflow9 = value59 & 0x40;
                            data_bank19 = data_bank18;
                            direct_page18 = direct_page17;
                        }
                        m_flag19 = m_flag18;
                        x_flag20 = x_flag19;
                        a_hi25 = a_hi24;
                        overflow10 = overflow9;
                        data_bank20 = data_bank19;
                        direct_page19 = direct_page18;
                    }
                    m_flag20 = m_flag19;
                    x_flag21 = x_flag20;
                    a_hi26 = a_hi25;
                    overflow11 = overflow10;
                    data_bank21 = data_bank20;
                    direct_page20 = direct_page19;
                } else {
                    if ((RAM8(0x0000) & 2) != 0) {
                        if (!(value53 & 0x01)) {
                            uint8_t value62 = RAM8(0x0000);
                            RAM8(0x0000) >>= 1;
                            uint8_t value63 = RAM8(0x001E);
                            if (value63 != 0) {
                                uint8_t a12;
                                if (value62 & 0x01) {
                                    a12 = value63;
                                } else {
                                    a12 = value63 ^ 0x80;
                                }
                                RAM8(0x001F) = a12;
                            }
                        }
                    }
                    m_flag20 = 1;
                    x_flag21 = 0;
                    a_hi26 = a_hi3;
                    overflow11 = overflow;
                    data_bank21 = 0x7E;
                    direct_page20 = 0;
                }
                r->a = (a_hi26 << 8) | (uint8_t)a;
                r->x = value;
                r->v = overflow11;
                r->mf = m_flag20;
                r->xf = x_flag21;
                r->db = data_bank21;
                r->dp = direct_page20;
                publish_hero_facing_pose_and_status_limited_motion_v2(c); return;
            }
            if ((value52 & 0xF0) == 0x30) {
                uint8_t value64 = RAM8(0x0000);
                RAM8(0x0000 + sp0) = value64;
                r->a = (a_hi3 << 8) | value64;
                r->x = value;
                r->c = (value52 & 0xF0) >= 0x30;
                r->z = value64 == 0;
                r->n = value64 & 0x80;
                r->mf = 1;
                r->sp -= 1;
                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xD3E2, publish_hero_facing_pose_and_status_limited_motion, sp_in, 2); GUARD_JSR(c, sp_call, 0xD3E2); }
                r->sp += 1;
                uint16_t dp_ret6 = r->dp;
                uint8_t value65 = RAM8(0x0000 + sp0);
                BUS8_SET(c, dp_ret6, ((value65 & 0x0F) >> 2) + 1);
                if ((value65 & 3) == 0) {
                    uint8_t value66 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 0x1F));
                    uint8_t a13;
                    if (!(value66 & 0x80)) {
                        a13 = value66;
                    } else {
                        a13 = (uint8_t)((value66 ^ 0x7F) + 1);
                    }
                    uint8_t value67 = BUS8_RDP(c, dp_ret6);
                    uint8_t a14;
                    if (!((uint8_t)(a13 - value67) & 0x80)) {
                        a14 = (uint8_t)(a13 - value67);
                    } else {
                        a14 = (uint8_t)(((uint8_t)(a13 - value67) ^ 0x7F) + 1) | 0x80;
                    }
                    BUS8_SET(c, (uint16_t)(dp_ret6 + 0x1F), a14);
                    r->c = a13 >= value67;
                    r->v = ((a13 ^ value67) & (a13 ^ (uint8_t)(a13 - value67)) & 0x80) != 0;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                if ((uint8_t)((value65 & 3) - 1) == 0) {
                    uint8_t value68 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 0x1F));
                    uint8_t a15;
                    if (!(value68 & 0x80)) {
                        a15 = value68;
                    } else {
                        a15 = (uint8_t)((value68 ^ 0x7F) + 1);
                    }
                    uint8_t value69 = BUS8_RDP(c, dp_ret6);
                    uint8_t a16;
                    if (!((uint8_t)(a15 + value69) & 0x80)) {
                        a16 = (uint8_t)(a15 + value69);
                    } else {
                        a16 = (uint8_t)(((uint8_t)(a15 + value69) ^ 0x7F) + 1) | 0x80;
                    }
                    BUS8_SET(c, (uint16_t)(dp_ret6 + 0x1F), a16);
                    r->c = a15 + value69 > 0xFF;
                    r->v = ((a15 ^ (uint8_t)(a15 + value69)) & (value69 ^ (uint8_t)(a15 + value69)) & 0x80) != 0;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                if ((uint8_t)((value65 & 3) - 2) == 0) {
                    uint8_t value70 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 0x1E));
                    uint8_t a17;
                    if (!(value70 & 0x80)) {
                        a17 = value70;
                    } else {
                        a17 = (uint8_t)((value70 ^ 0x7F) + 1);
                    }
                    uint8_t value71 = BUS8_RDP(c, dp_ret6);
                    uint8_t a18;
                    if (!((uint8_t)(a17 - value71) & 0x80)) {
                        a18 = (uint8_t)(a17 - value71);
                    } else {
                        a18 = (uint8_t)(((uint8_t)(a17 - value71) ^ 0x7F) + 1) | 0x80;
                    }
                    BUS8_SET(c, (uint16_t)(dp_ret6 + 0x1E), a18);
                    r->c = a17 >= value71;
                    r->v = ((a17 ^ value71) & (a17 ^ (uint8_t)(a17 - value71)) & 0x80) != 0;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint8_t value72 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 0x1E));
                uint8_t a19;
                if (!(value72 & 0x80)) {
                    a19 = value72;
                } else {
                    a19 = (uint8_t)((value72 ^ 0x7F) + 1);
                }
                uint8_t value73 = BUS8_RDP(c, dp_ret6);
                uint8_t a20;
                if (!((uint8_t)(a19 + value73) & 0x80)) {
                    a20 = (uint8_t)(a19 + value73);
                } else {
                    a20 = (uint8_t)(((uint8_t)(a19 + value73) ^ 0x7F) + 1) | 0x80;
                }
                BUS8_SET(c, (uint16_t)(dp_ret6 + 0x1E), a20);
                r->c = a19 + value73 > 0xFF;
                r->v = ((a19 ^ (uint8_t)(a19 + value73)) & (value73 ^ (uint8_t)(a19 + value73)) & 0x80) != 0;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t a_hi28;
            uint16_t y5;
            bool overflow13;
            if ((value52 & 0xF0) != 0x40) {
                a_hi28 = a_hi3;
                y5 = y;
                overflow13 = overflow;
            } else {
                uint8_t value74 = RAM8(0x0000);
                uint8_t value75 = RAM8(0x0095);
                uint8_t a_hi27;
                uint16_t y4;
                bool overflow12;
                if (((value74 & 0x0F) | 0x70) == value75) {
                    a_hi27 = a_hi3;
                    y4 = y;
                    overflow12 = overflow;
                } else {
                    r->a = (a_hi3 << 8) | ((value74 & 0x0F) | 0x70 | 0x80);
                    r->x = value;
                    r->c = ((value74 & 0x0F) | 0x70) >= value75;
                    r->z = ((value74 & 0x0F) | 0x70 | 0x80) == 0;
                    r->n = ((value74 & 0x0F) | 0x70 | 0x80) & 0x80;
                    r->mf = 1;
                    { const uint16_t sp_call = r->sp; JSL(c, 0xD38D, 0x01D28F); GUARD_JSL(c, sp_call, 0xD38D); } /* public_contact_presentation_byte */
                    uint16_t a_all9 = r->a;
                    uint16_t y_ret5 = r->y;
                    bool overflow_ret5 = r->v;
                    a_hi27 = a_all9 >> 8;
                    y4 = y_ret5;
                    overflow12 = overflow_ret5;
                }
                a_hi28 = a_hi27;
                y5 = y4;
                overflow13 = overflow12;
            }
            r->a = (a_hi28 << 8) | (uint8_t)a;
            r->x = value;
            r->y = y5;
            r->v = overflow13;
            r->mf = 1;
            r->xf = 0;
            publish_hero_facing_pose_and_status_limited_motion(c); return;
        }
        uint8_t value76 = RAM8(0xE071 + value);
        if (!(value76 & 0x80)) {
            r->a = a_hi3 << 8 | (value52 & 0xF0);
            r->x = value;
            r->c = (value52 & 0xF0) >= 0xD0;
            r->z = (value52 & 0xF0 & value76) == 0;
            r->n = value76 & 0x80;
            r->v = value76 & 0x40;
            r->mf = 1;
            publish_hero_facing_pose_and_status_limited_motion(c); return;
        }
        if (value8 != 0) {
            r->a = (a_hi3 << 8) | value8;
            r->x = value;
            r->c = (value52 & 0xF0) >= 0xD0;
            r->z = value8 == 0;
            r->n = value8 & 0x80;
            r->v = value76 & 0x40;
            r->mf = 1;
            publish_hero_facing_pose_and_status_limited_motion(c); return;
        }
        uint8_t value77 = RAM8(0xE01C + value);
        uint8_t value78 = RAM8(0xE045 + value);
        bool x_flag22;
        uint8_t a_hi29;
        uint16_t x2;
        uint16_t y6;
        bool carry2;
        bool overflow14;
        uint8_t data_bank22;
        if ((value77 | value78) != 0) {
            x_flag22 = 0;
            a_hi29 = a_hi3;
            x2 = value;
            y6 = y;
            carry2 = (value52 & 0xF0) >= 0xD0;
            overflow14 = value76 & 0x40;
            data_bank22 = 0x7E;
        } else {
            RAM16_SET(0x00D4, RAM16(0xE05B + value));
            RAM16_SET(0x003A, value);
            RAM16_SET(0x001E, 0);
            RAM16_SET(0xE006 + value, 0);
            uint16_t value80 = RAM16(0xE048 + value);
            RAM16_SET(0xE048 + value, 0);
            RAM8(0x0000 + sp0) = value80 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)value80;
            RAM16_SET(0x0000, value80 & 0x0F);
            uint16_t value81 = RAM16(0x0000);
            r->a = ((value80 >> 4) & 0x0FF0) | value81;
            r->x = value;
            r->c = value80 >> 3 & 0x01;
            r->z = (((value80 >> 4) & 0x0FF0) | value81) == 0;
            r->n = (((value80 >> 4) & 0x0FF0) | value81) & 0x8000;
            r->v = value76 & 0x40;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD478, 0x01E76D); GUARD_JSL(c, sp_call, 0xD478); } /* event_command_map_context_entry */
            uint8_t db_ret8 = r->db;
            bool x_ret9 = r->xf;
            uint16_t a_all10 = r->a;
            uint16_t x_ret10 = r->x;
            uint16_t y_ret6 = r->y;
            bool carry_ret10 = r->c;
            bool overflow_ret6 = r->v;
            x_flag22 = x_ret9;
            a_hi29 = a_all10 >> 8;
            x2 = x_ret10;
            y6 = y_ret6;
            carry2 = carry_ret10;
            overflow14 = overflow_ret6;
            data_bank22 = db_ret8;
        }
        r->a = (a_hi29 << 8) | (uint8_t)a;
        r->x = x2;
        r->y = y6;
        r->c = carry2;
        r->v = overflow14;
        r->mf = 1;
        r->xf = x_flag22;
        r->db = data_bank22;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    uint16_t value82 = RAM16(0x003A);
    if (value == value82) {
        r->a = (a_hi3 << 8) | value8;
        r->x = value;
        r->c = value >= value82;
        r->z = value == value82;
        r->n = (uint16_t)(value - value82) & 0x8000;
        r->mf = 1;
        publish_hero_facing_pose_and_status_limited_motion(c); return;
    }
    if (value != value82) {
        uint8_t value83 = RAM8(0xE048 + value);
        RAM8(0x0000) = value83;
        if ((value83 & 0xF0) == 0) {
            r->a = a_hi3 << 8 | (value83 & 0xF0);
            r->x = value;
            r->c = value >= value82;
            r->z = (value83 & 0xF0) == 0;
            r->n = value83 & 0xF0 & 0x80;
            r->mf = 1;
            publish_hero_facing_pose_and_status_limited_motion(c); return;
        }
        if ((value83 & 0xF0) != 0xD0) {
            if ((value83 & 0xF0) == 0x20) {
                uint8_t value84 = RAM8(0x00F4);
                bool m_flag30;
                bool x_flag32;
                uint8_t a_hi39;
                bool overflow18;
                uint8_t data_bank32;
                uint16_t direct_page30;
                if ((value84 & 4) == 0) {
                    uint8_t value85 = RAM8(0x0000);
                    bool m_flag29;
                    bool x_flag31;
                    uint8_t a_hi38;
                    bool overflow17;
                    uint8_t data_bank31;
                    uint16_t direct_page29;
                    if ((value85 & 2) == 0) {
                        uint8_t value86 = RAM8(0x001F);
                        bool m_flag24;
                        bool x_flag26;
                        uint8_t a_hi33;
                        bool overflow15;
                        uint8_t data_bank26;
                        uint16_t direct_page24;
                        if (value86 != 0) {
                            RAM8(0x001E) = 0;
                            RAM8(0x001F) = 0;
                            uint8_t value87 = RAM8(0x0095);
                            bool m_flag23;
                            bool x_flag25;
                            uint8_t a_hi32;
                            uint8_t data_bank25;
                            uint16_t direct_page23;
                            if (value87 & 0x80) {
                                m_flag23 = 1;
                                x_flag25 = 0;
                                a_hi32 = a_hi3;
                                data_bank25 = 0x7E;
                                direct_page23 = 0;
                            } else {
                                uint8_t value88 = RAM8(0xE02C + value);
                                bool m_flag22;
                                bool x_flag24;
                                uint8_t a_hi31;
                                uint8_t data_bank24;
                                uint16_t direct_page22;
                                if (value88 == 0) {
                                    m_flag22 = 1;
                                    x_flag24 = 0;
                                    a_hi31 = a_hi3;
                                    data_bank24 = 0x7E;
                                    direct_page22 = 0;
                                } else {
                                    bool m_flag21;
                                    bool x_flag23;
                                    uint8_t a_hi30;
                                    uint8_t data_bank23;
                                    uint16_t direct_page21;
                                    if ((value84 & 7) != 0) {
                                        m_flag21 = 1;
                                        x_flag23 = 0;
                                        a_hi30 = a_hi3;
                                        data_bank23 = 0x7E;
                                        direct_page21 = 0;
                                    } else {
                                        r->a = (a_hi3 << 8) | 0xEF;
                                        r->x = value;
                                        r->c = (value83 & 0xF0) >= 0x20;
                                        r->z = 0;
                                        r->n = 1;
                                        r->v = value87 & 0x40;
                                        r->mf = 1;
                                        { const uint16_t sp_call = r->sp; JSR(c, 0xD3D2, 0xC0BB11); GUARD_JSR(c, sp_call, 0xD3D2); } /* external */
                                        uint16_t dp_ret7 = r->dp;
                                        uint8_t db_ret9 = r->db;
                                        bool m_ret5 = r->mf;
                                        bool x_ret11 = r->xf;
                                        uint16_t a_all11 = r->a;
                                        m_flag21 = m_ret5;
                                        x_flag23 = x_ret11;
                                        a_hi30 = a_all11 >> 8;
                                        data_bank23 = db_ret9;
                                        direct_page21 = dp_ret7;
                                    }
                                    m_flag22 = m_flag21;
                                    x_flag24 = x_flag23;
                                    a_hi31 = a_hi30;
                                    data_bank24 = data_bank23;
                                    direct_page22 = direct_page21;
                                }
                                m_flag23 = m_flag22;
                                x_flag25 = x_flag24;
                                a_hi32 = a_hi31;
                                data_bank25 = data_bank24;
                                direct_page23 = direct_page22;
                            }
                            m_flag24 = m_flag23;
                            x_flag26 = x_flag25;
                            a_hi33 = a_hi32;
                            overflow15 = value87 & 0x40;
                            data_bank26 = data_bank25;
                            direct_page24 = direct_page23;
                        } else {
                            m_flag24 = 1;
                            x_flag26 = 0;
                            a_hi33 = a_hi3;
                            overflow15 = overflow;
                            data_bank26 = 0x7E;
                            direct_page24 = 0;
                        }
                        m_flag29 = m_flag24;
                        x_flag31 = x_flag26;
                        a_hi38 = a_hi33;
                        overflow17 = overflow15;
                        data_bank31 = data_bank26;
                        direct_page29 = direct_page24;
                    } else {
                        uint8_t value89 = RAM8(0x001E);
                        bool m_flag28;
                        bool x_flag30;
                        uint8_t a_hi37;
                        bool overflow16;
                        uint8_t data_bank30;
                        uint16_t direct_page28;
                        if (value89 == 0) {
                            m_flag28 = 1;
                            x_flag30 = 0;
                            a_hi37 = a_hi3;
                            overflow16 = overflow;
                            data_bank30 = 0x7E;
                            direct_page28 = 0;
                        } else {
                            RAM8(0x001E) = 0;
                            RAM8(0x001F) = 0;
                            uint8_t value90 = RAM8(0x0095);
                            bool m_flag27;
                            bool x_flag29;
                            uint8_t a_hi36;
                            uint8_t data_bank29;
                            uint16_t direct_page27;
                            if (value90 & 0x80) {
                                m_flag27 = 1;
                                x_flag29 = 0;
                                a_hi36 = a_hi3;
                                data_bank29 = 0x7E;
                                direct_page27 = 0;
                            } else {
                                uint8_t value91 = RAM8(0xE02C + value);
                                bool m_flag26;
                                bool x_flag28;
                                uint8_t a_hi35;
                                uint8_t data_bank28;
                                uint16_t direct_page26;
                                if (value91 == 0) {
                                    m_flag26 = 1;
                                    x_flag28 = 0;
                                    a_hi35 = a_hi3;
                                    data_bank28 = 0x7E;
                                    direct_page26 = 0;
                                } else {
                                    bool m_flag25;
                                    bool x_flag27;
                                    uint8_t a_hi34;
                                    uint8_t data_bank27;
                                    uint16_t direct_page25;
                                    if ((value84 & 7) != 0) {
                                        m_flag25 = 1;
                                        x_flag27 = 0;
                                        a_hi34 = a_hi3;
                                        data_bank27 = 0x7E;
                                        direct_page25 = 0;
                                    } else {
                                        r->a = (a_hi3 << 8) | 0xEF;
                                        r->x = value;
                                        r->c = (value83 & 0xF0) >= 0x20;
                                        r->z = 0;
                                        r->n = 1;
                                        r->v = value90 & 0x40;
                                        r->mf = 1;
                                        { const uint16_t sp_call = r->sp; JSR(c, 0xD3D2, 0xC0BB11); GUARD_JSR(c, sp_call, 0xD3D2); } /* external */
                                        uint16_t dp_ret8 = r->dp;
                                        uint8_t db_ret10 = r->db;
                                        bool m_ret6 = r->mf;
                                        bool x_ret12 = r->xf;
                                        uint16_t a_all12 = r->a;
                                        m_flag25 = m_ret6;
                                        x_flag27 = x_ret12;
                                        a_hi34 = a_all12 >> 8;
                                        data_bank27 = db_ret10;
                                        direct_page25 = dp_ret8;
                                    }
                                    m_flag26 = m_flag25;
                                    x_flag28 = x_flag27;
                                    a_hi35 = a_hi34;
                                    data_bank28 = data_bank27;
                                    direct_page26 = direct_page25;
                                }
                                m_flag27 = m_flag26;
                                x_flag29 = x_flag28;
                                a_hi36 = a_hi35;
                                data_bank29 = data_bank28;
                                direct_page27 = direct_page26;
                            }
                            m_flag28 = m_flag27;
                            x_flag30 = x_flag29;
                            a_hi37 = a_hi36;
                            overflow16 = value90 & 0x40;
                            data_bank30 = data_bank29;
                            direct_page28 = direct_page27;
                        }
                        m_flag29 = m_flag28;
                        x_flag31 = x_flag30;
                        a_hi38 = a_hi37;
                        overflow17 = overflow16;
                        data_bank31 = data_bank30;
                        direct_page29 = direct_page28;
                    }
                    m_flag30 = m_flag29;
                    x_flag32 = x_flag31;
                    a_hi39 = a_hi38;
                    overflow18 = overflow17;
                    data_bank32 = data_bank31;
                    direct_page30 = direct_page29;
                } else {
                    if ((RAM8(0x0000) & 2) != 0) {
                        if (!(value84 & 0x01)) {
                            uint8_t value93 = RAM8(0x0000);
                            RAM8(0x0000) >>= 1;
                            uint8_t value94 = RAM8(0x001E);
                            if (value94 != 0) {
                                uint8_t a21;
                                if (value93 & 0x01) {
                                    a21 = value94;
                                } else {
                                    a21 = value94 ^ 0x80;
                                }
                                RAM8(0x001F) = a21;
                            }
                        }
                    }
                    m_flag30 = 1;
                    x_flag32 = 0;
                    a_hi39 = a_hi3;
                    overflow18 = overflow;
                    data_bank32 = 0x7E;
                    direct_page30 = 0;
                }
                r->a = (a_hi39 << 8) | (uint8_t)a;
                r->x = value;
                r->v = overflow18;
                r->mf = m_flag30;
                r->xf = x_flag32;
                r->db = data_bank32;
                r->dp = direct_page30;
                publish_hero_facing_pose_and_status_limited_motion_v2(c); return;
            }
            if ((value83 & 0xF0) == 0x30) {
                uint8_t value95 = RAM8(0x0000);
                RAM8(0x0000 + sp0) = value95;
                r->a = (a_hi3 << 8) | value95;
                r->x = value;
                r->c = (value83 & 0xF0) >= 0x30;
                r->z = value95 == 0;
                r->n = value95 & 0x80;
                r->mf = 1;
                r->sp -= 1;
                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xD3E2, publish_hero_facing_pose_and_status_limited_motion, sp_in, 2); GUARD_JSR(c, sp_call, 0xD3E2); }
                r->sp += 1;
                uint16_t dp_ret9 = r->dp;
                uint8_t value96 = RAM8(0x0000 + sp0);
                BUS8_SET(c, dp_ret9, ((value96 & 0x0F) >> 2) + 1);
                if ((value96 & 3) == 0) {
                    uint8_t value97 = BUS8_RDP(c, (uint16_t)(dp_ret9 + 0x1F));
                    uint8_t a22;
                    if (!(value97 & 0x80)) {
                        a22 = value97;
                    } else {
                        a22 = (uint8_t)((value97 ^ 0x7F) + 1);
                    }
                    uint8_t value98 = BUS8_RDP(c, dp_ret9);
                    uint8_t a23;
                    if (!((uint8_t)(a22 - value98) & 0x80)) {
                        a23 = (uint8_t)(a22 - value98);
                    } else {
                        a23 = (uint8_t)(((uint8_t)(a22 - value98) ^ 0x7F) + 1) | 0x80;
                    }
                    BUS8_SET(c, (uint16_t)(dp_ret9 + 0x1F), a23);
                    r->c = a22 >= value98;
                    r->v = ((a22 ^ value98) & (a22 ^ (uint8_t)(a22 - value98)) & 0x80) != 0;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                if ((uint8_t)((value96 & 3) - 1) == 0) {
                    uint8_t value99 = BUS8_RDP(c, (uint16_t)(dp_ret9 + 0x1F));
                    uint8_t a24;
                    if (!(value99 & 0x80)) {
                        a24 = value99;
                    } else {
                        a24 = (uint8_t)((value99 ^ 0x7F) + 1);
                    }
                    uint8_t value100 = BUS8_RDP(c, dp_ret9);
                    uint8_t a25;
                    if (!((uint8_t)(a24 + value100) & 0x80)) {
                        a25 = (uint8_t)(a24 + value100);
                    } else {
                        a25 = (uint8_t)(((uint8_t)(a24 + value100) ^ 0x7F) + 1) | 0x80;
                    }
                    BUS8_SET(c, (uint16_t)(dp_ret9 + 0x1F), a25);
                    r->c = a24 + value100 > 0xFF;
                    r->v = ((a24 ^ (uint8_t)(a24 + value100)) & (value100 ^ (uint8_t)(a24 + value100)) & 0x80) != 0;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                if ((uint8_t)((value96 & 3) - 2) == 0) {
                    uint8_t value101 = BUS8_RDP(c, (uint16_t)(dp_ret9 + 0x1E));
                    uint8_t a26;
                    if (!(value101 & 0x80)) {
                        a26 = value101;
                    } else {
                        a26 = (uint8_t)((value101 ^ 0x7F) + 1);
                    }
                    uint8_t value102 = BUS8_RDP(c, dp_ret9);
                    uint8_t a27;
                    if (!((uint8_t)(a26 - value102) & 0x80)) {
                        a27 = (uint8_t)(a26 - value102);
                    } else {
                        a27 = (uint8_t)(((uint8_t)(a26 - value102) ^ 0x7F) + 1) | 0x80;
                    }
                    BUS8_SET(c, (uint16_t)(dp_ret9 + 0x1E), a27);
                    r->c = a26 >= value102;
                    r->v = ((a26 ^ value102) & (a26 ^ (uint8_t)(a26 - value102)) & 0x80) != 0;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint8_t value103 = BUS8_RDP(c, (uint16_t)(dp_ret9 + 0x1E));
                uint8_t a28;
                if (!(value103 & 0x80)) {
                    a28 = value103;
                } else {
                    a28 = (uint8_t)((value103 ^ 0x7F) + 1);
                }
                uint8_t value104 = BUS8_RDP(c, dp_ret9);
                uint8_t a29;
                if (!((uint8_t)(a28 + value104) & 0x80)) {
                    a29 = (uint8_t)(a28 + value104);
                } else {
                    a29 = (uint8_t)(((uint8_t)(a28 + value104) ^ 0x7F) + 1) | 0x80;
                }
                BUS8_SET(c, (uint16_t)(dp_ret9 + 0x1E), a29);
                r->c = a28 + value104 > 0xFF;
                r->v = ((a28 ^ (uint8_t)(a28 + value104)) & (value104 ^ (uint8_t)(a28 + value104)) & 0x80) != 0;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t a_hi41;
            uint16_t y8;
            bool overflow20;
            if ((value83 & 0xF0) != 0x40) {
                a_hi41 = a_hi3;
                y8 = y;
                overflow20 = overflow;
            } else {
                uint8_t value105 = RAM8(0x0000);
                uint8_t value106 = RAM8(0x0095);
                uint8_t a_hi40;
                uint16_t y7;
                bool overflow19;
                if (((value105 & 0x0F) | 0x70) == value106) {
                    a_hi40 = a_hi3;
                    y7 = y;
                    overflow19 = overflow;
                } else {
                    r->a = (a_hi3 << 8) | ((value105 & 0x0F) | 0x70 | 0x80);
                    r->x = value;
                    r->c = ((value105 & 0x0F) | 0x70) >= value106;
                    r->z = ((value105 & 0x0F) | 0x70 | 0x80) == 0;
                    r->n = ((value105 & 0x0F) | 0x70 | 0x80) & 0x80;
                    r->mf = 1;
                    { const uint16_t sp_call = r->sp; JSL(c, 0xD38D, 0x01D28F); GUARD_JSL(c, sp_call, 0xD38D); } /* public_contact_presentation_byte */
                    uint16_t a_all14 = r->a;
                    uint16_t y_ret8 = r->y;
                    bool overflow_ret8 = r->v;
                    a_hi40 = a_all14 >> 8;
                    y7 = y_ret8;
                    overflow19 = overflow_ret8;
                }
                a_hi41 = a_hi40;
                y8 = y7;
                overflow20 = overflow19;
            }
            r->a = (a_hi41 << 8) | (uint8_t)a;
            r->x = value;
            r->y = y8;
            r->v = overflow20;
            r->mf = 1;
            r->xf = 0;
            publish_hero_facing_pose_and_status_limited_motion(c); return;
        }
        uint8_t value107 = RAM8(0xE071 + value);
        if (!(value107 & 0x80)) {
            r->a = a_hi3 << 8 | (value83 & 0xF0);
            r->x = value;
            r->c = (value83 & 0xF0) >= 0xD0;
            r->z = (value83 & 0xF0 & value107) == 0;
            r->n = value107 & 0x80;
            r->v = value107 & 0x40;
            r->mf = 1;
            publish_hero_facing_pose_and_status_limited_motion(c); return;
        }
        if (value8 != 0) {
            r->a = (a_hi3 << 8) | value8;
            r->x = value;
            r->c = (value83 & 0xF0) >= 0xD0;
            r->z = value8 == 0;
            r->n = value8 & 0x80;
            r->v = value107 & 0x40;
            r->mf = 1;
            publish_hero_facing_pose_and_status_limited_motion(c); return;
        }
        uint8_t value108 = RAM8(0xE01C + value);
        uint8_t value109 = RAM8(0xE045 + value);
        bool x_flag33;
        uint8_t a_hi42;
        uint16_t x3;
        uint16_t y9;
        bool carry3;
        bool overflow21;
        uint8_t data_bank33;
        if ((value108 | value109) != 0) {
            x_flag33 = 0;
            a_hi42 = a_hi3;
            x3 = value;
            y9 = y;
            carry3 = (value83 & 0xF0) >= 0xD0;
            overflow21 = value107 & 0x40;
            data_bank33 = 0x7E;
        } else {
            RAM16_SET(0x00D4, RAM16(0xE05B + value));
            RAM16_SET(0x003A, value);
            RAM16_SET(0x001E, 0);
            RAM16_SET(0xE006 + value, 0);
            uint16_t value111 = RAM16(0xE048 + value);
            RAM16_SET(0xE048 + value, 0);
            RAM8(0x0000 + sp0) = value111 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)value111;
            RAM16_SET(0x0000, value111 & 0x0F);
            uint16_t value112 = RAM16(0x0000);
            r->a = ((value111 >> 4) & 0x0FF0) | value112;
            r->x = value;
            r->c = value111 >> 3 & 0x01;
            r->z = (((value111 >> 4) & 0x0FF0) | value112) == 0;
            r->n = (((value111 >> 4) & 0x0FF0) | value112) & 0x8000;
            r->v = value107 & 0x40;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD478, 0x01E76D); GUARD_JSL(c, sp_call, 0xD478); } /* event_command_map_context_entry */
            uint8_t db_ret12 = r->db;
            bool x_ret14 = r->xf;
            uint16_t a_all15 = r->a;
            uint16_t x_ret15 = r->x;
            uint16_t y_ret9 = r->y;
            bool carry_ret15 = r->c;
            bool overflow_ret9 = r->v;
            x_flag33 = x_ret14;
            a_hi42 = a_all15 >> 8;
            x3 = x_ret15;
            y9 = y_ret9;
            carry3 = carry_ret15;
            overflow21 = overflow_ret9;
            data_bank33 = db_ret12;
        }
        r->a = (a_hi42 << 8) | (uint8_t)a;
        r->x = x3;
        r->y = y9;
        r->c = carry3;
        r->v = overflow21;
        r->mf = 1;
        r->xf = x_flag33;
        r->db = data_bank33;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    uint16_t value113 = RAM16(0x00D4);
    if (value == value113) {
        r->a = (a_hi3 << 8) | value8;
        r->x = value;
        r->c = value >= value113;
        r->z = value == value113;
        r->n = (uint16_t)(value - value113) & 0x8000;
        r->mf = 1;
        publish_hero_facing_pose_and_status_limited_motion(c); return;
    }
    if (RAM8(0xE01B + value) != 0) {
        uint8_t value115 = RAM8(0x001E);
        if (value115 != 0) {
            RAM8(0x001E) = (value115 >> 7 << 7) | 1;
        }
        uint8_t value116 = RAM8(0x001F);
        if (value116 != 0) {
            RAM8(0x001F) = (value116 >> 7 << 7) | 1;
        }
    } else {
        if (RAM8(0xE01A + value) >= 2) {
            uint8_t value118 = RAM8(0x001E);
            if (value118 != 0) {
                RAM8(0x001E) = (value118 >> 7 << 7) | 1;
            }
            uint8_t value119 = RAM8(0x001F);
            if (value119 != 0) {
                RAM8(0x001F) = (value119 >> 7 << 7) | 1;
            }
        }
    }
    uint8_t value120 = RAM8(0xE048 + value);
    RAM8(0x0000) = value120;
    if ((value120 & 0xF0) == 0) {
        r->a = a_hi3 << 8 | (value120 & 0xF0);
        r->x = value;
        r->z = (value120 & 0xF0) == 0;
        r->n = value120 & 0xF0 & 0x80;
        r->mf = 1;
        publish_hero_facing_pose_and_status_limited_motion(c); return;
    }
    if ((value120 & 0xF0) != 0xD0) {
        if ((value120 & 0xF0) == 0x20) {
            uint8_t value121 = RAM8(0x00F4);
            bool m_flag40;
            bool x_flag43;
            uint8_t a_hi52;
            bool overflow25;
            uint8_t data_bank43;
            uint16_t direct_page40;
            if ((value121 & 4) == 0) {
                uint8_t value122 = RAM8(0x0000);
                bool m_flag39;
                bool x_flag42;
                uint8_t a_hi51;
                bool overflow24;
                uint8_t data_bank42;
                uint16_t direct_page39;
                if ((value122 & 2) == 0) {
                    uint8_t value123 = RAM8(0x001F);
                    bool m_flag34;
                    bool x_flag37;
                    uint8_t a_hi46;
                    bool overflow22;
                    uint8_t data_bank37;
                    uint16_t direct_page34;
                    if (value123 != 0) {
                        RAM8(0x001E) = 0;
                        RAM8(0x001F) = 0;
                        uint8_t value124 = RAM8(0x0095);
                        bool m_flag33;
                        bool x_flag36;
                        uint8_t a_hi45;
                        uint8_t data_bank36;
                        uint16_t direct_page33;
                        if (value124 & 0x80) {
                            m_flag33 = 1;
                            x_flag36 = 0;
                            a_hi45 = a_hi3;
                            data_bank36 = 0x7E;
                            direct_page33 = 0;
                        } else {
                            uint8_t value125 = RAM8(0xE02C + value);
                            bool m_flag32;
                            bool x_flag35;
                            uint8_t a_hi44;
                            uint8_t data_bank35;
                            uint16_t direct_page32;
                            if (value125 == 0) {
                                m_flag32 = 1;
                                x_flag35 = 0;
                                a_hi44 = a_hi3;
                                data_bank35 = 0x7E;
                                direct_page32 = 0;
                            } else {
                                bool m_flag31;
                                bool x_flag34;
                                uint8_t a_hi43;
                                uint8_t data_bank34;
                                uint16_t direct_page31;
                                if ((value121 & 7) != 0) {
                                    m_flag31 = 1;
                                    x_flag34 = 0;
                                    a_hi43 = a_hi3;
                                    data_bank34 = 0x7E;
                                    direct_page31 = 0;
                                } else {
                                    r->a = (a_hi3 << 8) | 0xEF;
                                    r->x = value;
                                    r->c = (value120 & 0xF0) >= 0x20;
                                    r->z = 0;
                                    r->n = 1;
                                    r->v = value124 & 0x40;
                                    r->mf = 1;
                                    { const uint16_t sp_call = r->sp; JSR(c, 0xD3D2, 0xC0BB11); GUARD_JSR(c, sp_call, 0xD3D2); } /* external */
                                    uint16_t dp_ret10 = r->dp;
                                    uint8_t db_ret13 = r->db;
                                    bool m_ret7 = r->mf;
                                    bool x_ret16 = r->xf;
                                    uint16_t a_all16 = r->a;
                                    m_flag31 = m_ret7;
                                    x_flag34 = x_ret16;
                                    a_hi43 = a_all16 >> 8;
                                    data_bank34 = db_ret13;
                                    direct_page31 = dp_ret10;
                                }
                                m_flag32 = m_flag31;
                                x_flag35 = x_flag34;
                                a_hi44 = a_hi43;
                                data_bank35 = data_bank34;
                                direct_page32 = direct_page31;
                            }
                            m_flag33 = m_flag32;
                            x_flag36 = x_flag35;
                            a_hi45 = a_hi44;
                            data_bank36 = data_bank35;
                            direct_page33 = direct_page32;
                        }
                        m_flag34 = m_flag33;
                        x_flag37 = x_flag36;
                        a_hi46 = a_hi45;
                        overflow22 = value124 & 0x40;
                        data_bank37 = data_bank36;
                        direct_page34 = direct_page33;
                    } else {
                        m_flag34 = 1;
                        x_flag37 = 0;
                        a_hi46 = a_hi3;
                        overflow22 = overflow;
                        data_bank37 = 0x7E;
                        direct_page34 = 0;
                    }
                    m_flag39 = m_flag34;
                    x_flag42 = x_flag37;
                    a_hi51 = a_hi46;
                    overflow24 = overflow22;
                    data_bank42 = data_bank37;
                    direct_page39 = direct_page34;
                } else {
                    uint8_t value126 = RAM8(0x001E);
                    bool m_flag38;
                    bool x_flag41;
                    uint8_t a_hi50;
                    bool overflow23;
                    uint8_t data_bank41;
                    uint16_t direct_page38;
                    if (value126 == 0) {
                        m_flag38 = 1;
                        x_flag41 = 0;
                        a_hi50 = a_hi3;
                        overflow23 = overflow;
                        data_bank41 = 0x7E;
                        direct_page38 = 0;
                    } else {
                        RAM8(0x001E) = 0;
                        RAM8(0x001F) = 0;
                        uint8_t value127 = RAM8(0x0095);
                        bool m_flag37;
                        bool x_flag40;
                        uint8_t a_hi49;
                        uint8_t data_bank40;
                        uint16_t direct_page37;
                        if (value127 & 0x80) {
                            m_flag37 = 1;
                            x_flag40 = 0;
                            a_hi49 = a_hi3;
                            data_bank40 = 0x7E;
                            direct_page37 = 0;
                        } else {
                            uint8_t value128 = RAM8(0xE02C + value);
                            bool m_flag36;
                            bool x_flag39;
                            uint8_t a_hi48;
                            uint8_t data_bank39;
                            uint16_t direct_page36;
                            if (value128 == 0) {
                                m_flag36 = 1;
                                x_flag39 = 0;
                                a_hi48 = a_hi3;
                                data_bank39 = 0x7E;
                                direct_page36 = 0;
                            } else {
                                bool m_flag35;
                                bool x_flag38;
                                uint8_t a_hi47;
                                uint8_t data_bank38;
                                uint16_t direct_page35;
                                if ((value121 & 7) != 0) {
                                    m_flag35 = 1;
                                    x_flag38 = 0;
                                    a_hi47 = a_hi3;
                                    data_bank38 = 0x7E;
                                    direct_page35 = 0;
                                } else {
                                    r->a = (a_hi3 << 8) | 0xEF;
                                    r->x = value;
                                    r->c = (value120 & 0xF0) >= 0x20;
                                    r->z = 0;
                                    r->n = 1;
                                    r->v = value127 & 0x40;
                                    r->mf = 1;
                                    { const uint16_t sp_call = r->sp; JSR(c, 0xD3D2, 0xC0BB11); GUARD_JSR(c, sp_call, 0xD3D2); } /* external */
                                    uint16_t dp_ret11 = r->dp;
                                    uint8_t db_ret14 = r->db;
                                    bool m_ret8 = r->mf;
                                    bool x_ret17 = r->xf;
                                    uint16_t a_all17 = r->a;
                                    m_flag35 = m_ret8;
                                    x_flag38 = x_ret17;
                                    a_hi47 = a_all17 >> 8;
                                    data_bank38 = db_ret14;
                                    direct_page35 = dp_ret11;
                                }
                                m_flag36 = m_flag35;
                                x_flag39 = x_flag38;
                                a_hi48 = a_hi47;
                                data_bank39 = data_bank38;
                                direct_page36 = direct_page35;
                            }
                            m_flag37 = m_flag36;
                            x_flag40 = x_flag39;
                            a_hi49 = a_hi48;
                            data_bank40 = data_bank39;
                            direct_page37 = direct_page36;
                        }
                        m_flag38 = m_flag37;
                        x_flag41 = x_flag40;
                        a_hi50 = a_hi49;
                        overflow23 = value127 & 0x40;
                        data_bank41 = data_bank40;
                        direct_page38 = direct_page37;
                    }
                    m_flag39 = m_flag38;
                    x_flag42 = x_flag41;
                    a_hi51 = a_hi50;
                    overflow24 = overflow23;
                    data_bank42 = data_bank41;
                    direct_page39 = direct_page38;
                }
                m_flag40 = m_flag39;
                x_flag43 = x_flag42;
                a_hi52 = a_hi51;
                overflow25 = overflow24;
                data_bank43 = data_bank42;
                direct_page40 = direct_page39;
            } else {
                if ((RAM8(0x0000) & 2) != 0) {
                    if (!(value121 & 0x01)) {
                        uint8_t value130 = RAM8(0x0000);
                        RAM8(0x0000) >>= 1;
                        uint8_t value131 = RAM8(0x001E);
                        if (value131 != 0) {
                            uint8_t a30;
                            if (value130 & 0x01) {
                                a30 = value131;
                            } else {
                                a30 = value131 ^ 0x80;
                            }
                            RAM8(0x001F) = a30;
                        }
                    }
                }
                m_flag40 = 1;
                x_flag43 = 0;
                a_hi52 = a_hi3;
                overflow25 = overflow;
                data_bank43 = 0x7E;
                direct_page40 = 0;
            }
            r->a = (a_hi52 << 8) | (uint8_t)a;
            r->x = value;
            r->v = overflow25;
            r->mf = m_flag40;
            r->xf = x_flag43;
            r->db = data_bank43;
            r->dp = direct_page40;
            publish_hero_facing_pose_and_status_limited_motion_v2(c); return;
        }
        if ((value120 & 0xF0) == 0x30) {
            uint8_t value132 = RAM8(0x0000);
            RAM8(0x0000 + sp0) = value132;
            r->a = (a_hi3 << 8) | value132;
            r->x = value;
            r->c = (value120 & 0xF0) >= 0x30;
            r->z = value132 == 0;
            r->n = value132 & 0x80;
            r->mf = 1;
            r->sp -= 1;
            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xD3E2, publish_hero_facing_pose_and_status_limited_motion, sp_in, 2); GUARD_JSR(c, sp_call, 0xD3E2); }
            r->sp += 1;
            uint16_t dp_ret12 = r->dp;
            uint8_t value133 = RAM8(0x0000 + sp0);
            BUS8_SET(c, dp_ret12, ((value133 & 0x0F) >> 2) + 1);
            if ((value133 & 3) == 0) {
                uint8_t value134 = BUS8_RDP(c, (uint16_t)(dp_ret12 + 0x1F));
                uint8_t a31;
                if (!(value134 & 0x80)) {
                    a31 = value134;
                } else {
                    a31 = (uint8_t)((value134 ^ 0x7F) + 1);
                }
                uint8_t value135 = BUS8_RDP(c, dp_ret12);
                uint8_t a32;
                if (!((uint8_t)(a31 - value135) & 0x80)) {
                    a32 = (uint8_t)(a31 - value135);
                } else {
                    a32 = (uint8_t)(((uint8_t)(a31 - value135) ^ 0x7F) + 1) | 0x80;
                }
                BUS8_SET(c, (uint16_t)(dp_ret12 + 0x1F), a32);
                r->c = a31 >= value135;
                r->v = ((a31 ^ value135) & (a31 ^ (uint8_t)(a31 - value135)) & 0x80) != 0;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if ((uint8_t)((value133 & 3) - 1) == 0) {
                uint8_t value136 = BUS8_RDP(c, (uint16_t)(dp_ret12 + 0x1F));
                uint8_t a33;
                if (!(value136 & 0x80)) {
                    a33 = value136;
                } else {
                    a33 = (uint8_t)((value136 ^ 0x7F) + 1);
                }
                uint8_t value137 = BUS8_RDP(c, dp_ret12);
                uint8_t a34;
                if (!((uint8_t)(a33 + value137) & 0x80)) {
                    a34 = (uint8_t)(a33 + value137);
                } else {
                    a34 = (uint8_t)(((uint8_t)(a33 + value137) ^ 0x7F) + 1) | 0x80;
                }
                BUS8_SET(c, (uint16_t)(dp_ret12 + 0x1F), a34);
                r->c = a33 + value137 > 0xFF;
                r->v = ((a33 ^ (uint8_t)(a33 + value137)) & (value137 ^ (uint8_t)(a33 + value137)) & 0x80) != 0;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if ((uint8_t)((value133 & 3) - 2) == 0) {
                uint8_t value138 = BUS8_RDP(c, (uint16_t)(dp_ret12 + 0x1E));
                uint8_t a35;
                if (!(value138 & 0x80)) {
                    a35 = value138;
                } else {
                    a35 = (uint8_t)((value138 ^ 0x7F) + 1);
                }
                uint8_t value139 = BUS8_RDP(c, dp_ret12);
                uint8_t a36;
                if (!((uint8_t)(a35 - value139) & 0x80)) {
                    a36 = (uint8_t)(a35 - value139);
                } else {
                    a36 = (uint8_t)(((uint8_t)(a35 - value139) ^ 0x7F) + 1) | 0x80;
                }
                BUS8_SET(c, (uint16_t)(dp_ret12 + 0x1E), a36);
                r->c = a35 >= value139;
                r->v = ((a35 ^ value139) & (a35 ^ (uint8_t)(a35 - value139)) & 0x80) != 0;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t value140 = BUS8_RDP(c, (uint16_t)(dp_ret12 + 0x1E));
            uint8_t a37;
            if (!(value140 & 0x80)) {
                a37 = value140;
            } else {
                a37 = (uint8_t)((value140 ^ 0x7F) + 1);
            }
            uint8_t value141 = BUS8_RDP(c, dp_ret12);
            uint8_t a38;
            if (!((uint8_t)(a37 + value141) & 0x80)) {
                a38 = (uint8_t)(a37 + value141);
            } else {
                a38 = (uint8_t)(((uint8_t)(a37 + value141) ^ 0x7F) + 1) | 0x80;
            }
            BUS8_SET(c, (uint16_t)(dp_ret12 + 0x1E), a38);
            r->c = a37 + value141 > 0xFF;
            r->v = ((a37 ^ (uint8_t)(a37 + value141)) & (value141 ^ (uint8_t)(a37 + value141)) & 0x80) != 0;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint8_t a_hi54;
        uint16_t y11;
        bool overflow27;
        if ((value120 & 0xF0) != 0x40) {
            a_hi54 = a_hi3;
            y11 = y;
            overflow27 = overflow;
        } else {
            uint8_t value142 = RAM8(0x0000);
            uint8_t value143 = RAM8(0x0095);
            uint8_t a_hi53;
            uint16_t y10;
            bool overflow26;
            if (((value142 & 0x0F) | 0x70) == value143) {
                a_hi53 = a_hi3;
                y10 = y;
                overflow26 = overflow;
            } else {
                r->a = (a_hi3 << 8) | ((value142 & 0x0F) | 0x70 | 0x80);
                r->x = value;
                r->c = ((value142 & 0x0F) | 0x70) >= value143;
                r->z = ((value142 & 0x0F) | 0x70 | 0x80) == 0;
                r->n = ((value142 & 0x0F) | 0x70 | 0x80) & 0x80;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSL(c, 0xD38D, 0x01D28F); GUARD_JSL(c, sp_call, 0xD38D); } /* public_contact_presentation_byte */
                uint16_t a_all19 = r->a;
                uint16_t y_ret11 = r->y;
                bool overflow_ret11 = r->v;
                a_hi53 = a_all19 >> 8;
                y10 = y_ret11;
                overflow26 = overflow_ret11;
            }
            a_hi54 = a_hi53;
            y11 = y10;
            overflow27 = overflow26;
        }
        r->a = (a_hi54 << 8) | (uint8_t)a;
        r->x = value;
        r->y = y11;
        r->v = overflow27;
        r->mf = 1;
        r->xf = 0;
        publish_hero_facing_pose_and_status_limited_motion(c); return;
    }
    uint8_t value144 = RAM8(0xE071 + value);
    if (!(value144 & 0x80)) {
        r->a = a_hi3 << 8 | (value120 & 0xF0);
        r->x = value;
        r->c = (value120 & 0xF0) >= 0xD0;
        r->z = (value120 & 0xF0 & value144) == 0;
        r->n = value144 & 0x80;
        r->v = value144 & 0x40;
        r->mf = 1;
        publish_hero_facing_pose_and_status_limited_motion(c); return;
    }
    if (value8 != 0) {
        r->a = (a_hi3 << 8) | value8;
        r->x = value;
        r->c = (value120 & 0xF0) >= 0xD0;
        r->z = value8 == 0;
        r->n = value8 & 0x80;
        r->v = value144 & 0x40;
        r->mf = 1;
        publish_hero_facing_pose_and_status_limited_motion(c); return;
    }
    uint8_t value145 = RAM8(0xE01C + value);
    uint8_t value146 = RAM8(0xE045 + value);
    bool x_flag44;
    uint8_t a_hi55;
    uint16_t x4;
    uint16_t y12;
    bool carry4;
    bool overflow28;
    uint8_t data_bank44;
    if ((value145 | value146) != 0) {
        x_flag44 = 0;
        a_hi55 = a_hi3;
        x4 = value;
        y12 = y;
        carry4 = (value120 & 0xF0) >= 0xD0;
        overflow28 = value144 & 0x40;
        data_bank44 = 0x7E;
    } else {
        RAM16_SET(0x00D4, RAM16(0xE05B + value));
        RAM16_SET(0x003A, value);
        RAM16_SET(0x001E, 0);
        RAM16_SET(0xE006 + value, 0);
        uint16_t value148 = RAM16(0xE048 + value);
        RAM16_SET(0xE048 + value, 0);
        RAM8(0x0000 + sp0) = value148 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)value148;
        RAM16_SET(0x0000, value148 & 0x0F);
        uint16_t value149 = RAM16(0x0000);
        r->a = ((value148 >> 4) & 0x0FF0) | value149;
        r->x = value;
        r->c = value148 >> 3 & 0x01;
        r->z = (((value148 >> 4) & 0x0FF0) | value149) == 0;
        r->n = (((value148 >> 4) & 0x0FF0) | value149) & 0x8000;
        r->v = value144 & 0x40;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD478, 0x01E76D); GUARD_JSL(c, sp_call, 0xD478); } /* event_command_map_context_entry */
        uint8_t db_ret16 = r->db;
        bool x_ret19 = r->xf;
        uint16_t a_all20 = r->a;
        uint16_t x_ret20 = r->x;
        uint16_t y_ret12 = r->y;
        bool carry_ret20 = r->c;
        bool overflow_ret12 = r->v;
        x_flag44 = x_ret19;
        a_hi55 = a_all20 >> 8;
        x4 = x_ret20;
        y12 = y_ret12;
        carry4 = carry_ret20;
        overflow28 = overflow_ret12;
        data_bank44 = db_ret16;
    }
    r->a = (a_hi55 << 8) | (uint8_t)a;
    r->x = x4;
    r->y = y12;
    r->c = carry4;
    r->v = overflow28;
    r->mf = 1;
    r->xf = x_flag44;
    r->db = data_bank44;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0D2E0, SOM_RTS, "gen", apply_actor_ground_contact_effect_to_live_motion, 0, L_B | L_X | L_Y | L_C | L_V, 10, 0, 0, 736, 363)

/* C0D482 publish_hero_facing_pose_and_status_limited_motion   [class A, 326 bytes, 153 instructions]
 * Source: src/rom/apply_actor_ground_contact_effect_to_live_motion.s
 * Subroutine of apply_actor_ground_contact_effect_to_live_motion, translated in place.
 * Entry: M=any X=any DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void publish_hero_facing_pose_and_status_limited_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0010);
    if (value >= 0x0600) {
        RAM8(0xE029 + value) = 0;
        SET_A8(r, 0);
        r->x = value;
        r->c = value >= 0x0600;
        r->z = 1;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if ((RAM8(0xE01C + value) | RAM8(0xE060 + value)) != 0) {
        RAM8(0xE029 + value) = 0;
        SET_A8(r, 0);
        r->x = value;
        r->c = value >= 0x0600;
        r->z = 1;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value4 = RAM8(0xE02F + value);
    if (value4 != 0) {
        RAM8(0xE011 + value) = value4;
        SET_A8(r, value4);
        r->x = value;
        r->c = value >= 0x0600;
        r->z = value4 == 0;
        r->n = value4 & 0x80;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if (RAM8(0xE067 + value) != 0) {
        RAM8(0xE029 + value) = 0;
        SET_A8(r, 0);
        r->x = value;
        r->c = value >= 0x0600;
        r->z = 1;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value6 = RAM16(ACTOR_STATUS + value);
    if ((value6 & 0x4160) != 0) {
        RAM8(0xE029 + value) = 0;
        r->a = (value6 >> 8 << 8) | 0;
        r->x = value;
        r->c = value >= 0x0600;
        r->z = 1;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t a39;
    uint8_t a_hi15;
    bool carry29;
    bool zero13;
    bool negative11;
    bool overflow8;
    if ((value6 & 0x8404) == 0) {
        uint8_t value7 = RAM8(0xE01D + value);
        if ((value7 & 0x30) == 0) {
            uint8_t value8 = RAM8(0xE006 + value);
            if (value8 == 0) {
                uint8_t value9 = RAM8(0xE007 + value);
                if (value9 != 0) {
                    uint8_t a1;
                    if (value9 & 0x80) {
                        a1 = 0;
                    } else {
                        a1 = 1;
                    }
                    RAM8(0xE010 + value) = a1;
                }
            } else {
                uint8_t a2;
                if (value8 & 0x80) {
                    a2 = 0x82;
                } else {
                    a2 = 2;
                }
                RAM8(0xE010 + value) = a2;
            }
        } else {
            RAM8(0xE01D + value) = value7 & 0x80;
        }
        uint8_t value10 = RAM8(0x001E);
        uint8_t a33;
        uint8_t a_hi14;
        bool carry22;
        bool zero9;
        bool negative7;
        bool overflow7;
        if (value10 != 0) {
            uint8_t value11 = RAM8(0xE029 + value);
            uint8_t a12;
            uint8_t a_hi6;
            bool carry6;
            bool overflow2;
            if (!(value11 & 0x80)) {
                uint8_t value12 = RAM8(0x00ED);
                uint8_t a6;
                uint8_t a_hi2;
                bool carry2;
                if (!(value12 & 0x80)) {
                    uint8_t a3;
                    if ((value10 & 0x7F) < 3) {
                        a3 = 1;
                    } else {
                        a3 = 2;
                    }
                    a6 = a3;
                    a_hi2 = value11;
                    carry2 = (value10 & 0x7F) >= 3;
                } else {
                    uint8_t value13 = RAM8(0xE01A + value);
                    uint8_t value14 = RAM8(0xE01B + value);
                    uint8_t a5;
                    uint8_t a_hi1;
                    bool carry1;
                    if ((value13 | value14) == 0) {
                        uint8_t a4;
                        if ((value10 & 0x7F) < 3) {
                            a4 = 1;
                        } else {
                            a4 = 2;
                        }
                        a5 = a4;
                        a_hi1 = value13 | value14;
                        carry1 = (value10 & 0x7F) >= 3;
                    } else {
                        a5 = 4;
                        a_hi1 = value10;
                        carry1 = value >= 0x0600;
                    }
                    a6 = a5;
                    a_hi2 = a_hi1;
                    carry2 = carry1;
                }
                a12 = a6;
                a_hi6 = a_hi2;
                carry6 = carry2;
                overflow2 = value12 & 0x40;
            } else {
                RAM8(0xE029 + value) = 0;
                uint8_t a11;
                uint8_t a_hi5;
                bool carry5;
                bool overflow1;
                if (1) {
                    a11 = 8;
                    a_hi5 = value10;
                    carry5 = value >= 0x0600;
                    overflow1 = overflow;
                } else {
                    uint8_t value15 = RAM8(0x00ED);
                    uint8_t a10;
                    uint8_t a_hi4;
                    bool carry4;
                    if (!(value15 & 0x80)) {
                        uint8_t a7;
                        if ((value10 & 0x7F) < 3) {
                            a7 = 1;
                        } else {
                            a7 = 2;
                        }
                        a10 = a7;
                        a_hi4 = 8;
                        carry4 = (value10 & 0x7F) >= 3;
                    } else {
                        uint8_t value16 = RAM8(0xE01A + value);
                        uint8_t value17 = RAM8(0xE01B + value);
                        uint8_t a9;
                        uint8_t a_hi3;
                        bool carry3;
                        if ((value16 | value17) == 0) {
                            uint8_t a8;
                            if ((value10 & 0x7F) < 3) {
                                a8 = 1;
                            } else {
                                a8 = 2;
                            }
                            a9 = a8;
                            a_hi3 = value16 | value17;
                            carry3 = (value10 & 0x7F) >= 3;
                        } else {
                            a9 = 4;
                            a_hi3 = value10;
                            carry3 = value >= 0x0600;
                        }
                        a10 = a9;
                        a_hi4 = a_hi3;
                        carry4 = carry3;
                    }
                    a11 = a10;
                    a_hi5 = a_hi4;
                    carry5 = carry4;
                    overflow1 = value15 & 0x40;
                }
                a12 = a11;
                a_hi6 = a_hi5;
                carry6 = carry5;
                overflow2 = overflow1;
            }
            a33 = a12;
            a_hi14 = a_hi6;
            carry22 = carry6;
            zero9 = 0;
            negative7 = 0;
            overflow7 = overflow2;
        } else {
            uint8_t value18 = RAM8(0x001F);
            uint8_t a32;
            uint8_t a_hi13;
            bool carry21;
            bool zero8;
            bool negative6;
            bool overflow6;
            if (value18 != 0) {
                uint8_t value19 = RAM8(0xE029 + value);
                uint8_t a22;
                uint8_t a_hi12;
                bool carry12;
                bool overflow4;
                if (!(value19 & 0x80)) {
                    uint8_t value20 = RAM8(0x00ED);
                    uint8_t a16;
                    uint8_t a_hi8;
                    bool carry8;
                    if (!(value20 & 0x80)) {
                        uint8_t a13;
                        if ((value18 & 0x7F) < 3) {
                            a13 = 1;
                        } else {
                            a13 = 2;
                        }
                        a16 = a13;
                        a_hi8 = value19;
                        carry8 = (value18 & 0x7F) >= 3;
                    } else {
                        uint8_t value21 = RAM8(0xE01A + value);
                        uint8_t value22 = RAM8(0xE01B + value);
                        uint8_t a15;
                        uint8_t a_hi7;
                        bool carry7;
                        if ((value21 | value22) == 0) {
                            uint8_t a14;
                            if ((value18 & 0x7F) < 3) {
                                a14 = 1;
                            } else {
                                a14 = 2;
                            }
                            a15 = a14;
                            a_hi7 = value21 | value22;
                            carry7 = (value18 & 0x7F) >= 3;
                        } else {
                            a15 = 4;
                            a_hi7 = value18;
                            carry7 = value >= 0x0600;
                        }
                        a16 = a15;
                        a_hi8 = a_hi7;
                        carry8 = carry7;
                    }
                    a22 = a16;
                    a_hi12 = a_hi8;
                    carry12 = carry8;
                    overflow4 = value20 & 0x40;
                } else {
                    RAM8(0xE029 + value) = 0;
                    uint8_t a21;
                    uint8_t a_hi11;
                    bool carry11;
                    bool overflow3;
                    if (1) {
                        a21 = 8;
                        a_hi11 = value18;
                        carry11 = value >= 0x0600;
                        overflow3 = overflow;
                    } else {
                        uint8_t value23 = RAM8(0x00ED);
                        uint8_t a20;
                        uint8_t a_hi10;
                        bool carry10;
                        if (!(value23 & 0x80)) {
                            uint8_t a17;
                            if ((value18 & 0x7F) < 3) {
                                a17 = 1;
                            } else {
                                a17 = 2;
                            }
                            a20 = a17;
                            a_hi10 = 8;
                            carry10 = (value18 & 0x7F) >= 3;
                        } else {
                            uint8_t value24 = RAM8(0xE01A + value);
                            uint8_t value25 = RAM8(0xE01B + value);
                            uint8_t a19;
                            uint8_t a_hi9;
                            bool carry9;
                            if ((value24 | value25) == 0) {
                                uint8_t a18;
                                if ((value18 & 0x7F) < 3) {
                                    a18 = 1;
                                } else {
                                    a18 = 2;
                                }
                                a19 = a18;
                                a_hi9 = value24 | value25;
                                carry9 = (value18 & 0x7F) >= 3;
                            } else {
                                a19 = 4;
                                a_hi9 = value18;
                                carry9 = value >= 0x0600;
                            }
                            a20 = a19;
                            a_hi10 = a_hi9;
                            carry10 = carry9;
                        }
                        a21 = a20;
                        a_hi11 = a_hi10;
                        carry11 = carry10;
                        overflow3 = value23 & 0x40;
                    }
                    a22 = a21;
                    a_hi12 = a_hi11;
                    carry12 = carry11;
                    overflow4 = overflow3;
                }
                a32 = a22;
                a_hi13 = a_hi12;
                carry21 = carry12;
                zero8 = 0;
                negative6 = 0;
                overflow6 = overflow4;
            } else {
                uint8_t value26 = RAM8(0xE029 + value);
                uint8_t a31;
                bool carry20;
                bool zero7;
                bool negative5;
                bool overflow5;
                if (value26 & 0x80) {
                    RAM8(0xE029 + value) = 0;
                    uint8_t a28;
                    bool carry19;
                    bool zero4;
                    bool negative4;
                    if (1) {
                        a28 = 8;
                        carry19 = value >= 0x0600;
                        zero4 = 0;
                        negative4 = 0;
                    } else {
                        uint8_t value27 = RAM8(0x00FF);
                        bool carry17;
                        if (value27 != 0) {
                            carry17 = value >= 0x0600;
                        } else {
                            uint8_t value28 = RAM8(ACTOR_STATUS_HIGH + value);
                            bool carry14;
                            if (!(value28 & 0x80)) {
                                carry14 = value >= 0x0600;
                            } else {
                                if ((uint8_t)(RAM8(0x001E) << 1) >= 6) {
                                    uint8_t value30 = RAM8(0x001E);
                                    RAM8(0x001E) <<= 1;
                                    RAM8(0x001E) = (value30 >> 7 << 7) | 2;
                                }
                                uint8_t value31 = RAM8(0x001F);
                                bool carry13;
                                if ((uint8_t)(value31 << 1) < 6) {
                                    carry13 = (uint8_t)(value31 << 1) >= 6;
                                } else {
                                    uint8_t value32 = RAM8(0x001F);
                                    RAM8(0x001F) <<= 1;
                                    RAM8(0x001F) = (value32 >> 7 << 7) | 2;
                                    carry13 = 0;
                                }
                                carry14 = carry13;
                            }
                            uint8_t value33 = RAM8(ACTOR_STATUS + value);
                            uint8_t value34 = RAM8(ACTOR_STATUS_HIGH + value);
                            bool carry16;
                            if (((value33 | value34) & 4) == 0) {
                                carry16 = carry14;
                            } else {
                                if ((uint8_t)(RAM8(0x001E) << 1) >= 4) {
                                    uint8_t value36 = RAM8(0x001E);
                                    RAM8(0x001E) <<= 1;
                                    RAM8(0x001E) = (value36 >> 7 << 7) | 1;
                                }
                                uint8_t value37 = RAM8(0x001F);
                                bool carry15;
                                if ((uint8_t)(value37 << 1) < 4) {
                                    carry15 = (uint8_t)(value37 << 1) >= 4;
                                } else {
                                    uint8_t value38 = RAM8(0x001F);
                                    RAM8(0x001F) <<= 1;
                                    RAM8(0x001F) = (value38 >> 7 << 7) | 1;
                                    carry15 = 0;
                                }
                                carry16 = carry15;
                            }
                            carry17 = carry16;
                        }
                        uint8_t value39 = RAM8(0xE006 + value);
                        if (value39 == 0) {
                            uint8_t value40 = RAM8(0xE007 + value);
                            if (value40 != 0) {
                                uint8_t a23;
                                if (value40 & 0x80) {
                                    a23 = 0;
                                } else {
                                    a23 = 1;
                                }
                                RAM8(0xE010 + value) = a23;
                            }
                        } else {
                            uint8_t a24;
                            if (value39 & 0x80) {
                                a24 = 0x82;
                            } else {
                                a24 = 2;
                            }
                            RAM8(0xE010 + value) = a24;
                        }
                        uint8_t value41 = RAM8(ACTOR_STATUS_HIGH + value);
                        uint8_t a27;
                        bool carry18;
                        bool zero3;
                        bool negative3;
                        if (!(value41 & 0x80)) {
                            uint8_t a26;
                            bool zero2;
                            bool negative2;
                            if ((value41 & 4) == 0) {
                                uint8_t value42 = RAM8(0x001E);
                                uint8_t value43 = RAM8(0x001F);
                                uint8_t a25;
                                bool zero1;
                                bool negative1;
                                if ((value42 | value43) == 0) {
                                    a25 = value42 | value43;
                                    zero1 = (value42 | value43) == 0;
                                    negative1 = (value42 | value43) & 0x80;
                                } else {
                                    a25 = 4;
                                    zero1 = 0;
                                    negative1 = 0;
                                }
                                a26 = a25;
                                zero2 = zero1;
                                negative2 = negative1;
                            } else {
                                a26 = 4;
                                zero2 = 0;
                                negative2 = 0;
                            }
                            a27 = a26;
                            carry18 = carry17;
                            zero3 = zero2;
                            negative3 = negative2;
                        } else {
                            uint8_t value44 = RAM8(0x001E);
                            uint8_t value45 = RAM8(0x001F);
                            a27 = (value44 | value45) >= 1;
                            carry18 = 0;
                            zero3 = (value44 | value45) >= 1 == 0;
                            negative3 = (value44 | value45) >= 1 & 0x80;
                        }
                        a28 = a27;
                        carry19 = carry18;
                        zero4 = zero3;
                        negative4 = negative3;
                    }
                    a31 = a28;
                    carry20 = carry19;
                    zero7 = zero4;
                    negative5 = negative4;
                    overflow5 = overflow;
                } else {
                    uint8_t value46 = RAM8(0x00ED);
                    uint8_t a30;
                    bool zero6;
                    if (!(value46 & 0x80)) {
                        a30 = 0;
                        zero6 = 1;
                    } else {
                        uint8_t value47 = RAM8(ACTOR_WEAPON_GAUGE + value);
                        uint8_t a29;
                        bool zero5;
                        if (value47 != 0) {
                            a29 = 0;
                            zero5 = 1;
                        } else {
                            a29 = 3;
                            zero5 = 0;
                        }
                        a30 = a29;
                        zero6 = zero5;
                    }
                    a31 = a30;
                    carry20 = value >= 0x0600;
                    zero7 = zero6;
                    negative5 = 0;
                    overflow5 = value46 & 0x40;
                }
                a32 = a31;
                a_hi13 = value6 >> 8;
                carry21 = carry20;
                zero8 = zero7;
                negative6 = negative5;
                overflow6 = overflow5;
            }
            a33 = a32;
            a_hi14 = a_hi13;
            carry22 = carry21;
            zero9 = zero8;
            negative7 = negative6;
            overflow7 = overflow6;
        }
        a39 = a33;
        a_hi15 = a_hi14;
        carry29 = carry22;
        zero13 = zero9;
        negative11 = negative7;
        overflow8 = overflow7;
    } else {
        uint8_t value48 = RAM8(0x00FF);
        bool carry27;
        if (value48 != 0) {
            carry27 = value >= 0x0600;
        } else {
            uint8_t value49 = RAM8(ACTOR_STATUS_HIGH + value);
            bool carry24;
            if (!(value49 & 0x80)) {
                carry24 = value >= 0x0600;
            } else {
                if ((uint8_t)(RAM8(0x001E) << 1) >= 6) {
                    uint8_t value51 = RAM8(0x001E);
                    RAM8(0x001E) <<= 1;
                    RAM8(0x001E) = (value51 >> 7 << 7) | 2;
                }
                uint8_t value52 = RAM8(0x001F);
                bool carry23;
                if ((uint8_t)(value52 << 1) < 6) {
                    carry23 = (uint8_t)(value52 << 1) >= 6;
                } else {
                    uint8_t value53 = RAM8(0x001F);
                    RAM8(0x001F) <<= 1;
                    RAM8(0x001F) = (value53 >> 7 << 7) | 2;
                    carry23 = 0;
                }
                carry24 = carry23;
            }
            uint8_t value54 = RAM8(ACTOR_STATUS + value);
            uint8_t value55 = RAM8(ACTOR_STATUS_HIGH + value);
            bool carry26;
            if (((value54 | value55) & 4) == 0) {
                carry26 = carry24;
            } else {
                if ((uint8_t)(RAM8(0x001E) << 1) >= 4) {
                    uint8_t value57 = RAM8(0x001E);
                    RAM8(0x001E) <<= 1;
                    RAM8(0x001E) = (value57 >> 7 << 7) | 1;
                }
                uint8_t value58 = RAM8(0x001F);
                bool carry25;
                if ((uint8_t)(value58 << 1) < 4) {
                    carry25 = (uint8_t)(value58 << 1) >= 4;
                } else {
                    uint8_t value59 = RAM8(0x001F);
                    RAM8(0x001F) <<= 1;
                    RAM8(0x001F) = (value59 >> 7 << 7) | 1;
                    carry25 = 0;
                }
                carry26 = carry25;
            }
            carry27 = carry26;
        }
        uint8_t value60 = RAM8(0xE006 + value);
        if (value60 == 0) {
            uint8_t value61 = RAM8(0xE007 + value);
            if (value61 != 0) {
                uint8_t a34;
                if (value61 & 0x80) {
                    a34 = 0;
                } else {
                    a34 = 1;
                }
                RAM8(0xE010 + value) = a34;
            }
        } else {
            uint8_t a35;
            if (value60 & 0x80) {
                a35 = 0x82;
            } else {
                a35 = 2;
            }
            RAM8(0xE010 + value) = a35;
        }
        uint8_t value62 = RAM8(ACTOR_STATUS_HIGH + value);
        uint8_t a38;
        bool carry28;
        bool zero12;
        bool negative10;
        if (!(value62 & 0x80)) {
            uint8_t a37;
            bool zero11;
            bool negative9;
            if ((value62 & 4) == 0) {
                uint8_t value63 = RAM8(0x001E);
                uint8_t value64 = RAM8(0x001F);
                uint8_t a36;
                bool zero10;
                bool negative8;
                if ((value63 | value64) == 0) {
                    a36 = value63 | value64;
                    zero10 = (value63 | value64) == 0;
                    negative8 = (value63 | value64) & 0x80;
                } else {
                    a36 = 4;
                    zero10 = 0;
                    negative8 = 0;
                }
                a37 = a36;
                zero11 = zero10;
                negative9 = negative8;
            } else {
                a37 = 4;
                zero11 = 0;
                negative9 = 0;
            }
            a38 = a37;
            carry28 = carry27;
            zero12 = zero11;
            negative10 = negative9;
        } else {
            uint8_t value65 = RAM8(0x001E);
            uint8_t value66 = RAM8(0x001F);
            a38 = (value65 | value66) >= 1;
            carry28 = 0;
            zero12 = (value65 | value66) >= 1 == 0;
            negative10 = (value65 | value66) >= 1 & 0x80;
        }
        a39 = a38;
        a_hi15 = value6 >> 8;
        carry29 = carry28;
        zero13 = zero12;
        negative11 = negative10;
        overflow8 = overflow;
    }
    RAM8(0xE011 + value) = a39;
    r->a = (a_hi15 << 8) | a39;
    r->x = value;
    r->c = carry29;
    r->z = zero13;
    r->n = negative11;
    r->v = overflow8;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}

/* C0D482 publish_hero_facing_pose_and_status_limited_motion_v2   [class A, 326 bytes, 153 instructions]
 * Source: src/rom/apply_actor_ground_contact_effect_to_live_motion.s
 * Subroutine of apply_actor_ground_contact_effect_to_live_motion, translated in place.
 * Entry: M=any X=any DB=any D=any.  Callers read: ABXYCZNV.
 */
static void publish_hero_facing_pose_and_status_limited_motion_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t dp = r->dp;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x10));
    if (value >= 0x0600) {
        BUS8_SET(c, (db << 0x10) + 0xE029 + value, 0);
        SET_A8(r, 0);
        r->x = value;
        r->c = value >= 0x0600;
        r->z = 1;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0xE01C + value);
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0xE060 + value);
    if ((value2 | value3) != 0) {
        BUS8_SET(c, (db << 0x10) + 0xE029 + value, 0);
        SET_A8(r, 0);
        r->x = value;
        r->c = value >= 0x0600;
        r->z = 1;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0xE02F + value);
    if (value4 != 0) {
        BUS8_SET(c, (db << 0x10) + 0xE011 + value, value4);
        SET_A8(r, value4);
        r->x = value;
        r->c = value >= 0x0600;
        r->z = value4 == 0;
        r->n = value4 & 0x80;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0xE067 + value);
    if (value5 != 0) {
        BUS8_SET(c, (db << 0x10) + 0xE029 + value, 0);
        SET_A8(r, 0);
        r->x = value;
        r->c = value >= 0x0600;
        r->z = 1;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value6 = BUS16_RDP(c, (db << 0x10) + 0xE190 + value);
    if ((value6 & 0x4160) != 0) {
        BUS8_SET(c, (db << 0x10) + 0xE029 + value, 0);
        r->a = (value6 >> 8 << 8) | 0;
        r->x = value;
        r->c = value >= 0x0600;
        r->z = 1;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t a39;
    uint8_t a_hi15;
    bool carry29;
    bool zero13;
    bool negative11;
    bool overflow8;
    if ((value6 & 0x8404) == 0) {
        uint8_t value7 = BUS8_RDP(c, (db << 0x10) + 0xE01D + value);
        if ((value7 & 0x30) == 0) {
            uint8_t value8 = BUS8_RDP(c, (db << 0x10) + 0xE006 + value);
            if (value8 == 0) {
                uint8_t value9 = BUS8_RDP(c, (db << 0x10) + 0xE007 + value);
                if (value9 != 0) {
                    uint8_t a1;
                    if (value9 & 0x80) {
                        a1 = 0;
                    } else {
                        a1 = 1;
                    }
                    BUS8_SET(c, (db << 0x10) + 0xE010 + value, a1);
                }
            } else {
                uint8_t a2;
                if (value8 & 0x80) {
                    a2 = 0x82;
                } else {
                    a2 = 2;
                }
                BUS8_SET(c, (db << 0x10) + 0xE010 + value, a2);
            }
        } else {
            BUS8_SET(c, (db << 0x10) + 0xE01D + value, value7 & 0x80);
        }
        uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
        uint8_t a33;
        uint8_t a_hi14;
        bool carry22;
        bool zero9;
        bool negative7;
        bool overflow7;
        if (value10 != 0) {
            uint8_t value11 = BUS8_RDP(c, (db << 0x10) + 0xE029 + value);
            uint8_t a12;
            uint8_t a_hi6;
            bool carry6;
            bool overflow2;
            if (!(value11 & 0x80)) {
                uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp + 0xED));
                uint8_t a6;
                uint8_t a_hi2;
                bool carry2;
                if (!(value12 & 0x80)) {
                    uint8_t a3;
                    if ((value10 & 0x7F) < 3) {
                        a3 = 1;
                    } else {
                        a3 = 2;
                    }
                    a6 = a3;
                    a_hi2 = value11;
                    carry2 = (value10 & 0x7F) >= 3;
                } else {
                    uint8_t value13 = BUS8_RDP(c, (db << 0x10) + 0xE01A + value);
                    uint8_t value14 = BUS8_RDP(c, (db << 0x10) + 0xE01B + value);
                    uint8_t a5;
                    uint8_t a_hi1;
                    bool carry1;
                    if ((value13 | value14) == 0) {
                        uint8_t a4;
                        if ((value10 & 0x7F) < 3) {
                            a4 = 1;
                        } else {
                            a4 = 2;
                        }
                        a5 = a4;
                        a_hi1 = value13 | value14;
                        carry1 = (value10 & 0x7F) >= 3;
                    } else {
                        a5 = 4;
                        a_hi1 = value10;
                        carry1 = value >= 0x0600;
                    }
                    a6 = a5;
                    a_hi2 = a_hi1;
                    carry2 = carry1;
                }
                a12 = a6;
                a_hi6 = a_hi2;
                carry6 = carry2;
                overflow2 = value12 & 0x40;
            } else {
                BUS8_SET(c, (db << 0x10) + 0xE029 + value, 0);
                uint8_t a11;
                uint8_t a_hi5;
                bool carry5;
                bool overflow1;
                if (1) {
                    a11 = 8;
                    a_hi5 = value10;
                    carry5 = value >= 0x0600;
                    overflow1 = overflow;
                } else {
                    uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp + 0xED));
                    uint8_t a10;
                    uint8_t a_hi4;
                    bool carry4;
                    if (!(value15 & 0x80)) {
                        uint8_t a7;
                        if ((value10 & 0x7F) < 3) {
                            a7 = 1;
                        } else {
                            a7 = 2;
                        }
                        a10 = a7;
                        a_hi4 = 8;
                        carry4 = (value10 & 0x7F) >= 3;
                    } else {
                        uint8_t value16 = BUS8_RDP(c, (db << 0x10) + 0xE01A + value);
                        uint8_t value17 = BUS8_RDP(c, (db << 0x10) + 0xE01B + value);
                        uint8_t a9;
                        uint8_t a_hi3;
                        bool carry3;
                        if ((value16 | value17) == 0) {
                            uint8_t a8;
                            if ((value10 & 0x7F) < 3) {
                                a8 = 1;
                            } else {
                                a8 = 2;
                            }
                            a9 = a8;
                            a_hi3 = value16 | value17;
                            carry3 = (value10 & 0x7F) >= 3;
                        } else {
                            a9 = 4;
                            a_hi3 = value10;
                            carry3 = value >= 0x0600;
                        }
                        a10 = a9;
                        a_hi4 = a_hi3;
                        carry4 = carry3;
                    }
                    a11 = a10;
                    a_hi5 = a_hi4;
                    carry5 = carry4;
                    overflow1 = value15 & 0x40;
                }
                a12 = a11;
                a_hi6 = a_hi5;
                carry6 = carry5;
                overflow2 = overflow1;
            }
            a33 = a12;
            a_hi14 = a_hi6;
            carry22 = carry6;
            zero9 = 0;
            negative7 = 0;
            overflow7 = overflow2;
        } else {
            uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
            uint8_t a32;
            uint8_t a_hi13;
            bool carry21;
            bool zero8;
            bool negative6;
            bool overflow6;
            if (value18 != 0) {
                uint8_t value19 = BUS8_RDP(c, (db << 0x10) + 0xE029 + value);
                uint8_t a22;
                uint8_t a_hi12;
                bool carry12;
                bool overflow4;
                if (!(value19 & 0x80)) {
                    uint8_t value20 = BUS8_RDP(c, (uint16_t)(dp + 0xED));
                    uint8_t a16;
                    uint8_t a_hi8;
                    bool carry8;
                    if (!(value20 & 0x80)) {
                        uint8_t a13;
                        if ((value18 & 0x7F) < 3) {
                            a13 = 1;
                        } else {
                            a13 = 2;
                        }
                        a16 = a13;
                        a_hi8 = value19;
                        carry8 = (value18 & 0x7F) >= 3;
                    } else {
                        uint8_t value21 = BUS8_RDP(c, (db << 0x10) + 0xE01A + value);
                        uint8_t value22 = BUS8_RDP(c, (db << 0x10) + 0xE01B + value);
                        uint8_t a15;
                        uint8_t a_hi7;
                        bool carry7;
                        if ((value21 | value22) == 0) {
                            uint8_t a14;
                            if ((value18 & 0x7F) < 3) {
                                a14 = 1;
                            } else {
                                a14 = 2;
                            }
                            a15 = a14;
                            a_hi7 = value21 | value22;
                            carry7 = (value18 & 0x7F) >= 3;
                        } else {
                            a15 = 4;
                            a_hi7 = value18;
                            carry7 = value >= 0x0600;
                        }
                        a16 = a15;
                        a_hi8 = a_hi7;
                        carry8 = carry7;
                    }
                    a22 = a16;
                    a_hi12 = a_hi8;
                    carry12 = carry8;
                    overflow4 = value20 & 0x40;
                } else {
                    BUS8_SET(c, (db << 0x10) + 0xE029 + value, 0);
                    uint8_t a21;
                    uint8_t a_hi11;
                    bool carry11;
                    bool overflow3;
                    if (1) {
                        a21 = 8;
                        a_hi11 = value18;
                        carry11 = value >= 0x0600;
                        overflow3 = overflow;
                    } else {
                        uint8_t value23 = BUS8_RDP(c, (uint16_t)(dp + 0xED));
                        uint8_t a20;
                        uint8_t a_hi10;
                        bool carry10;
                        if (!(value23 & 0x80)) {
                            uint8_t a17;
                            if ((value18 & 0x7F) < 3) {
                                a17 = 1;
                            } else {
                                a17 = 2;
                            }
                            a20 = a17;
                            a_hi10 = 8;
                            carry10 = (value18 & 0x7F) >= 3;
                        } else {
                            uint8_t value24 = BUS8_RDP(c, (db << 0x10) + 0xE01A + value);
                            uint8_t value25 = BUS8_RDP(c, (db << 0x10) + 0xE01B + value);
                            uint8_t a19;
                            uint8_t a_hi9;
                            bool carry9;
                            if ((value24 | value25) == 0) {
                                uint8_t a18;
                                if ((value18 & 0x7F) < 3) {
                                    a18 = 1;
                                } else {
                                    a18 = 2;
                                }
                                a19 = a18;
                                a_hi9 = value24 | value25;
                                carry9 = (value18 & 0x7F) >= 3;
                            } else {
                                a19 = 4;
                                a_hi9 = value18;
                                carry9 = value >= 0x0600;
                            }
                            a20 = a19;
                            a_hi10 = a_hi9;
                            carry10 = carry9;
                        }
                        a21 = a20;
                        a_hi11 = a_hi10;
                        carry11 = carry10;
                        overflow3 = value23 & 0x40;
                    }
                    a22 = a21;
                    a_hi12 = a_hi11;
                    carry12 = carry11;
                    overflow4 = overflow3;
                }
                a32 = a22;
                a_hi13 = a_hi12;
                carry21 = carry12;
                zero8 = 0;
                negative6 = 0;
                overflow6 = overflow4;
            } else {
                uint8_t value26 = BUS8_RDP(c, (db << 0x10) + 0xE029 + value);
                uint8_t a31;
                bool carry20;
                bool zero7;
                bool negative5;
                bool overflow5;
                if (value26 & 0x80) {
                    BUS8_SET(c, (db << 0x10) + 0xE029 + value, 0);
                    uint8_t a28;
                    bool carry19;
                    bool zero4;
                    bool negative4;
                    if (1) {
                        a28 = 8;
                        carry19 = value >= 0x0600;
                        zero4 = 0;
                        negative4 = 0;
                    } else {
                        uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp + 0xFF));
                        bool carry17;
                        if (value27 != 0) {
                            carry17 = value >= 0x0600;
                        } else {
                            uint8_t value28 = BUS8_RDP(c, (db << 0x10) + 0xE191 + value);
                            bool carry14;
                            if (!(value28 & 0x80)) {
                                carry14 = value >= 0x0600;
                            } else {
                                uint8_t value29 = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
                                if ((uint8_t)(value29 << 1) >= 6) {
                                    uint8_t value30 = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
                                    BUS8_SET(c, (uint16_t)(dp + 0x1E), (uint8_t)(value30 << 1));
                                    BUS8_SET(c, (uint16_t)(dp + 0x1E), (value30 >> 7 << 7) | 2);
                                }
                                uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                                bool carry13;
                                if ((uint8_t)(value31 << 1) < 6) {
                                    carry13 = (uint8_t)(value31 << 1) >= 6;
                                } else {
                                    uint8_t value32 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                                    BUS8_SET(c, (uint16_t)(dp + 0x1F), (uint8_t)(value32 << 1));
                                    BUS8_SET(c, (uint16_t)(dp + 0x1F), (value32 >> 7 << 7) | 2);
                                    carry13 = 0;
                                }
                                carry14 = carry13;
                            }
                            uint8_t value33 = BUS8_RDP(c, (db << 0x10) + 0xE190 + value);
                            uint8_t value34 = BUS8_RDP(c, (db << 0x10) + 0xE191 + value);
                            bool carry16;
                            if (((value33 | value34) & 4) == 0) {
                                carry16 = carry14;
                            } else {
                                uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
                                if ((uint8_t)(value35 << 1) >= 4) {
                                    uint8_t value36 = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
                                    BUS8_SET(c, (uint16_t)(dp + 0x1E), (uint8_t)(value36 << 1));
                                    BUS8_SET(c, (uint16_t)(dp + 0x1E), (value36 >> 7 << 7) | 1);
                                }
                                uint8_t value37 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                                bool carry15;
                                if ((uint8_t)(value37 << 1) < 4) {
                                    carry15 = (uint8_t)(value37 << 1) >= 4;
                                } else {
                                    uint8_t value38 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                                    BUS8_SET(c, (uint16_t)(dp + 0x1F), (uint8_t)(value38 << 1));
                                    BUS8_SET(c, (uint16_t)(dp + 0x1F), (value38 >> 7 << 7) | 1);
                                    carry15 = 0;
                                }
                                carry16 = carry15;
                            }
                            carry17 = carry16;
                        }
                        uint8_t value39 = BUS8_RDP(c, (db << 0x10) + 0xE006 + value);
                        if (value39 == 0) {
                            uint8_t value40 = BUS8_RDP(c, (db << 0x10) + 0xE007 + value);
                            if (value40 != 0) {
                                uint8_t a23;
                                if (value40 & 0x80) {
                                    a23 = 0;
                                } else {
                                    a23 = 1;
                                }
                                BUS8_SET(c, (db << 0x10) + 0xE010 + value, a23);
                            }
                        } else {
                            uint8_t a24;
                            if (value39 & 0x80) {
                                a24 = 0x82;
                            } else {
                                a24 = 2;
                            }
                            BUS8_SET(c, (db << 0x10) + 0xE010 + value, a24);
                        }
                        uint8_t value41 = BUS8_RDP(c, (db << 0x10) + 0xE191 + value);
                        uint8_t a27;
                        bool carry18;
                        bool zero3;
                        bool negative3;
                        if (!(value41 & 0x80)) {
                            uint8_t a26;
                            bool zero2;
                            bool negative2;
                            if ((value41 & 4) == 0) {
                                uint8_t value42 = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
                                uint8_t value43 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                                uint8_t a25;
                                bool zero1;
                                bool negative1;
                                if ((value42 | value43) == 0) {
                                    a25 = value42 | value43;
                                    zero1 = (value42 | value43) == 0;
                                    negative1 = (value42 | value43) & 0x80;
                                } else {
                                    a25 = 4;
                                    zero1 = 0;
                                    negative1 = 0;
                                }
                                a26 = a25;
                                zero2 = zero1;
                                negative2 = negative1;
                            } else {
                                a26 = 4;
                                zero2 = 0;
                                negative2 = 0;
                            }
                            a27 = a26;
                            carry18 = carry17;
                            zero3 = zero2;
                            negative3 = negative2;
                        } else {
                            uint8_t value44 = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
                            uint8_t value45 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                            a27 = (value44 | value45) >= 1;
                            carry18 = 0;
                            zero3 = (value44 | value45) >= 1 == 0;
                            negative3 = (value44 | value45) >= 1 & 0x80;
                        }
                        a28 = a27;
                        carry19 = carry18;
                        zero4 = zero3;
                        negative4 = negative3;
                    }
                    a31 = a28;
                    carry20 = carry19;
                    zero7 = zero4;
                    negative5 = negative4;
                    overflow5 = overflow;
                } else {
                    uint8_t value46 = BUS8_RDP(c, (uint16_t)(dp + 0xED));
                    uint8_t a30;
                    bool zero6;
                    if (!(value46 & 0x80)) {
                        a30 = 0;
                        zero6 = 1;
                    } else {
                        uint8_t value47 = BUS8_RDP(c, (db << 0x10) + 0xE1ED + value);
                        uint8_t a29;
                        bool zero5;
                        if (value47 != 0) {
                            a29 = 0;
                            zero5 = 1;
                        } else {
                            a29 = 3;
                            zero5 = 0;
                        }
                        a30 = a29;
                        zero6 = zero5;
                    }
                    a31 = a30;
                    carry20 = value >= 0x0600;
                    zero7 = zero6;
                    negative5 = 0;
                    overflow5 = value46 & 0x40;
                }
                a32 = a31;
                a_hi13 = value6 >> 8;
                carry21 = carry20;
                zero8 = zero7;
                negative6 = negative5;
                overflow6 = overflow5;
            }
            a33 = a32;
            a_hi14 = a_hi13;
            carry22 = carry21;
            zero9 = zero8;
            negative7 = negative6;
            overflow7 = overflow6;
        }
        a39 = a33;
        a_hi15 = a_hi14;
        carry29 = carry22;
        zero13 = zero9;
        negative11 = negative7;
        overflow8 = overflow7;
    } else {
        uint8_t value48 = BUS8_RDP(c, (uint16_t)(dp + 0xFF));
        bool carry27;
        if (value48 != 0) {
            carry27 = value >= 0x0600;
        } else {
            uint8_t value49 = BUS8_RDP(c, (db << 0x10) + 0xE191 + value);
            bool carry24;
            if (!(value49 & 0x80)) {
                carry24 = value >= 0x0600;
            } else {
                uint8_t value50 = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
                if ((uint8_t)(value50 << 1) >= 6) {
                    uint8_t value51 = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
                    BUS8_SET(c, (uint16_t)(dp + 0x1E), (uint8_t)(value51 << 1));
                    BUS8_SET(c, (uint16_t)(dp + 0x1E), (value51 >> 7 << 7) | 2);
                }
                uint8_t value52 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                bool carry23;
                if ((uint8_t)(value52 << 1) < 6) {
                    carry23 = (uint8_t)(value52 << 1) >= 6;
                } else {
                    uint8_t value53 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                    BUS8_SET(c, (uint16_t)(dp + 0x1F), (uint8_t)(value53 << 1));
                    BUS8_SET(c, (uint16_t)(dp + 0x1F), (value53 >> 7 << 7) | 2);
                    carry23 = 0;
                }
                carry24 = carry23;
            }
            uint8_t value54 = BUS8_RDP(c, (db << 0x10) + 0xE190 + value);
            uint8_t value55 = BUS8_RDP(c, (db << 0x10) + 0xE191 + value);
            bool carry26;
            if (((value54 | value55) & 4) == 0) {
                carry26 = carry24;
            } else {
                uint8_t value56 = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
                if ((uint8_t)(value56 << 1) >= 4) {
                    uint8_t value57 = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
                    BUS8_SET(c, (uint16_t)(dp + 0x1E), (uint8_t)(value57 << 1));
                    BUS8_SET(c, (uint16_t)(dp + 0x1E), (value57 >> 7 << 7) | 1);
                }
                uint8_t value58 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                bool carry25;
                if ((uint8_t)(value58 << 1) < 4) {
                    carry25 = (uint8_t)(value58 << 1) >= 4;
                } else {
                    uint8_t value59 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                    BUS8_SET(c, (uint16_t)(dp + 0x1F), (uint8_t)(value59 << 1));
                    BUS8_SET(c, (uint16_t)(dp + 0x1F), (value59 >> 7 << 7) | 1);
                    carry25 = 0;
                }
                carry26 = carry25;
            }
            carry27 = carry26;
        }
        uint8_t value60 = BUS8_RDP(c, (db << 0x10) + 0xE006 + value);
        if (value60 == 0) {
            uint8_t value61 = BUS8_RDP(c, (db << 0x10) + 0xE007 + value);
            if (value61 != 0) {
                uint8_t a34;
                if (value61 & 0x80) {
                    a34 = 0;
                } else {
                    a34 = 1;
                }
                BUS8_SET(c, (db << 0x10) + 0xE010 + value, a34);
            }
        } else {
            uint8_t a35;
            if (value60 & 0x80) {
                a35 = 0x82;
            } else {
                a35 = 2;
            }
            BUS8_SET(c, (db << 0x10) + 0xE010 + value, a35);
        }
        uint8_t value62 = BUS8_RDP(c, (db << 0x10) + 0xE191 + value);
        uint8_t a38;
        bool carry28;
        bool zero12;
        bool negative10;
        if (!(value62 & 0x80)) {
            uint8_t a37;
            bool zero11;
            bool negative9;
            if ((value62 & 4) == 0) {
                uint8_t value63 = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
                uint8_t value64 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
                uint8_t a36;
                bool zero10;
                bool negative8;
                if ((value63 | value64) == 0) {
                    a36 = value63 | value64;
                    zero10 = (value63 | value64) == 0;
                    negative8 = (value63 | value64) & 0x80;
                } else {
                    a36 = 4;
                    zero10 = 0;
                    negative8 = 0;
                }
                a37 = a36;
                zero11 = zero10;
                negative9 = negative8;
            } else {
                a37 = 4;
                zero11 = 0;
                negative9 = 0;
            }
            a38 = a37;
            carry28 = carry27;
            zero12 = zero11;
            negative10 = negative9;
        } else {
            uint8_t value65 = BUS8_RDP(c, (uint16_t)(dp + 0x1E));
            uint8_t value66 = BUS8_RDP(c, (uint16_t)(dp + 0x1F));
            a38 = (value65 | value66) >= 1;
            carry28 = 0;
            zero12 = (value65 | value66) >= 1 == 0;
            negative10 = (value65 | value66) >= 1 & 0x80;
        }
        a39 = a38;
        a_hi15 = value6 >> 8;
        carry29 = carry28;
        zero13 = zero12;
        negative11 = negative10;
        overflow8 = overflow;
    }
    BUS8_SET(c, (db << 0x10) + 0xE011 + value, a39);
    r->a = (a_hi15 << 8) | a39;
    r->x = value;
    r->c = carry29;
    r->z = zero13;
    r->n = negative11;
    r->v = overflow8;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
