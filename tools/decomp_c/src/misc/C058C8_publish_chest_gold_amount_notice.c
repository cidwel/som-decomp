#include "som_c.h"

/* C058C8 publish_chest_gold_amount_notice   [class B, 19 bytes, 9 instructions]
 * Source: src/rom/publish_chest_gold_amount_notice.s
 * Documented in docs/event-vm-chest-reward.md
 * Entry: M=8 bit X=16 bit DB=any D=$0300.  Callers read: nothing.
 */
static void publish_chest_gold_amount_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    r->sp -= 1;
    JSR(c, 0x58CB, 0xC05D08); /* allocate_reverse_combat_message_slot */
    r->sp += 1;
    RAM8(0x03D0) = a;
    RAM8(0x03D1) = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x58D3, 0xC05C6C); /* append_message_word_decimal */
    r->x = 0x6294;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x58D9, 0xC05C2A); /* append_rom_message_text */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC058C8, SOM_RTL, "gen", publish_chest_gold_amount_notice, 0, 0, 1, 1, 0, 19, 9)
