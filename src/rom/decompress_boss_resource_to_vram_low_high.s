; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

decompress_block_long_call_wrapper = $C10014
expand_boss_resource_to_vram_low_high = $255E

.segment "CODE"
.org $2614
decompress_boss_resource_to_vram_low_high:
    asl
    asl
    asl
    tax
    lda f:$D0BC52,X
    sta $95
    sta $9D
    lda f:$D0BC54,X
    sta $97
    lda f:$D0BC56,X
    sta $99
    lda f:$D0BC58,X
    sta $9B
    .i16
    ldy #$6000
    ldx $97
    .a16
    lda #$007F
    sta $9E
    lda $9D
    jsl f:decompress_block_long_call_wrapper
    sep #$20
    .a8
    lda #$7F
    sta $7B
    rep #$20
    .a16
    lda #$6000
    sta $79
    lda $99
    sta f:$002116
    lda $9B
    sta $68
    stz $6A
    stz $6C
    jmp expand_boss_resource_to_vram_low_high
