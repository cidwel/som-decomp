; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-follow-child.md.
.setcpu "65816"
.smart
.a8
.i16

request_boss_sound_with_parameter_word = $30E3

.segment "CODE"
.org $9AD1
request_follow_spell_target_sound:
    lda a:$00B4,X
    asl
    tax
    lda f:$DCE7B9,X
    beq request_follow_spell_target_sound_c29ae2
    .i16
    ldx #$000F
    jsr request_boss_sound_with_parameter_word
request_follow_spell_target_sound_c29ae2:
    ldx $87
    rts
