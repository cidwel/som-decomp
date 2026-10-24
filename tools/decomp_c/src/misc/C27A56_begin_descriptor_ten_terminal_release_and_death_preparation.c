#include "som_c.h"

/* C27A56 begin_descriptor_ten_terminal_release_and_death_preparation   [class A, 21 bytes, 9 instructions]
 * Source: src/rom/begin_descriptor_ten_terminal_release_and_death_preparation.s
 * Documented in docs/boss-descriptor-ten-terminal.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void begin_descriptor_ten_terminal_release_and_death_preparation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(0x0060 + battle_defence_work);
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((value & 0xFF) != 0) {
        m_flag = 0;
        x_flag = 0;
        a1 = value & 0xFF;
        a_hi1 = 0;
        x1 = battle_defence_work;
        y1 = y;
        zero1 = (value & 0xFF) == 0;
        negative1 = value & 0xFF & 0x8000;
        overflow1 = overflow;
        data_bank = 0x7E;
        direct_page = 0x0300;
    } else {
        RAM16_SET(OBJECT_PHASE + battle_defence_work, (uint16_t)(RAM16(OBJECT_PHASE + battle_defence_work) + 1));
        r->a = value & 0xFF;
        { const uint16_t sp_call = r->sp; JSR(c, 0x7A65, 0xC2EFBE); GUARD_JSR(c, sp_call, 0x7A65); } /* release_selected_party_control_without_palette_or_music */
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x7A68, 0xC20B14); GUARD_JSR(c, sp_call, 0x7A68); } /* prepare_boss_death_palettes_graphics_and_selected_actor */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret2 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret3 = r->x;
        uint16_t y_ret2 = r->y;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret2 = r->v;
        m_flag = m_ret;
        x_flag = x_ret2;
        a1 = (uint8_t)a_all2;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret3;
        y1 = y_ret2;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
        overflow1 = overflow_ret2;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27A56, SOM_RTS, "gen", begin_descriptor_ten_terminal_release_and_death_preparation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 21, 9)
