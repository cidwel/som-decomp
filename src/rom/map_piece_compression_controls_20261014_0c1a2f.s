.setcpu "65816"
.segment "CODE"
.org $1A2F
map_control_0c1a2f:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
