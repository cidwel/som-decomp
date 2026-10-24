.setcpu "65816"
.segment "CODE"
.org $2BFB
map_control_0e2bfb:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
