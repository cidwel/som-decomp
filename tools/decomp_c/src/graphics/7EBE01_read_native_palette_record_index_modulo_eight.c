#include "som_c.h"

/* 7EBE01 read_native_palette_record_index_modulo_eight   [class A, 30 bytes, 22 instructions]
 * Source: src/boot/read_native_palette_record_index_modulo_eight.s
 * Documented in docs/source-recovery-parallel-palette-apis.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0200.  Callers read: ABXYCZNV.
 */
static void read_native_palette_record_index_modulo_eight(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    r->a = ((uint16_t)(x - RAM16(0x102D2)) >> 5) & 7;
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EBE01, SOM_RTS, "gen", read_native_palette_record_index_modulo_eight, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 30, 22)
