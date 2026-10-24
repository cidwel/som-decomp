; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

current_task_id = $ACE9

.segment "CODE"
.org $A351
claim_controller_routes:
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
    pha
    jsr current_task_id
    sta $02
    pla
    .a8
    cmp #$05
    bcs claim_controller_routes_a385
    rep #$20
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    clc
    adc a:$0092
    tax
    sep #$20
    lda $02
    sta a:$0001,X
    bra claim_controller_routes_a39f
claim_controller_routes_a385:
    .a8
    lda #$05
    sta $01
    ldx a:$0092
claim_controller_routes_a38c:
    lda $02
    sta a:$0001,X
    clc
    rep #$20
    txa
    .a16
    adc #$0010
    tax
    sep #$20
    dec $01
    bne claim_controller_routes_a38c
claim_controller_routes_a39f:
    plb
    pla
    pla
    plp
    pld
    rts
