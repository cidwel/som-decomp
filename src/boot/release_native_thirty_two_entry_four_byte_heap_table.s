; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-release-small-tables.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb0d6 = $B0D6

.segment "CODE"
.org $CB71
release_native_thirty_two_entry_four_byte_heap_table:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldx a:$0302
    jsr routine_7eb0d6
    plb
    plp
    pld
    rts
