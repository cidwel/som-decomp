#include "som_c.h"

/* C0C42C restore_map_saved_palette_rows   [class A, 49 bytes, 20 instructions]
 * Source: src/rom/restore_map_saved_palette_rows.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BYC.
 */
static void restore_map_saved_palette_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x0602, RAM16(0xDE02));
    RAM16_SET(0x0604, RAM16(0xDE04));
    RAM16_SET(0x0606, RAM16(0xDE06));
    RAM16_SET(0x0608, RAM16(0xDE08));
    RAM16_SET(0x060A, RAM16(0xDE0A));
    RAM16_SET(0x060C, RAM16(0xDE0C));
    RAM16_SET(0x060E, RAM16(0xDE0E));
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C42C, SOM_RTS, "gen", restore_map_saved_palette_rows, 0, L_B | L_Y | L_C, 2, 1, 0, 49, 20)
