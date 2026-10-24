; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-registered-buffer-query.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7ec710 = $C710

.segment "CODE"
.org $C858
read_native_registered_buffer_pointer_from_caller_record:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    jsr routine_7ec710
    ldy a:$0002,X
    tyx
    plb
    plp
    pld
    rts
