.setcpu "65816"
.segment "CODE"
.org $6D3F
map_control_0e6d3f:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
