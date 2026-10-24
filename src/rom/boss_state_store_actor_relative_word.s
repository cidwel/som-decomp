; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3922
boss_state_store_actor_relative_word:
    ldx $87
    lda [$30],Y
    clc
    adc $87
    sta $33
    iny
    iny
    lda [$30],Y
    iny
    iny
    sta ($33)
    rts
