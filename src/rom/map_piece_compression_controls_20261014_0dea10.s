.setcpu "65816"
.segment "CODE"
.org $EA10
map_control_0dea10:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
