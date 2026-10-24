; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16

restore_saved_menu_palette_and_request_upload = $D0CD6D
select_native_menu_window_close_script_when_needed = $D0D5A0

.segment "CODE"
.org $6608
close_native_ring_dialogue_and_restore_shadow_palette:
    jsl f:select_native_menu_window_close_script_when_needed
    jsl f:restore_saved_menu_palette_and_request_upload
