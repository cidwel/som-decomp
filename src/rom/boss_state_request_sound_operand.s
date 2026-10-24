; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

request_boss_sound_with_parameter_word = $30E3

.segment "CODE"
.org $394F
boss_state_request_sound_operand:
    lda [$30],Y
    iny
    iny
    .i16
    ldx #$000F
    jsr request_boss_sound_with_parameter_word
    ldx $87
    rts
