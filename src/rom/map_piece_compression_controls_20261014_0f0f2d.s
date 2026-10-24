.setcpu "65816"
.segment "CODE"
.org $0F2D
map_control_0f0f2d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
