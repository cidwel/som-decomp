; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-motion.md.
.setcpu "65816"
.smart
.a8
.i16

accelerate_native54_auxiliary_lunge = $46B4
consume_native54_action_damage_and_initialize_auxiliary_recoil = $496C

.segment "CODE"
.org $4682
advance_native54_lunge_or_consume_hurt:
    ldx $87
    jsr consume_native54_action_damage_and_initialize_auxiliary_recoil
    bcs advance_native54_lunge_or_consume_hurt_c246b2
    lda a:$0096,X
    .a16
    cmp #$0006
    bne advance_native54_lunge_or_consume_hurt_c246af
    .a16
    lda #$000C
    sta a:$0094,X
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
    clc
    rts
advance_native54_lunge_or_consume_hurt_c246af:
    jsr accelerate_native54_auxiliary_lunge
advance_native54_lunge_or_consume_hurt_c246b2:
    clc
    rts
