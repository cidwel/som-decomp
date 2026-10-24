#include "som_c.h"

/* C18775 execute_ordinary_actor_cast_presentation   [class B, 77 bytes, 30 instructions]
 * Source: src/rom/execute_ordinary_actor_cast_presentation.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void execute_ordinary_actor_cast_presentation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    BUS16_SET(c, (uint16_t)(dp + 0x14), x);
    RAM8(0xE012 + x) = 0;
    RAM8(0xE084 + x) = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8781, 0xC18B82); GUARD_JSR(c, sp_call, 0x8781); } /* prepare_actor_cast_three_target_presentation */
    uint8_t db_ret = r->db;
    uint16_t x_ret2 = r->x;
    bool carry_ret = r->c;
    if (carry_ret) {
        uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0xE111 + x_ret2);
        uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0xE170 + x_ret2);
        r->a = (value << 8) | value2;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8792, 0xC18654); GUARD_JSR(c, sp_call, 0x8792); } /* load_actor_cast_graphics_by_spell_and_level */
        uint8_t db_ret2 = r->db;
        uint16_t x_ret3 = r->x;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8795, 0xC186D1); GUARD_JSR(c, sp_call, 0x8795); } /* select_actor_cast_presentation_record */
        uint16_t a_all3 = r->a;
        uint8_t value3 = BUS8(c, 0xD02AA0 + a_all3);
        BUS8_SET(c, (db_ret2 << 0x10) + 0xE04F + x_ret3, value3);
        BUS8_SET(c, (db_ret2 << 0x10) + 0xE060 + x_ret3, 0xE0);
        uint16_t value4 = BUS16(c, 0xD02AA2 + a_all3);
        BUS16_SET(c, (db_ret2 << 0x10) + 0xE06A + x_ret3, value4);
        uint16_t value5 = BUS16(c, 0xD02AA4 + a_all3);
        BUS16_SET(c, (db_ret2 << 0x10) + 0xE0FC + x_ret3, value5);
        BUS16_SET(c, (db_ret2 << 0x10) + 0xE0FE + x_ret3, value5);
        uint8_t value6 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xE04F + x_ret3);
        r->a = (value5 >> 8 << 8) | value6;
        r->y = x_ret3;
        r->z = x_ret3 == 0;
        r->n = x_ret3 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        TAIL_CALL(c, 0xC1859B, SOM_RTS); /* copy_object_weapon_palette */
    }
    TAIL_CALL(c, 0xC18C96, SOM_RTS); /* cancel_cast_and_deliver_pending_target_hits */
}
SOM_REGISTER(0xC18775, SOM_RTS, "gen", execute_ordinary_actor_cast_presentation, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 77, 30)
