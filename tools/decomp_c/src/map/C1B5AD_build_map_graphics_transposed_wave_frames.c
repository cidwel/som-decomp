#include "som_c.h"

/* C1B5AD build_map_graphics_transposed_wave_frames   [class B, 39 bytes, 20 instructions]
 * Source: src/rom/build_map_graphics_transposed_wave_frames.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: B.
 */
static void build_map_graphics_transposed_wave_frames(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    uint16_t value = RAM16(0x0006);
    r->mf = 0;
    r->sp -= 2;
    JSR(c, 0xB5B4, 0xC1B5D4); /* transpose_map_graphics_four_plane_block */
    r->sp += 2;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 2;
    JSR(c, 0xB5B7, 0xC1B687); /* build_map_graphics_wave_frames */
    r->sp += 2;
    RAM16_SET(0x0006, value);
    uint8_t a_hi1 = value >> 8;
    uint8_t x1 = 0x10;
    for (;;) {
        r->x = x1;
        r->mf = 1;
        r->xf = 1;
        r->db = 0x7F;
        r->dp = 0;
        JSR(c, 0xB5C3, 0xC1B5D4); /* transpose_map_graphics_four_plane_block */
        uint16_t value2 = RAM16(0x0006);
        RAM16_SET(0x0006, (uint16_t)(value2 + 0x40));
        a_hi1 = (uint16_t)(value2 + 0x40) >> 8;
        x1 = (uint8_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7F;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1B5AD, SOM_RTS, "gen", build_map_graphics_transposed_wave_frames, 0, L_B, 2, 1, 1, 39, 20)
