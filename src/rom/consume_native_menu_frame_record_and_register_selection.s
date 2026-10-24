; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-records.md.
.setcpu "65816"
.smart
.a8
.i16

expand_native_menu_bottom_border = $2576
expand_native_menu_frame_vertical_pairs = $24E3
expand_native_menu_top_border = $2556

.segment "CODE"
.org $248F
consume_native_menu_frame_record_and_register_selection:
    ldx a:$0000,Y
    iny
    iny
    rep #$20
    lda a:$0000,Y
    iny
    iny
    sep #$20
    phy
    tay
    phb
    .a8
    lda #$7E
    pha
    plb
    sty a:$A163
    sty a:$A16B
    lda a:$A20A
    .a8
    bit #$20
    beq consume_native_menu_frame_record_and_register_selection_c024d0
    rep #$20
    lda a:$A200
    .a16
    and #$00FF
    asl
    asl
    tay
    txa
    sta a:$A1E0,Y
    lda a:$A16B
    sta a:$A1E2,Y
    sep #$20
    inc a:$A200
    .a8
    lda #$20
    trb a:$A20A
consume_native_menu_frame_record_and_register_selection_c024d0:
    phx
    jsr expand_native_menu_top_border
    jsr expand_native_menu_frame_vertical_pairs
    jsr expand_native_menu_bottom_border
    .a8
    lda #$40
    trb a:$A20A
    plx
    plb
    ply
    rts
