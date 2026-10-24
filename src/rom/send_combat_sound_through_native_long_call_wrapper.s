; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-sound-sprite-public-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16

send_combat_sound_with_fixed_parameter_fifteen = $398D

.segment "CODE"
.org $3989
send_combat_sound_through_native_long_call_wrapper:
    jsr send_combat_sound_with_fixed_parameter_fifteen
    rtl
