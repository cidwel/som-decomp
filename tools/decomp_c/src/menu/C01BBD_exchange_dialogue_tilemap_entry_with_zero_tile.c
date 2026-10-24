#include "som_c.h"

/* C01BBD exchange_dialogue_tilemap_entry_with_zero_tile   [class B, 58 bytes, 35 instructions]
 * Source: src/rom/exchange_dialogue_tilemap_entry_with_zero_tile.s
 * Documented in docs/event-dialogue-window-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void exchange_dialogue_tilemap_entry_with_zero_tile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0xA156);
    uint16_t value2 = RAM16(0xA157);
    uint16_t value3 = RAM16(0x0000 + (uint16_t)((uint16_t)((uint16_t)(((uint8_t)(value - 1) << 1 << 1 << 1 << 1 << 1) + value2 + ((uint8_t)(value - 1) << 1 << 1 << 1 << 1 >> 0x0F)) << 1) + 0x9C00));
    RAM16_SET(0x0000 + (uint16_t)((uint16_t)((uint16_t)(((uint8_t)(value - 1) << 1 << 1 << 1 << 1 << 1) + value2 + ((uint8_t)(value - 1) << 1 << 1 << 1 << 1 >> 0x0F)) << 1) + 0x9C00), 0x2000);
    r->a = ((value3 & 0xDFFF) >> 8 << 8) | 0x44;
    r->x = value3 & 0xDFFF;
    r->v = (((uint16_t)((uint16_t)(((uint8_t)(value - 1) << 1 << 1 << 1 << 1 << 1) + value2 + ((uint8_t)(value - 1) << 1 << 1 << 1 << 1 >> 0x0F)) << 1) ^ (uint16_t)((uint16_t)((uint16_t)(((uint8_t)(value - 1) << 1 << 1 << 1 << 1 << 1) + value2 + ((uint8_t)(value - 1) << 1 << 1 << 1 << 1 >> 0x0F)) << 1) + 0x9C00)) & ((uint16_t)((uint16_t)((uint16_t)(((uint8_t)(value - 1) << 1 << 1 << 1 << 1 << 1) + value2 + ((uint8_t)(value - 1) << 1 << 1 << 1 << 1 >> 0x0F)) << 1) + 0x9C00) ^ 0x9C00) & 0x8000) != 0;
    JSR(c, 0x1BF5, 0xC00FFA); /* request_dialogue_transfer_and_conditional_window_flags */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01BBD, SOM_RTS, "gen", exchange_dialogue_tilemap_entry_with_zero_tile, 0, L_B | L_X | L_Y | L_V, 5, 1, 0, 58, 35)
