; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $225B
boss_loader_write_word:
    lda [$30]
    inc $30
    inc $30
    sta $33
    lda [$30]
    inc $30
    inc $30
    sta ($33)
    rts
