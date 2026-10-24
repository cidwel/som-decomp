#include "som_c.h"

/* C0E355 initialize_map_sprite_workspace   [class B, 45 bytes, 22 instructions]
 * Source: src/rom/initialize_map_sprite_workspace.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void initialize_map_sprite_workspace(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
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
    RAM8(0x007C) = 0;
    RAM8(RING_OPEN) = 0;
    RAM8(0x005A) = 0;
    RAM8(0x0059) = 0;
    r->a = 0xE001;
    r->x = x2;
    r->y = (uint8_t)y;
    r->c = carry1;
    r->z = 0;
    r->n = 0;
    r->v = overflow;
    r->xf = 1;
    TAIL_CALL(c, 0xC0E8D7, SOM_RTS); /* order_map_sprite_actor_groups */
}
SOM_REGISTER(0xC0E355, SOM_RTS, "gen", initialize_map_sprite_workspace, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 45, 22)
