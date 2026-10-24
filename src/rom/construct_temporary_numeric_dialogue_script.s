; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-number-window.md.
.setcpu "65816"
.smart
.a8
.i16

convert_24_bit_dialogue_quantity_to_seven_digit_fields = $C754DB
format_dialogue_quantity_digits_and_append_original_suffix = $19C7

.segment "CODE"
.org $1999
construct_temporary_numeric_dialogue_script:
    .i16
    ldy #$0000
    .a8
    lda #$04
    .i16
    ldx #$0000
construct_temporary_numeric_dialogue_script_c019a1:
    xba
    lda a:$CC6A,X
    sta a:$A136,Y
    inx
    iny
    xba
    dec
    bne construct_temporary_numeric_dialogue_script_c019a1
    jsl f:convert_24_bit_dialogue_quantity_to_seven_digit_fields
    jsr format_dialogue_quantity_digits_and_append_original_suffix
    rep #$20
    .a16
    lda #$A1E0
    sta f:$001D01
    sep #$20
    .a8
    lda #$7E
    sta f:$001D03
    rts
