#include "som_c.h"

/* D0CCD6 rotate_one_native_enabled_equipment_row_palette   [class C, 66 bytes, 29 instructions]
 * Source: src/rom/rotate_one_native_enabled_equipment_row_palette.s
 * Documented in docs/event-menu-ring-palette.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXV.
 */
static void rotate_one_native_enabled_equipment_row_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    uint16_t value = BUS16(c, 0x18A1 + a);
    uint8_t a_hi1;
    if ((value & 0x80) != 0) {
        a_hi1 = 0;
    } else {
        uint16_t value2 = RAM16(0x0000 + x);
        RAM16_SET(0x0000 + x, RAM16(0x0002 + x));
        RAM16_SET(0x0002 + x, RAM16(0x0004 + x));
        RAM16_SET(0x0004 + x, RAM16(0x0006 + x));
        RAM16_SET(0x0006 + x, RAM16(0x0008 + x));
        RAM16_SET(0x0008 + x, value2);
        a_hi1 = value2 >> 8;
    }
    r->a = (uint16_t)(a + 2);
    r->x = (uint16_t)(x + 0x0A);
    r->v = ((x ^ (uint16_t)(x + 0x0A)) & ((uint16_t)(x + 0x0A) ^ 0x0A) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0CCD6, SOM_RTS, "hand", rotate_one_native_enabled_equipment_row_palette, 0, L_A | L_B | L_X | L_V, 6, 0, 0, 66, 29)
