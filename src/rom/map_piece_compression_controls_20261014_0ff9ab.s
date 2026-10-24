.setcpu "65816"
.segment "CODE"
.org $F9AB
map_control_0ff9ab:
    .byte $E6 ; previous-row copy count
