#include "som_c.h"

/* C2A765 set_map_layer_nibble_parameters   [class B, 72 bytes, 36 instructions]
 * Source: src/rom/set_map_layer_nibble_parameters.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void set_map_layer_nibble_parameters(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t y = r->y;
    if ((a & 0x0F) == 0) {
        SET_A8(r, a & 0x0F);
        RETURN_RTS(c);
    }
    if ((a & 0x0F) == 8) {
        RAM8(0x0A82 + y) = 1;
        uint16_t value = RAM16(0x00F4);
        RAM16_SET(0x00F4, (uint16_t)(RAM16(0x00F4) + 1));
        r->a = value & 0x13FF;
        r->c = (a & 0x0F) >= 8;
        r->mf = 0;
        TAIL_CALL(c, 0xC2A7D5, SOM_RTS); /* set_map_layer_packed_parameters */
    }
    if ((a & 0x0F) >= 8) {
        RAM8(0x0A85 + y) = 0x80;
    }
    RAM8(0x0A82 + y) = 2;
    if ((uint8_t)((a & 7) - 1) != 0) {
        uint8_t a1;
        if ((uint8_t)((a & 7) - 2) != 0) {
            a1 = (uint8_t)((a & 7) - 2);
        } else {
            RAM8(0x0A86 + y) = 0x80;
            a1 = 0x80;
        }
        uint8_t a2;
        if (a1 != 5) {
            a2 = a1;
        } else {
            a2 = 8;
        }
        RAM8(0x0A87 + y) = a2;
        SET_A8(r, a2);
        r->c = a1 >= 5;
        RETURN_RTS(c);
    }
    RAM8(0x0A86 + y) = 0x55;
    SET_A8(r, 0x55);
    r->c = (a & 0x0F) >= 8;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2A765, SOM_RTS, "gen", set_map_layer_nibble_parameters, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 72, 36)
