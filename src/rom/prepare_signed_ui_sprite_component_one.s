; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c09ff8 = $9FF8

.segment "CODE"
.org $9FA6
prepare_signed_ui_sprite_component_one:
    rep #$20
    .a16
    lda #$00F0
    ldx $5F
    .i8
    cpx #$04
    beq prepare_signed_ui_sprite_component_one_c09fc2
    .a16
    lda #$F0F0
    ldx $7A
    beq prepare_signed_ui_sprite_component_one_c09fc2
    bmi prepare_signed_ui_sprite_component_one_c09fbf
    .a16
    lda #$F0F1
    bra prepare_signed_ui_sprite_component_one_c09fc2
prepare_signed_ui_sprite_component_one_c09fbf:
    .a16
    lda #$F0EF
prepare_signed_ui_sprite_component_one_c09fc2:
    sta $08
    ldy $10
    lda a:$A2C6,Y
    .i8
    ldx #$01
    sta $00
    lda $F4
    lsr
    lsr
    bra routine_c09ff8
