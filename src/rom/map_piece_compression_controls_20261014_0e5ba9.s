.setcpu "65816"
.segment "CODE"
.org $5BA9
map_control_0e5ba9:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
