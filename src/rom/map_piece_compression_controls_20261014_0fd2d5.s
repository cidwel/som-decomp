.setcpu "65816"
.segment "CODE"
.org $D2D5
map_control_0fd2d5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
