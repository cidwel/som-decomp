.setcpu "65816"
.segment "CODE"
.org $DA4D
map_control_0dda4d:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
