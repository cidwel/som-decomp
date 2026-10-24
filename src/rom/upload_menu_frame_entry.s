; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

upload_menu_frame_jump = $0086

.segment "CODE"
.org $0006
upload_menu_frame_entry:
    jmp upload_menu_frame_jump
