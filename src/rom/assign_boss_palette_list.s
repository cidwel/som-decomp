; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

load_boss_palette_through_wram_dma = $26AC

.segment "CODE"
.org $2309
assign_boss_palette_list:
    sec
    .a16
    sbc #$0054
    asl
    tax
    .a16
    lda #$C100
    sta $34
    lda f:$CABE00,X
    sta $33
    ldx $87
    lda a:$0FA4
    sta a:$00A3,X
    sta $24
assign_boss_palette_list_c22324:
    lda [$33]
    inc $33
    .a16
    and #$00FF
    .a16
    cmp #$00FF
    beq assign_boss_palette_list_c2234a
    sep #$20
    clc
    adc $24
    sta a:$0018,X
    rep #$20
    inx
    phx
    tax
    lda [$33]
    inc $33
    .a16
    and #$00FF
    jsr load_boss_palette_through_wram_dma
    plx
    bra assign_boss_palette_list_c22324
assign_boss_palette_list_c2234a:
    rts
