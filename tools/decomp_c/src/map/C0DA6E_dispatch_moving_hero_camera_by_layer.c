#include "som_c.h"

/* C0DA6E dispatch_moving_hero_camera_by_layer   [class C, 125 bytes, 57 instructions]
 * Source: src/rom/dispatch_moving_hero_camera_by_layer.s
 * Documented in docs/map-hero-motion.md
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void dispatch_moving_hero_camera_by_layer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->mf = 1; /* sep #$30 */
    r->xf = 1;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x00FF);
    if (value == 0) {
        uint8_t value2 = RAM8(0x010E);
        uint8_t value3 = RAM8(0x010F);
        if ((value2 | value3) == 0) {
            SET_A8(r, value2 | value3);
            r->x = (uint8_t)x;
            r->y = (uint8_t)y;
            r->z = (value2 | value3) == 0;
            r->n = (value2 | value3) & 0x80;
            r->mf = 1;
            r->xf = 1;
            RETURN_RTS(c);
        }
        if (RAM8(0x001B) & 0x80) {
            uint8_t value5 = RAM8(0x0084);
            uint8_t a_hi1;
            bool carry1;
            bool overflow1;
            if (value5 == 0) {
                a_hi1 = a >> 8;
                carry1 = carry;
                overflow1 = overflow;
            } else {
                r->a = (a >> 8 << 8) | value5;
                r->x = (uint8_t)x;
                r->y = (uint8_t)y;
                r->mf = 1;
                r->xf = 1;
                JSR(c, 0xDABC, 0xC0DC56); /* move_secondary_camera_horizontal */
                r->mf = 1;
                r->xf = 1;
                r->x &= 0xFF;
                r->y &= 0xFF;
                uint16_t a_all = r->a;
                bool carry_ret = r->c;
                bool overflow_ret = r->v;
                a_hi1 = a_all >> 8;
                carry1 = carry_ret;
                overflow1 = overflow_ret;
            }
            uint8_t value6 = RAM8(0x0086);
            uint8_t a_hi2;
            bool carry2;
            bool overflow2;
            if (value6 == 0) {
                a_hi2 = a_hi1;
                carry2 = carry1;
                overflow2 = overflow1;
            } else {
                r->a = (a_hi1 << 8) | value6;
                r->x = (uint8_t)x;
                r->y = (uint8_t)y;
                r->c = carry1;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 1;
                JSR(c, 0xDAC5, 0xC0DC99); /* move_secondary_camera_vertical */
                r->mf = 1;
                r->xf = 1;
                r->x &= 0xFF;
                r->y &= 0xFF;
                uint16_t a_all2 = r->a;
                bool carry_ret2 = r->c;
                bool overflow_ret2 = r->v;
                a_hi2 = a_all2 >> 8;
                carry2 = carry_ret2;
                overflow2 = overflow_ret2;
            }
            uint8_t value7 = RAM8(0x0084);
            uint8_t a_hi4;
            uint8_t x1;
            bool carry4;
            bool overflow4;
            if (value7 == 0) {
                a_hi4 = a_hi2;
                x1 = (uint8_t)x;
                carry4 = carry2;
                overflow4 = overflow2;
            } else {
                r->a = (a_hi2 << 8) | value7;
                r->x = 0;
                r->y = (uint8_t)y;
                r->v = overflow2;
                r->mf = 1;
                r->xf = 1;
                JSR(c, 0xDAD0, 0xC0DAEB); /* scale_camera_motion_for_layer */
                uint16_t a_all3 = r->a;
                bool carry_ret3 = r->c;
                uint8_t a_hi3;
                bool carry3;
                bool overflow3;
                if (carry_ret3) {
                    a_hi3 = a_all3 >> 8;
                    carry3 = carry_ret3;
                    overflow3 = overflow2;
                } else {
                    RAM8(0x0084) = (uint8_t)a_all3;
                    r->mf = 1;
                    r->xf = 1;
                    JSR(c, 0xDAD7, 0xC0DBDA); /* move_primary_camera_horizontal */
                    r->mf = 1;
                    r->xf = 1;
                    r->x &= 0xFF;
                    r->y &= 0xFF;
                    uint16_t a_all4 = r->a;
                    bool carry_ret4 = r->c;
                    bool overflow_ret3 = r->v;
                    a_hi3 = a_all4 >> 8;
                    carry3 = carry_ret4;
                    overflow3 = overflow_ret3;
                }
                a_hi4 = a_hi3;
                x1 = 0;
                carry4 = carry3;
                overflow4 = overflow3;
            }
            uint8_t value8 = RAM8(0x0086);
            bool m_flag2;
            uint8_t a2;
            uint8_t a_hi6;
            uint8_t x2;
            bool carry6;
            bool zero2;
            bool negative2;
            bool overflow6;
            if (value8 == 0) {
                m_flag2 = 1;
                a2 = value8;
                a_hi6 = a_hi4;
                x2 = x1;
                carry6 = carry4;
                zero2 = value8 == 0;
                negative2 = value8 & 0x80;
                overflow6 = overflow4;
            } else {
                r->a = (a_hi4 << 8) | value8;
                r->x = 0x10;
                r->y = (uint8_t)y;
                r->v = overflow4;
                r->mf = 1;
                r->xf = 1;
                JSR(c, 0xDAE2, 0xC0DAEB); /* scale_camera_motion_for_layer */
                uint16_t a_all5 = r->a;
                bool carry_ret5 = r->c;
                bool zero_ret5 = r->z;
                bool negative_ret5 = r->n;
                bool m_flag;
                uint8_t a1;
                uint8_t a_hi5;
                bool carry5;
                bool zero1;
                bool negative1;
                bool overflow5;
                if (carry_ret5) {
                    m_flag = 1;
                    a1 = (uint8_t)a_all5;
                    a_hi5 = a_all5 >> 8;
                    carry5 = carry_ret5;
                    zero1 = zero_ret5;
                    negative1 = negative_ret5;
                    overflow5 = overflow4;
                } else {
                    RAM8(0x0086) = (uint8_t)a_all5;
                    r->mf = 1;
                    r->xf = 1;
                    JSR(c, 0xDAE9, 0xC0DC18); /* move_primary_camera_vertical */
                    uint16_t a_all6 = r->a;
                    bool carry_ret6 = r->c;
                    bool zero_ret6 = r->z;
                    bool negative_ret6 = r->n;
                    bool overflow_ret4 = r->v;
                    m_flag = 0;
                    a1 = (uint8_t)a_all6;
                    a_hi5 = a_all6 >> 8;
                    carry5 = carry_ret6;
                    zero1 = zero_ret6;
                    negative1 = negative_ret6;
                    overflow5 = overflow_ret4;
                }
                m_flag2 = m_flag;
                a2 = a1;
                a_hi6 = a_hi5;
                x2 = 0x10;
                carry6 = carry5;
                zero2 = zero1;
                negative2 = negative1;
                overflow6 = overflow5;
            }
            r->a = (a_hi6 << 8) | a2;
            r->x = x2;
            r->y = (uint8_t)y;
            r->c = carry6;
            r->z = zero2;
            r->n = negative2;
            r->v = overflow6;
            r->xf = 1;
            RETURN_RTS(c);
        }
        uint8_t value9 = RAM8(0x0084);
        bool m_flag3;
        uint8_t a_hi7;
        bool carry7;
        bool overflow7;
        if (value9 == 0) {
            m_flag3 = 1;
            a_hi7 = a >> 8;
            carry7 = carry;
            overflow7 = overflow;
        } else {
            r->a = (a >> 8 << 8) | value9;
            r->x = (uint8_t)x;
            r->y = (uint8_t)y;
            r->mf = 1;
            r->xf = 1;
            JSR(c, 0xDA87, 0xC0DBDA); /* move_primary_camera_horizontal */
            r->mf = 1;
            r->xf = 1;
            r->x &= 0xFF;
            r->y &= 0xFF;
            uint16_t a_all7 = r->a;
            bool carry_ret7 = r->c;
            bool overflow_ret5 = r->v;
            m_flag3 = 0;
            a_hi7 = a_all7 >> 8;
            carry7 = carry_ret7;
            overflow7 = overflow_ret5;
        }
        uint8_t value10 = RAM8(0x0086);
        bool m_flag4;
        uint8_t a_hi8;
        bool carry8;
        bool overflow8;
        if (value10 == 0) {
            m_flag4 = 1;
            a_hi8 = a_hi7;
            carry8 = carry7;
            overflow8 = overflow7;
        } else {
            r->a = (a_hi7 << 8) | value10;
            r->x = (uint8_t)x;
            r->y = (uint8_t)y;
            r->mf = 1;
            r->xf = 1;
            JSR(c, 0xDA90, 0xC0DC18); /* move_primary_camera_vertical */
            r->mf = 1;
            r->xf = 1;
            r->x &= 0xFF;
            r->y &= 0xFF;
            uint16_t a_all8 = r->a;
            bool carry_ret8 = r->c;
            bool overflow_ret6 = r->v;
            m_flag4 = 0;
            a_hi8 = a_all8 >> 8;
            carry8 = carry_ret8;
            overflow8 = overflow_ret6;
        }
        uint8_t value11 = RAM8(0x0084);
        uint8_t a_hi10;
        uint8_t x3;
        bool carry10;
        bool overflow10;
        if (value11 == 0) {
            a_hi10 = a_hi8;
            x3 = (uint8_t)x;
            carry10 = carry8;
            overflow10 = overflow8;
        } else {
            r->a = (a_hi8 << 8) | value11;
            r->x = 0x20;
            r->y = (uint8_t)y;
            r->v = overflow8;
            r->mf = 1;
            r->xf = 1;
            JSR(c, 0xDA9B, 0xC0DAEB); /* scale_camera_motion_for_layer */
            uint16_t a_all9 = r->a;
            bool carry_ret9 = r->c;
            uint8_t a_hi9;
            bool carry9;
            bool overflow9;
            if (carry_ret9) {
                a_hi9 = a_all9 >> 8;
                carry9 = carry_ret9;
                overflow9 = overflow8;
            } else {
                RAM8(0x0084) = (uint8_t)a_all9;
                r->mf = 1;
                r->xf = 1;
                JSR(c, 0xDAA2, 0xC0DC56); /* move_secondary_camera_horizontal */
                r->mf = 1;
                r->xf = 1;
                r->x &= 0xFF;
                r->y &= 0xFF;
                uint16_t a_all10 = r->a;
                bool carry_ret10 = r->c;
                bool overflow_ret7 = r->v;
                a_hi9 = a_all10 >> 8;
                carry9 = carry_ret10;
                overflow9 = overflow_ret7;
            }
            a_hi10 = a_hi9;
            x3 = 0x20;
            carry10 = carry9;
            overflow10 = overflow9;
        }
        uint8_t value12 = RAM8(0x0086);
        uint8_t a4;
        uint8_t a_hi12;
        uint8_t x4;
        bool carry12;
        bool zero4;
        bool negative4;
        bool overflow12;
        if (value12 == 0) {
            a4 = value12;
            a_hi12 = a_hi10;
            x4 = x3;
            carry12 = carry10;
            zero4 = value12 == 0;
            negative4 = value12 & 0x80;
            overflow12 = overflow10;
        } else {
            r->a = (a_hi10 << 8) | value12;
            r->x = 0x30;
            r->y = (uint8_t)y;
            r->v = overflow10;
            r->mf = 1;
            r->xf = 1;
            JSR(c, 0xDAAD, 0xC0DAEB); /* scale_camera_motion_for_layer */
            uint16_t a_all11 = r->a;
            bool carry_ret11 = r->c;
            bool zero_ret11 = r->z;
            bool negative_ret11 = r->n;
            uint8_t a3;
            uint8_t a_hi11;
            bool carry11;
            bool zero3;
            bool negative3;
            bool overflow11;
            if (carry_ret11) {
                a3 = (uint8_t)a_all11;
                a_hi11 = a_all11 >> 8;
                carry11 = carry_ret11;
                zero3 = zero_ret11;
                negative3 = negative_ret11;
                overflow11 = overflow10;
            } else {
                RAM8(0x0086) = (uint8_t)a_all11;
                r->mf = 1;
                r->xf = 1;
                JSR(c, 0xDAB4, 0xC0DC99); /* move_secondary_camera_vertical */
                uint16_t a_all12 = r->a;
                bool carry_ret12 = r->c;
                bool zero_ret12 = r->z;
                bool negative_ret12 = r->n;
                bool overflow_ret8 = r->v;
                a3 = (uint8_t)a_all12;
                a_hi11 = a_all12 >> 8;
                carry11 = carry_ret12;
                zero3 = zero_ret12;
                negative3 = negative_ret12;
                overflow11 = overflow_ret8;
            }
            a4 = a3;
            a_hi12 = a_hi11;
            x4 = 0x30;
            carry12 = carry11;
            zero4 = zero3;
            negative4 = negative3;
            overflow12 = overflow11;
        }
        r->a = (a_hi12 << 8) | a4;
        r->x = x4;
        r->y = (uint8_t)y;
        r->c = carry12;
        r->z = zero4;
        r->n = negative4;
        r->v = overflow12;
        RETURN_RTS(c);
    }
    SET_A8(r, value);
    r->x = (uint8_t)x;
    r->y = (uint8_t)y;
    r->z = value == 0;
    r->n = value & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DA6E, SOM_RTS, "hand", dispatch_moving_hero_camera_by_layer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, 0, 125, 57)
