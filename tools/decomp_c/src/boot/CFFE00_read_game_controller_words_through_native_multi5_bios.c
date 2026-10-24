#include "som_c.h"

/* CFFE00 read_game_controller_words_through_native_multi5_bios   [class B, 83 bytes, 43 instructions]
 * Source: src/rom/read_game_controller_words_through_native_multi5_bios.s
 * Documented in docs/game-controller-inputs.md
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: ABXY.
 */
static void read_game_controller_words_through_native_multi5_bios(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t x_entry = r->xf;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x17) + 0xB > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6) | 0x20) | (x_entry << 4)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 0x17) = 0;
    RAM8(0x0000 + sp0 - 0x18) = 0;
    r->a = ((uint16_t)(sp0 - 0x17) >> 8 << 8) | 0;
    r->c = (uint16_t)(sp0 - 3) >= 0x14;
    r->z = 1;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 0x14) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x17)) & 0x8000) != 0;
    r->xf = 0;
    r->dp = (uint16_t)(sp0 - 0x17);
    r->sp -= 24;
    { const uint16_t sp_call = r->sp; JSR(c, 0xFE14, 0xCFFE70); GUARD_JSR(c, sp_call, 0xFE14); } /* detect_native_multi5_interfaces_from_serial_probes */
    r->sp += 24;
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    uint8_t value = RAM8(0x0001 + (uint16_t)(sp0 - 0x17));
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    if ((value & 0x40) == 0) {
        uint16_t value2 = BUS16(c, 0x004218);
        RAM16_SET(0x0042, value2);
        uint16_t value3 = BUS16(c, 0x00421A);
        RAM16_SET(0x0044, value3);
        RAM16_SET(0x0046, 0);
        a1 = 0;
        a_hi1 = 0;
        x1 = x_ret;
        y1 = y_ret;
    } else {
        r->a = (a_all >> 8 << 8) | value;
        r->z = (value & 0x40) == 0;
        r->n = value & 0x80;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 24;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFE1F, 0xCFFF2A); GUARD_JSR(c, sp_call, 0xFE1F); } /* read_native_multi5_auto_and_serial_controller_fields */
        r->sp += 24;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        RAM16_SET(0x0042, RAM16(0x000A + (uint16_t)(sp0 - 0x17)));
        RAM16_SET(0x0044, RAM16(0x0008 + (uint16_t)(sp0 - 0x17)));
        RAM16_SET(0x0046, RAM16(0x0006 + (uint16_t)(sp0 - 0x17)));
        a1 = 0xFF;
        a_hi1 = 0xFF;
        x1 = x_ret2;
        y1 = y_ret2;
    }
    uint8_t value7 = RAM8(0x0000 + sp0 - 0x17);
    RAM16_SET(0x0000 + sp0 - 4, (a_hi1 << 8) | a1);
    uint8_t value8 = RAM8(0x0000 + sp0 - 4);
    uint8_t value9 = RAM8(0x0000 + sp0 - 3);
    uint8_t value10 = RAM8(0x0000 + sp0 - 2);
    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
    uint8_t value12 = RAM8(0x0000 + sp0);
    r->a = (value9 << 8) | value8;
    r->x = x1;
    r->y = y1;
    r->mf = value10 & 0x20;
    r->xf = value10 & 0x10;
    r->db = value7;
    r->dp = (value12 << 8) | value11;
    r->i = value10 & 0x04;
    r->d = value10 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xCFFE00, SOM_RTL, "gen", read_game_controller_words_through_native_multi5_bios, 0, L_A | L_B | L_X | L_Y, 25, 1, -1, 83, 43)
