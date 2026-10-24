#include "som_c.h"

/* C00D8B select_dialogue_window_geometry_from_state   [class B, 113 bytes, 50 instructions]
 * Source: src/rom/select_dialogue_window_geometry_from_state.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYV.
 */
static void select_dialogue_window_geometry_from_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0xC7;
    uint8_t value = RAM8(0xA162);
    uint8_t value2 = BUS8(c, 0xC77147 + (uint8_t)(value << 1));
    uint8_t value3 = BUS8(c, 0xC77148 + (uint8_t)(value << 1));
    uint8_t value4 = BUS8(c, 0xC77153 + (uint8_t)(value << 1));
    RAM8(0x1D1A) = value4;
    uint8_t value5 = BUS8(c, 0xC77154 + (uint8_t)(value << 1));
    RAM8(0x1D1B) = value5;
    uint8_t a_hi1;
    if (value != 2) {
        a_hi1 = value2;
    } else {
        RAM16_SET(0x1D1A, 0x0500);
        a_hi1 = 5;
    }
    uint8_t value6 = RAM8(0xA170);
    uint8_t a1;
    uint8_t a_hi2;
    if (value6 == 0x51) {
        uint8_t value7 = BUS8(c, 0xC7713B + (uint8_t)(value << 1));
        uint8_t value8 = BUS8(c, 0xC7713C + (uint8_t)(value << 1));
        a1 = value8;
        a_hi2 = value7;
    } else {
        uint16_t value9 = BUS16(c, 0xC7714D + (uint8_t)(value << 1));
        RAM16_SET(0xA169, value9);
        uint16_t value10 = BUS16(c, 0xC77141 + (uint8_t)(value << 1));
        RAM16_SET(0xA196, value10);
        uint8_t value11 = BUS8(c, 0xC77135 + (uint8_t)(value << 1));
        uint8_t value12 = BUS8(c, 0xC77136 + (uint8_t)(value << 1));
        a1 = value12;
        a_hi2 = value11;
    }
    RAM16_SET(0xA163, ((uint8_t)((value2 << 8) | value3) << 8) | value2);
    RAM16_SET(0xA16B, ((uint8_t)((value2 << 8) | value3) << 8) | value2);
    r->a = (a_hi2 << 8) | a1;
    r->x = (uint8_t)(value << 1);
    r->y = (value2 << 8) | value3;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00D8B, SOM_RTS, "gen", select_dialogue_window_geometry_from_state, 0, L_A | L_B | L_X | L_Y | L_V, 2, 1, 0, 113, 50)
