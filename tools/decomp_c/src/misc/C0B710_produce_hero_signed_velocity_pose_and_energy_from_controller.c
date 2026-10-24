#include "som_c.h"

/* C0B710 produce_hero_signed_velocity_pose_and_energy_from_controller   [class B, 137 bytes, 67 instructions]
 * Source: src/rom/produce_hero_signed_velocity_pose_and_energy_from_controller.s
 * Documented in docs/hero-controller-motion.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void produce_hero_signed_velocity_pose_and_energy_from_controller(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0x0010);
    uint8_t x2;
    if ((value & 3) == 0) {
        x2 = 0;
    } else {
        uint8_t x1;
        if ((value & 1) != 0) {
            x1 = 2;
        } else {
            x1 = 0x82;
        }
        x2 = x1;
    }
    uint8_t a1;
    uint8_t y2;
    if ((value & 0x0C) == 0) {
        a1 = value & 0x0C;
        y2 = 0;
    } else {
        uint8_t y1;
        if ((value & 4) != 0) {
            y1 = 2;
        } else {
            y1 = 0x82;
        }
        a1 = value & 4;
        y2 = y1;
    }
    if (!(value & 0x80)) {
        RAM8(0x0012) &= 0xCF;
    }
    uint8_t value3 = RAM8(0x0011);
    RAM8(0x0011) >>= 1;
    uint16_t x4;
    bool carry1;
    if (value3 & 0x01) {
        x4 = 0;
        carry1 = value3 & 0x01;
    } else {
        uint8_t value4 = RAM8(0x0011);
        RAM8(0x0011) >>= 1;
        uint16_t x3;
        if (value4 & 0x01) {
            x3 = 0x0200;
        } else {
            x3 = 0x0400;
        }
        x4 = x3;
        carry1 = value4 & 0x01;
    }
    RAM8(0xE067 + x4) = 0;
    uint8_t value5 = RAM8(0xE01C + x4);
    uint8_t value6 = RAM8(0xE060 + x4);
    uint8_t value7 = RAM8(0xE00A + x4);
    if ((value5 | value6 | value7) == 0) {
        uint8_t value8 = RAM8(0x0012);
        bool m_flag2;
        uint8_t a7;
        bool carry7;
        bool overflow6;
        if (!(value8 & 0x80)) {
            uint8_t value9 = RAM8(0xE01D + x4);
            uint8_t a2;
            bool carry2;
            bool overflow1;
            if (!(value9 & 0x80)) {
                a2 = value8;
                carry2 = carry1;
                overflow1 = value9 & 0x40;
            } else {
                uint8_t value10 = RAM8(ACTOR_AGILITY + x4);
                RAM8(ACTOR_WEAPON_GAUGE + x4) = ((uint8_t)(0x64 - value10) >> 1) + 0x32;
                a2 = RAM8(0x0012);
                carry2 = ((uint8_t)(0x64 - value10) >> 1) + 0x32 > 0xFF;
                overflow1 = ((((uint8_t)(0x64 - value10) >> 1) ^ ((uint8_t)(0x64 - value10) >> 1) + 0x32) & (((uint8_t)(0x64 - value10) >> 1) + 0x32 ^ 0x32) & 0x80) != 0;
            }
            RAM8(0xE01D + x4) = a2;
            RAM16_SET(0xE006 + x4, (y2 << 8) | x2);
            m_flag2 = 0;
            a7 = (uint8_t)((y2 << 8) | x2);
            carry7 = carry2;
            overflow6 = overflow1;
        } else {
            RAM8(0xE01D + x4) = value8;
            uint8_t value12 = RAM8(0xE011 + x4);
            bool m_flag;
            uint8_t a6;
            bool carry6;
            bool overflow5;
            if (value12 == 2) {
                m_flag = 1;
                a6 = value12;
                carry6 = value12 >= 2;
                overflow5 = value & 0x40;
            } else {
                RAM8(0x0012) &= 0x7F;
                uint8_t value14 = RAM8(0xE063 + x4);
                uint8_t a5;
                bool carry5;
                bool overflow4;
                if (!(value14 & 0x01)) {
                    a5 = RAM8(0x0012);
                    carry5 = value14 & 0x01;
                    overflow4 = value & 0x40;
                } else {
                    uint8_t a4;
                    bool carry4;
                    bool overflow3;
                    if (value14 & 0x01) {
                        uint8_t value16 = RAM8(ACTOR_AGILITY + x4);
                        RAM8(ACTOR_WEAPON_GAUGE + x4) = ((uint8_t)(0x64 - value16) >> 1) + 0x32;
                        a4 = RAM8(0x0012);
                        carry4 = ((uint8_t)(0x64 - value16) >> 1) + 0x32 > 0xFF;
                        overflow3 = ((((uint8_t)(0x64 - value16) >> 1) ^ ((uint8_t)(0x64 - value16) >> 1) + 0x32) & (((uint8_t)(0x64 - value16) >> 1) + 0x32 ^ 0x32) & 0x80) != 0;
                    } else {
                        uint8_t value18 = RAM8(0xE01D + x4);
                        uint8_t a3;
                        bool carry3;
                        bool overflow2;
                        if (!(value18 & 0x80)) {
                            a3 = value14 >> 1;
                            carry3 = value14 & 0x01;
                            overflow2 = value18 & 0x40;
                        } else {
                            uint8_t value19 = RAM8(ACTOR_AGILITY + x4);
                            RAM8(ACTOR_WEAPON_GAUGE + x4) = ((uint8_t)(0x64 - value19) >> 1) + 0x32;
                            a3 = RAM8(0x0012);
                            carry3 = ((uint8_t)(0x64 - value19) >> 1) + 0x32 > 0xFF;
                            overflow2 = ((((uint8_t)(0x64 - value19) >> 1) ^ ((uint8_t)(0x64 - value19) >> 1) + 0x32) & (((uint8_t)(0x64 - value19) >> 1) + 0x32 ^ 0x32) & 0x80) != 0;
                        }
                        a4 = a3;
                        carry4 = carry3;
                        overflow3 = overflow2;
                    }
                    a5 = a4;
                    carry5 = carry4;
                    overflow4 = overflow3;
                }
                RAM8(0xE01D + x4) = a5;
                RAM16_SET(0xE006 + x4, (y2 << 8) | x2);
                m_flag = 0;
                a6 = (uint8_t)((y2 << 8) | x2);
                carry6 = carry5;
                overflow5 = overflow4;
            }
            m_flag2 = m_flag;
            a7 = a6;
            carry7 = carry6;
            overflow6 = overflow5;
        }
        r->a = (y2 << 8) | a7;
        r->x = x4;
        r->y = (y2 << 8) | x2;
        r->c = carry7;
        r->v = overflow6;
        r->mf = m_flag2;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = (y2 << 8) | (value5 | value6 | value7);
    r->x = x4;
    r->y = (y2 << 8) | x2;
    r->c = carry1;
    r->v = value & 0x40;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0B710, SOM_RTS, "gen", produce_hero_signed_velocity_pose_and_energy_from_controller, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 137, 67)
