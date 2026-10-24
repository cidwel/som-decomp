#include "som_c.h"

/* C0951C detect_controller_interface_change_and_reassign_first_player   [class B, 52 bytes, 28 instructions]
 * Source: src/rom/detect_controller_interface_change_and_reassign_first_player.s
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: XYV.
 */
static void detect_controller_interface_change_and_reassign_first_player(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t x_entry = r->xf;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = (((((negative << 7) | (overflow << 6) | 0x20) | (x_entry << 4)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x9520, 0xCFFE00); GUARD_JSL(c, sp_call, 0x9520); } /* read_game_controller_words_through_native_multi5_bios */
    r->sp += 1;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    uint8_t value = RAM8(0x0000 + sp0);
    if (value & 0x20) {
        if ((uint8_t)a_all == 0) {
            uint8_t value2 = RAM8(0x00DB);
            if (value2 == 0) {
                r->v = value & 0x40;
                r->mf = 1;
                r->xf = value & 0x10;
                r->i = value & 0x04;
                r->d = value & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            RAM8(0x00DB) = 0;
            RAM8(0x0000 + sp0) = db;
            RAM8(0x0000 + sp0 - 1) = 0x7E;
            RAM8(0xE02C + (((value2 & 6) << 8) | 0)) = 0;
            RAM8(0xE08C + (((value2 & 6) << 8) | 0)) = 0;
            uint8_t value3 = RAM8(0x0000 + sp0);
            uint8_t value4 = RAM8(0x00DA);
            uint8_t value5 = RAM8(0x00D9);
            if ((value4 | value5) != 0) {
                r->x = ((value2 & 6) << 8) | 0;
                r->y = y_ret & 0xFFFF - ((value >> 4) & 1) * 0xFF00;
                r->v = value & 0x40;
                r->mf = 1;
                r->xf = 0;
                r->db = value3;
                r->i = value & 0x04;
                r->d = value & 0x08;
                RETURN_RTS(c);
            }
            r->a = ((value2 & 6) << 8) | (value4 | value5);
            r->x = 0;
            r->y = (uint8_t)(y_ret & 0xFFFF - ((value >> 4) & 1) * 0xFF00);
            r->c = value & 0x01;
            r->z = 1;
            r->n = 0;
            r->v = value & 0x40;
            r->mf = 1;
            r->xf = 1;
            r->db = value3;
            r->i = value & 0x04;
            r->d = value & 0x08;
            { const uint16_t sp_call = r->sp; JSL(c, 0x954E, 0x00BDBB); GUARD_JSL(c, sp_call, 0x954E); } /* reassign_controller_with_saved_bank */
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        r->v = value & 0x40;
        r->mf = 1;
        r->xf = value & 0x10;
        r->i = value & 0x04;
        r->d = value & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    }
}
SOM_REGISTER(0xC0951C, SOM_RTS, "gen", detect_controller_interface_change_and_reassign_first_player, 0, L_X | L_Y | L_V, 2, 1, -1, 52, 28)
