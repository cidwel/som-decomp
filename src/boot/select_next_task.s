; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

create_task_resources = $AAFF
dispatch_task = $A961

.segment "CODE"
.org $A948
select_next_task:
    rep #$20
    ldx a:$00A0
    bne dispatch_task
    sep #$20
    .i16
    ldx #$600A
    .a8
    lda #$7E
    jsr create_task_resources
    lda a:$0004,X
    sta a:$00BE
    rep #$20
