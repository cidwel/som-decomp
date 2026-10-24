.setcpu "65816"
.segment "CODE"
.org $DA15
map_control_0dda15:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
