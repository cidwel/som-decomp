.setcpu "65816"
.segment "CODE"
.org $B056
map_control_0fb056:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
