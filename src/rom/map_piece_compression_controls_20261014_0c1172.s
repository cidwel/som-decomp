.setcpu "65816"
.segment "CODE"
.org $1172
map_control_0c1172:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
