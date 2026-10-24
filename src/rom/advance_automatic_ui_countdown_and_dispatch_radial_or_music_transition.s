; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-motion-chain.md.
.setcpu "65816"
.smart
.a8
.i16

advance_two_scene_attribute_windows_and_rom_rows = $8455
continue_automatic_ui_motion_and_derive_real_map_transition = $8CFF
routine_c08d02 = $8D02

.segment "CODE"
.org $8C78
advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition:
    sep #$20
    lda $8C
    bne advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition_c08c7f
    rts
advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition_c08c7f:
    lda $E3
    .a8
    bit #$06
    beq routine_c08d02
    .a8
    bit #$04
    beq advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition_c08c8d
    .a8
    lda #$0C
    sta $E7
advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition_c08c8d:
    rep #$20
    lda $F6
    inc
    .a16
    and #$03FF
    sta $F6
    lda $F4
    lsr
    bcs advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition_c08ca5
    sep #$10
    .i8
    ldx #$00
    .i8
    ldy #$02
    jsr advance_two_scene_attribute_windows_and_rom_rows
advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition_c08ca5:
    sep #$10
    lda $8E
    dec
    sta $8E
    sep #$20
    bne continue_automatic_ui_motion_and_derive_real_map_transition
