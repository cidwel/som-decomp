.setcpu "65816"
.segment "CODE"
.org $F0A0
map_control_0ff0a0:
    .byte $E3 ; previous-row copy count
