.setcpu "65816"
.segment "CODE"
.org $F65F
map_control_0ef65f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
