; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-font-layout.md.
.setcpu "65816"
.smart
.a8
.i16

decode_native_menu_font_stream_and_expand_double_rows = $2354
upload_native_menu_assembled_text_tiles = $23BA

.segment "CODE"
.org $2293
render_native_menu_description_with_alternating_rows:
    stz a:$A163
    .a8
    lda #$C0
    sta f:$001D03
    rep #$20
    stz a:$A1A0
    lda a:$A20F
    .a16
    and #$00FF
    .a16
    cmp #$00FF
    bne render_native_menu_description_with_alternating_rows_c022af
    jmp render_native_menu_description_with_alternating_rows_c02351
render_native_menu_description_with_alternating_rows_c022af:
    sta a:$A173
    asl
    clc
    adc a:$A173
    tax
    lda f:$C033B6,X
    sta f:$001D02
    lda f:$C033B5,X
    sta f:$001D01
    sep #$20
    stz a:$A1C5
    .a8
    lda #$01
    trb a:$A212
render_native_menu_description_with_alternating_rows_c022d2:
    .a8
    lda #$00
    sta f:$001D00
    jsr decode_native_menu_font_stream_and_expand_double_rows
    rep #$20
    lda a:$A217
    pha
    asl
    asl
    asl
    clc
    .a16
    adc #$6000
    sta a:$A18C
    lda a:$A20A
    .a16
    and #$0010
    beq render_native_menu_description_with_alternating_rows_c02312
    pla
    tax
    clc
    .a16
    adc #$0040
    sta a:$A217
    lda a:$A1A0
    inc
    sta a:$A1A0
    .a16
    and #$0001
    bne render_native_menu_description_with_alternating_rows_c02330
    txa
    clc
    .a16
    adc #$0014
    sta a:$A217
    bra render_native_menu_description_with_alternating_rows_c02330
render_native_menu_description_with_alternating_rows_c02312:
    pla
    clc
    .a16
    adc #$0038
    sta a:$A217
    lda a:$A1A0
    inc
    sta a:$A1A0
    .a16
    and #$0001
    beq render_native_menu_description_with_alternating_rows_c02330
    lda a:$A217
    clc
    .a16
    adc #$0008
    sta a:$A217
render_native_menu_description_with_alternating_rows_c02330:
    sep #$20
    .i16
    ldx #$0400
    stx a:$A191
    jsr upload_native_menu_assembled_text_tiles
    inc a:$A163
    lda a:$A163
    .a8
    cmp #$10
    bne render_native_menu_description_with_alternating_rows_c0234a
    .a8
    lda #$10
    trb a:$A20A
render_native_menu_description_with_alternating_rows_c0234a:
    lda a:$A212
    .a8
    bit #$01
    beq render_native_menu_description_with_alternating_rows_c022d2
render_native_menu_description_with_alternating_rows_c02351:
    sep #$20
    rts
