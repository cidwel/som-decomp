#include "som_c.h"

/* C05BCA enqueue_numeric_boss_attack_notice_preserving_context   [class A, 32 bytes, 20 instructions]
 * Source: src/rom/enqueue_numeric_boss_attack_notice_preserving_context.s
 * Documented in docs/boss-native-spell-status-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYCV.
 */
static void enqueue_numeric_boss_attack_notice_preserving_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool carry = r->c;
    uint16_t value = BUS16(c, 0xC05E0B + (uint16_t)(a << 1));
    r->x = value;
    r->c = a & 0x8000;
    r->mf = 1;
    r->dp = 0x0300;
    r->sp -= 4;
    JSR(c, 0x5BE2, 0xC05D08); /* allocate_reverse_combat_message_slot */
    r->sp += 4;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 4;
    JSR(c, 0x5BE5, 0xC05C2A); /* append_rom_message_text */
    r->sp += 4;
    r->c = carry;
    r->mf = 0;
    r->xf = 0;
    r->dp = 0x0200;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC05BCA, SOM_RTL, "gen", enqueue_numeric_boss_attack_notice_preserving_context, 0, L_B | L_Y | L_C | L_V, 5, 0, 0, 32, 20)
