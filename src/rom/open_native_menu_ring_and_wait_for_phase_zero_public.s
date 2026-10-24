; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-waits.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_menu_ring_frames_until_phase_zero = $68F1
request_native_menu_ring_open_and_build_selected_list = $6906

.segment "CODE"
.org $68EA
open_native_menu_ring_and_wait_for_phase_zero_public:
    jsr request_native_menu_ring_open_and_build_selected_list
    jsr advance_native_menu_ring_frames_until_phase_zero
    rtl
