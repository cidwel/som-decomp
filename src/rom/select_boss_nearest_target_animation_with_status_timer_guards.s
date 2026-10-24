; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-target-animation.md.
.setcpu "65816"
.smart
.a8
.i16

derive_eight_way_direction_to_low_byte_target = $0941
select_boss_animation_and_reset_frame_cursor = $1394
select_nearest_active_living_party_actor = $3224

.segment "CODE"
.org $579E
select_boss_nearest_target_animation_with_status_timer_guards:
    jsr select_nearest_active_living_party_actor
    ldx $87
    sta a:$00A9,X
    lda a:$0190,X
    .a16
    bit #$8003
    bne select_boss_nearest_target_animation_with_status_timer_guards_c257c5
    lda a:$0060,X
    .a16
    bit #$00E0
    bne select_boss_nearest_target_animation_with_status_timer_guards_c257c5
    lda a:$00B8,X
    bne select_boss_nearest_target_animation_with_status_timer_guards_c257d1
    lda a:$002D,X
    lsr
    lsr
    cmp a:$002D,X
    bcc select_boss_nearest_target_animation_with_status_timer_guards_c257d6
select_boss_nearest_target_animation_with_status_timer_guards_c257c5:
    .a16
    lda #$0018
    cmp a:$009A,X
    beq select_boss_nearest_target_animation_with_status_timer_guards_c257d0
    jsr select_boss_animation_and_reset_frame_cursor
select_boss_nearest_target_animation_with_status_timer_guards_c257d0:
    rts
select_boss_nearest_target_animation_with_status_timer_guards_c257d1:
    dec a:$00B8,X
    bra select_boss_nearest_target_animation_with_status_timer_guards_c257c5
select_boss_nearest_target_animation_with_status_timer_guards_c257d6:
    lda a:$00A9,X
    jsr derive_eight_way_direction_to_low_byte_target
    ldx $87
    sta a:$00AB,X
    asl
    tax
    lda f:$C2580D,X
    ldx $87
    sta $00
    .a16
    and #$000F
    clc
    .a16
    adc #$0018
    cmp a:$009A,X
    beq select_boss_nearest_target_animation_with_status_timer_guards_c2580c
    jsr select_boss_animation_and_reset_frame_cursor
    lda a:$0098,X
    .a16
    and #$FF3F
    sta $02
    lda $01
    .a16
    and #$00C0
    ora $02
    sta a:$0098,X
select_boss_nearest_target_animation_with_status_timer_guards_c2580c:
    rts
