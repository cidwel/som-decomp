; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-setup.md.
.setcpu "65816"
.smart
.a8
.i16

derive_eight_way_direction_to_low_byte_target = $0941
select_boss_animation_and_reset_frame_cursor = $1394
select_nearest_active_living_party_actor = $3224

.segment "CODE"
.org $454E
choose_native54_spawn_or_attack_state_after_twelve_ticks:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$000C
    bcc choose_native54_spawn_or_attack_state_after_twelve_ticks_c24594
    lda a:$00B2,X
    beq choose_native54_spawn_or_attack_state_after_twelve_ticks_c2458b
    jsr select_nearest_active_living_party_actor
    ldx $87
    sta a:$00A9,X
    jsr derive_eight_way_direction_to_low_byte_target
    asl
    tax
    lda f:$DCE5FB,X
    sta $95
    ldx $87
    lda a:$0098,X
    .a16
    and #$FF3F
    ora $95
    sta a:$0098,X
    .a16
    lda #$0004
    sta a:$0094,X
    .a16
    lda #$0072
    jsr select_boss_animation_and_reset_frame_cursor
    bra choose_native54_spawn_or_attack_state_after_twelve_ticks_c24594
choose_native54_spawn_or_attack_state_after_twelve_ticks_c2458b:
    .a16
    lda #$0003
    sta a:$0094,X
    stz a:$00BA,X
choose_native54_spawn_or_attack_state_after_twelve_ticks_c24594:
    clc
    rts
