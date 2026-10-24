; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-heap-teardown.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb0d6 = $B0D6

.segment "CODE"
.org $BB96
release_native_copy_request_heap_table:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldx a:$02D2
    jsr routine_7eb0d6
    plb
    plp
    pld
    rts
