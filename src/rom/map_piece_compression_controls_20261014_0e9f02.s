.setcpu "65816"
.segment "CODE"
.org $9F02
map_control_0e9f02:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
