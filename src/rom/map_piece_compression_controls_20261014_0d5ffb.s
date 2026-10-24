.setcpu "65816"
.segment "CODE"
.org $5FFB
map_control_0d5ffb:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
