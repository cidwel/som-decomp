.setcpu "65816"
.segment "CODE"
.org $D55F
map_control_0dd55f:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
