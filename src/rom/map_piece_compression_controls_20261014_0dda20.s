.setcpu "65816"
.segment "CODE"
.org $DA20
map_control_0dda20:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
