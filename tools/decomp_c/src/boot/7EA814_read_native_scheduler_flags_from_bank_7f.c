#include "som_c.h"

/* 7EA814 read_native_scheduler_flags_from_bank_7f   [class A, 18 bytes, 13 instructions]
 * Source: src/boot/read_native_scheduler_flags_from_bank_7f.s
 * Documented in docs/boot-native-scheduler-flags.md
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: ABXYCV.
 */
static void read_native_scheduler_flags_from_bank_7f(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    SET_A8(r, RAM8(0x10096));
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA814, SOM_RTS, "gen", read_native_scheduler_flags_from_bank_7f, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 5, 1, 0, 18, 13)
