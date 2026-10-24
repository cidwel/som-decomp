#include "som_c.h"

/* C1EFE7 consume_event_gold_word_and_add_or_spend_with_native_cap   [class A, 19 bytes, 9 instructions]
 * Source: src/rom/consume_event_gold_word_and_add_or_spend_with_native_cap.s
 * Documented in docs/event-gold-hud-commands.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void consume_event_gold_word_and_add_or_spend_with_native_cap(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value;
    BUS16_OK(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 1, value);
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    uint8_t value2 = RAM8(0x0004);
    r->a = value;
    r->x = value2;
    r->y = 1;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    r->mf = 0;
    JSL(c, 0xEFF8, 0xC00057); /* jump_public_party_gold_transaction */
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1EFE7, SOM_RTS, "hand", consume_event_gold_word_and_add_or_spend_with_native_cap, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 19, 9)
