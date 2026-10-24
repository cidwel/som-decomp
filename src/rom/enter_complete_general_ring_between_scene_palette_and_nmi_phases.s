; Recovered Secret of Mana USA routine; behaviour documented in docs/map-main-frame-menu-bridge.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_queued_actor_weapon_cast_or_motion_request = $DB6B
public_general_ring_menu_alias = $C00015
routine_02ab30 = $2AB30
routine_02c7dd = $2C7DD
select_scene_bank_and_update_ring_sprite_shadow_priority = $CB82

.segment "CODE"
.org $CB38
enter_complete_general_ring_between_scene_palette_and_nmi_phases:
    rep #$20
    stx $10
    sty $12
    phb
    jsr select_scene_bank_and_update_ring_sprite_shadow_priority
    sep #$20
    .a8
    lda #$01
    sta $EC
enter_complete_general_ring_between_scene_palette_and_nmi_phases_c1cb48:
    bit $EC
    bne enter_complete_general_ring_between_scene_palette_and_nmi_phases_c1cb48
    lda $2A
    pha
    jsl f:routine_02c7dd
    stz $2A
    rep #$10
    ldx $10
    ldy $12
    .a8
    lda #$00
    xba
    lda $99
    jsl f:public_general_ring_menu_alias
    sep #$20
    stz $EC
    pla
    sta $2A
    jsl f:routine_02c7dd
    jsl f:routine_02ab30
    jsr dispatch_queued_actor_weapon_cast_or_motion_request
    plb
    sep #$20
    .a8
    lda #$06
    sta $EC
enter_complete_general_ring_between_scene_palette_and_nmi_phases_c1cb7d:
    bit $EC
    bne enter_complete_general_ring_between_scene_palette_and_nmi_phases_c1cb7d
    rtl
