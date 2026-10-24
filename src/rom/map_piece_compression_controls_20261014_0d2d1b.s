.setcpu "65816"
.segment "CODE"
.org $2D1B
map_control_0d2d1b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
