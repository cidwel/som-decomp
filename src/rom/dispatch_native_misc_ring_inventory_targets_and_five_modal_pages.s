; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-general.md.
.setcpu "65816"
.smart
.a8
.i16

build_native_three_actor_menu_target_list_and_count = $D0DA60
call_actor_status_program_long = $C10024
close_dialogue_public_jump = $C00095
encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags = $787E
hide_native_menu_icon_oam_objects = $D0C83F
public_first_three_boss_animation_control_jump = $C20018
request_event_menu_loop_and_initialize_input_state = $692D
request_native_menu_audio_0e = $D0CF08
request_native_menu_audio_a3 = $D0CF40
restore_inventory_menu_direct_page_bank_and_status = $645C
routine_c0000f = $C0000F
routine_c07271 = $7271
routine_c07275 = $7275
routine_d9fc90 = $D9FC90
select_native_menu_target_with_controller_edges_and_real_vblank = $D0DB58

.segment "CODE"
.org $73DB
dispatch_native_misc_ring_inventory_targets_and_five_modal_pages:
    sep #$20
    .i16
    ldx #$19FD
    lda a:$1836
    sta $00,X
    lda a:$1808
    sta $01,X
    lda a:$1802
    sta $02,X
    .a8
    lda #$C0
    sta a:$19F0
    lda a:$1876
    beq dispatch_native_misc_ring_inventory_targets_and_five_modal_pages_c07417
    dec
    beq dispatch_native_misc_ring_inventory_targets_and_five_modal_pages_c07435
    jsl f:request_native_menu_audio_0e
    pha
    jsl f:close_dialogue_public_jump
    pla
    jsl f:routine_c0000f
    jsl f:public_first_three_boss_animation_control_jump
    rep #$20
    lda a:$19CE
    tcs
    jmp restore_inventory_menu_direct_page_bank_and_status
dispatch_native_misc_ring_inventory_targets_and_five_modal_pages_c07417:
    jsl f:routine_d9fc90
    beq dispatch_native_misc_ring_inventory_targets_and_five_modal_pages_c07450
    jsl f:request_native_menu_audio_0e
    jsl f:hide_native_menu_icon_oam_objects
    jsr request_event_menu_loop_and_initialize_input_state
    sep #$20
    .a8
    lda #$08
    tsb a:$1803
    .a8
    lda #$04
    sta a:$1809
    rts
dispatch_native_misc_ring_inventory_targets_and_five_modal_pages_c07435:
    sep #$30
    .a8
    lda #$80
    sta a:$19F0
    .a8
    lda #$80
    sta a:$1842
    jsl f:build_native_three_actor_menu_target_list_and_count
    beq dispatch_native_misc_ring_inventory_targets_and_five_modal_pages_c07450
    jsl f:select_native_menu_target_with_controller_edges_and_real_vblank
    beq dispatch_native_misc_ring_inventory_targets_and_five_modal_pages_c07453
    jmp routine_c07275
dispatch_native_misc_ring_inventory_targets_and_five_modal_pages_c07450:
    jmp routine_c07271
dispatch_native_misc_ring_inventory_targets_and_five_modal_pages_c07453:
    jsl f:request_native_menu_audio_a3
    rep #$30
    jsr encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags
    rep #$10
    sep #$20
    lda a:$19F3
    ldx a:$1844
    sta f:$7E002C,X
    rep #$30
    txa
    .a16
    and #$0600
    tax
    .a16
    lda #$0000
    jsl f:call_actor_status_program_long
    .a16
    lda #$01C0
    sta a:$19F0
    rts
