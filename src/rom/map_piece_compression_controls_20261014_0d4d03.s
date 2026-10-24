.setcpu "65816"
.segment "CODE"
.org $4D03
map_control_0d4d03:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
