.setcpu "65816"
.segment "CODE"
.org $C991
map_control_0ec991:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
