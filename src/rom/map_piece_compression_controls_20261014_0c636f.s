.setcpu "65816"
.segment "CODE"
.org $636F
map_control_0c636f:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
