.setcpu "65816"
.segment "CODE"
.org $C73B
map_control_0fc73b:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
