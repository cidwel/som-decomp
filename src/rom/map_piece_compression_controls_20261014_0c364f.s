.setcpu "65816"
.segment "CODE"
.org $364F
map_control_0c364f:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
