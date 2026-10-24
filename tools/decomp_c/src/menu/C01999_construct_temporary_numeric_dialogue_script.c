#include "som_c.h"

/* C01999 construct_temporary_numeric_dialogue_script   [class B, 46 bytes, 20 instructions]
 * Source: src/rom/construct_temporary_numeric_dialogue_script.s
 * Documented in docs/event-dialogue-number-window.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYV.
 */
static void construct_temporary_numeric_dialogue_script(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t a1 = 4;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = 0;
    for (;;) {
        uint8_t inventory_gold = RAM8(INVENTORY_GOLD + x1);
        RAM8(0xA136 + y1) = inventory_gold;
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = inventory_gold;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 + 1);
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    JSL(c, 0x19B1, 0xC754DB); /* convert_24_bit_dialogue_quantity_to_seven_digit_fields */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x19B4, 0xC019C7); /* format_dialogue_quantity_digits_and_append_original_suffix */
    RAM16_SET(0x1D01, 0xA1E0);
    RAM8(0x1D03) = 0x7E;
    r->a = (r->a & 0x00FF) | (0xA1 << 8);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01999, SOM_RTS, "gen", construct_temporary_numeric_dialogue_script, 0, L_B | L_Y | L_V, 1, 1, 0, 46, 20)
