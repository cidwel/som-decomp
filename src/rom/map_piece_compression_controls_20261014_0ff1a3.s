.setcpu "65816"
.segment "CODE"
.org $F1A3
map_control_0ff1a3:
    .byte $E1 ; previous-row copy count
