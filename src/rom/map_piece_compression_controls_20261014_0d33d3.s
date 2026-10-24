.setcpu "65816"
.segment "CODE"
.org $33D3
map_control_0d33d3:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
