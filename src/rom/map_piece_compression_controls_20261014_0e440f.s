.setcpu "65816"
.segment "CODE"
.org $440F
map_control_0e440f:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
