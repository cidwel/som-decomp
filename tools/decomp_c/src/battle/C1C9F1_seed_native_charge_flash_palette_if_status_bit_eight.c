#include "som_c.h"

/* C1C9F1 seed_native_charge_flash_palette_if_status_bit_eight   [class B, 94 bytes, 46 instructions]
 * Source: src/rom/seed_native_charge_flash_palette_if_status_bit_eight.s
 * Documented in docs/actor-charge-gauge-presentation.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void seed_native_charge_flash_palette_if_status_bit_eight(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint8_t value = RAM8(0xE100 + x);
    if ((value & 8) != 0) {
        RAM8(0x000C) = 0x8D;
        RAM8(0xE100 + x) = 8;
        JSR(c, 0xCA4B, 0xC1D90D); /* load_actor_fifteen_palette_colors_from_rom */
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    SET_A8(r, value);
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1C9F1, SOM_RTL, "gen", seed_native_charge_flash_palette_if_status_bit_eight, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 94, 46)
