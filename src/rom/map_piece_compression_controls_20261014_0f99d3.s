.setcpu "65816"
.segment "CODE"
.org $99D3
map_control_0f99d3:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
