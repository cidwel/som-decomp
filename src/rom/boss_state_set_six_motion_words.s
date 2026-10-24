; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3802
boss_state_set_six_motion_words:
    ldx $87
    lda [$30],Y
    sta a:$003A,X
    iny
    iny
    lda [$30],Y
    sta a:$003C,X
    iny
    iny
    lda [$30],Y
    sta a:$003E,X
    iny
    iny
    lda [$30],Y
    sta a:$0040,X
    iny
    iny
    lda [$30],Y
    sta a:$00C4,X
    iny
    iny
    lda [$30],Y
    sta a:$00C6,X
    iny
    iny
    rts
