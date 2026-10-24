.setcpu "65816"
.segment "CODE"
.org $2D27
map_control_0d2d27:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
