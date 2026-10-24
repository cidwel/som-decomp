#include "som_c.h"

/* C0C481 initialize_map_header_resources   [class B, 163 bytes, 73 instructions]
 * Source: src/rom/initialize_map_header_resources.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void initialize_map_header_resources(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    uint16_t value = RAM16(0x00DC);
    uint16_t value2 = BUS16(c, 0xC87000 + (uint16_t)(value << 1));
    RAM16_SET(0x001D, value2);
    uint16_t value3 = BUS16(c, 0xC87002 + (uint16_t)(value << 1));
    RAM8(0x0000 + sp0) = value3 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value3;
    RAM8(0x001F) = 0xC8;
    uint8_t value4 = BUS8_RDL(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D) + 3, RAM8(0x001F));
    RAM8(0x00B8) = value4;
    uint8_t value5 = BUS8_RDL(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D) + 1, RAM8(0x001F));
    RAM8(0x001B) = value5;
    uint8_t value6 = BUS8_RDL(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D), RAM8(0x001F));
    RAM8(0x001C) = value6;
    r->a = (value3 >> 8 << 8) | value6;
    r->x = (uint8_t)(value << 1);
    r->y = 0;
    r->c = value & 0x8000;
    r->z = value6 == 0;
    r->n = value6 & 0x80;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xC4AD, 0x01F403); GUARD_JSL(c, sp_call, 0xC4AD); } /* initialize_map_graphics_resources */
    r->sp += 2;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xC4B1, 0x01B0EC); GUARD_JSL(c, sp_call, 0xC4B1); } /* initialize_map_scroll_animation */
    r->sp += 2;
    r->mf = 1;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xC4B5, 0x01B17E); GUARD_JSL(c, sp_call, 0xC4B5); } /* initialize_map_character_animation */
    r->sp += 2;
    uint16_t a_all3 = r->a;
    uint8_t value7 = BUS8_RDL(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D) + 1, RAM8(0x001F));
    RAM8(0x001C) = value7;
    r->a = (a_all3 >> 8 << 8) | value7;
    r->y = 1;
    r->z = value7 == 0;
    r->n = value7 & 0x80;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xC4C1, 0x02BC7E); GUARD_JSL(c, sp_call, 0xC4C1); } /* initialize_map_palette_animation */
    r->sp += 2;
    uint16_t a_all4 = r->a;
    uint16_t x_ret6 = r->x;
    uint8_t value8 = BUS8_RDL(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D) + 2, RAM8(0x001F));
    RAM8(0x001C) = value8;
    r->a = (a_all4 >> 8 << 8) | value8;
    r->x = (uint8_t)x_ret6;
    r->y = 2;
    r->z = value8 == 0;
    r->n = value8 & 0x80;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xC4CD, 0x02A000); GUARD_JSL(c, sp_call, 0xC4CD); } /* initialize_map_tile_attributes_and_words */
    r->sp += 2;
    uint16_t a_all5 = r->a;
    uint8_t value9 = BUS8_RDL(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D) + 3, RAM8(0x001F));
    r->a = (a_all5 >> 8 << 8) | value9;
    r->y = 3;
    r->z = value9 == 0;
    r->n = value9 & 0x80;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC4D6, 0xC0C45D); GUARD_JSR(c, sp_call, 0xC4D6); } /* map_header_reserved_return */
    r->sp += 2;
    uint8_t value10 = BUS8_RDL(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D) + 4, RAM8(0x001F));
    r->a = (a_all5 >> 8 << 8) | value10;
    r->y = 4;
    r->z = value10 == 0;
    r->n = value10 & 0x80;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xC4E0, 0x02AB03); GUARD_JSL(c, sp_call, 0xC4E0); } /* apply_map_header_transition_flags */
    r->sp += 2;
    uint16_t a_all6 = r->a;
    uint8_t value11 = BUS8_RDL(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D) + 5, RAM8(0x001F));
    RAM8(0x0030) = value11;
    if ((value11 & 0xC0) == 0x40) {
        RAM8(0x0099) = 8;
    }
    uint8_t value12 = BUS8_RDL(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D) + 6, RAM8(0x001F));
    RAM8(0x0094) = value12;
    uint8_t value13 = BUS8_RDL(c, (RAM8(0x001F) << 0x10) + RAM16(0x001D) + 7, RAM8(0x001F));
    r->a = (a_all6 >> 8 << 8) | value13;
    r->y = 7;
    r->c = (value11 & 0xC0) >= 0x40;
    r->z = value13 == 0;
    r->n = value13 & 0x80;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC503, 0xC0C524); GUARD_JSR(c, sp_call, 0xC503); } /* select_map_object_palette_rows */
    r->sp += 2;
    RAM16_SET(0xE802, (uint16_t)(RAM16(0x001D) + 8));
    RAM16_SET(0xE804, RAM16(0x001F));
    uint8_t value16 = RAM8(0x0000 + sp0 - 1);
    uint8_t value17 = RAM8(0x0000 + sp0);
    uint16_t value18 = RAM16(0xE802);
    RAM16_SET(0xE800, (uint16_t)(((value17 << 8) | value16) - value18) >> 3);
    r->a = (uint16_t)(((value17 << 8) | value16) - value18) >> 3;
    r->c = (uint16_t)(((value17 << 8) | value16) - value18) >> 2 & 0x01;
    r->v = ((((value17 << 8) | value16) ^ value18) & (((value17 << 8) | value16) ^ (uint16_t)(((value17 << 8) | value16) - value18)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C481, SOM_RTS, "gen", initialize_map_header_resources, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 1, 163, 73)
