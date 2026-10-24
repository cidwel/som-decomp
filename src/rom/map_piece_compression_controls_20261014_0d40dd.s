.setcpu "65816"
.segment "CODE"
.org $40DD
map_control_0d40dd:
    .byte $E3 ; previous-row copy count
