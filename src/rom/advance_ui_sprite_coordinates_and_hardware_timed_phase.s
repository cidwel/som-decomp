; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9D0A
advance_ui_sprite_coordinates_and_hardware_timed_phase:
    sep #$30
    lda $F4
    sta a:$4204
    stz a:$4205
    .i8
    ldx #$04
    lda $43
    .a8
    and #$0C
    bne advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d1e
    .i8
    ldx #$06
advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d1e:
    stx a:$4206
    .i8
    ldx #$05
advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d23:
    lda a:$0A46,X
    cmp a:$0A4C,X
    beq advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d46
    bcc advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d39
    .a8
    sbc #$02
    cmp a:$0A4C,X
    bcs advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d43
    lda a:$0A4C,X
    bra advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d43
advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d39:
    .a8
    adc #$02
    cmp a:$0A4C,X
    bcc advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d43
    lda a:$0A4C,X
advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d43:
    sta a:$0A46,X
advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d46:
    dex
    bpl advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d23
    lda a:$4216
    beq advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d4f
    rts
advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d4f:
    lda a:$0A40
    inc
    .a8
    and #$0F
    sta a:$0A40
    .i8
    ldx #$05
advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d5a:
    lda a:$0A40,X
    dec
    .a8
    and #$0F
    sta a:$0A40,X
    dex
    bne advance_ui_sprite_coordinates_and_hardware_timed_phase_c09d5a
    rts
