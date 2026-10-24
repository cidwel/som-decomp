; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

emit_alternating_boss_objects_with_saved_context = $0250

.segment "CODE"
.org $000C
boss_alternating_object_emission_public_jump:
    jmp emit_alternating_boss_objects_with_saved_context
