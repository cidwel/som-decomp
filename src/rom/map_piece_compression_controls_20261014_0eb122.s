.setcpu "65816"
.segment "CODE"
.org $B122
map_control_0eb122:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
