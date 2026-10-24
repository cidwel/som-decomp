.setcpu "65816"
.segment "CODE"
.org $605F
map_control_0c605f:
    .byte $E0 ; previous-row copy escape
    .byte $B7 ; row-distance/count
