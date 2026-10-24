#include "som_c.h"

/* C05745 initialize_new_game_save_records_preserving_context   [class B, 110 bytes, 47 instructions]
 * Source: src/rom/initialize_new_game_save_records_preserving_context.s
 * Documented in docs/ui-native-loaded-game-save-load.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: B.
 */
static void initialize_new_game_save_records_preserving_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t x1 = 0xCC00;
    uint16_t y1 = 0x24;
    for (;;) {
        RAM8(0x0000 + x1) = 0xFF;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    uint16_t x2 = x1;
    uint16_t y2 = 0x38;
    for (;;) {
        RAM8(0x0000 + x2) = 0xFF;
        x2 = (uint16_t)(x2 + 1);
        y2 = (uint16_t)(y2 - 1);
        if (!(y2 != 0)) break;
    }
    RAM8(0xCC2F) = 0xFE;
    RAM8(0xCC3B) = 0xFE;
    RAM8(0xCC47) = 0xFE;
    uint16_t value = BUS16(c, 0xC057B3);
    RAM16_SET(INVENTORY_GOLD, value);
    uint16_t value2 = BUS16(c, 0xC057B5);
    RAM16_SET(0xCFFC, value2);
    uint16_t value3 = BUS16(c, 0xC057B7);
    RAM16_SET(0xCC73, value3);
    uint8_t value4 = BUS8(c, 0xC057B9);
    RAM8(0xCC75) = value4;
    uint8_t value5 = BUS8(c, 0xC057BA);
    RAM8(0xCC7A) = value5;
    uint8_t value6 = BUS8(c, 0xC057BB);
    RAM8(0xCC7B) = value6;
    uint8_t value7 = BUS8(c, 0xC057BC);
    RAM8(0xCC7C) = value7;
    r->a = (value3 >> 8 << 8) | value7;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC05745, SOM_RTL, "gen", initialize_new_game_save_records_preserving_context, 0, L_B, 5, 1, 0, 110, 47)
