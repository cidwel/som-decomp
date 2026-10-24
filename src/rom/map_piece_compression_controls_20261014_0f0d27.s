.setcpu "65816"
.segment "CODE"
.org $0D27
map_control_0f0d27:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
