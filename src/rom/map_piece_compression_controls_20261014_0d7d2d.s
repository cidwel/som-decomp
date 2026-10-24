.setcpu "65816"
.segment "CODE"
.org $7D2D
map_control_0d7d2d:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
