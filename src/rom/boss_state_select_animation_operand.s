; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $37F8
boss_state_select_animation_operand:
    ldx $87
    lda [$30],Y
    iny
    iny
    jsr select_boss_animation_and_reset_frame_cursor
    rts
