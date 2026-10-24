.setcpu "65816"
.segment "CODE"
.org $0C2D
map_control_0c0c2d:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
