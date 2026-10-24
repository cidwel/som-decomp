.setcpu "65816"
.segment "CODE"
.org $D90D
map_control_0dd90d:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
