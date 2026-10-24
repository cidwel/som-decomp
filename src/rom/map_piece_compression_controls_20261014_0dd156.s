.setcpu "65816"
.segment "CODE"
.org $D156
map_control_0dd156:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
