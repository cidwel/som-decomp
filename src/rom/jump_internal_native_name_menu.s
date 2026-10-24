; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-name-command.md.
.setcpu "65816"
.smart
.a8
.i16

run_native_main_menu_page_input_and_publication_loop = $1D97

.segment "CODE"
.org $008F
jump_internal_native_name_menu:
    jmp run_native_main_menu_page_input_and_publication_loop
