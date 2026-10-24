#include "som_c.h"

/* C1B78D search_native_horizontal_detour_after_vertical_motion   [class B, 131 bytes, 66 instructions]
 * Source: src/rom/search_native_horizontal_detour_after_vertical_motion.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void search_native_horizontal_detour_after_vertical_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0x0008);
    RAM8(0x0002) = (uint8_t)(value << 1);
    uint8_t value2 = RAM8(0x0009);
    uint8_t value3 = RAM8(0x0007);
    uint8_t a3;
    bool overflow3;
    if (value3 & 0x80) {
        uint8_t a1;
        bool overflow1;
        if (!((uint8_t)((uint8_t)((value2 << 1) | (value >> 7)) - 1) & 0x80)) {
            a1 = (uint8_t)((uint8_t)((value2 << 1) | (value >> 7)) - 1);
            overflow1 = value3 & 0x40;
        } else {
            uint8_t value4 = RAM8(0x009D);
            a1 = (uint8_t)((uint8_t)((uint8_t)((value2 << 1) | (value >> 7)) - 1) + value4);
            overflow1 = (((uint8_t)((uint8_t)((value2 << 1) | (value >> 7)) - 1) ^ (uint8_t)((uint8_t)((uint8_t)((value2 << 1) | (value >> 7)) - 1) + value4)) & (value4 ^ (uint8_t)((uint8_t)((uint8_t)((value2 << 1) | (value >> 7)) - 1) + value4)) & 0x80) != 0;
        }
        a3 = a1;
        overflow3 = overflow1;
    } else {
        uint8_t value5 = RAM8(0x009D);
        uint8_t a2;
        bool overflow2;
        if ((uint8_t)((uint8_t)((value2 << 1) | (value >> 7)) + 1) < value5) {
            a2 = (uint8_t)((uint8_t)((value2 << 1) | (value >> 7)) + 1);
            overflow2 = value3 & 0x40;
        } else {
            a2 = (uint8_t)((uint8_t)((uint8_t)((value2 << 1) | (value >> 7)) + 1) - value5 - ((uint8_t)((uint8_t)((value2 << 1) | (value >> 7)) + 1) >= value5 ^ 1));
            overflow2 = (((uint8_t)((uint8_t)((value2 << 1) | (value >> 7)) + 1) ^ value5) & ((uint8_t)((uint8_t)((value2 << 1) | (value >> 7)) + 1) ^ (uint8_t)((uint8_t)((uint8_t)((value2 << 1) | (value >> 7)) + 1) - value5 - ((uint8_t)((uint8_t)((value2 << 1) | (value >> 7)) + 1) >= value5 ^ 1))) & 0x80) != 0;
        }
        a3 = a2;
        overflow3 = overflow2;
    }
    RAM8(0x0003) = a3 >> 1;
    RAM8(0x0002) = (RAM8(0x0002) >> 1) | ((a3 & 1) << 7);
    RAM8(0x0005) = 1;
    uint8_t value7 = RAM8(0xE02E + x);
    RAM8(0xE02E + x) = value7 ^ 1;
    if ((value7 ^ 1) & 0x01) {
        r->a = (a_hi << 8) | ((value7 ^ 1) >> 1);
        r->c = (value7 ^ 1) & 0x01;
        r->z = (value7 ^ 1) >> 1 == 0;
        r->n = (value7 ^ 1) >> 1 & 0x80;
        r->v = overflow3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB7E1, 0xC1B810); GUARD_JSR(c, sp_call, 0xB7E1); } /* probe_native_detour_tile_left */
        bool m_ret = r->mf;
        bool carry_ret = r->c;
        if (!carry_ret) {
            RAM8(0xE006 + x) = 0x83;
            uint8_t value8 = RAM8(0x0005);
            RAM8(0x0005) = (uint8_t)(value8 << 1);
            uint8_t value9 = RAM8(0x0005);
            RAM8(0xE00A + x) = (uint8_t)((uint8_t)((uint8_t)(value8 << 2) + value9 + ((uint8_t)(value8 << 1) >> 7)) + 2);
            SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value8 << 2) + value9 + ((uint8_t)(value8 << 1) >> 7)) + 2));
            r->c = (uint8_t)((uint8_t)(value8 << 2) + value9 + ((uint8_t)(value8 << 1) >> 7)) + 2 > 0xFF;
            r->v = (((uint8_t)((uint8_t)(value8 << 2) + value9 + ((uint8_t)(value8 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value8 << 2) + value9 + ((uint8_t)(value8 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value8 << 2) + value9 + ((uint8_t)(value8 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        if (m_ret) {
            RAM8(0x0005)++;
            uint8_t value10 = RAM8(0x0005);
            r->z = value10 == 0;
            r->n = value10 & 0x80;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB7E8, 0xC1B810); GUARD_JSR(c, sp_call, 0xB7E8); } /* probe_native_detour_tile_left */
            bool m_ret2 = r->mf;
            bool carry_ret2 = r->c;
            if (!carry_ret2) {
                RAM8(0xE006 + x) = 0x83;
                uint8_t value11 = RAM8(0x0005);
                RAM8(0x0005) = (uint8_t)(value11 << 1);
                uint8_t value12 = RAM8(0x0005);
                RAM8(0xE00A + x) = (uint8_t)((uint8_t)((uint8_t)(value11 << 2) + value12 + ((uint8_t)(value11 << 1) >> 7)) + 2);
                SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value11 << 2) + value12 + ((uint8_t)(value11 << 1) >> 7)) + 2));
                r->c = (uint8_t)((uint8_t)(value11 << 2) + value12 + ((uint8_t)(value11 << 1) >> 7)) + 2 > 0xFF;
                r->v = (((uint8_t)((uint8_t)(value11 << 2) + value12 + ((uint8_t)(value11 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value11 << 2) + value12 + ((uint8_t)(value11 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value11 << 2) + value12 + ((uint8_t)(value11 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            if (m_ret2) {
                RAM8(0x0005)++;
                uint8_t value13 = RAM8(0x0005);
                r->z = value13 == 0;
                r->n = value13 & 0x80;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB7EF, 0xC1B810); GUARD_JSR(c, sp_call, 0xB7EF); } /* probe_native_detour_tile_left */
                bool m_ret3 = r->mf;
                bool carry_ret3 = r->c;
                if (!carry_ret3) {
                    RAM8(0xE006 + x) = 0x83;
                    uint8_t value14 = RAM8(0x0005);
                    RAM8(0x0005) = (uint8_t)(value14 << 1);
                    uint8_t value15 = RAM8(0x0005);
                    RAM8(0xE00A + x) = (uint8_t)((uint8_t)((uint8_t)(value14 << 2) + value15 + ((uint8_t)(value14 << 1) >> 7)) + 2);
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value14 << 2) + value15 + ((uint8_t)(value14 << 1) >> 7)) + 2));
                    r->c = (uint8_t)((uint8_t)(value14 << 2) + value15 + ((uint8_t)(value14 << 1) >> 7)) + 2 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value14 << 2) + value15 + ((uint8_t)(value14 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value14 << 2) + value15 + ((uint8_t)(value14 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value14 << 2) + value15 + ((uint8_t)(value14 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (m_ret3) {
                    RAM8(0x0005)++;
                    uint8_t value16 = RAM8(0x0005);
                    r->z = value16 == 0;
                    r->n = value16 & 0x80;
                    r->mf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB7F6, 0xC1B810); GUARD_JSR(c, sp_call, 0xB7F6); } /* probe_native_detour_tile_left */
                    bool carry_ret4 = r->c;
                    if (!carry_ret4) {
                        RAM8(0xE006 + x) = 0x83;
                        uint8_t value17 = RAM8(0x0005);
                        RAM8(0x0005) = (uint8_t)(value17 << 1);
                        uint8_t value18 = RAM8(0x0005);
                        RAM8(0xE00A + x) = (uint8_t)((uint8_t)((uint8_t)(value17 << 2) + value18 + ((uint8_t)(value17 << 1) >> 7)) + 2);
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value17 << 2) + value18 + ((uint8_t)(value17 << 1) >> 7)) + 2));
                        r->c = (uint8_t)((uint8_t)(value17 << 2) + value18 + ((uint8_t)(value17 << 1) >> 7)) + 2 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value17 << 2) + value18 + ((uint8_t)(value17 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value17 << 2) + value18 + ((uint8_t)(value17 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value17 << 2) + value18 + ((uint8_t)(value17 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    RAM16_SET(0x0005, (uint16_t)(RAM16(0x0005) + 1));
                    uint16_t value19 = RAM16(0x0005);
                    r->z = value19 == 0;
                    r->n = value19 & 0x8000;
                    r->mf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB7F6, 0xC1B810); GUARD_JSR(c, sp_call, 0xB7F6); } /* probe_native_detour_tile_left */
                    bool carry_ret5 = r->c;
                    if (!carry_ret5) {
                        RAM8(0xE006 + x) = 0x83;
                        uint8_t value20 = RAM8(0x0005);
                        RAM8(0x0005) = (uint8_t)(value20 << 1);
                        uint8_t value21 = RAM8(0x0005);
                        RAM8(0xE00A + x) = (uint8_t)((uint8_t)((uint8_t)(value20 << 2) + value21 + ((uint8_t)(value20 << 1) >> 7)) + 2);
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value20 << 2) + value21 + ((uint8_t)(value20 << 1) >> 7)) + 2));
                        r->c = (uint8_t)((uint8_t)(value20 << 2) + value21 + ((uint8_t)(value20 << 1) >> 7)) + 2 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value20 << 2) + value21 + ((uint8_t)(value20 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value20 << 2) + value21 + ((uint8_t)(value20 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value20 << 2) + value21 + ((uint8_t)(value20 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            } else {
                RAM16_SET(0x0005, (uint16_t)(RAM16(0x0005) + 1));
                uint16_t value22 = RAM16(0x0005);
                r->z = value22 == 0;
                r->n = value22 & 0x8000;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB7EF, 0xC1B810); GUARD_JSR(c, sp_call, 0xB7EF); } /* probe_native_detour_tile_left */
                bool m_ret6 = r->mf;
                bool carry_ret6 = r->c;
                if (!carry_ret6) {
                    RAM8(0xE006 + x) = 0x83;
                    uint8_t value23 = RAM8(0x0005);
                    RAM8(0x0005) = (uint8_t)(value23 << 1);
                    uint8_t value24 = RAM8(0x0005);
                    RAM8(0xE00A + x) = (uint8_t)((uint8_t)((uint8_t)(value23 << 2) + value24 + ((uint8_t)(value23 << 1) >> 7)) + 2);
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value23 << 2) + value24 + ((uint8_t)(value23 << 1) >> 7)) + 2));
                    r->c = (uint8_t)((uint8_t)(value23 << 2) + value24 + ((uint8_t)(value23 << 1) >> 7)) + 2 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value23 << 2) + value24 + ((uint8_t)(value23 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value23 << 2) + value24 + ((uint8_t)(value23 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value23 << 2) + value24 + ((uint8_t)(value23 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (m_ret6) {
                    RAM8(0x0005)++;
                    uint8_t value25 = RAM8(0x0005);
                    r->z = value25 == 0;
                    r->n = value25 & 0x80;
                    r->mf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB7F6, 0xC1B810); GUARD_JSR(c, sp_call, 0xB7F6); } /* probe_native_detour_tile_left */
                    bool carry_ret7 = r->c;
                    if (!carry_ret7) {
                        RAM8(0xE006 + x) = 0x83;
                        uint8_t value26 = RAM8(0x0005);
                        RAM8(0x0005) = (uint8_t)(value26 << 1);
                        uint8_t value27 = RAM8(0x0005);
                        RAM8(0xE00A + x) = (uint8_t)((uint8_t)((uint8_t)(value26 << 2) + value27 + ((uint8_t)(value26 << 1) >> 7)) + 2);
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value26 << 2) + value27 + ((uint8_t)(value26 << 1) >> 7)) + 2));
                        r->c = (uint8_t)((uint8_t)(value26 << 2) + value27 + ((uint8_t)(value26 << 1) >> 7)) + 2 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value26 << 2) + value27 + ((uint8_t)(value26 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value26 << 2) + value27 + ((uint8_t)(value26 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value26 << 2) + value27 + ((uint8_t)(value26 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    RAM16_SET(0x0005, (uint16_t)(RAM16(0x0005) + 1));
                    uint16_t value28 = RAM16(0x0005);
                    r->z = value28 == 0;
                    r->n = value28 & 0x8000;
                    r->mf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB7F6, 0xC1B810); GUARD_JSR(c, sp_call, 0xB7F6); } /* probe_native_detour_tile_left */
                    bool carry_ret8 = r->c;
                    if (!carry_ret8) {
                        RAM8(0xE006 + x) = 0x83;
                        uint8_t value29 = RAM8(0x0005);
                        RAM8(0x0005) = (uint8_t)(value29 << 1);
                        uint8_t value30 = RAM8(0x0005);
                        RAM8(0xE00A + x) = (uint8_t)((uint8_t)((uint8_t)(value29 << 2) + value30 + ((uint8_t)(value29 << 1) >> 7)) + 2);
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value29 << 2) + value30 + ((uint8_t)(value29 << 1) >> 7)) + 2));
                        r->c = (uint8_t)((uint8_t)(value29 << 2) + value30 + ((uint8_t)(value29 << 1) >> 7)) + 2 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value29 << 2) + value30 + ((uint8_t)(value29 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value29 << 2) + value30 + ((uint8_t)(value29 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value29 << 2) + value30 + ((uint8_t)(value29 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
        } else {
            RAM16_SET(0x0005, (uint16_t)(RAM16(0x0005) + 1));
            uint16_t value31 = RAM16(0x0005);
            r->z = value31 == 0;
            r->n = value31 & 0x8000;
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB7E8, 0xC1B810); GUARD_JSR(c, sp_call, 0xB7E8); } /* probe_native_detour_tile_left */
            bool m_ret9 = r->mf;
            bool carry_ret9 = r->c;
            if (!carry_ret9) {
                RAM8(0xE006 + x) = 0x83;
                uint8_t value32 = RAM8(0x0005);
                RAM8(0x0005) = (uint8_t)(value32 << 1);
                uint8_t value33 = RAM8(0x0005);
                RAM8(0xE00A + x) = (uint8_t)((uint8_t)((uint8_t)(value32 << 2) + value33 + ((uint8_t)(value32 << 1) >> 7)) + 2);
                SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value32 << 2) + value33 + ((uint8_t)(value32 << 1) >> 7)) + 2));
                r->c = (uint8_t)((uint8_t)(value32 << 2) + value33 + ((uint8_t)(value32 << 1) >> 7)) + 2 > 0xFF;
                r->v = (((uint8_t)((uint8_t)(value32 << 2) + value33 + ((uint8_t)(value32 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value32 << 2) + value33 + ((uint8_t)(value32 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value32 << 2) + value33 + ((uint8_t)(value32 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            if (m_ret9) {
                RAM8(0x0005)++;
                uint8_t value34 = RAM8(0x0005);
                r->z = value34 == 0;
                r->n = value34 & 0x80;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB7EF, 0xC1B810); GUARD_JSR(c, sp_call, 0xB7EF); } /* probe_native_detour_tile_left */
                bool m_ret10 = r->mf;
                bool carry_ret10 = r->c;
                if (!carry_ret10) {
                    RAM8(0xE006 + x) = 0x83;
                    uint8_t value35 = RAM8(0x0005);
                    RAM8(0x0005) = (uint8_t)(value35 << 1);
                    uint8_t value36 = RAM8(0x0005);
                    RAM8(0xE00A + x) = (uint8_t)((uint8_t)((uint8_t)(value35 << 2) + value36 + ((uint8_t)(value35 << 1) >> 7)) + 2);
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value35 << 2) + value36 + ((uint8_t)(value35 << 1) >> 7)) + 2));
                    r->c = (uint8_t)((uint8_t)(value35 << 2) + value36 + ((uint8_t)(value35 << 1) >> 7)) + 2 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value35 << 2) + value36 + ((uint8_t)(value35 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value35 << 2) + value36 + ((uint8_t)(value35 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value35 << 2) + value36 + ((uint8_t)(value35 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (m_ret10) {
                    RAM8(0x0005)++;
                    uint8_t value37 = RAM8(0x0005);
                    r->z = value37 == 0;
                    r->n = value37 & 0x80;
                    r->mf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB7F6, 0xC1B810); GUARD_JSR(c, sp_call, 0xB7F6); } /* probe_native_detour_tile_left */
                    bool carry_ret11 = r->c;
                    if (!carry_ret11) {
                        RAM8(0xE006 + x) = 0x83;
                        uint8_t value38 = RAM8(0x0005);
                        RAM8(0x0005) = (uint8_t)(value38 << 1);
                        uint8_t value39 = RAM8(0x0005);
                        RAM8(0xE00A + x) = (uint8_t)((uint8_t)((uint8_t)(value38 << 2) + value39 + ((uint8_t)(value38 << 1) >> 7)) + 2);
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value38 << 2) + value39 + ((uint8_t)(value38 << 1) >> 7)) + 2));
                        r->c = (uint8_t)((uint8_t)(value38 << 2) + value39 + ((uint8_t)(value38 << 1) >> 7)) + 2 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value38 << 2) + value39 + ((uint8_t)(value38 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value38 << 2) + value39 + ((uint8_t)(value38 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value38 << 2) + value39 + ((uint8_t)(value38 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    RAM16_SET(0x0005, (uint16_t)(RAM16(0x0005) + 1));
                    uint16_t value40 = RAM16(0x0005);
                    r->z = value40 == 0;
                    r->n = value40 & 0x8000;
                    r->mf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB7F6, 0xC1B810); GUARD_JSR(c, sp_call, 0xB7F6); } /* probe_native_detour_tile_left */
                    bool carry_ret12 = r->c;
                    if (!carry_ret12) {
                        RAM8(0xE006 + x) = 0x83;
                        uint8_t value41 = RAM8(0x0005);
                        RAM8(0x0005) = (uint8_t)(value41 << 1);
                        uint8_t value42 = RAM8(0x0005);
                        RAM8(0xE00A + x) = (uint8_t)((uint8_t)((uint8_t)(value41 << 2) + value42 + ((uint8_t)(value41 << 1) >> 7)) + 2);
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value41 << 2) + value42 + ((uint8_t)(value41 << 1) >> 7)) + 2));
                        r->c = (uint8_t)((uint8_t)(value41 << 2) + value42 + ((uint8_t)(value41 << 1) >> 7)) + 2 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value41 << 2) + value42 + ((uint8_t)(value41 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value41 << 2) + value42 + ((uint8_t)(value41 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value41 << 2) + value42 + ((uint8_t)(value41 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            } else {
                RAM16_SET(0x0005, (uint16_t)(RAM16(0x0005) + 1));
                uint16_t value43 = RAM16(0x0005);
                r->z = value43 == 0;
                r->n = value43 & 0x8000;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB7EF, 0xC1B810); GUARD_JSR(c, sp_call, 0xB7EF); } /* probe_native_detour_tile_left */
                bool m_ret13 = r->mf;
                bool carry_ret13 = r->c;
                if (!carry_ret13) {
                    RAM8(0xE006 + x) = 0x83;
                    uint8_t value44 = RAM8(0x0005);
                    RAM8(0x0005) = (uint8_t)(value44 << 1);
                    uint8_t value45 = RAM8(0x0005);
                    RAM8(0xE00A + x) = (uint8_t)((uint8_t)((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7)) + 2);
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7)) + 2));
                    r->c = (uint8_t)((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7)) + 2 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value44 << 2) + value45 + ((uint8_t)(value44 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (m_ret13) {
                    RAM8(0x0005)++;
                    uint8_t value46 = RAM8(0x0005);
                    r->z = value46 == 0;
                    r->n = value46 & 0x80;
                    r->mf = 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB7F6, 0xC1B810); GUARD_JSR(c, sp_call, 0xB7F6); } /* probe_native_detour_tile_left */
                    bool carry_ret14 = r->c;
                    if (!carry_ret14) {
                        RAM8(0xE006 + x) = 0x83;
                        uint8_t value47 = RAM8(0x0005);
                        RAM8(0x0005) = (uint8_t)(value47 << 1);
                        uint8_t value48 = RAM8(0x0005);
                        RAM8(0xE00A + x) = (uint8_t)((uint8_t)((uint8_t)(value47 << 2) + value48 + ((uint8_t)(value47 << 1) >> 7)) + 2);
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value47 << 2) + value48 + ((uint8_t)(value47 << 1) >> 7)) + 2));
                        r->c = (uint8_t)((uint8_t)(value47 << 2) + value48 + ((uint8_t)(value47 << 1) >> 7)) + 2 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value47 << 2) + value48 + ((uint8_t)(value47 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value47 << 2) + value48 + ((uint8_t)(value47 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value47 << 2) + value48 + ((uint8_t)(value47 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    RAM16_SET(0x0005, (uint16_t)(RAM16(0x0005) + 1));
                    uint16_t value49 = RAM16(0x0005);
                    r->z = value49 == 0;
                    r->n = value49 & 0x8000;
                    r->mf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0xB7F6, 0xC1B810); GUARD_JSR(c, sp_call, 0xB7F6); } /* probe_native_detour_tile_left */
                    bool carry_ret15 = r->c;
                    if (!carry_ret15) {
                        RAM8(0xE006 + x) = 0x83;
                        uint8_t value50 = RAM8(0x0005);
                        RAM8(0x0005) = (uint8_t)(value50 << 1);
                        uint8_t value51 = RAM8(0x0005);
                        RAM8(0xE00A + x) = (uint8_t)((uint8_t)((uint8_t)(value50 << 2) + value51 + ((uint8_t)(value50 << 1) >> 7)) + 2);
                        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value50 << 2) + value51 + ((uint8_t)(value50 << 1) >> 7)) + 2));
                        r->c = (uint8_t)((uint8_t)(value50 << 2) + value51 + ((uint8_t)(value50 << 1) >> 7)) + 2 > 0xFF;
                        r->v = (((uint8_t)((uint8_t)(value50 << 2) + value51 + ((uint8_t)(value50 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value50 << 2) + value51 + ((uint8_t)(value50 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value50 << 2) + value51 + ((uint8_t)(value50 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                        r->mf = 1;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
            }
        }
    }
    r->a = (a_hi << 8) | ((value7 ^ 1) >> 1);
    r->c = (value7 ^ 1) & 0x01;
    r->z = (value7 ^ 1) >> 1 == 0;
    r->n = (value7 ^ 1) >> 1 & 0x80;
    r->v = overflow3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB7C0, 0xC1B81E); GUARD_JSR(c, sp_call, 0xB7C0); } /* probe_native_detour_tile_right_with_shared_probe */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret16 = r->mf;
    bool carry_ret16 = r->c;
    if (!carry_ret16) {
        BUS8_SET(c, (db_ret << 0x10) + 0xE006 + x, 3);
        uint8_t value52 = BUS8_RDP(c, (uint16_t)(dp_ret + 5));
        BUS8_SET(c, (uint16_t)(dp_ret + 5), (uint8_t)(value52 << 1));
        uint8_t value53 = BUS8_RDP(c, (uint16_t)(dp_ret + 5));
        BUS8_SET(c, (db_ret << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value52 << 2) + value53 + ((uint8_t)(value52 << 1) >> 7)) + 2));
        SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value52 << 2) + value53 + ((uint8_t)(value52 << 1) >> 7)) + 2));
        r->c = (uint8_t)((uint8_t)(value52 << 2) + value53 + ((uint8_t)(value52 << 1) >> 7)) + 2 > 0xFF;
        r->v = (((uint8_t)((uint8_t)(value52 << 2) + value53 + ((uint8_t)(value52 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value52 << 2) + value53 + ((uint8_t)(value52 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value52 << 2) + value53 + ((uint8_t)(value52 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if (m_ret16) {
        uint8_t value54 = BUS8_RDP(c, (uint16_t)(dp_ret + 5));
        BUS8_SET(c, (uint16_t)(dp_ret + 5), (uint8_t)(value54 + 1));
        r->z = (uint8_t)(value54 + 1) == 0;
        r->n = (uint8_t)(value54 + 1) & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB7C7, 0xC1B81E); GUARD_JSR(c, sp_call, 0xB7C7); } /* probe_native_detour_tile_right_with_shared_probe */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret17 = r->mf;
        bool carry_ret17 = r->c;
        if (!carry_ret17) {
            BUS8_SET(c, (db_ret2 << 0x10) + 0xE006 + x, 3);
            uint8_t value55 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 5));
            BUS8_SET(c, (uint16_t)(dp_ret2 + 5), (uint8_t)(value55 << 1));
            uint8_t value56 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 5));
            BUS8_SET(c, (db_ret2 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value55 << 2) + value56 + ((uint8_t)(value55 << 1) >> 7)) + 2));
            SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value55 << 2) + value56 + ((uint8_t)(value55 << 1) >> 7)) + 2));
            r->c = (uint8_t)((uint8_t)(value55 << 2) + value56 + ((uint8_t)(value55 << 1) >> 7)) + 2 > 0xFF;
            r->v = (((uint8_t)((uint8_t)(value55 << 2) + value56 + ((uint8_t)(value55 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value55 << 2) + value56 + ((uint8_t)(value55 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value55 << 2) + value56 + ((uint8_t)(value55 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        if (m_ret17) {
            uint8_t value57 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 5));
            BUS8_SET(c, (uint16_t)(dp_ret2 + 5), (uint8_t)(value57 + 1));
            r->z = (uint8_t)(value57 + 1) == 0;
            r->n = (uint8_t)(value57 + 1) & 0x80;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB7CE, 0xC1B81E); GUARD_JSR(c, sp_call, 0xB7CE); } /* probe_native_detour_tile_right_with_shared_probe */
            uint16_t dp_ret3 = r->dp;
            uint8_t db_ret3 = r->db;
            bool m_ret18 = r->mf;
            bool carry_ret18 = r->c;
            if (!carry_ret18) {
                BUS8_SET(c, (db_ret3 << 0x10) + 0xE006 + x, 3);
                uint8_t value58 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret3 + 5), (uint8_t)(value58 << 1));
                uint8_t value59 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 5));
                BUS8_SET(c, (db_ret3 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value58 << 2) + value59 + ((uint8_t)(value58 << 1) >> 7)) + 2));
                SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value58 << 2) + value59 + ((uint8_t)(value58 << 1) >> 7)) + 2));
                r->c = (uint8_t)((uint8_t)(value58 << 2) + value59 + ((uint8_t)(value58 << 1) >> 7)) + 2 > 0xFF;
                r->v = (((uint8_t)((uint8_t)(value58 << 2) + value59 + ((uint8_t)(value58 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value58 << 2) + value59 + ((uint8_t)(value58 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value58 << 2) + value59 + ((uint8_t)(value58 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            if (m_ret18) {
                uint8_t value60 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret3 + 5), (uint8_t)(value60 + 1));
                r->z = (uint8_t)(value60 + 1) == 0;
                r->n = (uint8_t)(value60 + 1) & 0x80;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB7D5, 0xC1B81E); GUARD_JSR(c, sp_call, 0xB7D5); } /* probe_native_detour_tile_right_with_shared_probe */
                uint16_t dp_ret4 = r->dp;
                uint8_t db_ret4 = r->db;
                bool carry_ret19 = r->c;
                if (!carry_ret19) {
                    BUS8_SET(c, (db_ret4 << 0x10) + 0xE006 + x, 3);
                    uint8_t value61 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret4 + 5), (uint8_t)(value61 << 1));
                    uint8_t value62 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 5));
                    BUS8_SET(c, (db_ret4 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value61 << 2) + value62 + ((uint8_t)(value61 << 1) >> 7)) + 2));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value61 << 2) + value62 + ((uint8_t)(value61 << 1) >> 7)) + 2));
                    r->c = (uint8_t)((uint8_t)(value61 << 2) + value62 + ((uint8_t)(value61 << 1) >> 7)) + 2 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value61 << 2) + value62 + ((uint8_t)(value61 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value61 << 2) + value62 + ((uint8_t)(value61 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value61 << 2) + value62 + ((uint8_t)(value61 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value63 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 5));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 5), (uint16_t)(value63 + 1));
                r->z = (uint16_t)(value63 + 1) == 0;
                r->n = (uint16_t)(value63 + 1) & 0x8000;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB7D5, 0xC1B81E); GUARD_JSR(c, sp_call, 0xB7D5); } /* probe_native_detour_tile_right_with_shared_probe */
                uint16_t dp_ret5 = r->dp;
                uint8_t db_ret5 = r->db;
                bool carry_ret20 = r->c;
                if (!carry_ret20) {
                    BUS8_SET(c, (db_ret5 << 0x10) + 0xE006 + x, 3);
                    uint8_t value64 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret5 + 5), (uint8_t)(value64 << 1));
                    uint8_t value65 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 5));
                    BUS8_SET(c, (db_ret5 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value64 << 2) + value65 + ((uint8_t)(value64 << 1) >> 7)) + 2));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value64 << 2) + value65 + ((uint8_t)(value64 << 1) >> 7)) + 2));
                    r->c = (uint8_t)((uint8_t)(value64 << 2) + value65 + ((uint8_t)(value64 << 1) >> 7)) + 2 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value64 << 2) + value65 + ((uint8_t)(value64 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value64 << 2) + value65 + ((uint8_t)(value64 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value64 << 2) + value65 + ((uint8_t)(value64 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            uint16_t value66 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 5));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 5), (uint16_t)(value66 + 1));
            r->z = (uint16_t)(value66 + 1) == 0;
            r->n = (uint16_t)(value66 + 1) & 0x8000;
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB7CE, 0xC1B81E); GUARD_JSR(c, sp_call, 0xB7CE); } /* probe_native_detour_tile_right_with_shared_probe */
            uint16_t dp_ret6 = r->dp;
            uint8_t db_ret6 = r->db;
            bool m_ret21 = r->mf;
            bool carry_ret21 = r->c;
            if (!carry_ret21) {
                BUS8_SET(c, (db_ret6 << 0x10) + 0xE006 + x, 3);
                uint8_t value67 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret6 + 5), (uint8_t)(value67 << 1));
                uint8_t value68 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 5));
                BUS8_SET(c, (db_ret6 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value67 << 2) + value68 + ((uint8_t)(value67 << 1) >> 7)) + 2));
                SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value67 << 2) + value68 + ((uint8_t)(value67 << 1) >> 7)) + 2));
                r->c = (uint8_t)((uint8_t)(value67 << 2) + value68 + ((uint8_t)(value67 << 1) >> 7)) + 2 > 0xFF;
                r->v = (((uint8_t)((uint8_t)(value67 << 2) + value68 + ((uint8_t)(value67 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value67 << 2) + value68 + ((uint8_t)(value67 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value67 << 2) + value68 + ((uint8_t)(value67 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            if (m_ret21) {
                uint8_t value69 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret6 + 5), (uint8_t)(value69 + 1));
                r->z = (uint8_t)(value69 + 1) == 0;
                r->n = (uint8_t)(value69 + 1) & 0x80;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB7D5, 0xC1B81E); GUARD_JSR(c, sp_call, 0xB7D5); } /* probe_native_detour_tile_right_with_shared_probe */
                uint16_t dp_ret7 = r->dp;
                uint8_t db_ret7 = r->db;
                bool carry_ret22 = r->c;
                if (!carry_ret22) {
                    BUS8_SET(c, (db_ret7 << 0x10) + 0xE006 + x, 3);
                    uint8_t value70 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret7 + 5), (uint8_t)(value70 << 1));
                    uint8_t value71 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 5));
                    BUS8_SET(c, (db_ret7 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value70 << 2) + value71 + ((uint8_t)(value70 << 1) >> 7)) + 2));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value70 << 2) + value71 + ((uint8_t)(value70 << 1) >> 7)) + 2));
                    r->c = (uint8_t)((uint8_t)(value70 << 2) + value71 + ((uint8_t)(value70 << 1) >> 7)) + 2 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value70 << 2) + value71 + ((uint8_t)(value70 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value70 << 2) + value71 + ((uint8_t)(value70 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value70 << 2) + value71 + ((uint8_t)(value70 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value72 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 5));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret6 + 5), (uint16_t)(value72 + 1));
                r->z = (uint16_t)(value72 + 1) == 0;
                r->n = (uint16_t)(value72 + 1) & 0x8000;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB7D5, 0xC1B81E); GUARD_JSR(c, sp_call, 0xB7D5); } /* probe_native_detour_tile_right_with_shared_probe */
                uint16_t dp_ret8 = r->dp;
                uint8_t db_ret8 = r->db;
                bool carry_ret23 = r->c;
                if (!carry_ret23) {
                    BUS8_SET(c, (db_ret8 << 0x10) + 0xE006 + x, 3);
                    uint8_t value73 = BUS8_RDP(c, (uint16_t)(dp_ret8 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret8 + 5), (uint8_t)(value73 << 1));
                    uint8_t value74 = BUS8_RDP(c, (uint16_t)(dp_ret8 + 5));
                    BUS8_SET(c, (db_ret8 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value73 << 2) + value74 + ((uint8_t)(value73 << 1) >> 7)) + 2));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value73 << 2) + value74 + ((uint8_t)(value73 << 1) >> 7)) + 2));
                    r->c = (uint8_t)((uint8_t)(value73 << 2) + value74 + ((uint8_t)(value73 << 1) >> 7)) + 2 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value73 << 2) + value74 + ((uint8_t)(value73 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value73 << 2) + value74 + ((uint8_t)(value73 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value73 << 2) + value74 + ((uint8_t)(value73 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    } else {
        uint16_t value75 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret + 5), (uint16_t)(value75 + 1));
        r->z = (uint16_t)(value75 + 1) == 0;
        r->n = (uint16_t)(value75 + 1) & 0x8000;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB7C7, 0xC1B81E); GUARD_JSR(c, sp_call, 0xB7C7); } /* probe_native_detour_tile_right_with_shared_probe */
        uint16_t dp_ret9 = r->dp;
        uint8_t db_ret9 = r->db;
        bool m_ret24 = r->mf;
        bool carry_ret24 = r->c;
        if (!carry_ret24) {
            BUS8_SET(c, (db_ret9 << 0x10) + 0xE006 + x, 3);
            uint8_t value76 = BUS8_RDP(c, (uint16_t)(dp_ret9 + 5));
            BUS8_SET(c, (uint16_t)(dp_ret9 + 5), (uint8_t)(value76 << 1));
            uint8_t value77 = BUS8_RDP(c, (uint16_t)(dp_ret9 + 5));
            BUS8_SET(c, (db_ret9 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value76 << 2) + value77 + ((uint8_t)(value76 << 1) >> 7)) + 2));
            SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value76 << 2) + value77 + ((uint8_t)(value76 << 1) >> 7)) + 2));
            r->c = (uint8_t)((uint8_t)(value76 << 2) + value77 + ((uint8_t)(value76 << 1) >> 7)) + 2 > 0xFF;
            r->v = (((uint8_t)((uint8_t)(value76 << 2) + value77 + ((uint8_t)(value76 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value76 << 2) + value77 + ((uint8_t)(value76 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value76 << 2) + value77 + ((uint8_t)(value76 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        if (m_ret24) {
            uint8_t value78 = BUS8_RDP(c, (uint16_t)(dp_ret9 + 5));
            BUS8_SET(c, (uint16_t)(dp_ret9 + 5), (uint8_t)(value78 + 1));
            r->z = (uint8_t)(value78 + 1) == 0;
            r->n = (uint8_t)(value78 + 1) & 0x80;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB7CE, 0xC1B81E); GUARD_JSR(c, sp_call, 0xB7CE); } /* probe_native_detour_tile_right_with_shared_probe */
            uint16_t dp_ret10 = r->dp;
            uint8_t db_ret10 = r->db;
            bool m_ret25 = r->mf;
            bool carry_ret25 = r->c;
            if (!carry_ret25) {
                BUS8_SET(c, (db_ret10 << 0x10) + 0xE006 + x, 3);
                uint8_t value79 = BUS8_RDP(c, (uint16_t)(dp_ret10 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret10 + 5), (uint8_t)(value79 << 1));
                uint8_t value80 = BUS8_RDP(c, (uint16_t)(dp_ret10 + 5));
                BUS8_SET(c, (db_ret10 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value79 << 2) + value80 + ((uint8_t)(value79 << 1) >> 7)) + 2));
                SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value79 << 2) + value80 + ((uint8_t)(value79 << 1) >> 7)) + 2));
                r->c = (uint8_t)((uint8_t)(value79 << 2) + value80 + ((uint8_t)(value79 << 1) >> 7)) + 2 > 0xFF;
                r->v = (((uint8_t)((uint8_t)(value79 << 2) + value80 + ((uint8_t)(value79 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value79 << 2) + value80 + ((uint8_t)(value79 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value79 << 2) + value80 + ((uint8_t)(value79 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            if (m_ret25) {
                uint8_t value81 = BUS8_RDP(c, (uint16_t)(dp_ret10 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret10 + 5), (uint8_t)(value81 + 1));
                r->z = (uint8_t)(value81 + 1) == 0;
                r->n = (uint8_t)(value81 + 1) & 0x80;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB7D5, 0xC1B81E); GUARD_JSR(c, sp_call, 0xB7D5); } /* probe_native_detour_tile_right_with_shared_probe */
                uint16_t dp_ret11 = r->dp;
                uint8_t db_ret11 = r->db;
                bool carry_ret26 = r->c;
                if (!carry_ret26) {
                    BUS8_SET(c, (db_ret11 << 0x10) + 0xE006 + x, 3);
                    uint8_t value82 = BUS8_RDP(c, (uint16_t)(dp_ret11 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret11 + 5), (uint8_t)(value82 << 1));
                    uint8_t value83 = BUS8_RDP(c, (uint16_t)(dp_ret11 + 5));
                    BUS8_SET(c, (db_ret11 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value82 << 2) + value83 + ((uint8_t)(value82 << 1) >> 7)) + 2));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value82 << 2) + value83 + ((uint8_t)(value82 << 1) >> 7)) + 2));
                    r->c = (uint8_t)((uint8_t)(value82 << 2) + value83 + ((uint8_t)(value82 << 1) >> 7)) + 2 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value82 << 2) + value83 + ((uint8_t)(value82 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value82 << 2) + value83 + ((uint8_t)(value82 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value82 << 2) + value83 + ((uint8_t)(value82 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value84 = BUS16_RDP(c, (uint16_t)(dp_ret10 + 5));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret10 + 5), (uint16_t)(value84 + 1));
                r->z = (uint16_t)(value84 + 1) == 0;
                r->n = (uint16_t)(value84 + 1) & 0x8000;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB7D5, 0xC1B81E); GUARD_JSR(c, sp_call, 0xB7D5); } /* probe_native_detour_tile_right_with_shared_probe */
                uint16_t dp_ret12 = r->dp;
                uint8_t db_ret12 = r->db;
                bool carry_ret27 = r->c;
                if (!carry_ret27) {
                    BUS8_SET(c, (db_ret12 << 0x10) + 0xE006 + x, 3);
                    uint8_t value85 = BUS8_RDP(c, (uint16_t)(dp_ret12 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret12 + 5), (uint8_t)(value85 << 1));
                    uint8_t value86 = BUS8_RDP(c, (uint16_t)(dp_ret12 + 5));
                    BUS8_SET(c, (db_ret12 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value85 << 2) + value86 + ((uint8_t)(value85 << 1) >> 7)) + 2));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value85 << 2) + value86 + ((uint8_t)(value85 << 1) >> 7)) + 2));
                    r->c = (uint8_t)((uint8_t)(value85 << 2) + value86 + ((uint8_t)(value85 << 1) >> 7)) + 2 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value85 << 2) + value86 + ((uint8_t)(value85 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value85 << 2) + value86 + ((uint8_t)(value85 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value85 << 2) + value86 + ((uint8_t)(value85 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            uint16_t value87 = BUS16_RDP(c, (uint16_t)(dp_ret9 + 5));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret9 + 5), (uint16_t)(value87 + 1));
            r->z = (uint16_t)(value87 + 1) == 0;
            r->n = (uint16_t)(value87 + 1) & 0x8000;
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB7CE, 0xC1B81E); GUARD_JSR(c, sp_call, 0xB7CE); } /* probe_native_detour_tile_right_with_shared_probe */
            uint16_t dp_ret13 = r->dp;
            uint8_t db_ret13 = r->db;
            bool m_ret28 = r->mf;
            bool carry_ret28 = r->c;
            if (!carry_ret28) {
                BUS8_SET(c, (db_ret13 << 0x10) + 0xE006 + x, 3);
                uint8_t value88 = BUS8_RDP(c, (uint16_t)(dp_ret13 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret13 + 5), (uint8_t)(value88 << 1));
                uint8_t value89 = BUS8_RDP(c, (uint16_t)(dp_ret13 + 5));
                BUS8_SET(c, (db_ret13 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value88 << 2) + value89 + ((uint8_t)(value88 << 1) >> 7)) + 2));
                SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value88 << 2) + value89 + ((uint8_t)(value88 << 1) >> 7)) + 2));
                r->c = (uint8_t)((uint8_t)(value88 << 2) + value89 + ((uint8_t)(value88 << 1) >> 7)) + 2 > 0xFF;
                r->v = (((uint8_t)((uint8_t)(value88 << 2) + value89 + ((uint8_t)(value88 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value88 << 2) + value89 + ((uint8_t)(value88 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value88 << 2) + value89 + ((uint8_t)(value88 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            if (m_ret28) {
                uint8_t value90 = BUS8_RDP(c, (uint16_t)(dp_ret13 + 5));
                BUS8_SET(c, (uint16_t)(dp_ret13 + 5), (uint8_t)(value90 + 1));
                r->z = (uint8_t)(value90 + 1) == 0;
                r->n = (uint8_t)(value90 + 1) & 0x80;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB7D5, 0xC1B81E); GUARD_JSR(c, sp_call, 0xB7D5); } /* probe_native_detour_tile_right_with_shared_probe */
                uint16_t dp_ret14 = r->dp;
                uint8_t db_ret14 = r->db;
                bool carry_ret29 = r->c;
                if (!carry_ret29) {
                    BUS8_SET(c, (db_ret14 << 0x10) + 0xE006 + x, 3);
                    uint8_t value91 = BUS8_RDP(c, (uint16_t)(dp_ret14 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret14 + 5), (uint8_t)(value91 << 1));
                    uint8_t value92 = BUS8_RDP(c, (uint16_t)(dp_ret14 + 5));
                    BUS8_SET(c, (db_ret14 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value91 << 2) + value92 + ((uint8_t)(value91 << 1) >> 7)) + 2));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value91 << 2) + value92 + ((uint8_t)(value91 << 1) >> 7)) + 2));
                    r->c = (uint8_t)((uint8_t)(value91 << 2) + value92 + ((uint8_t)(value91 << 1) >> 7)) + 2 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value91 << 2) + value92 + ((uint8_t)(value91 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value91 << 2) + value92 + ((uint8_t)(value91 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value91 << 2) + value92 + ((uint8_t)(value91 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value93 = BUS16_RDP(c, (uint16_t)(dp_ret13 + 5));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret13 + 5), (uint16_t)(value93 + 1));
                r->z = (uint16_t)(value93 + 1) == 0;
                r->n = (uint16_t)(value93 + 1) & 0x8000;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0xB7D5, 0xC1B81E); GUARD_JSR(c, sp_call, 0xB7D5); } /* probe_native_detour_tile_right_with_shared_probe */
                uint16_t dp_ret15 = r->dp;
                uint8_t db_ret15 = r->db;
                bool carry_ret30 = r->c;
                if (!carry_ret30) {
                    BUS8_SET(c, (db_ret15 << 0x10) + 0xE006 + x, 3);
                    uint8_t value94 = BUS8_RDP(c, (uint16_t)(dp_ret15 + 5));
                    BUS8_SET(c, (uint16_t)(dp_ret15 + 5), (uint8_t)(value94 << 1));
                    uint8_t value95 = BUS8_RDP(c, (uint16_t)(dp_ret15 + 5));
                    BUS8_SET(c, (db_ret15 << 0x10) + 0xE00A + x, (uint8_t)((uint8_t)((uint8_t)(value94 << 2) + value95 + ((uint8_t)(value94 << 1) >> 7)) + 2));
                    SET_A8(r, (uint8_t)((uint8_t)((uint8_t)(value94 << 2) + value95 + ((uint8_t)(value94 << 1) >> 7)) + 2));
                    r->c = (uint8_t)((uint8_t)(value94 << 2) + value95 + ((uint8_t)(value94 << 1) >> 7)) + 2 > 0xFF;
                    r->v = (((uint8_t)((uint8_t)(value94 << 2) + value95 + ((uint8_t)(value94 << 1) >> 7)) ^ (uint8_t)((uint8_t)((uint8_t)(value94 << 2) + value95 + ((uint8_t)(value94 << 1) >> 7)) + 2)) & ((uint8_t)((uint8_t)((uint8_t)(value94 << 2) + value95 + ((uint8_t)(value94 << 1) >> 7)) + 2) ^ 2) & 0x80) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
}
SOM_REGISTER(0xC1B78D, SOM_RTS, "gen", search_native_horizontal_detour_after_vertical_motion, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 131, 66)
