; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $34B0
test_boss_negative_status_word:
    lda a:$0190,X
    bmi test_boss_negative_status_word_c234b7
    clc
    rts
test_boss_negative_status_word_c234b7:
    sec
    rts
