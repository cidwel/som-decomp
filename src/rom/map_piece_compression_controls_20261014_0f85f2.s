.setcpu "65816"
.segment "CODE"
.org $85F2
map_control_0f85f2:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
