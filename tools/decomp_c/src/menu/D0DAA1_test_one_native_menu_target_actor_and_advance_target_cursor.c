#include "som_c.h"

/* D0DAA1 test_one_native_menu_target_actor_and_advance_target_cursor   [class C, 183 bytes, 78 instructions]
 * Source: src/rom/test_one_native_menu_target_actor_and_advance_target_cursor.s
 * Documented in docs/event-menu-target-eligibility.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: XYCV.
 */
static void test_one_native_menu_target_actor_and_advance_target_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    BUS16_SET(c, 0x000000 + y, 0);
    uint16_t value = RAM16(0x0020 + x);
    bool m_flag49;
    uint8_t a_hi51;
    if (value < 8) {
        m_flag49 = 0;
        a_hi51 = value >> 8;
    } else {
        bool m_flag48;
        uint8_t a_hi50;
        if (value >= 0xF8) {
            m_flag48 = 0;
            a_hi50 = value >> 8;
        } else {
            uint16_t value2 = RAM16(0x0022 + x);
            bool m_flag47;
            uint8_t a_hi49;
            if (value2 >= 0xD8) {
                m_flag47 = 0;
                a_hi49 = value2 >> 8;
            } else {
                uint8_t value3 = RAM8(0x0000 + x);
                bool m_flag46;
                uint8_t a_hi48;
                if ((uint8_t)(value3 - 1) != 0) {
                    m_flag46 = 1;
                    a_hi48 = value2 >> 8;
                } else {
                    bool m_flag45;
                    uint8_t a_hi47;
                    if (x < 0xE600) {
                        uint8_t value4 = RAM8(0x1842);
                        bool m_flag35;
                        uint8_t a_hi37;
                        if ((value4 & 0x40) == 0) {
                            uint8_t ring_category = RAM8(RING_CATEGORY);
                            bool m_flag16;
                            uint8_t a_hi17;
                            if (ring_category != 0) {
                                bool m_flag9;
                                uint8_t a_hi9;
                                if ((uint8_t)(ring_category - 1) != 0) {
                                    uint8_t value5 = RAM8(0x0180 + x);
                                    bool m_flag3;
                                    uint8_t a_hi3;
                                    if (value5 == 0x54) {
                                        RAM8(0x1834)++;
                                        BUS16_SET(c, 0x000000 + y, x);
                                        m_flag3 = 0;
                                        a_hi3 = x >> 8;
                                    } else {
                                        bool m_flag2;
                                        uint8_t a_hi2;
                                        if (value5 == 0x55) {
                                            RAM8(0x1834)++;
                                            BUS16_SET(c, 0x000000 + y, x);
                                            m_flag2 = 0;
                                            a_hi2 = x >> 8;
                                        } else {
                                            uint8_t value6 = RAM8(0x0191 + x);
                                            bool m_flag;
                                            uint8_t a_hi1;
                                            if (value6 & 0x80) {
                                                m_flag = 1;
                                                a_hi1 = value2 >> 8;
                                            } else {
                                                RAM8(0x1834)++;
                                                BUS16_SET(c, 0x000000 + y, x);
                                                m_flag = 0;
                                                a_hi1 = x >> 8;
                                            }
                                            m_flag2 = m_flag;
                                            a_hi2 = a_hi1;
                                        }
                                        m_flag3 = m_flag2;
                                        a_hi3 = a_hi2;
                                    }
                                    m_flag9 = m_flag3;
                                    a_hi9 = a_hi3;
                                } else {
                                    uint8_t value7 = RAM8(0x1839);
                                    bool m_flag8;
                                    uint8_t a_hi8;
                                    if (value7 != 0x21) {
                                        uint8_t value8 = RAM8(0x0180 + x);
                                        bool m_flag6;
                                        uint8_t a_hi6;
                                        if (value8 == 0x54) {
                                            RAM8(0x1834)++;
                                            BUS16_SET(c, 0x000000 + y, x);
                                            m_flag6 = 0;
                                            a_hi6 = x >> 8;
                                        } else {
                                            bool m_flag5;
                                            uint8_t a_hi5;
                                            if (value8 == 0x55) {
                                                RAM8(0x1834)++;
                                                BUS16_SET(c, 0x000000 + y, x);
                                                m_flag5 = 0;
                                                a_hi5 = x >> 8;
                                            } else {
                                                uint8_t value9 = RAM8(0x0191 + x);
                                                bool m_flag4;
                                                uint8_t a_hi4;
                                                if (value9 & 0x80) {
                                                    m_flag4 = 1;
                                                    a_hi4 = value2 >> 8;
                                                } else {
                                                    RAM8(0x1834)++;
                                                    BUS16_SET(c, 0x000000 + y, x);
                                                    m_flag4 = 0;
                                                    a_hi4 = x >> 8;
                                                }
                                                m_flag5 = m_flag4;
                                                a_hi5 = a_hi4;
                                            }
                                            m_flag6 = m_flag5;
                                            a_hi6 = a_hi5;
                                        }
                                        m_flag8 = m_flag6;
                                        a_hi8 = a_hi6;
                                    } else {
                                        uint8_t value10 = RAM8(0x0191 + x);
                                        bool m_flag7;
                                        uint8_t a_hi7;
                                        if (!(value10 & 0x80)) {
                                            m_flag7 = 1;
                                            a_hi7 = value2 >> 8;
                                        } else {
                                            RAM8(0x1834)++;
                                            BUS16_SET(c, 0x000000 + y, x);
                                            m_flag7 = 0;
                                            a_hi7 = x >> 8;
                                        }
                                        m_flag8 = m_flag7;
                                        a_hi8 = a_hi7;
                                    }
                                    m_flag9 = m_flag8;
                                    a_hi9 = a_hi8;
                                }
                                m_flag16 = m_flag9;
                                a_hi17 = a_hi9;
                            } else {
                                uint8_t value11 = RAM8(0x19F1);
                                bool m_flag15;
                                uint8_t a_hi16;
                                if (value11 == 4) {
                                    uint16_t value12 = RAM16(0x0190 + x);
                                    uint8_t a_hi10;
                                    if ((value12 & 0x73FC) == 0) {
                                        a_hi10 = value12 >> 8;
                                    } else {
                                        RAM8(0x1834)++;
                                        BUS16_SET(c, 0x000000 + y, x);
                                        a_hi10 = x >> 8;
                                    }
                                    m_flag15 = 0;
                                    a_hi16 = a_hi10;
                                } else {
                                    bool m_flag14;
                                    uint8_t a_hi15;
                                    if (value11 != 5) {
                                        uint8_t value13 = RAM8(0x0180 + x);
                                        bool m_flag12;
                                        uint8_t a_hi13;
                                        if (value13 == 0x54) {
                                            RAM8(0x1834)++;
                                            BUS16_SET(c, 0x000000 + y, x);
                                            m_flag12 = 0;
                                            a_hi13 = x >> 8;
                                        } else {
                                            bool m_flag11;
                                            uint8_t a_hi12;
                                            if (value13 == 0x55) {
                                                RAM8(0x1834)++;
                                                BUS16_SET(c, 0x000000 + y, x);
                                                m_flag11 = 0;
                                                a_hi12 = x >> 8;
                                            } else {
                                                uint8_t value14 = RAM8(0x0191 + x);
                                                bool m_flag10;
                                                uint8_t a_hi11;
                                                if (value14 & 0x80) {
                                                    m_flag10 = 1;
                                                    a_hi11 = value2 >> 8;
                                                } else {
                                                    RAM8(0x1834)++;
                                                    BUS16_SET(c, 0x000000 + y, x);
                                                    m_flag10 = 0;
                                                    a_hi11 = x >> 8;
                                                }
                                                m_flag11 = m_flag10;
                                                a_hi12 = a_hi11;
                                            }
                                            m_flag12 = m_flag11;
                                            a_hi13 = a_hi12;
                                        }
                                        m_flag14 = m_flag12;
                                        a_hi15 = a_hi13;
                                    } else {
                                        uint8_t value15 = RAM8(0x0191 + x);
                                        bool m_flag13;
                                        uint8_t a_hi14;
                                        if (!(value15 & 0x80)) {
                                            m_flag13 = 1;
                                            a_hi14 = value2 >> 8;
                                        } else {
                                            RAM8(0x1834)++;
                                            BUS16_SET(c, 0x000000 + y, x);
                                            m_flag13 = 0;
                                            a_hi14 = x >> 8;
                                        }
                                        m_flag14 = m_flag13;
                                        a_hi15 = a_hi14;
                                    }
                                    m_flag15 = m_flag14;
                                    a_hi16 = a_hi15;
                                }
                                m_flag16 = m_flag15;
                                a_hi17 = a_hi16;
                            }
                            m_flag35 = m_flag16;
                            a_hi37 = a_hi17;
                        } else {
                            bool m_flag34;
                            uint8_t a_hi36;
                            if (x != 0xE000) {
                                m_flag34 = 1;
                                a_hi36 = value2 >> 8;
                            } else {
                                uint8_t value16 = RAM8(0xCC55);
                                bool m_flag33;
                                uint8_t a_hi35;
                                if ((value16 & 0xC0) != 0x40) {
                                    m_flag33 = 1;
                                    a_hi35 = value2 >> 8;
                                } else {
                                    uint8_t ring_category2 = RAM8(RING_CATEGORY);
                                    bool m_flag32;
                                    uint8_t a_hi34;
                                    if (ring_category2 != 0) {
                                        bool m_flag25;
                                        uint8_t a_hi26;
                                        if ((uint8_t)(ring_category2 - 1) != 0) {
                                            uint8_t value17 = RAM8(0x0180 + x);
                                            bool m_flag19;
                                            uint8_t a_hi20;
                                            if (value17 == 0x54) {
                                                RAM8(0x1834)++;
                                                BUS16_SET(c, 0x000000 + y, x);
                                                m_flag19 = 0;
                                                a_hi20 = x >> 8;
                                            } else {
                                                bool m_flag18;
                                                uint8_t a_hi19;
                                                if (value17 == 0x55) {
                                                    RAM8(0x1834)++;
                                                    BUS16_SET(c, 0x000000 + y, x);
                                                    m_flag18 = 0;
                                                    a_hi19 = x >> 8;
                                                } else {
                                                    uint8_t value18 = RAM8(0x0191 + x);
                                                    bool m_flag17;
                                                    uint8_t a_hi18;
                                                    if (value18 & 0x80) {
                                                        m_flag17 = 1;
                                                        a_hi18 = value2 >> 8;
                                                    } else {
                                                        RAM8(0x1834)++;
                                                        BUS16_SET(c, 0x000000 + y, x);
                                                        m_flag17 = 0;
                                                        a_hi18 = x >> 8;
                                                    }
                                                    m_flag18 = m_flag17;
                                                    a_hi19 = a_hi18;
                                                }
                                                m_flag19 = m_flag18;
                                                a_hi20 = a_hi19;
                                            }
                                            m_flag25 = m_flag19;
                                            a_hi26 = a_hi20;
                                        } else {
                                            uint8_t value19 = RAM8(0x1839);
                                            bool m_flag24;
                                            uint8_t a_hi25;
                                            if (value19 != 0x21) {
                                                uint8_t value20 = RAM8(0x0180 + x);
                                                bool m_flag22;
                                                uint8_t a_hi23;
                                                if (value20 == 0x54) {
                                                    RAM8(0x1834)++;
                                                    BUS16_SET(c, 0x000000 + y, x);
                                                    m_flag22 = 0;
                                                    a_hi23 = x >> 8;
                                                } else {
                                                    bool m_flag21;
                                                    uint8_t a_hi22;
                                                    if (value20 == 0x55) {
                                                        RAM8(0x1834)++;
                                                        BUS16_SET(c, 0x000000 + y, x);
                                                        m_flag21 = 0;
                                                        a_hi22 = x >> 8;
                                                    } else {
                                                        uint8_t value21 = RAM8(0x0191 + x);
                                                        bool m_flag20;
                                                        uint8_t a_hi21;
                                                        if (value21 & 0x80) {
                                                            m_flag20 = 1;
                                                            a_hi21 = value2 >> 8;
                                                        } else {
                                                            RAM8(0x1834)++;
                                                            BUS16_SET(c, 0x000000 + y, x);
                                                            m_flag20 = 0;
                                                            a_hi21 = x >> 8;
                                                        }
                                                        m_flag21 = m_flag20;
                                                        a_hi22 = a_hi21;
                                                    }
                                                    m_flag22 = m_flag21;
                                                    a_hi23 = a_hi22;
                                                }
                                                m_flag24 = m_flag22;
                                                a_hi25 = a_hi23;
                                            } else {
                                                uint8_t value22 = RAM8(0x0191 + x);
                                                bool m_flag23;
                                                uint8_t a_hi24;
                                                if (!(value22 & 0x80)) {
                                                    m_flag23 = 1;
                                                    a_hi24 = value2 >> 8;
                                                } else {
                                                    RAM8(0x1834)++;
                                                    BUS16_SET(c, 0x000000 + y, x);
                                                    m_flag23 = 0;
                                                    a_hi24 = x >> 8;
                                                }
                                                m_flag24 = m_flag23;
                                                a_hi25 = a_hi24;
                                            }
                                            m_flag25 = m_flag24;
                                            a_hi26 = a_hi25;
                                        }
                                        m_flag32 = m_flag25;
                                        a_hi34 = a_hi26;
                                    } else {
                                        uint8_t value23 = RAM8(0x19F1);
                                        bool m_flag31;
                                        uint8_t a_hi33;
                                        if (value23 == 4) {
                                            uint16_t value24 = RAM16(0x0190 + x);
                                            uint8_t a_hi27;
                                            if ((value24 & 0x73FC) == 0) {
                                                a_hi27 = value24 >> 8;
                                            } else {
                                                RAM8(0x1834)++;
                                                BUS16_SET(c, 0x000000 + y, x);
                                                a_hi27 = x >> 8;
                                            }
                                            m_flag31 = 0;
                                            a_hi33 = a_hi27;
                                        } else {
                                            bool m_flag30;
                                            uint8_t a_hi32;
                                            if (value23 != 5) {
                                                uint8_t value25 = RAM8(0x0180 + x);
                                                bool m_flag28;
                                                uint8_t a_hi30;
                                                if (value25 == 0x54) {
                                                    RAM8(0x1834)++;
                                                    BUS16_SET(c, 0x000000 + y, x);
                                                    m_flag28 = 0;
                                                    a_hi30 = x >> 8;
                                                } else {
                                                    bool m_flag27;
                                                    uint8_t a_hi29;
                                                    if (value25 == 0x55) {
                                                        RAM8(0x1834)++;
                                                        BUS16_SET(c, 0x000000 + y, x);
                                                        m_flag27 = 0;
                                                        a_hi29 = x >> 8;
                                                    } else {
                                                        uint8_t value26 = RAM8(0x0191 + x);
                                                        bool m_flag26;
                                                        uint8_t a_hi28;
                                                        if (value26 & 0x80) {
                                                            m_flag26 = 1;
                                                            a_hi28 = value2 >> 8;
                                                        } else {
                                                            RAM8(0x1834)++;
                                                            BUS16_SET(c, 0x000000 + y, x);
                                                            m_flag26 = 0;
                                                            a_hi28 = x >> 8;
                                                        }
                                                        m_flag27 = m_flag26;
                                                        a_hi29 = a_hi28;
                                                    }
                                                    m_flag28 = m_flag27;
                                                    a_hi30 = a_hi29;
                                                }
                                                m_flag30 = m_flag28;
                                                a_hi32 = a_hi30;
                                            } else {
                                                uint8_t value27 = RAM8(0x0191 + x);
                                                bool m_flag29;
                                                uint8_t a_hi31;
                                                if (!(value27 & 0x80)) {
                                                    m_flag29 = 1;
                                                    a_hi31 = value2 >> 8;
                                                } else {
                                                    RAM8(0x1834)++;
                                                    BUS16_SET(c, 0x000000 + y, x);
                                                    m_flag29 = 0;
                                                    a_hi31 = x >> 8;
                                                }
                                                m_flag30 = m_flag29;
                                                a_hi32 = a_hi31;
                                            }
                                            m_flag31 = m_flag30;
                                            a_hi33 = a_hi32;
                                        }
                                        m_flag32 = m_flag31;
                                        a_hi34 = a_hi33;
                                    }
                                    m_flag33 = m_flag32;
                                    a_hi35 = a_hi34;
                                }
                                m_flag34 = m_flag33;
                                a_hi36 = a_hi35;
                            }
                            m_flag35 = m_flag34;
                            a_hi37 = a_hi36;
                        }
                        m_flag45 = m_flag35;
                        a_hi47 = a_hi37;
                    } else {
                        uint8_t value28 = RAM8(0x1842);
                        bool m_flag44;
                        uint8_t a_hi46;
                        if (!(value28 & 0x80)) {
                            bool m_flag37;
                            uint8_t a_hi39;
                            if ((value28 & 0x20) == 0) {
                                m_flag37 = 1;
                                a_hi39 = value2 >> 8;
                            } else {
                                uint8_t value29 = RAM8(0x0180 + x);
                                bool m_flag36;
                                uint8_t a_hi38;
                                if (value29 == 0xEA) {
                                    RAM8(0x1834)++;
                                    BUS16_SET(c, 0x000000 + y, x);
                                    m_flag36 = 0;
                                    a_hi38 = x >> 8;
                                } else {
                                    m_flag36 = 1;
                                    a_hi38 = value2 >> 8;
                                }
                                m_flag37 = m_flag36;
                                a_hi39 = a_hi38;
                            }
                            m_flag44 = m_flag37;
                            a_hi46 = a_hi39;
                        } else {
                            uint8_t value30 = RAM8(0x0180 + x);
                            bool m_flag43;
                            uint8_t a_hi45;
                            if (!(value30 & 0x80)) {
                                bool m_flag40;
                                uint8_t a_hi42;
                                if (value30 == 0x54) {
                                    RAM8(0x1834)++;
                                    BUS16_SET(c, 0x000000 + y, x);
                                    m_flag40 = 0;
                                    a_hi42 = x >> 8;
                                } else {
                                    bool m_flag39;
                                    uint8_t a_hi41;
                                    if (value30 == 0x55) {
                                        RAM8(0x1834)++;
                                        BUS16_SET(c, 0x000000 + y, x);
                                        m_flag39 = 0;
                                        a_hi41 = x >> 8;
                                    } else {
                                        uint8_t value31 = RAM8(0x0191 + x);
                                        bool m_flag38;
                                        uint8_t a_hi40;
                                        if (value31 & 0x80) {
                                            m_flag38 = 1;
                                            a_hi40 = value2 >> 8;
                                        } else {
                                            RAM8(0x1834)++;
                                            BUS16_SET(c, 0x000000 + y, x);
                                            m_flag38 = 0;
                                            a_hi40 = x >> 8;
                                        }
                                        m_flag39 = m_flag38;
                                        a_hi41 = a_hi40;
                                    }
                                    m_flag40 = m_flag39;
                                    a_hi42 = a_hi41;
                                }
                                m_flag43 = m_flag40;
                                a_hi45 = a_hi42;
                            } else {
                                bool m_flag42;
                                uint8_t a_hi44;
                                if ((value28 & 0x20) == 0) {
                                    m_flag42 = 1;
                                    a_hi44 = value2 >> 8;
                                } else {
                                    bool m_flag41;
                                    uint8_t a_hi43;
                                    if (value30 == 0xEA) {
                                        RAM8(0x1834)++;
                                        BUS16_SET(c, 0x000000 + y, x);
                                        m_flag41 = 0;
                                        a_hi43 = x >> 8;
                                    } else {
                                        m_flag41 = 1;
                                        a_hi43 = value2 >> 8;
                                    }
                                    m_flag42 = m_flag41;
                                    a_hi44 = a_hi43;
                                }
                                m_flag43 = m_flag42;
                                a_hi45 = a_hi44;
                            }
                            m_flag44 = m_flag43;
                            a_hi46 = a_hi45;
                        }
                        m_flag45 = m_flag44;
                        a_hi47 = a_hi46;
                    }
                    m_flag46 = m_flag45;
                    a_hi48 = a_hi47;
                }
                m_flag47 = m_flag46;
                a_hi49 = a_hi48;
            }
            m_flag48 = m_flag47;
            a_hi50 = a_hi49;
        }
        m_flag49 = m_flag48;
        a_hi51 = a_hi50;
    }
    uint8_t value32 = RAM8(0x0000 + sp0 - 1);
    uint8_t value33 = RAM8(0x0000 + sp0);
    r->x = (uint16_t)(((value33 << 8) | value32) + 0x0200);
    r->y = (uint16_t)(y + 2);
    r->c = ((value33 << 8) | value32) + 0x0200 > 0xFFFF;
    r->v = ((((value33 << 8) | value32) ^ (uint16_t)(((value33 << 8) | value32) + 0x0200)) & ((uint16_t)(((value33 << 8) | value32) + 0x0200) ^ 0x0200) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0DAA1, SOM_RTS, "gen", test_one_native_menu_target_actor_and_advance_target_cursor, 0, L_X | L_Y | L_C | L_V, 2, 0, 0, 183, 78)
