; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2459
boss_loader_call_native_callback:
    lda [$30]
    inc $30
    inc $30
    sta $33
    jmp ($0233)
