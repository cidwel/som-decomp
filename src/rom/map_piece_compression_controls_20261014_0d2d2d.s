.setcpu "65816"
.segment "CODE"
.org $2D2D
map_control_0d2d2d:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
