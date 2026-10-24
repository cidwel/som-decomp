; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


message_queue_buffer = $FE00

.segment "CODE"
.org $5C38
append_message_byte_decimal:
    sta $AC
    stz $A4
    stz $A6
append_message_byte_decimal_c05c3e:
    sec
    .a8
    sbc #$0A
    bmi append_message_byte_decimal_c05c47
    inc $A4
    bra append_message_byte_decimal_c05c3e
append_message_byte_decimal_c05c47:
    clc
    .a8
    adc #$0A
append_message_byte_decimal_c05c4a:
    dec
    bmi append_message_byte_decimal_c05c51
    inc $A6
    bra append_message_byte_decimal_c05c4a
append_message_byte_decimal_c05c51:
    lda $A4
    clc
    .a8
    adc #$B5
    .a8
    cmp #$B5
    beq append_message_byte_decimal_c05c62
    sta $A4
    lda $A4
    sta a:message_queue_buffer,Y
    iny
append_message_byte_decimal_c05c62:
    lda $A6
    clc
    .a8
    adc #$B5
    sta a:message_queue_buffer,Y
    iny
    rts
