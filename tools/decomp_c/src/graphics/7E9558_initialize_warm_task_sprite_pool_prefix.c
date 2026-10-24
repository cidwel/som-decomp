#include "som_c.h"

/* 7E9558 initialize_warm_task_sprite_pool_prefix   [class C, 104 bytes, 43 instructions]
 * Source: src/boot/initialize_warm_task_sprite_pool_prefix.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XYCZNV.
 */
static void initialize_warm_task_sprite_pool_prefix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->a = 0x0B01;
    r->c = (uint16_t)(sp0 - 3) >= 0x0C;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 0x0C) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0F)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 0x0F);
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9568, 0x7EB42B); GUARD_JSR(c, sp_call, 0x9568); } /* initialize_native_one_hundred_twenty_eight_sprite_records_and_thirty_two_groups */
    r->sp += 15;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    r->a = 0;
    r->x = 0x0100;
    r->y = 0xE0;
    r->z = 0;
    r->n = 0;
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9574, 0x7E87DF); GUARD_JSR(c, sp_call, 0x9574); } /* initialize_colour_workspace */
    r->sp += 15;
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9577, 0x7E94BF); GUARD_JSR(c, sp_call, 0x9577); } /* construct_warm_scene_colour_hdma_records */
    r->sp += 15;
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0x957A, 0x7E93F4); GUARD_JSR(c, sp_call, 0x957A); } /* enter_warm_graphics_resource_constructor */
    r->sp += 15;
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0x957D, 0x7E945D); GUARD_JSR(c, sp_call, 0x957D); } /* construct_sixteen_warm_scene_sprites */
    r->sp += 15;
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9580, 0x7E9373); GUARD_JSR(c, sp_call, 0x9580); } /* construct_four_warm_scene_template_sprites */
    r->sp += 15;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    r->a = 0x7E;
    r->x = 0x601E;
    r->z = 0;
    r->n = 0;
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9589, 0x7EAB88); GUARD_JSR(c, sp_call, 0x9589); } /* create_and_enqueue_task */
    r->sp += 15;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 1;
    r->z = 0;
    r->n = 0;
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0x958F, 0x7EABE7); GUARD_JSR(c, sp_call, 0x958F); } /* receive_with_supplied_delay */
    r->sp += 15;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    r->a = 0x7E;
    r->x = 0x60BE;
    r->z = 0;
    r->n = 0;
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9598, 0x7EAB88); GUARD_JSR(c, sp_call, 0x9598); } /* create_and_enqueue_task */
    r->sp += 15;
    if (r->mf != 0) { c->fail = 3; return; }
    r->a = 5;
    r->z = 0;
    r->n = 0;
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0x959E, 0x7EC030); GUARD_JSR(c, sp_call, 0x959E); } /* allocate_ppu_register_entry */
    r->sp += 15;
    uint8_t db_ret9 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    uint16_t x_ret16 = r->x;
    BUS16_SET(c, (db_ret9 << 0x10) + 2 + x_ret16, 9);
    r->a = 9;
    r->z = 0;
    r->n = 0;
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0x95A7, 0x7EC097); GUARD_JSR(c, sp_call, 0x95A7); } /* append_oneshot_ppu_entry */
    r->sp += 15;
    if (r->mf != 0) { c->fail = 3; return; }
    r->a = 0x2C;
    r->z = 0;
    r->n = 0;
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0x95AD, 0x7EC030); GUARD_JSR(c, sp_call, 0x95AD); } /* allocate_ppu_register_entry */
    r->sp += 15;
    uint8_t db_ret11 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    uint16_t x_ret19 = r->x;
    BUS16_SET(c, (db_ret11 << 0x10) + 2 + x_ret19, 0x15);
    r->a = 0x15;
    r->z = 0;
    r->n = 0;
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSR(c, 0x95B6, 0x7EC097); GUARD_JSR(c, sp_call, 0x95B6); } /* append_oneshot_ppu_entry */
    r->sp += 15;
    if (r->mf != 0) { c->fail = 3; return; }
    uint8_t value = RAM8(0x0000 + sp0 - 2);
    uint8_t value2 = RAM8(0x0000 + sp0 - 1);
    uint8_t value3 = RAM8(0x0000 + sp0);
    r->c = value & 0x01;
    r->z = ((value3 << 8) | value2) == 0;
    r->n = ((value3 << 8) | value2) & 0x8000;
    r->v = value & 0x40;
    r->mf = value & 0x20;
    r->xf = value & 0x10;
    r->dp = (value3 << 8) | value2;
    r->i = value & 0x04;
    r->d = value & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9558, SOM_RTS, "gen", initialize_warm_task_sprite_pool_prefix, 0, L_X | L_Y | L_C | L_Z | L_N | L_V, 15, 1, 0, 104, 43)
