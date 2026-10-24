.setcpu "65816"
.segment "CODE"
.org $DAE6
map_control_0ddae6:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
