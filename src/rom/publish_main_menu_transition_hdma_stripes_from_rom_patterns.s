; Recovered Secret of Mana USA routine; behaviour documented in docs/map-main-frame-transition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A4EE
publish_main_menu_transition_hdma_stripes_from_rom_patterns:
    lda $52
    lsr
    bcc publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a500
    lda $3E
    bpl publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a4f9
    .a8
    eor #$FF
publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a4f9:
    .a8
    eor #$7F
    lsr
    lsr
    lsr
    sta $40
publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a500:
    lda $52
    .a8
    cmp #$03
    bcs publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a51e
    lda $3E
    lsr
    lsr
    lsr
    tax
    clc
    .a8
    adc #$1F
    .a8
    and #$1F
    tay
    lda $52
    .a8
    cmp #$02
    beq publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a531
    .i8
    cpx #$18
    bcs publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a531
    bcc publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a551
publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a51e:
    lda $3E
    lsr
    lsr
    lsr
    tay
    .a8
    eor #$1F
    tax
    lda $52
    .a8
    cmp #$04
    beq publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a531
    .i8
    cpx #$18
    bcc publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a54d
publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a531:
    rep #$20
    .a16
    lda #$0000
    tax
publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a537:
    sta f:$7FFF00,X
    inx
    inx
    .i8
    cpx #$24
    bcc publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a537
    rep #$20
    tya
    clc
    .a16
    adc #$5D00
    sta $74
    sep #$20
    rts
publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a54d:
    .a8
    lda #$04
    bra publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a553
publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a551:
    .a8
    lda #$00
publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a553:
    sta $04
    rep #$20
    tya
    clc
    .a16
    adc #$5D00
    sta $74
    stx $02
    rep #$10
    .i16
    ldy #$0000
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a56c:
    lda f:$C67400,X
    bpl publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a576
    .a8
    lda #$20
    bra publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a579
publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a576:
    clc
    .a8
    adc #$20
publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a579:
    sta a:$FF00,Y
    iny
    iny
    rep #$20
    txa
    clc
    .a16
    adc #$0018
    tax
    sep #$20
    .i16
    cpy #$0024
    bcc publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a56c
    sep #$10
    stz $00
    lda $02
    lsr
    ror $00
    tax
    .i8
    ldy #$01
publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a599:
    lda f:$C67520,X
    bit $00
    bpl publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a5a5
    lsr
    lsr
    lsr
    lsr
publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a5a5:
    .a8
    and #$0F
    eor $04
    sta $02
    .a8
    and #$03
    sta $03
    lda $02
    .a8
    and #$0C
    .a8
    ora #$02
    asl
    asl
    ora $03
    asl
    sec
    rol
    sta a:$FF00,Y
    txa
    clc
    .a8
    adc #$0C
    tax
    iny
    iny
    .i8
    cpy #$18
    bcc publish_main_menu_transition_hdma_stripes_from_rom_patterns_c0a599
    plb
    rts
