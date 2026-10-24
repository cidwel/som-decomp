.setcpu "65816"
.segment "CODE"
.org $1183
map_control_0e1183:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
