.setcpu "65816"
.segment "CODE"
.org $D57F
map_control_0dd57f:
    .byte $E0 ; previous-row copy escape
    .byte $C7 ; row-distance/count
