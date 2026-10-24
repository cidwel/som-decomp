; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-hero-initialize.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_hero_identity_health_equipment_and_inventory = $4D72

.segment "CODE"
.org $3821
initialize_hero_record_public_jump_mirror:
    jmp initialize_hero_identity_health_equipment_and_inventory
