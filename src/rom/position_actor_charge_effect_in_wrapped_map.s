; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-special-helpers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C04D
position_actor_charge_effect_in_wrapped_map:
    rep #$20
    lda a:$E092,X
    .a16
    and #$3000
    ora a:$E086,X
    clc
    .a16
    adc #$0020
    sta a:$D00E,Y
    lda a:$E002,X
    sta a:$D002,Y
    lda a:$E074,X
    .a16
    and #$007F
    clc
    adc a:$E045,X
    sta a:$D006,Y
    .a16
    eor #$FFFF
    sec
    adc a:$E004,X
    bpl position_actor_charge_effect_in_wrapped_map_c2c07e
    clc
    adc $C2
position_actor_charge_effect_in_wrapped_map_c2c07e:
    sta a:$D004,Y
    sep #$20
    lda a:$D006,Y
    sta a:$D00B,Y
    lda a:$D000,Y
    xba
    lda a:$D001,Y
    .a8
    and #$03
    .a8
    cmp #$02
    bcc position_actor_charge_effect_in_wrapped_map_c2c0da
    xba
    .a8
    cmp #$01
    beq position_actor_charge_effect_in_wrapped_map_c2c0b1
    .a8
    cmp #$02
    beq position_actor_charge_effect_in_wrapped_map_c2c0a8
    .a8
    lda #$FC
    sta a:$D00D,Y
    .a8
    lda #$F8
    bra position_actor_charge_effect_in_wrapped_map_c2c0b8
position_actor_charge_effect_in_wrapped_map_c2c0a8:
    .a8
    lda #$F4
    sta a:$D00D,Y
    .a8
    lda #$F0
    bra position_actor_charge_effect_in_wrapped_map_c2c0b8
position_actor_charge_effect_in_wrapped_map_c2c0b1:
    .a8
    lda #$F8
    sta a:$D00D,Y
    .a8
    lda #$00
position_actor_charge_effect_in_wrapped_map_c2c0b8:
    pha
    .a8
    eor #$FF
    sec
    adc a:$D006,Y
    sta a:$D006,Y
    .a8
    lda #$F8
    sta a:$D00C,Y
    pla
    xba
    lsr
    .a8
    lda #$0A
    bcc position_actor_charge_effect_in_wrapped_map_c2c100
    lda a:$D00F,Y
    .a8
    eor #$40
    sta a:$D00F,Y
    .a8
    lda #$F6
    bra position_actor_charge_effect_in_wrapped_map_c2c100
position_actor_charge_effect_in_wrapped_map_c2c0da:
    lsr
    .a8
    lda #$F8
    sta a:$D00C,Y
    sta a:$D00D,Y
    .a8
    lda #$F6
    bcc position_actor_charge_effect_in_wrapped_map_c2c0f1
    lda a:$D00F,Y
    .a8
    eor #$C0
    sta a:$D00F,Y
    .a8
    lda #$0A
position_actor_charge_effect_in_wrapped_map_c2c0f1:
    xba
    .a8
    cmp #$01
    bne position_actor_charge_effect_in_wrapped_map_c2c0fe
    lda a:$D00F,Y
    .a8
    eor #$40
    sta a:$D00F,Y
position_actor_charge_effect_in_wrapped_map_c2c0fe:
    .a8
    lda #$00
position_actor_charge_effect_in_wrapped_map_c2c100:
    sep #$20
    pha
    xba
    .a8
    cmp #$80
    rep #$20
    .a16
    and #$00FF
    bcc position_actor_charge_effect_in_wrapped_map_c2c110
    .a16
    ora #$FF00
position_actor_charge_effect_in_wrapped_map_c2c110:
    clc
    adc a:$D004,Y
    bpl position_actor_charge_effect_in_wrapped_map_c2c11a
    adc $C2
    bra position_actor_charge_effect_in_wrapped_map_c2c120
position_actor_charge_effect_in_wrapped_map_c2c11a:
    cmp $C2
    bcc position_actor_charge_effect_in_wrapped_map_c2c120
    sbc $C2
position_actor_charge_effect_in_wrapped_map_c2c120:
    sta a:$D004,Y
    sep #$20
    pla
    .a8
    cmp #$80
    rep #$20
    .a16
    and #$00FF
    bcc position_actor_charge_effect_in_wrapped_map_c2c132
    .a16
    ora #$FF00
position_actor_charge_effect_in_wrapped_map_c2c132:
    clc
    adc a:$D002,Y
    bpl position_actor_charge_effect_in_wrapped_map_c2c13c
    adc $C0
    bra position_actor_charge_effect_in_wrapped_map_c2c142
position_actor_charge_effect_in_wrapped_map_c2c13c:
    cmp $C0
    bcc position_actor_charge_effect_in_wrapped_map_c2c142
    sbc $C0
position_actor_charge_effect_in_wrapped_map_c2c142:
    sta a:$D002,Y
    sep #$20
    rts
