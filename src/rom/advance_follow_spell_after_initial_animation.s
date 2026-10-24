; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-follow-child.md.
.setcpu "65816"
.smart
.a8
.i16

start_follow_spell_target_animation = $9A67

.segment "CODE"
.org $9A3F
advance_follow_spell_after_initial_animation:
    ldx $87
    lda a:$009E,X
    bne advance_follow_spell_after_initial_animation_c29a52
    inc a:$0094,X
    .a16
    lda #$993D
    sta a:$0090,X
    jsr start_follow_spell_target_animation
advance_follow_spell_after_initial_animation_c29a52:
    clc
    rts
