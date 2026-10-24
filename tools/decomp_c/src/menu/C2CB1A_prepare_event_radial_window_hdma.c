#include "som_c.h"

/* C2CB1A prepare_event_radial_window_hdma   [class D, 85 bytes, 31 instructions]
 * Source: src/rom/prepare_event_radial_window_hdma.s
 * Documented in docs/event-menu-effect-preparation.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void prepare_event_radial_window_hdma(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS16_SET(c, 0x004320, 0x2641);
    BUS16_SET(c, 0x004322, 0xF018);
    BUS16_SET(c, 0x004324, 0x7E);
    BUS16_SET(c, 0x004326, 0x7E00);
    RAM16_SET(0xF019, 0xF020);
    RAM16_SET(0xF01C, 0xF11E);
    RAM16_SET(0xF01E, 0);
    RAM16_SET(0x001E, RAM16(0xE020));
    uint16_t value2 = RAM16(0xE074);
    uint16_t value3 = RAM16(0xE045);
    uint16_t value4 = RAM16(0xE022);
    RAM8(0x001F) = (uint8_t)(((uint16_t)((value2 & 0x7F) + value3) ^ 0xFFFF) + value4 + 1);
    RAM8(0xF018) = 0xFF;
    RAM8(0xF01B) = 0xE0;
    r->a = ((uint16_t)(((uint16_t)((value2 & 0x7F) + value3) ^ 0xFFFF) + value4 + 1) >> 8 << 8) | 0xE0;
    r->c = ((uint16_t)((value2 & 0x7F) + value3) ^ 0xFFFF) + value4 + 1 > 0xFFFF;
    r->z = 0;
    r->n = 1;
    r->v = (((uint16_t)((value2 & 0x7F) + value3) ^ 0xFFFF ^ (uint16_t)(((uint16_t)((value2 & 0x7F) + value3) ^ 0xFFFF) + value4 + 1)) & (value4 ^ (uint16_t)(((uint16_t)((value2 & 0x7F) + value3) ^ 0xFFFF) + value4 + 1)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2CB1A, SOM_RTS, "gen", prepare_event_radial_window_hdma, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 85, 31)
