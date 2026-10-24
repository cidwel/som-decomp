#include "som_c.h"

/* C09CAB clear_scene_oam_and_initialize_color_targets   [class B, 46 bytes, 22 instructions]
 * Source: src/rom/clear_scene_oam_and_initialize_color_targets.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: V.
 */
static void clear_scene_oam_and_initialize_color_targets(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t x1 = 0;
    bool carry1 = carry;
    for (;;) {
        BUS16_SET(c, 0x000800 + x1, 0xE0FF);
        uint16_t x1_next = (uint16_t)(x1 + 4);
        bool carry1_next = (uint16_t)(x1 + 4) >= 0x0200;
        x1 = x1_next;
        carry1 = carry1_next;
        if (!(x1 < 0x0200)) break;
    }
    uint8_t x2 = 0x3F;
    for (;;) {
        RAM8(0x0A00 + x2) = 0;
        x2 = (uint8_t)(x2 - 1);
        if (!(!(x2 & 0x80))) break;
    }
    r->a = 0xE000;
    r->x = x2;
    r->y = y;
    r->c = carry1;
    r->v = overflow;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9CCD, 0xC09A91); GUARD_JSR(c, sp_call, 0x9CCD); } /* publish_scene_oam_buffer_through_dma_seven */
    uint16_t a_all = r->a;
    RAM8(0x007C) = 0;
    RAM8(RING_OPEN) = 0;
    r->a = (a_all >> 8 << 8) | 0;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->xf = 1;
    TAIL_CALL(c, 0xC09D67, SOM_RTS); /* copy_selected_scene_color_targets_to_current_values */
}
SOM_REGISTER(0xC09CAB, SOM_RTS, "gen", clear_scene_oam_and_initialize_color_targets, 0, L_V, 1, 1, 1, 46, 22)
