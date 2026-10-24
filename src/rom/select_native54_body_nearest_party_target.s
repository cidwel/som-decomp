; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16

select_nearest_active_living_party_actor = $3224

.segment "CODE"
.org $4BEC
select_native54_body_nearest_party_target:
    jsr select_nearest_active_living_party_actor
    rts
