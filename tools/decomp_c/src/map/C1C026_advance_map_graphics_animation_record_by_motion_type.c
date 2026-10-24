#include "som_c.h"

/* C1C026 advance_map_graphics_animation_record_by_motion_type   [class B, 316 bytes, 138 instructions]
 * Source: src/rom/advance_map_graphics_animation_record_by_motion_type.s
 * Documented in docs/map-graphics-runtime-animation.md
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: BXY.
 */
static void advance_map_graphics_animation_record_by_motion_type(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const uint8_t db = r->db;
    if (y >= 2) {
        if (y >= 4) {
            if (y >= 5) {
                if (y >= 6) {
                    if (y >= 8) {
                        if (y >= 0x0A) {
                            if (y >= 0x0C) {
                                if (y >= 0x0D) {
                                    if (y >= 0x0E) {
                                        uint16_t value = BUS16_RDP(c, (db << 0x10) + 0x8204 + x);
                                        BUS16_SET(c, (db << 0x10) + 0x8204 + x, (uint16_t)(value + 0x40) & 0x03C0);
                                        uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0x8202 + x);
                                        BUS16_SET(c, (db << 0x10) + 0x820A + x, (uint16_t)(((uint16_t)(value + 0x40) & 0x03C0) + value2));
                                        uint16_t value3 = BUS16_RDP(c, (db << 0x10) + 0x8206 + x);
                                        BUS16_SET(c, (db << 0x10) + 0x820C + x, value3);
                                        r->a = value3;
                                        r->mf = 0;
                                        RETURN_RTS(c);
                                    }
                                    uint16_t value4 = BUS16_RDP(c, (db << 0x10) + 0x8204 + x);
                                    RAM8(0x0000 + sp0) = (uint16_t)(value4 + 2) >> 8;
                                    RAM8(0x0000 + sp0 - 1) = (uint8_t)(value4 + 2);
                                    uint8_t a1;
                                    if (((uint16_t)(value4 + 2) & 0x10) == 0) {
                                        a1 = (uint16_t)(value4 + 2) & 0x10;
                                    } else {
                                        a1 = ((uint16_t)(value4 + 2) & 0x10) | 0x20;
                                    }
                                    RAM16_SET(0x0002, a1);
                                    uint16_t value5 = RAM16(0x0002);
                                    BUS16_SET(c, (db << 0x10) + 0x8204 + x, (uint16_t)((uint16_t)(value4 + 2) + value5 + (value4 + 2 > 0xFFFF)) & 0x7F);
                                    RAM8(0x0000 + sp0) = 0;
                                    RAM8(0x0000 + sp0 - 1) = (uint16_t)((uint16_t)(value4 + 2) + value5 + (value4 + 2 > 0xFFFF)) & 0x7F;
                                    uint16_t value6 = BUS16_RDP(c, (db << 0x10) + 0x8202 + x);
                                    RAM16_SET(0x0002, (uint16_t)(((uint16_t)((uint16_t)(value4 + 2) + value5 + (value4 + 2 > 0xFFFF)) & 0x7F) + value6 + ((uint16_t)(value4 + 2) + value5 + (value4 + 2 > 0xFFFF) > 0xFFFF)));
                                    uint16_t value7 = BUS16_RDP(c, (db << 0x10) + RAM16(0x0002));
                                    BUS16_SET(c, (db << 0x10) + 0x8302 + x, value7);
                                    uint16_t value8 = BUS16_RDP(c, (db << 0x10) + RAM16(0x0002) + 0x10);
                                    BUS16_SET(c, (db << 0x10) + 0x8306 + x, value8);
                                    uint16_t value9 = BUS16_RDP(c, (db << 0x10) + RAM16(0x0002) + 0x20);
                                    BUS16_SET(c, (db << 0x10) + 0x830A + x, value9);
                                    uint16_t value10 = BUS16_RDP(c, (db << 0x10) + RAM16(0x0002) + 0x30);
                                    BUS16_SET(c, (db << 0x10) + 0x830E + x, value10);
                                    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
                                    uint8_t value12 = RAM8(0x0000 + sp0);
                                    uint16_t value13 = BUS16_RDP(c, (db << 0x10) + 0x8206 + x);
                                    BUS16_SET(c, (db << 0x10) + 0x8300 + x, (uint16_t)(((((value12 << 8) | value11) & 0x0F) >> 1) + value13));
                                    BUS16_SET(c, (db << 0x10) + 0x8304 + x, (uint16_t)(((((value12 << 8) | value11) & 0x0F) >> 1) + value13) | 8);
                                    BUS16_SET(c, (db << 0x10) + 0x8308 + x, ((uint16_t)(((((value12 << 8) | value11) & 0x0F) >> 1) + value13) | 8) ^ 0x18);
                                    BUS16_SET(c, (db << 0x10) + 0x830C + x, ((uint16_t)(((((value12 << 8) | value11) & 0x0F) >> 1) + value13) | 8) ^ 0x18 | 8);
                                    r->a = ((uint16_t)(((((value12 << 8) | value11) & 0x0F) >> 1) + value13) | 8) ^ 0x18 | 8;
                                    r->y = 0x30;
                                    r->mf = 0;
                                    RETURN_RTS(c);
                                }
                                uint16_t value14 = BUS16_RDP(c, (db << 0x10) + 0x8204 + x);
                                BUS16_SET(c, (db << 0x10) + 0x8204 + x, (uint16_t)(value14 + 0x40) & 0xFF);
                                uint16_t value15 = BUS16_RDP(c, (db << 0x10) + 0x8202 + x);
                                BUS16_SET(c, (db << 0x10) + 0x820A + x, (uint16_t)(((uint16_t)(value14 + 0x40) & 0xFF) + value15));
                                uint16_t value16 = BUS16_RDP(c, (db << 0x10) + 0x8206 + x);
                                BUS16_SET(c, (db << 0x10) + 0x820C + x, value16);
                                r->a = value16;
                                r->mf = 0;
                                RETURN_RTS(c);
                            }
                            uint16_t value17 = BUS16_RDP(c, (db << 0x10) + 0x8204 + x);
                            RAM8(0x0000 + sp0) = (uint16_t)(value17 + 2) >> 8;
                            RAM8(0x0000 + sp0 - 1) = (uint8_t)(value17 + 2);
                            uint8_t a2;
                            if (((uint16_t)(value17 + 2) & 0x10) == 0) {
                                a2 = (uint16_t)(value17 + 2) & 0x10;
                            } else {
                                a2 = ((uint16_t)(value17 + 2) & 0x10) | 0x20;
                            }
                            RAM16_SET(0x0002, a2);
                            uint16_t value18 = RAM16(0x0002);
                            BUS16_SET(c, (db << 0x10) + 0x8204 + x, (uint16_t)((uint16_t)(value17 + 2) + value18 + (value17 + 2 > 0xFFFF)) & 0x03FF);
                            RAM8(0x0000 + sp0) = ((uint16_t)((uint16_t)(value17 + 2) + value18 + (value17 + 2 > 0xFFFF)) & 0x03FF) >> 8;
                            RAM8(0x0000 + sp0 - 1) = (uint8_t)((uint16_t)((uint16_t)(value17 + 2) + value18 + (value17 + 2 > 0xFFFF)) & 0x03FF);
                            uint16_t value19 = BUS16_RDP(c, (db << 0x10) + 0x8202 + x);
                            RAM16_SET(0x0002, (uint16_t)(((uint16_t)((uint16_t)(value17 + 2) + value18 + (value17 + 2 > 0xFFFF)) & 0x03FF) + value19 + ((uint16_t)(value17 + 2) + value18 + (value17 + 2 > 0xFFFF) > 0xFFFF)));
                            uint16_t value20 = BUS16_RDP(c, (db << 0x10) + RAM16(0x0002));
                            BUS16_SET(c, (db << 0x10) + 0x8302 + x, value20);
                            uint16_t value21 = BUS16_RDP(c, (db << 0x10) + RAM16(0x0002) + 0x10);
                            BUS16_SET(c, (db << 0x10) + 0x8306 + x, value21);
                            uint16_t value22 = BUS16_RDP(c, (db << 0x10) + RAM16(0x0002) + 0x20);
                            BUS16_SET(c, (db << 0x10) + 0x830A + x, value22);
                            uint16_t value23 = BUS16_RDP(c, (db << 0x10) + RAM16(0x0002) + 0x30);
                            BUS16_SET(c, (db << 0x10) + 0x830E + x, value23);
                            uint8_t value24 = RAM8(0x0000 + sp0 - 1);
                            uint8_t value25 = RAM8(0x0000 + sp0);
                            uint16_t value26 = BUS16_RDP(c, (db << 0x10) + 0x8206 + x);
                            BUS16_SET(c, (db << 0x10) + 0x8300 + x, (uint16_t)(((((value25 << 8) | value24) & 0x0F) >> 1) + value26));
                            BUS16_SET(c, (db << 0x10) + 0x8304 + x, (uint16_t)(((((value25 << 8) | value24) & 0x0F) >> 1) + value26) | 8);
                            BUS16_SET(c, (db << 0x10) + 0x8308 + x, ((uint16_t)(((((value25 << 8) | value24) & 0x0F) >> 1) + value26) | 8) ^ 0x18);
                            BUS16_SET(c, (db << 0x10) + 0x830C + x, ((uint16_t)(((((value25 << 8) | value24) & 0x0F) >> 1) + value26) | 8) ^ 0x18 | 8);
                            r->a = ((uint16_t)(((((value25 << 8) | value24) & 0x0F) >> 1) + value26) | 8) ^ 0x18 | 8;
                            r->y = 0x30;
                            r->mf = 0;
                            RETURN_RTS(c);
                        }
                        uint16_t value27 = BUS16_RDP(c, (db << 0x10) + 0x8204 + x);
                        BUS16_SET(c, (db << 0x10) + 0x8204 + x, (uint16_t)(value27 + 0x40) & 0x07C0);
                        uint16_t value28 = BUS16_RDP(c, (db << 0x10) + 0x8202 + x);
                        BUS16_SET(c, (db << 0x10) + 0x820A + x, (uint16_t)(((uint16_t)(value27 + 0x40) & 0x07C0) + value28));
                        uint16_t value29 = BUS16_RDP(c, (db << 0x10) + 0x8206 + x);
                        BUS16_SET(c, (db << 0x10) + 0x820C + x, value29);
                        r->a = value29;
                        r->mf = 0;
                        RETURN_RTS(c);
                    }
                    uint16_t value30 = BUS16_RDP(c, (db << 0x10) + 0x8204 + x);
                    BUS16_SET(c, (db << 0x10) + 0x8204 + x, (uint16_t)(value30 + 0x20) & 0x01E0);
                    uint16_t value31 = BUS16_RDP(c, (db << 0x10) + 0x8202 + x);
                    BUS16_SET(c, (db << 0x10) + 0x820A + x, (uint16_t)(((uint16_t)(value30 + 0x20) & 0x01E0) + value31));
                    uint16_t value32 = BUS16_RDP(c, (db << 0x10) + 0x8206 + x);
                    BUS16_SET(c, (db << 0x10) + 0x820C + x, value32);
                    r->a = value32;
                    r->mf = 0;
                    RETURN_RTS(c);
                }
                uint16_t value33 = BUS16_RDP(c, (db << 0x10) + 0x8204 + x);
                BUS16_SET(c, (db << 0x10) + 0x8204 + x, (uint16_t)(value33 + 0x40) & 0x03C0);
                uint16_t value34 = BUS16_RDP(c, (db << 0x10) + 0x8202 + x);
                BUS16_SET(c, (db << 0x10) + 0x820A + x, (uint16_t)(((uint16_t)(value33 + 0x40) & 0x03C0) + value34));
                uint16_t value35 = BUS16_RDP(c, (db << 0x10) + 0x8206 + x);
                BUS16_SET(c, (db << 0x10) + 0x820C + x, value35);
                r->a = value35;
                r->mf = 0;
                RETURN_RTS(c);
            }
            uint16_t value36 = BUS16_RDP(c, (db << 0x10) + 0x8204 + x);
            BUS16_SET(c, (db << 0x10) + 0x8204 + x, (uint16_t)(value36 + 0x40) & 0x03C0);
            uint16_t value37 = BUS16_RDP(c, (db << 0x10) + 0x8202 + x);
            BUS16_SET(c, (db << 0x10) + 0x820A + x, (uint16_t)(((uint16_t)(value36 + 0x40) & 0x03C0) + value37));
            uint16_t value38 = BUS16_RDP(c, (db << 0x10) + 0x8206 + x);
            BUS16_SET(c, (db << 0x10) + 0x820C + x, value38);
            r->a = value38;
            r->mf = 0;
            RETURN_RTS(c);
        }
        uint16_t value39 = BUS16_RDP(c, (db << 0x10) + 0x8204 + x);
        RAM8(0x0000 + sp0) = (uint16_t)(value39 + 2) >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)(value39 + 2);
        RAM16_SET(0x0002, (uint16_t)(value39 + 2) & 0x10);
        uint16_t value40 = RAM16(0x0002);
        BUS16_SET(c, (db << 0x10) + 0x8204 + x, (uint16_t)((uint16_t)(value39 + 2) + value40 + (value39 + 2 > 0xFFFF)) & 0xFF);
        RAM8(0x0000 + sp0) = 0;
        RAM8(0x0000 + sp0 - 1) = (uint16_t)((uint16_t)(value39 + 2) + value40 + (value39 + 2 > 0xFFFF)) & 0xFF;
        uint16_t value41 = BUS16_RDP(c, (db << 0x10) + 0x8202 + x);
        RAM16_SET(0x0002, (uint16_t)(((uint16_t)((uint16_t)(value39 + 2) + value40 + (value39 + 2 > 0xFFFF)) & 0xFF) + value41 + ((uint16_t)(value39 + 2) + value40 + (value39 + 2 > 0xFFFF) > 0xFFFF)));
        uint16_t value42 = BUS16_RDP(c, (db << 0x10) + RAM16(0x0002));
        BUS16_SET(c, (db << 0x10) + 0x8302 + x, value42);
        uint16_t value43 = BUS16_RDP(c, (db << 0x10) + RAM16(0x0002) + 0x10);
        BUS16_SET(c, (db << 0x10) + 0x8306 + x, value43);
        uint8_t value44 = RAM8(0x0000 + sp0 - 1);
        uint8_t value45 = RAM8(0x0000 + sp0);
        uint16_t value46 = BUS16_RDP(c, (db << 0x10) + 0x8206 + x);
        BUS16_SET(c, (db << 0x10) + 0x8300 + x, (uint16_t)(((((value45 << 8) | value44) & 0x0F) >> 1) + value46));
        BUS16_SET(c, (db << 0x10) + 0x8304 + x, (uint16_t)(((((value45 << 8) | value44) & 0x0F) >> 1) + value46) | 8);
        r->a = (uint16_t)(((((value45 << 8) | value44) & 0x0F) >> 1) + value46) | 8;
        r->y = 0x10;
        r->mf = 0;
        RETURN_RTS(c);
    }
    uint16_t value47 = BUS16_RDP(c, (db << 0x10) + 0x8204 + x);
    BUS16_SET(c, (db << 0x10) + 0x8204 + x, (uint16_t)(value47 + 0x20) & 0x01E0);
    uint16_t value48 = BUS16_RDP(c, (db << 0x10) + 0x8202 + x);
    BUS16_SET(c, (db << 0x10) + 0x820A + x, (uint16_t)(((uint16_t)(value47 + 0x20) & 0x01E0) + value48));
    uint16_t value49 = BUS16_RDP(c, (db << 0x10) + 0x8206 + x);
    BUS16_SET(c, (db << 0x10) + 0x820C + x, value49);
    r->a = value49;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1C026, SOM_RTS, "gen", advance_map_graphics_animation_record_by_motion_type, 0, L_B | L_X | L_Y, 2, 1, 1, 316, 138)
