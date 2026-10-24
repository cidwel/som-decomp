.setcpu "65816"
.segment "CODE"
.org $539D
map_control_0d539d:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
