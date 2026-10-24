; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


message_queue_buffer = $FE00
message_decimal_places = $5CC5

.segment "CODE"
.org $5C6C
append_message_word_decimal:
    phx
    phy
    .a8
    lda #$C0
    sta $B6
    .i16
    ldy #message_decimal_places
    rep #$20
    stz $B4
    .i16
    ldx #$0000
    .a16
    lda #$0005
    sta $B0
append_message_word_decimal_c05c81:
    lda [$B4],Y
    sta $AC
    .a16
    lda #$00B5
    sta $A4,X
    lda $D0
append_message_word_decimal_c05c8c:
    sec
    sbc $AC
    bmi append_message_word_decimal_c05c95
    inc $A4,X
    bra append_message_word_decimal_c05c8c
append_message_word_decimal_c05c95:
    clc
    adc $AC
    sta $D0
    iny
    iny
    inx
    dec $B0
    bne append_message_word_decimal_c05c81
    sep #$20
    .a8
    lda #$04
    sta $B2
    .i16
    ldx #$0000
append_message_word_decimal_c05caa:
    lda $A4,X
    .a8
    cmp #$B5
    bne append_message_word_decimal_c05cb5
    inx
    dec $B2
    bne append_message_word_decimal_c05caa
append_message_word_decimal_c05cb5:
    inc $B2
    ply
append_message_word_decimal_c05cb8:
    lda $A4,X
    sta a:message_queue_buffer,Y
    iny
    inx
    dec $B2
    bne append_message_word_decimal_c05cb8
    plx
    rts
