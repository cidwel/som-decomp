.setcpu "65816"
.segment "CODE"
.org $400F
map_control_0f400f:
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
