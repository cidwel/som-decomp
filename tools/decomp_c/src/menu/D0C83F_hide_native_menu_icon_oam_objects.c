#include "som_c.h"

/* D0C83F hide_native_menu_icon_oam_objects   [class A, 23 bytes, 13 instructions]
 * Source: src/rom/hide_native_menu_icon_oam_objects.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCZV.
 */
static void hide_native_menu_icon_oam_objects(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t x1 = 0x082D;
    bool carry1 = carry;
    bool zero1 = 0;
    for (;;) {
        BUS8_SET(c, x1, 0xE8);
        uint16_t x1_next = (uint16_t)(x1 + 4);
        bool carry1_next = (uint16_t)(x1 + 4) >= 0x0878;
        bool zero1_next = (uint16_t)(x1 + 4) == 0x0878;
        x1 = x1_next;
        carry1 = carry1_next;
        zero1 = zero1_next;
        if (!(x1 < 0x0878)) break;
    }
    r->a = (a >> 8 << 8) | 0xE8;
    r->x = x1;
    r->y = y;
    r->c = carry1;
    r->z = zero1;
    r->v = overflow;
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0C83F, SOM_RTL, "gen", hide_native_menu_icon_oam_objects, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 0, 0, 23, 13)
