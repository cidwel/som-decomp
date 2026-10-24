.setcpu "65816"
.segment "CODE"
.org $F50F
map_control_0ff50f:
    .byte $E1 ; previous-row copy count
