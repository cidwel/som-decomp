.setcpu "65816"
.segment "CODE"
.org $D33F
map_control_0fd33f:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
