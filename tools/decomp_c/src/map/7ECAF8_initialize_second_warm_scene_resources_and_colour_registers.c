#include "som_c.h"

/* 7ECAF8 initialize_second_warm_scene_resources_and_colour_registers   [class B, 51 bytes, 23 instructions]
 * Source: src/boot/initialize_second_warm_scene_resources_and_colour_registers.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BYCZNV.
 */
static void initialize_second_warm_scene_resources_and_colour_registers(SomCtx *c)
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
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCB00, 0x7ECA65); GUARD_JSR(c, sp_call, 0xCB00); } /* construct_second_warm_scene_background_resources */
    r->sp += 3;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    r->a = (a_all >> 8 << 8) | 0x30;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCB05, 0x7EC030); GUARD_JSR(c, sp_call, 0xCB05); } /* allocate_ppu_register_entry */
    r->sp += 3;
    uint8_t db_ret2 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint16_t x_ret4 = r->x;
    BUS8_SET(c, (db_ret2 << 0x10) + 2 + x_ret4, 0);
    r->a = (a_all2 >> 8 << 8) | 0;
    r->z = 1;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCB0D, 0x7EC097); GUARD_JSR(c, sp_call, 0xCB0D); } /* append_oneshot_ppu_entry */
    r->sp += 3;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all3 = r->a;
    r->a = (a_all3 >> 8 << 8) | 0x31;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCB12, 0x7EC030); GUARD_JSR(c, sp_call, 0xCB12); } /* allocate_ppu_register_entry */
    r->sp += 3;
    uint8_t db_ret4 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all4 = r->a;
    uint16_t x_ret7 = r->x;
    BUS8_SET(c, (db_ret4 << 0x10) + 2 + x_ret7, 0x81);
    r->a = (a_all4 >> 8 << 8) | 0x81;
    r->z = 0;
    r->n = 1;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCB1A, 0x7EC097); GUARD_JSR(c, sp_call, 0xCB1A); } /* append_oneshot_ppu_entry */
    r->sp += 3;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all5 = r->a;
    r->a = (a_all5 >> 8 << 8) | 0x32;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCB1F, 0x7EC030); GUARD_JSR(c, sp_call, 0xCB1F); } /* allocate_ppu_register_entry */
    r->sp += 3;
    uint8_t db_ret6 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all6 = r->a;
    uint16_t x_ret10 = r->x;
    BUS8_SET(c, (db_ret6 << 0x10) + 2 + x_ret10, 0xFF);
    r->a = (a_all6 >> 8 << 8) | 0xFF;
    r->z = 0;
    r->n = 1;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCB27, 0x7EC097); GUARD_JSR(c, sp_call, 0xCB27); } /* append_oneshot_ppu_entry */
    r->sp += 3;
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
SOM_REGISTER(0x7ECAF8, SOM_RTS, "gen", initialize_second_warm_scene_resources_and_colour_registers, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 51, 23)
