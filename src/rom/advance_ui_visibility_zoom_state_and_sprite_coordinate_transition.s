; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16

copy_selected_scene_color_targets_to_current_values = $9D67

.segment "CODE"
.org $8272
advance_ui_visibility_zoom_state_and_sprite_coordinate_transition:
    sep #$30
    .a8
    lda #$03
    and $F2
    bne advance_ui_visibility_zoom_state_and_sprite_coordinate_transition_c08290
    .a8
    lda #$1F
    clc
    adc $F8
    .a8
    eor #$FF
    lsr
    lsr
    lsr
    sta $00
    lsr
    clc
    adc $00
    .a8
    adc #$08
    sta a:$0F04
    rts
advance_ui_visibility_zoom_state_and_sprite_coordinate_transition_c08290:
    lsr
    bcs advance_ui_visibility_zoom_state_and_sprite_coordinate_transition_c082ab
    lda $51
    clc
    .a8
    adc #$01
    .a8
    cmp #$10
    bcc advance_ui_visibility_zoom_state_and_sprite_coordinate_transition_c082a8
    .a8
    lda #$02
    eor $F2
    sta $F2
    .a8
    lda #$00
    sta a:$2106
    rts
advance_ui_visibility_zoom_state_and_sprite_coordinate_transition_c082a8:
    sta $51
    rts
advance_ui_visibility_zoom_state_and_sprite_coordinate_transition_c082ab:
    lda $51
    sec
    .a8
    sbc #$02
    bcs advance_ui_visibility_zoom_state_and_sprite_coordinate_transition_c082a8
    .a8
    lda #$83
    eor $F2
    sta $F2
    and $BE
    bpl advance_ui_visibility_zoom_state_and_sprite_coordinate_transition_c082c0
    .a8
    lda #$80
    trb $BE
advance_ui_visibility_zoom_state_and_sprite_coordinate_transition_c082c0:
    jsr copy_selected_scene_color_targets_to_current_values
    rts
