; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-masks.md.
.setcpu "65816"
.smart
.a8
.i16

mark_native_inventory_descriptor_row_at_current_y = $FDFD
routine_d9fd72 = $FD72

.segment "CODE"
.org $FCC1
dispatch_native_inventory_status_masks_by_mode_and_category:
    rep #$30
    sep #$20
    lda a:$1847
    .a8
    cmp #$03
    bne dispatch_native_inventory_status_masks_by_mode_and_category_d9fcf2
    .i16
    ldx #$0000
    txy
dispatch_native_inventory_status_masks_by_mode_and_category_d9fcd0:
    lda f:$7ECC54,X
    .a8
    cmp #$FF
    beq dispatch_native_inventory_status_masks_by_mode_and_category_d9fceb
    lda f:$7ECFB0,X
    .a8
    cmp #$08
    bcs dispatch_native_inventory_status_masks_by_mode_and_category_d9fce6
    cmp f:$7ECFB8,X
    bcc dispatch_native_inventory_status_masks_by_mode_and_category_d9fce9
dispatch_native_inventory_status_masks_by_mode_and_category_d9fce6:
    jsr mark_native_inventory_descriptor_row_at_current_y
dispatch_native_inventory_status_masks_by_mode_and_category_d9fce9:
    iny
    iny
dispatch_native_inventory_status_masks_by_mode_and_category_d9fceb:
    inx
    .i16
    cpx #$0008
    bcc dispatch_native_inventory_status_masks_by_mode_and_category_d9fcd0
    rts
dispatch_native_inventory_status_masks_by_mode_and_category_d9fcf2:
    rep #$30
    lda a:$1844
    tax
    sep #$20
    lda f:$7E0011,X
    .a8
    bit #$04
    bne routine_d9fd72
    rep #$30
    lda a:$1809
    .a16
    and #$00FF
    asl
    asl
    tax
    jmp ($FD10,X)
