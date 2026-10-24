.setcpu "65816"
.segment "CODE"
.org $D864
map_control_0ed864:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
