#include "som_c.h"

/* C2ABA9 copy_actor_sprite_list_to_workspace   [class A, 33 bytes, 20 instructions]
 * Source: src/rom/copy_actor_sprite_list_to_workspace.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void copy_actor_sprite_list_to_workspace(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t a1 = RAM16(0x0002) & 0xFF;
    uint8_t a_hi1 = 0;
    uint16_t x1 = x;
    uint16_t y1 = y;
    for (;;) {
        RAM8(0x0000 + sp0) = a_hi1;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi1 << 8) | a1);
        RAM16_SET(0xC000 + x1, RAM16(0x0000 + y1));
        RAM16_SET(0xC002 + x1, RAM16(0x0002 + y1));
        uint8_t value4 = RAM8(0x0000 + sp0 - 1);
        uint8_t value5 = RAM8(0x0000 + sp0);
        a1 = (uint8_t)(((value5 << 8) | value4) - 1);
        a_hi1 = (uint16_t)(((value5 << 8) | value4) - 1) >> 8;
        x1 = (uint16_t)(x1 + 4);
        y1 = (uint16_t)(y1 + 4);
        if (!((uint16_t)(((value5 << 8) | value4) - 1) != 0)) break;
    }
    r->x = x1;
    r->y = y1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2ABA9, SOM_RTS, "gen", copy_actor_sprite_list_to_workspace, 0, L_X | L_Y, 2, 0, 0, 33, 20)
