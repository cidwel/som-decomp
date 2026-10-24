.setcpu "65816"
.segment "CODE"
.org $1A38
map_control_0c1a38:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
