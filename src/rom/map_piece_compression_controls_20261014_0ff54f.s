.setcpu "65816"
.segment "CODE"
.org $F54F
map_control_0ff54f:
    .byte $E5 ; previous-row copy count
