#include "som_c.h"

/* C004E2 expand_dialogue_window_tile_forward_with_plane_mask   [class B, 51 bytes, 26 instructions]
 * Source: src/rom/expand_dialogue_window_tile_forward_with_plane_mask.s
 * Documented in docs/event-dialogue-render-core.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void expand_dialogue_window_tile_forward_with_plane_mask(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint8_t a1 = 8;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = (a_hi << 8) | a;
    uint16_t y1 = y;
    for (;;) {
        uint8_t value = BUS8(c, 0xD2D080 + x1);
        RAM8(0x9400 + y1) = value;
        uint8_t value2 = BUS8(c, 0xD2D081 + x1);
        RAM8(0x9401 + y1) = value2;
        RAM8(0x9410 + y1) = (value2 & RAM8(0xA171)) | RAM8(0x9400 + y1);
        RAM8(0x9411 + y1) = 0;
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = 0;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 2);
        if (!(a1 != a_hi1)) break;
    }
    r->a = (uint16_t)(y1 + 0x10);
    r->x = x1;
    r->y = (uint16_t)(y1 + 0x10);
    r->c = y1 + 0x10 > 0xFFFF;
    r->z = (uint16_t)(y1 + 0x10) == 0;
    r->n = (uint16_t)(y1 + 0x10) & 0x8000;
    r->v = ((y1 ^ (uint16_t)(y1 + 0x10)) & ((uint16_t)(y1 + 0x10) ^ 0x10) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC004E2, SOM_RTS, "gen", expand_dialogue_window_tile_forward_with_plane_mask, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 51, 26)
