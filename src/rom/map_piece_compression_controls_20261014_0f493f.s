.setcpu "65816"
.segment "CODE"
.org $493F
map_control_0f493f:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
