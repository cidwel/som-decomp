#include "som_c.h"

/* C0824E derive_automatic_ui_map_target_before_native_stack_reset   [class A, 18 bytes, 8 instructions]
 * Source: src/rom/derive_automatic_ui_map_target_before_native_stack_reset.s
 * Documented in docs/ui-native-ui-frame-motion-chain.md
 * Entry: M=8 bit X=8 bit DB=any D=any.  Callers read: BXYC.
 */
static void derive_automatic_ui_map_target_before_native_stack_reset(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    const uint16_t sp_entry = r->sp;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8250, 0xC081ED); GUARD_JSR(c, sp_call, 0x8250); } /* derive_complete_map_target_from_ui_coordinate_sectors */
    uint16_t dp_ret = r->dp;
    RAM8(0x00E8 + dp_ret) = 0;
    r->sp = 0x01FF;
    r->x = 0x01FF;
    r->mf = 1;
    r->xf = 0;
    /* The callee runs on the reset stack and never returns; the original code is cut at the first RTS taken at the entry S of this routine. */
    som_call_frame(c, 0xC0B03F, SOM_RTS, (uint16_t)(sp_entry - r->sp)); /* initialize_main_map_loop_before_native_nmi_wait */
    return;
}
SOM_REGISTER(0xC0824E, SOM_RTS, "hand", derive_automatic_ui_map_target_before_native_stack_reset, 0, L_B | L_X | L_Y | L_C, 1, 1, 1, 18, 8)
