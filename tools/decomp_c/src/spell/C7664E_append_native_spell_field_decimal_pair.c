#include "som_c.h"

/* C7664E append_native_spell_field_decimal_pair   [class A, 19 bytes, 9 instructions]
 * Source: src/rom/append_native_spell_field_decimal_pair.s
 * Documented in docs/ui-native-spell-item-labels.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BX.
 */
static void append_native_spell_field_decimal_pair(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0xA171, 0x58);
    r->sp -= 2;
    JSR(c, 0x6657, 0xC766BF); /* derive_native_selected_actor_field_offset */
    r->sp += 2;
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint8_t value = RAM8(0xE180 + x_ret);
    r->a = (a_all >> 8 << 8) | value;
    r->x = x;
    r->y = (a_all >> 8 << 8) | value;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x665F, 0xC75AFC); /* format_and_append_native_saved_slot_decimal_pair */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7664E, SOM_RTS, "gen", append_native_spell_field_decimal_pair, 0, L_B | L_X, 2, 1, 0, 19, 9)
