#include "som_c.h"

/* C1B93E test_actor_signed_step_against_wrapped_terrain   [class B, 172 bytes, 90 instructions]
 * Source: src/rom/test_actor_signed_step_against_wrapped_terrain.s
 * Documented in docs/actor-map-terrain-queries.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void test_actor_signed_step_against_wrapped_terrain(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x001E);
    uint8_t a3;
    uint8_t a_hi3;
    if (value >= 0x80) {
        uint16_t value2 = RAM16(0x0012);
        uint8_t a1;
        uint8_t a_hi1;
        if (!((uint16_t)(((((a_hi << 8) | value) & 0x0F) ^ 0xFFFF) + value2 + 1) & 0x8000)) {
            a1 = (uint8_t)(((((a_hi << 8) | value) & 0x0F) ^ 0xFFFF) + value2 + 1);
            a_hi1 = (uint16_t)(((((a_hi << 8) | value) & 0x0F) ^ 0xFFFF) + value2 + 1) >> 8;
        } else {
            uint16_t value3 = RAM16(0x00C0);
            a1 = (uint8_t)((uint16_t)(((((a_hi << 8) | value) & 0x0F) ^ 0xFFFF) + value2 + 1) + value3);
            a_hi1 = (uint16_t)((uint16_t)(((((a_hi << 8) | value) & 0x0F) ^ 0xFFFF) + value2 + 1) + value3) >> 8;
        }
        a3 = a1;
        a_hi3 = a_hi1;
    } else {
        uint16_t value4 = RAM16(0x0012);
        uint16_t value5 = RAM16(0x00C0);
        uint8_t a2;
        uint8_t a_hi2;
        if ((uint16_t)((((a_hi << 8) | value) & 0x0F) + value4) < value5) {
            a2 = (uint8_t)((((a_hi << 8) | value) & 0x0F) + value4);
            a_hi2 = (uint16_t)((((a_hi << 8) | value) & 0x0F) + value4) >> 8;
        } else {
            a2 = (uint8_t)((uint16_t)((((a_hi << 8) | value) & 0x0F) + value4) - value5 - ((uint16_t)((((a_hi << 8) | value) & 0x0F) + value4) >= value5 ^ 1));
            a_hi2 = (uint16_t)((uint16_t)((((a_hi << 8) | value) & 0x0F) + value4) - value5 - ((uint16_t)((((a_hi << 8) | value) & 0x0F) + value4) >= value5 ^ 1)) >> 8;
        }
        a3 = a2;
        a_hi3 = a_hi2;
    }
    RAM16_SET(0x0008, ((a_hi3 << 8) | a3) >> 4);
    uint8_t value6 = RAM8(0x001F);
    uint8_t a6;
    uint8_t a_hi6;
    bool overflow3;
    if (value6 >= 0x80) {
        uint16_t value7 = RAM16(0x0014);
        uint8_t a4;
        uint8_t a_hi4;
        bool overflow1;
        if (!((uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) ^ 0xFFFF) + value7 + 1) & 0x8000)) {
            a4 = (uint8_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) ^ 0xFFFF) + value7 + 1);
            a_hi4 = (uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) ^ 0xFFFF) + value7 + 1) >> 8;
            overflow1 = (((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) ^ 0xFFFF ^ (uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) ^ 0xFFFF) + value7 + 1)) & (value7 ^ (uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) ^ 0xFFFF) + value7 + 1)) & 0x8000) != 0;
        } else {
            uint16_t value8 = RAM16(0x00C2);
            a4 = (uint8_t)((uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) ^ 0xFFFF) + value7 + 1) + value8);
            a_hi4 = (uint16_t)((uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) ^ 0xFFFF) + value7 + 1) + value8) >> 8;
            overflow1 = (((uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) ^ 0xFFFF) + value7 + 1) ^ (uint16_t)((uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) ^ 0xFFFF) + value7 + 1) + value8)) & (value8 ^ (uint16_t)((uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) ^ 0xFFFF) + value7 + 1) + value8)) & 0x8000) != 0;
        }
        a6 = a4;
        a_hi6 = a_hi4;
        overflow3 = overflow1;
    } else {
        uint16_t value9 = RAM16(0x0014);
        uint16_t value10 = RAM16(0x00C2);
        uint8_t a5;
        uint8_t a_hi5;
        bool overflow2;
        if ((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) + value9) < value10) {
            a5 = (uint8_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) + value9);
            a_hi5 = (uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) + value9) >> 8;
            overflow2 = (((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) ^ (uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) + value9)) & (value9 ^ (uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) + value9)) & 0x8000) != 0;
        } else {
            a5 = (uint8_t)((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) + value9) - value10 - ((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) + value9) >= value10 ^ 1));
            a_hi5 = (uint16_t)((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) + value9) - value10 - ((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) + value9) >= value10 ^ 1)) >> 8;
            overflow2 = (((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) + value9) ^ value10) & ((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) + value9) ^ (uint16_t)((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) + value9) - value10 - ((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value6) & 0x0F) + value9) >= value10 ^ 1))) & 0x8000) != 0;
        }
        a6 = a5;
        a_hi6 = a_hi5;
        overflow3 = overflow2;
    }
    uint16_t value12;
    BUS16_OK(c, (RAM8(0x000C) << 0x10) + RAM16(0x000A) + (((((a_hi6 << 8) | a6) & 0x0FF0) << 1 << 1 << 1) | RAM16(0x0008)), value12);
    RAM16_SET(0x0000, value12 & 0xFF);
    uint16_t value13 = RAM16(0x0010);
    if (RAM8(0x0000) < RAM8(0x004D)) {
        uint16_t value16;
        BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((value12 & 0xFF) << 1 << 1), value16);
        if ((value16 & 0x1000) == 0) {
            if (((uint8_t)value16 & 8) == 0) {
                r->a = value16 >> 8 << 8 | ((uint8_t)value16 & 8);
                r->y = (value12 & 0xFF) << 1 << 1;
                r->v = overflow3;
                JSR(c, 0xB9E8, 0xC1BBE3); /* resolve_actor_axis_or_diagonal_terrain_step */
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            r->a = (r->a & 0x00FF) | ((value16 >> 8) << 8);
            r->y = (value12 & 0xFF) << 1 << 1;
            r->c = 0;
            r->v = overflow3;
            RETURN_RTL(c);
        }
        if (value13 >= 0x0600) {
            r->a = (r->a & 0x00FF) | ((value16 >> 8) << 8);
            r->y = (value12 & 0xFF) << 1 << 1;
            r->c = 1;
            r->v = overflow3;
            RETURN_RTL(c);
        }
        uint8_t value17 = RAM8(0x00D0);
        uint8_t value18 = RAM8(0xE01C + value13);
        if ((value17 | value18) != 0) {
            r->a = (r->a & 0x00FF) | ((value16 >> 8) << 8);
            r->y = (value12 & 0xFF) << 1 << 1;
            r->c = 1;
            r->v = overflow3;
            RETURN_RTL(c);
        }
        if (((value17 | value18) & 8) == 0) {
            r->a = value16 >> 8 << 8 | ((value17 | value18) & 8);
            r->y = (value12 & 0xFF) << 1 << 1;
            r->v = overflow3;
            JSR(c, 0xB9E8, 0xC1BBE3); /* resolve_actor_axis_or_diagonal_terrain_step */
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        r->a = (r->a & 0x00FF) | ((value16 >> 8) << 8);
        r->y = (value12 & 0xFF) << 1 << 1;
        r->c = 0;
        r->v = overflow3;
        RETURN_RTL(c);
    }
    if (value13 >= 0x0600) {
        r->a = (r->a & 0x00FF) | (((value12 & 0xFF) << 1 << 1 >> 8) << 8);
        r->y = (value12 & 0xFF) << 1 << 1;
        r->c = 1;
        r->v = overflow3;
        RETURN_RTL(c);
    }
    if (RAM8(0xE02C + value13) != 0) {
        if (RAM8(0x00FF) != 0) {
            uint16_t value21;
            BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((value12 & 0xFF) << 1 << 1), value21);
            if ((value21 & 0x1000) == 0) {
                if (((uint8_t)value21 & 8) == 0) {
                    r->a = value21 >> 8 << 8 | ((uint8_t)value21 & 8);
                    r->y = (value12 & 0xFF) << 1 << 1;
                    r->v = overflow3;
                    JSR(c, 0xB9E8, 0xC1BBE3); /* resolve_actor_axis_or_diagonal_terrain_step */
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTL(c);
                }
                r->a = (r->a & 0x00FF) | ((value21 >> 8) << 8);
                r->y = (value12 & 0xFF) << 1 << 1;
                r->c = 0;
                r->v = overflow3;
                RETURN_RTL(c);
            }
            if (value13 >= 0x0600) {
                r->a = (r->a & 0x00FF) | ((value21 >> 8) << 8);
                r->y = (value12 & 0xFF) << 1 << 1;
                r->c = 1;
                r->v = overflow3;
                RETURN_RTL(c);
            }
            uint8_t value22 = RAM8(0x00D0);
            uint8_t value23 = RAM8(0xE01C + value13);
            if ((value22 | value23) != 0) {
                r->a = (r->a & 0x00FF) | ((value21 >> 8) << 8);
                r->y = (value12 & 0xFF) << 1 << 1;
                r->c = 1;
                r->v = overflow3;
                RETURN_RTL(c);
            }
            if (((value22 | value23) & 8) == 0) {
                r->a = value21 >> 8 << 8 | ((value22 | value23) & 8);
                r->y = (value12 & 0xFF) << 1 << 1;
                r->v = overflow3;
                JSR(c, 0xB9E8, 0xC1BBE3); /* resolve_actor_axis_or_diagonal_terrain_step */
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            r->a = (r->a & 0x00FF) | ((value21 >> 8) << 8);
            r->y = (value12 & 0xFF) << 1 << 1;
            r->c = 0;
            r->v = overflow3;
            RETURN_RTL(c);
        }
        uint8_t value24 = RAM8(0x00D0);
        uint8_t value25 = RAM8(0xE01C + value13);
        if ((value24 | value25) != 0) {
            r->a = (r->a & 0x00FF) | (((value12 & 0xFF) << 1 << 1 >> 8) << 8);
            r->y = (value12 & 0xFF) << 1 << 1;
            r->c = 1;
            r->v = overflow3;
            RETURN_RTL(c);
        }
        uint16_t value26;
        BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((value12 & 0xFF) << 1 << 1), value26);
        if ((value26 & 0x1000) == 0) {
            if (((uint8_t)value26 & 8) == 0) {
                r->a = value26 >> 8 << 8 | ((uint8_t)value26 & 8);
                r->y = (value12 & 0xFF) << 1 << 1;
                r->v = overflow3;
                JSR(c, 0xB9E8, 0xC1BBE3); /* resolve_actor_axis_or_diagonal_terrain_step */
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            r->a = (r->a & 0x00FF) | ((value26 >> 8) << 8);
            r->y = (value12 & 0xFF) << 1 << 1;
            r->c = 0;
            r->v = overflow3;
            RETURN_RTL(c);
        }
        if (value13 >= 0x0600) {
            r->a = (r->a & 0x00FF) | ((value26 >> 8) << 8);
            r->y = (value12 & 0xFF) << 1 << 1;
            r->c = 1;
            r->v = overflow3;
            RETURN_RTL(c);
        }
        if ((value24 | value25) != 0) {
            r->a = (r->a & 0x00FF) | ((value26 >> 8) << 8);
            r->y = (value12 & 0xFF) << 1 << 1;
            r->c = 1;
            r->v = overflow3;
            RETURN_RTL(c);
        }
        if (((value24 | value25) & 8) == 0) {
            r->a = value26 >> 8 << 8 | ((value24 | value25) & 8);
            r->y = (value12 & 0xFF) << 1 << 1;
            r->v = overflow3;
            JSR(c, 0xB9E8, 0xC1BBE3); /* resolve_actor_axis_or_diagonal_terrain_step */
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        r->a = (r->a & 0x00FF) | ((value26 >> 8) << 8);
        r->y = (value12 & 0xFF) << 1 << 1;
        r->c = 0;
        r->v = overflow3;
        RETURN_RTL(c);
    }
    uint16_t value27;
    BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((value12 & 0xFF) << 1 << 1), value27);
    if ((value27 & 0x4000) != 0) {
        uint16_t value28;
        BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((value12 & 0xFF) << 1 << 1), value28);
        if ((value28 & 0x1000) == 0) {
            if (((uint8_t)value28 & 8) == 0) {
                r->a = value28 >> 8 << 8 | ((uint8_t)value28 & 8);
                r->y = (value12 & 0xFF) << 1 << 1;
                r->v = overflow3;
                JSR(c, 0xB9E8, 0xC1BBE3); /* resolve_actor_axis_or_diagonal_terrain_step */
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            r->a = (r->a & 0x00FF) | ((value28 >> 8) << 8);
            r->y = (value12 & 0xFF) << 1 << 1;
            r->c = 0;
            r->v = overflow3;
            RETURN_RTL(c);
        }
        if (value13 >= 0x0600) {
            r->a = (r->a & 0x00FF) | ((value28 >> 8) << 8);
            r->y = (value12 & 0xFF) << 1 << 1;
            r->c = 1;
            r->v = overflow3;
            RETURN_RTL(c);
        }
        uint8_t value29 = RAM8(0x00D0);
        uint8_t value30 = RAM8(0xE01C + value13);
        if ((value29 | value30) != 0) {
            r->a = (r->a & 0x00FF) | ((value28 >> 8) << 8);
            r->y = (value12 & 0xFF) << 1 << 1;
            r->c = 1;
            r->v = overflow3;
            RETURN_RTL(c);
        }
        if (((value29 | value30) & 8) == 0) {
            r->a = value28 >> 8 << 8 | ((value29 | value30) & 8);
            r->y = (value12 & 0xFF) << 1 << 1;
            r->v = overflow3;
            JSR(c, 0xB9E8, 0xC1BBE3); /* resolve_actor_axis_or_diagonal_terrain_step */
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        r->a = (r->a & 0x00FF) | ((value28 >> 8) << 8);
        r->y = (value12 & 0xFF) << 1 << 1;
        r->c = 0;
        r->v = overflow3;
        RETURN_RTL(c);
    }
    r->a = value27;
    r->y = (value12 & 0xFF) << 1 << 1;
    r->c = 1;
    r->v = overflow3;
    r->mf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1B93E, SOM_RTL, "hand", test_actor_signed_step_against_wrapped_terrain, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 172, 90)
