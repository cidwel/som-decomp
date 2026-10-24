.setcpu "65816"
.segment "CODE"
.org $F21D
map_control_0ff21d:
    .byte $E1 ; previous-row copy count
