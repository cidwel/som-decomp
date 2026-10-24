#include "som_c.h"

/* C1B687 build_map_graphics_wave_frames   [class C, 45 bytes, 25 instructions]
 * Source: src/rom/build_map_graphics_wave_frames.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: B.
 */
static void build_map_graphics_wave_frames(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    uint16_t value = RAM16(0x0006);
    r->a = 0x03C0;
    r->x = value;
    r->y = (uint16_t)(value + 0x40);
    r->mf = 0;
    r->xf = 0;
    i_mvn(c, 0x7F, 0x7F); /* copy up bank $7F to bank $7F */
    uint8_t a_hi1 = 0xFF;
    uint8_t x1 = 0;
    for (;;) {
        r->a = (a_hi1 << 8) | a;
        r->x = x1;
        r->mf = 1;
        r->xf = 1;
        r->db = 0x7F;
        r->dp = 0;
        JSR(c, 0xB69D, 0xC1B6B4); /* rotate_map_graphics_wave_frame */
        uint16_t a_all = r->a;
        uint8_t x_ret = r->x;
        uint8_t a1;
        if ((uint8_t)(x_ret + 8) < 0x10) {
            a1 = (uint8_t)(x_ret + 8);
        } else {
            a1 = (uint8_t)(x_ret + 8) & 0x0F;
        }
        r->a = (a_all >> 8 << 8) | a1;
        r->x = (uint8_t)((a_all >> 8 << 8) | a1);
        r->mf = 1;
        r->xf = 1;
        r->sp -= 1;
        JSR(c, 0xB6AC, 0xC1B6B4); /* rotate_map_graphics_wave_frame */
        r->sp += 1;
        uint16_t a_all2 = r->a;
        a_hi1 = a_all2 >> 8;
        x1 = (uint8_t)(x_ret + 1);
        if (!(x1 < 0x10)) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7F;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1B687, SOM_RTS, "gen", build_map_graphics_wave_frames, 0, L_B, 1, 1, 1, 45, 25)
