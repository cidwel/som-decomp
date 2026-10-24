; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-parent-actions.md.
.setcpu "65816"
.smart
.a8
.i16

choose_native58_farthest_close_or_nearest_projectile_attack = $7D5B
draw_boss_frame_random_number = $300B
prepare_native58_revive_cast_and_execute_success = $7DB5
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $7D0B
native58_variant_one_cast_or_projectile:
    ldx $87
    lda a:$E990
    and a:$EB90
    bmi native58_variant_one_cast_or_projectile_c27d4a
    lda a:$E990
    bpl native58_variant_one_cast_or_projectile_c27d2c
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    bne native58_variant_one_cast_or_projectile_c27d41
    .a16
    lda #$0005
    sta $95
    jsr prepare_native58_revive_cast_and_execute_success
    bra native58_variant_one_cast_or_projectile_c27d41
native58_variant_one_cast_or_projectile_c27d2c:
    lda a:$EB90
    bpl native58_variant_one_cast_or_projectile_c27d41
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    bne native58_variant_one_cast_or_projectile_c27d41
    .a16
    lda #$0006
    sta $95
    jsr prepare_native58_revive_cast_and_execute_success
native58_variant_one_cast_or_projectile_c27d41:
    ldx $87
    .a16
    lda #$012F
    jsr select_boss_animation_and_reset_frame_cursor
    rts
native58_variant_one_cast_or_projectile_c27d4a:
    ldx $87
    lda $C7
    sta a:$00B6,X
    .a16
    lda #$012F
    jsr select_boss_animation_and_reset_frame_cursor
    jsr choose_native58_farthest_close_or_nearest_projectile_attack
    rts
