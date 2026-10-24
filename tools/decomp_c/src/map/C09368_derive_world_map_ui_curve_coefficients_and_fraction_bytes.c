#include "som_c.h"

/* C09368 derive_world_map_ui_curve_coefficients_and_fraction_bytes   [class B, 55 bytes, 34 instructions]
 * Source: src/rom/derive_world_map_ui_curve_coefficients_and_fraction_bytes.s
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYC.
 */
static void derive_world_map_ui_curve_coefficients_and_fraction_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    RAM16_SET(0x0000, a);
    uint16_t value = RAM16(0x0000);
    uint16_t x1;
    uint16_t y1;
    if ((value & 0x0100) == 0) {
        x1 = (((a & 0xFF) << 1) ^ 0x01FE) + 2;
        y1 = (a & 0xFF) << 1;
    } else {
        RAM8(0x0000 + sp0) = (a & 0xFF) << 1 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((a & 0xFF) << 1);
        RAM8(0x0000 + sp0 - 2) = (((a & 0xFF) << 1) ^ 0x01FE) + 2 >> 8;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)((((a & 0xFF) << 1) ^ 0x01FE) + 2);
        x1 = (a & 0xFF) << 1;
        y1 = (((a & 0xFF) << 1) ^ 0x01FE) + 2;
    }
    uint16_t value2 = BUS16(c, 0x00FD22 + y1);
    RAM16_SET(0x0030, value2);
    uint16_t value3 = RAM16(0x0030);
    uint16_t value4 = BUS16(c, 0x00FD22 + x1);
    RAM16_SET(0x0032, value4);
    uint16_t value5 = RAM16(0x0032);
    RAM8(0x0034) = (uint8_t)((uint16_t)((value2 >> 2) + value3 + ((value2 >> 1) & 1)) >> 1);
    RAM8(0x0035) = (uint8_t)((uint16_t)((value4 >> 2) + value5 + ((value4 >> 1) & 1)) >> 1);
    r->a = (uint16_t)((value4 >> 2) + value5 + ((value4 >> 1) & 1)) >> 1;
    r->x = (uint8_t)((uint16_t)((value4 >> 2) + value5 + ((value4 >> 1) & 1)) >> 1);
    r->y = (uint8_t)((uint16_t)((value2 >> 2) + value3 + ((value2 >> 1) & 1)) >> 1);
    r->c = (uint16_t)((value4 >> 2) + value5 + ((value4 >> 1) & 1)) & 0x01;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09368, SOM_RTS, "gen", derive_world_map_ui_curve_coefficients_and_fraction_bytes, 0, L_A | L_B | L_X | L_Y | L_C, 4, 0, 1, 55, 34)
