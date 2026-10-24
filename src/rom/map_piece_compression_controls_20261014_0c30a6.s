.setcpu "65816"
.segment "CODE"
.org $30A6
map_control_0c30a6:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
