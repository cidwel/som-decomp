.setcpu "65816"
.segment "CODE"
.org $2C04
map_control_0d2c04:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $25 ; distance low bit/count
