#include "som_c.h"

/* C137E7 construct_spell_entity_graphics_audio_resources   [class B, 136 bytes, 72 instructions]
 * Source: src/rom/construct_spell_entity_graphics_audio_resources.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYCV.
 */
static void construct_spell_entity_graphics_audio_resources(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0B) + 0x8 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0C) = 0x7E;
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 0x0B), x);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0B), y);
    r->a = 0x0F01;
    r->c = (uint16_t)(sp0 - 3) >= 8;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 8) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0B)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 0x0B);
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3804, 0xC13D8F); GUARD_JSR(c, sp_call, 0x3804); } /* initialize_spell_entity_oam_workspace */
    r->sp += 12;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0005 + (uint16_t)(sp0 - 0x0B));
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 0x0B), (uint16_t)(value - 0xF800));
    uint16_t value2 = BUS16(c, 0xDCF800 + (uint16_t)(value - 0xF800));
    RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0B), value2 & 0xFF);
    r->a = (value2 & 0xFF) << 1 << 1 << 1 << 1 << 1;
    r->x = (value2 & 0xFF) << 1 << 1 << 1 << 1 << 1;
    r->c = (value2 & 0xFF) << 1 << 1 << 1 << 1 & 0x8000;
    r->z = (value2 & 0xFF) << 1 << 1 << 1 << 1 << 1 == 0;
    r->n = (value2 & 0xFF) << 1 << 1 << 1 << 1 << 1 & 0x8000;
    r->v = ((value ^ 0xF800) & (value ^ (uint16_t)(value - 0xF800)) & 0x8000) != 0;
    r->mf = 0;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3821, 0xC13D29); GUARD_JSR(c, sp_call, 0x3821); } /* allocate_spell_entity_heap_bytes */
    r->sp += 12;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t x_ret2 = r->x;
    BUS16_SET(c, (uint16_t)(dp_ret + 3), x_ret2);
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
    uint16_t value4 = BUS16(c, 0xDCF801 + value3);
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
    uint8_t value6 = BUS8_RDP(c, (db_ret << 0x10) + 0x29 + value5);
    uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret + 7));
    uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
    r->a = ((uint8_t)(value6 - 0xE0) >> 1 << 8) | value7;
    r->x = value8;
    r->y = value4;
    r->c = (uint8_t)(value6 - 0xE0) & 0x01;
    r->z = value8 == 0;
    r->n = value8 & 0x8000;
    r->v = ((value6 ^ 0xE0) & (value6 ^ (uint8_t)(value6 - 0xE0)) & 0x80) != 0;
    r->mf = 1;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x383D, 0xC13007); GUARD_JSR(c, sp_call, 0x383D); } /* convert_spell_entity_graphics_planes */
    r->sp += 12;
    uint16_t dp_ret2 = r->dp;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3840, 0xC12FE4); GUARD_JSR(c, sp_call, 0x3840); } /* wait_for_spell_entity_irq_completion */
    r->sp += 12;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 5));
    uint16_t value10 = BUS16(c, 0xDCF804 + value9);
    uint16_t value11 = BUS16(c, 0xDCF803 + value9);
    uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 3));
    r->a = value11;
    r->x = value12;
    r->y = value10;
    r->z = value12 == 0;
    r->n = value12 & 0x8000;
    r->mf = 0;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3852, 0xC1302E); GUARD_JSR(c, sp_call, 0x3852); } /* build_spell_entity_script_transfers */
    r->sp += 12;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 5));
    uint16_t value14 = BUS16(c, 0xDCF80E + value13);
    uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
    r->a = value14;
    r->x = value15;
    r->z = value15 == 0;
    r->n = value15 & 0x8000;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x385D, 0xC137AD); GUARD_JSR(c, sp_call, 0x385D); } /* send_spell_entity_actor_positional_sound */
    r->sp += 12;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
    uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 5));
    r->x = value17;
    r->y = value16;
    r->z = value17 == 0;
    r->n = value17 & 0x8000;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3864, 0xC1332C); GUARD_JSR(c, sp_call, 0x3864); } /* construct_spell_entity_visual_resource */
    r->sp += 12;
    if (r->mf != 0) { c->fail = 3; return; }
    uint8_t value18 = RAM8(0x0000 + sp0 - 0x0B);
    uint8_t value19 = RAM8(0x0000 + sp0 - 2);
    uint8_t value20 = RAM8(0x0000 + sp0 - 1);
    uint8_t value21 = RAM8(0x0000 + sp0);
    r->c = value19 & 0x01;
    r->v = value19 & 0x40;
    r->mf = value19 & 0x20;
    r->xf = value19 & 0x10;
    r->db = value18;
    r->dp = (value21 << 8) | value20;
    r->i = value19 & 0x04;
    r->d = value19 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC137E7, SOM_RTS, "gen", construct_spell_entity_graphics_audio_resources, 0, L_X | L_Y | L_C | L_V, 13, 1, 0, 136, 72)
