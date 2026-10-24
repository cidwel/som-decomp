.setcpu "65816"
.segment "CODE"
.org $10D3
map_control_0f10d3:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
