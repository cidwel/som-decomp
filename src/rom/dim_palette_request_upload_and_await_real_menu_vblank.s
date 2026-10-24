; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-vblank.md.
.setcpu "65816"
.smart
.a8
.i16

dim_menu_palette_preserving_first_actor_row_when_requested = $CD35
request_menu_palette_upload = $CDA9
wait_menu_vblank_through_native_long_wrapper = $C0693F

.segment "CODE"
.org $CD2A
dim_palette_request_upload_and_await_real_menu_vblank:
    jsr dim_menu_palette_preserving_first_actor_row_when_requested
    jsr request_menu_palette_upload
    jsl f:wait_menu_vblank_through_native_long_wrapper
    rtl
