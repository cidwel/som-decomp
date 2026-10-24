; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-hero-initialize.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_hero_record_public_jump_mirror = $3821

.segment "CODE"
.org $0039
initialize_hero_record_public_jump:
    jmp initialize_hero_record_public_jump_mirror
