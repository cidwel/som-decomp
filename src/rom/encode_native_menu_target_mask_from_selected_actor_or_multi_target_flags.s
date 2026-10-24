; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-action-rows.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $787E
encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags:
    rep #$30
    ldx a:$1822
    lda $00,X
    .a16
    cmp #$FFFF
    beq encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags_c07897
    .a16
    and #$0E00
    xba
    lsr
    sep #$20
    sta a:$19F3
    rep #$20
    rts
encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags_c07897:
    sep #$20
    .a8
    lda #$00
    ldx a:$1812
    beq encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags_c078a2
    .a8
    ora #$01
encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags_c078a2:
    ldx a:$1814
    beq encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags_c078a9
    .a8
    ora #$02
encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags_c078a9:
    ldx a:$1816
    beq encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags_c078b0
    .a8
    ora #$04
encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags_c078b0:
    .a8
    ora #$20
    tax
    lda a:$1842
    bpl encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags_c078bd
    txa
    .a8
    and #$07
    .a8
    ora #$40
encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags_c078bd:
    sta a:$19F3
    rep #$20
    rts
