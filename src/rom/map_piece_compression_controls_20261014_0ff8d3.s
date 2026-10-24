.setcpu "65816"
.segment "CODE"
.org $F8D3
map_control_0ff8d3:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
