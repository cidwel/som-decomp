#include "som_c.h"

/* 7ECD50 run_native_title_main_driver_and_restore_task_context   [class B, 50 bytes, 24 instructions]
 * Source: src/boot/run_native_title_main_driver_and_restore_task_context.s
 * Documented in docs/source-recovery-parallel-title-driver.md
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: ABXYCZNV.
 */
static void run_native_title_main_driver_and_restore_task_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    r->a = 0x0F01;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD62, 0x7EB42B); GUARD_JSR(c, sp_call, 0xCD62); } /* initialize_native_one_hundred_twenty_eight_sprite_records_and_thirty_two_groups */
    r->sp += 4;
    r->a = 0;
    r->x = 0x0100;
    r->y = 0xE0;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD6E, 0x7E87DF); GUARD_JSR(c, sp_call, 0xCD6E); } /* initialize_colour_workspace */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD71, 0x7ECDBF); GUARD_JSR(c, sp_call, 0xCD71); } /* construct_native_boot_title_graphics_palette_and_background_resources */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD74, 0x7ECE62); GUARD_JSR(c, sp_call, 0xCD74); } /* reserved_native_title_status_and_direct_page_api */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD77, 0x7EA4C2); GUARD_JSR(c, sp_call, 0xCD77); } /* register_native_current_task_as_boot_input_owner */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD7A, 0x7ED473); GUARD_JSR(c, sp_call, 0xCD7A); } /* prepare_native_title_coordinator_and_enter_palette_spawn_prefix */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD7D, 0x7EA4D7); GUARD_JSR(c, sp_call, 0xCD7D); } /* clear_native_boot_input_owner */
    r->sp += 4;
    uint8_t value = RAM8(0x0000 + sp0 - 3);
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->c = value2 & 0x01;
    r->z = ((value4 << 8) | value3) == 0;
    r->n = ((value4 << 8) | value3) & 0x8000;
    r->v = value2 & 0x40;
    r->mf = value2 & 0x20;
    r->xf = value2 & 0x10;
    r->db = value;
    r->dp = (value4 << 8) | value3;
    r->i = value2 & 0x04;
    r->d = value2 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0x7ECD50, SOM_RTL, "gen", run_native_title_main_driver_and_restore_task_context, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 50, 24)
