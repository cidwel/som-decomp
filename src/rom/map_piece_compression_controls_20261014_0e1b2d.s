.setcpu "65816"
.segment "CODE"
.org $1B2D
map_control_0e1b2d:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
