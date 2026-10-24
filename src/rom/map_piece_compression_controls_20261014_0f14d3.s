.setcpu "65816"
.segment "CODE"
.org $14D3
map_control_0f14d3:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
