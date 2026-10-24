#include "som_c.h"

/* C1B6B4 rotate_map_graphics_wave_frame   [class A, 11 bytes, 7 instructions]
 * Source: src/rom/rotate_map_graphics_wave_frame.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: BX.
 */
static void rotate_map_graphics_wave_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t x = r->x;
    RAM8(0x0000 + sp0) = x;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB6B7, 0xC1B6BF); GUARD_JSR(c, sp_call, 0xB6B7); } /* rotate_map_graphics_wave_plane */
    r->sp += 1;
    uint8_t value = RAM8(0x0000 + sp0);
    RAM8(0x0000 + sp0) = value;
    r->x = value;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB6BC, 0xC1B6BF); GUARD_JSR(c, sp_call, 0xB6BC); } /* rotate_map_graphics_wave_plane */
    r->sp += 1;
    r->x = RAM8(0x0000 + sp0);
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1B6B4, SOM_RTS, "gen", rotate_map_graphics_wave_frame, 0, L_B | L_X, 1, 1, 1, 11, 7)
