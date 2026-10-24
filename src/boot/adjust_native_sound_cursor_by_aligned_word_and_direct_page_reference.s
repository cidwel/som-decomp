; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-sound-cursor-math.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $05DF
adjust_native_sound_cursor_by_aligned_word_and_direct_page_reference:
    php
    rep #$20
    pha
    lda $15
    .a16
    and #$FF80
    sec
    sbc $FA
    clc
    adc $15
    sta $15
    pla
    plp
    rts
