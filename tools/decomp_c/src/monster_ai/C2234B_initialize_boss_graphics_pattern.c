#include "som_c.h"

/* C2234B initialize_boss_graphics_pattern   [class D, 62 bytes, 23 instructions]
 * Source: src/rom/initialize_boss_graphics_pattern.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void initialize_boss_graphics_pattern(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    BUS16_SET(c, 0x002181, 0xBC00);
    BUS8_SET(c, 0x002183, 1);
    uint8_t a_hi1 = 0xBC;
    uint16_t x1 = 0;
    for (;;) {
        BUS8_SET(c, 0x002180, 0);
        BUS8_SET(c, 0x002180, 3);
        x1 = (uint16_t)(x1 + 1);
        if (!(x1 != 0x0200)) break;
    }
    BUS16_SET(c, 0x002116, 0x3800);
    uint16_t x2 = 0;
    bool carry1 = 0;
    bool zero1 = 0;
    bool negative1 = 0;
    for (;;) {
        BUS16_SET(c, 0x002118, 0x0300);
        uint16_t x2_next = (uint16_t)(x2 + 1);
        bool carry1_next = (uint16_t)(x2 + 1) >= 0x0800;
        bool zero1_next = (uint16_t)(x2 + 1) == 0x0800;
        bool negative1_next = (uint16_t)((uint16_t)(x2 + 1) - 0x0800) & 0x8000;
        x2 = x2_next;
        carry1 = carry1_next;
        zero1 = zero1_next;
        negative1 = negative1_next;
        if (!(x2 != 0x0800)) break;
    }
    r->a = 0x0300;
    r->x = x2;
    r->y = y;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2234B, SOM_RTS, "gen", initialize_boss_graphics_pattern, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 62, 23)
