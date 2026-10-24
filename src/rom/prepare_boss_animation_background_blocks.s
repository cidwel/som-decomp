; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

decode_boss_animation_background_block_to_tilemap = $1CCF

.segment "CODE"
.org $1CA4
prepare_boss_animation_background_blocks:
    .i8
    ldx #$00
    .i8
    ldy #$00
prepare_boss_animation_background_blocks_c21ca8:
    lda [$79],Y
    sta $6C
    iny
    iny
    lda [$79],Y
    sta $6E
    iny
    iny
    lda $6F
    .a16
    and #$00FF
    sta a:$0FBA
    lda [$79],Y
    sta $76
    iny
    iny
    phx
    phy
    jsr decode_boss_animation_background_block_to_tilemap
    ply
    plx
    inx
    cpx $66
    bne prepare_boss_animation_background_blocks_c21ca8
    rts
