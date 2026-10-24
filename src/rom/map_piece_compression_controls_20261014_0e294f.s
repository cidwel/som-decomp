.setcpu "65816"
.segment "CODE"
.org $294F
map_control_0e294f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
