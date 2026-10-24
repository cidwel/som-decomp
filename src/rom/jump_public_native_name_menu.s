; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-name-command.md.
.setcpu "65816"
.smart
.a8
.i16

jump_internal_native_name_menu = $008F

.segment "CODE"
.org $000F
jump_public_native_name_menu:
    jmp jump_internal_native_name_menu
