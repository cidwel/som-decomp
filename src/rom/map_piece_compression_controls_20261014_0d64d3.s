.setcpu "65816"
.segment "CODE"
.org $64D3
map_control_0d64d3:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
