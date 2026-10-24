#include "som_c.h"
#include "som_hand_d.h"

/* C29D26 finish_status_spell_child_after_three_ticks   [class A, 18 bytes, 8 instructions]
 * Source: src/rom/finish_status_spell_child_after_three_ticks.s
 * Documented in docs/boss-native-spell-status-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void finish_status_spell_child_after_three_ticks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    a_ldx(r, dp_rd16(c, 0x87)); /* child object */
    JSR(c, 0x9D2A, 0xC29CFA); /* set_status_single_or_three_spell_targets */
    REQUIRE_M16(c);
    a_lda(r, RAM16(OBJECT_AGE + r->x));
    a_cmp(r, 0x0003);
    if (r->c) {
        JSR(c, 0x9D35, 0xC29D38); /* resolve_single_or_three_spell_target_contacts */
        r->c = 1;
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29D26, SOM_RTS, "hand", finish_status_spell_child_after_three_ticks, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 18, 8)
