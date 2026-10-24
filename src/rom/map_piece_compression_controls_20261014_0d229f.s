.setcpu "65816"
.segment "CODE"
.org $229F
map_control_0d229f:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
