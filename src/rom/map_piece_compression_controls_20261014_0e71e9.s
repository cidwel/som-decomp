.setcpu "65816"
.segment "CODE"
.org $71E9
map_control_0e71e9:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
