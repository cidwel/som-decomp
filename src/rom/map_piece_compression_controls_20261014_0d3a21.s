.setcpu "65816"
.segment "CODE"
.org $3A21
map_control_0d3a21:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
