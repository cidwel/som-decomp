.setcpu "65816"
.segment "CODE"
.org $869F
map_control_0c869f:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
