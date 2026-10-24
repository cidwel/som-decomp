.setcpu "65816"
.segment "CODE"
.org $5BFB
map_control_0f5bfb:
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
