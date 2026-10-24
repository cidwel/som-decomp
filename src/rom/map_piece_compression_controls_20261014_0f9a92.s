.setcpu "65816"
.segment "CODE"
.org $9A92
map_control_0f9a92:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
