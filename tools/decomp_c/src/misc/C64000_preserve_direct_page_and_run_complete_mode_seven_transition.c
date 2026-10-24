#include "som_c.h"

/* C64000 preserve_direct_page_and_run_complete_mode_seven_transition   [class A, 40 bytes, 18 instructions]
 * Source: src/rom/preserve_direct_page_and_run_complete_mode_seven_transition.s
 * Documented in docs/ui-native-mode7-transition.md
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: BYCV.
 */
static void preserve_direct_page_and_run_complete_mode_seven_transition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t x_entry = r->xf;
    const bool carry = r->c;
    const bool overflow = r->v;
    r->a = 0x2F;
    r->x = 0x20;
    r->y = 0x1040;
    r->mf = 0;
    r->xf = 0;
    i_mvn(c, 0x00, 0x00); /* copy up bank $00 to bank $00 */
    r->mf = 1;
    r->sp -= 2;
    JSR(c, 0x4014, 0xC64028); /* run_complete_three_phase_mode_seven_transition */
    r->sp += 2;
    r->a = 0x2F;
    r->x = 0x1040;
    r->y = 0x20;
    r->mf = 0;
    r->xf = 0;
    i_mvn(c, 0x00, 0x00); /* copy up bank $00 to bank $00 */
    r->c = carry;
    r->v = overflow;
    r->mf = 1;
    r->xf = x_entry;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC64000, SOM_RTL, "gen", preserve_direct_page_and_run_complete_mode_seven_transition, 0, L_B | L_Y | L_C | L_V, 2, 1, -1, 40, 18)
