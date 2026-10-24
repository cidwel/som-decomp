.setcpu "65816"
.segment "CODE"
.org $BA15
map_control_0fba15:
    .byte $E9 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
