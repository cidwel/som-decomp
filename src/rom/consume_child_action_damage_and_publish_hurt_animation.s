; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-left-child.md.
.setcpu "65816"
.smart
.a8
.i16

consume_boss_byte34_bit0_or_return_negative_status = $0501
consume_boss_byte35_request = $051C
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $7FE5
consume_child_action_damage_and_publish_hurt_animation:
    jsr consume_boss_byte35_request
    jsr consume_boss_byte34_bit0_or_return_negative_status
    bcc consume_child_action_damage_and_publish_hurt_animation_c28008
    ldx $87
    inc a:$0094,X
    .a16
    lda #$012E
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$0096,X
    sep #$20
    lda a:$0380
    .a8
    and #$7F
    sta a:$0380
    rep #$20
    sec
consume_child_action_damage_and_publish_hurt_animation_c28008:
    rts
