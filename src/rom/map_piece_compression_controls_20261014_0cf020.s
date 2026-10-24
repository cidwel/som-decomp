.setcpu "65816"
.segment "CODE"
.org $F020
map_control_0cf020:
    .byte $E2 ; previous-row copy count
