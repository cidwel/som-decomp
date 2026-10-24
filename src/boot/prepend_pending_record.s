; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

find_task_by_id = $AD02
wake_waiting_task = $AC69

.segment "CODE"
.org $B2AB
prepend_pending_record:
    phd
    php
    rep #$30
    pha
    tsc
    tcd
    pla
    phx
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
    stz a:$0000,X
    stx $01
    jsr find_task_by_id
    txa
    beq prepend_pending_record_b2f0
    ldy a:$000A,X
    beq prepend_pending_record_b2d6
    .i16
    cpy #$FFFF
    bne prepend_pending_record_b2e3
prepend_pending_record_b2d6:
    lda $01
    sta a:$000A,X
    jsr wake_waiting_task
    .a16
    lda #$FFFF
    bra prepend_pending_record_b2f0
prepend_pending_record_b2e3:
    lda $01
    sta a:$000A,X
    tax
    tya
    sta a:$0000,X
    .a16
    lda #$FFFF
prepend_pending_record_b2f0:
    plp
    plb
    sep #$20
    sta $02,S
    pla
    pla
    plp
    pld
    rts
