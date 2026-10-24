; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

add_wrapped_menu_row_to_inventory_label_offset = $D530
locate_selected_armor_with_nonzero_level = $D0D0DA
locate_selected_weapon_with_nonzero_level = $D0D0B0
offset_armor_inventory_description_by_position = $D0D1FB
publish_selected_equipment_description_row = $D0CE5D

.segment "CODE"
.org $D3F0
select_complete_native_menu_description_script:
    sep #$20
    lda a:$1803
    .a8
    bit #$20
    beq select_complete_native_menu_description_script_d0d442
    rep #$30
    ldx a:$1822
    lda $00,X
    .a16
    cmp #$FFFF
    bne select_complete_native_menu_description_script_d0d40c
    .a16
    lda #$9C55
    sta a:$19D2
    rts
select_complete_native_menu_description_script_d0d40c:
    .a16
    cmp #$E600
    bcs select_complete_native_menu_description_script_d0d41e
    .i16
    ldx #$0057
    stx a:$19D2
    xba
    lsr
    .a16
    and #$0003
    bra select_complete_native_menu_description_script_d0d43f
select_complete_native_menu_description_script_d0d41e:
    .i16
    ldx #$0054
    stx a:$19D2
    tax
    lda f:$7E0180,X
    .a16
    and #$00FF
    .a16
    cmp #$00EA
    bne select_complete_native_menu_description_script_d0d43b
    .a16
    lda #$5654
    sta a:$19D2
    stz a:$19D4
    rts
select_complete_native_menu_description_script_d0d43b:
    lda f:$7E0180,X
select_complete_native_menu_description_script_d0d43f:
    jmp select_complete_native_menu_description_script_d0d4d9
select_complete_native_menu_description_script_d0d442:
    sep #$20
    lda a:$1847
    dec
    bne select_complete_native_menu_description_script_d0d46c
    rep #$30
    lda a:$19D3
    .a16
    and #$00FF
    clc
    adc a:$183C
    tax
    lda f:$D80000,X
    sep #$20
    .a8
    cmp #$BA
    bcs select_complete_native_menu_description_script_d0d466
    clc
    .a8
    adc #$CD
    bra select_complete_native_menu_description_script_d0d469
select_complete_native_menu_description_script_d0d466:
    sec
    .a8
    sbc #$32
select_complete_native_menu_description_script_d0d469:
    jmp select_complete_native_menu_description_script_d0d4d9
select_complete_native_menu_description_script_d0d46c:
    rep #$30
    lda a:$1809
    .a16
    and #$00FF
    asl
    clc
    .a16
    adc #$D564
    tax
    sep #$20
    stx a:$1859
    lda a:$1809
    dec
    beq select_complete_native_menu_description_script_d0d4df
    dec
    beq select_complete_native_menu_description_script_d0d4cc
    dec
    bne select_complete_native_menu_description_script_d0d48e
    jmp select_complete_native_menu_description_script_d0d511
select_complete_native_menu_description_script_d0d48e:
    lda f:$D00000,X
    sep #$30
    clc
    adc a:$19D3
    ldx a:$1809
    beq select_complete_native_menu_description_script_d0d4a4
    sec
    sbc a:$19D3
    jsr add_wrapped_menu_row_to_inventory_label_offset
select_complete_native_menu_description_script_d0d4a4:
    tax
    lda f:$7ECC00,X
    .a8
    cmp #$FE
    bcc select_complete_native_menu_description_script_d0d4be
    .a8
    cmp #$FF
    bne select_complete_native_menu_description_script_d0d4ba
    lda a:$1847
    beq select_complete_native_menu_description_script_d0d4ba
    stz a:$19D2
    rts
select_complete_native_menu_description_script_d0d4ba:
    .a8
    lda #$9B
    bra select_complete_native_menu_description_script_d0d4d9
select_complete_native_menu_description_script_d0d4be:
    .a8
    and #$3F
    ldy a:$1809
    bne select_complete_native_menu_description_script_d0d4c7
    .a8
    and #$1F
select_complete_native_menu_description_script_d0d4c7:
    sep #$20
    sta a:$19D3
select_complete_native_menu_description_script_d0d4cc:
    rep #$10
    ldx a:$1859
    lda f:$D00001,X
    clc
    adc a:$19D3
select_complete_native_menu_description_script_d0d4d9:
    sta a:$19D3
    rep #$30
    rts
select_complete_native_menu_description_script_d0d4df:
    rep #$20
    .a16
    lda #$0056
    sta a:$19D2
    lda a:$1803
    .a16
    and #$0080
    bne select_complete_native_menu_description_script_d0d509
    lda a:$1808
    .a16
    and #$0001
    beq select_complete_native_menu_description_script_d0d4fd
    jsl f:locate_selected_weapon_with_nonzero_level
    bra select_complete_native_menu_description_script_d0d501
select_complete_native_menu_description_script_d0d4fd:
    jsl f:locate_selected_armor_with_nonzero_level
select_complete_native_menu_description_script_d0d501:
    txa
    sep #$20
    clc
    .a8
    adc #$2A
    bra select_complete_native_menu_description_script_d0d4d9
select_complete_native_menu_description_script_d0d509:
    rep #$20
    jsl f:publish_selected_equipment_description_row
    bra select_complete_native_menu_description_script_d0d4d9
select_complete_native_menu_description_script_d0d511:
    lda f:$D00000,X
    sep #$30
    tax
    ldy a:$19D3
select_complete_native_menu_description_script_d0d51b:
    lda f:$7ECC00,X
    inx
    .a8
    cmp #$FF
    beq select_complete_native_menu_description_script_d0d51b
    dey
    bpl select_complete_native_menu_description_script_d0d51b
    .a8
    and #$3F
    dex
    jsl f:offset_armor_inventory_description_by_position
    bra select_complete_native_menu_description_script_d0d4c7
