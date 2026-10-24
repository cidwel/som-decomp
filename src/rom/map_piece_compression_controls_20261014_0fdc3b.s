.setcpu "65816"
.segment "CODE"
.org $DC3B
map_control_0fdc3b:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
