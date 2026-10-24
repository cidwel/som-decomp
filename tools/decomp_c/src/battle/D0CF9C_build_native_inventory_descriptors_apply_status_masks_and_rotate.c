#include "som_c.h"

/* D0CF9C build_native_inventory_descriptors_apply_status_masks_and_rotate   [class A, 37 bytes, 14 instructions]
 * Source: src/rom/build_native_inventory_descriptors_apply_status_masks_and_rotate.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCZV.
 */
static void build_native_inventory_descriptors_apply_status_masks_and_rotate(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t ring_category = RAM8(RING_CATEGORY);
    uint16_t value = BUS16(c, 0xD8FD60 + (uint8_t)((a_hi << 8) | (uint8_t)(ring_category << 1)));
    RAM16_SET(0x1828, value);
    r->a = value;
    r->x = (uint8_t)((a_hi << 8) | (uint8_t)(ring_category << 1));
    r->y = 0x1880;
    r->c = ring_category & 0x80;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCFB1, 0xD0CFC1); GUARD_JSR(c, sp_call, 0xCFB1); } /* dispatch_native_inventory_category_or_packed_equipment_rows */
    uint8_t db_ret = r->db;
    uint16_t y_ret = r->y;
    BUS16_SET(c, (db_ret << 0x10) + y_ret, 0xFFFF);
    r->a = 0xFFFF;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xCFBD, 0xD9FCBD); GUARD_JSL(c, sp_call, 0xCFBD); } /* apply_native_inventory_status_masks_public_wrapper */
    TAIL_CALL(c, 0xD0D319, SOM_RTS); /* rotate_native_menu_descriptor_rows_and_append_category_tail */
}
SOM_REGISTER(0xD0CF9C, SOM_RTS, "gen", build_native_inventory_descriptors_apply_status_masks_and_rotate, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 37, 14)
