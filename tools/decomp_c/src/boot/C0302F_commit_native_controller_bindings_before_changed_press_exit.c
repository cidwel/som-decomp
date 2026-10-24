#include "som_c.h"

/* C0302F commit_native_controller_bindings_before_changed_press_exit   [class A, 20 bytes, 8 instructions]
 * Source: src/rom/commit_native_controller_bindings_before_changed_press_exit.s
 * Documented in docs/ui-native-controller-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void commit_native_controller_bindings_before_changed_press_exit(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSL(c, 0x3032, 0xC76FA7); /* commit_three_native_controller_bindings_to_runtime_and_save_records */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x3035, 0xC0325A); /* compare_selected_pad_buttons_against_native_previous_buttons */
    uint16_t a_all2 = r->a;
    bool zero_ret2 = r->z;
    bool negative_ret2 = r->n;
    uint8_t a1;
    bool zero1;
    bool negative1;
    if (zero_ret2) {
        a1 = (uint8_t)a_all2;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
    } else {
        RAM8(0xA20A) |= 1;
        uint8_t value2 = RAM8(0xA212);
        RAM8(0xA212) &= 0xDF;
        a1 = 0x20;
        zero1 = (value2 & 0x20) == 0;
        negative1 = 0;
    }
    SET_A8(r, a1);
    r->z = zero1;
    r->n = negative1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0302F, SOM_RTS, "gen", commit_native_controller_bindings_before_changed_press_exit, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 20, 8)
