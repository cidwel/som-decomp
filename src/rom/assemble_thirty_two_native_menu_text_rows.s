; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

assemble_native_menu_doubled_text_half_row = $2387

.segment "CODE"
.org $2366
assemble_thirty_two_native_menu_text_rows:
    .i16
    ldx #$0000
    .i16
    ldy #$0000
    .a8
    lda #$20
    sta a:$A176
assemble_thirty_two_native_menu_text_rows_c02371:
    jsr assemble_native_menu_doubled_text_half_row
    jsr assemble_native_menu_doubled_text_half_row
    rep #$20
    txa
    clc
    .a16
    adc #$0020
    tax
    sep #$20
    dec a:$A176
    bne assemble_thirty_two_native_menu_text_rows_c02371
    rts
