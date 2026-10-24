#include "som_c.h"

/* C01A52 initialize_numeric_choice_controller_and_highlight   [class B, 36 bytes, 19 instructions]
 * Source: src/rom/initialize_numeric_choice_controller_and_highlight.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void initialize_numeric_choice_controller_and_highlight(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 3;
    for (;;) {
        uint8_t value = BUS8_RDP(c, (uint16_t)(x1 + 0xD8));
        uint16_t x2;
        if ((value & 0x80) != 0) {
            x2 = x1;
        } else {
            if ((uint16_t)(x1 - 1) != 0) {
                x1 = (uint16_t)(x1 - 1);
                continue;
            }
            x2 = (uint16_t)((uint16_t)(x1 - 1) + 1);
        }
        x1 = x2;
        break;
    }
    RAM16_SET(0xA182, (uint8_t)((uint8_t)(x1 - 1) << 1));
    RAM8(0xA200) = 0;
    r->a = (uint8_t)((uint8_t)(x1 - 1) << 1);
    r->x = (uint8_t)((uint8_t)(x1 - 1) << 1);
    r->y = y;
    r->c = (uint8_t)(x1 - 1) & 0x80;
    r->z = (uint8_t)((uint8_t)(x1 - 1) << 1) == 0;
    r->n = (uint8_t)((uint8_t)(x1 - 1) << 1) & 0x8000;
    r->v = overflow;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1A6E, 0xC01B55); GUARD_JSR(c, sp_call, 0x1A6E); } /* toggle_numeric_choice_tile_attributes_and_request_publication */
    RAM8(0xA201) = 0;
    RAM8(0xA160)++;
    r->z = RAM8(0xA160) == 0;
    r->n = RAM8(0xA160) & 0x80;
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01A52, SOM_RTS, "gen", initialize_numeric_choice_controller_and_highlight, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 36, 19)
