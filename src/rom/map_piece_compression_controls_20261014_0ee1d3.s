.setcpu "65816"
.segment "CODE"
.org $E1D3
map_control_0ee1d3:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
