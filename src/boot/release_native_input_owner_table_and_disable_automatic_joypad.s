; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-heap-teardown.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb0d6 = $B0D6

.segment "CODE"
.org $A314
release_native_input_owner_table_and_disable_automatic_joypad:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldx a:$0092
    jsr routine_7eb0d6
    lda a:$0090
    .a8
    and #$FE
    sta a:$0090
    sta f:$004200
    plb
    plp
    pld
    rts
