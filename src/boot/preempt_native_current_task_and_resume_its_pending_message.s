; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-active-irq.md.
.setcpu "65816"
.smart
.a8
.i16

suspend_current_task = $A911

.segment "CODE"
.org $AC44
preempt_native_current_task_and_resume_its_pending_message:
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
    php
    sei
    ldx a:$009E
    lda a:$000A,X
    bne preempt_native_current_task_and_resume_its_pending_message_ac61
    .a16
    lda #$FFFF
    sta a:$000A,X
preempt_native_current_task_and_resume_its_pending_message_ac61:
    jsr suspend_current_task
    plp
    plb
    plp
    pld
    rts
