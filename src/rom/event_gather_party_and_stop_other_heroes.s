; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16

clear_actor_movement_charge_and_palette_effects = $CA6C

.segment "CODE"
.org $E9FB
event_gather_party_and_stop_other_heroes:
    .a8
    lda #$80
    sta $4E
    sta $D0
    rep #$10
    .i16
    ldx #$0000
    cpx $D4
    beq event_gather_party_and_stop_other_heroes_c1ea0d
    jsr clear_actor_movement_charge_and_palette_effects
event_gather_party_and_stop_other_heroes_c1ea0d:
    .i16
    ldx #$0200
    cpx $D4
    beq event_gather_party_and_stop_other_heroes_c1ea17
    jsr clear_actor_movement_charge_and_palette_effects
event_gather_party_and_stop_other_heroes_c1ea17:
    .i16
    ldx #$0400
    cpx $D4
    beq event_gather_party_and_stop_other_heroes_c1ea21
    jsr clear_actor_movement_charge_and_palette_effects
event_gather_party_and_stop_other_heroes_c1ea21:
    rep #$20
    inc $D1
    rts
