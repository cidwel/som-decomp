#include "som_c.h"

/* 7EA88F enter_native_scheduler_and_launch_default_idle_task   [class C, 47 bytes, 22 instructions]
 * Source: src/boot/enter_native_scheduler_and_launch_default_idle_task.s
 * Documented in docs/boot-native-scheduler-entry.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void enter_native_scheduler_and_launch_default_idle_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    r->a = (a_hi << 8) | 0x7F;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->db = 0x7F;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA89E, 0x7EA1E2); GUARD_JSR(c, sp_call, 0xA89E); } /* publish_native_scheduler_irq_vector_and_enable_vertical_irq_after_vblank */
    r->sp += 4;
    RAM16_SET(0x10098, (uint16_t)(sp0 - 4));
    r->a = ((uint16_t)(sp0 - 4) >> 8 << 8) | 0x7E;
    r->x = 0x600A;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA8AC, 0x7EAAFF); GUARD_JSR(c, sp_call, 0xA8AC); } /* create_task_resources */
    r->sp += 4;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    uint16_t x_ret2 = r->x;
    if (m_ret) {
        uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 4 + x_ret2);
        BUS8_SET(c, (db_ret << 0x10) + 0xBE, value);
        uint16_t value2 = BUS16_RDP(c, (db_ret << 0x10) + 0xA0);
        BUS16_SET(c, (db_ret << 0x10) + x_ret2, value2);
        r->a = value2;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->mf = 0;
        TAIL_CALL_FRAME(c, 0x7EA961, SOM_RTS, 4); /* dispatch_task */
    } else {
        uint16_t value3 = BUS16_RDP(c, (db_ret << 0x10) + 4 + x_ret2);
        BUS16_SET(c, (db_ret << 0x10) + 0xBE, value3);
        uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0xA0);
        BUS16_SET(c, (db_ret << 0x10) + x_ret2, value4);
        r->a = value4;
        r->z = value4 == 0;
        r->n = value4 & 0x8000;
        r->mf = 0;
        TAIL_CALL_FRAME(c, 0x7EA961, SOM_RTS, 4); /* dispatch_task */
    }
}
SOM_REGISTER(0x7EA88F, SOM_RTS, "gen", enter_native_scheduler_and_launch_default_idle_task, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 47, 22)
