.setcpu "65816"
.segment "CODE"
.org $44D3
map_control_0e44d3:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
