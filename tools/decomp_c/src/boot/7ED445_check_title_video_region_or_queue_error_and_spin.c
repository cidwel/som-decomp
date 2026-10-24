#include "som_c.h"

/* 7ED445 check_title_video_region_or_queue_error_and_spin   [class B, 46 bytes, 21 instructions]
 * Source: src/boot/check_title_video_region_or_queue_error_and_spin.s
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: ABXYCZNV.
 */
static void check_title_video_region_or_queue_error_and_spin(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = BUS8(c, 0x00213F);
    if ((value & 0x10) != 0) {
        r->a = (a_hi << 8) | 0;
        r->c = (value & 0x10) >= 0;
        r->z = 1;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD459, 0x7EC030); GUARD_JSR(c, sp_call, 0xD459); } /* allocate_ppu_register_entry */
        r->sp += 3;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        BUS8_SET(c, (db_ret << 0x10) + 2 + x_ret2, 0x0F);
        r->a = (a_all >> 8 << 8) | 0x0F;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD461, 0x7EC097); GUARD_JSR(c, sp_call, 0xD461); } /* append_oneshot_ppu_entry */
        r->sp += 3;
        uint8_t db_ret2 = r->db;
        bool x_ret3 = r->xf;
        uint16_t y_ret2 = r->y;
        if (x_ret3) {
            uint8_t value2 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x0306);
            r->x = value2;
            r->y = (uint8_t)y_ret2;
            r->z = value2 == 0;
            r->n = value2 & 0x80;
            r->xf = 1;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD467, 0x7E8EA6); GUARD_JSR(c, sp_call, 0xD467); } /* render_three_native_region_error_rows */
            r->sp += 3;
            uint8_t db_ret3 = r->db;
            bool x_ret4 = r->xf;
            uint16_t y_ret3 = r->y;
            if (x_ret4) {
                uint8_t value3 = BUS8_RDP(c, (db_ret3 << 0x10) + 0x0306);
                r->x = value3;
                r->y = (uint8_t)y_ret3;
                r->z = value3 == 0;
                r->n = value3 & 0x80;
                r->xf = 1;
                r->sp -= 3;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD46D, 0x7EC870); GUARD_JSR(c, sp_call, 0xD46D); } /* queue_registered_vram_buffer */
                r->sp += 3;
                r->sp -= 3;
                for (;;) { if (som_spin_exit(c, 0x7ED46E)) return; }
            } else {
                uint16_t value4 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0306);
                r->x = value4;
                r->z = value4 == 0;
                r->n = value4 & 0x8000;
                r->xf = 0;
                r->sp -= 3;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD46D, 0x7EC870); GUARD_JSR(c, sp_call, 0xD46D); } /* queue_registered_vram_buffer */
                r->sp += 3;
                r->sp -= 3;
                for (;;) { if (som_spin_exit(c, 0x7ED46E)) return; }
            }
        } else {
            uint16_t value5 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x0306);
            r->x = value5;
            r->z = value5 == 0;
            r->n = value5 & 0x8000;
            r->xf = 0;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD467, 0x7E8EA6); GUARD_JSR(c, sp_call, 0xD467); } /* render_three_native_region_error_rows */
            r->sp += 3;
            uint8_t db_ret4 = r->db;
            bool x_ret10 = r->xf;
            uint16_t y_ret6 = r->y;
            if (x_ret10) {
                uint8_t value6 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x0306);
                r->x = value6;
                r->y = (uint8_t)y_ret6;
                r->z = value6 == 0;
                r->n = value6 & 0x80;
                r->xf = 1;
                r->sp -= 3;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD46D, 0x7EC870); GUARD_JSR(c, sp_call, 0xD46D); } /* queue_registered_vram_buffer */
                r->sp += 3;
                r->sp -= 3;
                for (;;) { if (som_spin_exit(c, 0x7ED46E)) return; }
            } else {
                uint16_t value7 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x0306);
                r->x = value7;
                r->z = value7 == 0;
                r->n = value7 & 0x8000;
                r->xf = 0;
                r->sp -= 3;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD46D, 0x7EC870); GUARD_JSR(c, sp_call, 0xD46D); } /* queue_registered_vram_buffer */
                r->sp += 3;
                r->sp -= 3;
                for (;;) { if (som_spin_exit(c, 0x7ED46E)) return; }
            }
        }
    }
    SET_A8(r, value & 0x10);
    r->z = dp == 0;
    r->n = dp & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ED445, SOM_RTS, "gen", check_title_video_region_or_queue_error_and_spin, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 46, 21)
