.setcpu "65816"
.segment "CODE"
.org $A8D3
map_control_0ea8d3:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
