; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-main-stopped-callback.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eacac = $ACAC
routine_7ed3aa = $D3AA

.segment "CODE"
.org $D3EA
stop_native_title_main_resources_and_peer_tasks:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldx a:$030E
    beq stop_native_title_main_resources_and_peer_tasks_d3fd
    jsr routine_7ed3aa
stop_native_title_main_resources_and_peer_tasks_d3fd:
    lda a:$0312
    jsr routine_7eacac
    lda a:$0311
    jsr routine_7eacac
    plb
    plp
    pld
    rtl
