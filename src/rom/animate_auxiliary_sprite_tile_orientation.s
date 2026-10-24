; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C485
animate_auxiliary_sprite_tile_orientation:
    lda a:$D00F,Y
    xba
    lda a:$D00E,Y
    .a8
    and #$FC
    pha
    lda $F4
    lsr
    lsr
    .a8
    and #$03
    beq animate_auxiliary_sprite_tile_orientation_c2c4c1
    dec
    beq animate_auxiliary_sprite_tile_orientation_c2c4b0
    dec
    beq animate_auxiliary_sprite_tile_orientation_c2c4a5
    pla
    rep #$20
    .a16
    and #$3FFC
    bra animate_auxiliary_sprite_tile_orientation_c2c4b9
animate_auxiliary_sprite_tile_orientation_c2c4a5:
    pla
    rep #$20
    .a16
    and #$3FFC
    .a16
    ora #$4000
    bra animate_auxiliary_sprite_tile_orientation_c2c4bd
animate_auxiliary_sprite_tile_orientation_c2c4b0:
    pla
    rep #$20
    .a16
    and #$3FFC
    .a16
    ora #$8000
animate_auxiliary_sprite_tile_orientation_c2c4b9:
    clc
    .a16
    adc #$0002
animate_auxiliary_sprite_tile_orientation_c2c4bd:
    sta a:$D00E,Y
    rts
animate_auxiliary_sprite_tile_orientation_c2c4c1:
    pla
    rep #$20
    .a16
    and #$3FFC
    bra animate_auxiliary_sprite_tile_orientation_c2c4bd
