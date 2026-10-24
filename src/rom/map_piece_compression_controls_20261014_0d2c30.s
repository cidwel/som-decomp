.setcpu "65816"
.segment "CODE"
.org $2C30
map_control_0d2c30:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
