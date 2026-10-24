; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-font-layout.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $23CF
expand_native_menu_fixed_ornament_records:
    ldx a:$A20D
    inx
    inx
    inx
    inx
    phb
    .a8
    lda #$C7
    pha
    plb
    ldy a:$0000,X
expand_native_menu_fixed_ornament_records_c023de:
    .a8
    lda #$20
    xba
    lda a:$0000,Y
    beq expand_native_menu_fixed_ornament_records_c02401
    iny
    ldx a:$0000,Y
    iny
    iny
    sta f:$7E9000,X
    inc
    inc
    sta f:$7E9040,X
    xba
    sta f:$7E9001,X
    sta f:$7E9041,X
    bra expand_native_menu_fixed_ornament_records_c023de
expand_native_menu_fixed_ornament_records_c02401:
    iny
expand_native_menu_fixed_ornament_records_c02402:
    lda a:$0000,Y
    beq expand_native_menu_fixed_ornament_records_c02434
    iny
    xba
    lda a:$0000,Y
    iny
    ldx a:$0000,Y
    iny
    iny
    xba
expand_native_menu_fixed_ornament_records_c02413:
    xba
    sta f:$7E9000,X
    inc
    inc
    sta f:$7E9040,X
    inc
    inc
    pha
    .a8
    lda #$20
    sta f:$7E9001,X
    sta f:$7E9041,X
    pla
    inx
    inx
    xba
    dec
    bne expand_native_menu_fixed_ornament_records_c02413
    bra expand_native_menu_fixed_ornament_records_c02402
expand_native_menu_fixed_ornament_records_c02434:
    plb
    .a8
    ora #$20
    xba
    .a8
    cmp #$20
    bne expand_native_menu_fixed_ornament_records_c0243e
    .a8
    lda #$50
expand_native_menu_fixed_ornament_records_c0243e:
    tax
    stx a:$A1C7
    rts
