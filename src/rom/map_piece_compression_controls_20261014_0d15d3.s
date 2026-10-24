.setcpu "65816"
.segment "CODE"
.org $15D3
map_control_0d15d3:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
