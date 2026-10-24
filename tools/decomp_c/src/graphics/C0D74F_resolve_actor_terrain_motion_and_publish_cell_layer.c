#include "som_c.h"

/* C0D74F resolve_actor_terrain_motion_and_publish_cell_layer   [class C, 321 bytes, 163 instructions]
 * Source: src/rom/resolve_actor_terrain_motion_and_publish_cell_layer.s
 * Documented in docs/map-motion-shared.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void resolve_actor_terrain_motion_and_publish_cell_layer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_hi_d7aa = 0;
    uint16_t y_d7aa = 0;
    bool carry_d7aa = 0;
    bool overflow_d7aa = 0;
    uint8_t a_hi_d7a7 = 0;
    uint8_t a_hi_d792 = 0;
    uint16_t y_d792 = 0;
    bool carry_d792 = 0;
    bool overflow_d792 = 0;
    RAM8(0x000F) = 0x7F;
    RAM8(0x000C) = 0x7F;
    if (RAM8(0x001B) & 0x80) {
        RAM16_SET(0x000A, 0x4000);
        RAM16_SET(0x000D, 0xBC00);
    } else {
        RAM16_SET(0x000A, 0);
        RAM16_SET(0x000D, 0xB800);
    }
    RAM16_SET(0x001C, 0);
    uint8_t value2 = RAM8(0x0011);
    if (value2 >= 6) {
        a_hi_d7aa = a_hi;
        y_d7aa = y;
        carry_d7aa = value2 >= 6;
        overflow_d7aa = overflow;
        goto shared_D7AA;
    }
    uint8_t value3 = RAM8(0xCF01);
    if (value3 & 0x01) {
        a_hi_d7a7 = a_hi;
        goto shared_D7A7;
    }
    if ((RAM8(0x00FF) & 0x20) == 0) {
        a_hi_d792 = a_hi;
        y_d792 = y;
        carry_d792 = value3 & 0x01;
        overflow_d792 = overflow;
        goto shared_D792;
    }
    uint8_t value5 = RAM8(0x00E1);
    if (value5 < 5) {
        a_hi_d7a7 = a_hi;
        goto shared_D7A7;
    }
    a_hi_d792 = a_hi;
    y_d792 = y;
    carry_d792 = value5 >= 5;
    overflow_d792 = overflow;
    shared_D792:;
    if ((RAM8(0x00F1) | RAM8(0x004E)) & 0x80) {
        a_hi_d7a7 = a_hi_d792;
        goto shared_D7A7;
    }
    if (RAM8(0x00D0) == 0) {
        a_hi_d7aa = a_hi_d792;
        y_d7aa = y_d792;
        carry_d7aa = carry_d792;
        overflow_d7aa = overflow_d792;
        goto shared_D7AA;
    }
    if (!((RAM8(0xE00E) | RAM8(0xE20E) | RAM8(0xE40E)) & 0x80)) {
        a_hi_d7aa = a_hi_d792;
        y_d7aa = y_d792;
        carry_d7aa = carry_d792;
        overflow_d7aa = overflow_d792;
        goto shared_D7AA;
    }
    a_hi_d7a7 = a_hi_d792;
    goto shared_D7A7;
    shared_D7AA:;
    r->a = (a_hi_d7aa << 8) | a;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    JSL(c, 0xD7AD, 0xC1B93E); /* test_actor_signed_step_against_wrapped_terrain */
    uint16_t a_all = r->a;
    bool carry_ret = r->c;
    if (!carry_ret) {
        uint8_t value6 = RAM8(0x0011);
        if (value6 >= 6) {
            uint8_t value7 = RAM8(0x001E);
            uint8_t a3;
            uint8_t a_hi3;
            if (value7 >= 0x80) {
                uint16_t value8 = RAM16(0x0012);
                uint8_t a1;
                uint8_t a_hi1;
                if (!((uint16_t)(((((a_all >> 8 << 8) | value7) & 0x7F) ^ 0xFFFF) + value8 + 1) & 0x8000)) {
                    a1 = (uint8_t)(((((a_all >> 8 << 8) | value7) & 0x7F) ^ 0xFFFF) + value8 + 1);
                    a_hi1 = (uint16_t)(((((a_all >> 8 << 8) | value7) & 0x7F) ^ 0xFFFF) + value8 + 1) >> 8;
                } else {
                    uint16_t value9 = RAM16(0x00C0);
                    a1 = (uint8_t)((uint16_t)(((((a_all >> 8 << 8) | value7) & 0x7F) ^ 0xFFFF) + value8 + 1) + value9);
                    a_hi1 = (uint16_t)((uint16_t)(((((a_all >> 8 << 8) | value7) & 0x7F) ^ 0xFFFF) + value8 + 1) + value9) >> 8;
                }
                a3 = a1;
                a_hi3 = a_hi1;
            } else {
                uint16_t value10 = RAM16(0x0012);
                uint16_t value11 = RAM16(0x00C0);
                uint8_t a2;
                uint8_t a_hi2;
                if ((uint16_t)((((a_all >> 8 << 8) | value7) & 0x7F) + value10) < value11) {
                    a2 = (uint8_t)((((a_all >> 8 << 8) | value7) & 0x7F) + value10);
                    a_hi2 = (uint16_t)((((a_all >> 8 << 8) | value7) & 0x7F) + value10) >> 8;
                } else {
                    a2 = (uint8_t)((uint16_t)((((a_all >> 8 << 8) | value7) & 0x7F) + value10) - value11 - ((uint16_t)((((a_all >> 8 << 8) | value7) & 0x7F) + value10) >= value11 ^ 1));
                    a_hi2 = (uint16_t)((uint16_t)((((a_all >> 8 << 8) | value7) & 0x7F) + value10) - value11 - ((uint16_t)((((a_all >> 8 << 8) | value7) & 0x7F) + value10) >= value11 ^ 1)) >> 8;
                }
                a3 = a2;
                a_hi3 = a_hi2;
            }
            RAM16_SET(0x0008, ((a_hi3 << 8) | a3) >> 4);
            uint8_t value12 = RAM8(0x001F);
            uint8_t a6;
            uint8_t a_hi6;
            bool overflow3;
            if (value12 >= 0x80) {
                uint16_t value13 = RAM16(0x0014);
                uint8_t a4;
                uint8_t a_hi4;
                bool overflow1;
                if (!((uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) ^ 0xFFFF) + value13 + 1) & 0x8000)) {
                    a4 = (uint8_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) ^ 0xFFFF) + value13 + 1);
                    a_hi4 = (uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) ^ 0xFFFF) + value13 + 1) >> 8;
                    overflow1 = (((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) ^ 0xFFFF ^ (uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) ^ 0xFFFF) + value13 + 1)) & (value13 ^ (uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) ^ 0xFFFF) + value13 + 1)) & 0x8000) != 0;
                } else {
                    uint16_t value14 = RAM16(0x00C2);
                    a4 = (uint8_t)((uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) ^ 0xFFFF) + value13 + 1) + value14);
                    a_hi4 = (uint16_t)((uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) ^ 0xFFFF) + value13 + 1) + value14) >> 8;
                    overflow1 = (((uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) ^ 0xFFFF) + value13 + 1) ^ (uint16_t)((uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) ^ 0xFFFF) + value13 + 1) + value14)) & (value14 ^ (uint16_t)((uint16_t)(((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) ^ 0xFFFF) + value13 + 1) + value14)) & 0x8000) != 0;
                }
                a6 = a4;
                a_hi6 = a_hi4;
                overflow3 = overflow1;
            } else {
                uint16_t value15 = RAM16(0x0014);
                uint16_t value16 = RAM16(0x00C2);
                uint8_t a5;
                uint8_t a_hi5;
                bool overflow2;
                if ((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) + value15) < value16) {
                    a5 = (uint8_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) + value15);
                    a_hi5 = (uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) + value15) >> 8;
                    overflow2 = (((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) ^ (uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) + value15)) & (value15 ^ (uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) + value15)) & 0x8000) != 0;
                } else {
                    a5 = (uint8_t)((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) + value15) - value16 - ((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) + value15) >= value16 ^ 1));
                    a_hi5 = (uint16_t)((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) + value15) - value16 - ((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) + value15) >= value16 ^ 1)) >> 8;
                    overflow2 = (((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) + value15) ^ value16) & ((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) + value15) ^ (uint16_t)((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) + value15) - value16 - ((uint16_t)((((((a_hi3 << 8) | a3) >> 4 >> 8 << 8) | value12) & 0x7F) + value15) >= value16 ^ 1))) & 0x8000) != 0;
                }
                a6 = a5;
                a_hi6 = a_hi5;
                overflow3 = overflow2;
            }
            uint16_t value17 = RAM16(0x0008);
            RAM16_SET(0x0008, ((((a_hi6 << 8) | a6) & 0x0FF0) << 1 << 1 << 1) | value17);
            uint16_t value18;
            BUS16_OK(c, (RAM8(0x000C) << 0x10) + RAM16(0x000A) + (((((a_hi6 << 8) | a6) & 0x0FF0) << 1 << 1 << 1) | value17), value18);
            RAM16_SET(0x0006, value18 & 0xFF);
            uint16_t value19;
            BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((value18 & 0xFF) << 1 << 1), value19);
            RAM16_SET(0x0000, value19);
            uint16_t value20;
            BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + (((value18 & 0xFF) << 1 << 1) + 2), value20);
            RAM16_SET(0x0004, value20);
            uint8_t value21 = RAM8(0x0000);
            if ((value21 & 8) == 0) {
                uint8_t a7;
                if ((value21 & 7) < 3) {
                    RAM8(0x0000) = value21 & 7;
                    a7 = (RAM8(0x001B) & 0xF0) | RAM8(0x0000);
                } else {
                    a7 = RAM8(0x001B) & 0xF7;
                }
                RAM8(0x001B) = a7;
            } else {
                uint8_t value25 = RAM8(0x001B);
                if ((value21 & 8 & value25) == 0) {
                    RAM8(0x001B) = (value25 ^ 0x88) & 0xF8;
                }
            }
            r->a = (r->a & 0x00FF) | ((value20 >> 8) << 8);
            r->y = ((value18 & 0xFF) << 1 << 1) + 2;
            r->c = 0;
            r->v = overflow3;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if (RAM8(0x001C) == 0) {
            if (RAM8(0x001D) == 0) {
                uint8_t value28 = RAM8(0x001E);
                uint8_t a10;
                uint8_t a_hi9;
                if (value28 >= 0x80) {
                    uint16_t value29 = RAM16(0x0012);
                    uint8_t a8;
                    uint8_t a_hi7;
                    if (!((uint16_t)(((((a_all >> 8 << 8) | value28) & 0x7F) ^ 0xFFFF) + value29 + 1) & 0x8000)) {
                        a8 = (uint8_t)(((((a_all >> 8 << 8) | value28) & 0x7F) ^ 0xFFFF) + value29 + 1);
                        a_hi7 = (uint16_t)(((((a_all >> 8 << 8) | value28) & 0x7F) ^ 0xFFFF) + value29 + 1) >> 8;
                    } else {
                        uint16_t value30 = RAM16(0x00C0);
                        a8 = (uint8_t)((uint16_t)(((((a_all >> 8 << 8) | value28) & 0x7F) ^ 0xFFFF) + value29 + 1) + value30);
                        a_hi7 = (uint16_t)((uint16_t)(((((a_all >> 8 << 8) | value28) & 0x7F) ^ 0xFFFF) + value29 + 1) + value30) >> 8;
                    }
                    a10 = a8;
                    a_hi9 = a_hi7;
                } else {
                    uint16_t value31 = RAM16(0x0012);
                    uint16_t value32 = RAM16(0x00C0);
                    uint8_t a9;
                    uint8_t a_hi8;
                    if ((uint16_t)((((a_all >> 8 << 8) | value28) & 0x7F) + value31) < value32) {
                        a9 = (uint8_t)((((a_all >> 8 << 8) | value28) & 0x7F) + value31);
                        a_hi8 = (uint16_t)((((a_all >> 8 << 8) | value28) & 0x7F) + value31) >> 8;
                    } else {
                        a9 = (uint8_t)((uint16_t)((((a_all >> 8 << 8) | value28) & 0x7F) + value31) - value32 - ((uint16_t)((((a_all >> 8 << 8) | value28) & 0x7F) + value31) >= value32 ^ 1));
                        a_hi8 = (uint16_t)((uint16_t)((((a_all >> 8 << 8) | value28) & 0x7F) + value31) - value32 - ((uint16_t)((((a_all >> 8 << 8) | value28) & 0x7F) + value31) >= value32 ^ 1)) >> 8;
                    }
                    a10 = a9;
                    a_hi9 = a_hi8;
                }
                RAM16_SET(0x0008, ((a_hi9 << 8) | a10) >> 4);
                uint8_t value33 = RAM8(0x001F);
                uint8_t a13;
                uint8_t a_hi12;
                bool overflow6;
                if (value33 >= 0x80) {
                    uint16_t value34 = RAM16(0x0014);
                    uint8_t a11;
                    uint8_t a_hi10;
                    bool overflow4;
                    if (!((uint16_t)(((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) ^ 0xFFFF) + value34 + 1) & 0x8000)) {
                        a11 = (uint8_t)(((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) ^ 0xFFFF) + value34 + 1);
                        a_hi10 = (uint16_t)(((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) ^ 0xFFFF) + value34 + 1) >> 8;
                        overflow4 = (((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) ^ 0xFFFF ^ (uint16_t)(((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) ^ 0xFFFF) + value34 + 1)) & (value34 ^ (uint16_t)(((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) ^ 0xFFFF) + value34 + 1)) & 0x8000) != 0;
                    } else {
                        uint16_t value35 = RAM16(0x00C2);
                        a11 = (uint8_t)((uint16_t)(((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) ^ 0xFFFF) + value34 + 1) + value35);
                        a_hi10 = (uint16_t)((uint16_t)(((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) ^ 0xFFFF) + value34 + 1) + value35) >> 8;
                        overflow4 = (((uint16_t)(((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) ^ 0xFFFF) + value34 + 1) ^ (uint16_t)((uint16_t)(((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) ^ 0xFFFF) + value34 + 1) + value35)) & (value35 ^ (uint16_t)((uint16_t)(((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) ^ 0xFFFF) + value34 + 1) + value35)) & 0x8000) != 0;
                    }
                    a13 = a11;
                    a_hi12 = a_hi10;
                    overflow6 = overflow4;
                } else {
                    uint16_t value36 = RAM16(0x0014);
                    uint16_t value37 = RAM16(0x00C2);
                    uint8_t a12;
                    uint8_t a_hi11;
                    bool overflow5;
                    if ((uint16_t)((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) + value36) < value37) {
                        a12 = (uint8_t)((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) + value36);
                        a_hi11 = (uint16_t)((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) + value36) >> 8;
                        overflow5 = (((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) ^ (uint16_t)((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) + value36)) & (value36 ^ (uint16_t)((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) + value36)) & 0x8000) != 0;
                    } else {
                        a12 = (uint8_t)((uint16_t)((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) + value36) - value37 - ((uint16_t)((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) + value36) >= value37 ^ 1));
                        a_hi11 = (uint16_t)((uint16_t)((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) + value36) - value37 - ((uint16_t)((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) + value36) >= value37 ^ 1)) >> 8;
                        overflow5 = (((uint16_t)((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) + value36) ^ value37) & ((uint16_t)((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) + value36) ^ (uint16_t)((uint16_t)((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) + value36) - value37 - ((uint16_t)((((((a_hi9 << 8) | a10) >> 4 >> 8 << 8) | value33) & 0x7F) + value36) >= value37 ^ 1))) & 0x8000) != 0;
                    }
                    a13 = a12;
                    a_hi12 = a_hi11;
                    overflow6 = overflow5;
                }
                uint16_t value38 = RAM16(0x0008);
                RAM16_SET(0x0008, ((((a_hi12 << 8) | a13) & 0x0FF0) << 1 << 1 << 1) | value38);
                uint16_t value39;
                BUS16_OK(c, (RAM8(0x000C) << 0x10) + RAM16(0x000A) + (((((a_hi12 << 8) | a13) & 0x0FF0) << 1 << 1 << 1) | value38), value39);
                RAM16_SET(0x0006, value39 & 0xFF);
                uint16_t value40;
                BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((value39 & 0xFF) << 1 << 1), value40);
                RAM16_SET(0x0000, value40);
                uint16_t value41;
                BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + (((value39 & 0xFF) << 1 << 1) + 2), value41);
                RAM16_SET(0x0004, value41);
                uint8_t value42 = RAM8(0x0000);
                if ((value42 & 8) == 0) {
                    uint8_t a14;
                    if ((value42 & 7) < 3) {
                        RAM8(0x0000) = value42 & 7;
                        a14 = (RAM8(0x001B) & 0xF0) | RAM8(0x0000);
                    } else {
                        a14 = RAM8(0x001B) & 0xF7;
                    }
                    RAM8(0x001B) = a14;
                } else {
                    uint8_t value46 = RAM8(0x001B);
                    if ((value42 & 8 & value46) == 0) {
                        RAM8(0x001B) = (value46 ^ 0x88) & 0xF8;
                    }
                }
                r->a = (r->a & 0x00FF) | ((value41 >> 8) << 8);
                r->y = ((value39 & 0xFF) << 1 << 1) + 2;
                r->c = 0;
                r->v = overflow6;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t value47 = RAM8(0x001F);
            if (value47 == 0) {
                uint8_t value48 = RAM8(0x001E);
                uint8_t a17;
                uint8_t a_hi15;
                if (value48 >= 0x80) {
                    uint16_t value49 = RAM16(0x0012);
                    uint8_t a15;
                    uint8_t a_hi13;
                    if (!((uint16_t)(((((a_all >> 8 << 8) | value48) & 0x7F) ^ 0xFFFF) + value49 + 1) & 0x8000)) {
                        a15 = (uint8_t)(((((a_all >> 8 << 8) | value48) & 0x7F) ^ 0xFFFF) + value49 + 1);
                        a_hi13 = (uint16_t)(((((a_all >> 8 << 8) | value48) & 0x7F) ^ 0xFFFF) + value49 + 1) >> 8;
                    } else {
                        uint16_t value50 = RAM16(0x00C0);
                        a15 = (uint8_t)((uint16_t)(((((a_all >> 8 << 8) | value48) & 0x7F) ^ 0xFFFF) + value49 + 1) + value50);
                        a_hi13 = (uint16_t)((uint16_t)(((((a_all >> 8 << 8) | value48) & 0x7F) ^ 0xFFFF) + value49 + 1) + value50) >> 8;
                    }
                    a17 = a15;
                    a_hi15 = a_hi13;
                } else {
                    uint16_t value51 = RAM16(0x0012);
                    uint16_t value52 = RAM16(0x00C0);
                    uint8_t a16;
                    uint8_t a_hi14;
                    if ((uint16_t)((((a_all >> 8 << 8) | value48) & 0x7F) + value51) < value52) {
                        a16 = (uint8_t)((((a_all >> 8 << 8) | value48) & 0x7F) + value51);
                        a_hi14 = (uint16_t)((((a_all >> 8 << 8) | value48) & 0x7F) + value51) >> 8;
                    } else {
                        a16 = (uint8_t)((uint16_t)((((a_all >> 8 << 8) | value48) & 0x7F) + value51) - value52 - ((uint16_t)((((a_all >> 8 << 8) | value48) & 0x7F) + value51) >= value52 ^ 1));
                        a_hi14 = (uint16_t)((uint16_t)((((a_all >> 8 << 8) | value48) & 0x7F) + value51) - value52 - ((uint16_t)((((a_all >> 8 << 8) | value48) & 0x7F) + value51) >= value52 ^ 1)) >> 8;
                    }
                    a17 = a16;
                    a_hi15 = a_hi14;
                }
                RAM16_SET(0x0008, ((a_hi15 << 8) | a17) >> 4);
                uint8_t a20;
                uint8_t a_hi18;
                bool overflow9;
                if (value47 >= 0x80) {
                    uint16_t value53 = RAM16(0x0014);
                    uint8_t a18;
                    uint8_t a_hi16;
                    bool overflow7;
                    if (!((uint16_t)(((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) ^ 0xFFFF) + value53 + 1) & 0x8000)) {
                        a18 = (uint8_t)(((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) ^ 0xFFFF) + value53 + 1);
                        a_hi16 = (uint16_t)(((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) ^ 0xFFFF) + value53 + 1) >> 8;
                        overflow7 = (((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) ^ 0xFFFF ^ (uint16_t)(((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) ^ 0xFFFF) + value53 + 1)) & (value53 ^ (uint16_t)(((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) ^ 0xFFFF) + value53 + 1)) & 0x8000) != 0;
                    } else {
                        uint16_t value54 = RAM16(0x00C2);
                        a18 = (uint8_t)((uint16_t)(((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) ^ 0xFFFF) + value53 + 1) + value54);
                        a_hi16 = (uint16_t)((uint16_t)(((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) ^ 0xFFFF) + value53 + 1) + value54) >> 8;
                        overflow7 = (((uint16_t)(((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) ^ 0xFFFF) + value53 + 1) ^ (uint16_t)((uint16_t)(((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) ^ 0xFFFF) + value53 + 1) + value54)) & (value54 ^ (uint16_t)((uint16_t)(((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) ^ 0xFFFF) + value53 + 1) + value54)) & 0x8000) != 0;
                    }
                    a20 = a18;
                    a_hi18 = a_hi16;
                    overflow9 = overflow7;
                } else {
                    uint16_t value55 = RAM16(0x0014);
                    uint16_t value56 = RAM16(0x00C2);
                    uint8_t a19;
                    uint8_t a_hi17;
                    bool overflow8;
                    if ((uint16_t)((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) + value55) < value56) {
                        a19 = (uint8_t)((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) + value55);
                        a_hi17 = (uint16_t)((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) + value55) >> 8;
                        overflow8 = (((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) ^ (uint16_t)((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) + value55)) & (value55 ^ (uint16_t)((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) + value55)) & 0x8000) != 0;
                    } else {
                        a19 = (uint8_t)((uint16_t)((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) + value55) - value56 - ((uint16_t)((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) + value55) >= value56 ^ 1));
                        a_hi17 = (uint16_t)((uint16_t)((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) + value55) - value56 - ((uint16_t)((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) + value55) >= value56 ^ 1)) >> 8;
                        overflow8 = (((uint16_t)((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) + value55) ^ value56) & ((uint16_t)((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) + value55) ^ (uint16_t)((uint16_t)((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) + value55) - value56 - ((uint16_t)((((((a_hi15 << 8) | a17) >> 4 >> 8 << 8) | value47) & 0x7F) + value55) >= value56 ^ 1))) & 0x8000) != 0;
                    }
                    a20 = a19;
                    a_hi18 = a_hi17;
                    overflow9 = overflow8;
                }
                uint16_t value57 = RAM16(0x0008);
                RAM16_SET(0x0008, ((((a_hi18 << 8) | a20) & 0x0FF0) << 1 << 1 << 1) | value57);
                uint16_t value58;
                BUS16_OK(c, (RAM8(0x000C) << 0x10) + RAM16(0x000A) + (((((a_hi18 << 8) | a20) & 0x0FF0) << 1 << 1 << 1) | value57), value58);
                RAM16_SET(0x0006, value58 & 0xFF);
                uint16_t value59;
                BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((value58 & 0xFF) << 1 << 1), value59);
                RAM16_SET(0x0000, value59);
                uint16_t value60;
                BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + (((value58 & 0xFF) << 1 << 1) + 2), value60);
                RAM16_SET(0x0004, value60);
                uint8_t value61 = RAM8(0x0000);
                if ((value61 & 8) == 0) {
                    uint8_t a21;
                    if ((value61 & 7) < 3) {
                        RAM8(0x0000) = value61 & 7;
                        a21 = (RAM8(0x001B) & 0xF0) | RAM8(0x0000);
                    } else {
                        a21 = RAM8(0x001B) & 0xF7;
                    }
                    RAM8(0x001B) = a21;
                } else {
                    uint8_t value65 = RAM8(0x001B);
                    if ((value61 & 8 & value65) == 0) {
                        RAM8(0x001B) = (value65 ^ 0x88) & 0xF8;
                    }
                }
                r->a = (r->a & 0x00FF) | ((value60 >> 8) << 8);
                r->y = ((value58 & 0xFF) << 1 << 1) + 2;
                r->c = 0;
                r->v = overflow9;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t value66 = RAM8(0x001E);
            RAM8(0x001D) = value66;
            RAM8(0x001E) = 0;
            r->a = (a_all >> 8 << 8) | value66;
            r->c = value6 >= 6;
            r->mf = 1;
            r->xf = 0;
            JSR(c, 0xD7EA, 0xC0D6C8); /* limit_hero_signed_motion_to_live_party_window */
            uint16_t a_all2 = r->a;
            bool carry_ret2 = r->c;
            if (carry_ret2) {
                RAM16_SET(0x001E, 0);
                r->c = 1;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            RAM8(0x001E) = RAM8(0x001D);
            uint8_t value68 = RAM8(0x001E);
            uint8_t a24;
            uint8_t a_hi21;
            if (value68 >= 0x80) {
                uint16_t value69 = RAM16(0x0012);
                uint8_t a22;
                uint8_t a_hi19;
                if (!((uint16_t)(((((a_all2 >> 8 << 8) | value68) & 0x7F) ^ 0xFFFF) + value69 + 1) & 0x8000)) {
                    a22 = (uint8_t)(((((a_all2 >> 8 << 8) | value68) & 0x7F) ^ 0xFFFF) + value69 + 1);
                    a_hi19 = (uint16_t)(((((a_all2 >> 8 << 8) | value68) & 0x7F) ^ 0xFFFF) + value69 + 1) >> 8;
                } else {
                    uint16_t value70 = RAM16(0x00C0);
                    a22 = (uint8_t)((uint16_t)(((((a_all2 >> 8 << 8) | value68) & 0x7F) ^ 0xFFFF) + value69 + 1) + value70);
                    a_hi19 = (uint16_t)((uint16_t)(((((a_all2 >> 8 << 8) | value68) & 0x7F) ^ 0xFFFF) + value69 + 1) + value70) >> 8;
                }
                a24 = a22;
                a_hi21 = a_hi19;
            } else {
                uint16_t value71 = RAM16(0x0012);
                uint16_t value72 = RAM16(0x00C0);
                uint8_t a23;
                uint8_t a_hi20;
                if ((uint16_t)((((a_all2 >> 8 << 8) | value68) & 0x7F) + value71) < value72) {
                    a23 = (uint8_t)((((a_all2 >> 8 << 8) | value68) & 0x7F) + value71);
                    a_hi20 = (uint16_t)((((a_all2 >> 8 << 8) | value68) & 0x7F) + value71) >> 8;
                } else {
                    a23 = (uint8_t)((uint16_t)((((a_all2 >> 8 << 8) | value68) & 0x7F) + value71) - value72 - ((uint16_t)((((a_all2 >> 8 << 8) | value68) & 0x7F) + value71) >= value72 ^ 1));
                    a_hi20 = (uint16_t)((uint16_t)((((a_all2 >> 8 << 8) | value68) & 0x7F) + value71) - value72 - ((uint16_t)((((a_all2 >> 8 << 8) | value68) & 0x7F) + value71) >= value72 ^ 1)) >> 8;
                }
                a24 = a23;
                a_hi21 = a_hi20;
            }
            RAM16_SET(0x0008, ((a_hi21 << 8) | a24) >> 4);
            uint8_t value73 = RAM8(0x001F);
            uint8_t a27;
            uint8_t a_hi24;
            bool overflow12;
            if (value73 >= 0x80) {
                uint16_t value74 = RAM16(0x0014);
                uint8_t a25;
                uint8_t a_hi22;
                bool overflow10;
                if (!((uint16_t)(((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) ^ 0xFFFF) + value74 + 1) & 0x8000)) {
                    a25 = (uint8_t)(((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) ^ 0xFFFF) + value74 + 1);
                    a_hi22 = (uint16_t)(((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) ^ 0xFFFF) + value74 + 1) >> 8;
                    overflow10 = (((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) ^ 0xFFFF ^ (uint16_t)(((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) ^ 0xFFFF) + value74 + 1)) & (value74 ^ (uint16_t)(((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) ^ 0xFFFF) + value74 + 1)) & 0x8000) != 0;
                } else {
                    uint16_t value75 = RAM16(0x00C2);
                    a25 = (uint8_t)((uint16_t)(((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) ^ 0xFFFF) + value74 + 1) + value75);
                    a_hi22 = (uint16_t)((uint16_t)(((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) ^ 0xFFFF) + value74 + 1) + value75) >> 8;
                    overflow10 = (((uint16_t)(((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) ^ 0xFFFF) + value74 + 1) ^ (uint16_t)((uint16_t)(((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) ^ 0xFFFF) + value74 + 1) + value75)) & (value75 ^ (uint16_t)((uint16_t)(((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) ^ 0xFFFF) + value74 + 1) + value75)) & 0x8000) != 0;
                }
                a27 = a25;
                a_hi24 = a_hi22;
                overflow12 = overflow10;
            } else {
                uint16_t value76 = RAM16(0x0014);
                uint16_t value77 = RAM16(0x00C2);
                uint8_t a26;
                uint8_t a_hi23;
                bool overflow11;
                if ((uint16_t)((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) + value76) < value77) {
                    a26 = (uint8_t)((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) + value76);
                    a_hi23 = (uint16_t)((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) + value76) >> 8;
                    overflow11 = (((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) ^ (uint16_t)((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) + value76)) & (value76 ^ (uint16_t)((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) + value76)) & 0x8000) != 0;
                } else {
                    a26 = (uint8_t)((uint16_t)((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) + value76) - value77 - ((uint16_t)((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) + value76) >= value77 ^ 1));
                    a_hi23 = (uint16_t)((uint16_t)((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) + value76) - value77 - ((uint16_t)((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) + value76) >= value77 ^ 1)) >> 8;
                    overflow11 = (((uint16_t)((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) + value76) ^ value77) & ((uint16_t)((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) + value76) ^ (uint16_t)((uint16_t)((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) + value76) - value77 - ((uint16_t)((((((a_hi21 << 8) | a24) >> 4 >> 8 << 8) | value73) & 0x7F) + value76) >= value77 ^ 1))) & 0x8000) != 0;
                }
                a27 = a26;
                a_hi24 = a_hi23;
                overflow12 = overflow11;
            }
            uint16_t value78 = RAM16(0x0008);
            RAM16_SET(0x0008, ((((a_hi24 << 8) | a27) & 0x0FF0) << 1 << 1 << 1) | value78);
            uint16_t value79;
            BUS16_OK(c, (RAM8(0x000C) << 0x10) + RAM16(0x000A) + (((((a_hi24 << 8) | a27) & 0x0FF0) << 1 << 1 << 1) | value78), value79);
            RAM16_SET(0x0006, value79 & 0xFF);
            uint16_t value80;
            BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((value79 & 0xFF) << 1 << 1), value80);
            RAM16_SET(0x0000, value80);
            uint16_t value81;
            BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + (((value79 & 0xFF) << 1 << 1) + 2), value81);
            RAM16_SET(0x0004, value81);
            uint8_t value82 = RAM8(0x0000);
            if ((value82 & 8) == 0) {
                uint8_t a28;
                if ((value82 & 7) < 3) {
                    RAM8(0x0000) = value82 & 7;
                    a28 = (RAM8(0x001B) & 0xF0) | RAM8(0x0000);
                } else {
                    a28 = RAM8(0x001B) & 0xF7;
                }
                RAM8(0x001B) = a28;
            } else {
                uint8_t value86 = RAM8(0x001B);
                if ((value82 & 8 & value86) == 0) {
                    RAM8(0x001B) = (value86 ^ 0x88) & 0xF8;
                }
            }
            r->a = (r->a & 0x00FF) | ((value81 >> 8) << 8);
            r->y = ((value79 & 0xFF) << 1 << 1) + 2;
            r->c = 0;
            r->v = overflow12;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint8_t value87 = RAM8(0x001E);
        if (value87 == 0) {
            uint8_t a31;
            uint8_t a_hi27;
            if (value87 >= 0x80) {
                uint16_t value88 = RAM16(0x0012);
                uint8_t a29;
                uint8_t a_hi25;
                if (!((uint16_t)(((((a_all >> 8 << 8) | value87) & 0x7F) ^ 0xFFFF) + value88 + 1) & 0x8000)) {
                    a29 = (uint8_t)(((((a_all >> 8 << 8) | value87) & 0x7F) ^ 0xFFFF) + value88 + 1);
                    a_hi25 = (uint16_t)(((((a_all >> 8 << 8) | value87) & 0x7F) ^ 0xFFFF) + value88 + 1) >> 8;
                } else {
                    uint16_t value89 = RAM16(0x00C0);
                    a29 = (uint8_t)((uint16_t)(((((a_all >> 8 << 8) | value87) & 0x7F) ^ 0xFFFF) + value88 + 1) + value89);
                    a_hi25 = (uint16_t)((uint16_t)(((((a_all >> 8 << 8) | value87) & 0x7F) ^ 0xFFFF) + value88 + 1) + value89) >> 8;
                }
                a31 = a29;
                a_hi27 = a_hi25;
            } else {
                uint16_t value90 = RAM16(0x0012);
                uint16_t value91 = RAM16(0x00C0);
                uint8_t a30;
                uint8_t a_hi26;
                if ((uint16_t)((((a_all >> 8 << 8) | value87) & 0x7F) + value90) < value91) {
                    a30 = (uint8_t)((((a_all >> 8 << 8) | value87) & 0x7F) + value90);
                    a_hi26 = (uint16_t)((((a_all >> 8 << 8) | value87) & 0x7F) + value90) >> 8;
                } else {
                    a30 = (uint8_t)((uint16_t)((((a_all >> 8 << 8) | value87) & 0x7F) + value90) - value91 - ((uint16_t)((((a_all >> 8 << 8) | value87) & 0x7F) + value90) >= value91 ^ 1));
                    a_hi26 = (uint16_t)((uint16_t)((((a_all >> 8 << 8) | value87) & 0x7F) + value90) - value91 - ((uint16_t)((((a_all >> 8 << 8) | value87) & 0x7F) + value90) >= value91 ^ 1)) >> 8;
                }
                a31 = a30;
                a_hi27 = a_hi26;
            }
            RAM16_SET(0x0008, ((a_hi27 << 8) | a31) >> 4);
            uint8_t value92 = RAM8(0x001F);
            uint8_t a34;
            uint8_t a_hi30;
            bool overflow15;
            if (value92 >= 0x80) {
                uint16_t value93 = RAM16(0x0014);
                uint8_t a32;
                uint8_t a_hi28;
                bool overflow13;
                if (!((uint16_t)(((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) ^ 0xFFFF) + value93 + 1) & 0x8000)) {
                    a32 = (uint8_t)(((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) ^ 0xFFFF) + value93 + 1);
                    a_hi28 = (uint16_t)(((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) ^ 0xFFFF) + value93 + 1) >> 8;
                    overflow13 = (((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) ^ 0xFFFF ^ (uint16_t)(((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) ^ 0xFFFF) + value93 + 1)) & (value93 ^ (uint16_t)(((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) ^ 0xFFFF) + value93 + 1)) & 0x8000) != 0;
                } else {
                    uint16_t value94 = RAM16(0x00C2);
                    a32 = (uint8_t)((uint16_t)(((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) ^ 0xFFFF) + value93 + 1) + value94);
                    a_hi28 = (uint16_t)((uint16_t)(((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) ^ 0xFFFF) + value93 + 1) + value94) >> 8;
                    overflow13 = (((uint16_t)(((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) ^ 0xFFFF) + value93 + 1) ^ (uint16_t)((uint16_t)(((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) ^ 0xFFFF) + value93 + 1) + value94)) & (value94 ^ (uint16_t)((uint16_t)(((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) ^ 0xFFFF) + value93 + 1) + value94)) & 0x8000) != 0;
                }
                a34 = a32;
                a_hi30 = a_hi28;
                overflow15 = overflow13;
            } else {
                uint16_t value95 = RAM16(0x0014);
                uint16_t value96 = RAM16(0x00C2);
                uint8_t a33;
                uint8_t a_hi29;
                bool overflow14;
                if ((uint16_t)((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) + value95) < value96) {
                    a33 = (uint8_t)((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) + value95);
                    a_hi29 = (uint16_t)((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) + value95) >> 8;
                    overflow14 = (((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) ^ (uint16_t)((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) + value95)) & (value95 ^ (uint16_t)((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) + value95)) & 0x8000) != 0;
                } else {
                    a33 = (uint8_t)((uint16_t)((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) + value95) - value96 - ((uint16_t)((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) + value95) >= value96 ^ 1));
                    a_hi29 = (uint16_t)((uint16_t)((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) + value95) - value96 - ((uint16_t)((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) + value95) >= value96 ^ 1)) >> 8;
                    overflow14 = (((uint16_t)((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) + value95) ^ value96) & ((uint16_t)((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) + value95) ^ (uint16_t)((uint16_t)((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) + value95) - value96 - ((uint16_t)((((((a_hi27 << 8) | a31) >> 4 >> 8 << 8) | value92) & 0x7F) + value95) >= value96 ^ 1))) & 0x8000) != 0;
                }
                a34 = a33;
                a_hi30 = a_hi29;
                overflow15 = overflow14;
            }
            uint16_t value97 = RAM16(0x0008);
            RAM16_SET(0x0008, ((((a_hi30 << 8) | a34) & 0x0FF0) << 1 << 1 << 1) | value97);
            uint16_t value98;
            BUS16_OK(c, (RAM8(0x000C) << 0x10) + RAM16(0x000A) + (((((a_hi30 << 8) | a34) & 0x0FF0) << 1 << 1 << 1) | value97), value98);
            RAM16_SET(0x0006, value98 & 0xFF);
            uint16_t value99;
            BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((value98 & 0xFF) << 1 << 1), value99);
            RAM16_SET(0x0000, value99);
            uint16_t value100;
            BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + (((value98 & 0xFF) << 1 << 1) + 2), value100);
            RAM16_SET(0x0004, value100);
            uint8_t value101 = RAM8(0x0000);
            if ((value101 & 8) == 0) {
                uint8_t a35;
                if ((value101 & 7) < 3) {
                    RAM8(0x0000) = value101 & 7;
                    a35 = (RAM8(0x001B) & 0xF0) | RAM8(0x0000);
                } else {
                    a35 = RAM8(0x001B) & 0xF7;
                }
                RAM8(0x001B) = a35;
            } else {
                uint8_t value105 = RAM8(0x001B);
                if ((value101 & 8 & value105) == 0) {
                    RAM8(0x001B) = (value105 ^ 0x88) & 0xF8;
                }
            }
            r->a = (r->a & 0x00FF) | ((value100 >> 8) << 8);
            r->y = ((value98 & 0xFF) << 1 << 1) + 2;
            r->c = 0;
            r->v = overflow15;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint8_t value106 = RAM8(0x001F);
        RAM8(0x001C) = value106;
        RAM8(0x001F) = 0;
        r->a = (a_all >> 8 << 8) | value106;
        r->c = value6 >= 6;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0xD7CF, 0xC0D6C8); /* limit_hero_signed_motion_to_live_party_window */
        uint16_t a_all3 = r->a;
        bool carry_ret3 = r->c;
        if (carry_ret3) {
            RAM16_SET(0x001E, 0);
            r->c = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        RAM8(0x001F) = RAM8(0x001C);
        uint8_t value108 = RAM8(0x001E);
        uint8_t a38;
        uint8_t a_hi33;
        if (value108 >= 0x80) {
            uint16_t value109 = RAM16(0x0012);
            uint8_t a36;
            uint8_t a_hi31;
            if (!((uint16_t)(((((a_all3 >> 8 << 8) | value108) & 0x7F) ^ 0xFFFF) + value109 + 1) & 0x8000)) {
                a36 = (uint8_t)(((((a_all3 >> 8 << 8) | value108) & 0x7F) ^ 0xFFFF) + value109 + 1);
                a_hi31 = (uint16_t)(((((a_all3 >> 8 << 8) | value108) & 0x7F) ^ 0xFFFF) + value109 + 1) >> 8;
            } else {
                uint16_t value110 = RAM16(0x00C0);
                a36 = (uint8_t)((uint16_t)(((((a_all3 >> 8 << 8) | value108) & 0x7F) ^ 0xFFFF) + value109 + 1) + value110);
                a_hi31 = (uint16_t)((uint16_t)(((((a_all3 >> 8 << 8) | value108) & 0x7F) ^ 0xFFFF) + value109 + 1) + value110) >> 8;
            }
            a38 = a36;
            a_hi33 = a_hi31;
        } else {
            uint16_t value111 = RAM16(0x0012);
            uint16_t value112 = RAM16(0x00C0);
            uint8_t a37;
            uint8_t a_hi32;
            if ((uint16_t)((((a_all3 >> 8 << 8) | value108) & 0x7F) + value111) < value112) {
                a37 = (uint8_t)((((a_all3 >> 8 << 8) | value108) & 0x7F) + value111);
                a_hi32 = (uint16_t)((((a_all3 >> 8 << 8) | value108) & 0x7F) + value111) >> 8;
            } else {
                a37 = (uint8_t)((uint16_t)((((a_all3 >> 8 << 8) | value108) & 0x7F) + value111) - value112 - ((uint16_t)((((a_all3 >> 8 << 8) | value108) & 0x7F) + value111) >= value112 ^ 1));
                a_hi32 = (uint16_t)((uint16_t)((((a_all3 >> 8 << 8) | value108) & 0x7F) + value111) - value112 - ((uint16_t)((((a_all3 >> 8 << 8) | value108) & 0x7F) + value111) >= value112 ^ 1)) >> 8;
            }
            a38 = a37;
            a_hi33 = a_hi32;
        }
        RAM16_SET(0x0008, ((a_hi33 << 8) | a38) >> 4);
        uint8_t value113 = RAM8(0x001F);
        uint8_t a41;
        uint8_t a_hi36;
        bool overflow18;
        if (value113 >= 0x80) {
            uint16_t value114 = RAM16(0x0014);
            uint8_t a39;
            uint8_t a_hi34;
            bool overflow16;
            if (!((uint16_t)(((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) ^ 0xFFFF) + value114 + 1) & 0x8000)) {
                a39 = (uint8_t)(((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) ^ 0xFFFF) + value114 + 1);
                a_hi34 = (uint16_t)(((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) ^ 0xFFFF) + value114 + 1) >> 8;
                overflow16 = (((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) ^ 0xFFFF ^ (uint16_t)(((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) ^ 0xFFFF) + value114 + 1)) & (value114 ^ (uint16_t)(((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) ^ 0xFFFF) + value114 + 1)) & 0x8000) != 0;
            } else {
                uint16_t value115 = RAM16(0x00C2);
                a39 = (uint8_t)((uint16_t)(((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) ^ 0xFFFF) + value114 + 1) + value115);
                a_hi34 = (uint16_t)((uint16_t)(((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) ^ 0xFFFF) + value114 + 1) + value115) >> 8;
                overflow16 = (((uint16_t)(((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) ^ 0xFFFF) + value114 + 1) ^ (uint16_t)((uint16_t)(((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) ^ 0xFFFF) + value114 + 1) + value115)) & (value115 ^ (uint16_t)((uint16_t)(((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) ^ 0xFFFF) + value114 + 1) + value115)) & 0x8000) != 0;
            }
            a41 = a39;
            a_hi36 = a_hi34;
            overflow18 = overflow16;
        } else {
            uint16_t value116 = RAM16(0x0014);
            uint16_t value117 = RAM16(0x00C2);
            uint8_t a40;
            uint8_t a_hi35;
            bool overflow17;
            if ((uint16_t)((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) + value116) < value117) {
                a40 = (uint8_t)((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) + value116);
                a_hi35 = (uint16_t)((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) + value116) >> 8;
                overflow17 = (((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) ^ (uint16_t)((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) + value116)) & (value116 ^ (uint16_t)((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) + value116)) & 0x8000) != 0;
            } else {
                a40 = (uint8_t)((uint16_t)((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) + value116) - value117 - ((uint16_t)((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) + value116) >= value117 ^ 1));
                a_hi35 = (uint16_t)((uint16_t)((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) + value116) - value117 - ((uint16_t)((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) + value116) >= value117 ^ 1)) >> 8;
                overflow17 = (((uint16_t)((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) + value116) ^ value117) & ((uint16_t)((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) + value116) ^ (uint16_t)((uint16_t)((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) + value116) - value117 - ((uint16_t)((((((a_hi33 << 8) | a38) >> 4 >> 8 << 8) | value113) & 0x7F) + value116) >= value117 ^ 1))) & 0x8000) != 0;
            }
            a41 = a40;
            a_hi36 = a_hi35;
            overflow18 = overflow17;
        }
        uint16_t value118 = RAM16(0x0008);
        RAM16_SET(0x0008, ((((a_hi36 << 8) | a41) & 0x0FF0) << 1 << 1 << 1) | value118);
        uint16_t value119;
        BUS16_OK(c, (RAM8(0x000C) << 0x10) + RAM16(0x000A) + (((((a_hi36 << 8) | a41) & 0x0FF0) << 1 << 1 << 1) | value118), value119);
        RAM16_SET(0x0006, value119 & 0xFF);
        uint16_t value120;
        BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((value119 & 0xFF) << 1 << 1), value120);
        RAM16_SET(0x0000, value120);
        uint16_t value121;
        BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + (((value119 & 0xFF) << 1 << 1) + 2), value121);
        RAM16_SET(0x0004, value121);
        uint8_t value122 = RAM8(0x0000);
        if ((value122 & 8) == 0) {
            uint8_t a42;
            if ((value122 & 7) < 3) {
                RAM8(0x0000) = value122 & 7;
                a42 = (RAM8(0x001B) & 0xF0) | RAM8(0x0000);
            } else {
                a42 = RAM8(0x001B) & 0xF7;
            }
            RAM8(0x001B) = a42;
        } else {
            uint8_t value126 = RAM8(0x001B);
            if ((value122 & 8 & value126) == 0) {
                RAM8(0x001B) = (value126 ^ 0x88) & 0xF8;
            }
        }
        r->a = (r->a & 0x00FF) | ((value121 >> 8) << 8);
        r->y = ((value119 & 0xFF) << 1 << 1) + 2;
        r->c = 0;
        r->v = overflow18;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RETURN_RTS(c);
    shared_D7A7:;
    uint8_t value127 = RAM8(0x001E);
    uint8_t a45;
    uint8_t a_hi39;
    if (value127 >= 0x80) {
        uint16_t value128 = RAM16(0x0012);
        uint8_t a43;
        uint8_t a_hi37;
        if (!((uint16_t)(((((a_hi_d7a7 << 8) | value127) & 0x7F) ^ 0xFFFF) + value128 + 1) & 0x8000)) {
            a43 = (uint8_t)(((((a_hi_d7a7 << 8) | value127) & 0x7F) ^ 0xFFFF) + value128 + 1);
            a_hi37 = (uint16_t)(((((a_hi_d7a7 << 8) | value127) & 0x7F) ^ 0xFFFF) + value128 + 1) >> 8;
        } else {
            uint16_t value129 = RAM16(0x00C0);
            a43 = (uint8_t)((uint16_t)(((((a_hi_d7a7 << 8) | value127) & 0x7F) ^ 0xFFFF) + value128 + 1) + value129);
            a_hi37 = (uint16_t)((uint16_t)(((((a_hi_d7a7 << 8) | value127) & 0x7F) ^ 0xFFFF) + value128 + 1) + value129) >> 8;
        }
        a45 = a43;
        a_hi39 = a_hi37;
    } else {
        uint16_t value130 = RAM16(0x0012);
        uint16_t value131 = RAM16(0x00C0);
        uint8_t a44;
        uint8_t a_hi38;
        if ((uint16_t)((((a_hi_d7a7 << 8) | value127) & 0x7F) + value130) < value131) {
            a44 = (uint8_t)((((a_hi_d7a7 << 8) | value127) & 0x7F) + value130);
            a_hi38 = (uint16_t)((((a_hi_d7a7 << 8) | value127) & 0x7F) + value130) >> 8;
        } else {
            a44 = (uint8_t)((uint16_t)((((a_hi_d7a7 << 8) | value127) & 0x7F) + value130) - value131 - ((uint16_t)((((a_hi_d7a7 << 8) | value127) & 0x7F) + value130) >= value131 ^ 1));
            a_hi38 = (uint16_t)((uint16_t)((((a_hi_d7a7 << 8) | value127) & 0x7F) + value130) - value131 - ((uint16_t)((((a_hi_d7a7 << 8) | value127) & 0x7F) + value130) >= value131 ^ 1)) >> 8;
        }
        a45 = a44;
        a_hi39 = a_hi38;
    }
    RAM16_SET(0x0008, ((a_hi39 << 8) | a45) >> 4);
    uint8_t value132 = RAM8(0x001F);
    uint8_t a48;
    uint8_t a_hi42;
    bool overflow21;
    if (value132 >= 0x80) {
        uint16_t value133 = RAM16(0x0014);
        uint8_t a46;
        uint8_t a_hi40;
        bool overflow19;
        if (!((uint16_t)(((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) ^ 0xFFFF) + value133 + 1) & 0x8000)) {
            a46 = (uint8_t)(((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) ^ 0xFFFF) + value133 + 1);
            a_hi40 = (uint16_t)(((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) ^ 0xFFFF) + value133 + 1) >> 8;
            overflow19 = (((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) ^ 0xFFFF ^ (uint16_t)(((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) ^ 0xFFFF) + value133 + 1)) & (value133 ^ (uint16_t)(((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) ^ 0xFFFF) + value133 + 1)) & 0x8000) != 0;
        } else {
            uint16_t value134 = RAM16(0x00C2);
            a46 = (uint8_t)((uint16_t)(((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) ^ 0xFFFF) + value133 + 1) + value134);
            a_hi40 = (uint16_t)((uint16_t)(((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) ^ 0xFFFF) + value133 + 1) + value134) >> 8;
            overflow19 = (((uint16_t)(((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) ^ 0xFFFF) + value133 + 1) ^ (uint16_t)((uint16_t)(((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) ^ 0xFFFF) + value133 + 1) + value134)) & (value134 ^ (uint16_t)((uint16_t)(((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) ^ 0xFFFF) + value133 + 1) + value134)) & 0x8000) != 0;
        }
        a48 = a46;
        a_hi42 = a_hi40;
        overflow21 = overflow19;
    } else {
        uint16_t value135 = RAM16(0x0014);
        uint16_t value136 = RAM16(0x00C2);
        uint8_t a47;
        uint8_t a_hi41;
        bool overflow20;
        if ((uint16_t)((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) + value135) < value136) {
            a47 = (uint8_t)((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) + value135);
            a_hi41 = (uint16_t)((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) + value135) >> 8;
            overflow20 = (((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) ^ (uint16_t)((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) + value135)) & (value135 ^ (uint16_t)((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) + value135)) & 0x8000) != 0;
        } else {
            a47 = (uint8_t)((uint16_t)((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) + value135) - value136 - ((uint16_t)((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) + value135) >= value136 ^ 1));
            a_hi41 = (uint16_t)((uint16_t)((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) + value135) - value136 - ((uint16_t)((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) + value135) >= value136 ^ 1)) >> 8;
            overflow20 = (((uint16_t)((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) + value135) ^ value136) & ((uint16_t)((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) + value135) ^ (uint16_t)((uint16_t)((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) + value135) - value136 - ((uint16_t)((((((a_hi39 << 8) | a45) >> 4 >> 8 << 8) | value132) & 0x7F) + value135) >= value136 ^ 1))) & 0x8000) != 0;
        }
        a48 = a47;
        a_hi42 = a_hi41;
        overflow21 = overflow20;
    }
    uint16_t value137 = RAM16(0x0008);
    RAM16_SET(0x0008, ((((a_hi42 << 8) | a48) & 0x0FF0) << 1 << 1 << 1) | value137);
    uint16_t value138;
    BUS16_OK(c, (RAM8(0x000C) << 0x10) + RAM16(0x000A) + (((((a_hi42 << 8) | a48) & 0x0FF0) << 1 << 1 << 1) | value137), value138);
    RAM16_SET(0x0006, value138 & 0xFF);
    uint16_t value139;
    BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + ((value138 & 0xFF) << 1 << 1), value139);
    RAM16_SET(0x0000, value139);
    uint16_t value140;
    BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + (((value138 & 0xFF) << 1 << 1) + 2), value140);
    RAM16_SET(0x0004, value140);
    uint8_t value141 = RAM8(0x0000);
    if ((value141 & 8) == 0) {
        uint8_t a49;
        if ((value141 & 7) < 3) {
            RAM8(0x0000) = value141 & 7;
            a49 = (RAM8(0x001B) & 0xF0) | RAM8(0x0000);
        } else {
            a49 = RAM8(0x001B) & 0xF7;
        }
        RAM8(0x001B) = a49;
    } else {
        uint8_t value145 = RAM8(0x001B);
        if ((value141 & 8 & value145) == 0) {
            RAM8(0x001B) = (value145 ^ 0x88) & 0xF8;
        }
    }
    r->a = (value140 >> 8 << 8) | a;
    r->y = ((value138 & 0xFF) << 1 << 1) + 2;
    r->c = 0;
    r->v = overflow21;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0D74F, SOM_RTS, "hand", resolve_actor_terrain_motion_and_publish_cell_layer, 0, L_B | L_Y | L_C | L_V, 1, 1, -1, 321, 163)
