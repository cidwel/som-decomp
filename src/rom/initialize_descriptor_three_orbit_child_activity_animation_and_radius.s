; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-three-orbit.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $6437
initialize_descriptor_three_orbit_child_activity_animation_and_radius:
    ldx $87
    inc a:$0094,X
    .a16
    lda #$00C0
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0001
    sta a:$0000,X
    sta a:$00B4,X
