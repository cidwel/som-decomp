; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

find_task_by_id = $AD02
wake_waiting_task = $AC69

.segment "CODE"
.org $B258
append_pending_record:
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
    beq append_pending_record_b2a0
    ldy a:$000A,X
    beq append_pending_record_b283
    .i16
    cpy #$FFFF
    bne append_pending_record_b290
append_pending_record_b283:
    lda $01
    sta a:$000A,X
    jsr wake_waiting_task
    .a16
    lda #$FFFF
    bra append_pending_record_b2a0
append_pending_record_b290:
    ldx a:$0000,Y
    beq append_pending_record_b298
    txy
    bra append_pending_record_b290
append_pending_record_b298:
    lda $01
    sta a:$0000,Y
    .a16
    lda #$FFFF
append_pending_record_b2a0:
    plp
    plb
    sep #$20
    sta $02,S
    pla
    pla
    plp
    pld
    rts
