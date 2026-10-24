#include "som_c.h"

/* C0A638 install_temporary_world_map_picker_nmi_vector   [class A, 14 bytes, 7 instructions]
 * Source: src/rom/install_temporary_world_map_picker_nmi_vector.s
 * Documented in docs/ui-native-world-map-picker-scene.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: XYCV.
 */
static void install_temporary_world_map_picker_nmi_vector(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a >> 8;
    uint8_t x1 = 3;
    for (;;) {
        uint8_t value = BUS8(c, 0x00A646 + x1);
        RAM8(0x0100 + x1) = value;
        x1 = (uint8_t)(x1 - 1);
        if (!(!(x1 & 0x80))) break;
    }
    r->x = x1;
    r->y = y;
    r->c = carry;
    r->v = overflow;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0A638, SOM_RTS, "gen", install_temporary_world_map_picker_nmi_vector, 0, L_X | L_Y | L_C | L_V, 1, 0, 1, 14, 7)
