#include "som_c.h"

/* C20AFD begin_boss_death_initialization_when_control_and_lock_clear   [class B, 23 bytes, 10 instructions]
 * Source: src/rom/begin_boss_death_initialization_when_control_and_lock_clear.s
 * Documented in docs/boss-native-linked-death-dependencies.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: AV.
 */
static void begin_boss_death_initialization_when_control_and_lock_clear(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool overflow = r->v;
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(0x0060 + battle_defence_work);
    bool m_flag2;
    bool x_flag2;
    uint8_t a2;
    bool overflow2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if ((value & 0xFF) != 0) {
        m_flag2 = 0;
        x_flag2 = 0;
        a2 = value & 0xFF;
        overflow2 = overflow;
        data_bank2 = 0x7E;
        direct_page2 = 0x0300;
    } else {
        uint16_t value2 = RAM16(0x004C + battle_defence_work);
        bool m_flag;
        bool x_flag;
        uint8_t a1;
        bool overflow1;
        uint8_t data_bank;
        uint16_t direct_page;
        if (value2 != 0) {
            m_flag = 0;
            x_flag = 0;
            a1 = (uint8_t)value2;
            overflow1 = overflow;
            data_bank = 0x7E;
            direct_page = 0x0300;
        } else {
            RAM16_SET(OBJECT_PHASE + battle_defence_work, (uint16_t)(RAM16(OBJECT_PHASE + battle_defence_work) + 1));
            r->x = battle_defence_work;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0B11, 0xC20B14); GUARD_JSR(c, sp_call, 0x0B11); } /* prepare_boss_death_palettes_graphics_and_selected_actor */
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            bool m_ret = r->mf;
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            bool overflow_ret = r->v;
            m_flag = m_ret;
            x_flag = x_ret;
            a1 = (uint8_t)a_all;
            overflow1 = overflow_ret;
            data_bank = db_ret;
            direct_page = dp_ret;
        }
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        a2 = a1;
        overflow2 = overflow1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    r->a = (a >> 8 << 8) | a2;
    r->v = overflow2;
    r->mf = m_flag2;
    r->xf = x_flag2;
    r->db = data_bank2;
    r->dp = direct_page2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20AFD, SOM_RTS, "gen", begin_boss_death_initialization_when_control_and_lock_clear, 0, L_A | L_V, 1, 0, 0, 23, 10)
