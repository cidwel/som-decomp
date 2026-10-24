.setcpu "65816"
.segment "CODE"
.org $D5D3
map_control_0dd5d3:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
