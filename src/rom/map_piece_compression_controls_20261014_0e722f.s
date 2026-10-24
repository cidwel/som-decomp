.setcpu "65816"
.segment "CODE"
.org $722F
map_control_0e722f:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
