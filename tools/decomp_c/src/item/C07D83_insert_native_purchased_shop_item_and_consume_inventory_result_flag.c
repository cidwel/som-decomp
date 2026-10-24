#include "som_c.h"

/* C07D83 insert_native_purchased_shop_item_and_consume_inventory_result_flag   [class B, 46 bytes, 20 instructions]
 * Source: src/rom/insert_native_purchased_shop_item_and_consume_inventory_result_flag.s
 * Documented in docs/event-menu-shop-inventory-insert.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void insert_native_purchased_shop_item_and_consume_inventory_result_flag(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint8_t a1;
    uint8_t a_hi1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if ((uint16_t)((a & 0xFF) - 0x7B) < 0x3F) {
        a1 = (uint8_t)((a & 0xFF) - 0x7B);
        a_hi1 = (uint16_t)((a & 0xFF) - 0x7B) >> 8;
        carry1 = (uint16_t)((a & 0xFF) - 0x7B) >= 0x3F;
        zero1 = (uint16_t)((a & 0xFF) - 0x7B) == 0x3F;
        negative1 = (uint16_t)((a & 0xFF) - 0xBA) & 0x8000;
        overflow1 = (((a & 0xFF) ^ 0x7B) & ((a & 0xFF) ^ (uint16_t)((a & 0xFF) - 0x7B)) & 0x8000) != 0;
    } else {
        a1 = (uint8_t)((uint16_t)((a & 0xFF) - 0xBA) + 0x40);
        a_hi1 = (uint16_t)((uint16_t)((a & 0xFF) - 0xBA) + 0x40) >> 8;
        carry1 = (uint16_t)((a & 0xFF) - 0xBA) + 0x40 > 0xFFFF;
        zero1 = (uint16_t)((uint16_t)((a & 0xFF) - 0xBA) + 0x40) == 0;
        negative1 = (uint16_t)((uint16_t)((a & 0xFF) - 0xBA) + 0x40) & 0x8000;
        overflow1 = (((uint16_t)((a & 0xFF) - 0xBA) ^ (uint16_t)((uint16_t)((a & 0xFF) - 0xBA) + 0x40)) & ((uint16_t)((uint16_t)((a & 0xFF) - 0xBA) + 0x40) ^ 0x40) & 0x8000) != 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    JSL(c, 0x7D9C, 0xC00051); /* jump_public_event_inventory_command */
    uint16_t a_all = r->a;
    uint8_t value = RAM8(0xCF0F);
    RAM8(0xCF0F) = 0;
    r->a = ((a_all >> 8 << 8) | value) & 0xFF;
    r->z = (((a_all >> 8 << 8) | value) & 0xFF) == 0;
    r->n = ((a_all >> 8 << 8) | value) & 0xFF & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07D83, SOM_RTS, "gen", insert_native_purchased_shop_item_and_consume_inventory_result_flag, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 46, 20)
