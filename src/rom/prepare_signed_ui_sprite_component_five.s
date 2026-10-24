; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

position_signed_ui_sprite_component = $9FFF

.segment "CODE"
.org $A02C
prepare_signed_ui_sprite_component_five:
    rep #$20
    ldy $10
    lda a:$A2E6,Y
    sta $00
    ldx a:$0A45
    lda a:$A062,X
    asl
    .a16
    and #$0007
    tay
    .a16
    lda #$10FC
    ldx $5F
    .i8
    cpx #$04
    bne prepare_signed_ui_sprite_component_five_c0a04e
    .a16
    lda #$E8FC
    bra prepare_signed_ui_sprite_component_five_c0a05a
prepare_signed_ui_sprite_component_five_c0a04e:
    ldx $7A
    beq prepare_signed_ui_sprite_component_five_c0a05a
    bmi prepare_signed_ui_sprite_component_five_c0a058
    inc
    inc
    bra prepare_signed_ui_sprite_component_five_c0a05a
prepare_signed_ui_sprite_component_five_c0a058:
    dec
    dec
prepare_signed_ui_sprite_component_five_c0a05a:
    sta $08
    lda ($00),Y
    .i8
    ldy #$05
    bra position_signed_ui_sprite_component
