; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16

close_dialogue_public_jump = $C00095
public_first_three_boss_animation_control_jump = $C20018
restore_inventory_menu_direct_page_bank_and_status = $645C

.segment "CODE"
.org $65BE
finish_native_ring_public_menu_and_restore_saved_context:
    sep #$20
    lda a:$1847
    bne finish_native_ring_public_menu_and_restore_saved_context_c065c9
    jsl f:public_first_three_boss_animation_control_jump
finish_native_ring_public_menu_and_restore_saved_context_c065c9:
    lda a:$19F0
    .a8
    cmp #$C0
    beq finish_native_ring_public_menu_and_restore_saved_context_c065d4
    jsl f:close_dialogue_public_jump
finish_native_ring_public_menu_and_restore_saved_context_c065d4:
    jmp restore_inventory_menu_direct_page_bank_and_status
