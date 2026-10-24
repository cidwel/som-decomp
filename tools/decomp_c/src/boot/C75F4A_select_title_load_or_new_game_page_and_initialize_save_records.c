#include "som_c.h"

/* C75F4A select_title_load_or_new_game_page_and_initialize_save_records   [class B, 61 bytes, 27 instructions]
 * Source: src/rom/select_title_load_or_new_game_page_and_initialize_save_records.s
 * Documented in docs/ui-native-loaded-game-title-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void select_title_load_or_new_game_page_and_initialize_save_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5F4C, 0xC751C2); GUARD_JSR(c, sp_call, 0x5F4C); } /* initialize_native_party_name_entry_records */
    uint8_t db_ret = r->db;
    uint8_t value = BUS8(c, 0x307FFF);
    if (value < 4) {
        uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0xA211);
        if (value2 != 0) {
            BUS8_SET(c, (db_ret << 0x10) + 0xA210, 2);
            BUS8_SET(c, (db_ret << 0x10) + 0xA211, 0);
            uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0xA20A);
            BUS8_SET(c, (db_ret << 0x10) + 0xA20A, value3 | 1);
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        uint16_t x1 = 0x0100;
        bool zero1 = 1;
        bool negative1 = 0;
        for (;;) {
            BUS8_SET(c, (db_ret << 0x10) + 0xCEFF + x1, 0);
            uint16_t x1_next = (uint16_t)(x1 - 1);
            bool zero1_next = (uint16_t)(x1 - 1) == 0;
            bool negative1_next = (uint16_t)(x1 - 1) & 0x8000;
            x1 = x1_next;
            zero1 = zero1_next;
            negative1 = negative1_next;
            if (!(x1 != 0)) break;
        }
        RAM8(0x0000 + sp0) = ((((negative1 << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero1 << 1) | value >= 4;
        r->a = 0x0200;
        r->c = value >= 4;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x5F72, 0xC00030); GUARD_JSL(c, sp_call, 0x5F72); } /* initialize_new_game_save_records_public_jump */
        r->sp += 1;
        uint8_t db_ret2 = r->db;
        uint8_t value4 = RAM8(0x0000 + sp0);
        if (value4 & 0x10) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            if (value4 & 0x20) {
                BUS8_SET(c, (db_ret2 << 0x10) + 0xA210, 3);
                BUS8_SET(c, (db_ret2 << 0x10) + 0xA211, 0);
                uint8_t value5 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA20A);
                BUS8_SET(c, (db_ret2 << 0x10) + 0xA20A, value5 | 1);
                r->mf = 1;
                r->xf = 0;
                r->i = value4 & 0x04;
                r->d = value4 & 0x08;
                RETURN_RTL(c);
            } else {
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            }
        }
    }
    BUS8_SET(c, 0x307FFF, 0);
    uint8_t value6 = BUS8_RDP(c, (db_ret << 0x10) + 0xA211);
    if (value6 != 0) {
        BUS8_SET(c, (db_ret << 0x10) + 0xA210, 2);
        BUS8_SET(c, (db_ret << 0x10) + 0xA211, 0);
        uint8_t value7 = BUS8_RDP(c, (db_ret << 0x10) + 0xA20A);
        BUS8_SET(c, (db_ret << 0x10) + 0xA20A, value7 | 1);
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    uint16_t x2 = 0x0100;
    bool zero2 = 1;
    bool negative2 = 0;
    for (;;) {
        BUS8_SET(c, (db_ret << 0x10) + 0xCEFF + x2, 0);
        uint16_t x2_next = (uint16_t)(x2 - 1);
        bool zero2_next = (uint16_t)(x2 - 1) == 0;
        bool negative2_next = (uint16_t)(x2 - 1) & 0x8000;
        x2 = x2_next;
        zero2 = zero2_next;
        negative2 = negative2_next;
        if (!(x2 != 0)) break;
    }
    RAM8(0x0000 + sp0) = ((((negative2 << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero2 << 1) | value >= 4;
    r->a = 0x0200;
    r->c = value >= 4;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5F72, 0xC00030); GUARD_JSL(c, sp_call, 0x5F72); } /* initialize_new_game_save_records_public_jump */
    r->sp += 1;
    uint8_t db_ret3 = r->db;
    uint8_t value8 = RAM8(0x0000 + sp0);
    if (value8 & 0x10) {
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    } else {
        if (value8 & 0x20) {
            BUS8_SET(c, (db_ret3 << 0x10) + 0xA210, 3);
            BUS8_SET(c, (db_ret3 << 0x10) + 0xA211, 0);
            uint8_t value9 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA20A);
            BUS8_SET(c, (db_ret3 << 0x10) + 0xA20A, value9 | 1);
            r->mf = 1;
            r->xf = 0;
            r->i = value8 & 0x04;
            r->d = value8 & 0x08;
            RETURN_RTL(c);
        } else {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        }
    }
}
SOM_REGISTER(0xC75F4A, SOM_RTL, "gen", select_title_load_or_new_game_page_and_initialize_save_records, 0, 0, 1, 1, 0, 61, 27)
