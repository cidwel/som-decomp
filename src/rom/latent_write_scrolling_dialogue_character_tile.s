; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-latent-scroll-flow.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FE7A
latent_write_scrolling_dialogue_character_tile:
    ldx a:$A19B
    lda a:$9000,Y
    iny
    .a8
    cmp #$20
    beq latent_write_scrolling_dialogue_character_tile_c9fe8e
    .a8
    cmp #$2E
    beq latent_write_scrolling_dialogue_character_tile_c9fe92
    sec
    .a8
    sbc #$40
    bra latent_write_scrolling_dialogue_character_tile_c9fe94
latent_write_scrolling_dialogue_character_tile_c9fe8e:
    .a8
    lda #$00
    bra latent_write_scrolling_dialogue_character_tile_c9fe94
latent_write_scrolling_dialogue_character_tile_c9fe92:
    .a8
    lda #$1B
latent_write_scrolling_dialogue_character_tile_c9fe94:
    rep #$20
    .a16
    and #$00FF
    asl
    clc
    .a16
    adc #$2100
    sta a:$9400,X
    inx
    inx
    txa
    sta a:$A19B
    sep #$20
    clc
    rts
