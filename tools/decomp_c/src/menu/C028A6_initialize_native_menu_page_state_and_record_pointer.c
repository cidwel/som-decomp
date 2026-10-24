#include "som_c.h"

/* C028A6 initialize_native_menu_page_state_and_record_pointer   [class D, 51 bytes, 21 instructions]
 * Source: src/rom/initialize_native_menu_page_state_and_record_pointer.s
 * Documented in docs/event-menu-controller.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYV.
 */
static void initialize_native_menu_page_state_and_record_pointer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS8_SET(c, 0x004200, 1);
    BUS8_SET(c, 0x002100, 0x80);
    RAM8(0xA200) = 0;
    RAM8(0xA210) = 0xFF;
    RAM8(0xA20A) = 0x80;
    uint16_t value = RAM16(0xA202);
    RAM16_SET(0xA173, (value & 0xFF) << 1);
    uint16_t value2 = RAM16(0xA173);
    RAM16_SET(0xA20D, (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + 0x780A + (((value & 0xFF) << 1 << 1) + value2 > 0xFFFF)));
    r->a = (r->a & 0x00FF) | (((uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + 0x780A + (((value & 0xFF) << 1 << 1) + value2 > 0xFFFF)) >> 8) << 8);
    r->v = (((uint16_t)(((value & 0xFF) << 1 << 1) + value2) ^ (uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + 0x780A + (((value & 0xFF) << 1 << 1) + value2 > 0xFFFF))) & ((uint16_t)((uint16_t)(((value & 0xFF) << 1 << 1) + value2) + 0x780A + (((value & 0xFF) << 1 << 1) + value2 > 0xFFFF)) ^ 0x780A) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC028A6, SOM_RTS, "gen", initialize_native_menu_page_state_and_record_pointer, 0, L_B | L_Y | L_V, 1, 1, 0, 51, 21)
