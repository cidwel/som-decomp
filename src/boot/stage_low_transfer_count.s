; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9193
stage_low_transfer_count:
    phd
    php
    rep #$30
    sep #$20
    lda a:$006C
    sta a:$006E
    plp
    pld
    rts
