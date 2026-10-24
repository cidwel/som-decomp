; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

advance_and_publish_automatic_ui_party_icons = $9DFC
advance_ui_sprite_coordinates_and_hardware_timed_phase = $9D0A
hide_unused_ui_sprite_slots = $9DE9
prepare_ui_sprite_grid_component_five = $9BEE
prepare_ui_sprite_grid_component_four = $9B6B
prepare_ui_sprite_grid_component_one = $9B7B
prepare_ui_sprite_grid_component_three = $9B5B
prepare_ui_sprite_grid_component_two = $9B9A
prepare_ui_sprite_grid_component_zero = $9B4B
publish_signed_turn_ui_sprite_components = $9F02
select_scene_color_targets_from_cursor_and_fade_flags = $9D78

.segment "CODE"
.org $9AB8
publish_ui_frame_sprites:
    sep #$30
    lda $8C
    beq publish_ui_frame_sprites_c09ad0
    lda $E3
    .a8
    bit #$06
    bne publish_ui_frame_sprites_c09ad0
    lsr
    bcs publish_ui_frame_sprites_c09aca
    jmp advance_and_publish_automatic_ui_party_icons
publish_ui_frame_sprites_c09aca:
    rts
publish_ui_frame_sprites_c09acb:
    stz $7C
    brl hide_unused_ui_sprite_slots
publish_ui_frame_sprites_c09ad0:
    lda $BF
    bne publish_ui_frame_sprites_c09acb
    ldx $7A
    cpx $7B
    beq publish_ui_frame_sprites_c09ae1
    stx $7B
    jsr select_scene_color_targets_from_cursor_and_fade_flags
    bra publish_ui_frame_sprites_c09ae4
publish_ui_frame_sprites_c09ae1:
    jsr advance_ui_sprite_coordinates_and_hardware_timed_phase
publish_ui_frame_sprites_c09ae4:
    lda $F2
    bpl publish_ui_frame_sprites_c09aeb
    jmp publish_signed_turn_ui_sprite_components
publish_ui_frame_sprites_c09aeb:
    lda $5F
    .a8
    and #$04
    beq publish_ui_frame_sprites_c09af3
    bra publish_ui_frame_sprites_c09b27
publish_ui_frame_sprites_c09af3:
    lda $7A
    beq publish_ui_frame_sprites_c09afb
    bpl publish_ui_frame_sprites_c09b03
    bmi publish_ui_frame_sprites_c09aff
publish_ui_frame_sprites_c09afb:
    .a8
    lda #$00
    bra publish_ui_frame_sprites_c09b05
publish_ui_frame_sprites_c09aff:
    .a8
    lda #$02
    bra publish_ui_frame_sprites_c09b05
publish_ui_frame_sprites_c09b03:
    .a8
    lda #$04
publish_ui_frame_sprites_c09b05:
    sta $10
    lda $F4
    lsr
    bcs publish_ui_frame_sprites_c09b1e
    .a8
    lda #$00
    sta $7C
    sta $7D
    jsr prepare_ui_sprite_grid_component_five
    jsr prepare_ui_sprite_grid_component_four
    jsr prepare_ui_sprite_grid_component_three
    jmp prepare_ui_sprite_grid_component_two
publish_ui_frame_sprites_c09b1e:
    jsr prepare_ui_sprite_grid_component_one
    jsr prepare_ui_sprite_grid_component_zero
    jmp hide_unused_ui_sprite_slots
publish_ui_frame_sprites_c09b27:
    .a8
    lda #$06
    sta $10
    lda $F4
    lsr
    bcc publish_ui_frame_sprites_c09b3c
    .a8
    lda #$00
    sta $7C
    sta $7D
    jsr prepare_ui_sprite_grid_component_zero
    jmp prepare_ui_sprite_grid_component_one
publish_ui_frame_sprites_c09b3c:
    jsr prepare_ui_sprite_grid_component_two
    jsr prepare_ui_sprite_grid_component_three
    jsr prepare_ui_sprite_grid_component_four
    jsr prepare_ui_sprite_grid_component_five
    jmp hide_unused_ui_sprite_slots
