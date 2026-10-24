.setcpu "65816"
.segment "CODE"
.org $AAF2
map_control_0faaf2:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
