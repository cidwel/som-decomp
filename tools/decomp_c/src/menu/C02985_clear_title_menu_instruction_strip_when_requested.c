#include "som_c.h"

/* C02985 clear_title_menu_instruction_strip_when_requested   [class A, 32 bytes, 14 instructions]
 * Source: src/rom/clear_title_menu_instruction_strip_when_requested.s
 * Documented in docs/event-menu-controller.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void clear_title_menu_instruction_strip_when_requested(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA202);
    uint8_t a2;
    uint16_t x3;
    uint16_t y3;
    bool zero3;
    if (value != 9) {
        a2 = value;
        x3 = x;
        y3 = y;
        zero3 = value == 9;
    } else {
        uint8_t value2 = RAM8(0x19FE);
        uint8_t a1;
        uint16_t x2;
        uint16_t y2;
        bool zero2;
        if (value2 != 0) {
            a1 = value2;
            x2 = x;
            y2 = y;
            zero2 = value2 == 0;
        } else {
            uint16_t x1 = 0x68;
            uint16_t y1 = 0x14;
            bool zero1 = 0;
            for (;;) {
                RAM8(0x9000 + x1) = 0x14;
                RAM8(0x9040 + x1) = 0x14;
                uint16_t x1_next = (uint16_t)(x1 + 1);
                uint16_t y1_next = (uint16_t)(y1 - 1);
                bool zero1_next = (uint16_t)(y1 - 1) == 0;
                x1 = x1_next;
                y1 = y1_next;
                zero1 = zero1_next;
                if (!(y1 != 0)) break;
            }
            a1 = 0x14;
            x2 = x1;
            y2 = y1;
            zero2 = zero1;
        }
        a2 = a1;
        x3 = x2;
        y3 = y2;
        zero3 = zero2;
    }
    r->a = (a_hi << 8) | a2;
    r->x = x3;
    r->y = y3;
    r->c = value >= 9;
    r->z = zero3;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02985, SOM_RTS, "gen", clear_title_menu_instruction_strip_when_requested, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 32, 14)
