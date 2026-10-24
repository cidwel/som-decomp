.setcpu "65816"
.segment "CODE"
.org $B85B
map_control_0eb85b:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
