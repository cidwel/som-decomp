; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-pull-child.md.
.setcpu "65816"
.smart
.a8
.i16

activate_spell_child_and_clear_fractional_height = $98DA
request_status_spell_start_sound = $9A2B
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $9D93
initialize_pull_spell_and_capture_parent_facing:
    ldx $87
    ldy a:$00B0,X
    lda a:$00B8,Y
    sta a:$00BE,X
    lda a:$00B4,X
    asl
    tax
    lda f:$DCE6FF,X
    ldx $87
    jsr select_boss_animation_and_reset_frame_cursor
    jsr request_status_spell_start_sound
    inc a:$0094,X
    .a16
    lda #$07FF
    sta a:$0022,X
    lda a:$0098,X
    .a16
    and #$7FFF
    sta a:$0098,X
    jsr activate_spell_child_and_clear_fractional_height
    clc
    rts
