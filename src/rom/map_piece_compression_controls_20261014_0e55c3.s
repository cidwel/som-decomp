.setcpu "65816"
.segment "CODE"
.org $55C3
map_control_0e55c3:
    .byte $F2 ; progressive-copy count
    .byte $E7 ; previous-row copy count
