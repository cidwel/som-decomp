#include "som_c.h"

/* C23512 initialize_parent_callbacks_and_first_state   [class B, 63 bytes, 22 instructions]
 * Source: src/rom/initialize_parent_callbacks_and_first_state.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_parent_callbacks_and_first_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0287);
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3516, 0xC23372); GUARD_JSR(c, sp_call, 0x3516); } /* derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction */
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    RAM16_SET(0x00AD + value, 0);
    RAM16_SET(0x007A + value, 0xFF);
    uint16_t value2 = RAM16(0x00A7 + value);
    uint8_t a_hi1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    if (value2 == 0) {
        a_hi1 = value2 >> 8;
        y1 = y;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
    } else {
        r->a = value2;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3527, 0xC23385); GUARD_JSR(c, sp_call, 0x3527); } /* allocate_parent_linked_boss_effect_and_copy_coordinates */
        uint16_t a_all2 = r->a;
        uint16_t y_ret = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        a_hi1 = a_all2 >> 8;
        y1 = y_ret;
        carry1 = carry_ret2;
        overflow1 = overflow_ret2;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x352A, 0xC235BF); GUARD_JSR(c, sp_call, 0x352A); } /* invoke_descriptor_initialization_callback */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret2 = r->xf;
    uint16_t y_ret2 = r->y;
    if (x_ret2) {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0xBC + value3);
        BUS16_SET(c, (db_ret << 0x10) + 0xB0 + value3, value4);
        BUS16_SET(c, (db_ret << 0x10) + 0xB2 + value3, 0);
        BUS16_SET(c, (db_ret << 0x10) + 0x94 + value3, 2);
        BUS16_SET(c, (db_ret << 0x10) + 0x80 + value3, 0);
        BUS16_SET(c, (db_ret << 0x10) + 0x14 + value3, 0);
        BUS16_SET(c, (db_ret << 0x10) + 0x48 + value3, 0);
        BUS16_SET(c, (db_ret << 0x10) + 0x4A + value3, 0);
        BUS16_SET(c, (db_ret << 0x10) + 0x82 + value3, 1);
        r->a = 1;
        r->x = value3;
        r->y = (uint8_t)y_ret2;
        r->z = 0;
        r->n = 0;
        r->xf = 1;
        TAIL_CALL(c, 0xC23561, SOM_RTS); /* consume_boss_state_list_and_bootstrap_vm */
    } else {
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + 0xBC + value5);
        BUS16_SET(c, (db_ret << 0x10) + 0xB0 + value5, value6);
        BUS16_SET(c, (db_ret << 0x10) + 0xB2 + value5, 0);
        BUS16_SET(c, (db_ret << 0x10) + 0x94 + value5, 2);
        BUS16_SET(c, (db_ret << 0x10) + 0x80 + value5, 0);
        BUS16_SET(c, (db_ret << 0x10) + 0x14 + value5, 0);
        BUS16_SET(c, (db_ret << 0x10) + 0x48 + value5, 0);
        BUS16_SET(c, (db_ret << 0x10) + 0x4A + value5, 0);
        BUS16_SET(c, (db_ret << 0x10) + 0x82 + value5, 1);
        r->a = 1;
        r->x = value5;
        r->z = 0;
        r->n = 0;
        r->xf = 0;
        TAIL_CALL(c, 0xC23561, SOM_RTS); /* consume_boss_state_list_and_bootstrap_vm */
    }
}
SOM_REGISTER(0xC23512, SOM_RTS, "gen", initialize_parent_callbacks_and_first_state, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 63, 22)
