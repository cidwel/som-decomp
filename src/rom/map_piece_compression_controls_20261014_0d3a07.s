.setcpu "65816"
.segment "CODE"
.org $3A07
map_control_0d3a07:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
