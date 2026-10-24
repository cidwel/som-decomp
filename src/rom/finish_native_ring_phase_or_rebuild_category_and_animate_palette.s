; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-phase.md.
.setcpu "65816"
.smart
.a8
.i16

await_vblank_edge_and_run_complete_menu_text_frame = $6943
dispatch_native_menu_weapon_palette_animation = $D0CBF6
hide_native_menu_icon_oam_objects = $D0C83F
persist_native_menu_category_row_and_equipment_rank = $C06B4C
step_category_then_build_native_menu_ring_list = $6F77

.segment "CODE"
.org $6E9F
finish_native_ring_phase_or_rebuild_category_and_animate_palette:
    lda a:$180C
    beq finish_native_ring_phase_or_rebuild_category_and_animate_palette_c06ee4
    jsl f:persist_native_menu_category_row_and_equipment_rank
    lda a:$1812
    rep #$10
    .a16
    cmp #$0003
    beq finish_native_ring_phase_or_rebuild_category_and_animate_palette_c06ee4
    tay
    clc
    .a16
    adc #$6EE9
    tax
    lda f:$C00000,X
    .a16
    and #$00FF
    tax
    lda a:$181E
    .i16
    cpy #$0005
    bne finish_native_ring_phase_or_rebuild_category_and_animate_palette_c06ecf
    .a16
    cmp #$0024
    beq finish_native_ring_phase_or_rebuild_category_and_animate_palette_c06ede
    bra finish_native_ring_phase_or_rebuild_category_and_animate_palette_c06ee4
finish_native_ring_phase_or_rebuild_category_and_animate_palette_c06ecf:
    .i16
    cpy #$0006
    bne finish_native_ring_phase_or_rebuild_category_and_animate_palette_c06ede
    jsl f:hide_native_menu_icon_oam_objects
    stz a:$1812
    jmp await_vblank_edge_and_run_complete_menu_text_frame
finish_native_ring_phase_or_rebuild_category_and_animate_palette_c06ede:
    stx a:$1812
    jsr step_category_then_build_native_menu_ring_list
finish_native_ring_phase_or_rebuild_category_and_animate_palette_c06ee4:
    jsl f:dispatch_native_menu_weapon_palette_animation
    rts
