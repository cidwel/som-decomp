; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-motion.md.
.setcpu "65816"
.smart
.a8
.i16

accelerate_native54_auxiliary_recoil = $492C

.segment "CODE"
.org $48F1
complete_auxiliary_recoil_or_accelerate:
    ldx $87
    lda a:$F811,Y
    .a16
    cmp #$C200
    bcc complete_auxiliary_recoil_or_accelerate_c24927
    .a16
    lda #$0007
    sta a:$0094,X
    sta a:$0076,X
    stz a:$0096,X
    sep #$20
    .a8
    lda #$C1
    sta a:$F812,Y
    .a8
    lda #$DE
    sta a:$F80E,Y
    .a8
    lda #$40
    sta a:$F813,Y
    rep #$20
    lda a:$0190,X
    bpl complete_auxiliary_recoil_or_accelerate_c24925
    .a16
    lda #$000E
    sta a:$0094,X
complete_auxiliary_recoil_or_accelerate_c24925:
    clc
    rts
complete_auxiliary_recoil_or_accelerate_c24927:
    jsr accelerate_native54_auxiliary_recoil
    clc
    rts
