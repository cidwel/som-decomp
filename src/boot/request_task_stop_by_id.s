; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

find_task_by_id = $AD02
wake_waiting_task = $AC69

.segment "CODE"
.org $ACAC
request_task_stop_by_id:
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
    php
    sei
    jsr find_task_by_id
    .i16
    cpx #$0000
    beq request_task_stop_by_id_accb
    jsr wake_waiting_task
    .a8
    lda #$10
    sta a:$0002,X
request_task_stop_by_id_accb:
    plp
    plb
    plp
    pld
    rts
