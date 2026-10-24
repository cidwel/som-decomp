.setcpu "65816"
.segment "CODE"
.org $4B04
map_control_0e4b04:
    .byte $E9 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
