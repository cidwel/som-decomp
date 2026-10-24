.setcpu "65816"
.segment "CODE"
.org $C449
map_control_0dc449:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
