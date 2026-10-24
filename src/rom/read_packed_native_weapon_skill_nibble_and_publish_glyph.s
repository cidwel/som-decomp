; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-personality-page.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6679
read_packed_native_weapon_skill_nibble_and_publish_glyph:
    phx
    .i16
    ldx #$0040
    stx a:$A171
    lda f:$0019FE
    rep #$20
    xba
    .a16
    and #$FF00
    asl
    sta a:$A173
    lda a:$A175
    .a16
    and #$00FF
    lsr
    php
    clc
    adc a:$A173
    adc a:$A171
    tax
    plp
    sep #$20
    bcc read_packed_native_weapon_skill_nibble_and_publish_glyph_c766aa
    lda a:$E180,X
    .a8
    and #$0F
    bra read_packed_native_weapon_skill_nibble_and_publish_glyph_c766b3
read_packed_native_weapon_skill_nibble_and_publish_glyph_c766aa:
    lda a:$E180,X
    .a8
    and #$F0
    lsr
    lsr
    lsr
    lsr
read_packed_native_weapon_skill_nibble_and_publish_glyph_c766b3:
    sta a:$A15A
    clc
    .a8
    adc #$B5
    plx
    sta a:$9C00,X
    inx
    rts
