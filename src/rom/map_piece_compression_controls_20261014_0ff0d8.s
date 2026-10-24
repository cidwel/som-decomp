.setcpu "65816"
.segment "CODE"
.org $F0D8
map_control_0ff0d8:
    .byte $E3 ; previous-row copy count
