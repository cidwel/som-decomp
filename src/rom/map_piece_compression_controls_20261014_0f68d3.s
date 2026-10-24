.setcpu "65816"
.segment "CODE"
.org $68D3
map_control_0f68d3:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
