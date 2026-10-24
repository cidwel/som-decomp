.setcpu "65816"
.segment "CODE"
.org $572B
map_control_0d572b:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
