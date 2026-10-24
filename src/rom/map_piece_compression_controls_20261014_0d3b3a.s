.setcpu "65816"
.segment "CODE"
.org $3B3A
map_control_0d3b3a:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
