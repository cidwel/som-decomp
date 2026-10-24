#include "som_c.h"

/* C08B5E update_complete_map_frame_screen_effects   [class C, 282 bytes, 136 instructions]
 * Source: src/rom/update_complete_map_frame_screen_effects.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void update_complete_map_frame_screen_effects(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const uint8_t db = r->db;
    uint8_t a_hi_8bc8 = 0;
    uint8_t x_8bc8 = 0;
    uint8_t y_8bc8 = 0;
    bool carry_8bc8 = 0;
    uint8_t a_8bb9 = 0;
    uint8_t a_hi_8bb9 = 0;
    uint8_t x_8bb9 = 0;
    uint8_t y_8bb9 = 0;
    bool negative_8bb9 = 0;
    uint8_t a_hi_8bb3 = 0;
    uint8_t x_8bb3 = 0;
    uint8_t y_8bb3 = 0;
    bool carry_8bb3 = 0;
    uint8_t a_hi_8bfe = 0;
    uint8_t x_8bfe = 0;
    uint8_t y_8bfe = 0;
    bool carry_8bfe = 0;
    uint8_t a_hi_8bec = 0;
    uint8_t x_8bec = 0;
    uint8_t y_8bec = 0;
    bool overflow_8bec = 0;
    uint8_t a_hi_8bdc = 0;
    uint8_t x_8bdc = 0;
    uint8_t y_8bdc = 0;
    bool carry_8bdc = 0;
    bool overflow_8bdc = 0;
    uint8_t value = RAM8(0x00E2);
    if (value != 0) {
        bool carry3;
        if ((value & 1) == 0) {
            carry3 = carry;
        } else {
            RAM8(0x00E4)--;
            bool carry2;
            if (RAM8(0x00E4) != 0) {
                carry2 = carry;
            } else {
                RAM8(0x00E4) = RAM8(0x00E5);
                uint8_t value3 = RAM8(0x00E6);
                uint8_t a1;
                if (!(value3 & 0x80)) {
                    a1 = value3;
                } else {
                    a1 = 0;
                }
                uint8_t value4 = RAM8(0x00E7);
                uint8_t a3;
                if (a1 == value4) {
                    a3 = a1;
                } else {
                    uint8_t a2;
                    if (a1 < value4) {
                        a2 = (uint8_t)(a1 + 1);
                    } else {
                        a2 = (uint8_t)(a1 - 1);
                    }
                    a3 = a2;
                }
                RAM8(0x00E6) = a3;
                bool carry1;
                if (a3 != value4) {
                    carry1 = a3 >= value4;
                } else {
                    if (a3 == 0) {
                        RAM8(0x00E6) = 0x8F;
                    }
                    RAM8(0x00E2) &= 0xFE;
                    carry1 = a3 >= 0;
                }
                carry2 = carry1;
            }
            carry3 = carry2;
        }
        if ((RAM8(0x00E2) & 2) == 0) {
            a_hi_8bc8 = a_hi;
            x_8bc8 = x;
            y_8bc8 = y;
            carry_8bc8 = carry3;
            goto shared_8BC8;
        }
        uint8_t value7 = BUS8_RDP(c, (db << 0x10) + 0x1057);
        if (!(value7 & 0x80)) {
            if (!((uint8_t)(value7 + 2) & 0x80)) {
                a_8bb9 = (uint8_t)(value7 + 2);
                a_hi_8bb9 = a_hi;
                x_8bb9 = x;
                y_8bb9 = y;
                negative_8bb9 = (uint8_t)(value7 + 2) & 0x80;
                goto shared_8BB9;
            }
            a_hi_8bb3 = a_hi;
            x_8bb3 = x;
            y_8bb3 = y;
            carry_8bb3 = value7 + 2 > 0xFF;
            goto shared_8BB3;
        }
        if (value7 + 2 <= 0xFF) {
            a_8bb9 = (uint8_t)(value7 + 2);
            a_hi_8bb9 = a_hi;
            x_8bb9 = x;
            y_8bb9 = y;
            negative_8bb9 = (uint8_t)(value7 + 2) & 0x80;
            goto shared_8BB9;
        }
        BUS8_SET(c, (db << 0x10) + 0x2106, RAM8(0x0020));
        a_hi_8bb3 = a_hi;
        x_8bb3 = x;
        y_8bb3 = y;
        carry_8bb3 = value7 + 2 > 0xFF;
        goto shared_8BB3;
    }
    SET_A8(r, value);
    r->z = value == 0;
    r->n = value & 0x80;
    RETURN_RTS(c);
    shared_8BC8:;
    uint8_t value9 = RAM8(0x00E2);
    if ((value9 & 4) == 0) {
        a_hi_8bfe = a_hi_8bc8;
        x_8bfe = x_8bc8;
        y_8bfe = y_8bc8;
        carry_8bfe = carry_8bc8;
        goto shared_8BFE;
    }
    uint8_t value10 = BUS8_RDP(c, (db << 0x10) + 0x1057);
    if (value10 == 0) {
        a_hi_8bec = a_hi_8bc8;
        x_8bec = x_8bc8;
        y_8bec = y_8bc8;
        overflow_8bec = value9 & 0x40;
        goto shared_8BEC;
    }
    uint8_t value11 = BUS8_RDP(c, (db << 0x10) + 0x1057);
    BUS8_SET(c, (db << 0x10) + 0x1057, (uint8_t)(value11 - 1));
    if ((uint8_t)(value11 - 1) != 0) {
        a_hi_8bec = a_hi_8bc8;
        x_8bec = x_8bc8;
        y_8bec = y_8bc8;
        overflow_8bec = value9 & 0x40;
        goto shared_8BEC;
    }
    RAM8(0x00E2) &= 0xFB;
    a_hi_8bdc = a_hi_8bc8;
    x_8bdc = x_8bc8;
    y_8bdc = y_8bc8;
    carry_8bdc = carry_8bc8;
    overflow_8bdc = value9 & 0x40;
    goto shared_8BDC;
    shared_8BB9:;
    BUS8_SET(c, (db << 0x10) + 0x1057, a_8bb9);
    uint8_t a4;
    if (!negative_8bb9) {
        a4 = a_8bb9;
    } else {
        a4 = a_8bb9 ^ 0xFF;
    }
    BUS8_SET(c, (db << 0x10) + 0x2106, ((uint8_t)(a4 << 1) & 0xF0) | 7);
    a_hi_8bc8 = a_hi_8bb9;
    x_8bc8 = x_8bb9;
    y_8bc8 = y_8bb9;
    carry_8bc8 = a4 & 0x80;
    goto shared_8BC8;
    shared_8BB3:;
    RAM8(0x00E2) &= 0xFD;
    a_hi_8bfe = a_hi_8bb3;
    x_8bfe = x_8bb3;
    y_8bfe = y_8bb3;
    carry_8bfe = carry_8bb3;
    goto shared_8BFE;
    shared_8BFE:;
    uint8_t value14 = RAM8(0x00E2);
    if ((value14 & 8) == 0) {
        if ((value14 & 0x10) == 0) {
            r->a = (a_hi_8bfe << 8) | 0x10;
            r->x = x_8bfe;
            r->y = y_8bfe;
            r->c = carry_8bfe;
            r->z = (value14 & 0x10) == 0;
            r->n = value14 & 0x80;
            r->v = value14 & 0x40;
            r->mf = 1;
            r->xf = 1;
            r->db = db;
            r->dp = 0;
            RETURN_RTS(c);
        }
        uint8_t value15 = RAM8(0x00F4);
        uint8_t a6;
        bool zero2;
        bool negative2;
        if ((value15 & 3) != 0) {
            a6 = value15 & 3;
            zero2 = (value15 & 3) == 0;
            negative2 = value15 & 3 & 0x80;
        } else {
            uint8_t value16 = BUS8_RDP(c, (db << 0x10) + 0x105A);
            BUS8_SET(c, (db << 0x10) + 0x105A, (uint8_t)(value16 - 1));
            uint8_t a5;
            bool zero1;
            bool negative1;
            if ((uint8_t)(value16 - 1) != 0) {
                a5 = value15 & 3;
                zero1 = (uint8_t)(value16 - 1) == 0;
                negative1 = (uint8_t)(value16 - 1) & 0x80;
            } else {
                RAM8(0x00E2) &= 0xEF;
                BUS8_SET(c, (db << 0x10) + 0x212D, RAM8(0x0022));
                BUS8_SET(c, (db << 0x10) + 0x2131, RAM8(0x0023));
                BUS8_SET(c, (db << 0x10) + 0x2132, 0xE0);
                a5 = 0xE0;
                zero1 = 0;
                negative1 = 1;
            }
            a6 = a5;
            zero2 = zero1;
            negative2 = negative1;
        }
        r->a = (a_hi_8bfe << 8) | a6;
        r->x = x_8bfe;
        r->y = y_8bfe;
        r->c = carry_8bfe;
        r->z = zero2;
        r->n = negative2;
        r->v = value14 & 0x40;
        r->mf = 1;
        r->xf = 1;
        r->db = db;
        r->dp = 0;
        RETURN_RTS(c);
    }
    uint16_t value20 = RAM16(0x00D4);
    uint8_t value21 = RAM8(0xE020 + value20);
    RAM8(0x0084) = 0;
    if (value21 < 0x7F) {
        uint8_t a7;
        if (value21 >= 0x7F) {
            a7 = 2;
        } else {
            a7 = 0x82;
        }
        RAM8(0x0084) = a7;
        uint8_t value22 = RAM8(0xE022 + value20);
        RAM8(0x0086) = 0;
        uint8_t a11;
        bool carry4;
        bool zero4;
        bool negative6;
        if (value22 < 0x7F) {
            uint8_t a8;
            bool negative3;
            if (value22 >= 0x7F) {
                a8 = 2;
                negative3 = 0;
            } else {
                a8 = 0x82;
                negative3 = 1;
            }
            RAM8(0x0086) = a8;
            a11 = a8;
            carry4 = value22 >= 0x7F;
            zero4 = 0;
            negative6 = negative3;
        } else {
            uint8_t a10;
            bool zero3;
            bool negative5;
            if (value22 >= 0x82) {
                uint8_t a9;
                bool negative4;
                if (value22 >= 0x82) {
                    a9 = 2;
                    negative4 = 0;
                } else {
                    a9 = 0x82;
                    negative4 = 1;
                }
                RAM8(0x0086) = a9;
                a10 = a9;
                zero3 = 0;
                negative5 = negative4;
            } else {
                a10 = value22;
                zero3 = value22 == 0x82;
                negative5 = (uint8_t)(value22 - 0x82) & 0x80;
            }
            a11 = a10;
            carry4 = value22 >= 0x82;
            zero4 = zero3;
            negative6 = negative5;
        }
        r->a = (a_hi_8bfe << 8) | a11;
        r->x = value20;
        r->y = y_8bfe;
        r->c = carry4;
        r->z = zero4;
        r->n = negative6;
        r->v = value14 & 0x40;
        r->mf = 1;
        r->xf = 0;
        r->db = db;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8C4F, 0xC0D1F9); GUARD_JSR(c, sp_call, 0x8C4F); } /* move_scene_camera_entry */
        r->c = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if (value21 >= 0x82) {
        uint8_t a12;
        if (value21 >= 0x82) {
            a12 = 2;
        } else {
            a12 = 0x82;
        }
        RAM8(0x0084) = a12;
        uint8_t value23 = RAM8(0xE022 + value20);
        RAM8(0x0086) = 0;
        uint8_t a16;
        bool carry5;
        bool zero6;
        bool negative10;
        if (value23 < 0x7F) {
            uint8_t a13;
            bool negative7;
            if (value23 >= 0x7F) {
                a13 = 2;
                negative7 = 0;
            } else {
                a13 = 0x82;
                negative7 = 1;
            }
            RAM8(0x0086) = a13;
            a16 = a13;
            carry5 = value23 >= 0x7F;
            zero6 = 0;
            negative10 = negative7;
        } else {
            uint8_t a15;
            bool zero5;
            bool negative9;
            if (value23 >= 0x82) {
                uint8_t a14;
                bool negative8;
                if (value23 >= 0x82) {
                    a14 = 2;
                    negative8 = 0;
                } else {
                    a14 = 0x82;
                    negative8 = 1;
                }
                RAM8(0x0086) = a14;
                a15 = a14;
                zero5 = 0;
                negative9 = negative8;
            } else {
                a15 = value23;
                zero5 = value23 == 0x82;
                negative9 = (uint8_t)(value23 - 0x82) & 0x80;
            }
            a16 = a15;
            carry5 = value23 >= 0x82;
            zero6 = zero5;
            negative10 = negative9;
        }
        r->a = (a_hi_8bfe << 8) | a16;
        r->x = value20;
        r->y = y_8bfe;
        r->c = carry5;
        r->z = zero6;
        r->n = negative10;
        r->v = value14 & 0x40;
        r->mf = 1;
        r->xf = 0;
        r->db = db;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8C4F, 0xC0D1F9); GUARD_JSR(c, sp_call, 0x8C4F); } /* move_scene_camera_entry */
        r->c = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    RAM8(0x0086) = 0;
    uint8_t value24 = RAM8(0xE022 + value20);
    if (value24 < 0x7F) {
        uint8_t a17;
        bool negative11;
        if (value24 >= 0x7F) {
            a17 = 2;
            negative11 = 0;
        } else {
            a17 = 0x82;
            negative11 = 1;
        }
        RAM8(0x0086) = a17;
        r->a = (a_hi_8bfe << 8) | a17;
        r->x = value20;
        r->y = y_8bfe;
        r->c = value24 >= 0x7F;
        r->z = 0;
        r->n = negative11;
        r->v = value14 & 0x40;
        r->mf = 1;
        r->xf = 0;
        r->db = db;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8C4F, 0xC0D1F9); GUARD_JSR(c, sp_call, 0x8C4F); } /* move_scene_camera_entry */
        r->c = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if (value24 >= 0x82) {
        uint8_t a18;
        bool negative12;
        if (value24 >= 0x82) {
            a18 = 2;
            negative12 = 0;
        } else {
            a18 = 0x82;
            negative12 = 1;
        }
        RAM8(0x0086) = a18;
        r->a = (a_hi_8bfe << 8) | a18;
        r->x = value20;
        r->y = y_8bfe;
        r->c = value24 >= 0x82;
        r->z = 0;
        r->n = negative12;
        r->v = value14 & 0x40;
        r->mf = 1;
        r->xf = 0;
        r->db = db;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8C4F, 0xC0D1F9); GUARD_JSR(c, sp_call, 0x8C4F); } /* move_scene_camera_entry */
        r->c = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    uint8_t value25 = RAM8(0x00E2);
    RAM8(0x00E2) &= 0xF7;
    r->a = (a_hi_8bfe << 8) | 8;
    r->x = value20;
    r->y = y_8bfe;
    r->c = value24 >= 0x82;
    r->z = (value25 & 8) == 0;
    r->n = 0;
    r->v = value14 & 0x40;
    r->mf = 1;
    r->xf = 0;
    r->db = db;
    r->dp = 0;
    RETURN_RTS(c);
    shared_8BEC:;
    uint8_t value26 = RAM8(0x00F4);
    if (!(value26 & 0x01)) {
        a_hi_8bdc = a_hi_8bec;
        x_8bdc = x_8bec;
        y_8bdc = y_8bec;
        carry_8bdc = value26 & 0x01;
        overflow_8bdc = overflow_8bec;
        goto shared_8BDC;
    }
    BUS8_SET(c, (db << 0x10) + 0x2130, 0);
    BUS8_SET(c, (db << 0x10) + 0x2131, 0x0F);
    BUS8_SET(c, (db << 0x10) + 0x2132, 0xFF);
    a_hi_8bfe = a_hi_8bec;
    x_8bfe = x_8bec;
    y_8bfe = y_8bec;
    carry_8bfe = value26 & 0x01;
    goto shared_8BFE;
    shared_8BDC:;
    BUS8_SET(c, (db << 0x10) + 0x2130, 2);
    BUS8_SET(c, (db << 0x10) + 0x2131, RAM8(0x0023));
    BUS8_SET(c, (db << 0x10) + 0x2132, 0xE0);
    r->a = (a_hi_8bdc << 8) | 0xE0;
    r->x = x_8bdc;
    r->y = y_8bdc;
    r->c = carry_8bdc;
    r->z = 0;
    r->n = 1;
    r->v = overflow_8bdc;
    r->mf = 1;
    r->xf = 1;
    r->db = db;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08B5E, SOM_RTS, "gen", update_complete_map_frame_screen_effects, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 282, 136)
