.setcpu "65816"
.segment "CODE"
.org $ED2C
map_control_0fed2c:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
