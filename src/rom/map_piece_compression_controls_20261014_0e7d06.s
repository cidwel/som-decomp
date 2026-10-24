.setcpu "65816"
.segment "CODE"
.org $7D06
map_control_0e7d06:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
