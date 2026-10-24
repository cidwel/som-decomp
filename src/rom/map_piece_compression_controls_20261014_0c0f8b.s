.setcpu "65816"
.segment "CODE"
.org $0F8B
map_control_0c0f8b:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
