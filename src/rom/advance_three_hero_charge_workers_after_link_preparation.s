; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-frame-workers.md.
.setcpu "65816"
.smart
.a8
.i16

advance_hero_charge_gauge_status_and_visual_effect_worker = $EB36
synchronize_linked_hero_fields_unless_native_byte_positions_differ = $F025

.segment "CODE"
.org $EB18
advance_three_hero_charge_workers_after_link_preparation:
    rep #$10
    sep #$20
    lda $4E
    beq advance_three_hero_charge_workers_after_link_preparation_c0eb23
    jsr synchronize_linked_hero_fields_unless_native_byte_positions_differ
advance_three_hero_charge_workers_after_link_preparation_c0eb23:
    .i16
    ldx #$0000
    jsr advance_hero_charge_gauge_status_and_visual_effect_worker
    .i16
    ldx #$0200
    jsr advance_hero_charge_gauge_status_and_visual_effect_worker
    .i16
    ldx #$0400
    jsr advance_hero_charge_gauge_status_and_visual_effect_worker
    rts
