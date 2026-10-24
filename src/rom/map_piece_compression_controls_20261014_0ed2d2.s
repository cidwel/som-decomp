.setcpu "65816"
.segment "CODE"
.org $D2D2
map_control_0ed2d2:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
