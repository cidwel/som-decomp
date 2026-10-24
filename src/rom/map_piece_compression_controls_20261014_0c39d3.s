.setcpu "65816"
.segment "CODE"
.org $39D3
map_control_0c39d3:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
