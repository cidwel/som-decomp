.setcpu "65816"
.segment "CODE"
.org $084F
map_control_0d084f:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
