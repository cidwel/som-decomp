.setcpu "65816"
.segment "CODE"
.org $621F
map_control_0f621f:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
