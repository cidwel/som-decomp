; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

current_task_id = $ACE9

.segment "CODE"
.org $A3FC
set_controller_pressed_masks:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0002
    tcd
    tcs
    lda $03,S
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    stx $01
    .a16
    and #$00FF
    .a16
    cmp #$0005
    bcs set_controller_pressed_masks_a42f
    asl
    asl
    asl
    asl
    clc
    adc a:$0092
    tax
    lda $01
    sta a:$0008,X
    bra set_controller_pressed_masks_a455
set_controller_pressed_masks_a42f:
    jsr current_task_id
    .a16
    and #$00FF
    sta $03
    .i16
    ldy #$0005
    ldx a:$0092
set_controller_pressed_masks_a43d:
    lda a:$0001,X
    .a16
    and #$00FF
    cmp $03
    bne set_controller_pressed_masks_a44c
    lda $01
    sta a:$0008,X
set_controller_pressed_masks_a44c:
    clc
    txa
    .a16
    adc #$0010
    tax
    dey
    bne set_controller_pressed_masks_a43d
set_controller_pressed_masks_a455:
    plb
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
