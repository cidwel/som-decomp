; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

upload_one_map_party_icon = $E6DA

vram_increment_mode = $2115
icon_vram_address = $00
first_party_icon_code = $7EE180
second_party_icon_code = $7EE380
third_party_icon_code = $7EE580

.segment "CODE"
.org $E6B6
upload_map_party_icons:
    sep #$20
    rep #$10
    .a8
    lda #$80
    sta a:vram_increment_mode
    .i16
    ldy #$7E80
    sty icon_vram_address
    lda f:first_party_icon_code
    jsr upload_one_map_party_icon
    lda f:second_party_icon_code
    jsr upload_one_map_party_icon
    lda f:third_party_icon_code
    jsr upload_one_map_party_icon
    rts
