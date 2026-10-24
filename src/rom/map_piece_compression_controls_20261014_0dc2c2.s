.setcpu "65816"
.segment "CODE"
.org $C2C2
map_control_0dc2c2:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
