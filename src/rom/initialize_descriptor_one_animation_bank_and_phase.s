; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-one.md.
.setcpu "65816"
.smart
.a8
.i16

set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $42E1
initialize_descriptor_one_animation_bank_and_phase:
    jsr set_boss_animation_bank_low_byte_c7
    stz a:$007E,X
    rts
