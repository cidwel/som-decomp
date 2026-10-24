; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E2A8
assign_large_object_palette_rows:
    rep #$30
    .a16
    lda #$00A2
    ldy $98
    beq assign_large_object_palette_rows_c0e2b4
    .a16
    eor #$0080
assign_large_object_palette_rows_c0e2b4:
    sta a:$E6F8
    clc
    .a16
    adc #$0020
    sta a:$E8F8
    clc
    .a16
    adc #$0020
    sta a:$EAF8
    .a16
    lda #$0082
    ldy $98
    beq assign_large_object_palette_rows_c0e2cf
    .a16
    eor #$0080
assign_large_object_palette_rows_c0e2cf:
    sta a:$E6FA
    clc
    .a16
    adc #$000A
    sta a:$E8FA
    clc
    .a16
    adc #$000A
    sta a:$EAFA
    rts
