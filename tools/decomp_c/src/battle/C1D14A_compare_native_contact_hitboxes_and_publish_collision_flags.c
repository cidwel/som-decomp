#include "som_c.h"

/* C1D14A compare_native_contact_hitboxes_and_publish_collision_flags   [class C, 315 bytes, 135 instructions]
 * Source: src/rom/compare_native_contact_hitboxes_and_publish_collision_flags.s
 * Documented in docs/actor-party-map-contacts.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void compare_native_contact_hitboxes_and_publish_collision_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    uint16_t value = RAM16(0xE0C2 + x);
    uint8_t a_hi9;
    uint16_t y7;
    bool carry11;
    if (value != 0) {
        RAM16_SET(0x0016, value);
        uint16_t value2 = RAM16(0xE0C0 + x);
        RAM16_SET(0x0014, value2);
        uint8_t value3 = RAM8(0x0050);
        uint8_t value4 = RAM8(0xE05A + x);
        uint8_t a_hi3;
        uint16_t y3;
        bool carry3;
        if ((value3 & 0xF0 & value4) != 0) {
            a_hi3 = value2 >> 8;
            y3 = y;
            carry3 = carry;
        } else {
            uint16_t value5 = RAM16(0xE0C2 + y);
            uint8_t a_hi2;
            uint16_t y2;
            bool carry2;
            if (value5 == 0) {
                a_hi2 = value5 >> 8;
                y2 = y;
                carry2 = carry;
            } else {
                RAM16_SET(0x0012, value5);
                uint16_t value6 = RAM16(0xE0C0 + y);
                RAM16_SET(0x0010, value6);
                r->a = value6;
                r->mf = 0;
                JSR(c, 0xD176, 0xC1D42A); /* compare_two_packed_contact_hitboxes */
                uint16_t a_all = r->a;
                bool carry_ret = r->c;
                uint8_t a_hi1;
                uint16_t y1;
                bool carry1;
                if (carry_ret) {
                    a_hi1 = a_all >> 8;
                    y1 = y;
                    carry1 = carry_ret;
                } else {
                    r->a = (a_all >> 8 << 8) | 0x80;
                    r->mf = 1;
                    r->xf = 0;
                    JSR(c, 0xD17F, 0xC1D285); /* record_contact_presentation_byte_and_volume */
                    uint16_t a_all2 = r->a;
                    uint16_t y_ret = r->y;
                    bool carry_ret2 = r->c;
                    RAM8(0xE05A + x) = (RAM8(0x0050) & 0xF0) | RAM8(0xE05A + x);
                    a_hi1 = a_all2 >> 8;
                    y1 = y_ret;
                    carry1 = carry_ret2;
                }
                a_hi2 = a_hi1;
                y2 = y1;
                carry2 = carry1;
            }
            a_hi3 = a_hi2;
            y3 = y2;
            carry3 = carry2;
        }
        uint8_t value9 = RAM8(0x0050);
        uint8_t value10 = RAM8(0xE05A + x);
        uint8_t a_hi5;
        bool carry7;
        if ((value9 & 0x0F & value10) != 0) {
            a_hi5 = a_hi3;
            carry7 = carry3;
        } else {
            uint16_t value11 = RAM16(0xE0CA + y3);
            uint8_t a_hi4;
            bool carry6;
            if (value11 == 0) {
                a_hi4 = value11 >> 8;
                carry6 = carry3;
            } else {
                RAM16_SET(0x0012, value11);
                uint16_t value12 = RAM16(0xE0C8 + y3);
                RAM16_SET(0x0010, value12);
                r->a = value12;
                r->y = y3;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0xD1A5, 0xC1D42A); /* compare_two_packed_contact_hitboxes */
                uint16_t a_all3 = r->a;
                bool carry_ret3 = r->c;
                bool carry5;
                if (carry_ret3) {
                    carry5 = carry_ret3;
                } else {
                    uint8_t a2;
                    bool carry4;
                    if (x == 0) {
                        a2 = 1;
                        carry4 = x >= 0;
                    } else {
                        uint8_t a1;
                        if (x == 0x0200) {
                            a1 = 2;
                        } else {
                            a1 = 4;
                        }
                        a2 = a1;
                        carry4 = x >= 0x0200;
                    }
                    RAM8(HERO_HIT_MASK + y3) = a2 | RAM8(HERO_HIT_MASK + y3);
                    RAM8(0xE05A + x) = (RAM8(0x0050) & 0x0F) | RAM8(0xE05A + x);
                    carry5 = carry4;
                }
                a_hi4 = a_all3 >> 8;
                carry6 = carry5;
            }
            a_hi5 = a_hi4;
            carry7 = carry6;
        }
        uint8_t value15 = RAM8(0x0050);
        uint8_t value16 = RAM8(0xE05A + x);
        uint8_t a_hi8;
        uint16_t y6;
        bool carry10;
        if ((value15 & 0xF0 & value16) != 0) {
            a_hi8 = a_hi5;
            y6 = y3;
            carry10 = carry7;
        } else {
            uint16_t value17 = RAM16(0xE0CE + y3);
            uint8_t a_hi7;
            uint16_t y5;
            bool carry9;
            if (value17 == 0) {
                a_hi7 = value17 >> 8;
                y5 = y3;
                carry9 = carry7;
            } else {
                RAM16_SET(0x0012, value17);
                uint16_t value18 = RAM16(0xE0CC + y3);
                RAM16_SET(0x0010, value18);
                r->a = value18;
                r->y = y3;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0xD1E4, 0xC1D42A); /* compare_two_packed_contact_hitboxes */
                uint16_t a_all4 = r->a;
                bool carry_ret4 = r->c;
                uint8_t a_hi6;
                uint16_t y4;
                bool carry8;
                if (carry_ret4) {
                    a_hi6 = a_all4 >> 8;
                    y4 = y3;
                    carry8 = carry_ret4;
                } else {
                    r->a = (a_all4 >> 8 << 8) | 0x81;
                    r->mf = 1;
                    r->xf = 0;
                    JSR(c, 0xD1ED, 0xC1D285); /* record_contact_presentation_byte_and_volume */
                    uint16_t a_all5 = r->a;
                    uint16_t y_ret2 = r->y;
                    bool carry_ret5 = r->c;
                    RAM8(0xE05A + x) = (RAM8(0x0050) & 0xF0) | RAM8(0xE05A + x);
                    a_hi6 = a_all5 >> 8;
                    y4 = y_ret2;
                    carry8 = carry_ret5;
                }
                a_hi7 = a_hi6;
                y5 = y4;
                carry9 = carry8;
            }
            a_hi8 = a_hi7;
            y6 = y5;
            carry10 = carry9;
        }
        a_hi9 = a_hi8;
        y7 = y6;
        carry11 = carry10;
    } else {
        a_hi9 = value >> 8;
        y7 = y;
        carry11 = carry;
    }
    RAM16_SET(0x0006, RAM16(0x0006) ^ 0x8080);
    uint16_t value22 = RAM16(0xE0C2 + y7);
    uint8_t a_hi15;
    uint16_t y11;
    if (value22 == 0) {
        a_hi15 = value22 >> 8;
        y11 = y7;
    } else {
        RAM16_SET(0x0016, value22);
        uint16_t value23 = RAM16(0xE0C0 + y7);
        RAM16_SET(0x0014, value23);
        uint8_t value24 = RAM8(0x0051);
        uint8_t value25 = RAM8(0xE05A + y7);
        uint8_t a_hi11;
        bool carry15;
        if ((value24 & 0x0F & value25) != 0) {
            a_hi11 = value23 >> 8;
            carry15 = carry11;
        } else {
            uint16_t value26 = RAM16(0xE0CA + x);
            uint8_t a_hi10;
            bool carry14;
            if (value26 == 0) {
                a_hi10 = value26 >> 8;
                carry14 = carry11;
            } else {
                RAM16_SET(0x0012, value26);
                uint16_t value27 = RAM16(0xE0C8 + x);
                RAM16_SET(0x0010, value27);
                r->a = value27;
                r->y = y7;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0xD228, 0xC1D42A); /* compare_two_packed_contact_hitboxes */
                uint16_t a_all6 = r->a;
                bool carry_ret6 = r->c;
                bool carry13;
                if (carry_ret6) {
                    carry13 = carry_ret6;
                } else {
                    uint8_t a4;
                    bool carry12;
                    if (y7 == 0x0600) {
                        a4 = 1;
                        carry12 = y7 >= 0x0600;
                    } else {
                        uint8_t a3;
                        if (y7 == 0x0800) {
                            a3 = 2;
                        } else {
                            a3 = 4;
                        }
                        a4 = a3;
                        carry12 = y7 >= 0x0800;
                    }
                    RAM8(HERO_HIT_MASK + x) = a4 | RAM8(HERO_HIT_MASK + x);
                    RAM8(0xE05A + y7) = (RAM8(0x0051) & 0x0F) | RAM8(0xE05A + y7);
                    carry13 = carry12;
                }
                a_hi10 = a_all6 >> 8;
                carry14 = carry13;
            }
            a_hi11 = a_hi10;
            carry15 = carry14;
        }
        uint8_t value30 = RAM8(0x0051);
        uint8_t value31 = RAM8(0xE05A + y7);
        uint8_t a_hi14;
        uint16_t y10;
        if ((value30 & 0xF0 & value31) != 0) {
            a_hi14 = a_hi11;
            y10 = y7;
        } else {
            uint16_t value32 = RAM16(0xE0CE + x);
            uint8_t a_hi13;
            uint16_t y9;
            if (value32 == 0) {
                a_hi13 = value32 >> 8;
                y9 = y7;
            } else {
                RAM16_SET(0x0012, value32);
                uint16_t value33 = RAM16(0xE0CC + x);
                RAM16_SET(0x0010, value33);
                r->a = value33;
                r->y = y7;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0xD267, 0xC1D42A); /* compare_two_packed_contact_hitboxes */
                uint16_t a_all7 = r->a;
                bool carry_ret7 = r->c;
                uint8_t a_hi12;
                uint16_t y8;
                if (carry_ret7) {
                    a_hi12 = a_all7 >> 8;
                    y8 = y7;
                } else {
                    r->a = (a_all7 >> 8 << 8) | 0x81;
                    r->mf = 1;
                    r->xf = 0;
                    JSR(c, 0xD270, 0xC1D285); /* record_contact_presentation_byte_and_volume */
                    uint16_t a_all8 = r->a;
                    uint16_t y_ret3 = r->y;
                    RAM8(0xE05A + y_ret3) = (RAM8(0x0051) & 0xF0) | RAM8(0xE05A + y_ret3);
                    a_hi12 = a_all8 >> 8;
                    y8 = y_ret3;
                }
                a_hi13 = a_hi12;
                y9 = y8;
            }
            a_hi14 = a_hi13;
            y10 = y9;
        }
        a_hi15 = a_hi14;
        y11 = y10;
    }
    RAM16_SET(0x0006, RAM16(0x0006) ^ 0x8080);
    r->y = y11;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1D14A, SOM_RTS, "gen", compare_native_contact_hitboxes_and_publish_collision_flags, 0, L_X | L_Y, 1, 1, 0, 315, 135)
