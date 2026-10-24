#include "som_c.h"

/* C2B10A project_ui_focus_marker_and_trigger_real_map_transition   [class C, 317 bytes, 155 instructions]
 * Source: src/rom/project_ui_focus_marker_and_trigger_real_map_transition.s
 * Entry: M=16 bit X=16 bit DB=any D=$0000.  Callers read: Y.
 */
static void project_ui_focus_marker_and_trigger_real_map_transition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const uint8_t db = r->db;
    if (RAM8(0x008C) != 0) {
        r->mf = 1;
        RETURN_RTL(c);
    }
    if ((RAM8(0x00E3) & 0x40) != 0) {
        uint8_t value3 = RAM8(0x00F4);
        bool carry3;
        if (value3 != 0) {
            carry3 = carry;
        } else {
            uint8_t value4 = RAM8(0x00F5);
            bool carry2;
            if (value4 & 0x01) {
                carry2 = value4 & 0x01;
            } else {
                uint8_t value5 = RAM8(0x00CF);
                bool carry1;
                if (value5 != 0) {
                    carry1 = value4 & 0x01;
                } else {
                    uint8_t value6 = RAM8(0x00C7);
                    RAM8(0x00C7) = (uint8_t)(value6 + 0x4B);
                    RAM8(0x00C6) = (uint8_t)(value6 + 0x4B) & 0x3F;
                    carry1 = value6 + 0x4B > 0xFF;
                }
                carry2 = carry1;
            }
            carry3 = carry2;
        }
        uint8_t value7 = RAM8(0x00C6);
        uint8_t a_hi3;
        bool carry5;
        if (value7 == 0) {
            a_hi3 = a >> 8;
            carry5 = carry3;
        } else {
            RAM8(0x00C6)--;
            uint16_t value8 = BUS16_RDP(c, (db << 0x10) + 0x0128);
            uint16_t value9 = RAM16(0x00C6);
            uint8_t a1;
            uint8_t a_hi1;
            if (!(value9 & 0x4000)) {
                a1 = (uint8_t)(value8 - 6);
                a_hi1 = (uint16_t)(value8 - 6) >> 8;
            } else {
                a1 = (uint8_t)(value8 + 6);
                a_hi1 = (uint16_t)(value8 + 6) >> 8;
            }
            BUS16_SET(c, (db << 0x10) + 0x0128, ((a_hi1 << 8) | a1) & 0x0FFF);
            uint16_t value10 = BUS16_RDP(c, (db << 0x10) + 0x012A);
            uint16_t value11 = RAM16(0x00C6);
            uint8_t a2;
            uint8_t a_hi2;
            bool carry4;
            if (value11 & 0x8000) {
                a2 = (uint8_t)(value10 - 6);
                a_hi2 = (uint16_t)(value10 - 6) >> 8;
                carry4 = value10 >= 6;
            } else {
                a2 = (uint8_t)(value10 + 6);
                a_hi2 = (uint16_t)(value10 + 6) >> 8;
                carry4 = value10 + 6 > 0xFFFF;
            }
            BUS16_SET(c, (db << 0x10) + 0x012A, ((a_hi2 << 8) | a2) & 0x0FFF);
            a_hi3 = (((a_hi2 << 8) | a2) & 0x0FFF) >> 8;
            carry5 = carry4;
        }
        RAM8(0x0000 + sp0) = y >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)y;
        RAM8(0x000B) = 0xD0;
        uint16_t value12 = BUS16_RDP(c, (db << 0x10) + 0x0128);
        RAM16_SET(0x000C, value12);
        uint16_t value13 = BUS16_RDP(c, (db << 0x10) + 0x012A);
        RAM16_SET(0x000E, value13);
        r->a = value13;
        r->c = carry5;
        r->z = value13 == 0;
        r->n = value13 & 0x8000;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB17E, 0xC2B287); GUARD_JSR(c, sp_call, 0xB17E); } /* project_wrapped_ui_target_with_native_perspective */
        r->sp += 2;
        uint16_t a_all = r->a;
        bool carry_ret = r->c;
        uint8_t value14 = RAM8(0x0000 + sp0 - 1);
        uint8_t value15 = RAM8(0x0000 + sp0);
        if (!carry_ret) {
            uint16_t value16 = BUS16(c, 0x02B7A4 + ((a_all & 7) << 1));
            uint16_t value17 = RAM16(0x000C);
            uint8_t a3;
            uint8_t a_hi4;
            if (!(value17 & 0x8000)) {
                a3 = (uint8_t)value17;
                a_hi4 = value17 >> 8;
            } else {
                a3 = (uint8_t)(value17 ^ 0xFFFF);
                a_hi4 = (value17 ^ 0xFFFF) >> 8;
            }
            if (((a_hi4 << 8) | a3) >= 0x40) {
                if (RAM8(0x00CF) != 0) {
                    RAM8(0x00CF)--;
                }
                RAM8(0x00BE) |= 0x80;
                uint8_t value20 = RAM8(0x00F2);
                if (value20 & 0x80) {
                    RAM8(0x00CC) |= 0x10;
                }
                uint8_t value22 = BUS8(c, 0xC20000 + value16);
                RAM8(0x0002) = value22;
                RAM8(0x0004) = value22;
                RAM8(0x0003) = 0;
                r->a = (a_hi4 << 8) | value22;
                r->x = (uint16_t)(value16 + 1);
                r->y = (value15 << 8) | value14;
                r->c = ((a_hi4 << 8) | a3) >= 0x40;
                r->z = (uint16_t)(value16 + 1) == 0;
                r->n = (uint16_t)(value16 + 1) & 0x8000;
                r->v = value20 & 0x40;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB206, 0xC2B247); GUARD_JSR(c, sp_call, 0xB206); } /* publish_clipped_ui_marker_sprite_records */
                uint16_t y_ret2 = r->y;
                uint8_t value23 = RAM8(0x00BF);
                bool m_flag;
                uint16_t y1;
                if (value23 == 0) {
                    m_flag = 1;
                    y1 = y_ret2;
                } else {
                    uint8_t a4;
                    if (!(value23 & 0x80)) {
                        a4 = value23;
                    } else {
                        RAM8(0x00E6) = ((value23 >> 3) & 0x0F) ^ 0x0F;
                        a4 = 0x7F;
                    }
                    BUS8_SET(c, (db << 0x10) + 0x4202, (uint8_t)(a4 << 1));
                    uint8_t value24 = RAM8(0x0009);
                    BUS8_SET(c, (db << 0x10) + 0x4203, (uint8_t)(value24 + 0x20 + (a4 >> 7)));
                    uint8_t value25 = BUS8_RDP(c, (db << 0x10) + 0x4217);
                    RAM8(0x0009) = (uint8_t)(value25 + 0xE4 + (value24 + 0x20 + (a4 >> 7) > 0xFF));
                    uint16_t value26 = RAM16(0x00F4);
                    uint16_t value27 = BUS16(c, 0x02B7B4 + ((value26 >> 1) & 6));
                    RAM16_SET(0x0002, 2);
                    r->a = 2;
                    r->x = value27;
                    r->c = value26 & 0x01;
                    r->z = 0;
                    r->n = 0;
                    r->v = ((value25 ^ (uint8_t)(value25 + 0xE4 + (value24 + 0x20 + (a4 >> 7) > 0xFF))) & ((uint8_t)(value25 + 0xE4 + (value24 + 0x20 + (a4 >> 7) > 0xFF)) ^ 0xE4) & 0x80) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB245, 0xC2B247); GUARD_JSR(c, sp_call, 0xB245); } /* publish_clipped_ui_marker_sprite_records */
                    bool m_ret3 = r->mf;
                    uint16_t y_ret3 = r->y;
                    m_flag = m_ret3;
                    y1 = y_ret3;
                }
                r->y = y1;
                r->mf = m_flag;
                r->xf = 0;
                RETURN_RTL(c);
            }
            uint16_t value28 = RAM16(0x000E);
            uint8_t a5;
            uint8_t a_hi5;
            if (!(value28 & 0x8000)) {
                a5 = (uint8_t)value28;
                a_hi5 = value28 >> 8;
            } else {
                a5 = (uint8_t)(value28 ^ 0xFFFF);
                a_hi5 = (value28 ^ 0xFFFF) >> 8;
            }
            if (((a_hi5 << 8) | a5) >= 0x40) {
                if (RAM8(0x00CF) != 0) {
                    RAM8(0x00CF)--;
                }
                RAM8(0x00BE) |= 0x80;
                uint8_t value31 = RAM8(0x00F2);
                if (value31 & 0x80) {
                    RAM8(0x00CC) |= 0x10;
                }
                uint8_t value33 = BUS8(c, 0xC20000 + value16);
                RAM8(0x0002) = value33;
                RAM8(0x0004) = value33;
                RAM8(0x0003) = 0;
                r->a = (a_hi5 << 8) | value33;
                r->x = (uint16_t)(value16 + 1);
                r->y = (value15 << 8) | value14;
                r->c = ((a_hi5 << 8) | a5) >= 0x40;
                r->z = (uint16_t)(value16 + 1) == 0;
                r->n = (uint16_t)(value16 + 1) & 0x8000;
                r->v = value31 & 0x40;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB206, 0xC2B247); GUARD_JSR(c, sp_call, 0xB206); } /* publish_clipped_ui_marker_sprite_records */
                uint16_t y_ret4 = r->y;
                uint8_t value34 = RAM8(0x00BF);
                bool m_flag2;
                uint16_t y2;
                if (value34 == 0) {
                    m_flag2 = 1;
                    y2 = y_ret4;
                } else {
                    uint8_t a6;
                    if (!(value34 & 0x80)) {
                        a6 = value34;
                    } else {
                        RAM8(0x00E6) = ((value34 >> 3) & 0x0F) ^ 0x0F;
                        a6 = 0x7F;
                    }
                    BUS8_SET(c, (db << 0x10) + 0x4202, (uint8_t)(a6 << 1));
                    uint8_t value35 = RAM8(0x0009);
                    BUS8_SET(c, (db << 0x10) + 0x4203, (uint8_t)(value35 + 0x20 + (a6 >> 7)));
                    uint8_t value36 = BUS8_RDP(c, (db << 0x10) + 0x4217);
                    RAM8(0x0009) = (uint8_t)(value36 + 0xE4 + (value35 + 0x20 + (a6 >> 7) > 0xFF));
                    uint16_t value37 = RAM16(0x00F4);
                    uint16_t value38 = BUS16(c, 0x02B7B4 + ((value37 >> 1) & 6));
                    RAM16_SET(0x0002, 2);
                    r->a = 2;
                    r->x = value38;
                    r->c = value37 & 0x01;
                    r->z = 0;
                    r->n = 0;
                    r->v = ((value36 ^ (uint8_t)(value36 + 0xE4 + (value35 + 0x20 + (a6 >> 7) > 0xFF))) & ((uint8_t)(value36 + 0xE4 + (value35 + 0x20 + (a6 >> 7) > 0xFF)) ^ 0xE4) & 0x80) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB245, 0xC2B247); GUARD_JSR(c, sp_call, 0xB245); } /* publish_clipped_ui_marker_sprite_records */
                    bool m_ret5 = r->mf;
                    uint16_t y_ret5 = r->y;
                    m_flag2 = m_ret5;
                    y2 = y_ret5;
                }
                r->y = y2;
                r->mf = m_flag2;
                r->xf = 0;
                RETURN_RTL(c);
            }
            uint8_t value39 = RAM8(0x00F8);
            if (value39 < 0xB8) {
                if (RAM8(0x00CF) != 0) {
                    RAM8(0x00CF)--;
                }
                RAM8(0x00BE) |= 0x80;
                uint8_t value42 = RAM8(0x00F2);
                if (value42 & 0x80) {
                    RAM8(0x00CC) |= 0x10;
                }
                uint8_t value44 = BUS8(c, 0xC20000 + value16);
                RAM8(0x0002) = value44;
                RAM8(0x0004) = value44;
                RAM8(0x0003) = 0;
                r->a = (a_hi5 << 8) | value44;
                r->x = (uint16_t)(value16 + 1);
                r->y = (value15 << 8) | value14;
                r->c = value39 >= 0xB8;
                r->z = (uint16_t)(value16 + 1) == 0;
                r->n = (uint16_t)(value16 + 1) & 0x8000;
                r->v = value42 & 0x40;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB206, 0xC2B247); GUARD_JSR(c, sp_call, 0xB206); } /* publish_clipped_ui_marker_sprite_records */
                uint16_t y_ret6 = r->y;
                uint8_t value45 = RAM8(0x00BF);
                bool m_flag3;
                uint16_t y3;
                if (value45 == 0) {
                    m_flag3 = 1;
                    y3 = y_ret6;
                } else {
                    uint8_t a7;
                    if (!(value45 & 0x80)) {
                        a7 = value45;
                    } else {
                        RAM8(0x00E6) = ((value45 >> 3) & 0x0F) ^ 0x0F;
                        a7 = 0x7F;
                    }
                    BUS8_SET(c, (db << 0x10) + 0x4202, (uint8_t)(a7 << 1));
                    uint8_t value46 = RAM8(0x0009);
                    BUS8_SET(c, (db << 0x10) + 0x4203, (uint8_t)(value46 + 0x20 + (a7 >> 7)));
                    uint8_t value47 = BUS8_RDP(c, (db << 0x10) + 0x4217);
                    RAM8(0x0009) = (uint8_t)(value47 + 0xE4 + (value46 + 0x20 + (a7 >> 7) > 0xFF));
                    uint16_t value48 = RAM16(0x00F4);
                    uint16_t value49 = BUS16(c, 0x02B7B4 + ((value48 >> 1) & 6));
                    RAM16_SET(0x0002, 2);
                    r->a = 2;
                    r->x = value49;
                    r->c = value48 & 0x01;
                    r->z = 0;
                    r->n = 0;
                    r->v = ((value47 ^ (uint8_t)(value47 + 0xE4 + (value46 + 0x20 + (a7 >> 7) > 0xFF))) & ((uint8_t)(value47 + 0xE4 + (value46 + 0x20 + (a7 >> 7) > 0xFF)) ^ 0xE4) & 0x80) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB245, 0xC2B247); GUARD_JSR(c, sp_call, 0xB245); } /* publish_clipped_ui_marker_sprite_records */
                    bool m_ret7 = r->mf;
                    uint16_t y_ret7 = r->y;
                    m_flag3 = m_ret7;
                    y3 = y_ret7;
                }
                r->y = y3;
                r->mf = m_flag3;
                r->xf = 0;
                RETURN_RTL(c);
            }
            uint8_t value50 = RAM8(0x00CF);
            if ((uint8_t)(value50 + 1) < 0x5C) {
                RAM8(0x00CF)++;
                RAM8(0x00BE) |= 0x80;
                uint8_t value52 = RAM8(0x00F2);
                if (value52 & 0x80) {
                    RAM8(0x00CC) |= 0x10;
                }
                uint8_t value54 = BUS8(c, 0xC20000 + value16);
                RAM8(0x0002) = value54;
                RAM8(0x0004) = value54;
                RAM8(0x0003) = 0;
                r->a = (a_hi5 << 8) | value54;
                r->x = (uint16_t)(value16 + 1);
                r->y = (value15 << 8) | value14;
                r->c = (uint8_t)(value50 + 1) >= 0x5C;
                r->z = (uint16_t)(value16 + 1) == 0;
                r->n = (uint16_t)(value16 + 1) & 0x8000;
                r->v = value52 & 0x40;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB206, 0xC2B247); GUARD_JSR(c, sp_call, 0xB206); } /* publish_clipped_ui_marker_sprite_records */
                uint16_t y_ret8 = r->y;
                uint8_t value55 = RAM8(0x00BF);
                bool m_flag4;
                uint16_t y4;
                if (value55 == 0) {
                    m_flag4 = 1;
                    y4 = y_ret8;
                } else {
                    uint8_t a8;
                    if (!(value55 & 0x80)) {
                        a8 = value55;
                    } else {
                        RAM8(0x00E6) = ((value55 >> 3) & 0x0F) ^ 0x0F;
                        a8 = 0x7F;
                    }
                    BUS8_SET(c, (db << 0x10) + 0x4202, (uint8_t)(a8 << 1));
                    uint8_t value56 = RAM8(0x0009);
                    BUS8_SET(c, (db << 0x10) + 0x4203, (uint8_t)(value56 + 0x20 + (a8 >> 7)));
                    uint8_t value57 = BUS8_RDP(c, (db << 0x10) + 0x4217);
                    RAM8(0x0009) = (uint8_t)(value57 + 0xE4 + (value56 + 0x20 + (a8 >> 7) > 0xFF));
                    uint16_t value58 = RAM16(0x00F4);
                    uint16_t value59 = BUS16(c, 0x02B7B4 + ((value58 >> 1) & 6));
                    RAM16_SET(0x0002, 2);
                    r->a = 2;
                    r->x = value59;
                    r->c = value58 & 0x01;
                    r->z = 0;
                    r->n = 0;
                    r->v = ((value57 ^ (uint8_t)(value57 + 0xE4 + (value56 + 0x20 + (a8 >> 7) > 0xFF))) & ((uint8_t)(value57 + 0xE4 + (value56 + 0x20 + (a8 >> 7) > 0xFF)) ^ 0xE4) & 0x80) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB245, 0xC2B247); GUARD_JSR(c, sp_call, 0xB245); } /* publish_clipped_ui_marker_sprite_records */
                    bool m_ret9 = r->mf;
                    uint16_t y_ret9 = r->y;
                    m_flag4 = m_ret9;
                    y4 = y_ret9;
                }
                r->y = y4;
                r->mf = m_flag4;
                r->xf = 0;
                RETURN_RTL(c);
            }
            uint8_t value60 = RAM8(0x00BF);
            RAM8(0x00BF) = (uint8_t)(value60 + ((uint8_t)(value50 + 1) >= 0x5C));
            if ((uint8_t)(value60 + ((uint8_t)(value50 + 1) >= 0x5C)) != 0) {
                RAM8(0x00BE) |= 0x80;
                uint8_t value62 = RAM8(0x00F2);
                if (value62 & 0x80) {
                    RAM8(0x00CC) |= 0x10;
                }
                uint8_t value64 = BUS8(c, 0xC20000 + value16);
                RAM8(0x0002) = value64;
                RAM8(0x0004) = value64;
                RAM8(0x0003) = 0;
                r->a = (a_hi5 << 8) | value64;
                r->x = (uint16_t)(value16 + 1);
                r->y = (value15 << 8) | value14;
                r->c = value60 + ((uint8_t)(value50 + 1) >= 0x5C) > 0xFF;
                r->z = (uint16_t)(value16 + 1) == 0;
                r->n = (uint16_t)(value16 + 1) & 0x8000;
                r->v = value62 & 0x40;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB206, 0xC2B247); GUARD_JSR(c, sp_call, 0xB206); } /* publish_clipped_ui_marker_sprite_records */
                uint16_t y_ret10 = r->y;
                uint8_t value65 = RAM8(0x00BF);
                bool m_flag5;
                uint16_t y5;
                if (value65 == 0) {
                    m_flag5 = 1;
                    y5 = y_ret10;
                } else {
                    uint8_t a9;
                    if (!(value65 & 0x80)) {
                        a9 = value65;
                    } else {
                        RAM8(0x00E6) = ((value65 >> 3) & 0x0F) ^ 0x0F;
                        a9 = 0x7F;
                    }
                    BUS8_SET(c, (db << 0x10) + 0x4202, (uint8_t)(a9 << 1));
                    uint8_t value66 = RAM8(0x0009);
                    BUS8_SET(c, (db << 0x10) + 0x4203, (uint8_t)(value66 + 0x20 + (a9 >> 7)));
                    uint8_t value67 = BUS8_RDP(c, (db << 0x10) + 0x4217);
                    RAM8(0x0009) = (uint8_t)(value67 + 0xE4 + (value66 + 0x20 + (a9 >> 7) > 0xFF));
                    uint16_t value68 = RAM16(0x00F4);
                    uint16_t value69 = BUS16(c, 0x02B7B4 + ((value68 >> 1) & 6));
                    RAM16_SET(0x0002, 2);
                    r->a = 2;
                    r->x = value69;
                    r->c = value68 & 0x01;
                    r->z = 0;
                    r->n = 0;
                    r->v = ((value67 ^ (uint8_t)(value67 + 0xE4 + (value66 + 0x20 + (a9 >> 7) > 0xFF))) & ((uint8_t)(value67 + 0xE4 + (value66 + 0x20 + (a9 >> 7) > 0xFF)) ^ 0xE4) & 0x80) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB245, 0xC2B247); GUARD_JSR(c, sp_call, 0xB245); } /* publish_clipped_ui_marker_sprite_records */
                    bool m_ret11 = r->mf;
                    uint16_t y_ret11 = r->y;
                    m_flag5 = m_ret11;
                    y5 = y_ret11;
                }
                r->y = y5;
                r->mf = m_flag5;
                r->xf = 0;
                RETURN_RTL(c);
            }
            RAM8(0x00E8) = 1;
            RAM8(0x00F2) |= 0x80;
            r->sp = 0x01FF;
            som_task_note(c);
            sp0 = r->sp;
            if (r->sp < 0x100 || sp0 > 0x1FFF) { c->fail = 3; return; }
            r->a = 0x0A;
            r->x = 0x01FF;
            r->y = (value15 << 8) | value14;
            r->c = value60 + ((uint8_t)(value50 + 1) >= 0x5C) > 0xFF;
            r->z = 0;
            r->n = 0;
            r->v = ((value60 ^ (uint8_t)(value60 + ((uint8_t)(value50 + 1) >= 0x5C))) & (uint8_t)(value60 + ((uint8_t)(value50 + 1) >= 0x5C)) & 0x80) != 0;
            r->mf = 0;
            r->xf = 0;
            TAIL_CALL(c, 0x008260, SOM_RTL); /* enter_native_map_from_selected_ui_target_index */
        }
        RAM8(0x00BE) = 0;
        RAM8(0x00BF) = 0;
        if (RAM8(0x00CF) != 0) {
            RAM8(0x00CF)--;
        }
        r->y = (value15 << 8) | value14;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    r->mf = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2B10A, SOM_RTL, "gen", project_ui_focus_marker_and_trigger_real_map_transition, 0, L_Y, 2, 0, 0, 317, 155)
