#include "som_c.h"
#include "som_hand.h"

/* 7EAD75 initialize_boot_resources   [class B, 179 bytes, 69 instructions]
 * Source: src/boot/initialize_boot_resources.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void initialize_boot_resources(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    r->a = 0x032E;
    r->x = 0x032E;
    r->c = 1;
    r->z = 0;
    r->n = 0;
    r->v = 0;
    r->mf = 0;
    r->db = 0x7F;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAD8C, 0x7EAF3C); GUARD_JSR(c, sp_call, 0xAD8C); } /* clear_native_boot_resource_headers_and_reserve_their_heap_units */
    r->sp += 4;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    r->a = 0x7EC7;
    r->x = 0xB480;
    r->y = 0x5000;
    r->z = 0;
    r->n = 1;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0xAD9D, 0xC10014); GUARD_JSL(c, sp_call, 0xAD9D); } /* decompress_block_long_call_wrapper */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xADA0, 0x7EBF6E); GUARD_JSR(c, sp_call, 0xADA0); } /* initialize_native_boot_ppu_shadow_and_sixty_three_record_pool */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xADA3, 0x7EBFDA); GUARD_JSR(c, sp_call, 0xADA3); } /* queue_thirty_eight_native_boot_ppu_defaults_from_loaded_descriptor */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xADA6, 0x7EC0FD); GUARD_JSR(c, sp_call, 0xADA6); } /* write_ppu_queue_entries */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xADA9, 0x7EC18B); GUARD_JSR(c, sp_call, 0xADA9); } /* apply_ppu_queue_shadow */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xADAC, 0x7EC8C8); GUARD_JSR(c, sp_call, 0xADAC); } /* initialize_copy_queue_pool */
    r->sp += 4;
    uint8_t db_ret4 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t value = BUS16(c, (db_ret4 << 0x10) + 0x10);
    BUS16_RMW_SET(c, (db_ret4 << 0x10) + 0x10, (uint16_t)(value + 1));
    uint16_t value2 = BUS16(c, 0x306001);
    uint16_t value3 = BUS16(c, 0x306401);
    uint16_t value4 = BUS16(c, 0x306801);
    uint16_t value5 = BUS16(c, 0x306C01);
    r->x = value2 ^ value3 ^ value4 ^ value5;
    r->z = (value2 ^ value3 ^ value4 ^ value5) == 0;
    r->n = (value2 ^ value3 ^ value4 ^ value5) & 0x8000;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xADC3, 0x7EC2D9); GUARD_JSR(c, sp_call, 0xADC3); } /* seed_fifteen_native_random_bytes_from_saved_slot_counters */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xADC6, 0x7EA826); GUARD_JSR(c, sp_call, 0xADC6); } /* initialize_twenty_native_task_records_and_dispatch_headers */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xADC9, 0x7EB129); GUARD_JSR(c, sp_call, 0xADC9); } /* initialize_two_hundred_fifty_six_native_eight_byte_message_records */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xADCC, 0x7ECB57); GUARD_JSR(c, sp_call, 0xADCC); } /* initialize_native_thirty_two_entry_four_byte_resource_table */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xADCF, 0x7EA2EB); GUARD_JSR(c, sp_call, 0xADCF); } /* initialize_native_controller_service_and_enable_automatic_polling */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xADD2, 0x7E8F08); GUARD_JSR(c, sp_call, 0xADD2); } /* initialize_native_display_resources_and_scratch_pointers */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xADD5, 0x7ED5C4); GUARD_JSR(c, sp_call, 0xADD5); } /* initialize_native_small_resource_callback_table */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xADD8, 0x7EBB67); GUARD_JSR(c, sp_call, 0xADD8); } /* initialize_native_sixteen_screen_records_with_inactive_markers */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xADDB, 0x7E8000); GUARD_JSR(c, sp_call, 0xADDB); } /* initialize_native_eight_resource_owner_records */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xADDE, 0x7EC6B1); GUARD_JSR(c, sp_call, 0xADDE); } /* initialize_native_four_resource_owner_records */
    r->sp += 4;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    r->a = 0x7EDC;
    r->x = 0xF240;
    r->y = 0x2000;
    r->z = 0;
    r->n = 1;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0xADEF, 0xC10014); GUARD_JSL(c, sp_call, 0xADEF); } /* decompress_block_long_call_wrapper */
    r->sp += 4;
    /* the 16-bit immediates of the remaining loads assume the callee returned with M=16 and X=16 */
    HAND_REQUIRE_WIDE(c);
    r->a = 0x7EDC;
    r->x = 0xE800;
    r->y = 0x4000;
    r->z = 0;
    r->n = 1;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0xAE00, 0xC10014); GUARD_JSL(c, sp_call, 0xAE00); } /* decompress_block_long_call_wrapper */
    r->sp += 4;
    HAND_REQUIRE_WIDE(c);
    r->a = 0x7EC7;
    r->x = 0xC1C0;
    r->y = 0x4C00;
    r->z = 0;
    r->n = 1;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0xAE11, 0xC10014); GUARD_JSL(c, sp_call, 0xAE11); } /* decompress_block_long_call_wrapper */
    r->sp += 4;
    HAND_REQUIRE_WIDE(c);
    r->a = 0;
    r->z = 1;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAE17, 0x7EC030); GUARD_JSR(c, sp_call, 0xAE17); } /* allocate_ppu_register_entry */
    r->sp += 4;
    HAND_REQUIRE_WIDE(c);
    BUS16_SET(c, ((uint32_t)r->db << 16) + 2 + r->x, 0);
    r->a = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAE20, 0x7EC097); GUARD_JSR(c, sp_call, 0xAE20); } /* append_oneshot_ppu_entry */
    r->sp += 4;
    HAND_REQUIRE_WIDE(c);
    {
        const uint32_t counter = ((uint32_t)r->db << 16) + 0x0010;
        const uint16_t value6 = BUS16(c, counter);
        BUS16_RMW_SET(c, counter, (uint16_t)(value6 - 1));
    }
    r->sp -= 4;
    hand_plb(c);
    hand_plp(c);
    hand_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EAD75, SOM_RTS, "hand", initialize_boot_resources, 0, L_B | L_Y | L_C | L_V, 5, 1, 0, 179, 69)
