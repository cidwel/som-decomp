.setcpu "65816"
.segment "CODE"
.org $D127
map_control_0dd127:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
