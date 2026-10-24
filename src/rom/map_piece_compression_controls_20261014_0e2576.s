.setcpu "65816"
.segment "CODE"
.org $2576
map_control_0e2576:
    .byte $F4 ; progressive-copy count
    .byte $E1 ; previous-row copy count
