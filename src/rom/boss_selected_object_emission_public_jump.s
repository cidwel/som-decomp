; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

emit_selected_boss_object_with_saved_context = $023A

.segment "CODE"
.org $0006
boss_selected_object_emission_public_jump:
    jmp emit_selected_boss_object_with_saved_context
