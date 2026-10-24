.setcpu "65816"
.segment "CODE"
.org $6696
map_control_0d6696:
    .byte $E0 ; previous-row copy escape
    .byte $DA ; row-distance/count
