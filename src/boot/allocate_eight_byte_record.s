; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

current_task_id = $ACE9

.segment "CODE"
.org $B1A9
allocate_eight_byte_record:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    php
    sei
    ldx a:$02C6
    lda a:$0000,X
    sta a:$02C6
    stz a:$0000,X
    stx $01
    jsr current_task_id
    ldx $01
    sta a:$0002,X
    stz a:$0003,X
    plp
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
