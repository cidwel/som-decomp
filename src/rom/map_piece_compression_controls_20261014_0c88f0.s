.setcpu "65816"
.segment "CODE"
.org $88F0
map_control_0c88f0:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
