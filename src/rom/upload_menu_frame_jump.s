; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

upload_complete_menu_frame = $1BF7

.segment "CODE"
.org $0086
upload_menu_frame_jump:
    jmp upload_complete_menu_frame
