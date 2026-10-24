; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $39A4
cap_combat_24bit_value_at_9999999:
    lda $D2
    .a8
    cmp #$98
    rep #$20
    bcc cap_combat_24bit_value_at_9999999_c039cc
    beq cap_combat_24bit_value_at_9999999_c039b0
    bcs cap_combat_24bit_value_at_9999999_c039bf
cap_combat_24bit_value_at_9999999_c039b0:
    .a16
    lda #$967F
    cmp $D0
    bcs cap_combat_24bit_value_at_9999999_c039cc
    .a16
    lda #$967F
    sta $D0
    sep #$20
    rts
cap_combat_24bit_value_at_9999999_c039bf:
    sep #$20
    .a8
    lda #$98
    sta $D2
    rep #$20
    .a16
    lda #$967F
    sta $D0
cap_combat_24bit_value_at_9999999_c039cc:
    sep #$20
    rts
