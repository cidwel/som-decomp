.setcpu "65816"
.segment "CODE"
.org $D4D6
map_control_0ed4d6:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
