.setcpu "65816"
.segment "CODE"
.org $9B11
map_control_0d9b11:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
