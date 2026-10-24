.setcpu "65816"
.segment "CODE"
.org $52E7
map_control_0f52e7:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
