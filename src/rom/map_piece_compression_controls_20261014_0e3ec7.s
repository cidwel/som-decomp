.setcpu "65816"
.segment "CODE"
.org $3EC7
map_control_0e3ec7:
    .byte $F2 ; progressive-copy count
    .byte $E3 ; previous-row copy count
