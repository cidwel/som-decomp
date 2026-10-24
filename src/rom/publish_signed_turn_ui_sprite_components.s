; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

hide_unused_ui_sprite_slots = $9DE9
prepare_signed_ui_sprite_component_five = $A02C
prepare_signed_ui_sprite_component_four = $9F81
prepare_signed_ui_sprite_component_one = $9FA6
prepare_signed_ui_sprite_component_three = $9F68
prepare_signed_ui_sprite_component_two = $9FD3
prepare_signed_ui_sprite_component_zero = $9F4E

.segment "CODE"
.org $9F02
publish_signed_turn_ui_sprite_components:
    sep #$30
    stz $12
    lda $5F
    .a8
    and #$04
    beq publish_signed_turn_ui_sprite_components_c09f0e
    bra publish_signed_turn_ui_sprite_components_c09f4a
publish_signed_turn_ui_sprite_components_c09f0e:
    lda $7A
    beq publish_signed_turn_ui_sprite_components_c09f16
    bpl publish_signed_turn_ui_sprite_components_c09f22
    bmi publish_signed_turn_ui_sprite_components_c09f1a
publish_signed_turn_ui_sprite_components_c09f16:
    .a8
    lda #$00
    bra publish_signed_turn_ui_sprite_components_c09f28
publish_signed_turn_ui_sprite_components_c09f1a:
    .a8
    lda #$FF
    sta $12
    .a8
    lda #$02
    bra publish_signed_turn_ui_sprite_components_c09f28
publish_signed_turn_ui_sprite_components_c09f22:
    .a8
    lda #$01
    sta $12
    .a8
    lda #$04
publish_signed_turn_ui_sprite_components_c09f28:
    sta $10
    lda $F4
    lsr
    bcs publish_signed_turn_ui_sprite_components_c09f41
    .a8
    lda #$00
    sta $7C
    sta $7D
    jsr prepare_signed_ui_sprite_component_five
    jsr prepare_signed_ui_sprite_component_four
    jsr prepare_signed_ui_sprite_component_three
    jmp prepare_signed_ui_sprite_component_two
publish_signed_turn_ui_sprite_components_c09f41:
    jsr prepare_signed_ui_sprite_component_one
    jsr prepare_signed_ui_sprite_component_zero
    jmp hide_unused_ui_sprite_slots
publish_signed_turn_ui_sprite_components_c09f4a:
    .a8
    lda #$06
    bra publish_signed_turn_ui_sprite_components_c09f28
