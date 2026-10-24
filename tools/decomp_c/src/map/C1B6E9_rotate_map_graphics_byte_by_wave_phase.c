#include "som_c.h"

/* C1B6E9 rotate_map_graphics_byte_by_wave_phase   [class B, 64 bytes, 38 instructions]
 * Source: src/rom/rotate_map_graphics_byte_by_wave_phase.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: AXY.
 */
static void rotate_map_graphics_byte_by_wave_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t x = r->x;
    RAM8(0x0000) = a;
    if (x >= 8) {
        if (x == 8) {
            RETURN_RTS(c);
        }
        if (x != 9) {
            if (x == 0x0F) {
                SET_A8(r, (uint8_t)((a << 1) | (a >= 0x80)));
                RETURN_RTS(c);
            }
            uint8_t a1;
            if (x != 0x0C) {
                a1 = a;
            } else {
                a1 = (uint8_t)((a << 1) | (a >= 0x80));
            }
            SET_A8(r, (uint8_t)(((uint8_t)((a1 << 1) | (a1 >= 0x80)) << 1) | ((uint8_t)((a1 << 1) | (a1 >= 0x80)) >= 0x80)));
            RETURN_RTS(c);
        }
        SET_A8(r, (uint8_t)((a << 1) | (a >= 0x80)));
        RETURN_RTS(c);
    }
    if (x == 0) {
        RETURN_RTS(c);
    }
    if (x != 1) {
        if (x == 7) {
            uint8_t value = RAM8(0x0000);
            RAM8(0x0000) >>= 1;
            SET_A8(r, (a >> 1) | ((value & 1) << 7));
            RETURN_RTS(c);
        }
        uint8_t a2;
        if (x != 4) {
            a2 = a;
        } else {
            uint8_t value2 = RAM8(0x0000);
            RAM8(0x0000) >>= 1;
            a2 = (a >> 1) | ((value2 & 1) << 7);
        }
        uint8_t value3 = RAM8(0x0000);
        RAM8(0x0000) >>= 1;
        uint8_t value4 = RAM8(0x0000);
        RAM8(0x0000) >>= 1;
        SET_A8(r, (((a2 >> 1) | ((value3 & 1) << 7)) >> 1) | ((value4 & 1) << 7));
        RETURN_RTS(c);
    }
    uint8_t value5 = RAM8(0x0000);
    RAM8(0x0000) >>= 1;
    SET_A8(r, (a >> 1) | ((value5 & 1) << 7));
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1B6E9, SOM_RTS, "gen", rotate_map_graphics_byte_by_wave_phase, 0, L_A | L_X | L_Y, 1, 1, 1, 64, 38)
