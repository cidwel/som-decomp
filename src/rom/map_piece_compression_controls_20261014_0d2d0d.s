.setcpu "65816"
.segment "CODE"
.org $2D0D
map_control_0d2d0d:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
