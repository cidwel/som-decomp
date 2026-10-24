#include "som_c.h"

/* C0C59F detect_map_scroll_edges_and_prepare_both_layer_tile_buffers   [class C, 243 bytes, 121 instructions]
 * Source: src/rom/detect_map_scroll_edges_and_prepare_both_layer_tile_buffers.s
 * Documented in docs/map-scroll-edge-planning.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void detect_map_scroll_edges_and_prepare_both_layer_tile_buffers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    uint16_t value = RAM16(0x0088);
    uint8_t a_hi6;
    uint8_t x18;
    bool carry10;
    if (value != 0) {
        uint16_t value2 = RAM16(0x00A8);
        uint8_t a_hi1;
        uint8_t x7;
        bool carry3;
        if ((value2 & 0xFFF0) != 0) {
            uint8_t x2;
            if ((value2 & 0xFFF0) == value) {
                x2 = 0;
            } else {
                RAM16_SET(0x0088, value2 & 0xFFF0);
                uint8_t x1;
                if (!((uint16_t)((value2 & 0xFFF0) - value) & 0x8000)) {
                    x1 = 0;
                } else {
                    x1 = 1;
                }
                x2 = (uint8_t)(x1 + 1);
            }
            a_hi1 = (value2 & 0xFFF0) >> 8;
            x7 = x2;
            carry3 = (value2 & 0xFFF0) >= value;
        } else {
            RAM16_SET(0x0088, 0);
            uint8_t x6;
            bool carry2;
            if (value == 0x10) {
                x6 = 2;
                carry2 = value >= 0x10;
            } else {
                uint8_t x5;
                bool carry1;
                if (value != 0x10) {
                    x5 = 1;
                    carry1 = value >= 0x10;
                } else {
                    uint16_t value3 = RAM16(0x0088);
                    uint8_t x4;
                    if (value == value3) {
                        x4 = 0;
                    } else {
                        RAM16_SET(0x0088, value);
                        uint8_t x3;
                        if (!((uint16_t)(value - value3) & 0x8000)) {
                            x3 = 0;
                        } else {
                            x3 = 1;
                        }
                        x4 = (uint8_t)(x3 + 1);
                    }
                    x5 = x4;
                    carry1 = value >= value3;
                }
                x6 = x5;
                carry2 = carry1;
            }
            a_hi1 = value >> 8;
            x7 = x6;
            carry3 = carry2;
        }
        a_hi6 = a_hi1;
        x18 = x7;
        carry10 = carry3;
    } else {
        uint16_t value4 = RAM16(0x00A8);
        uint8_t a_hi5;
        uint8_t x17;
        bool carry9;
        if ((value4 & 0xFFF0) == 0) {
            a_hi5 = (value4 & 0xFFF0) >> 8;
            x17 = 0;
            carry9 = carry;
        } else {
            RAM16_SET(0x0088, value4 & 0xFFF0);
            uint8_t a_hi4;
            uint8_t x16;
            bool carry8;
            if ((value4 & 0xFFF0) == 0x10) {
                a_hi4 = (value4 & 0xFFF0) >> 8;
                x16 = 1;
                carry8 = (value4 & 0xFFF0) >= 0x10;
            } else {
                uint8_t a_hi3;
                uint8_t x15;
                bool carry7;
                if ((value4 & 0xFFF0) != 0x10) {
                    a_hi3 = (value4 & 0xFFF0) >> 8;
                    x15 = 2;
                    carry7 = (value4 & 0xFFF0) >= 0x10;
                } else {
                    uint8_t a_hi2;
                    uint8_t x14;
                    bool carry6;
                    if ((value4 & 0xFFF0) != 0) {
                        uint16_t value5 = RAM16(0x0088);
                        uint8_t x9;
                        if ((value4 & 0xFFF0) == value5) {
                            x9 = 0;
                        } else {
                            RAM16_SET(0x0088, value4 & 0xFFF0);
                            uint8_t x8;
                            if (!((uint16_t)((value4 & 0xFFF0) - value5) & 0x8000)) {
                                x8 = 0;
                            } else {
                                x8 = 1;
                            }
                            x9 = (uint8_t)(x8 + 1);
                        }
                        a_hi2 = (value4 & 0xFFF0) >> 8;
                        x14 = x9;
                        carry6 = (value4 & 0xFFF0) >= value5;
                    } else {
                        uint16_t value6 = RAM16(0x0088);
                        RAM16_SET(0x0088, 0);
                        uint8_t x13;
                        bool carry5;
                        if (value6 == 0x10) {
                            x13 = 2;
                            carry5 = value6 >= 0x10;
                        } else {
                            uint8_t x12;
                            bool carry4;
                            if (value6 != 0x10) {
                                x12 = 1;
                                carry4 = value6 >= 0x10;
                            } else {
                                uint16_t value7 = RAM16(0x0088);
                                uint8_t x11;
                                if (value6 == value7) {
                                    x11 = 0;
                                } else {
                                    RAM16_SET(0x0088, value6);
                                    uint8_t x10;
                                    if (!((uint16_t)(value6 - value7) & 0x8000)) {
                                        x10 = 0;
                                    } else {
                                        x10 = 1;
                                    }
                                    x11 = (uint8_t)(x10 + 1);
                                }
                                x12 = x11;
                                carry4 = value6 >= value7;
                            }
                            x13 = x12;
                            carry5 = carry4;
                        }
                        a_hi2 = value6 >> 8;
                        x14 = x13;
                        carry6 = carry5;
                    }
                    a_hi3 = a_hi2;
                    x15 = x14;
                    carry7 = carry6;
                }
                a_hi4 = a_hi3;
                x16 = x15;
                carry8 = carry7;
            }
            a_hi5 = a_hi4;
            x17 = x16;
            carry9 = carry8;
        }
        a_hi6 = a_hi5;
        x18 = x17;
        carry10 = carry9;
    }
    uint16_t value8 = RAM16(0x008A);
    uint8_t a6;
    uint8_t a_hi12;
    uint8_t y18;
    bool carry20;
    if (value8 != 0) {
        uint16_t value9 = RAM16(0x00AA);
        uint8_t a1;
        uint8_t a_hi7;
        uint8_t y7;
        bool carry13;
        if ((value9 & 0xFFF0) != 0) {
            uint8_t y2;
            if ((value9 & 0xFFF0) == value8) {
                y2 = 0;
            } else {
                RAM16_SET(0x008A, value9 & 0xFFF0);
                uint8_t y1;
                if (!((uint16_t)((value9 & 0xFFF0) - value8) & 0x8000)) {
                    y1 = 0;
                } else {
                    y1 = 1;
                }
                y2 = (uint8_t)(y1 + 1);
            }
            a1 = (uint8_t)(value9 & 0xFFF0);
            a_hi7 = (value9 & 0xFFF0) >> 8;
            y7 = y2;
            carry13 = (value9 & 0xFFF0) >= value8;
        } else {
            RAM16_SET(0x008A, 0);
            uint8_t y6;
            bool carry12;
            if (value8 == 0x10) {
                y6 = 2;
                carry12 = value8 >= 0x10;
            } else {
                uint8_t y5;
                bool carry11;
                if (value8 != 0x10) {
                    y5 = 1;
                    carry11 = value8 >= 0x10;
                } else {
                    uint16_t value10 = RAM16(0x008A);
                    uint8_t y4;
                    if (value8 == value10) {
                        y4 = 0;
                    } else {
                        RAM16_SET(0x008A, value8);
                        uint8_t y3;
                        if (!((uint16_t)(value8 - value10) & 0x8000)) {
                            y3 = 0;
                        } else {
                            y3 = 1;
                        }
                        y4 = (uint8_t)(y3 + 1);
                    }
                    y5 = y4;
                    carry11 = value8 >= value10;
                }
                y6 = y5;
                carry12 = carry11;
            }
            a1 = (uint8_t)value8;
            a_hi7 = value8 >> 8;
            y7 = y6;
            carry13 = carry12;
        }
        a6 = a1;
        a_hi12 = a_hi7;
        y18 = y7;
        carry20 = carry13;
    } else {
        uint16_t value11 = RAM16(0x00AA);
        uint8_t a5;
        uint8_t a_hi11;
        uint8_t y17;
        bool carry19;
        if ((value11 & 0xFFF0) == 0) {
            a5 = (uint8_t)(value11 & 0xFFF0);
            a_hi11 = (value11 & 0xFFF0) >> 8;
            y17 = 0;
            carry19 = carry10;
        } else {
            RAM16_SET(0x008A, value11 & 0xFFF0);
            uint8_t a4;
            uint8_t a_hi10;
            uint8_t y16;
            bool carry18;
            if ((value11 & 0xFFF0) == 0x10) {
                a4 = (uint8_t)(value11 & 0xFFF0);
                a_hi10 = (value11 & 0xFFF0) >> 8;
                y16 = 1;
                carry18 = (value11 & 0xFFF0) >= 0x10;
            } else {
                uint8_t a3;
                uint8_t a_hi9;
                uint8_t y15;
                bool carry17;
                if ((value11 & 0xFFF0) != 0x10) {
                    a3 = (uint8_t)(value11 & 0xFFF0);
                    a_hi9 = (value11 & 0xFFF0) >> 8;
                    y15 = 2;
                    carry17 = (value11 & 0xFFF0) >= 0x10;
                } else {
                    uint8_t a2;
                    uint8_t a_hi8;
                    uint8_t y14;
                    bool carry16;
                    if ((value11 & 0xFFF0) != 0) {
                        uint16_t value12 = RAM16(0x008A);
                        uint8_t y9;
                        if ((value11 & 0xFFF0) == value12) {
                            y9 = 0;
                        } else {
                            RAM16_SET(0x008A, value11 & 0xFFF0);
                            uint8_t y8;
                            if (!((uint16_t)((value11 & 0xFFF0) - value12) & 0x8000)) {
                                y8 = 0;
                            } else {
                                y8 = 1;
                            }
                            y9 = (uint8_t)(y8 + 1);
                        }
                        a2 = (uint8_t)(value11 & 0xFFF0);
                        a_hi8 = (value11 & 0xFFF0) >> 8;
                        y14 = y9;
                        carry16 = (value11 & 0xFFF0) >= value12;
                    } else {
                        uint16_t value13 = RAM16(0x008A);
                        RAM16_SET(0x008A, 0);
                        uint8_t y13;
                        bool carry15;
                        if (value13 == 0x10) {
                            y13 = 2;
                            carry15 = value13 >= 0x10;
                        } else {
                            uint8_t y12;
                            bool carry14;
                            if (value13 != 0x10) {
                                y12 = 1;
                                carry14 = value13 >= 0x10;
                            } else {
                                uint16_t value14 = RAM16(0x008A);
                                uint8_t y11;
                                if (value13 == value14) {
                                    y11 = 0;
                                } else {
                                    RAM16_SET(0x008A, value13);
                                    uint8_t y10;
                                    if (!((uint16_t)(value13 - value14) & 0x8000)) {
                                        y10 = 0;
                                    } else {
                                        y10 = 1;
                                    }
                                    y11 = (uint8_t)(y10 + 1);
                                }
                                y12 = y11;
                                carry14 = value13 >= value14;
                            }
                            y13 = y12;
                            carry15 = carry14;
                        }
                        a2 = (uint8_t)value13;
                        a_hi8 = value13 >> 8;
                        y14 = y13;
                        carry16 = carry15;
                    }
                    a3 = a2;
                    a_hi9 = a_hi8;
                    y15 = y14;
                    carry17 = carry16;
                }
                a4 = a3;
                a_hi10 = a_hi9;
                y16 = y15;
                carry18 = carry17;
            }
            a5 = a4;
            a_hi11 = a_hi10;
            y17 = y16;
            carry19 = carry18;
        }
        a6 = a5;
        a_hi12 = a_hi11;
        y18 = y17;
        carry20 = carry19;
    }
    RAM8(0x002F) = x18;
    RAM8(0x002E) = y18;
    uint8_t value15 = RAM8(0x00B9);
    if (value15 == 0) {
        r->a = (a_hi12 << 8) | a6;
        r->x = value15;
        r->y = y18;
        r->c = carry20;
        r->mf = 0;
        r->xf = 1;
        JSR(c, 0xC68E, 0xC0C7C3); /* prepare_pending_map_rows */
        r->mf = 1;
        r->xf = 1;
        TAIL_CALL(c, 0xC0C8EF, SOM_RTS); /* prepare_pending_map_columns */
    }
    uint16_t value16 = RAM16(0x008C);
    uint8_t a_hi18;
    uint8_t x36;
    bool carry30;
    if (value16 != 0) {
        uint16_t value17 = RAM16(0x00AC);
        uint8_t a_hi13;
        uint8_t x25;
        bool carry23;
        if ((value17 & 0xFFF0) != 0) {
            uint8_t x20;
            if ((value17 & 0xFFF0) == value16) {
                x20 = 0;
            } else {
                RAM16_SET(0x008C, value17 & 0xFFF0);
                uint8_t x19;
                if (!((uint16_t)((value17 & 0xFFF0) - value16) & 0x8000)) {
                    x19 = 0;
                } else {
                    x19 = 1;
                }
                x20 = (uint8_t)(x19 + 1);
            }
            a_hi13 = (value17 & 0xFFF0) >> 8;
            x25 = x20;
            carry23 = (value17 & 0xFFF0) >= value16;
        } else {
            RAM16_SET(0x008C, 0);
            uint8_t x24;
            bool carry22;
            if (value16 == 0x10) {
                x24 = 2;
                carry22 = value16 >= 0x10;
            } else {
                uint8_t x23;
                bool carry21;
                if (value16 != 0x10) {
                    x23 = 1;
                    carry21 = value16 >= 0x10;
                } else {
                    uint16_t value18 = RAM16(0x008C);
                    uint8_t x22;
                    if (value16 == value18) {
                        x22 = 0;
                    } else {
                        RAM16_SET(0x008C, value16);
                        uint8_t x21;
                        if (!((uint16_t)(value16 - value18) & 0x8000)) {
                            x21 = 0;
                        } else {
                            x21 = 1;
                        }
                        x22 = (uint8_t)(x21 + 1);
                    }
                    x23 = x22;
                    carry21 = value16 >= value18;
                }
                x24 = x23;
                carry22 = carry21;
            }
            a_hi13 = value16 >> 8;
            x25 = x24;
            carry23 = carry22;
        }
        a_hi18 = a_hi13;
        x36 = x25;
        carry30 = carry23;
    } else {
        uint16_t value19 = RAM16(0x00AC);
        uint8_t a_hi17;
        uint8_t x35;
        bool carry29;
        if ((value19 & 0xFFF0) == 0) {
            a_hi17 = (value19 & 0xFFF0) >> 8;
            x35 = 0;
            carry29 = carry20;
        } else {
            RAM16_SET(0x008C, value19 & 0xFFF0);
            uint8_t a_hi16;
            uint8_t x34;
            bool carry28;
            if ((value19 & 0xFFF0) == 0x10) {
                a_hi16 = (value19 & 0xFFF0) >> 8;
                x34 = 1;
                carry28 = (value19 & 0xFFF0) >= 0x10;
            } else {
                uint8_t a_hi15;
                uint8_t x33;
                bool carry27;
                if ((value19 & 0xFFF0) != 0x10) {
                    a_hi15 = (value19 & 0xFFF0) >> 8;
                    x33 = 2;
                    carry27 = (value19 & 0xFFF0) >= 0x10;
                } else {
                    uint8_t a_hi14;
                    uint8_t x32;
                    bool carry26;
                    if ((value19 & 0xFFF0) != 0) {
                        uint16_t value20 = RAM16(0x008C);
                        uint8_t x27;
                        if ((value19 & 0xFFF0) == value20) {
                            x27 = 0;
                        } else {
                            RAM16_SET(0x008C, value19 & 0xFFF0);
                            uint8_t x26;
                            if (!((uint16_t)((value19 & 0xFFF0) - value20) & 0x8000)) {
                                x26 = 0;
                            } else {
                                x26 = 1;
                            }
                            x27 = (uint8_t)(x26 + 1);
                        }
                        a_hi14 = (value19 & 0xFFF0) >> 8;
                        x32 = x27;
                        carry26 = (value19 & 0xFFF0) >= value20;
                    } else {
                        uint16_t value21 = RAM16(0x008C);
                        RAM16_SET(0x008C, 0);
                        uint8_t x31;
                        bool carry25;
                        if (value21 == 0x10) {
                            x31 = 2;
                            carry25 = value21 >= 0x10;
                        } else {
                            uint8_t x30;
                            bool carry24;
                            if (value21 != 0x10) {
                                x30 = 1;
                                carry24 = value21 >= 0x10;
                            } else {
                                uint16_t value22 = RAM16(0x008C);
                                uint8_t x29;
                                if (value21 == value22) {
                                    x29 = 0;
                                } else {
                                    RAM16_SET(0x008C, value21);
                                    uint8_t x28;
                                    if (!((uint16_t)(value21 - value22) & 0x8000)) {
                                        x28 = 0;
                                    } else {
                                        x28 = 1;
                                    }
                                    x29 = (uint8_t)(x28 + 1);
                                }
                                x30 = x29;
                                carry24 = value21 >= value22;
                            }
                            x31 = x30;
                            carry25 = carry24;
                        }
                        a_hi14 = value21 >> 8;
                        x32 = x31;
                        carry26 = carry25;
                    }
                    a_hi15 = a_hi14;
                    x33 = x32;
                    carry27 = carry26;
                }
                a_hi16 = a_hi15;
                x34 = x33;
                carry28 = carry27;
            }
            a_hi17 = a_hi16;
            x35 = x34;
            carry29 = carry28;
        }
        a_hi18 = a_hi17;
        x36 = x35;
        carry30 = carry29;
    }
    uint16_t value23 = RAM16(0x008E);
    uint8_t a_hi24;
    uint8_t y36;
    bool carry40;
    if (value23 != 0) {
        uint16_t value24 = RAM16(0x00AE);
        uint8_t a_hi19;
        uint8_t y25;
        bool carry33;
        if ((value24 & 0xFFF0) != 0) {
            uint8_t y20;
            if ((value24 & 0xFFF0) == value23) {
                y20 = 0;
            } else {
                RAM16_SET(0x008E, value24 & 0xFFF0);
                uint8_t y19;
                if (!((uint16_t)((value24 & 0xFFF0) - value23) & 0x8000)) {
                    y19 = 0;
                } else {
                    y19 = 1;
                }
                y20 = (uint8_t)(y19 + 1);
            }
            a_hi19 = (value24 & 0xFFF0) >> 8;
            y25 = y20;
            carry33 = (value24 & 0xFFF0) >= value23;
        } else {
            RAM16_SET(0x008E, 0);
            uint8_t y24;
            bool carry32;
            if (value23 == 0x10) {
                y24 = 2;
                carry32 = value23 >= 0x10;
            } else {
                uint8_t y23;
                bool carry31;
                if (value23 != 0x10) {
                    y23 = 1;
                    carry31 = value23 >= 0x10;
                } else {
                    uint16_t value25 = RAM16(0x008E);
                    uint8_t y22;
                    if (value23 == value25) {
                        y22 = 0;
                    } else {
                        RAM16_SET(0x008E, value23);
                        uint8_t y21;
                        if (!((uint16_t)(value23 - value25) & 0x8000)) {
                            y21 = 0;
                        } else {
                            y21 = 1;
                        }
                        y22 = (uint8_t)(y21 + 1);
                    }
                    y23 = y22;
                    carry31 = value23 >= value25;
                }
                y24 = y23;
                carry32 = carry31;
            }
            a_hi19 = value23 >> 8;
            y25 = y24;
            carry33 = carry32;
        }
        a_hi24 = a_hi19;
        y36 = y25;
        carry40 = carry33;
    } else {
        uint16_t value26 = RAM16(0x00AE);
        uint8_t a_hi23;
        uint8_t y35;
        bool carry39;
        if ((value26 & 0xFFF0) == 0) {
            a_hi23 = (value26 & 0xFFF0) >> 8;
            y35 = 0;
            carry39 = carry30;
        } else {
            RAM16_SET(0x008E, value26 & 0xFFF0);
            uint8_t a_hi22;
            uint8_t y34;
            bool carry38;
            if ((value26 & 0xFFF0) == 0x10) {
                a_hi22 = (value26 & 0xFFF0) >> 8;
                y34 = 1;
                carry38 = (value26 & 0xFFF0) >= 0x10;
            } else {
                uint8_t a_hi21;
                uint8_t y33;
                bool carry37;
                if ((value26 & 0xFFF0) != 0x10) {
                    a_hi21 = (value26 & 0xFFF0) >> 8;
                    y33 = 2;
                    carry37 = (value26 & 0xFFF0) >= 0x10;
                } else {
                    uint8_t a_hi20;
                    uint8_t y32;
                    bool carry36;
                    if ((value26 & 0xFFF0) != 0) {
                        uint16_t value27 = RAM16(0x008E);
                        uint8_t y27;
                        if ((value26 & 0xFFF0) == value27) {
                            y27 = 0;
                        } else {
                            RAM16_SET(0x008E, value26 & 0xFFF0);
                            uint8_t y26;
                            if (!((uint16_t)((value26 & 0xFFF0) - value27) & 0x8000)) {
                                y26 = 0;
                            } else {
                                y26 = 1;
                            }
                            y27 = (uint8_t)(y26 + 1);
                        }
                        a_hi20 = (value26 & 0xFFF0) >> 8;
                        y32 = y27;
                        carry36 = (value26 & 0xFFF0) >= value27;
                    } else {
                        uint16_t value28 = RAM16(0x008E);
                        RAM16_SET(0x008E, 0);
                        uint8_t y31;
                        bool carry35;
                        if (value28 == 0x10) {
                            y31 = 2;
                            carry35 = value28 >= 0x10;
                        } else {
                            uint8_t y30;
                            bool carry34;
                            if (value28 != 0x10) {
                                y30 = 1;
                                carry34 = value28 >= 0x10;
                            } else {
                                uint16_t value29 = RAM16(0x008E);
                                uint8_t y29;
                                if (value28 == value29) {
                                    y29 = 0;
                                } else {
                                    RAM16_SET(0x008E, value28);
                                    uint8_t y28;
                                    if (!((uint16_t)(value28 - value29) & 0x8000)) {
                                        y28 = 0;
                                    } else {
                                        y28 = 1;
                                    }
                                    y29 = (uint8_t)(y28 + 1);
                                }
                                y30 = y29;
                                carry34 = value28 >= value29;
                            }
                            y31 = y30;
                            carry35 = carry34;
                        }
                        a_hi20 = value28 >> 8;
                        y32 = y31;
                        carry36 = carry35;
                    }
                    a_hi21 = a_hi20;
                    y33 = y32;
                    carry37 = carry36;
                }
                a_hi22 = a_hi21;
                y34 = y33;
                carry38 = carry37;
            }
            a_hi23 = a_hi22;
            y35 = y34;
            carry39 = carry38;
        }
        a_hi24 = a_hi23;
        y36 = y35;
        carry40 = carry39;
    }
    uint8_t value30 = RAM8(0x0029);
    if ((value30 & 4) == 0) {
        RAM8(0x002F) = (uint8_t)(x36 << 2) | RAM8(0x002F);
        uint8_t value32 = RAM8(0x002E);
        RAM8(0x002E) = (uint8_t)(y36 << 2) | value32;
        r->a = (a_hi24 << 8) | ((uint8_t)(y36 << 2) | value32);
        r->x = x36;
        r->y = y36;
        r->c = (uint8_t)(y36 << 1) & 0x80;
        r->xf = 1;
        JSR(c, 0xC68E, 0xC0C7C3); /* prepare_pending_map_rows */
        r->mf = 1;
        r->xf = 1;
        TAIL_CALL(c, 0xC0C8EF, SOM_RTS); /* prepare_pending_map_columns */
    }
    RAM8(0x002F) = 0;
    RAM8(0x002E) = 0;
    r->a = (a_hi24 << 8) | value30;
    r->x = x36;
    r->y = y36;
    r->c = carry40;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C59F, SOM_RTS, "gen", detect_map_scroll_edges_and_prepare_both_layer_tile_buffers, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 243, 121)
