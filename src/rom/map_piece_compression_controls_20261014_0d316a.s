.setcpu "65816"
.segment "CODE"
.org $316A
map_control_0d316a:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
