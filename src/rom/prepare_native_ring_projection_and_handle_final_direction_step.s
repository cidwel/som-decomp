; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-phase.md.
.setcpu "65816"
.smart
.a8
.i16

choose_next_native_menu_ring_row_with_directional_wrap = $6D37
finish_native_ring_phase_or_rebuild_category_and_animate_palette = $6E9F
project_and_publish_all_native_menu_ring_rows = $6D1C
repeat_native_menu_ring_rows_while_direction_is_held = $6D55

.segment "CODE"
.org $6C6D
prepare_native_ring_projection_and_handle_final_direction_step:
    rep #$30
    lda a:$181C
    sta a:$186C
    lda a:$181E
    sta a:$186E
    .a16
    lda #$0012
    sta a:$1824
    .a16
    lda #$0848
    sta a:$1832
    sep #$20
    .i16
    ldx #$0838
    lda a:$1812
    bne prepare_native_ring_projection_and_handle_final_direction_step_c06cb3
    lda a:$1847
    dec
    bne prepare_native_ring_projection_and_handle_final_direction_step_c06ca0
    lda a:$181C
    clc
    adc a:$186E
    bra prepare_native_ring_projection_and_handle_final_direction_step_c06ca7
prepare_native_ring_projection_and_handle_final_direction_step_c06ca0:
    lda a:$181C
    sec
    sbc a:$186E
prepare_native_ring_projection_and_handle_final_direction_step_c06ca7:
    sec
    .a8
    sbc #$08
    sta $01,X
    sta $05,X
    clc
    .a8
    adc #$10
    bra prepare_native_ring_projection_and_handle_final_direction_step_c06cb9
prepare_native_ring_projection_and_handle_final_direction_step_c06cb3:
    .a8
    lda #$E8
    sta $01,X
    sta $05,X
prepare_native_ring_projection_and_handle_final_direction_step_c06cb9:
    sta $09,X
    sta $0D,X
    sep #$30
    lda a:$1812
    bne prepare_native_ring_projection_and_handle_final_direction_step_c06d16
    lda a:$1806
    beq prepare_native_ring_projection_and_handle_final_direction_step_c06d16
    lda a:$1801
    .a8
    and #$03
    bne prepare_native_ring_projection_and_handle_final_direction_step_c06d16
    jsr choose_next_native_menu_ring_row_with_directional_wrap
    rep #$30
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    clc
    .a16
    adc #$18C0
    tax
    sep #$20
    lda a:$1806
    bmi prepare_native_ring_projection_and_handle_final_direction_step_c06cf9
    rep #$20
    lda $08,X
    sec
    .a16
    sbc #$0012
    .a16
    and #$FC00
    beq prepare_native_ring_projection_and_handle_final_direction_step_c06d16
    lda $08,X
    bra prepare_native_ring_projection_and_handle_final_direction_step_c06d0c
prepare_native_ring_projection_and_handle_final_direction_step_c06cf9:
    rep #$20
    lda $08,X
    clc
    .a16
    adc #$0012
    .a16
    cmp #$0400
    bcc prepare_native_ring_projection_and_handle_final_direction_step_c06d16
    .a16
    lda #$0400
    sec
    sbc $08,X
prepare_native_ring_projection_and_handle_final_direction_step_c06d0c:
    sta a:$1824
    sep #$20
    lda a:$1848
    bne repeat_native_menu_ring_rows_while_direction_is_held
prepare_native_ring_projection_and_handle_final_direction_step_c06d16:
    jsr project_and_publish_all_native_menu_ring_rows
    jmp finish_native_ring_phase_or_rebuild_category_and_animate_palette
