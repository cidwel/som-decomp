; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-children.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $8A19
snap_native59_projectile_to_target_on_velocity_sign_transition:
    ldx $87
    lda a:$00C6,X
    bpl snap_native59_projectile_to_target_on_velocity_sign_transition_c28a34
    lda a:$00B4,X
    bmi snap_native59_projectile_to_target_on_velocity_sign_transition_c28a34
    ldy a:$00B2,X
    lda a:$0002,Y
    sta a:$002B,X
    lda a:$0004,Y
    sta a:$0032,X
snap_native59_projectile_to_target_on_velocity_sign_transition_c28a34:
    lda a:$00C6,X
    sta a:$00B4,X
    lda a:$0066,X
    bne snap_native59_projectile_to_target_on_velocity_sign_transition_c28a51
    inc a:$0094,X
    .a16
    lda #$010E
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$0066,X
    stz a:$0090,X
    stz a:$00B4,X
snap_native59_projectile_to_target_on_velocity_sign_transition_c28a51:
    clc
    rts
