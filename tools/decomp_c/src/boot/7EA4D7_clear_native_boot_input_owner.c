#include "som_c.h"

/* 7EA4D7 clear_native_boot_input_owner   [class A, 18 bytes, 13 instructions]
 * Source: src/boot/clear_native_boot_input_owner.s
 * Documented in docs/boot-native-title-input-ownership.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: nothing.
 */
static void clear_native_boot_input_owner(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x10097) = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA4D7, SOM_RTS, "gen", clear_native_boot_input_owner, 0, 0, 5, 0, 0, 18, 13)
