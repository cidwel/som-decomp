.setcpu "65816"
.segment "CODE"
.org $D2F2
map_control_0dd2f2:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
