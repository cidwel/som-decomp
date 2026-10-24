.setcpu "65816"
.segment "CODE"
.org $042A
map_control_0f042a:
    .byte $F2 ; progressive-copy count
    .byte $E3 ; previous-row copy count
