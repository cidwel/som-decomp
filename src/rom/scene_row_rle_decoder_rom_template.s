; Source physical ROM C09A60; executes from RAM 000B00 after page operand patches.
; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-tile-rows.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9A60
scene_row_rle_decoder_rom_template:
scene_row_rle_decoder_rom_template_c09a60:
    lda a:$8400,Y
    .a8
    cmp #$C0
    bcs scene_row_rle_decoder_rom_template_c09a71
    sta f:$002180
    iny
    dex
    bpl scene_row_rle_decoder_rom_template_c09a60
    bmi scene_row_rle_decoder_rom_template_c09a90
scene_row_rle_decoder_rom_template_c09a71:
    .a8
    and #$3F
    sta $3A
    iny
    lda a:$8400,Y
    iny
    phy
    ldy $3A
scene_row_rle_decoder_rom_template_c09a7d:
    sta f:$002180
    dey
    bpl scene_row_rle_decoder_rom_template_c09a7d
    ply
    rep #$20
    txa
    clc
    sbc $3A
    tax
    sep #$20
    bpl scene_row_rle_decoder_rom_template_c09a60
scene_row_rle_decoder_rom_template_c09a90:
    rts
