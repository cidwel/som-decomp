; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

emit_ui_sprite_tile_grid = $9C2B

.segment "CODE"
.org $9BBD
position_ui_sprite_grid_component:
    sta $00
    sep #$20
    ldx a:$0A40,Y
    lda a:$9CD9,X
    clc
    .a8
    adc #$50
    sec
    sbc $CF
    clc
    adc $09
    sta $09
    lda a:$0A46,Y
    ldx $5F
    .i8
    cpx #$04
    bne position_ui_sprite_grid_component_c09be4
    sec
    .a8
    sbc #$80
    .a8
    cmp #$80
    ror
    clc
    .a8
    adc #$80
position_ui_sprite_grid_component_c09be4:
    clc
    adc $08
    sta $08
    stz $12
    jmp emit_ui_sprite_tile_grid
