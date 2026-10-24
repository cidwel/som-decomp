.setcpu "65816"
.segment "CODE"
.org $F0B9
map_control_0ff0b9:
    .byte $E4 ; previous-row copy count
