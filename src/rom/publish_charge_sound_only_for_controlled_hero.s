; Recovered Secret of Mana USA routine; behaviour documented in docs/hero-charge-input.md.
.setcpu "65816"
.smart
.a8
.i16

publish_deferred_actor_sound_and_position_volume = $BB11

.segment "CODE"
.org $BB27
publish_charge_sound_only_for_controlled_hero:
    pha
    lda f:$7EE02C,X
    .a8
    cmp #$01
    pla
    bcs publish_deferred_actor_sound_and_position_volume
    rts
