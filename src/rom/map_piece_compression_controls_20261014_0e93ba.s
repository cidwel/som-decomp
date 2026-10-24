.setcpu "65816"
.segment "CODE"
.org $93BA
map_control_0e93ba:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
