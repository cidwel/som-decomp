#include "som_c.h"

/* C2A15B apply_map_tile_separate_sign_delta   [class A, 33 bytes, 19 instructions]
 * Source: src/rom/apply_map_tile_separate_sign_delta.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: XY.
 */
static void apply_map_tile_separate_sign_delta(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    uint8_t value = RAM8(0x0001);
    RAM8(0x0001) >>= 1;
    if (value & 0x01) {
        RAM8(0x0001) = (uint8_t)((a ^ 0x3F) + 1);
        uint8_t value2 = RAM8(0x0004);
        uint8_t value3 = RAM8(0x0001);
        RAM8(0x0004) = (uint8_t)(value2 - value3);
        if (value2 < value3) {
            RAM8(0x0005)--;
        }
        RETURN_RTS(c);
    }
    uint8_t value4 = RAM8(0x0004);
    RAM8(0x0004) = (uint8_t)(a + value4);
    if (a + value4 > 0xFF) {
        RAM8(0x0005)++;
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2A15B, SOM_RTS, "gen", apply_map_tile_separate_sign_delta, 0, L_X | L_Y, 1, 1, 1, 33, 19)
