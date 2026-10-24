#include "som_c.h"

/* C03244 set_native_name_idle_timer   [class A, 6 bytes, 3 instructions]
 * Source: src/rom/set_native_name_idle_timer.s
 * Documented in docs/ui-native-name-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void set_native_name_idle_timer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0xA201) = 3;
    SET_A8(r, 3);
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC03244, SOM_RTS, "gen", set_native_name_idle_timer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 6, 3)
