; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-font-layout.md.
.setcpu "65816"
.smart
.a8
.i16

decode_native_menu_font_stream_and_expand_double_rows = $2354
upload_native_menu_assembled_text_tiles = $23BA

.segment "CODE"
.org $2227
render_native_menu_heading_until_text_command:
    stz a:$A181
    .a8
    lda #$C7
    sta f:$001D03
    phb
    pha
    plb
    rep #$20
    .a16
    lda #$0050
    sta f:$7EA217
    lda f:$7EA20D
    tay
    lda a:$0000,Y
    sta f:$001D01
    sep #$20
    plb
    stz a:$A1C5
    .a8
    lda #$01
    trb a:$A212
render_native_menu_heading_until_text_command_c02253:
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
    lda a:$A1CE
    .a16
    and #$007F
    sta a:$A173
    pla
    clc
    adc a:$A173
    adc a:$A173
    sta a:$A217
    sep #$20
    .i16
    ldx #$0400
    stx a:$A191
    jsr upload_native_menu_assembled_text_tiles
    lda a:$A212
    .a8
    and #$01
    beq render_native_menu_heading_until_text_command_c02253
    rts
