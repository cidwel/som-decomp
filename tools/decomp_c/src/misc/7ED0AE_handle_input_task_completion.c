#include "som_c.h"

/* 7ED0AE handle_input_task_completion   [class B, 30 bytes, 15 instructions]
 * Source: src/boot/handle_input_task_completion.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABYCV.
 */
static void handle_input_task_completion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD0B6, 0x7EB1DD); GUARD_JSR(c, sp_call, 0xD0B6); } /* release_eight_byte_record */
    r->sp += 3;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    r->a = (a_all >> 8 << 8) | 5;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD0BB, 0x7EA351); GUARD_JSR(c, sp_call, 0xD0BB); } /* claim_controller_routes */
    r->sp += 3;
    uint8_t db_ret2 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    r->a = (a_all2 >> 8 << 8) | 5;
    r->x = 0xF0F0;
    r->z = 0;
    r->n = 1;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD0C3, 0x7EA3FC); GUARD_JSR(c, sp_call, 0xD0C3); } /* set_controller_pressed_masks */
    r->sp += 3;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all3 = r->a;
    BUS8_SET(c, (db_ret2 << 0x10) + 0x0316, 1);
    uint8_t value = RAM8(0x0000 + sp0 - 2);
    uint8_t value2 = RAM8(0x0000 + sp0 - 1);
    uint8_t value3 = RAM8(0x0000 + sp0);
    r->a = (a_all3 >> 8 << 8) | 1;
    r->c = value & 0x01;
    r->v = value & 0x40;
    r->mf = value & 0x20;
    r->xf = value & 0x10;
    r->dp = (value3 << 8) | value2;
    r->i = value & 0x04;
    r->d = value & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ED0AE, SOM_RTS, "gen", handle_input_task_completion, 0, L_A | L_B | L_Y | L_C | L_V, 3, 1, 0, 30, 15)
