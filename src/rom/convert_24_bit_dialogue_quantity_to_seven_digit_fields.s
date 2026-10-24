; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-number-window.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $54DB
convert_24_bit_dialogue_quantity_to_seven_digit_fields:
    .i16
    ldy #$0000
    .a8
    lda #$04
convert_24_bit_dialogue_quantity_to_seven_digit_fields_c754e0:
    xba
    .a8
    lda #$00
    sta a:$A146,Y
    iny
    xba
    dec
    bne convert_24_bit_dialogue_quantity_to_seven_digit_fields_c754e0
    .i16
    ldy #$0018
    sta a:$A175
    sed
convert_24_bit_dialogue_quantity_to_seven_digit_fields_c754f2:
    .a8
    lda #$04
    .i16
    ldx #$0000
    clc
convert_24_bit_dialogue_quantity_to_seven_digit_fields_c754f8:
    xba
    lda a:$A146,X
    adc a:$A146,X
    sta a:$A146,X
    inx
    xba
    dec
    bne convert_24_bit_dialogue_quantity_to_seven_digit_fields_c754f8
    asl a:$A136
    rol a:$A137
    rol a:$A138
    .a8
    lda #$00
    adc a:$A146
    sta a:$A146
    dey
    bne convert_24_bit_dialogue_quantity_to_seven_digit_fields_c754f2
    cld
    .i16
    ldx #$0001
    .i16
    ldy #$0003
    lda a:$A149
    sta a:$A136
convert_24_bit_dialogue_quantity_to_seven_digit_fields_c75528:
    lda a:$A145,Y
    pha
    lsr
    lsr
    lsr
    lsr
    sta a:$A136,X
    inx
    pla
    .a8
    and #$0F
    sta a:$A136,X
    inx
    dey
    bne convert_24_bit_dialogue_quantity_to_seven_digit_fields_c75528
    rtl
