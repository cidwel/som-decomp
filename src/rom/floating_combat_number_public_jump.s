; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

create_floating_combat_number_with_saved_context = $8018

.segment "CODE"
.org $8015
floating_combat_number_public_jump:
    jmp create_floating_combat_number_with_saved_context
