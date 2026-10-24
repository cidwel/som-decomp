; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-navigation-icons.md.
.setcpu "65816"
.smart
.a8
.i16

persist_native_menu_category_row_and_equipment_rank = $C06B4C

.segment "CODE"
.org $66F3
update_native_menu_horizontal_repeat_and_description_request:
    sep #$30
    lda a:$1814
    bne update_native_menu_horizontal_repeat_and_description_request_c0673f
    lda a:$1801
    .i8
    ldx #$FF
    .a8
    bit #$01
    bne update_native_menu_horizontal_repeat_and_description_request_c06720
    .i8
    ldx #$01
    .a8
    bit #$02
    bne update_native_menu_horizontal_repeat_and_description_request_c06720
    lda a:$1807
    bne update_native_menu_horizontal_repeat_and_description_request_c0673f
    lda a:$1806
    beq update_native_menu_horizontal_repeat_and_description_request_c0673a
    .a8
    lda #$04
    tsb a:$1802
    stz a:$1806
    jsl f:persist_native_menu_category_row_and_equipment_rank
    rts
update_native_menu_horizontal_repeat_and_description_request_c06720:
    lda a:$1806
    beq update_native_menu_horizontal_repeat_and_description_request_c06731
    cpx a:$1806
    beq update_native_menu_horizontal_repeat_and_description_request_c0673a
    lda a:$1807
    bne update_native_menu_horizontal_repeat_and_description_request_c0673a
    bra update_native_menu_horizontal_repeat_and_description_request_c06736
update_native_menu_horizontal_repeat_and_description_request_c06731:
    .a8
    lda #$1E
    sta a:$1848
update_native_menu_horizontal_repeat_and_description_request_c06736:
    txa
    sta a:$1806
update_native_menu_horizontal_repeat_and_description_request_c0673a:
    .a8
    lda #$04
    trb a:$1802
update_native_menu_horizontal_repeat_and_description_request_c0673f:
    rts
