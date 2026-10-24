.setcpu "65816"
.segment "CODE"
.org $F08F
map_control_0ff08f:
    .byte $E1 ; previous-row copy count
