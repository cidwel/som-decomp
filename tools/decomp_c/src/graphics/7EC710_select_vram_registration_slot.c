#include "som_c.h"

/* 7EC710 select_vram_registration_slot   [class B, 43 bytes, 26 instructions]
 * Source: src/boot/select_vram_registration_slot.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: ABXYV.
 */
static void select_vram_registration_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t a = r->a;
    BUS16_SET(c, 0x004202, 8 << 8 | (((uint8_t)a >> 2) & 3));
    uint16_t value = BUS16(c, 0x004216);
    r->a = (uint16_t)((value & 0xFF) + RAM16(0x102F4));
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC710, SOM_RTS, "gen", select_vram_registration_slot, 0, L_A | L_B | L_X | L_Y | L_V, 6, 0, 0, 43, 26)
