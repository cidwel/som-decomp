.setcpu "65816"
.segment "CODE"
.org $2C99
map_control_0d2c99:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
