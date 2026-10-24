; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E022
load_actor_map_palette:
    sep #$20
    phy
    .i16
    cpx #$0600
    bcs load_actor_map_palette_c1e03a
    lda a:$E191,X
    .a8
    bit #$20
    beq load_actor_map_palette_c1e03a
    phx
    pla
    pla
    lsr
    clc
    .a8
    adc #$E7
    bra load_actor_map_palette_c1e040
load_actor_map_palette_c1e03a:
    lda a:$E180,X
    stz a:$E100,X
load_actor_map_palette_c1e040:
    sta f:$004202
    .a8
    lda #$1E
    sta f:$004203
    ldy a:$E0F8,X
    rep #$20
    .a16
    lda #$000F
    sta $00
    phx
    lda f:$004216
    tax
load_actor_map_palette_c1e05a:
    lda f:$C81000,X
    sta a:$0700,Y
    sta a:$DF00,Y
    iny
    iny
    inx
    inx
    dec $00
    bne load_actor_map_palette_c1e05a
    plx
    ply
    rts
