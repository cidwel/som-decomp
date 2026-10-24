.setcpu "65816"
.segment "CODE"
.org $C31F
map_control_0ec31f:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
