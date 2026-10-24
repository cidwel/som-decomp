.setcpu "65816"
.segment "CODE"
.org $F154
map_control_0cf154:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
