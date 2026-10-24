.setcpu "65816"
.segment "CODE"
.org $2D79
map_control_0d2d79:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
