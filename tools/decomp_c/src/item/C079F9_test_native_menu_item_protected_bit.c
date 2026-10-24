#include "som_c.h"

/* C079F9 test_native_menu_item_protected_bit   [class A, 9 bytes, 4 instructions]
 * Source: src/rom/test_native_menu_item_protected_bit.s
 * Documented in docs/event-menu-equipment-fields.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZV.
 */
static void test_native_menu_item_protected_bit(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    r->y = (uint8_t)y;
    r->mf = 1;
    r->xf = 1;
    JSL(c, 0x79FE, 0xC07A02); /* read_native_item_usability_and_category_bits */
    uint16_t a_all = r->a;
    r->z = ((uint8_t)a_all & 0x80) == 0;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC079F9, SOM_RTS, "gen", test_native_menu_item_protected_bit, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 0, 0, 9, 4)
