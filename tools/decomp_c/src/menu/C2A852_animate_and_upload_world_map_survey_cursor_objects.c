#include "som_c.h"

/* C2A852 animate_and_upload_world_map_survey_cursor_objects   [class D, 118 bytes, 51 instructions]
 * Source: src/rom/animate_and_upload_world_map_survey_cursor_objects.s
 * Documented in docs/ui-native-world-map-picker-composition.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCV.
 */
static void animate_and_upload_world_map_survey_cursor_objects(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x03F4);
    uint8_t a1;
    if ((value & 8) != 0) {
        a1 = 0xE2;
    } else {
        a1 = 0xE1;
    }
    RAM16_SET(0x0812, (0x3F << 8) | a1);
    uint8_t a2;
    uint8_t a_hi1;
    bool carry1;
    bool overflow1;
    if ((value & 0x10) == 0) {
        r->y = (uint8_t)y;
        r->mf = 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xA87F, 0xC2A8C8); GUARD_JSR(c, sp_call, 0xA87F); } /* derive_world_map_survey_cursor_and_optional_target_positions */
        uint16_t a_all = r->a;
        RAM16_SET(0x0800, a_all);
        RAM16_SET(0x0804, (a_all >> 8 << 8) | (uint8_t)((uint8_t)a_all + 0x10));
        RAM16_SET(0x0808, ((uint8_t)((a_all >> 8) + 0x10) << 8) | (uint8_t)a_all);
        a2 = (uint8_t)((uint8_t)a_all + 0x10);
        a_hi1 = (uint8_t)((a_all >> 8) + 0x10);
        carry1 = (uint8_t)a_all + 0x10 > 0xFF;
        overflow1 = (((uint8_t)a_all ^ (uint8_t)((uint8_t)a_all + 0x10)) & ((uint8_t)((uint8_t)a_all + 0x10) ^ 0x10) & 0x80) != 0;
    } else {
        RAM16_SET(0x0800, 0xE0FF);
        RAM16_SET(0x0804, 0xE0FF);
        RAM16_SET(0x0808, 0xE0FF);
        a2 = 0xFF;
        a_hi1 = 0xE0;
        carry1 = carry;
        overflow1 = overflow;
    }
    RAM16_SET(0x080C, (a_hi1 << 8) | a2);
    RAM16_SET(0x2102, 0);
    RAM16_SET(0x4372, 0x0800);
    RAM16_SET(0x4370, 0x0400);
    RAM8(0x4374) = 0;
    RAM16_SET(0x4375, 0x14);
    RAM8(0x420B) = 0x80;
    r->a = 0x14;
    r->x = 0x80;
    r->y = (uint8_t)y;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2A852, SOM_RTL, "gen", animate_and_upload_world_map_survey_cursor_objects, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 118, 51)
