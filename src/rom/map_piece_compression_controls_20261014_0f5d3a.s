.setcpu "65816"
.segment "CODE"
.org $5D3A
map_control_0f5d3a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
