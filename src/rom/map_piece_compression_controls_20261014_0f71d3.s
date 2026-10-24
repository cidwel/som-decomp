.setcpu "65816"
.segment "CODE"
.org $71D3
map_control_0f71d3:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
