.setcpu "65816"
.segment "CODE"
.org $3304
map_control_0d3304:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
