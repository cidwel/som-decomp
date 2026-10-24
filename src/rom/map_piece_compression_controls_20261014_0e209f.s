.setcpu "65816"
.segment "CODE"
.org $209F
map_control_0e209f:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
