.setcpu "65816"
.segment "CODE"
.org $2C46
map_control_0f2c46:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
