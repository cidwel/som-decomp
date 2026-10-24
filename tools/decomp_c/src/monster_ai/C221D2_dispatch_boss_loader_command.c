#include "som_c.h"

/* C221D2 dispatch_boss_loader_command   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_boss_loader_command.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYV.
 */
static void dispatch_boss_loader_command(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    r->a = (a & 0xFF) << 1;
    r->x = (a & 0xFF) << 1;
    r->c = a & 0xFF & 0x8000;
    r->z = (a & 0xFF) << 1 == 0;
    r->n = (a & 0xFF) << 1 & 0x8000;
    switch ((a & 0xFF) << 1) {
    case 0x0000: TAIL_CALL(c, 0xC22218, SOM_RTS); /* boss_loader_load_palette_operands */
    case 0x0002: TAIL_CALL(c, 0xC22218, SOM_RTS); /* boss_loader_load_palette_operands */
    case 0x0004: TAIL_CALL(c, 0xC2222A, SOM_RTS); /* boss_loader_reserved_02_03 */
    case 0x0006: TAIL_CALL(c, 0xC2222A, SOM_RTS); /* boss_loader_reserved_02_03 */
    case 0x0008: TAIL_CALL(c, 0xC2222B, SOM_RTS); /* boss_loader_allocate_object_operands */
    case 0x000A: TAIL_CALL(c, 0xC2223C, SOM_RTS); /* boss_loader_reserved_05_06 */
    case 0x000C: TAIL_CALL(c, 0xC2223C, SOM_RTS); /* boss_loader_reserved_05_06 */
    case 0x000E: TAIL_CALL(c, 0xC2223D, SOM_RTS); /* boss_loader_reset_object_pool */
    case 0x0010: TAIL_CALL(c, 0xC22240, SOM_RTS); /* boss_loader_consume_song_word_and_invoke_music_request */
    case 0x0012: TAIL_CALL(c, 0xC22249, SOM_RTS); /* boss_loader_ram_resource_operands */
    case 0x0014: TAIL_CALL(c, 0xC22249, SOM_RTS); /* boss_loader_ram_resource_operands */
    case 0x0016: TAIL_CALL(c, 0xC22249, SOM_RTS); /* boss_loader_ram_resource_operands */
    case 0x0018: TAIL_CALL(c, 0xC22249, SOM_RTS); /* boss_loader_ram_resource_operands */
    case 0x001A: TAIL_CALL(c, 0xC22249, SOM_RTS); /* boss_loader_ram_resource_operands */
    case 0x001C: TAIL_CALL(c, 0xC22249, SOM_RTS); /* boss_loader_ram_resource_operands */
    case 0x001E: TAIL_CALL(c, 0xC22249, SOM_RTS); /* boss_loader_ram_resource_operands */
    case 0x0020: TAIL_CALL(c, 0xC22249, SOM_RTS); /* boss_loader_ram_resource_operands */
    case 0x0022: TAIL_CALL(c, 0xC22249, SOM_RTS); /* boss_loader_ram_resource_operands */
    case 0x0024: TAIL_CALL(c, 0xC22252, SOM_RTS); /* boss_loader_direct_vram_low_high_operands */
    case 0x0026: TAIL_CALL(c, 0xC2225B, SOM_RTS); /* boss_loader_write_word */
    case 0x0028: TAIL_CALL(c, 0xC2226C, SOM_RTS); /* boss_loader_reserved_parameter_14 */
    case 0x002A: TAIL_CALL(c, 0xC22275, SOM_RTS); /* boss_loader_reserved_parameter_15 */
    case 0x002C: TAIL_CALL(c, 0xC2227E, SOM_RTS); /* boss_loader_allocate_and_prepare_object */
    case 0x002E: TAIL_CALL(c, 0xC2234B, SOM_RTS); /* initialize_boss_graphics_pattern */
    case 0x0030: TAIL_CALL(c, 0xC2238A, SOM_RTS); /* reset_boss_secondary_object_buffers */
    case 0x0032: TAIL_CALL(c, 0xC223DA, SOM_RTS); /* boss_loader_create_descriptor_object */
    case 0x0034: TAIL_CALL(c, 0xC223E7, SOM_RTS); /* boss_loader_direct_vram_high_operands */
    case 0x0036: TAIL_CALL(c, 0xC223F0, SOM_RTS); /* fill_boss_graphics_buffers_through_dma */
    case 0x0038: TAIL_CALL(c, 0xC22459, SOM_RTS); /* boss_loader_call_native_callback */
    case 0x003A: TAIL_CALL(c, 0xC22464, SOM_RTS); /* boss_loader_indirect_vram_low_high_operands */
    case 0x003C: TAIL_CALL(c, 0xC2246D, SOM_RTS); /* boss_loader_indirect_vram_high_operands */
    default: TAIL_CALL(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x21DA + ((a & 0xFF) << 1))), SOM_RTS);
    }
}
SOM_REGISTER(0xC221D2, SOM_RTS, "gen", dispatch_boss_loader_command, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 8, 4)
