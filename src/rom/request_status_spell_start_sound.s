; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16

request_boss_sound_with_parameter_word = $30E3

.segment "CODE"
.org $9A2B
request_status_spell_start_sound:
    lda a:$00B4,X
    asl
    tax
    lda f:$DCE77B,X
    beq request_status_spell_start_sound_c29a3c
    .i16
    ldx #$000F
    jsr request_boss_sound_with_parameter_word
request_status_spell_start_sound_c29a3c:
    ldx $87
    rts
