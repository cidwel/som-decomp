; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-fields.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7A7D
write_native_actor_equipment_field_with_weapon_palette_alias:
    phx
    php
    rep #$30
    pha
    txa
    .a16
    and #$067F
    tax
    sep #$20
    .a8
    cmp #$63
    bne write_native_actor_equipment_field_with_weapon_palette_alias_c07aa9
    lda f:$7EE180,X
    .a8
    cmp #$F1
    bcc write_native_actor_equipment_field_with_weapon_palette_alias_c07a9d
    lda $01,S
    sta f:$7EE185,X
    bra write_native_actor_equipment_field_with_weapon_palette_alias_c07aaf
write_native_actor_equipment_field_with_weapon_palette_alias_c07a9d:
    lda $01,S
    sta f:$7EE180,X
    sta f:$7EE185,X
    bra write_native_actor_equipment_field_with_weapon_palette_alias_c07aaf
write_native_actor_equipment_field_with_weapon_palette_alias_c07aa9:
    lda $01,S
    sta f:$7EE180,X
write_native_actor_equipment_field_with_weapon_palette_alias_c07aaf:
    rep #$30
    pla
    plp
    plx
    rts
