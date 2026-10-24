; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

current_task_id = $ACE9
select_graphics_registration = $805F

.segment "CODE"
.org $81D6
allocate_graphics_workspace_block:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0007
    tcd
    tcs
    lda $08,S
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    jsr select_graphics_registration
    sta $08
    tax
    lda a:$0004,X
    sta $04
    lda a:$0006,X
    sta $02
    lda a:$0002,X
    .a16
    and #$00FF
    tay
    lda a:$0001,X
    .a16
    and #$00FF
    xba
allocate_graphics_workspace_block_820d:
    lsr
    dey
    bne allocate_graphics_workspace_block_820d
    clc
    adc $02
    sta $06
    ldx $04
    sep #$20
allocate_graphics_workspace_block_821a:
    lda a:$0000,X
    beq allocate_graphics_workspace_block_822f
    inx
    cpx $06
    bcc allocate_graphics_workspace_block_8226
    ldx $02
allocate_graphics_workspace_block_8226:
    cpx $04
    bne allocate_graphics_workspace_block_821a
    .i16
    ldx #$FFFF
    bra allocate_graphics_workspace_block_826b
allocate_graphics_workspace_block_822f:
    stx $04
    jsr current_task_id
    ldy $04
    sta a:$0000,Y
    rep #$20
    tya
    ldx $08
    sta a:$0004,X
    sec
    sbc $02
    asl
    asl
    asl
    asl
    asl
    sta $04
    lda a:$0002,X
    .a16
    cmp #$0003
    beq allocate_graphics_workspace_block_825c
    lsr $04
    .a16
    cmp #$0002
    beq allocate_graphics_workspace_block_825c
    lsr $04
allocate_graphics_workspace_block_825c:
    lda a:$0000,X
    .a16
    and #$00FF
    asl
    asl
    xba
    clc
    adc $04
    tax
    sep #$20
allocate_graphics_workspace_block_826b:
    plb
    rep #$20
    tsc
    clc
    .a16
    adc #$0009
    tcs
    plp
    pld
    rts
