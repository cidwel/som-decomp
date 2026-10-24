; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-motion.md.
.setcpu "65816"
.smart
.a8
.i16

consume_boss_byte34_bit0_or_return_negative_status = $0501
consume_boss_byte35_request = $051C

.segment "CODE"
.org $496C
consume_native54_action_damage_and_initialize_auxiliary_recoil:
    jsr consume_boss_byte35_request
    jsr consume_boss_byte34_bit0_or_return_negative_status
    bcc consume_native54_action_damage_and_initialize_auxiliary_recoil_c249ae
    ldx $87
    .a16
    lda #$000A
    sta a:$0094,X
    stz a:$0096,X
    stz a:$009E,X
    .a16
    lda #$EB00
    sta a:$003C,X
    .a16
    lda #$F200
    sta a:$0040,X
    .a16
    lda #$C100
    sta a:$00B4,X
    .a16
    lda #$DE00
    sta a:$00B6,X
    sep #$20
    .a8
    lda #$C1
    sta a:$F812,Y
    .a8
    lda #$DE
    sta a:$F80E,Y
    .a8
    lda #$80
    sta a:$F813,Y
    rep #$20
    sec
consume_native54_action_damage_and_initialize_auxiliary_recoil_c249ae:
    rts
