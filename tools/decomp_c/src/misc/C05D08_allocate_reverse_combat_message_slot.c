#include "som_c.h"

/* C05D08 allocate_reverse_combat_message_slot   [class B, 43 bytes, 21 instructions]
 * Source: src/rom/allocate_reverse_combat_message_slot.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void allocate_reverse_combat_message_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint8_t value = RAM8(0x03A2);
    uint8_t a1;
    if (!((uint8_t)(value - 1) & 0x80)) {
        a1 = (uint8_t)(value - 1);
    } else {
        a1 = 0x0B;
    }
    RAM8(0x03A2) = a1;
    BUS8_SET(c, 0x004202, a1);
    BUS8_SET(c, 0x004203, 0x1E);
    uint16_t value2 = BUS16(c, 0x004216);
    r->y = value2;
    r->mf = 0;
    JSR(c, 0x5D27, 0xC05D33); /* clear_message_queue_line */
    uint16_t y_ret = r->y;
    RAM8(0xFE00 + y_ret) = 0x60;
    RAM8(0x039F)++;
    r->y = (uint16_t)(y_ret + 1);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC05D08, SOM_RTS, "gen", allocate_reverse_combat_message_slot, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 43, 21)
