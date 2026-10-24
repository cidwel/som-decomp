#include "som_c.h"

/* D0CF61 build_shop_menu_descriptor_list_and_apply_native_row_order   [class B, 59 bytes, 27 instructions]
 * Source: src/rom/build_shop_menu_descriptor_list_and_apply_native_row_order.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCZV.
 */
static void build_shop_menu_descriptor_list_and_apply_native_row_order(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const bool overflow = r->v;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCF65, 0xD0D308); GUARD_JSR(c, sp_call, 0xCF65); } /* clear_native_menu_descriptor_row_attributes */
    uint16_t a_all = r->a;
    bool carry_ret = r->c;
    uint16_t value = RAM16(0x183C);
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = value;
    uint16_t y1 = 0x1880;
    bool carry1 = carry_ret;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value2 = RAM16(0x183C);
        uint8_t a_hi2;
        uint16_t x2;
        bool carry2;
        if ((uint16_t)(x1 - value2) == 0x0C) {
            a_hi2 = (uint16_t)(x1 - value2) >> 8;
            x2 = x1;
            carry2 = (uint16_t)(x1 - value2) >= 0x0C;
        } else {
            uint16_t value3 = BUS16(c, 0xD80000 + x1);
            if ((value3 & 0xFF) != 0xFF) {
                RAM8(0x0000 + sp0) = (uint16_t)(x1 + 1) >> 8;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)(x1 + 1);
                uint16_t value4 = BUS16(c, 0xD8FD7E + (uint16_t)((uint16_t)((value3 & 0xFF) - 1) << 1));
                BUS16_SET(c, 0x000000 + y1, value4);
                uint8_t value5 = RAM8(0x0000 + sp0 - 1);
                uint8_t value6 = RAM8(0x0000 + sp0);
                uint8_t a_hi1_next = value4 >> 8;
                uint16_t x1_next = (value6 << 8) | value5;
                uint16_t y1_next = (uint16_t)(y1 + 2);
                bool carry1_next = (uint16_t)((value3 & 0xFF) - 1) & 0x8000;
                bool overflow1_next = ((x1 ^ value2) & (x1 ^ (uint16_t)(x1 - value2)) & 0x8000) != 0;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                y1 = y1_next;
                carry1 = carry1_next;
                overflow1 = overflow1_next;
                continue;
            }
            a_hi2 = 0;
            x2 = (uint16_t)(x1 + 1);
            carry2 = (value3 & 0xFF) >= 0xFF;
        }
        uint8_t a_hi1_next2 = a_hi2;
        uint16_t x1_next2 = x2;
        bool carry1_next2 = carry2;
        bool overflow1_next2 = ((x1 ^ value2) & (x1 ^ (uint16_t)(x1 - value2)) & 0x8000) != 0;
        a_hi1 = a_hi1_next2;
        x1 = x1_next2;
        carry1 = carry1_next2;
        overflow1 = overflow1_next2;
        break;
    }
    BUS16_SET(c, 0x000000 + y1, 0xFFFF);
    r->a = 0xFFFF;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = 0;
    r->n = 1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    TAIL_CALL(c, 0xD0D319, SOM_RTS); /* rotate_native_menu_descriptor_rows_and_append_category_tail */
}
SOM_REGISTER(0xD0CF61, SOM_RTS, "gen", build_shop_menu_descriptor_list_and_apply_native_row_order, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 1, 0, 59, 27)
