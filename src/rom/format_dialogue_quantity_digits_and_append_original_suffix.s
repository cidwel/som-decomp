; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-number-window.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $19C7
format_dialogue_quantity_digits_and_append_original_suffix:
    .i16
    ldy #$0000
    .i16
    ldx #$0000
    .a8
    lda #$06
format_dialogue_quantity_digits_and_append_original_suffix_c019cf:
    xba
    lda a:$A136,Y
    iny
    .a8
    cmp #$00
    bne format_dialogue_quantity_digits_and_append_original_suffix_c019e4
    .a8
    lda #$80
    sta a:$A1E0,X
    inx
    xba
    dec
    bne format_dialogue_quantity_digits_and_append_original_suffix_c019cf
    iny
    xba
format_dialogue_quantity_digits_and_append_original_suffix_c019e4:
    xba
    dey
    inc
format_dialogue_quantity_digits_and_append_original_suffix_c019e7:
    xba
    lda a:$A136,Y
    iny
    clc
    .a8
    adc #$B5
    sta a:$A1E0,X
    inx
    xba
    dec
    bne format_dialogue_quantity_digits_and_append_original_suffix_c019e7
    stz a:$A1E0,X
    txy
    .i16
    ldx #$0000
format_dialogue_quantity_digits_and_append_original_suffix_c019fe:
    lda f:$C77B6A,X
    sta a:$A1E0,Y
    php
    inx
    iny
    plp
    bne format_dialogue_quantity_digits_and_append_original_suffix_c019fe
    rts
