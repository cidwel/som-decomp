#include "som_c.h"

/* C000C9 open_load_game_menu_and_enter_selected_map_or_cold_boot   [class B, 74 bytes, 25 instructions]
 * Source: src/rom/open_load_game_menu_and_enter_selected_map_or_cold_boot.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCV.
 * Hand completed (r15 captures-C): the generated text stopped after the M=8 arm of the first JSL; the M=16 arm, the final lda/plp/jml 00800C are added.
 * DB is not used by this routine (long addressing); C00FAA checks the DB and D it needs itself, and the real entry has DB=00.
 */
static void open_load_game_menu_and_enter_selected_map_or_cold_boot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x19FD) = 0;
    RAM8(0xCFF6) = 0;
    uint8_t value = RAM8(0xA212);
    RAM8(0xA212) = value | 0x10;
    r->a = (a_hi << 8) | (value | 0x10);
    r->z = (value | 0x10) == 0;
    r->n = (value | 0x10) & 0x80;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x00E2, 0xC00FAA); GUARD_JSR(c, sp_call, 0x00E2); } /* clear_direct_page_and_party_workspace_before_load_game_menu */
    r->sp += 1;
    uint16_t a_all = r->a;
    RAM8(0x011F) = 0xFF;
    r->a = (a_all >> 8 << 8) | 6;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x00EE, 0xC01D97); GUARD_JSL(c, sp_call, 0x00EE); } /* run_native_menu_coordinator_before_exceptional_callback */
    r->sp += 1;
    uint16_t value2 = RAM16(0xA213);
    if (value2 == 0x0707) {
        uint8_t value3 = RAM8(0x0000 + sp0);
        r->a = value2;
        r->c = value3 & 0x01;
        r->z = value3 & 0x02;
        r->n = value3 & 0x80;
        r->v = value3 & 0x40;
        r->mf = value3 & 0x20;
        r->xf = value3 & 0x10;
        r->i = value3 & 0x04;
        r->d = value3 & 0x08;
        TAIL_CALL(c, 0xC10010, SOM_RTS); /* jump_to_cold_boot */
    }
    r->a = value2;
    r->c = value2 >= 0x0707;
    r->z = value2 == 0x0707;
    r->n = (uint16_t)(value2 - 0x0707) & 0x8000;
    r->mf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x00FC, 0xC00FD5); GUARD_JSR(c, sp_call, 0x00FC); } /* request_audio_macro_eighty_with_parameter_thirty_two */
    r->sp += 1;
    bool m_ret2 = r->mf;
    uint16_t a_all3 = r->a;
    if (m_ret2) {
        uint8_t value4 = RAM8(0xA23C);
        r->a = (a_all3 >> 8 << 8) | value4;
        r->z = value4 == 0;
        r->n = value4 & 0x80;
        r->mf = 1;
    } else {
        uint16_t value4 = RAM16(0xA23C);
        r->a = value4;
        r->z = value4 == 0;
        r->n = value4 & 0x8000;
        r->mf = 0;
    }
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x0104, 0xC2000F); GUARD_JSL(c, sp_call, 0x0104); } /* public_boss_random_initialization_jump */
    r->sp += 1;
    bool m_ret3 = r->mf;
    uint16_t a_all4 = r->a;
    if (m_ret3) {
        uint8_t value5 = RAM8(0xA25A);
        r->a = (a_all4 >> 8 << 8) | value5;
        r->z = value5 == 0;
        r->n = value5 & 0x80;
    } else {
        uint16_t value5 = RAM16(0xA25A);
        r->a = value5;
        r->z = value5 == 0;
        r->n = value5 & 0x8000;
    }
    {
        uint8_t value6 = RAM8(0x0000 + sp0);
        r->c = value6 & 0x01;
        r->z = value6 & 0x02;
        r->n = value6 & 0x80;
        r->v = value6 & 0x40;
        r->mf = value6 & 0x20;
        r->xf = value6 & 0x10;
        r->i = value6 & 0x04;
        r->d = value6 & 0x08;
    }
    TAIL_CALL(c, 0x00800C, SOM_RTS); /* routine_00800c */
}
SOM_REGISTER(0xC000C9, SOM_RTS, "hand", open_load_game_menu_and_enter_selected_map_or_cold_boot, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 74, 25)
