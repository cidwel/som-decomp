.setcpu "65816"
.segment "CODE"
.org $2C12
map_control_0d2c12:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
