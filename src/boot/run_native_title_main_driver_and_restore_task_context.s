; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-title-driver.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7e87df = $87DF
routine_7ea4c2 = $A4C2
routine_7ea4d7 = $A4D7
routine_7eb42b = $B42B
routine_7ecdbf = $CDBF
routine_7ece62 = $CE62
routine_7ed473 = $D473

.segment "CODE"
.org $CD50
run_native_title_main_driver_and_restore_task_context:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    .a16
    lda #$0F01
    jsr routine_7eb42b
    .a16
    lda #$0000
    .i16
    ldx #$0100
    .i16
    ldy #$00E0
    jsr routine_7e87df
    jsr routine_7ecdbf
    jsr routine_7ece62
    jsr routine_7ea4c2
    jsr routine_7ed473
    jsr routine_7ea4d7
    plb
    plp
    pld
    rtl
