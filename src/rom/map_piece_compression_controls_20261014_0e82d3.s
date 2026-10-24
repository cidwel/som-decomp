.setcpu "65816"
.segment "CODE"
.org $82D3
map_control_0e82d3:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
