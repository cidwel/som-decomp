; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-hero-initialize.md.
.setcpu "65816"
.smart
.a8
.i16

insert_inventory_record_with_explicit_controller_bits = $64B3

.segment "CODE"
.org $6423
jump_inventory_insert_with_explicit_hero_owner:
    jmp insert_inventory_record_with_explicit_controller_bits
