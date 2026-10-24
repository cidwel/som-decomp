.setcpu "65816"
.segment "CODE"
.org $DA05
map_control_0dda05:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
