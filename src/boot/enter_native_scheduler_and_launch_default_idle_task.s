; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-scheduler-entry.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00a961 = $A961
routine_7ea1e2 = $A1E2
routine_7eaaff = $AAFF

.segment "CODE"
.org $A88F
enter_native_scheduler_and_launch_default_idle_task:
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
    jsr routine_7ea1e2
    tsc
    sta a:$0098
    sep #$20
    .i16
    ldx #$600A
    .a8
    lda #$7E
    jsr routine_7eaaff
    lda a:$0004,X
    sta a:$00BE
    rep #$20
    lda a:$00A0
    sta a:$0000,X
    jmp routine_00a961
