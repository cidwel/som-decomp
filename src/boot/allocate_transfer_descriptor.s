; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_transfer_pass = $9164
receive_with_supplied_delay = $ABE7
reserve_highest_free_hdma_channel = $8F8F

.segment "CODE"
.org $8FC7
allocate_transfer_descriptor:
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
    pha
    sep #$20
allocate_transfer_descriptor_8fde:
    ldx a:$0064
    .i16
    ldy #$0020
allocate_transfer_descriptor_8fe4:
    lda a:$000F,X
    beq allocate_transfer_descriptor_900d
    clc
    rep #$20
    txa
    .a16
    adc #$0010
    tax
    sep #$20
    dey
    bne allocate_transfer_descriptor_8fe4
    lda $02,S
    inc
    beq allocate_transfer_descriptor_9006
    jsr prepare_transfer_pass
    .i16
    ldx #$0001
    jsr receive_with_supplied_delay
    bra allocate_transfer_descriptor_8fde
allocate_transfer_descriptor_9006:
    .i16
    ldx #$0000
    pla
    pla
    bra allocate_transfer_descriptor_9060
allocate_transfer_descriptor_900d:
    rep #$20
    pla
    sep #$20
    sta a:$000F,X
    xba
    sta a:$000D,X
    phx
    .a8
    cmp #$00
    beq allocate_transfer_descriptor_9034
    .a8
    cmp #$20
    beq allocate_transfer_descriptor_9024
    bcs allocate_transfer_descriptor_9034
allocate_transfer_descriptor_9024:
    dec
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:$0068
    tax
    sep #$20
    inc a:$0000,X
allocate_transfer_descriptor_9034:
    plx
    .a8
    lda #$00
    xba
    lda a:$000F,X
    .a8
    and #$07
    dec
    txy
    tax
    lda f:$7E5EB4,X
    sta a:$0000,Y
    lda f:$7E5EB9,X
    sta a:$0009,Y
    lda f:$7E5EBE,X
    sta a:$0001,Y
    tyx
    lda a:$000F,X
    .a8
    cmp #$05
    bne allocate_transfer_descriptor_9060
    jsr reserve_highest_free_hdma_channel
allocate_transfer_descriptor_9060:
    plb
    pla
    pla
    plp
    pld
    rts
