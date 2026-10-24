#include "som_c.h"

/* C286B3 cast_native59_weighted_random_spell   [class B, 42 bytes, 16 instructions]
 * Source: src/rom/cast_native59_weighted_random_spell.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void cast_native59_weighted_random_spell(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t direct_page_86dc = 0;
    uint8_t data_bank_86dc = 0;
    uint16_t direct_page_86dc2 = 0;
    uint8_t data_bank_86dc2 = 0;
    uint16_t direct_page_86dc3 = 0;
    uint8_t data_bank_86dc3 = 0;
    uint16_t direct_page_86dc4 = 0;
    uint8_t data_bank_86dc4 = 0;
    r->a = 6;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x86B8, 0xC2300B); GUARD_JSR(c, sp_call, 0x86B8); } /* draw_boss_frame_random_number */
    uint16_t a_all = r->a;
    uint16_t value = BUS16(c, 0xC286DD + a_all);
    uint16_t value2 = RAM16(0x0287);
    r->a = value & 0xFF;
    r->x = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x86C8, 0xC2396D); GUARD_JSR(c, sp_call, 0x86C8); } /* prepare_boss_spell_targets */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x86CC, 0xC0001B); GUARD_JSL(c, sp_call, 0x86CC); } /* cast_spell_public_jump */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t y_ret3 = r->y;
    if ((a_all3 & 0xFF) != 0) {
        if (x_ret3) {
            direct_page_86dc = dp_ret;
            data_bank_86dc = db_ret;
            goto shared_86DC;
        } else {
            direct_page_86dc2 = dp_ret;
            data_bank_86dc2 = db_ret;
            goto shared_86DC_1;
        }
    }
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
    if (x_ret3) {
        r->a = value3 & 0x1FFF;
        r->x = (uint8_t)(value3 & 0x1FFF);
        r->y = (uint8_t)y_ret3;
        r->z = (uint8_t)(value3 & 0x1FFF) == 0;
        r->n = (uint8_t)(value3 & 0x1FFF) & 0x80;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x86DB, 0x01800F); GUARD_JSL(c, sp_call, 0x86DB); } /* cast_actor_request_public_jump */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret = r->mf;
        bool x_ret5 = r->xf;
        if (m_ret) {
            if (x_ret5) {
                direct_page_86dc3 = dp_ret2;
                data_bank_86dc3 = db_ret2;
                goto shared_86DC_2;
            } else {
                direct_page_86dc4 = dp_ret2;
                data_bank_86dc4 = db_ret2;
                goto shared_86DC_3;
            }
        } else {
            if (x_ret5) {
                direct_page_86dc = dp_ret2;
                data_bank_86dc = db_ret2;
                goto shared_86DC;
            } else {
                direct_page_86dc2 = dp_ret2;
                data_bank_86dc2 = db_ret2;
                goto shared_86DC_1;
            }
        }
    } else {
        r->a = value3 & 0x1FFF;
        r->x = value3 & 0x1FFF;
        r->z = (value3 & 0x1FFF) == 0;
        r->n = value3 & 0x1FFF & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x86DB, 0x01800F); GUARD_JSL(c, sp_call, 0x86DB); } /* cast_actor_request_public_jump */
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret7 = r->xf;
        if (m_ret2) {
            if (x_ret7) {
                direct_page_86dc3 = dp_ret3;
                data_bank_86dc3 = db_ret3;
                goto shared_86DC_2;
            } else {
                direct_page_86dc4 = dp_ret3;
                data_bank_86dc4 = db_ret3;
                goto shared_86DC_3;
            }
        } else {
            if (x_ret7) {
                direct_page_86dc = dp_ret3;
                data_bank_86dc = db_ret3;
                goto shared_86DC;
            } else {
                direct_page_86dc2 = dp_ret3;
                data_bank_86dc2 = db_ret3;
                goto shared_86DC_1;
            }
        }
    }
    shared_86DC:;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_86dc;
    r->dp = direct_page_86dc;
    RETURN_RTS(c);
    shared_86DC_1:;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_86dc2;
    r->dp = direct_page_86dc2;
    RETURN_RTS(c);
    shared_86DC_2:;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_86dc3;
    r->dp = direct_page_86dc3;
    RETURN_RTS(c);
    shared_86DC_3:;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_86dc4;
    r->dp = direct_page_86dc4;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC286B3, SOM_RTS, "gen", cast_native59_weighted_random_spell, 0, 0, 1, 0, 0, 42, 16)
