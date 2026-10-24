.setcpu "65816"
.segment "CODE"
.org $2D6B
map_control_0c2d6b:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
