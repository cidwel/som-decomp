; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D90D
load_actor_fifteen_palette_colors_from_rom:
    lda $0C
    sta f:$004202
    .a8
    lda #$1E
    sta f:$004203
    .a8
    lda #$0F
    sta $0A
    stz $0B
    ldy a:$E0F8,X
    .a8
    lda #$C8
    sta $0F
    rep #$20
    .a16
    lda #$1000
    clc
    adc f:$004216
    sta $0D
load_actor_fifteen_palette_colors_from_rom_c1d932:
    lda [$0D]
    sta a:$0700,Y
    inc $0D
    inc $0D
    iny
    iny
    dec $0A
    bne load_actor_fifteen_palette_colors_from_rom_c1d932
    rts
