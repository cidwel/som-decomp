.setcpu "65816"
.segment "CODE"
.org $1229
map_control_0c1229:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
