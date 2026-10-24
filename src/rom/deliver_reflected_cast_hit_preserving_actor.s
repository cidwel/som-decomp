; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-execution-check.md.
.setcpu "65816"
.smart
.a8
.i16

deliver_complete_cast_hit_to_target = $8D12

.segment "CODE"
.org $8D09
deliver_reflected_cast_hit_preserving_actor:
    tay
    phx
    jsr deliver_complete_cast_hit_to_target
    rep #$10
    plx
    rts
