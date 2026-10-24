.setcpu "65816"
.segment "CODE"
.org $E6D3
map_control_0de6d3:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
