.setcpu "65816"
.segment "CODE"
.org $5EB6
map_control_0d5eb6:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
