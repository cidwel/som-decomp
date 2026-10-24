; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

enqueue_task_by_priority = $A8D6
select_next_task = $A948

.segment "CODE"
.org $A911
suspend_current_task:
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
    tsc
    sta a:$0006,X
    sep #$20
    ldy a:$000A,X
    beq suspend_current_task_a938
    .a8
    lda #$02
    sta a:$0002,X
    jsr enqueue_task_by_priority
    bra select_next_task
suspend_current_task_a938:
    .a8
    lda #$04
    sta a:$0002,X
    rep #$20
    lda a:$00A2
    sta a:$0000,X
    stx a:$00A2
