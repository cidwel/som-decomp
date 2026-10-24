.setcpu "65816"
.segment "CODE"
.org $B00F
map_control_0eb00f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
