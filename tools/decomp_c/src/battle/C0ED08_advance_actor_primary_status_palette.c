#include "som_c.h"

/* C0ED08 advance_actor_primary_status_palette   [class B, 388 bytes, 187 instructions]
 * Source: src/rom/advance_actor_primary_status_palette.s
 * Documented in docs/actor-status-palette-animation.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void advance_actor_primary_status_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    RAM8(0x0000) = a;
    if ((RAM8(0x00F4) & 3) == 0) {
        uint8_t value2 = RAM8(0x0000);
        if ((value2 & 0x20) == 0) {
            uint8_t a5;
            if ((value2 & 0x40) != 0) {
                uint8_t value3 = RAM8(0xE103 + x);
                uint8_t value4 = RAM8(0xE101 + x);
                uint8_t a2;
                if (value3 == value4) {
                    RAM8(0xE103 + x) = (uint8_t)(value3 + 1);
                    RAM8(0xE100 + x) ^= 0x40;
                    a2 = (uint8_t)(value3 + 1);
                } else {
                    uint8_t a1;
                    if (value3 >= value4) {
                        RAM8(0xE103 + x) = (uint8_t)(value3 - 1);
                        a1 = (uint8_t)(value3 - 1);
                    } else {
                        RAM8(0xE103 + x) = (uint8_t)(value3 + 1);
                        RAM8(0xE100 + x) ^= 0x40;
                        a1 = (uint8_t)(value3 + 1);
                    }
                    a2 = a1;
                }
                a5 = a2;
            } else {
                uint8_t value7 = RAM8(0xE103 + x);
                uint8_t value8 = RAM8(0xE102 + x);
                uint8_t a4;
                if (value7 < value8) {
                    RAM8(0xE103 + x) = (uint8_t)(value7 + 1);
                    a4 = (uint8_t)(value7 + 1);
                } else {
                    uint8_t value9 = RAM8(0x0000);
                    RAM8(0x0000) >>= 1;
                    uint8_t a3;
                    if (value9 & 0x01) {
                        RAM8(0xE103 + x) = (uint8_t)(value7 - 1);
                        RAM8(0xE100 + x) ^= 0x40;
                        a3 = (uint8_t)(value7 - 1);
                    } else {
                        uint8_t value11 = RAM8(0xE101 + x);
                        RAM8(0xE103 + x) = value11;
                        a3 = value11;
                    }
                    a4 = a3;
                }
                a5 = a4;
            }
            uint16_t value12 = RAM16(0xE0F8 + x);
            BUS8_SET(c, 0x004202, a5);
            BUS8_SET(c, 0x004203, 0x1E);
            RAM8(0x000F) = 0xC8;
            uint16_t value13 = BUS16(c, 0x004216);
            RAM16_SET(0x000D, (uint16_t)(value13 + 0x1000));
            RAM16_SET(0x000A, 0x0F);
            uint8_t a_hi1 = 0;
            uint16_t y1 = value12;
            do {
                uint16_t value14;
                BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D), value14);
                RAM16_SET(0x0700 + y1, value14);
                RAM16_SET(0x000D, (uint16_t)(RAM16(0x000D) + 1));
                RAM16_SET(0x000D, (uint16_t)(RAM16(0x000D) + 1));
                RAM16_SET(0x000A, (uint16_t)(RAM16(0x000A) - 1));
                a_hi1 = value14 >> 8;
                y1 = (uint16_t)(y1 + 2);
            } while (RAM16(0x000A) != 0);
            r->a = (a_hi1 << 8) | a;
            r->x = x;
            r->y = y1;
            r->c = value13 + 0x1000 > 0xFFFF;
            r->v = (((uint16_t)(value13 + 0x1000) ^ 0x1000) & (value13 ^ (uint16_t)(value13 + 0x1000)) & 0x8000) != 0;
            RETURN_RTS(c);
        }
        uint8_t value15 = RAM8(0xE103 + x);
        uint8_t value16 = RAM8(0xE101 + x);
        uint16_t value17 = RAM16(0xE0F8 + x);
        RAM8(sp0) = value15; /* PHA of the 16-bit (value15 << 8 | value16) */
        RAM8((uint16_t)(sp0 - 1)) = value16;
        uint8_t a6 = value16;
        uint8_t a_hi2 = value15;
        uint16_t y2 = (uint16_t)(value17 - 2);
        for (;;) {
            RAM16_SET(0x000E, y2);
            uint16_t value18 = RAM16(0x000E);
            RAM16_SET(0x000E, (uint16_t)((((((uint8_t)((a_hi2 << 8) | a6) << 8) | a_hi2) & 0x0F) << 1) + value18));
            uint16_t value19 = RAM16(0x0700 + (uint16_t)(((((a_hi2 << 8) | a6) & 0x0F) << 1) + value18));
            RAM8(sp0) = value19 >> 8; /* PHA */
            RAM8((uint16_t)(sp0 - 1)) = (uint8_t)value19;
            uint8_t a_hi3 = value19 >> 8;
            uint16_t y3 = (uint16_t)(((((a_hi2 << 8) | a6) & 0x0F) << 1) + value18);
            bool carry1 = (((((uint8_t)((a_hi2 << 8) | a6) << 8) | a_hi2) & 0x0F) << 1) + value18 > 0xFFFF;
            for (;;) {
                uint16_t value20 = RAM16(0x0702 + y3);
                RAM16_SET(0x0700 + y3, value20);
                uint16_t value21 = RAM16(0x000E);
                uint8_t a_hi3_next = value20 >> 8;
                uint16_t y3_next = (uint16_t)(y3 + 2);
                bool carry1_next = (uint16_t)(y3 + 2) >= value21;
                a_hi3 = a_hi3_next;
                y3 = y3_next;
                carry1 = carry1_next;
                if (!(y3 < value21)) break;
            }
            const uint16_t pulled = (uint16_t)(RAM8((uint16_t)(sp0 - 1)) | (RAM8(sp0) << 8)); /* PLA */
            RAM16_SET(0x0700 + y3, pulled);
            r->a = pulled;
            r->x = x;
            r->y = y3;
            r->c = carry1;
            r->v = (((((((uint8_t)((a_hi2 << 8) | a6) << 8) | a_hi2) & 0x0F) << 1) ^ (uint16_t)((((((uint8_t)((a_hi2 << 8) | a6) << 8) | a_hi2) & 0x0F) << 1) + value18)) & (value18 ^ (uint16_t)((((((uint8_t)((a_hi2 << 8) | a6) << 8) | a_hi2) & 0x0F) << 1) + value18)) & 0x8000) != 0;
            RETURN_RTS(c);
        }
        uint8_t a11;
        if ((a6 & 0x40) != 0) {
            uint8_t value22 = RAM8(0xE107 + x);
            uint8_t value23 = RAM8(0xE105 + x);
            uint8_t a8;
            if (value22 == value23) {
                RAM8(0xE107 + x) = (uint8_t)(value22 + 1);
                RAM8(0xE104 + x) ^= 0x40;
                a8 = (uint8_t)(value22 + 1);
            } else {
                uint8_t a7;
                if (value22 >= value23) {
                    RAM8(0xE107 + x) = (uint8_t)(value22 - 1);
                    a7 = (uint8_t)(value22 - 1);
                } else {
                    RAM8(0xE107 + x) = (uint8_t)(value22 + 1);
                    RAM8(0xE104 + x) ^= 0x40;
                    a7 = (uint8_t)(value22 + 1);
                }
                a8 = a7;
            }
            a11 = a8;
        } else {
            uint8_t value26 = RAM8(0xE107 + x);
            uint8_t value27 = RAM8(0xE106 + x);
            uint8_t a10;
            if (value26 < value27) {
                RAM8(0xE107 + x) = (uint8_t)(value26 + 1);
                a10 = (uint8_t)(value26 + 1);
            } else {
                uint8_t value28 = RAM8(0x0000);
                RAM8(0x0000) >>= 1;
                uint8_t a9;
                if (value28 & 0x01) {
                    RAM8(0xE107 + x) = (uint8_t)(value26 - 1);
                    RAM8(0xE104 + x) ^= 0x40;
                    a9 = (uint8_t)(value26 - 1);
                } else {
                    uint8_t value30 = RAM8(0xE105 + x);
                    RAM8(0xE107 + x) = value30;
                    a9 = value30;
                }
                a10 = a9;
            }
            a11 = a10;
        }
        uint16_t value31 = RAM16(0xE0FA + x);
        BUS8_SET(c, 0x004202, a11);
        BUS8_SET(c, 0x004203, 0x0A);
        RAM8(0x000F) = 0xD1;
        uint16_t value32 = BUS16(c, 0x004216);
        RAM16_SET(0x000D, (uint16_t)(value32 + 0xF600));
        RAM16_SET(0x000A, 5);
        uint8_t a_hi4 = 0;
        uint16_t y4 = value31;
        do {
            uint16_t value33;
            BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D), value33);
            RAM16_SET(0x0700 + y4, value33);
            RAM16_SET(0x000D, (uint16_t)(RAM16(0x000D) + 1));
            RAM16_SET(0x000D, (uint16_t)(RAM16(0x000D) + 1));
            RAM16_SET(0x000A, (uint16_t)(RAM16(0x000A) - 1));
            a_hi4 = value33 >> 8;
            y4 = (uint16_t)(y4 + 2);
        } while (RAM16(0x000A) != 0);
        r->a = (a_hi4 << 8) | a;
        r->x = x;
        r->y = y4;
        r->c = value32 + 0xF600 > 0xFFFF;
        r->v = (((uint16_t)(value32 + 0xF600) ^ 0xF600) & (value32 ^ (uint16_t)(value32 + 0xF600)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0ED08, SOM_RTS, "hand", advance_actor_primary_status_palette, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 388, 187)
