; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $391D
boss_state_jump_to_native_pointer:
    sta $33
    jmp ($0233)
