#include "som_c.h"

/* C0D890 publish_actor_wrapped_position_layer_and_camera_step   [class C, 210 bytes, 98 instructions]
 * Source: src/rom/publish_actor_wrapped_position_layer_and_camera_step.s
 * Documented in docs/map-motion-shared.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void publish_actor_wrapped_position_layer_and_camera_step(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    if (x < 0x0600) {
        if ((RAM8(0x001B) & 8) != 0) {
            if (RAM8(0xE02C + x) == 0) {
                uint16_t value3 = RAM16(0x00BA);
                RAM8(0x001B) <<= 1;
                RAM8(0x001B) = (RAM8(0x001B) >> 1) | (RAM8(0xE00B + value3) >> 7 << 7);
            }
        }
    }
    RAM8(0xE00B + x) = RAM8(0x001B);
    uint8_t value8 = RAM8(0x0004);
    uint8_t value9 = RAM8(0xE04D + x);
    if (value8 != value9) {
        RAM8(0xE04D + x) = value8;
        RAM8(0xE048 + x) = value8;
        RAM8(0xE049 + x) = RAM8(0x0005);
    }
    uint8_t value11 = RAM8(0x001E);
    RAM8(0x0084) = value11;
    bool m_flag7;
    uint8_t a_hi6;
    bool carry5;
    bool overflow5;
    if (value11 == 0) {
        m_flag7 = 1;
        a_hi6 = a_hi;
        carry5 = value8 >= value9;
        overflow5 = overflow;
    } else {
        uint8_t a3;
        uint8_t a_hi3;
        bool overflow3;
        if (value11 & 0x80) {
            uint16_t value12 = RAM16(0xE002 + x);
            uint8_t a1;
            uint8_t a_hi1;
            bool overflow1;
            if (!((uint16_t)(((((a_hi << 8) | value11) & 0x7F) ^ 0xFFFF) + value12 + 1) & 0x8000)) {
                a1 = (uint8_t)(((((a_hi << 8) | value11) & 0x7F) ^ 0xFFFF) + value12 + 1);
                a_hi1 = (uint16_t)(((((a_hi << 8) | value11) & 0x7F) ^ 0xFFFF) + value12 + 1) >> 8;
                overflow1 = (((((a_hi << 8) | value11) & 0x7F) ^ 0xFFFF ^ (uint16_t)(((((a_hi << 8) | value11) & 0x7F) ^ 0xFFFF) + value12 + 1)) & (value12 ^ (uint16_t)(((((a_hi << 8) | value11) & 0x7F) ^ 0xFFFF) + value12 + 1)) & 0x8000) != 0;
            } else {
                uint16_t value13 = RAM16(0x00C0);
                a1 = (uint8_t)((uint16_t)(((((a_hi << 8) | value11) & 0x7F) ^ 0xFFFF) + value12 + 1) + value13);
                a_hi1 = (uint16_t)((uint16_t)(((((a_hi << 8) | value11) & 0x7F) ^ 0xFFFF) + value12 + 1) + value13) >> 8;
                overflow1 = (((uint16_t)(((((a_hi << 8) | value11) & 0x7F) ^ 0xFFFF) + value12 + 1) ^ (uint16_t)((uint16_t)(((((a_hi << 8) | value11) & 0x7F) ^ 0xFFFF) + value12 + 1) + value13)) & (value13 ^ (uint16_t)((uint16_t)(((((a_hi << 8) | value11) & 0x7F) ^ 0xFFFF) + value12 + 1) + value13)) & 0x8000) != 0;
            }
            a3 = a1;
            a_hi3 = a_hi1;
            overflow3 = overflow1;
        } else {
            uint16_t value14 = RAM16(0xE002 + x);
            uint16_t value15 = RAM16(0x00C0);
            uint8_t a2;
            uint8_t a_hi2;
            bool overflow2;
            if ((uint16_t)((((a_hi << 8) | value11) & 0x7F) + value14) < value15) {
                a2 = (uint8_t)((((a_hi << 8) | value11) & 0x7F) + value14);
                a_hi2 = (uint16_t)((((a_hi << 8) | value11) & 0x7F) + value14) >> 8;
                overflow2 = (((((a_hi << 8) | value11) & 0x7F) ^ (uint16_t)((((a_hi << 8) | value11) & 0x7F) + value14)) & (value14 ^ (uint16_t)((((a_hi << 8) | value11) & 0x7F) + value14)) & 0x8000) != 0;
            } else {
                a2 = (uint8_t)((uint16_t)((((a_hi << 8) | value11) & 0x7F) + value14) - value15 - ((uint16_t)((((a_hi << 8) | value11) & 0x7F) + value14) >= value15 ^ 1));
                a_hi2 = (uint16_t)((uint16_t)((((a_hi << 8) | value11) & 0x7F) + value14) - value15 - ((uint16_t)((((a_hi << 8) | value11) & 0x7F) + value14) >= value15 ^ 1)) >> 8;
                overflow2 = (((uint16_t)((((a_hi << 8) | value11) & 0x7F) + value14) ^ value15) & ((uint16_t)((((a_hi << 8) | value11) & 0x7F) + value14) ^ (uint16_t)((uint16_t)((((a_hi << 8) | value11) & 0x7F) + value14) - value15 - ((uint16_t)((((a_hi << 8) | value11) & 0x7F) + value14) >= value15 ^ 1))) & 0x8000) != 0;
            }
            a3 = a2;
            a_hi3 = a_hi2;
            overflow3 = overflow2;
        }
        RAM16_SET(0xE002 + x, (a_hi3 << 8) | a3);
        bool m_flag6;
        uint8_t a_hi5;
        bool carry4;
        bool overflow4;
        if (x >= 0x0600) {
            RAM8(0x0084) = 0;
            m_flag6 = 1;
            a_hi5 = a_hi3;
            carry4 = x >= 0x0600;
            overflow4 = overflow3;
        } else {
            uint16_t value16 = RAM16(0x0016);
            uint8_t a4;
            uint8_t a_hi4;
            if (((a_hi3 << 8) | a3) >= value16) {
                a4 = (uint8_t)(((a_hi3 << 8) | a3) - value16);
                a_hi4 = (uint16_t)(((a_hi3 << 8) | a3) - value16) >> 8;
            } else {
                uint16_t value17 = RAM16(0x00C0);
                a4 = (uint8_t)((uint16_t)(((a_hi3 << 8) | a3) - value16) + value17 + (((a_hi3 << 8) | a3) >= value16));
                a_hi4 = (uint16_t)((uint16_t)(((a_hi3 << 8) | a3) - value16) + value17 + (((a_hi3 << 8) | a3) >= value16)) >> 8;
            }
            uint16_t value18 = RAM16(0x001D);
            bool m_flag5;
            bool carry3;
            if (!(value18 & 0x8000)) {
                bool m_flag;
                if (((a_hi4 << 8) | a4) >= 0xC8) {
                    m_flag = 0;
                } else {
                    RAM8(0x0084) = 0;
                    m_flag = 1;
                }
                m_flag5 = m_flag;
                carry3 = ((a_hi4 << 8) | a4) >= 0xC8;
            } else {
                bool m_flag4;
                bool carry2;
                if (((a_hi4 << 8) | a4) >= 0x38) {
                    RAM8(0x0084) = 0;
                    m_flag4 = 1;
                    carry2 = ((a_hi4 << 8) | a4) >= 0x38;
                } else {
                    bool m_flag3;
                    bool carry1;
                    if (((a_hi4 << 8) | a4) < 0x38) {
                        m_flag3 = 0;
                        carry1 = ((a_hi4 << 8) | a4) >= 0x38;
                    } else {
                        bool m_flag2;
                        if (((a_hi4 << 8) | a4) >= 0xC8) {
                            m_flag2 = 0;
                        } else {
                            RAM8(0x0084) = 0;
                            m_flag2 = 1;
                        }
                        m_flag3 = m_flag2;
                        carry1 = ((a_hi4 << 8) | a4) >= 0xC8;
                    }
                    m_flag4 = m_flag3;
                    carry2 = carry1;
                }
                m_flag5 = m_flag4;
                carry3 = carry2;
            }
            m_flag6 = m_flag5;
            a_hi5 = a_hi4;
            carry4 = carry3;
            overflow4 = value18 & 0x4000;
        }
        m_flag7 = m_flag6;
        a_hi6 = a_hi5;
        carry5 = carry4;
        overflow5 = overflow4;
    }
    uint8_t value19 = RAM8(0x001F);
    RAM8(0x0086) = value19;
    bool m_flag14;
    uint8_t a10;
    uint8_t a_hi12;
    bool carry10;
    bool overflow10;
    if (value19 == 0) {
        m_flag14 = 1;
        a10 = value19;
        a_hi12 = a_hi6;
        carry10 = carry5;
        overflow10 = overflow5;
    } else {
        uint8_t a7;
        uint8_t a_hi9;
        bool overflow8;
        if (value19 & 0x80) {
            uint16_t value20 = RAM16(0xE004 + x);
            uint8_t a5;
            uint8_t a_hi7;
            bool overflow6;
            if (!((uint16_t)(((((a_hi6 << 8) | value19) & 0x7F) ^ 0xFFFF) + value20 + 1) & 0x8000)) {
                a5 = (uint8_t)(((((a_hi6 << 8) | value19) & 0x7F) ^ 0xFFFF) + value20 + 1);
                a_hi7 = (uint16_t)(((((a_hi6 << 8) | value19) & 0x7F) ^ 0xFFFF) + value20 + 1) >> 8;
                overflow6 = (((((a_hi6 << 8) | value19) & 0x7F) ^ 0xFFFF ^ (uint16_t)(((((a_hi6 << 8) | value19) & 0x7F) ^ 0xFFFF) + value20 + 1)) & (value20 ^ (uint16_t)(((((a_hi6 << 8) | value19) & 0x7F) ^ 0xFFFF) + value20 + 1)) & 0x8000) != 0;
            } else {
                uint16_t value21 = RAM16(0x00C2);
                a5 = (uint8_t)((uint16_t)(((((a_hi6 << 8) | value19) & 0x7F) ^ 0xFFFF) + value20 + 1) + value21);
                a_hi7 = (uint16_t)((uint16_t)(((((a_hi6 << 8) | value19) & 0x7F) ^ 0xFFFF) + value20 + 1) + value21) >> 8;
                overflow6 = (((uint16_t)(((((a_hi6 << 8) | value19) & 0x7F) ^ 0xFFFF) + value20 + 1) ^ (uint16_t)((uint16_t)(((((a_hi6 << 8) | value19) & 0x7F) ^ 0xFFFF) + value20 + 1) + value21)) & (value21 ^ (uint16_t)((uint16_t)(((((a_hi6 << 8) | value19) & 0x7F) ^ 0xFFFF) + value20 + 1) + value21)) & 0x8000) != 0;
            }
            a7 = a5;
            a_hi9 = a_hi7;
            overflow8 = overflow6;
        } else {
            uint16_t value22 = RAM16(0xE004 + x);
            uint16_t value23 = RAM16(0x00C2);
            uint8_t a6;
            uint8_t a_hi8;
            bool overflow7;
            if ((uint16_t)((((a_hi6 << 8) | value19) & 0x7F) + value22) < value23) {
                a6 = (uint8_t)((((a_hi6 << 8) | value19) & 0x7F) + value22);
                a_hi8 = (uint16_t)((((a_hi6 << 8) | value19) & 0x7F) + value22) >> 8;
                overflow7 = (((((a_hi6 << 8) | value19) & 0x7F) ^ (uint16_t)((((a_hi6 << 8) | value19) & 0x7F) + value22)) & (value22 ^ (uint16_t)((((a_hi6 << 8) | value19) & 0x7F) + value22)) & 0x8000) != 0;
            } else {
                a6 = (uint8_t)((uint16_t)((((a_hi6 << 8) | value19) & 0x7F) + value22) - value23 - ((uint16_t)((((a_hi6 << 8) | value19) & 0x7F) + value22) >= value23 ^ 1));
                a_hi8 = (uint16_t)((uint16_t)((((a_hi6 << 8) | value19) & 0x7F) + value22) - value23 - ((uint16_t)((((a_hi6 << 8) | value19) & 0x7F) + value22) >= value23 ^ 1)) >> 8;
                overflow7 = (((uint16_t)((((a_hi6 << 8) | value19) & 0x7F) + value22) ^ value23) & ((uint16_t)((((a_hi6 << 8) | value19) & 0x7F) + value22) ^ (uint16_t)((uint16_t)((((a_hi6 << 8) | value19) & 0x7F) + value22) - value23 - ((uint16_t)((((a_hi6 << 8) | value19) & 0x7F) + value22) >= value23 ^ 1))) & 0x8000) != 0;
            }
            a7 = a6;
            a_hi9 = a_hi8;
            overflow8 = overflow7;
        }
        RAM16_SET(0xE004 + x, (a_hi9 << 8) | a7);
        bool m_flag13;
        uint8_t a9;
        uint8_t a_hi11;
        bool carry9;
        bool overflow9;
        if (x >= 0x0600) {
            m_flag13 = 0;
            a9 = a7;
            a_hi11 = a_hi9;
            carry9 = x >= 0x0600;
            overflow9 = overflow8;
        } else {
            uint16_t value24 = RAM16(0x0018);
            uint8_t a8;
            uint8_t a_hi10;
            if (((a_hi9 << 8) | a7) >= value24) {
                a8 = (uint8_t)(((a_hi9 << 8) | a7) - value24);
                a_hi10 = (uint16_t)(((a_hi9 << 8) | a7) - value24) >> 8;
            } else {
                uint16_t value25 = RAM16(0x00C2);
                a8 = (uint8_t)((uint16_t)(((a_hi9 << 8) | a7) - value24) + value25 + (((a_hi9 << 8) | a7) >= value24));
                a_hi10 = (uint16_t)((uint16_t)(((a_hi9 << 8) | a7) - value24) + value25 + (((a_hi9 << 8) | a7) >= value24)) >> 8;
            }
            uint16_t value26 = RAM16(0x001E);
            bool m_flag12;
            bool carry8;
            if (!(value26 & 0x8000)) {
                bool m_flag8;
                if (((a_hi10 << 8) | a8) >= 0xB0) {
                    m_flag8 = 0;
                } else {
                    RAM8(0x0086) = 0;
                    m_flag8 = 1;
                }
                m_flag12 = m_flag8;
                carry8 = ((a_hi10 << 8) | a8) >= 0xB0;
            } else {
                bool m_flag11;
                bool carry7;
                if (((a_hi10 << 8) | a8) >= 0x48) {
                    RAM8(0x0086) = 0;
                    m_flag11 = 1;
                    carry7 = ((a_hi10 << 8) | a8) >= 0x48;
                } else {
                    bool m_flag10;
                    bool carry6;
                    if (((a_hi10 << 8) | a8) < 0x48) {
                        m_flag10 = 0;
                        carry6 = ((a_hi10 << 8) | a8) >= 0x48;
                    } else {
                        bool m_flag9;
                        if (((a_hi10 << 8) | a8) >= 0xB0) {
                            m_flag9 = 0;
                        } else {
                            RAM8(0x0086) = 0;
                            m_flag9 = 1;
                        }
                        m_flag10 = m_flag9;
                        carry6 = ((a_hi10 << 8) | a8) >= 0xB0;
                    }
                    m_flag11 = m_flag10;
                    carry7 = carry6;
                }
                m_flag12 = m_flag11;
                carry8 = carry7;
            }
            m_flag13 = m_flag12;
            a9 = a8;
            a_hi11 = a_hi10;
            carry9 = carry8;
            overflow9 = value26 & 0x4000;
        }
        m_flag14 = m_flag13;
        a10 = a9;
        a_hi12 = a_hi11;
        carry10 = carry9;
        overflow10 = overflow9;
    }
    r->a = (a_hi12 << 8) | a10;
    r->c = carry10;
    r->v = overflow10;
    r->mf = m_flag14;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0D890, SOM_RTS, "gen", publish_actor_wrapped_position_layer_and_camera_step, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 210, 98)
