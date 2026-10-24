; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

request_boss_sound_with_parameter_word = $30E3

.segment "CODE"
.org $062D
exclude_and_mark_party_contact_inside_second_boss_box:
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    sep #$20
    ldx $8B
    lda f:$C205F0,X
    and a:$005A,Y
    rep #$20
    bne exclude_and_mark_party_contact_inside_second_boss_box_c2068c
    lda $52
    ora $54
    beq exclude_and_mark_party_contact_inside_second_boss_box_c2068e
    lda $4E
    sec
    sbc $56
    bpl exclude_and_mark_party_contact_inside_second_boss_box_c20654
    .a16
    eor #$FFFF
    inc
exclude_and_mark_party_contact_inside_second_boss_box_c20654:
    sta $5E
    lda $52
    clc
    adc $5A
    cmp $5E
    bcc exclude_and_mark_party_contact_inside_second_boss_box_c2068e
    lda $50
    sec
    sbc $58
    bpl exclude_and_mark_party_contact_inside_second_boss_box_c2066a
    .a16
    eor #$FFFF
    inc
exclude_and_mark_party_contact_inside_second_boss_box_c2066a:
    sta $5E
    lda $54
    clc
    adc $5C
    cmp $5E
    bcc exclude_and_mark_party_contact_inside_second_boss_box_c2068e
    sep #$20
    lda f:$C205F0,X
    ora a:$005A,Y
    sta a:$005A,Y
    rep #$20
    .a16
    lda #$0000
    .i16
    ldx #$0000
    jsr request_boss_sound_with_parameter_word
exclude_and_mark_party_contact_inside_second_boss_box_c2068c:
    sec
    rts
exclude_and_mark_party_contact_inside_second_boss_box_c2068e:
    clc
    rts
