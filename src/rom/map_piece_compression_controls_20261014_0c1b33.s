.setcpu "65816"
.segment "CODE"
.org $1B33
map_control_0c1b33:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
