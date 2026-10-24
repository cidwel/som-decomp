; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-obstacle-detour.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B84B
test_native_partner_detour_tile_attributes:
    lda [$0A],Y
    .a16
    and #$00FF
    asl
    asl
    tay
    sep #$20
    lda [$0D],Y
    .a8
    and #$07
    beq test_native_partner_detour_tile_attributes_c1b869
    .a8
    cmp #$04
    bcs test_native_partner_detour_tile_attributes_c1b869
    .a8
    cmp #$03
    beq test_native_partner_detour_tile_attributes_c1b875
    eor $04
    .a8
    cmp #$03
    beq test_native_partner_detour_tile_attributes_c1b875
test_native_partner_detour_tile_attributes_c1b869:
    iny
    iny
    lda [$0D],Y
    .a8
    and #$F0
    .a8
    cmp #$10
    beq test_native_partner_detour_tile_attributes_c1b875
    clc
    rts
test_native_partner_detour_tile_attributes_c1b875:
    sec
    rts
