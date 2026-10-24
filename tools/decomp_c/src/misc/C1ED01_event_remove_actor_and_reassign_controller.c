#include "som_c.h"

/* C1ED01 event_remove_actor_and_reassign_controller   [class B, 52 bytes, 24 instructions]
 * Source: src/rom/event_remove_actor_and_reassign_controller.s
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_remove_actor_and_reassign_controller(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0004);
    RAM16_SET(0xE000 + ((value & 0x0F00) << 1), 0x80);
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    uint8_t value2 = RAM8(0xE02C + ((value & 0x0F00) << 1));
    bool m_flag;
    bool x_flag;
    uint8_t a2;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    uint8_t data_bank;
    if (value2 == 0) {
        m_flag = 1;
        x_flag = 0;
        a2 = value2;
        a_hi1 = 0;
        x1 = (value & 0x0F00) << 1;
        y1 = y;
        carry1 = value & 0x0F00 & 0x8000;
        zero1 = value2 == 0;
        negative1 = value2 & 0x80;
        overflow1 = overflow;
        data_bank = 0x7E;
    } else {
        RAM8(0xE02C + ((value & 0x0F00) << 1)) = 0;
        uint8_t a1;
        if ((uint8_t)((value2 & 0x0F) - 1) != 3) {
            a1 = (uint8_t)((value2 & 0x0F) - 1);
        } else {
            a1 = 2;
        }
        RAM8(0x00D9 + a1) = 0;
        r->a = 0;
        r->x = a1;
        r->c = (uint8_t)((value2 & 0x0F) - 1) >= 3;
        r->z = 1;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xED31, 0x00BDBB); GUARD_JSL(c, sp_call, 0xED31); } /* reassign_controller_with_saved_bank */
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        x_flag = x_ret;
        a2 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        carry1 = carry_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
    }
    r->a = (a_hi1 << 8) | a2;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    TAIL_CALL(c, 0xC1E0DB, SOM_RTS); /* restore_party_hud_across_two_native_frames */
}
SOM_REGISTER(0xC1ED01, SOM_RTS, "gen", event_remove_actor_and_reassign_controller, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 52, 24)
