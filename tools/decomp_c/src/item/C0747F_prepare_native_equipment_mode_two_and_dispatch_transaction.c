#include "som_c.h"

/* C0747F prepare_native_equipment_mode_two_and_dispatch_transaction   [class C, 83 bytes, hand written]
 * docs/event-menu-equipment-dispatch.md.  Sets the native menu to equipment mode 2, publishes the cursor context and
 * dispatches one of sixteen equipment transactions by (owner class of the previous row, owner class of the current row).
 *
 *   audio request 0E ; $19F0 = 2 ; locate the category's inventory and equipment spans (D0:C800)
 *   $186A = X, $186C = Y, $1840 = A                     the spans returned by the locator
 *   $182A = $E180 + ((($1808 & 3) << 9) + Y)           equipment field address of the selected hero row
 *   $1820 = X ; resolve the rotated inventory selection from $180A (C0:7635)
 *   owner0 = classify($185D)                            C074D2: previous row, FE -> 0, FF -> 1, same hero 2, other hero 3
 *   owner1 = classify(mark the selected ring row)       C0794A returns the current row owner, then classified again
 *   index  = ((owner0 * 4 + owner1) << 1)               JMP ($74E4,X): sixteen near pointers at C0:74E4
 *
 * Entry: any widths; the routine sets them.  The helpers of rt/somlift.h keep every flag the targets can read.
 */
static void prepare_native_equipment_mode_two_and_dispatch_transaction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    JSL(c, 0x7482, 0xD0CF08); /* request_native_menu_audio_0e */
    r->mf = 1; /* SEP #$20 */
    a_lda(r, 2);
    RAM8(0x19F0) = 2;
    JSL(c, 0x748D, 0xD0C800); /* locate_menu_category_inventory_and_equipment_spans */
    r->mf = 0; /* REP #$30 */
    r->xf = 0;
    RAM16_SET(0x186A, r->x);
    RAM16_SET(0x186C, r->y);
    RAM16_SET(0x1840, r->a);
    const uint16_t saved_y = r->y; /* PHY */
    push16(c, saved_y);
    a_lda(r, RAM16(0x1808));
    a_and(r, 3);
    r->a = (uint16_t)((r->a << 8) | (r->a >> 8)); /* XBA */
    zn(r, r->a, 1);
    r->c = r->a >> 15;
    r->a = (uint16_t)(r->a << 1); /* ASL A */
    zn(r, r->a, 0);
    r->c = 0;
    a_adc(r, 0xE180);
    r->c = 0;
    a_adc(r, saved_y); /* ADC 1,S */
    RAM16_SET(0x182A, r->a);
    a_lda(r, pull16(c)); /* PLA */
    RAM16_SET(0x1820, r->x);
    a_lda(r, RAM16(0x180A));
    JSR(c, 0x74B5, 0xC07635); /* resolve_native_rotated_inventory_selection_with_sparse_armor_slots */
    r->mf = 1; /* SEP #$30 */
    r->xf = 1;
    r->x &= 0xFF;
    r->y &= 0xFF;
    a_lda(r, RAM8(0x185D));
    JSR(c, 0x74BD, 0xC074D2); /* classify_native_menu_row_owner_for_equipment_transaction */
    push8(c, (uint8_t)r->a); /* PHA */
    JSR(c, 0x74C1, 0xC0794A); /* mark_selected_native_ring_row_and_return_owner_or_special_descriptor */
    JSR(c, 0x74C4, 0xC074D2);
    for (int i = 0; i < 2; i++) { /* ASL, ASL */
        r->c = (r->a >> 7) & 1;
        r->a = (r->a & 0xFF00) | ((r->a << 1) & 0xFF);
        zn(r, r->a, 1);
    }
    r->c = 0;
    a_adc(r, RAM8((uint16_t)(r->sp + 1))); /* ADC 1,S */
    r->y = pull8(c); /* PLY */
    zn(r, r->y, 1);
    r->c = (r->a >> 7) & 1; /* ASL A */
    r->a = (r->a & 0xFF00) | ((r->a << 1) & 0xFF);
    zn(r, r->a, 1);
    r->x = r->a & 0xFF; /* TAX */
    zn(r, r->x, 1);
    r->mf = 0; /* REP #$30 */
    r->xf = 0;
    switch (r->x) {
    case 0x00: TAIL_CALL(c, 0xC07598, SOM_RTS); break;
    case 0x02: TAIL_CALL(c, 0xC075AE, SOM_RTS); break;
    case 0x04: TAIL_CALL(c, 0xC07561, SOM_RTS); break;
    case 0x06: TAIL_CALL(c, 0xC07598, SOM_RTS); break;
    case 0x08: TAIL_CALL(c, 0xC075AE, SOM_RTS); break;
    case 0x0A: TAIL_CALL(c, 0xC07504, SOM_RTS); break; /* retarget_native_selected_equipment_owner_or_apply_same_row */
    case 0x0C: TAIL_CALL(c, 0xC07527, SOM_RTS); break;
    case 0x0E: TAIL_CALL(c, 0xC07598, SOM_RTS); break;
    case 0x10: TAIL_CALL(c, 0xC07561, SOM_RTS); break;
    case 0x12: TAIL_CALL(c, 0xC0751F, SOM_RTS); break;
    case 0x14: TAIL_CALL(c, 0xC07571, SOM_RTS); break;
    case 0x16: TAIL_CALL(c, 0xC0773A, SOM_RTS); break;
    case 0x18: TAIL_CALL(c, 0xC07598, SOM_RTS); break;
    case 0x1A: TAIL_CALL(c, 0xC07598, SOM_RTS); break;
    case 0x1C: TAIL_CALL(c, 0xC0773A, SOM_RTS); break;
    case 0x1E: TAIL_CALL(c, 0xC07715, SOM_RTS); break;
    default: TAIL_CALL(c, 0xC00000 | BUS16(c, 0xC074E4 + r->x), SOM_RTS); break;
    }
}
SOM_REGISTER(0xC0747F, SOM_RTS, "hand", prepare_native_equipment_mode_two_and_dispatch_transaction, 0, L_ALL, 16, -1, -1, 83, 38)
