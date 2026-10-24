; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-four.md.
.setcpu "65816"
.smart
.a8
.i16

derive_four_way_direction_to_low_byte_target = $091D
select_nearest_active_living_party_actor = $3224

.segment "CODE"
.org $3A52
select_nearest_living_target_and_four_way_direction:
    ldx $87
    jsr select_nearest_active_living_party_actor
    ldx $87
    sta a:$00A9,X
    jsr derive_four_way_direction_to_low_byte_target
    sta a:$00AB,X
    rts
