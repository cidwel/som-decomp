.setcpu "65816"
.segment "CODE"
.org $FC8F
map_control_0dfc8f:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
