.setcpu "65816"
.segment "CODE"
.org $0F60
map_control_0c0f60:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
