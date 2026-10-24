; Recovered Secret of Mana USA boot code. See docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

expand_title_text_row = $8820
update_title_colour_at_offset4 = $8B15
wait_for_title_row = $8B00

.segment "CODE"
.org $8BA5
animate_title_text_row:
    phd
    php
    rep #$30
    tsc
    sec
    sbc #$0006
    tcd
    tcs
    sep #$20
    stx $03
    lda a:$0063
    inc
    sta a:$0063
    cmp #$26
    bcc animate_title_text_row_8bd8
    cmp #$2B
    bcc animate_title_text_row_8bf4
    bne animate_title_text_row_8bd8
    jmp animate_title_text_row_8c42
animate_title_text_row_8bc8:
    sep #$20
    ldx a:$0052
    lda #$FF
    sta a:$0003,X
    ldx a:$0054
    stz a:$0003,X
animate_title_text_row_8bd8:
    rep #$20
    ldx #$0001
    jsr wait_for_title_row
    lda #$FFF8
    sta a:$005D
animate_title_text_row_8be6:
    ldx #$0008
    jsr wait_for_title_row
    inc a:$005D
    bne animate_title_text_row_8be6
    jmp animate_title_text_row_8c9d
animate_title_text_row_8bf4:
    rep #$20
    ldx a:$0046
    lda a:$0004,X
    cmp $7E5E1E
    beq animate_title_text_row_8bc8
    lda $03
    clc
    adc #$0080
    tay
    ldx #$01A0
    jsr expand_title_text_row
    ldx #$0001
    jsr wait_for_title_row
    lda #$FFF8
    sta a:$005D
    lda #$0020
    sta $01
    stz $05
animate_title_text_row_8c22:
    ldx #$0002
    jsr wait_for_title_row
    ldx $05
    jsr update_title_colour_at_offset4
    inx
    inx
    stx $05
    lda $01
    and #$0003
    dec
    bne animate_title_text_row_8c3c
    inc a:$005D
animate_title_text_row_8c3c:
    dec $01
    bne animate_title_text_row_8c22
    bra animate_title_text_row_8c9d
animate_title_text_row_8c42:
    .a8                       ; counter2B branch enters with byte accumulator
    ldx a:$0052
    stz a:$0003,X
    ldx a:$0054
    lda #$02
    sta a:$0003,X
    rep #$20
    ldx #$0001
    jsr wait_for_title_row
    lda #$FFF8
    sta a:$005D
    ldx #$0001
    jsr wait_for_title_row
    lda #$FFF8
    sta a:$005D
    lda #$0020
    sta $01
    asl
    sta $05
animate_title_text_row_8c72:
    ldx #$0002
    jsr wait_for_title_row
    ldx $05
    dex
    dex
    jsr update_title_colour_at_offset4
    stx $05
    lda $01
    and #$0003
    dec
    bne animate_title_text_row_8c8c
    inc a:$005D
animate_title_text_row_8c8c:
    dec $01
    bne animate_title_text_row_8c72
    lda $03
    clc
    adc #$0080
    tay
    ldx #$019E
    jsr expand_title_text_row
animate_title_text_row_8c9d:
    tsc
    clc
    adc #$0006
    tcs
    plp
    pld
    rts
