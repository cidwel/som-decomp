; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

emit_ui_sprite_tile_grid = $9C2B

.segment "CODE"
.org $9FFF
position_signed_ui_sprite_component:
    sta $00
    sep #$20
    ldx a:$0A40,Y
    lda a:$A072,X
    ldx $5F
    .i8
    cpx #$04
    beq position_signed_ui_sprite_component_c0a018
    ldx $7A
    beq position_signed_ui_sprite_component_c0a018
    bpl position_signed_ui_sprite_component_c0a018
    .a8
    eor #$FF
    inc
position_signed_ui_sprite_component_c0a018:
    clc
    adc a:$0A46,Y
    clc
    adc $08
    sta $08
    .a8
    lda #$70
    clc
    adc $09
    sta $09
    clc
    jmp emit_ui_sprite_tile_grid
