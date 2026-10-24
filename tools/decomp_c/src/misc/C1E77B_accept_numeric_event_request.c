#include "som_c.h"

/* C1E77B accept_numeric_event_request   [class C, 396 bytes, 186 instructions]
 * Source: src/rom/accept_numeric_event_request.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=any X=any DB=$7E D=any.  Callers read: ABXYCV.
 */
static void accept_numeric_event_request(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    if (a >= 0x0800) {
        bool m_flag4;
        uint8_t a5;
        uint8_t a_hi5;
        uint16_t y5;
        bool carry6;
        bool overflow4;
        if (a >= 0x0C00) {
            bool m_flag3;
            uint8_t a4;
            uint8_t a_hi4;
            uint16_t y4;
            bool carry5;
            bool overflow3;
            if (a >= 0x0D00) {
                bool m_flag2;
                uint8_t a2;
                uint8_t a_hi2;
                uint16_t y2;
                bool carry3;
                bool overflow1;
                if (a >= 0x0D80) {
                    bool carry1;
                    if (a >= 0x0E00) {
                        carry1 = a >= 0x0F00;
                    } else {
                        carry1 = a >= 0x0E00;
                    }
                    m_flag2 = 0;
                    a2 = (uint8_t)a;
                    a_hi2 = a >> 8;
                    y2 = y;
                    carry3 = carry1;
                    overflow1 = overflow;
                } else {
                    uint16_t value = RAM16(0x00FE + dp);
                    bool m_flag;
                    uint8_t a1;
                    uint8_t a_hi1;
                    uint16_t y1;
                    bool carry2;
                    if (value & 0x8000) {
                        m_flag = 0;
                        a1 = (uint8_t)a;
                        a_hi1 = a >> 8;
                        y1 = y;
                        carry2 = a >= 0x0D80;
                    } else {
                        uint16_t value2 = BUS16(c, 0xC67C80 + ((a & 0x7F) << 1 << 1));
                        RAM16_SET(0x0000 + dp, value2);
                        RAM16_SET(0x00FA + dp, (value2 & 0xFF) << 1 << 1 << 1 << 1);
                        uint16_t value3 = RAM16(0x0001 + dp);
                        RAM16_SET(0x00FC + dp, (value3 & 0xFF) << 1 << 1 << 1 << 1);
                        uint16_t value4 = BUS16(c, 0xC67C82 + ((a & 0x7F) << 1 << 1));
                        RAM16_SET(0x0110, value4);
                        r->a = value4;
                        r->x = (a & 0x7F) << 1 << 1;
                        r->c = (value3 & 0xFF) << 1 << 1 << 1 & 0x8000;
                        r->v = value & 0x4000;
                        r->mf = 0;
                        r->xf = 0;
                        r->sp -= 2;
                        JSL(c, 0xE86D, 0xC0BC01); /* request_destination_fade */
                        r->sp += 2;
                        uint16_t a_all = r->a;
                        uint16_t y_ret = r->y;
                        m_flag = 1;
                        a1 = (uint8_t)a_all;
                        a_hi1 = a_all >> 8;
                        y1 = y_ret;
                        carry2 = (value3 & 0xFF) << 1 << 1 << 1 & 0x8000;
                    }
                    m_flag2 = m_flag;
                    a2 = a1;
                    a_hi2 = a_hi1;
                    y2 = y1;
                    carry3 = carry2;
                    overflow1 = value & 0x4000;
                }
                m_flag3 = m_flag2;
                a4 = a2;
                a_hi4 = a_hi2;
                y4 = y2;
                carry5 = carry3;
                overflow3 = overflow1;
            } else {
                uint16_t value5 = RAM16(0x00FE + dp);
                uint8_t a3;
                uint8_t a_hi3;
                uint16_t y3;
                bool carry4;
                bool overflow2;
                if (value5 & 0x8000) {
                    a3 = (uint8_t)a;
                    a_hi3 = a >> 8;
                    y3 = y;
                    carry4 = a >= 0x0D00;
                    overflow2 = value5 & 0x4000;
                } else {
                    uint16_t value6 = BUS16(c, 0xC67A80 + ((a & 0xFF) << 1));
                    RAM16_SET(0x0000 + dp, value6);
                    RAM16_SET(0x00FA + dp, (value6 & 0xFF) << 1 << 1 << 1 << 1);
                    uint16_t value7 = RAM16(0x0001 + dp);
                    RAM16_SET(0x00FC + dp, (value7 & 0xFF) << 1 << 1 << 1 << 1);
                    RAM16_SET(0x00F6 + dp, 0);
                    RAM8(0x00E8 + dp) = 4;
                    r->a = ((value7 & 0xFF) << 1 << 1 << 1 << 1 >> 8 << 8) | 4;
                    r->c = (value7 & 0xFF) << 1 << 1 << 1 & 0x8000;
                    r->v = value5 & 0x4000;
                    r->mf = 1;
                    r->xf = 0;
                    r->sp -= 2;
                    JSL(c, 0xE836, 0xC1CBCB); /* snapshot_map_state_entry */
                    r->sp += 2;
                    uint16_t a_all2 = r->a;
                    uint16_t y_ret2 = r->y;
                    bool carry_ret = r->c;
                    bool overflow_ret = r->v;
                    a3 = (uint8_t)a_all2;
                    a_hi3 = a_all2 >> 8;
                    y3 = y_ret2;
                    carry4 = carry_ret;
                    overflow2 = overflow_ret;
                }
                m_flag3 = 0;
                a4 = a3;
                a_hi4 = a_hi3;
                y4 = y3;
                carry5 = carry4;
                overflow3 = overflow2;
            }
            m_flag4 = m_flag3;
            a5 = a4;
            a_hi5 = a_hi4;
            y5 = y4;
            carry6 = carry5;
            overflow4 = overflow3;
        } else {
            r->mf = 0;
            r->xf = 0;
            r->sp -= 4;
            JSL(c, 0xE7D2, 0xC1CBCF); /* snapshot_map_state_and_backup */
            r->sp += 4;
            uint16_t y_ret3 = r->y;
            bool overflow_ret2 = r->v;
            RAM16_SET(0x010E, a & 0x03FF);
            uint16_t value8 = BUS16(c, 0xC83000 + ((a & 0x03FF) << 1 << 1));
            RAM16_SET(0x00DC + dp, value8 & 0x01FF);
            uint16_t value9 = BUS16(c, 0xC83001 + ((a & 0x03FF) << 1 << 1));
            RAM16_SET(0x00DE + dp, (value9 & 0xFF) >> 1);
            uint16_t value10 = BUS16(c, 0xC83002 + ((a & 0x03FF) << 1 << 1));
            RAM16_SET(0x00DF + dp, value10);
            RAM8(0x00FF + dp) = 0x40;
            RAM8(0x00E8 + dp) = 0;
            m_flag4 = 1;
            a5 = 0x40;
            a_hi5 = value10 >> 8;
            y5 = y_ret3;
            carry6 = value9 & 0xFF & 0x01;
            overflow4 = overflow_ret2;
        }
        RAM8(0x00CC + dp) = 0;
        RAM8(0x00CD + dp) = 0;
        RAM8(0x00CE + dp) = 0;
        r->a = (a_hi5 << 8) | a5;
        r->x = x;
        r->y = y5;
        r->c = carry6;
        r->v = overflow4;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0000 + dp, a);
    uint16_t value11 = RAM16(0x00D0 + dp);
    if ((value11 & 0xFF) == 0) {
        uint16_t value12 = RAM16(0x0000 + dp);
        uint8_t a6;
        uint8_t a_hi6;
        if (value12 >= 0x0400) {
            uint16_t value13 = BUS16(c, 0xCA0000 + ((value12 & 0x03FF) << 1));
            RAM16_SET(0x00D1 + dp, value13);
            a6 = 0xCA;
            a_hi6 = value13 >> 8;
        } else {
            uint16_t value14 = BUS16(c, 0xC90000 + ((value12 & 0x03FF) << 1));
            RAM16_SET(0x00D1 + dp, value14);
            a6 = 0xC9;
            a_hi6 = value14 >> 8;
        }
        RAM8(0x00D3 + dp) = a6;
        uint8_t value15 = RAM8(0x00D0 + dp);
        RAM8(0x00D0 + dp) = 1;
        if (value15 < 1) {
            RAM8(0x00CC + dp) = 0;
            RAM8(0x00CD + dp) = 0;
            RAM8(0x00CE + dp) = 0;
            uint16_t value16 = RAM16(0x00D4 + dp);
            uint8_t value17 = RAM8(0xE02C + value16);
            uint16_t y8;
            bool carry8;
            if ((value17 & 7) == 0) {
                y8 = 0;
                carry8 = value15 >= 1;
            } else {
                uint16_t y7;
                bool carry7;
                if ((value17 & 7) >> 1 == 0) {
                    y7 = 0;
                    carry7 = value17 & 7 & 0x01;
                } else {
                    uint16_t y6;
                    if ((value17 & 7) >> 2 == 0) {
                        y6 = 1;
                    } else {
                        y6 = 2;
                    }
                    y7 = y6;
                    carry7 = (value17 & 7) >> 1 & 0x01;
                }
                RAM8(0x00D9 + y7) |= 0x80;
                y8 = y7;
                carry8 = carry7;
            }
            uint8_t value19 = RAM8(0x00FF + dp);
            bool m_flag5;
            uint8_t a7;
            uint8_t a_hi7;
            if (value19 != 0) {
                m_flag5 = 1;
                a7 = value19;
                a_hi7 = a_hi6;
            } else {
                RAM16_SET(0xE006 + value16, 0);
                RAM16_SET(0xE008 + value16, 0);
                m_flag5 = 0;
                a7 = 0;
                a_hi7 = 0;
            }
            r->x = value16;
            r->xf = 0;
            r->sp -= 2;
            JSR(c, 0xE8C4, 0xC1F390); /* reset_actor_event_animation_and_motion */
            r->sp += 2;
            r->x = x; /* PLX; M/X stay as reset_actor_event_animation_and_motion left them */
            RETURN_RTS(c);
        }
        r->a = (a_hi6 << 8) | 1;
        r->c = value15 >= 1;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if ((value11 & 0xFF) == 0xFF) {
        uint16_t value20 = RAM16(0x0000 + dp);
        uint8_t a8;
        uint8_t a_hi8;
        if (value20 >= 0x0400) {
            uint16_t value21 = BUS16(c, 0xCA0000 + ((value20 & 0x03FF) << 1));
            RAM16_SET(0x00D1 + dp, value21);
            a8 = 0xCA;
            a_hi8 = value21 >> 8;
        } else {
            uint16_t value22 = BUS16(c, 0xC90000 + ((value20 & 0x03FF) << 1));
            RAM16_SET(0x00D1 + dp, value22);
            a8 = 0xC9;
            a_hi8 = value22 >> 8;
        }
        RAM8(0x00D3 + dp) = a8;
        uint8_t value23 = RAM8(0x00D0 + dp);
        RAM8(0x00D0 + dp) = 1;
        if (value23 < 1) {
            RAM8(0x00CC + dp) = 0;
            RAM8(0x00CD + dp) = 0;
            RAM8(0x00CE + dp) = 0;
            uint16_t value24 = RAM16(0x00D4 + dp);
            uint8_t value25 = RAM8(0xE02C + value24);
            uint16_t y11;
            bool carry10;
            if ((value25 & 7) == 0) {
                y11 = 0;
                carry10 = value23 >= 1;
            } else {
                uint16_t y10;
                bool carry9;
                if ((value25 & 7) >> 1 == 0) {
                    y10 = 0;
                    carry9 = value25 & 7 & 0x01;
                } else {
                    uint16_t y9;
                    if ((value25 & 7) >> 2 == 0) {
                        y9 = 1;
                    } else {
                        y9 = 2;
                    }
                    y10 = y9;
                    carry9 = (value25 & 7) >> 1 & 0x01;
                }
                RAM8(0x00D9 + y10) |= 0x80;
                y11 = y10;
                carry10 = carry9;
            }
            uint8_t value27 = RAM8(0x00FF + dp);
            bool m_flag6;
            uint8_t a9;
            uint8_t a_hi9;
            if (value27 != 0) {
                m_flag6 = 1;
                a9 = value27;
                a_hi9 = a_hi8;
            } else {
                RAM16_SET(0xE006 + value24, 0);
                RAM16_SET(0xE008 + value24, 0);
                m_flag6 = 0;
                a9 = 0;
                a_hi9 = 0;
            }
            r->x = value24;
            r->xf = 0;
            r->sp -= 2;
            JSR(c, 0xE8C4, 0xC1F390); /* reset_actor_event_animation_and_motion */
            r->sp += 2;
            r->x = x;
            RETURN_RTS(c);
        }
        r->a = (a_hi8 << 8) | 1;
        r->c = value23 >= 1;
        r->mf = 1; /* SEP #$20 at the numeric-request tail */
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM8(0x00CC + dp) = 0;
    RAM8(0x00CD + dp) = 0;
    RAM8(0x00CE + dp) = 0;
    r->a = value11 & 0xFF;
    r->c = (value11 & 0xFF) >= 0xFF;
    r->mf = 1; /* clear_event_request_scratch_and_return: REP #$10, SEP #$20 */
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E77B, SOM_RTS, "hand", accept_numeric_event_request, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 4, -1, -1, 981, 186)
