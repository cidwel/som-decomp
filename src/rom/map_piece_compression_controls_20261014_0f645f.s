.setcpu "65816"
.segment "CODE"
.org $645F
map_control_0f645f:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
