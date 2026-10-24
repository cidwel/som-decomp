.setcpu "65816"
.segment "CODE"
.org $D2DA
map_control_0dd2da:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
