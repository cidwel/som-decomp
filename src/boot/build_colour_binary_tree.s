; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A090
build_colour_binary_tree:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$000B
    tcd
    tcs
    lda $0C,S
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    sta $03
    stx $01
    .i16
    ldy #$0000
    lda [$01],Y
    xba
    .a16
    and #$00FF
    inc
    sta $06
    dec
    sta $04
    iny
    iny
    ldx a:$008A
    txa
    clc
    .a16
    adc #$03FC
    sta $0A
build_colour_binary_tree_a0c8:
    stx $08
    lda [$01],Y
    iny
    iny
    sta $0C
    .a16
    and #$00FF
    inc
    asl
    asl
    clc
    adc $08
    cmp $0A
    bcc build_colour_binary_tree_a0e4
    sec
    sbc $0A
    lsr
    clc
    adc $0A
build_colour_binary_tree_a0e4:
    sta a:$0000,X
    lda $0D
    .a16
    and #$00FF
    inc
    asl
    asl
    clc
    adc $08
    cmp $0A
    bcc build_colour_binary_tree_a0fd
    sec
    sbc $0A
    lsr
    clc
    adc $0A
build_colour_binary_tree_a0fd:
    sta a:$0002,X
    clc
    txa
    .a16
    adc #$0004
    tax
    dec $04
    bne build_colour_binary_tree_a0c8
    lda $06
    sta $04
    ldx $0A
build_colour_binary_tree_a110:
    lda [$01],Y
    iny
    .a16
    and #$00FF
    sta a:$0000,X
    inx
    inx
    dec $04
    bne build_colour_binary_tree_a110
    lda [$01]
    plb
    sta $0C,S
    tsc
    clc
    .a16
    adc #$000B
    tcs
    pla
    plp
    pld
    rts
