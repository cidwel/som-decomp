.setcpu "65816"
.segment "CODE"
.org $B08F
map_control_0fb08f:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
