#include "som_c.h"

/* C0C859 build_first_layer_tile_row   [class B, 150 bytes, 84 instructions]
 * Source: src/rom/build_first_layer_tile_row.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=8 bit DB=$7F D=$0000.  Callers read: ABXYCV.
 */
static void build_first_layer_tile_row(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t y = r->y;
    uint16_t value = RAM16(0x00AA);
    uint16_t value2 = RAM16(0x0000);
    uint16_t value3 = RAM16(0x00C2);
    uint8_t a1;
    uint8_t a_hi1;
    if ((uint16_t)(value + value2) < value3) {
        a1 = (uint8_t)(value + value2);
        a_hi1 = (uint16_t)(value + value2) >> 8;
    } else {
        a1 = (uint8_t)((uint16_t)(value + value2) - value3 - ((uint16_t)(value + value2) >= value3 ^ 1));
        a_hi1 = (uint16_t)((uint16_t)(value + value2) - value3 - ((uint16_t)(value + value2) >= value3 ^ 1)) >> 8;
    }
    RAM16_SET(0x0010, (uint16_t)(((((a_hi1 << 8) | a1) & 0x07F0) << 1 << 1 << 1) + RAM16(0x00C8) + ((((a_hi1 << 8) | a1) & 0x07F0) << 1 << 1 >> 0x0F)));
    RAM8(0x0004) = (uint8_t)(RAM16(0x00A8) >> 4);
    RAM16_SET(0x0076, (((uint16_t)(value2 + RAM16(0x00B2)) & 0xF0) << 1 << 1) | 0x5000);
    uint16_t value7 = RAM16(0x00B0);
    RAM8(0x0076) = (((uint8_t)value7 >> 3) & 0x1E) | RAM8(0x0076);
    RAM8(0x006D) = ((((uint8_t)value7 >> 3) & 0x1E) << 1) + 4 + ((((uint8_t)value7 >> 3) & 0x1E) >> 7);
    RAM8(0x006C) = (uint8_t)(((uint8_t)(((((uint8_t)value7 >> 3) & 0x1E) << 1) + 4 + ((((uint8_t)value7 >> 3) & 0x1E) >> 7) - 4) ^ 0x3F) + 1);
    if (value7 >> 8 != 0) {
        RAM8(0x0077) |= 4;
    }
    uint8_t a2 = 0;
    uint8_t a_hi2 = (uint8_t)(((uint8_t)(((((uint8_t)value7 >> 3) & 0x1E) << 1) + 4 + ((((uint8_t)value7 >> 3) & 0x1E) >> 7) - 4) ^ 0x3F) + 1);
    uint16_t x1 = 0;
    uint16_t y1 = y;
    bool carry1 = ((((uint8_t)value7 >> 3) & 0x1E) << 1) + 4 + ((((uint8_t)value7 >> 3) & 0x1E) >> 7) >= 4;
    bool overflow1 = ((((((uint8_t)value7 >> 3) & 0x1E) << 1) + 4 + ((((uint8_t)value7 >> 3) & 0x1E) >> 7) ^ 4) & (((((uint8_t)value7 >> 3) & 0x1E) << 1) + 4 + ((((uint8_t)value7 >> 3) & 0x1E) >> 7) ^ (uint8_t)(((((uint8_t)value7 >> 3) & 0x1E) << 1) + 4 + ((((uint8_t)value7 >> 3) & 0x1E) >> 7) - 4)) & 0x80) != 0;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            uint8_t value10 = RAM8(0x0004);
            RAM8(0x0004) = (uint8_t)(value10 + 1);
            uint8_t value11 = RAM8(0x009C);
            bool overflow2;
            if ((uint8_t)(value10 + 1) < value11) {
                overflow2 = overflow1;
            } else {
                RAM8(0x0004) = (uint8_t)((uint8_t)(value10 + 1) - value11 - ((uint8_t)(value10 + 1) >= value11 ^ 1));
                overflow2 = (((uint8_t)(value10 + 1) ^ value11) & ((uint8_t)(value10 + 1) ^ (uint8_t)((uint8_t)(value10 + 1) - value11 - ((uint8_t)(value10 + 1) >= value11 ^ 1))) & 0x80) != 0;
            }
            uint8_t value12 = BUS8(c, RAM16(0x0010) + 0x7F0000 + value10);
            RAM16_SET(0x1D000 + (uint8_t)x1, RAM16(0x1C000 + ((((a_hi2 << 8) | value12) & 0xFF) << 1 << 1 << 1)));
            RAM16_SET(0x1D044 + (uint8_t)x1, RAM16(0x1C004 + ((((a_hi2 << 8) | value12) & 0xFF) << 1 << 1 << 1)));
            RAM16_SET(0x1D000 + (uint8_t)x1 + 2, RAM16(0x1C002 + ((((a_hi2 << 8) | value12) & 0xFF) << 1 << 1 << 1)));
            uint16_t value16 = RAM16(0x1C006 + ((((a_hi2 << 8) | value12) & 0xFF) << 1 << 1 << 1));
            RAM16_SET(0x1D044 + (uint8_t)x1 + 2, value16);
            if ((uint8_t)x1 + 4 < 0x44) {
                uint8_t a2_next = (uint8_t)value16;
                uint8_t a_hi2_next = value16 >> 8;
                uint16_t x1_next = (uint8_t)x1 + 4;
                uint16_t y1_next = (((a_hi2 << 8) | value12) & 0xFF) << 1 << 1 << 1;
                bool carry1_next = (uint8_t)x1 + 4 >= 0x44;
                bool overflow1_next = overflow2;
                a2 = a2_next;
                a_hi2 = a_hi2_next;
                x1 = x1_next;
                y1 = y1_next;
                carry1 = carry1_next;
                overflow1 = overflow1_next;
                first_pass = false;
                continue;
            }
            uint8_t a2_next2 = (uint8_t)value16;
            uint8_t a_hi2_next2 = value16 >> 8;
            uint16_t x1_next2 = (uint8_t)x1 + 4;
            uint16_t y1_next2 = (((a_hi2 << 8) | value12) & 0xFF) << 1 << 1 << 1;
            bool carry1_next2 = (uint8_t)x1 + 4 >= 0x44;
            bool overflow1_next2 = overflow2;
            a2 = a2_next2;
            a_hi2 = a_hi2_next2;
            x1 = x1_next2;
            y1 = y1_next2;
            carry1 = carry1_next2;
            overflow1 = overflow1_next2;
            break;
        } else {
            uint8_t value17 = RAM8(0x0004);
            RAM8(0x0004) = (uint8_t)(value17 + 1);
            uint8_t value18 = RAM8(0x009C);
            bool overflow3;
            if ((uint8_t)(value17 + 1) < value18) {
                overflow3 = overflow1;
            } else {
                RAM8(0x0004) = (uint8_t)((uint8_t)(value17 + 1) - value18 - ((uint8_t)(value17 + 1) >= value18 ^ 1));
                overflow3 = (((uint8_t)(value17 + 1) ^ value18) & ((uint8_t)(value17 + 1) ^ (uint8_t)((uint8_t)(value17 + 1) - value18 - ((uint8_t)(value17 + 1) >= value18 ^ 1))) & 0x80) != 0;
            }
            uint8_t value19 = BUS8(c, RAM16(0x0010) + 0x7F0000 + value17);
            RAM16_SET(0x1D000 + (uint8_t)x1, RAM16(0x1C000 + ((((a_hi2 << 8) | value19) & 0xFF) << 1 << 1 << 1)));
            RAM16_SET(0x1D044 + (uint8_t)x1, RAM16(0x1C004 + ((((a_hi2 << 8) | value19) & 0xFF) << 1 << 1 << 1)));
            RAM16_SET(0x1D000 + (uint8_t)x1 + 2, RAM16(0x1C002 + ((((a_hi2 << 8) | value19) & 0xFF) << 1 << 1 << 1)));
            uint16_t value23 = RAM16(0x1C006 + ((((a_hi2 << 8) | value19) & 0xFF) << 1 << 1 << 1));
            RAM16_SET(0x1D044 + (uint8_t)x1 + 2, value23);
            if ((uint8_t)x1 + 4 < 0x44) {
                uint8_t a2_next3 = (uint8_t)value23;
                uint8_t a_hi2_next3 = value23 >> 8;
                uint16_t x1_next3 = (uint8_t)x1 + 4;
                uint16_t y1_next3 = (((a_hi2 << 8) | value19) & 0xFF) << 1 << 1 << 1;
                bool carry1_next3 = (uint8_t)x1 + 4 >= 0x44;
                bool overflow1_next3 = overflow3;
                a2 = a2_next3;
                a_hi2 = a_hi2_next3;
                x1 = x1_next3;
                y1 = y1_next3;
                carry1 = carry1_next3;
                overflow1 = overflow1_next3;
                continue;
            }
            uint8_t a2_next4 = (uint8_t)value23;
            uint8_t a_hi2_next4 = value23 >> 8;
            uint16_t x1_next4 = (uint8_t)x1 + 4;
            uint16_t y1_next4 = (((a_hi2 << 8) | value19) & 0xFF) << 1 << 1 << 1;
            bool carry1_next4 = (uint8_t)x1 + 4 >= 0x44;
            bool overflow1_next4 = overflow3;
            a2 = a2_next4;
            a_hi2 = a_hi2_next4;
            x1 = x1_next4;
            y1 = y1_next4;
            carry1 = carry1_next4;
            overflow1 = overflow1_next4;
            break;
        }
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C859, SOM_RTS, "gen", build_first_layer_tile_row, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 1, 150, 84)
