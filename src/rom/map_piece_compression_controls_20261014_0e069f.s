.setcpu "65816"
.segment "CODE"
.org $069F
map_control_0e069f:
    .byte $F2 ; progressive-copy count
    .byte $E6 ; previous-row copy count
