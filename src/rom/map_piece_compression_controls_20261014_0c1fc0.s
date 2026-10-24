.setcpu "65816"
.segment "CODE"
.org $1FC0
map_control_0c1fc0:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
