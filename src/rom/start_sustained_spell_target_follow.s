; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-hold-child.md.
.setcpu "65816"
.smart
.a8
.i16

start_follow_spell_target_animation = $9A67

.segment "CODE"
.org $9F0D
start_sustained_spell_target_follow:
    ldx $87
    inc a:$0094,X
    stz a:$0096,X
    stz a:$00BA,X
    stz a:$0022,X
    .a16
    lda #$993D
    sta a:$0090,X
    jsr start_follow_spell_target_animation
    clc
    rts
