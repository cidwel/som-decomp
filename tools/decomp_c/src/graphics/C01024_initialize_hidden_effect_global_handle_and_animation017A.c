#include "som_c.h"

/* C01024 initialize_hidden_effect_global_handle_and_animation017A   [class B, 63 bytes, 23 instructions]
 * Source: src/rom/initialize_hidden_effect_global_handle_and_animation017A.s
 * Documented in docs/boss-native59-hidden-child.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void initialize_hidden_effect_global_handle_and_animation017A(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM8(0x0000 + value) = 0;
    RAM16_SET(0x1D14, value);
    RAM16_SET(0x1D16, RAM16(0x0289));
    RAM16_SET(0x0022 + value, 0x07FF);
    RAM16_SET(0x002B + value, 0x68);
    RAM16_SET(0x0032 + value, 0);
    RAM16_SET(0x009A + value, 0x017A);
    RAM16_SET(0x009C + value, 0);
    RAM16_SET(0x009E + value, 1);
    RAM8(0x000B + value) = 1;
    RAM8(0x00A2 + value) = 0xCA;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01024, SOM_RTS, "gen", initialize_hidden_effect_global_handle_and_animation017A, 0, 0, 1, 1, 0, 63, 23)
