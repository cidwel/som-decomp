#include "som_c.h"
#include "som_hand_d.h"

/* C01A96 read_numeric_choice_controller_and_dispatch_button_actions   [class B, 57 bytes, 25 instructions]
 * Source: src/rom/read_numeric_choice_controller_and_dispatch_button_actions.s
 * Documented in docs/event-dialogue-numeric-selection.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void read_numeric_choice_controller_and_dispatch_button_actions(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    i_sep(r, 0x10);
    JSL(c, 0x1A9B, 0x008000); /* public_controller_poll_long */
    i_rep(r, 0x10);
    a_ldx(r, RAM16(0xA182));
    a_lda(r, dp_rd8(c, 0x43 + r->x)); /* buttons newly pressed */
    if (r->z) {
        REQUIRE_M8(c);
        a_lda(r, 0x02);
        RAM8(0xA187) = m_trb(r, RAM8(0xA187)); /* released: allow the next press */
    } else {
        i_xba(r);
        a_lda(r, RAM8(0xA187));
        a_biti(r, 0x02);
        if (r->z) {
            i_xba(r);
            a_cmp(r, 0x80);
            JSR(c, 0x1AB9, 0xC01ACF); /* confirm_numeric_choice_and_advance_selected_script */
            REQUIRE_M8(c);
            a_cmp(r, 0x40);
            JSR(c, 0x1ABE, 0xC01AF1); /* cancel_numeric_choice_when_script_cancellation_is_available */
            REQUIRE_M8(c);
            a_cmp(r, 0x02);
            JSR(c, 0x1AC3, 0xC01B20); /* move_numeric_choice_up_with_native_wraparound */
            REQUIRE_M8(c);
            a_cmp(r, 0x01);
            JSR(c, 0x1AC8, 0xC01B3B); /* move_numeric_choice_down_with_native_wraparound */
            REQUIRE_M8(c);
            a_lda(r, 0x02);
            RAM8(0xA187) = m_tsb(r, RAM8(0xA187));
        }
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01A96, SOM_RTS, "hand", read_numeric_choice_controller_and_dispatch_button_actions, 0, 0, 1, 1, 0, 57, 25)
