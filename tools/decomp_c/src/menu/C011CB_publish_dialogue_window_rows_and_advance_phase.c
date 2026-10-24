#include "som_c.h"

/* C011CB publish_dialogue_window_rows_and_advance_phase   [class B, 106 bytes, 44 instructions]
 * Source: src/rom/publish_dialogue_window_rows_and_advance_phase.s
 * Documented in docs/event-dialogue-render-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void publish_dialogue_window_rows_and_advance_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0xA181);
    uint8_t a2;
    uint8_t a_hi2;
    if (value == 0) {
        a2 = value;
        a_hi2 = 6;
    } else {
        uint8_t a1;
        uint8_t a_hi1;
        if (value == 3) {
            a1 = value;
            a_hi1 = 6;
        } else {
            a1 = 6;
            a_hi1 = 8;
        }
        a2 = a1;
        a_hi2 = a_hi1;
    }
    RAM8(0xA175) = a_hi2;
    uint16_t value2 = RAM16(0xA189);
    r->a = (a2 << 8) | a_hi2;
    r->x = 0x9400;
    r->y = value2;
    r->sp -= 1;
    JSR(c, 0x11E7, 0xC01235); /* copy_dialogue_window_rows_with_upload_padding */
    r->sp += 1;
    uint16_t value3 = RAM16(0xA189);
    RAM8(0xA175) = a_hi2;
    r->a = ((uint16_t)(value3 + 0x10) >> 8 << 8) | a_hi2;
    r->y = (uint16_t)(value3 + 0x10);
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x11FA, 0xC01235); /* copy_dialogue_window_rows_with_upload_padding */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x11FD, 0xC01257); /* advance_dialogue_window_graphics_pointer */
    uint16_t value4 = RAM16(0xA181);
    uint16_t value5 = BUS16(c, 0xC01A36 + ((value4 & 0xFF) << 1));
    RAM16_SET(0x1D06, value5);
    uint16_t value6 = BUS16(c, 0xC01A3E + ((value4 & 0xFF) << 1));
    RAM16_SET(0x1D08, value6);
    RAM16_SET(0x1D18, 0x0100);
    RAM8(0xA181)++;
    if (RAM8(0xA181) == 4) {
        RAM8(0xA181) = 0;
        RAM8(0xA15D)++;
        RAM8(0xA15D)++;
    }
    r->a = (r->a & 0x00FF) | (1 << 8);
    r->x = (value4 & 0xFF) << 1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC011CB, SOM_RTS, "gen", publish_dialogue_window_rows_and_advance_phase, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 106, 44)
