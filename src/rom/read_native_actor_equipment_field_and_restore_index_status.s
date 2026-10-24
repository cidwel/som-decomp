; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-fields.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7A54
read_native_actor_equipment_field_and_restore_index_status:
    phx
    php
    rep #$30
    txa
    .a16
    and #$067F
    tax
    sep #$20
    .a8
    cmp #$63
    bne read_native_actor_equipment_field_and_restore_index_status_c07a71
    lda f:$7EE180,X
    .a8
    cmp #$F1
    bcc read_native_actor_equipment_field_and_restore_index_status_c07a75
    lda f:$7EE185,X
    bra read_native_actor_equipment_field_and_restore_index_status_c07a75
read_native_actor_equipment_field_and_restore_index_status_c07a71:
    lda f:$7EE180,X
read_native_actor_equipment_field_and_restore_index_status_c07a75:
    rep #$20
    .a16
    and #$00FF
    plp
    plx
    rts
