#include "som_c.h"

/* C093B3 transfer_controller_reset_hotkey_to_cold_boot   [class B, 129 bytes, 67 instructions]
 * Source: src/rom/transfer_controller_reset_hotkey_to_cold_boot.s
 * Documented in docs/game-controller-poll.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void transfer_controller_reset_hotkey_to_cold_boot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->c = 0;
    /* jump_to_cold_boot restarts the game and never comes back to the pushed address; the test window closes at the first RTS
     * taken at this routine's entry S, which is where the original code is cut. */
    push8(c, r->k);
    push16(c, 0x93B7);
    som_call_frame(c, 0xC10010, SOM_RTS, 3);
}
SOM_REGISTER(0xC093B3, SOM_RTS, "hand", transfer_controller_reset_hotkey_to_cold_boot, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 1, 129, 67)
