; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-heap-teardown.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb0d6 = $B0D6

.segment "CODE"
.org $8F44
release_native_dma_descriptor_pointer_and_index_heap_tables:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldx a:$0064
    jsr routine_7eb0d6
    ldx a:$0066
    jsr routine_7eb0d6
    ldx a:$006A
    jsr routine_7eb0d6
    plb
    plp
    pld
    rts
