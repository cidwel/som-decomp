; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C18B
apply_ppu_queue_shadow:
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
    lda a:$02E2
    sta $01
    .i16
    ldy #$02DA
apply_ppu_queue_shadow_c1a3:
    lda a:$0001,Y
    .a16
    and #$00FF
    beq apply_ppu_queue_shadow_c1e7
    clc
    adc a:$02D6
    tax
    pha
    lda a:$0000,X
    .a16
    and #$00FF
    tay
    lda a:$0002,X
    sep #$20
    sta ($01),Y
    tyx
    lda f:$7E603E,X
    beq apply_ppu_queue_shadow_c1e2
    .a8
    cmp #$01
    bne apply_ppu_queue_shadow_c1d0
    iny
    xba
    sta ($01),Y
    bra apply_ppu_queue_shadow_c1e2
apply_ppu_queue_shadow_c1d0:
    lda ($01),Y
    rep #$20
    pha
    lda f:$7E603E,X
    .a16
    and #$00FF
    tay
    pla
    sta ($01),Y
    sep #$20
apply_ppu_queue_shadow_c1e2:
    ply
    rep #$20
    bra apply_ppu_queue_shadow_c1a3
apply_ppu_queue_shadow_c1e7:
    .i16
    ldy #$02DE
apply_ppu_queue_shadow_c1ea:
    lda a:$0001,Y
    .a16
    and #$00FF
    beq apply_ppu_queue_shadow_c23c
    clc
    adc a:$02D6
    tax
    pha
    .i16
    cpy #$02DE
    beq apply_ppu_queue_shadow_c206
    lda a:$02D8
    sta a:$0000,Y
    sty a:$02D8
apply_ppu_queue_shadow_c206:
    lda a:$0000,X
    .a16
    and #$00FF
    tay
    lda a:$0002,X
    sep #$20
    sta ($01),Y
    tyx
    lda f:$7E603E,X
    beq apply_ppu_queue_shadow_c237
    .a8
    cmp #$01
    bne apply_ppu_queue_shadow_c225
    iny
    xba
    sta ($01),Y
    bra apply_ppu_queue_shadow_c237
apply_ppu_queue_shadow_c225:
    lda ($01),Y
    rep #$20
    pha
    lda f:$7E603E,X
    .a16
    and #$00FF
    tay
    pla
    sta ($01),Y
    sep #$20
apply_ppu_queue_shadow_c237:
    ply
    rep #$20
    bra apply_ppu_queue_shadow_c1ea
apply_ppu_queue_shadow_c23c:
    .i16
    cpy #$02DE
    beq apply_ppu_queue_shadow_c24a
    lda a:$02D8
    sta a:$0000,Y
    sty a:$02D8
apply_ppu_queue_shadow_c24a:
    stz a:$02DE
    .a16
    lda #$02DE
    sta a:$02E0
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
