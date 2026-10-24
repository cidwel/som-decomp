.setcpu "65816"
.segment "CODE"
.org $3C6E
map_control_0d3c6e:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
