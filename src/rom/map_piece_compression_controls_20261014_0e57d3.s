.setcpu "65816"
.segment "CODE"
.org $57D3
map_control_0e57d3:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
