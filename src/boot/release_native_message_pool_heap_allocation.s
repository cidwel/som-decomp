; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-task-access-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb0d6 = $B0D6

.segment "CODE"
.org $B15A
release_native_message_pool_heap_allocation:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldx a:$02C4
    jsr routine_7eb0d6
    plb
    plp
    pld
    rts
