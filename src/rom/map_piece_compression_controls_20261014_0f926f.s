.setcpu "65816"
.segment "CODE"
.org $926F
map_control_0f926f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
