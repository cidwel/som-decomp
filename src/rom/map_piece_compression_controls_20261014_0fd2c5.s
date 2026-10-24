.setcpu "65816"
.segment "CODE"
.org $D2C5
map_control_0fd2c5:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
