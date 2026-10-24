#include "som_c.h"

/* C21F07 prepare_boss_animation_piece_vertical_offset   [class A, 30 bytes, 17 instructions]
 * Source: src/rom/prepare_boss_animation_piece_vertical_offset.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0200.  Callers read: Y.
 */
static void prepare_boss_animation_piece_vertical_offset(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint8_t value;
    BUS8_OK(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + 1, value);
    RAM8(0x026C) = (uint8_t)(value + RAM8(0x0294));
    if ((RAM8(0x028D) & 0x80) != 0) {
        RAM8(0x026C) = (uint8_t)(((uint8_t)(RAM8(0x0270) + RAM8(0x026C)) ^ 0xFF) + 1);
    }
    BUS8_SET(c, RAM16(0x027C) + 0x7E0001, RAM8(0x026C));
    r->y = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21F07, SOM_RTS, "hand", prepare_boss_animation_piece_vertical_offset, 0, L_Y, 1, 1, 1, 30, 17)
