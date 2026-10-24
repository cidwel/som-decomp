#include "som_c.h"

/* C2A069 decode_map_tile_word_layers   [class C, 242 bytes, 121 instructions]
 * Source: src/rom/decode_map_tile_word_layers.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: BX.
 */
static void decode_map_tile_word_layers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    uint8_t value = RAM8(0x001C);
    RAM8(0x0000) = value & 0x3F;
    uint8_t value2 = RAM8(0x0000);
    uint16_t value3 = BUS16(c, 0xCB4000 + (uint8_t)((a >> 8 << 8) | (uint8_t)(((value & 0x3F) << 1) + value2)));
    RAM16_SET(0x0010, value3);
    uint16_t value4 = BUS16(c, 0xCB4002 + (uint8_t)((a >> 8 << 8) | (uint8_t)(((value & 0x3F) << 1) + value2)));
    RAM16_SET(0x0012, value4 | 0xC0);
    RAM16_SET(0x0014, 0xC000);
    RAM16_SET(0x0016, 0xC800);
    RAM16_SET(0x0018, 0x0300);
    RAM16_SET(0x0004, 0);
    uint8_t value5 = BUS8_RDL(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010), RAM8(0x0012));
    RAM8(0x0000) = value5;
    uint8_t a1 = value5;
    uint8_t a_hi1 = 3;
    uint8_t x1 = 4;
    uint8_t y1 = 0;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            uint8_t value6 = RAM8(0x0000);
            RAM8(0x0000) <<= 1;
            uint8_t value7 = RAM8(0x0000);
            RAM8(0x0000) <<= 1;
            uint8_t x2;
            if ((uint8_t)(x1 - 1) != 0) {
                x2 = (uint8_t)(x1 - 1);
            } else {
                RAM8(0x0010)++;
                if (RAM8(0x0010) == 0) {
                    RAM8(0x0011)++;
                    if (RAM8(0x0011) == 0) {
                        RAM8(0x0012)++;
                    }
                }
                RAM8(0x0000 + sp0) = (uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7));
                uint8_t value8 = BUS8_RDL(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010) + y1, RAM8(0x0012));
                RAM8(0x0000) = value8;
                x2 = 4;
            }
            bool m_flag4;
            uint8_t a_hi5;
            uint8_t x7;
            uint8_t y5;
            if (((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) == 0) {
                m_flag4 = 1;
                a_hi5 = a_hi1;
                x7 = x2;
                y5 = y1;
            } else {
                bool m_flag3;
                uint8_t a_hi4;
                uint8_t x6;
                uint8_t y4;
                if (((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) == 3) {
                    uint8_t value9 = RAM8(0x0000);
                    RAM8(0x0000) <<= 1;
                    uint8_t value10 = RAM8(0x0000);
                    RAM8(0x0000) <<= 1;
                    uint8_t x3;
                    if ((uint8_t)(x2 - 1) != 0) {
                        x3 = (uint8_t)(x2 - 1);
                    } else {
                        RAM8(0x0010)++;
                        if (RAM8(0x0010) == 0) {
                            RAM8(0x0011)++;
                            if (RAM8(0x0011) == 0) {
                                RAM8(0x0012)++;
                            }
                        }
                        RAM8(0x0000 + sp0) = (((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7);
                        uint8_t value11 = BUS8_RDL(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010) + y1, RAM8(0x0012));
                        RAM8(0x0000) = value11;
                        x3 = 4;
                    }
                    bool m_flag2;
                    uint8_t a_hi3;
                    uint8_t x5;
                    uint8_t y3;
                    if ((((((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3) >= 2) {
                        bool m_flag;
                        uint8_t a_hi2;
                        uint8_t x4;
                        uint8_t y2;
                        if ((((((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3) != 2) {
                            r->a = a_hi1 << 8 | (((((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3);
                            r->x = x3;
                            r->y = y1;
                            r->c = (((((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3) >= 2;
                            r->z = (((((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3) == 2;
                            r->n = (uint8_t)((((((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3) - 2) & 0x80;
                            r->mf = 1;
                            r->xf = 1;
                            r->db = 0x7F;
                            r->dp = 0;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xA157, 0xC2A19D); GUARD_JSR(c, sp_call, 0xA157); } /* read_map_tile_absolute_word */
                            bool m_ret = r->mf;
                            uint16_t a_all = r->a;
                            uint8_t y_ret = r->y;
                            m_flag = m_ret;
                            a_hi2 = a_all >> 8;
                            x4 = x3;
                            y2 = y_ret;
                        } else {
                            r->a = a_hi1 << 8 | (((((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3);
                            r->x = x3;
                            r->y = y1;
                            r->c = (((((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3) >= 2;
                            r->z = (((((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3) == 2;
                            r->n = (uint8_t)((((((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3) - 2) & 0x80;
                            r->mf = 1;
                            r->xf = 1;
                            r->db = 0x7F;
                            r->dp = 0;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xA14B, 0xC2A282); GUARD_JSR(c, sp_call, 0xA14B); } /* update_map_tile_word_attributes */
                            r->mf = 1;
                            r->xf = 1;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xA14E, 0xC2A227); GUARD_JSR(c, sp_call, 0xA14E); } /* read_map_tile_six_bit_value */
                            r->mf = 1;
                            r->xf = 1;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xA151, 0xC2A17C); GUARD_JSR(c, sp_call, 0xA151); } /* apply_map_tile_signed_six_bit_delta */
                            uint16_t a_all4 = r->a;
                            uint8_t x_ret3 = r->x;
                            uint8_t y_ret2 = r->y;
                            m_flag = 1;
                            a_hi2 = a_all4 >> 8;
                            x4 = x_ret3;
                            y2 = y_ret2;
                        }
                        m_flag2 = m_flag;
                        a_hi3 = a_hi2;
                        x5 = x4;
                        y3 = y2;
                    } else {
                        RAM8(0x0001) = ((((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3;
                        r->a = a_hi1 << 8 | (((((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3);
                        r->x = x3;
                        r->y = y1;
                        r->c = (((((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3) >= 2;
                        r->z = (((((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3) == 2;
                        r->n = (uint8_t)((((((((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3) - 2) & 0x80;
                        r->mf = 1;
                        r->xf = 1;
                        r->db = 0x7F;
                        r->dp = 0;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xA140, 0xC2A227); GUARD_JSR(c, sp_call, 0xA140); } /* read_map_tile_six_bit_value */
                        r->mf = 1;
                        r->xf = 1;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xA143, 0xC2A15B); GUARD_JSR(c, sp_call, 0xA143); } /* apply_map_tile_separate_sign_delta */
                        uint16_t a_all6 = r->a;
                        uint8_t x_ret5 = r->x;
                        uint8_t y_ret3 = r->y;
                        m_flag2 = 1;
                        a_hi3 = a_all6 >> 8;
                        x5 = x_ret5;
                        y3 = y_ret3;
                    }
                    m_flag3 = m_flag2;
                    a_hi4 = a_hi3;
                    x6 = x5;
                    y4 = y3;
                } else {
                    if (((uint8_t)(((uint8_t)((a1 << 1) | (value6 >> 7)) << 1) | (value7 >> 7)) & 3) != 1) {
                        RAM8(0x0004)--;
                    } else {
                        RAM8(0x0004)++;
                    }
                    m_flag3 = 1;
                    a_hi4 = a_hi1;
                    x6 = x2;
                    y4 = y1;
                }
                m_flag4 = m_flag3;
                a_hi5 = a_hi4;
                x7 = x6;
                y5 = y4;
            }
            uint16_t value12 = RAM16(0x0004);
            uint16_t value13 = RAM16(0x001B);
            if (!(value13 & 0x8000)) {
                if (!(value13 & 0x4000)) {
                    BUS16_SET(c, RAM16(0x0014) + 0x7F0000 + y5, value12);
                    RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) + 1));
                    RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) + 1));
                    BUS16_SET(c, RAM16(0x0016) + 0x7F0000 + y5, value12);
                    uint16_t value15 = RAM16(0x0016);
                    RAM16_SET(0x0016, (uint16_t)(value15 + 2));
                    if ((uint16_t)(value15 + 2) < 0xCE00) {
                        a1 = (uint8_t)(value15 + 2);
                        a_hi1 = (uint16_t)(value15 + 2) >> 8;
                        x1 = x7;
                        y1 = y5;
                        first_pass = false;
                        continue;
                    }
                    r->a = (uint16_t)(value15 + 2);
                    r->x = x7;
                    r->mf = 0;
                    r->xf = 1;
                    r->db = 0x7F;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                RAM16_SET(0x0018, (uint16_t)(RAM16(0x0018) - 1));
                if (RAM16(0x0018) & 0x8000) {
                    BUS16_SET(c, RAM16(0x0014) + 0x7F0000 + y5, value12);
                    uint16_t value17 = RAM16(0x0014);
                    RAM16_SET(0x0014, (uint16_t)(value17 + 2));
                    if ((uint16_t)(value17 + 2) < 0xC600) {
                        a1 = (uint8_t)(value17 + 2);
                        a_hi1 = (uint16_t)(value17 + 2) >> 8;
                        x1 = x7;
                        y1 = y5;
                        first_pass = false;
                        continue;
                    }
                    r->a = (uint16_t)(value17 + 2);
                    r->x = x7;
                    r->mf = 0;
                    r->xf = 1;
                    r->db = 0x7F;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                BUS16_SET(c, RAM16(0x0016) + 0x7F0000 + y5, value12);
                RAM16_SET(0x0016, (uint16_t)(RAM16(0x0016) + 1));
                RAM16_SET(0x0016, (uint16_t)(RAM16(0x0016) + 1));
                a1 = (uint8_t)value12;
                a_hi1 = value12 >> 8;
                x1 = x7;
                y1 = y5;
                first_pass = false;
                continue;
            }
            if (!(value13 & 0x4000)) {
                RAM16_SET(0x0018, (uint16_t)(RAM16(0x0018) - 1));
                if (RAM16(0x0018) & 0x8000) {
                    BUS16_SET(c, RAM16(0x0016) + 0x7F0000 + y5, value12);
                    uint16_t value20 = RAM16(0x0016);
                    RAM16_SET(0x0016, (uint16_t)(value20 + 2));
                    if ((uint16_t)(value20 + 2) < 0xCE00) {
                        a1 = (uint8_t)(value20 + 2);
                        a_hi1 = (uint16_t)(value20 + 2) >> 8;
                        x1 = x7;
                        y1 = y5;
                        first_pass = false;
                        continue;
                    }
                    r->a = (uint16_t)(value20 + 2);
                    r->x = x7;
                    r->mf = 0;
                    r->xf = 1;
                    r->db = 0x7F;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                BUS16_SET(c, RAM16(0x0014) + 0x7F0000 + y5, value12);
                RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) + 1));
                RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) + 1));
                a1 = (uint8_t)value12;
                a_hi1 = value12 >> 8;
                x1 = x7;
                y1 = y5;
                first_pass = false;
                continue;
            }
            RAM16_SET(0x0018, (uint16_t)(RAM16(0x0018) - 1));
            if (!(RAM16(0x0018) & 0x8000)) {
                a1 = (uint8_t)value12;
                a_hi1 = value12 >> 8;
                x1 = x7;
                y1 = y5;
                first_pass = false;
                continue;
            }
            BUS16_SET(c, RAM16(0x0014) + 0x7F0000 + y5, value12);
            RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) + 1));
            RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) + 1));
            BUS16_SET(c, RAM16(0x0016) + 0x7F0000 + y5, value12);
            uint16_t value24 = RAM16(0x0016);
            RAM16_SET(0x0016, (uint16_t)(value24 + 2));
            if ((uint16_t)(value24 + 2) < 0xCE00) {
                a1 = (uint8_t)(value24 + 2);
                a_hi1 = (uint16_t)(value24 + 2) >> 8;
                x1 = x7;
                y1 = y5;
                first_pass = false;
                continue;
            }
            r->a = (uint16_t)(value24 + 2);
            r->x = x7;
            r->mf = 0;
            r->xf = 1;
            r->db = 0x7F;
            r->dp = 0;
            RETURN_RTS(c);
        } else {
            uint8_t value25 = RAM8(0x0000);
            RAM8(0x0000) <<= 1;
            uint8_t value26 = RAM8(0x0000);
            RAM8(0x0000) <<= 1;
            uint8_t x8;
            if ((uint8_t)(x1 - 1) != 0) {
                x8 = (uint8_t)(x1 - 1);
            } else {
                RAM8(0x0010)++;
                if (RAM8(0x0010) == 0) {
                    RAM8(0x0011)++;
                    if (RAM8(0x0011) == 0) {
                        RAM8(0x0012)++;
                    }
                }
                RAM8(0x0000 + sp0) = (uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7));
                uint8_t value27 = BUS8_RDL(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010) + y1, RAM8(0x0012));
                RAM8(0x0000) = value27;
                x8 = 4;
            }
            bool m_flag8;
            uint8_t a_hi9;
            uint8_t x13;
            uint8_t y9;
            if (((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) == 0) {
                m_flag8 = 1;
                a_hi9 = a_hi1;
                x13 = x8;
                y9 = y1;
            } else {
                bool m_flag7;
                uint8_t a_hi8;
                uint8_t x12;
                uint8_t y8;
                if (((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) == 3) {
                    uint8_t value28 = RAM8(0x0000);
                    RAM8(0x0000) <<= 1;
                    uint8_t value29 = RAM8(0x0000);
                    RAM8(0x0000) <<= 1;
                    uint8_t x9;
                    if ((uint8_t)(x8 - 1) != 0) {
                        x9 = (uint8_t)(x8 - 1);
                    } else {
                        RAM8(0x0010)++;
                        if (RAM8(0x0010) == 0) {
                            RAM8(0x0011)++;
                            if (RAM8(0x0011) == 0) {
                                RAM8(0x0012)++;
                            }
                        }
                        RAM8(0x0000 + sp0) = (((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7);
                        uint8_t value30 = BUS8_RDL(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010) + y1, RAM8(0x0012));
                        RAM8(0x0000) = value30;
                        x9 = 4;
                    }
                    bool m_flag6;
                    uint8_t a_hi7;
                    uint8_t x11;
                    uint8_t y7;
                    if ((((((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7)) & 3) >= 2) {
                        bool m_flag5;
                        uint8_t a_hi6;
                        uint8_t x10;
                        uint8_t y6;
                        if ((((((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7)) & 3) != 2) {
                            r->a = a_hi1 << 8 | (((((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7)) & 3);
                            r->x = x9;
                            r->y = y1;
                            r->c = (((((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7)) & 3) >= 2;
                            r->z = (((((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7)) & 3) == 2;
                            r->n = (uint8_t)((((((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7)) & 3) - 2) & 0x80;
                            r->mf = 1;
                            r->xf = 1;
                            r->db = 0x7F;
                            r->dp = 0;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xA157, 0xC2A19D); GUARD_JSR(c, sp_call, 0xA157); } /* read_map_tile_absolute_word */
                            bool m_ret2 = r->mf;
                            uint16_t a_all7 = r->a;
                            uint8_t y_ret4 = r->y;
                            m_flag5 = m_ret2;
                            a_hi6 = a_all7 >> 8;
                            x10 = x9;
                            y6 = y_ret4;
                        } else {
                            r->a = a_hi1 << 8 | (((((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7)) & 3);
                            r->x = x9;
                            r->y = y1;
                            r->c = (((((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7)) & 3) >= 2;
                            r->z = (((((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7)) & 3) == 2;
                            r->n = (uint8_t)((((((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7)) & 3) - 2) & 0x80;
                            r->mf = 1;
                            r->xf = 1;
                            r->db = 0x7F;
                            r->dp = 0;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xA14B, 0xC2A282); GUARD_JSR(c, sp_call, 0xA14B); } /* update_map_tile_word_attributes */
                            r->mf = 1;
                            r->xf = 1;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xA14E, 0xC2A227); GUARD_JSR(c, sp_call, 0xA14E); } /* read_map_tile_six_bit_value */
                            r->mf = 1;
                            r->xf = 1;
                            { const uint16_t sp_call = r->sp; JSR(c, 0xA151, 0xC2A17C); GUARD_JSR(c, sp_call, 0xA151); } /* apply_map_tile_signed_six_bit_delta */
                            uint16_t a_all10 = r->a;
                            uint8_t x_ret8 = r->x;
                            uint8_t y_ret5 = r->y;
                            m_flag5 = 1;
                            a_hi6 = a_all10 >> 8;
                            x10 = x_ret8;
                            y6 = y_ret5;
                        }
                        m_flag6 = m_flag5;
                        a_hi7 = a_hi6;
                        x11 = x10;
                        y7 = y6;
                    } else {
                        RAM8(0x0001) = ((((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7)) & 3;
                        r->a = a_hi1 << 8 | (((((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7)) & 3);
                        r->x = x9;
                        r->y = y1;
                        r->c = (((((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7)) & 3) >= 2;
                        r->z = (((((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7)) & 3) == 2;
                        r->n = (uint8_t)((((((((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) << 1) | (value28 >> 7)) << 1) | (value29 >> 7)) & 3) - 2) & 0x80;
                        r->mf = 1;
                        r->xf = 1;
                        r->db = 0x7F;
                        r->dp = 0;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xA140, 0xC2A227); GUARD_JSR(c, sp_call, 0xA140); } /* read_map_tile_six_bit_value */
                        r->mf = 1;
                        r->xf = 1;
                        { const uint16_t sp_call = r->sp; JSR(c, 0xA143, 0xC2A15B); GUARD_JSR(c, sp_call, 0xA143); } /* apply_map_tile_separate_sign_delta */
                        uint16_t a_all12 = r->a;
                        uint8_t x_ret10 = r->x;
                        uint8_t y_ret6 = r->y;
                        m_flag6 = 1;
                        a_hi7 = a_all12 >> 8;
                        x11 = x_ret10;
                        y7 = y_ret6;
                    }
                    m_flag7 = m_flag6;
                    a_hi8 = a_hi7;
                    x12 = x11;
                    y8 = y7;
                } else {
                    if (((uint8_t)(((uint8_t)((a1 << 1) | (value25 >> 7)) << 1) | (value26 >> 7)) & 3) != 1) {
                        RAM8(0x0004)--;
                    } else {
                        RAM8(0x0004)++;
                    }
                    m_flag7 = 1;
                    a_hi8 = a_hi1;
                    x12 = x8;
                    y8 = y1;
                }
                m_flag8 = m_flag7;
                a_hi9 = a_hi8;
                x13 = x12;
                y9 = y8;
            }
            uint16_t value31 = RAM16(0x0004);
            uint16_t value32 = RAM16(0x001B);
            if (!(value32 & 0x8000)) {
                if (!(value32 & 0x4000)) {
                    BUS16_SET(c, RAM16(0x0014) + 0x7F0000 + y9, value31);
                    RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) + 1));
                    RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) + 1));
                    BUS16_SET(c, RAM16(0x0016) + 0x7F0000 + y9, value31);
                    uint16_t value34 = RAM16(0x0016);
                    RAM16_SET(0x0016, (uint16_t)(value34 + 2));
                    if ((uint16_t)(value34 + 2) < 0xCE00) {
                        a1 = (uint8_t)(value34 + 2);
                        a_hi1 = (uint16_t)(value34 + 2) >> 8;
                        x1 = x13;
                        y1 = y9;
                        continue;
                    }
                    r->a = (uint16_t)(value34 + 2);
                    r->x = x13;
                    r->mf = 0;
                    r->xf = 1;
                    r->db = 0x7F;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                RAM16_SET(0x0018, (uint16_t)(RAM16(0x0018) - 1));
                if (RAM16(0x0018) & 0x8000) {
                    BUS16_SET(c, RAM16(0x0014) + 0x7F0000 + y9, value31);
                    uint16_t value36 = RAM16(0x0014);
                    RAM16_SET(0x0014, (uint16_t)(value36 + 2));
                    if ((uint16_t)(value36 + 2) < 0xC600) {
                        a1 = (uint8_t)(value36 + 2);
                        a_hi1 = (uint16_t)(value36 + 2) >> 8;
                        x1 = x13;
                        y1 = y9;
                        continue;
                    }
                    r->a = (uint16_t)(value36 + 2);
                    r->x = x13;
                    r->mf = 0;
                    r->xf = 1;
                    r->db = 0x7F;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                BUS16_SET(c, RAM16(0x0016) + 0x7F0000 + y9, value31);
                RAM16_SET(0x0016, (uint16_t)(RAM16(0x0016) + 1));
                RAM16_SET(0x0016, (uint16_t)(RAM16(0x0016) + 1));
                a1 = (uint8_t)value31;
                a_hi1 = value31 >> 8;
                x1 = x13;
                y1 = y9;
                continue;
            }
            if (!(value32 & 0x4000)) {
                RAM16_SET(0x0018, (uint16_t)(RAM16(0x0018) - 1));
                if (RAM16(0x0018) & 0x8000) {
                    BUS16_SET(c, RAM16(0x0016) + 0x7F0000 + y9, value31);
                    uint16_t value39 = RAM16(0x0016);
                    RAM16_SET(0x0016, (uint16_t)(value39 + 2));
                    if ((uint16_t)(value39 + 2) < 0xCE00) {
                        a1 = (uint8_t)(value39 + 2);
                        a_hi1 = (uint16_t)(value39 + 2) >> 8;
                        x1 = x13;
                        y1 = y9;
                        continue;
                    }
                    r->a = (uint16_t)(value39 + 2);
                    r->x = x13;
                    r->mf = 0;
                    r->xf = 1;
                    r->db = 0x7F;
                    r->dp = 0;
                    RETURN_RTS(c);
                }
                BUS16_SET(c, RAM16(0x0014) + 0x7F0000 + y9, value31);
                RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) + 1));
                RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) + 1));
                a1 = (uint8_t)value31;
                a_hi1 = value31 >> 8;
                x1 = x13;
                y1 = y9;
                continue;
            }
            RAM16_SET(0x0018, (uint16_t)(RAM16(0x0018) - 1));
            if (!(RAM16(0x0018) & 0x8000)) {
                a1 = (uint8_t)value31;
                a_hi1 = value31 >> 8;
                x1 = x13;
                y1 = y9;
                continue;
            }
            BUS16_SET(c, RAM16(0x0014) + 0x7F0000 + y9, value31);
            RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) + 1));
            RAM16_SET(0x0014, (uint16_t)(RAM16(0x0014) + 1));
            BUS16_SET(c, RAM16(0x0016) + 0x7F0000 + y9, value31);
            uint16_t value43 = RAM16(0x0016);
            RAM16_SET(0x0016, (uint16_t)(value43 + 2));
            if ((uint16_t)(value43 + 2) < 0xCE00) {
                a1 = (uint8_t)(value43 + 2);
                a_hi1 = (uint16_t)(value43 + 2) >> 8;
                x1 = x13;
                y1 = y9;
                continue;
            }
            r->a = (uint16_t)(value43 + 2);
            r->x = x13;
            r->mf = 0;
            r->xf = 1;
            r->db = 0x7F;
            r->dp = 0;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC2A069, SOM_RTS, "gen", decode_map_tile_word_layers, 0, L_B | L_X, 1, 0, 0, 242, 121)
