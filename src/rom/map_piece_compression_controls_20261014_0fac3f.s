.setcpu "65816"
.segment "CODE"
.org $AC3F
map_control_0fac3f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
