.setcpu "65816"
.segment "CODE"
.org $3C5B
map_control_0d3c5b:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
