; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-refresh.md.
.setcpu "65816"
.smart
.a8
.i16

read_native_actor_equipment_field_and_restore_index_status = $7A54

.segment "CODE"
.org $7699
refresh_native_equipped_sprite_id_and_clear_pose_offsets:
    jsr read_native_actor_equipment_field_and_restore_index_status
    rep #$30
    asl
    asl
    pha
    asl
    clc
    adc $01,S
    pla
    phx
    tax
    sep #$20
    lda f:$D01000,X
    plx
    sta f:$7E0001,X
    rep #$30
    txa
    .a16
    and #$FF80
    tax
    sep #$20
    .a8
    lda #$00
    sta f:$7E0015,X
    sta f:$7E001D,X
    rts
