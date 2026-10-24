.setcpu "65816"
.segment "CODE"
.org $B70F
map_control_0eb70f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
