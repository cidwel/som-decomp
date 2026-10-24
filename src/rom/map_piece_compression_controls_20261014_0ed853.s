.setcpu "65816"
.segment "CODE"
.org $D853
map_control_0ed853:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
