.setcpu "65816"
.segment "CODE"
.org $D2AB
map_control_0dd2ab:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
