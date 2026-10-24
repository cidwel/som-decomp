; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

upload_map_party_icon_tile = $E723

icon_vram_address = $00
vram_word_address = $2116
icon_top_left_descriptor = $D2C600
icon_top_right_descriptor = $D2C602
icon_bottom_left_descriptor = $D2C604
icon_bottom_right_descriptor = $D2C606

.segment "CODE"
.org $E6DA
upload_one_map_party_icon:
    .a8
    cmp #$EC
    bcs upload_one_map_party_icon_c1e6e2
    .a8
    and #$03
    bra upload_one_map_party_icon_c1e6e5
upload_one_map_party_icon_c1e6e2:
    sec
    .a8
    sbc #$E9
upload_one_map_party_icon_c1e6e5:
    rep #$20
    .a16
    and #$00FF
    asl
    asl
    asl
    tax
    lda icon_vram_address
    sta a:vram_word_address
    lda f:icon_top_left_descriptor,X
    jsr upload_map_party_icon_tile
    lda f:icon_top_right_descriptor,X
    jsr upload_map_party_icon_tile
    lda icon_vram_address
    clc
    .a16
    adc #$0100
    sta a:vram_word_address
    lda f:icon_bottom_left_descriptor,X
    jsr upload_map_party_icon_tile
    lda f:icon_bottom_right_descriptor,X
    jsr upload_map_party_icon_tile
    lda icon_vram_address
    clc
    .a16
    adc #$0020
    sta icon_vram_address
    sep #$20
    rts
