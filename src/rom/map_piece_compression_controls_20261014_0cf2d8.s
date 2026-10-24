.setcpu "65816"
.segment "CODE"
.org $F2D8
map_control_0cf2d8:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
