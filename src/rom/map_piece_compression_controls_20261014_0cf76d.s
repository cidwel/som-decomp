.setcpu "65816"
.segment "CODE"
.org $F76D
map_control_0cf76d:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
