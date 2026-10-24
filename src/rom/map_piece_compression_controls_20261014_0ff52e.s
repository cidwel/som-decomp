.setcpu "65816"
.segment "CODE"
.org $F52E
map_control_0ff52e:
    .byte $E1 ; previous-row copy count
