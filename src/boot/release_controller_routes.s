; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

current_task_id = $ACE9

.segment "CODE"
.org $A3A5
release_controller_routes:
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
    bcs release_controller_routes_a3d7
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
    stz a:$0001,X
    bra release_controller_routes_a3f6
release_controller_routes_a3d7:
    .a8
    lda #$05
    sta $01
    ldx a:$0092
release_controller_routes_a3de:
    lda $02
    cmp a:$0001,X
    bne release_controller_routes_a3e8
    stz a:$0001,X
release_controller_routes_a3e8:
    clc
    rep #$20
    txa
    .a16
    adc #$0010
    tax
    sep #$20
    dec $01
    bne release_controller_routes_a3de
release_controller_routes_a3f6:
    plb
    pla
    pla
    plp
    pld
    rts
