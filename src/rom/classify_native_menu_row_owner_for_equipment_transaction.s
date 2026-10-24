; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-dispatch.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $74D2
classify_native_menu_row_owner_for_equipment_transaction:
    sep #$30
    tay
    .a8
    bit #$80
    bne classify_native_menu_row_owner_for_equipment_transaction_c074e1
    .a8
    lda #$00
    cpy a:$1808
    beq classify_native_menu_row_owner_for_equipment_transaction_c074e1
    inc
classify_native_menu_row_owner_for_equipment_transaction_c074e1:
    inc
    inc
    rts
