.setcpu "65816"
.segment "CODE"
.org $084F
map_control_0f084f:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
