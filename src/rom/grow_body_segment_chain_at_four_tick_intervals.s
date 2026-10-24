; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16

consume_body_damage_or_parent_phase15_and_enter_hurt = $4DB9
grow_body_auxiliary_segment_and_publish_collision_geometry = $4DDE

.segment "CODE"
.org $4C0D
grow_body_segment_chain_at_four_tick_intervals:
    ldx $87
    lda a:$00B0,X
    tax
    inc a:$00BC,X
    ldx $87
    jsr consume_body_damage_or_parent_phase15_and_enter_hurt
    bcs grow_body_segment_chain_at_four_tick_intervals_c24c33
    lda a:$0096,X
    .a16
    cmp #$0004
    bne grow_body_segment_chain_at_four_tick_intervals_c24c33
    lda a:$00B2,X
    .a16
    cmp #$000C
    bcs grow_body_segment_chain_at_four_tick_intervals_c24c35
    stz a:$0096,X
    jsr grow_body_auxiliary_segment_and_publish_collision_geometry
grow_body_segment_chain_at_four_tick_intervals_c24c33:
    clc
    rts
grow_body_segment_chain_at_four_tick_intervals_c24c35:
    stz a:$00C2,X
    .a16
    lda #$0005
    sta a:$0094,X
    stz a:$0096,X
    clc
    rts
