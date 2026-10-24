.setcpu "65816"
.segment "CODE"
.org $2C69
map_control_0f2c69:
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
