; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-effect-update.md.
.setcpu "65816"
.smart
.a8
.i16

test_charge_effect_contact_geometry_and_mark_target = $C5B4

.segment "CODE"
.org $C54E
select_opposing_charge_effect_contact_actor_and_mark_source:
    stx $00
    lda a:$E02E,X
    .i16
    cpx #$0600
    bcc select_opposing_charge_effect_contact_actor_and_mark_source_c2c58b
    lsr
    bcs select_opposing_charge_effect_contact_actor_and_mark_source_c2c565
    .i16
    ldx #$0000
    pha
    jsr test_charge_effect_contact_geometry_and_mark_target
    pla
    bcs select_opposing_charge_effect_contact_actor_and_mark_source_c2c581
select_opposing_charge_effect_contact_actor_and_mark_source_c2c565:
    lsr
    bcs select_opposing_charge_effect_contact_actor_and_mark_source_c2c572
    .i16
    ldx #$0200
    pha
    jsr test_charge_effect_contact_geometry_and_mark_target
    pla
    bcs select_opposing_charge_effect_contact_actor_and_mark_source_c2c581
select_opposing_charge_effect_contact_actor_and_mark_source_c2c572:
    lsr
    bcs select_opposing_charge_effect_contact_actor_and_mark_source_c2c57d
    .i16
    ldx #$0400
    jsr test_charge_effect_contact_geometry_and_mark_target
    bcs select_opposing_charge_effect_contact_actor_and_mark_source_c2c581
select_opposing_charge_effect_contact_actor_and_mark_source_c2c57d:
    ldx $00
    clc
    rts
select_opposing_charge_effect_contact_actor_and_mark_source_c2c581:
    ldx $00
    xba
    ora a:$E02E,X
    sta a:$E02E,X
    rts
select_opposing_charge_effect_contact_actor_and_mark_source_c2c58b:
    lsr
    bcs select_opposing_charge_effect_contact_actor_and_mark_source_c2c598
    .i16
    ldx #$0600
    pha
    jsr test_charge_effect_contact_geometry_and_mark_target
    pla
    bcs select_opposing_charge_effect_contact_actor_and_mark_source_c2c581
select_opposing_charge_effect_contact_actor_and_mark_source_c2c598:
    lsr
    bcs select_opposing_charge_effect_contact_actor_and_mark_source_c2c5a5
    .i16
    ldx #$0800
    pha
    jsr test_charge_effect_contact_geometry_and_mark_target
    pla
    bcs select_opposing_charge_effect_contact_actor_and_mark_source_c2c581
select_opposing_charge_effect_contact_actor_and_mark_source_c2c5a5:
    lsr
    bcs select_opposing_charge_effect_contact_actor_and_mark_source_c2c5b0
    .i16
    ldx #$0A00
    jsr test_charge_effect_contact_geometry_and_mark_target
    bcs select_opposing_charge_effect_contact_actor_and_mark_source_c2c581
select_opposing_charge_effect_contact_actor_and_mark_source_c2c5b0:
    ldx $00
    clc
    rts
