; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

create_task_resources = $AAFF
enqueue_task_by_priority = $A8D6

.segment "CODE"
.org $AB88
create_and_enqueue_task:
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
    rep #$20
    php
    sei
    jsr create_task_resources
    txa
    beq create_and_enqueue_task_aba8
    jsr enqueue_task_by_priority
    lda a:$0004,X
    inc a:$009A
create_and_enqueue_task_aba8:
    plp
    plb
    plp
    pld
    rts
