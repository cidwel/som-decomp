#include "som_c.h"

/* C28DA5 compare_descriptor_eleven_vertical_target_distance_with_48   [class A, 28 bytes, 15 instructions]
 * Source: src/rom/compare_descriptor_eleven_vertical_target_distance_with_48.s
 * Documented in docs/boss-descriptor-eleven-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void compare_descriptor_eleven_vertical_target_distance_with_48(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t x = dp_rd16(c, 0x87);                  /* LDX $87 */
    uint16_t a = RAM16(0x00A9 + x);                       /* LDA $00A9,X */
    a = (uint16_t)((a << 8) | (a >> 8));                  /* XBA */
    a = (uint16_t)(a << 1);                               /* ASL */
    r->c = false;                                             /* CLC */
    a = hand_adc16(r, a, 0xE000);                         /* ADC #$E000 */
    const uint16_t y = a;                                 /* TAY */
    a = RAM16(0x0032 + x);                                /* LDA $0032,X */
    r->c = true;                                             /* SEC */
    a = hand_sbc16(r, a, RAM16(0x0004 + y));              /* SBC $0004,Y */
    if (r->n) {
        a = (uint16_t)((a ^ dp_rd16(c, 0xC7)) + 1);       /* EOR $C7 ; INC */
    }
    hand_cmp16(r, a, 0x0030);                             /* CMP #$0030 */
    r->a = a;
    r->x = x;
    r->y = y;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28DA5, SOM_RTS, "hand", compare_descriptor_eleven_vertical_target_distance_with_48, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 0, 0, 0, 28, 15)
