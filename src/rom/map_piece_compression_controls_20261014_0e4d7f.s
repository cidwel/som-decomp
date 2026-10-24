.setcpu "65816"
.segment "CODE"
.org $4D7F
map_control_0e4d7f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
