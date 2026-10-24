.setcpu "65816"
.segment "CODE"
.org $F1B2
map_control_0ff1b2:
    .byte $E1 ; previous-row copy count
