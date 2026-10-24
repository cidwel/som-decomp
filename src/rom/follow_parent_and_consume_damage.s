; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-left-child.md.
.setcpu "65816"
.smart
.a8
.i16

consume_child_action_damage_and_publish_hurt_animation = $7FE5

.segment "CODE"
.org $7F54
follow_parent_and_consume_damage:
    ldx $87
    ldy a:$00B0,X
    lda a:$0094,Y
    .a16
    cmp #$0006
    beq follow_parent_and_consume_damage_c27f88
    jsr consume_child_action_damage_and_publish_hurt_animation
    bcs follow_parent_and_consume_damage_c27f86
    lda a:$002B,Y
    sec
    .a16
    sbc #$0040
    sta a:$002B,X
    lda a:$0032,Y
    clc
    .a16
    adc #$0010
    sta a:$0032,X
    lda a:$00A9,Y
    sta a:$00A9,X
    lda a:$00AB,Y
    sta a:$00AB,X
follow_parent_and_consume_damage_c27f86:
    clc
    rts
follow_parent_and_consume_damage_c27f88:
    sec
    rts
