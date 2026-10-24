#include "som_c.h"

/* C2BB0F advance_one_timed_menu_tile_record_and_publish_native_tiles   [class C, 289 bytes, 137 instructions]
 * Source: src/rom/advance_one_timed_menu_tile_record_and_publish_native_tiles.s
 * Documented in docs/map-main-frame-menu-records.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: BXY.
 */
static void advance_one_timed_menu_tile_record_and_publish_native_tiles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    if (a >= 4) {
        if (a != 5) {
            if (a != 4) {
                if (a != 7) {
                    uint8_t value = RAM8(0xD206 + x);
                    uint8_t a1;
                    if ((uint8_t)(value + 1) < 8) {
                        a1 = (uint8_t)(value + 1);
                    } else {
                        a1 = 0;
                    }
                    RAM8(0xD206 + x) = a1;
                    if (a1 != 7) {
                        BUS8_SET(c, 0x004202, a1);
                        BUS8_SET(c, 0x004203, 0x1E);
                        uint16_t value2 = RAM16(0xD204 + x);
                        uint16_t value3 = RAM16(0xD208 + x);
                        uint16_t value4 = BUS16(c, 0x004216);
                        RAM8(0x0000 + sp0) = 0;
                        RAM8(0x0000 + sp0 - 1) = x;
                        r->a = 0x1D;
                        r->x = (uint16_t)(value3 + value4);
                        r->y = (uint16_t)(value2 + 2) | 0x0600;
                        r->mf = 0;
                        r->xf = 0;
                        i_mvn(c, 0xC8, 0x7E); /* copy up bank $C8 to bank $7E */
                        r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                        RETURN_RTS(c);
                    }
                    uint8_t value7 = RAM8(0xD204 + x);
                    RAM8(0x0000 + sp0) = x;
                    uint8_t a_hi1 = a_hi;
                    uint8_t x1 = 0x0F;
                    uint8_t y1 = (uint8_t)((a_hi << 8) | value7);
                    for (;;) {
                        uint16_t value8 = RAM16(0xDE02 + y1);
                        RAM16_SET(0x0602 + y1, value8);
                        a_hi1 = value8 >> 8;
                        x1 = (uint8_t)(x1 - 1);
                        y1 = (uint8_t)(y1 + 2);
                        if (!(x1 != 0)) break;
                    }
                    uint8_t value9 = RAM8(0x0000 + sp0);
                    r->a = (a_hi1 << 8) | a;
                    r->x = value9;
                    r->y = y1;
                    RETURN_RTS(c);
                }
                uint8_t value10 = RAM8(0xD206 + x);
                uint8_t a2;
                if ((uint8_t)(value10 + 1) < 0x10) {
                    a2 = (uint8_t)(value10 + 1);
                } else {
                    a2 = 0;
                }
                RAM8(0xD206 + x) = a2;
                if (a2 == 0x0F) {
                    uint8_t value11 = RAM8(0xD204 + x);
                    RAM8(0x0000 + sp0) = x;
                    uint8_t a_hi2 = a_hi;
                    uint8_t x2 = 0x0F;
                    uint8_t y2 = (uint8_t)((a_hi << 8) | value11);
                    for (;;) {
                        uint16_t value12 = RAM16(0xDE02 + y2);
                        RAM16_SET(0x0602 + y2, value12);
                        a_hi2 = value12 >> 8;
                        x2 = (uint8_t)(x2 - 1);
                        y2 = (uint8_t)(y2 + 2);
                        if (!(x2 != 0)) break;
                    }
                    uint8_t value13 = RAM8(0x0000 + sp0);
                    r->a = (a_hi2 << 8) | a;
                    r->x = value13;
                    r->y = y2;
                    RETURN_RTS(c);
                }
                BUS8_SET(c, 0x004202, a2);
                BUS8_SET(c, 0x004203, 0x1E);
                uint16_t value14 = RAM16(0xD204 + x);
                uint16_t value15 = RAM16(0xD208 + x);
                uint16_t value16 = BUS16(c, 0x004216);
                RAM8(0x0000 + sp0) = 0;
                RAM8(0x0000 + sp0 - 1) = x;
                r->a = 0x1D;
                r->x = (uint16_t)(value15 + value16);
                r->y = (uint16_t)(value14 + 2) | 0x0600;
                r->mf = 0;
                r->xf = 0;
                i_mvn(c, 0xC8, 0x7E); /* copy up bank $C8 to bank $7E */
                r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                RETURN_RTS(c);
            }
            uint8_t value19 = RAM8(0xD201 + x);
            uint8_t a5;
            uint8_t y3;
            if (value19 != 0) {
                uint8_t value20 = RAM8(0xD206 + x);
                uint8_t a3;
                if (!((uint8_t)(value20 - 1) & 0x80)) {
                    a3 = (uint8_t)(value20 - 1);
                } else {
                    RAM8(0xD201 + x) = value19 ^ 1;
                    a3 = 0;
                }
                a5 = a3;
                y3 = (uint8_t)((a_hi << 8) | value20);
            } else {
                uint8_t value21 = RAM8(0xD206 + x);
                uint8_t a4;
                if ((uint8_t)(value21 + 1) < 0x0F) {
                    a4 = (uint8_t)(value21 + 1);
                } else {
                    RAM8(0xD201 + x) = value19 ^ 1;
                    a4 = 0x0F;
                }
                a5 = a4;
                y3 = (uint8_t)((a_hi << 8) | value21);
            }
            RAM8(0xD206 + x) = a5;
            BUS8_SET(c, 0x004202, y3);
            BUS8_SET(c, 0x004203, 0x1E);
            uint16_t value22 = RAM16(0xD204 + x);
            uint16_t value23 = RAM16(0xD208 + x);
            uint16_t value24 = BUS16(c, 0x004216);
            RAM8(0x0000 + sp0) = 0;
            RAM8(0x0000 + sp0 - 1) = x;
            r->a = 0x1D;
            r->x = (uint16_t)(value23 + value24);
            r->y = (uint16_t)(value22 + 2) | 0x0600;
            r->mf = 0;
            r->xf = 0;
            i_mvn(c, 0x7E, 0x7E); /* copy up bank $7E to bank $7E */
            uint16_t y_moved3 = r->y;
            r->x = (uint8_t)((RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1));
            r->y = (uint8_t)y_moved3;
            r->mf = 1;
            r->xf = 1;
            RETURN_RTS(c);
        }
        RAM8(0xD206 + x)++;
        uint16_t value27 = RAM16(0xD204 + x);
        uint16_t value28 = RAM16(0xD206 + x);
        if (((uint16_t)(value28 << 1) & 0x1E) != 0x1E) {
            uint16_t value29 = RAM16(0xD208 + x);
            RAM8(0x0000 + sp0) = 0;
            RAM8(0x0000 + sp0 - 1) = x;
            uint16_t value30 = BUS16(c, 0xC80000 + (uint16_t)(((uint16_t)(value28 << 1) & 0x1E) + value29));
            RAM16_SET(0x0600 + (value27 | 0x1E), value30);
            uint8_t value31 = RAM8(0x0000 + sp0 - 1);
            uint8_t value32 = RAM8(0x0000 + sp0);
            r->a = value30;
            r->x = (value32 << 8) | value31;
            r->y = value27 | 0x1E;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value33 = RAM16(0xDE00 + (value27 | 0x1E));
        RAM16_SET(0x0600 + (value27 | 0x1E), value33);
        r->a = value33;
        r->y = value27 | 0x1E;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if (a != 3) {
        uint8_t a7;
        uint8_t y4;
        if (a != 2) {
            a7 = a;
            y4 = y;
        } else {
            uint8_t value34 = RAM8(0xD201 + x);
            uint8_t value35 = RAM8(0xD206 + x);
            uint8_t value36 = RAM8(0xD20C + x);
            uint8_t a6;
            if ((uint8_t)(value35 + 1) < value36) {
                a6 = (uint8_t)(value35 + 1);
            } else {
                RAM8(0xD201 + x) = value34 ^ 1;
                a6 = 0;
            }
            RAM8(0xD206 + x) = a6;
            a7 = (uint8_t)((a_hi << 8) | value34);
            y4 = (uint8_t)((a_hi << 8) | value34);
        }
        r->a = (a_hi << 8) | a7;
        r->y = y4;
        TAIL_CALL(c, 0xC2BC30, SOM_RTS); /* rotate_one_timed_menu_tile_row_in_selected_direction */
    }
    if (1) {
        if (0) {
            if (1) {
                uint8_t value37 = RAM8(0xD206 + x);
                uint8_t a8;
                if ((uint8_t)(value37 + 1) < 8) {
                    a8 = (uint8_t)(value37 + 1);
                } else {
                    a8 = 0;
                }
                RAM8(0xD206 + x) = a8;
                if (a8 != 7) {
                    BUS8_SET(c, 0x004202, a8);
                    BUS8_SET(c, 0x004203, 0x1E);
                    uint16_t value38 = RAM16(0xD204 + x);
                    uint16_t value39 = RAM16(0xD208 + x);
                    uint16_t value40 = BUS16(c, 0x004216);
                    RAM8(0x0000 + sp0) = 0;
                    RAM8(0x0000 + sp0 - 1) = x;
                    r->a = 0x1D;
                    r->x = (uint16_t)(value39 + value40);
                    r->y = (uint16_t)(value38 + 2) | 0x0600;
                    r->mf = 0;
                    r->xf = 0;
                    i_mvn(c, 0xC8, 0x7E); /* copy up bank $C8 to bank $7E */
                    r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                    RETURN_RTS(c);
                }
                uint8_t value43 = RAM8(0xD204 + x);
                RAM8(0x0000 + sp0) = x;
                uint8_t a_hi3 = a_hi;
                uint8_t x3 = 0x0F;
                uint8_t y5 = (uint8_t)((a_hi << 8) | value43);
                for (;;) {
                    uint16_t value44 = RAM16(0xDE02 + y5);
                    RAM16_SET(0x0602 + y5, value44);
                    a_hi3 = value44 >> 8;
                    x3 = (uint8_t)(x3 - 1);
                    y5 = (uint8_t)(y5 + 2);
                    if (!(x3 != 0)) break;
                }
                uint8_t value45 = RAM8(0x0000 + sp0);
                r->a = (a_hi3 << 8) | a;
                r->x = value45;
                r->y = y5;
                RETURN_RTS(c);
            }
            uint8_t value46 = RAM8(0xD206 + x);
            uint8_t a9;
            if ((uint8_t)(value46 + 1) < 0x10) {
                a9 = (uint8_t)(value46 + 1);
            } else {
                a9 = 0;
            }
            RAM8(0xD206 + x) = a9;
            if (a9 == 0x0F) {
                uint8_t value47 = RAM8(0xD204 + x);
                RAM8(0x0000 + sp0) = x;
                uint8_t a_hi4 = a_hi;
                uint8_t x4 = 0x0F;
                uint8_t y6 = (uint8_t)((a_hi << 8) | value47);
                for (;;) {
                    uint16_t value48 = RAM16(0xDE02 + y6);
                    RAM16_SET(0x0602 + y6, value48);
                    a_hi4 = value48 >> 8;
                    x4 = (uint8_t)(x4 - 1);
                    y6 = (uint8_t)(y6 + 2);
                    if (!(x4 != 0)) break;
                }
                uint8_t value49 = RAM8(0x0000 + sp0);
                r->a = (a_hi4 << 8) | a;
                r->x = value49;
                r->y = y6;
                RETURN_RTS(c);
            }
            BUS8_SET(c, 0x004202, a9);
            BUS8_SET(c, 0x004203, 0x1E);
            uint16_t value50 = RAM16(0xD204 + x);
            uint16_t value51 = RAM16(0xD208 + x);
            uint16_t value52 = BUS16(c, 0x004216);
            RAM8(0x0000 + sp0) = 0;
            RAM8(0x0000 + sp0 - 1) = x;
            r->a = 0x1D;
            r->x = (uint16_t)(value51 + value52);
            r->y = (uint16_t)(value50 + 2) | 0x0600;
            r->mf = 0;
            r->xf = 0;
            i_mvn(c, 0xC8, 0x7E); /* copy up bank $C8 to bank $7E */
            r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
            RETURN_RTS(c);
        }
        uint8_t value55 = RAM8(0xD201 + x);
        uint8_t a12;
        uint8_t y7;
        if (value55 != 0) {
            uint8_t value56 = RAM8(0xD206 + x);
            uint8_t a10;
            if (!((uint8_t)(value56 - 1) & 0x80)) {
                a10 = (uint8_t)(value56 - 1);
            } else {
                RAM8(0xD201 + x) = value55 ^ 1;
                a10 = 0;
            }
            a12 = a10;
            y7 = (uint8_t)((a_hi << 8) | value56);
        } else {
            uint8_t value57 = RAM8(0xD206 + x);
            uint8_t a11;
            if ((uint8_t)(value57 + 1) < 0x0F) {
                a11 = (uint8_t)(value57 + 1);
            } else {
                RAM8(0xD201 + x) = value55 ^ 1;
                a11 = 0x0F;
            }
            a12 = a11;
            y7 = (uint8_t)((a_hi << 8) | value57);
        }
        RAM8(0xD206 + x) = a12;
        BUS8_SET(c, 0x004202, y7);
        BUS8_SET(c, 0x004203, 0x1E);
        uint16_t value58 = RAM16(0xD204 + x);
        uint16_t value59 = RAM16(0xD208 + x);
        uint16_t value60 = BUS16(c, 0x004216);
        RAM8(0x0000 + sp0) = 0;
        RAM8(0x0000 + sp0 - 1) = x;
        r->a = 0x1D;
        r->x = (uint16_t)(value59 + value60);
        r->y = (uint16_t)(value58 + 2) | 0x0600;
        r->mf = 0;
        r->xf = 0;
        i_mvn(c, 0x7E, 0x7E); /* copy up bank $7E to bank $7E */
        uint16_t y_moved6 = r->y;
        r->x = (uint8_t)((RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1));
        r->y = (uint8_t)y_moved6;
        r->mf = 1;
        r->xf = 1;
        RETURN_RTS(c);
    }
    RAM8(0xD206 + x)++;
    uint16_t value63 = RAM16(0xD204 + x);
    uint16_t value64 = RAM16(0xD206 + x);
    if (((uint16_t)(value64 << 1) & 0x1E) != 0x1E) {
        uint16_t value65 = RAM16(0xD208 + x);
        RAM8(0x0000 + sp0) = 0;
        RAM8(0x0000 + sp0 - 1) = x;
        uint16_t value66 = BUS16(c, 0xC80000 + (uint16_t)(((uint16_t)(value64 << 1) & 0x1E) + value65));
        RAM16_SET(0x0600 + (value63 | 0x1E), value66);
        uint8_t value67 = RAM8(0x0000 + sp0 - 1);
        uint8_t value68 = RAM8(0x0000 + sp0);
        r->a = value66;
        r->x = (value68 << 8) | value67;
        r->y = value63 | 0x1E;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value69 = RAM16(0xDE00 + (value63 | 0x1E));
    RAM16_SET(0x0600 + (value63 | 0x1E), value69);
    r->a = value69;
    r->y = value63 | 0x1E;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2BB0F, SOM_RTS, "gen", advance_one_timed_menu_tile_record_and_publish_native_tiles, 0, L_B | L_X | L_Y, 2, 1, 1, 289, 137)
