.setcpu "65816"
.segment "CODE"
.org $4977
map_control_0d4977:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
