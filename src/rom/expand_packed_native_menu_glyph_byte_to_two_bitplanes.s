; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2191
expand_packed_native_menu_glyph_byte_to_two_bitplanes:
    stz a:$9400,X
    stz a:$9410,X
    lda a:$9000,Y
    iny
    xba
    .a8
    lda #$04
expand_packed_native_menu_glyph_byte_to_two_bitplanes_c0219e:
    xba
    lsr
    php
    ror a:$9410,X
    plp
    ror a:$9410,X
    xba
    dec
    bne expand_packed_native_menu_glyph_byte_to_two_bitplanes_c0219e
    .a8
    lda #$04
expand_packed_native_menu_glyph_byte_to_two_bitplanes_c021ae:
    xba
    lsr
    php
    ror a:$9400,X
    plp
    ror a:$9400,X
    xba
    dec
    bne expand_packed_native_menu_glyph_byte_to_two_bitplanes_c021ae
    inx
    rts
