#include "som_c.h"

/* 7EC01E read_native_current_program_header_pointer   [class A, 18 bytes, 13 instructions]
 * Source: src/boot/read_native_current_program_header_pointer.s
 * Documented in docs/boot-native-pause-gate-header.md
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: BXYV.
 */
static void read_native_current_program_header_pointer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    r->x = RAM16(0x102E2);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC01E, SOM_RTS, "gen", read_native_current_program_header_pointer, 0, L_B | L_X | L_Y | L_V, 5, 1, 0, 18, 13)
